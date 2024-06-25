// Copyright 2024 Darya Rybakova

#include <iostream>
#include <deque>
#include <string>
#include <map>
#include <vector>
#include <random>
#include <fstream>

typedef std::deque<std::string> prefix; // очередь префиксов

class TextGen {
    private:
    std::map<prefix, std::vector<std::string> > statetab; // префикс-суффиксы
    int npref = 0;
    public:
    TextGen(int npref);
    void loadInput(std::istream &istream);
    std::string createText(int words);
};