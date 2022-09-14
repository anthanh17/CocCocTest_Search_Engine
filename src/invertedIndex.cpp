#include "invertedIndex.hpp"

InvertedIndex::InvertedIndex() {}
InvertedIndex::~InvertedIndex() {}

std::map<std::string, std::set<std::string> > InvertedIndex::getDictionary(void) {
    return _dictionary;
}

void InvertedIndex::buildDictionary(const std::string& filename) {
    std::ifstream fp;
    fp.open(filename, std::ios::in);
    if(!fp.good()) {
        std::cout<<"File Not Found\n";
        return;
    }

    std::string line,word;
    while (getline(fp, line)) {
        std::stringstream s(line);
        while (s >> word) {
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
                return std::tolower(c); 
            });
            std::regex wordRegex("(\\w+)");
            auto wordsBegin = std::sregex_iterator(word.begin(), word.end(), wordRegex);
            auto wordsEnd = std::sregex_iterator();
            for (auto it = wordsBegin; it != wordsEnd; ++it) {
                _dictionary[it->str()].insert(filename);
            }
        }
    }
    fp.close();
}

void InvertedIndex::showFileNameWithWord(const std::set<std::string>& words){
    std::cout << "Dictionary \n";
    for (const auto& w : words) {
        std::cout << "==========================\n";
        std::cout << "-> "<< w << " <-"<< ": \n";
        for (auto it = _dictionary[w].begin(); it != _dictionary[w].end(); ++it) {
            std::cout << *it << "\n";
        }
    }
}