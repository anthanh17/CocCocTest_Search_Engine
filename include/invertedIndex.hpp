#ifndef Inverted_Index_H
#define Inverted_Index_H

#include <set>
#include <map>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>

class InvertedIndex final {
private:
    // key: word -  value: list <file name>
    std::map<std::string, std::set<std::string> > _dictionary;
    std::vector<std::string> _words;

public:
    InvertedIndex();
    ~InvertedIndex();

    std::map<std::string, std::set<std::string> > getDictionary(void);

    void buildDictionary(const std::string& filename);

    void showFileNameWithWord(const std::set<std::string>& words);
};

#endif 