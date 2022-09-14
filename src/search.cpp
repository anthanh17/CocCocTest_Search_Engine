#include "invertedIndex.hpp"
#include "tokenize.hpp"
#include "search.hpp"

Search::Search() {
    _data = std::make_shared<InvertedIndex>();
    _parser = std::make_shared<Tokenize>();
}

Search::~Search(){}

std::shared_ptr<InvertedIndex> Search::getInvertedIndex(void) {
    return _data;
}

std::shared_ptr<Tokenize> Search::getTokenize(void) {
    return _parser;
}

std::vector<std::string> Search::getListFileName(void) {
    return _fileName;
}

bool Search::searchWord(std::string& word) {
    // not found
    auto dictionary = _data->getDictionary();
    if (dictionary.find(word) == dictionary.end()) {
        //std::cout<<"No instance exist\n";
        return true;
    }

    // found
    for (auto it = dictionary[word].begin(); it != dictionary[word].end(); ++it) {
        _fileName.push_back(*it);
    }
    return false;
}