#include "tokenize.hpp"

Tokenize::Tokenize(){}

Tokenize::~Tokenize(){}

std::set<std::string> Tokenize::getInputEnv(void) {
    return _inputEnv;
}

void Tokenize::inputEnvParser(std::string& word) {
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    std::regex wordRegex("(\\w+)");
    auto wordsBegin = std::sregex_iterator(word.begin(), word.end(), wordRegex);
    auto wordsEnd = std::sregex_iterator();
    for (auto it = wordsBegin; it != wordsEnd; ++it){
        _inputEnv.insert(it->str());
    }       
}