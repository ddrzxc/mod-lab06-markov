// Copyright 2024 Darya Rybakova

#include "../include/textgen.h"

TextGen::TextGen(int npref) {
    this->npref = npref;
}

void TextGen::loadInput(std::istream &istream) {
    prefix pref;
    std::string elem;
    for (int i = 0; i < npref; i++) {
        istream >> elem;
        pref.push_back(elem);
    }
    while (istream >> elem) {
        auto &suf = statetab[pref];
        suf.push_back(elem);
        pref.pop_front();
        pref.push_back(elem);
    }
}

std::string TextGen::createText(int words) {
    prefix pref = statetab.begin()->first;
    std::string result;
    while (!pref.empty()) {
        result += pref.front() + " ";
        pref.pop_front();
    }
    pref = statetab.begin()->first;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < words - npref; i++) {
        if (statetab[pref].empty())
            break;
        auto suf = statetab[pref];
        std::uniform_int_distribution<> dist(0, suf.size()-1);
        int index = dist(gen);
        result += suf[index] + " ";
        pref.pop_front();
        pref.push_back(suf[index]);
    }
    result.erase(result.size()-1);
    return result;
}
