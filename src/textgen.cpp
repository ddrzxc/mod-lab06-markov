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
    for (int i = 0; i < words - npref; i++) {
        if (statetab[pref].empty())
            break;
        std::string suf = getSuffix(pref);
        result += suf + " ";
        pref.pop_front();
        pref.push_back(suf);
    }
    result.erase(result.size()-1);
    return result;
}

void TextGen::loadStatetab(std::map<prefix, std::vector<std::string> > stab) {
    this->statetab = stab;
}

std::string TextGen::getSuffix(prefix pref) {
    std::random_device rd;
    std::mt19937 gen(rd());
    auto suf = statetab[pref];
    std::uniform_int_distribution<> dist(0, suf.size()-1);
    int index = dist(gen);
    return suf[index];
}

std::map<prefix, std::vector<std::string> > TextGen::getStatetab() {
    return statetab;
}
