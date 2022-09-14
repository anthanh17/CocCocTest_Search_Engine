#include "invertedIndex.hpp"
#include "tokenize.hpp"
#include "search.hpp"

#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;

void buildDictionary(std::shared_ptr<InvertedIndex> data, std::string path, std::set<std::string> lookUpStrings) {
    try {
        for (const auto & file : fs::recursive_directory_iterator(path)) {
        if(is_regular_file(file)) {
            data->buildDictionary(file.path().string());
        }
    }
    }
    catch(std::filesystem::filesystem_error const& ex) {
        std::cout
            << "Invalid path!\n" << ex.what() << '\n';
    }
    //std::cout << "\nBuild Dictionary";
    //data->showFileNameWithWord(lookUpStrings);
}

std::set<std::string> inputHanlder(std::string& manyWords, std::string path, std::shared_ptr<Search> search) {
    auto tokenize = search->getTokenize();
    tokenize->inputEnvParser(manyWords);

    std::set<std::string> lookUpStrings{};
    
    lookUpStrings = std::move(tokenize->getInputEnv());
    // std::cout << "Vector lookUpStrings: \n";
    // for (auto s : lookUpStrings) {
    //     std::cout << " - " << s << "\n";
    // }

    auto data = search->getInvertedIndex();
    buildDictionary(data, path, lookUpStrings);

    return lookUpStrings;
}

void searchHandler(std::set<std::string> lookUpStrings, std::shared_ptr<Search> search) {
    for (auto word : lookUpStrings) {
        if (search->searchWord(word)){
            continue;
        }
    }
}

void booleanLogic(std::shared_ptr<Search> search, std::set<std::string> lookUpStrings) {
    auto listFileName = std::move(search->getListFileName());

    // std::cout << "\nList file contain words: " << "\n";
    // for (auto l : listFileName){
    //     std::cout << l << std::endl;
    // }
    // std::cout << std::endl;

    int count = lookUpStrings.size();
    std::unordered_map <std::string, int> mMap{};
    for (auto &a : listFileName) {
        mMap[a] ++;
    }
    // std::cout << "Count of parameters: "<< count << std::endl;
    // std::cout << "\nFile occurrences: \n";
    // for(auto it = mMap.cbegin(); it != mMap.cend(); ++it) {
    //     std::cout << it->first << " -- " << it->second << "\n";
    // }
    // std::cout << std::endl;
    std::set<std::string> result{};
    for (auto& file : listFileName) {
        if(mMap[file] == count) {
            result.insert(file);
        }
    }

    //std::cout << "Final result: \n";
    if (result.empty()) {
        std::cout<<"No instance exist\n";
    }
        
    for (const auto& rel : result) {
        std::cout << rel << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::string path{};         // path to directory
    std::string manyWords{};    // search words
    
    if (argc < 2) {
        std::cerr << "Syntax error!  \n\t" 
                  << "> coccoc “many words” [path to directory]" << std::endl; 
        return 1;
    } else if (argc < 3) {
        manyWords = std::move(argv[1]);
        path = std::move("./");
    } else {
        manyWords = std::move(argv[1]);
        path = std::move(argv[2]);
    }

    auto search = std::make_shared<Search>();
    auto lookUpStrings = inputHanlder(manyWords, path, search);
    searchHandler(lookUpStrings, search);
    booleanLogic(search, lookUpStrings);
    return 0;
}