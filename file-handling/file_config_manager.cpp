#include <assert.h>

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <locale>
#include <unordered_map>
#include <vector>

static std::string ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  [](char c) { return !std::isspace(c); }));
  return s;
}

static bool is_not_empty(std::string s) {
  if (s.length() == 0) return false;
  if (ltrim(s).length() == 0) return false;
  return true;
}

class FileConfigManager {
  std::string dir;
  std::string filename;
  char delimiter;
  std::unordered_map<std::string, std::string> kv_map;

  bool is_file_present();

 public:
  FileConfigManager(std::string dir, std::string filename) {
    assert(is_not_empty(dir));
    assert(is_not_empty(filename));
    this->dir = dir;
    this->filename = filename;
    this->delimiter = '=';
  }

  FileConfigManager(std::string dir, std::string filename, char delimiter)
      : dir(dir), filename(filename) {
    this->delimiter = delimiter;
  }

  std::string get_path();
  void dump();
  bool load();
  bool save();
  std::string get(std::string key);
  std::string get(std::string key, std::string default_value);
  void put(std::string key, std::string value);
  bool remove(std::string key);
  void extract(std::unordered_map<std::string, std::string> &map);
};

std::string FileConfigManager::get_path() { return this->dir + this->filename; }

bool FileConfigManager::is_file_present() {
  bool present = false;
  std::ifstream fin;
  fin.open(this->get_path(), std::ios_base::in);
  if (fin) present = true;
  fin.close();
  return present;
}

bool FileConfigManager::load() {
  bool present_before_load = this->is_file_present();
  std::ifstream fin;
  fin.open(this->get_path(), std::ios_base::app);
  fin.seekg(0);
  std::string line;
  while (std::getline(fin, line)) {
    std::string key, value;
    int delimiter_found = 0;
    for (int32_t i = 0; i < line.length(); i++) {
      if (line[i] == this->delimiter) {
        delimiter_found += 1;
        continue;
      }
      if (delimiter_found == 0)
        key += line[i];
      else if (delimiter_found == 1)
        value += line[i];
      else
        break;
    }
    this->kv_map[key] = value;
  }
  fin.close();
  return !present_before_load;
}

bool FileConfigManager::save() {
  bool present_before_load = this->is_file_present();
  std::ofstream fout;
  std::vector<std::string> keys;

  fout.open(this->get_path(), std::ios_base::trunc);
  for (auto kv : this->kv_map) {
    keys.push_back(kv.first);
  }
  std::sort(keys.begin(), keys.end());
  for (auto k : keys) {
    std::string value = this->kv_map[k];
    fout << k << this->delimiter << value << std::endl;
  }
  fout.close();
  return !present_before_load;
}

void FileConfigManager::dump() {
  std::cout << "dir: " << this->dir << std::endl;
  std::cout << "filename: " << this->filename << std::endl;
  std::cout << "full path: " << this->get_path() << std::endl;
  std::cout << "delimiter: " << this->delimiter << std::endl;
  for (auto kv : this->kv_map) {
    std::string key = kv.first;
    std::string value = kv.second;
    std::cout << "[" << key << this->delimiter << value << "]" << std::endl;
  }
}

std::string FileConfigManager::get(std::string key) {
  if (this->kv_map.find(key) == this->kv_map.end()) {
    return "";
  }
  return this->kv_map[key];
}
std::string FileConfigManager::get(std::string key, std::string default_value) {
  std::string value = this->get(key);
  if (is_not_empty(value)) return value;
  return default_value;
}

void FileConfigManager::put(std::string key, std::string value) {
  assert(is_not_empty(key));
  assert(is_not_empty(value));
  this->kv_map[key] = value;
}

bool FileConfigManager::remove(std::string key) {
  if (this->kv_map.find(key) == this->kv_map.end()) return false;
  this->kv_map.erase(key);
  return true;
}

void FileConfigManager::extract(
    std::unordered_map<std::string, std::string> &map) {
  for (auto kv : this->kv_map) {
    map[kv.first] = kv.second;
  }
}

int main(int argc, char **argv) {
  FileConfigManager fcm("./", "local.env");
  bool created_file = fcm.load();
  std::cout << "Config file created? " << created_file << std::endl;
  fcm.dump();

  std::cout << "env:" << fcm.get("env") << std::endl;
  std::cout << "level:" << fcm.get("level") << std::endl;
  std::cout << "level:" << fcm.get("level", "info") << std::endl;

  fcm.put("testput", "true");
  fcm.put("testput1", "false");
  fcm.remove("testput1");
  created_file = fcm.save();
  std::cout << "Config file created? " << created_file << std::endl;

  std::unordered_map<std::string, std::string> map;
  fcm.extract(map);
  std::cout << "config size:" << map.size() << std::endl;
  return EXIT_SUCCESS;
}
