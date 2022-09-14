#ifndef Search_H
#define Search_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Search final {
private:
    std::shared_ptr<InvertedIndex> _data;
    std::shared_ptr<Tokenize> _parser;
    std::vector<std::string> _fileName{};
public:
    Search();
    ~Search();
    std::shared_ptr<InvertedIndex> getInvertedIndex(void);

    std::shared_ptr<Tokenize> getTokenize(void);

    std::vector<std::string> getListFileName(void);

    bool searchWord(std::string& word);
};

#endif 