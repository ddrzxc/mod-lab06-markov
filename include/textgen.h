// Copyright 2024 Darya Rybakova
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

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
    explicit TextGen(int npref);
    void loadInput(std::istream &istream);
    std::string createText(int words);
    void loadStatetab(std::map<prefix, std::vector<std::string> > stab);
    std::string getSuffix(prefix pref);
};

#endif  // INCLUDE_TEXTGEN_H_
