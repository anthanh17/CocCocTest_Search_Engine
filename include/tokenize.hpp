#ifndef Tokenize_H
#define Tokenize_H

#include <set>
#include <regex>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>


class Tokenize final {
private:
    std::set<std::string> _inputEnv{};
public:
    Tokenize();
    ~Tokenize();
    
    std::set<std::string> getInputEnv(void);

    void inputEnvParser(std::string& word);
};

#endif 