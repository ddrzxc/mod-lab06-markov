// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(textgen, test1) {
    TextGen textGen(3);
    std::ifstream ifstream("test.txt");
    textGen.loadInput(ifstream);
    auto statetab = textGen.getStatetab();
    for (auto elem : statetab) {
        EXPECT_EQ(3, elem.first.size());
    }
}

TEST(textgen, test2) {
    TextGen textGen(2);
    std::ifstream ifstream("test.txt");
    textGen.loadInput(ifstream);
    auto statetab = textGen.getStatetab();
    EXPECT_EQ(31, statetab.size());
}

TEST(textgen, test3) {
    TextGen textGen(2);
    std::ifstream ifstream("test.txt");
    textGen.loadInput(ifstream);
    prefix pref = {"рыбатекст", "используется"};
    EXPECT_EQ("дизайнерами,", textGen.getSuffix(pref));
}

TEST(textgen, test4) {
    TextGen textGen(1);
    std::map<prefix, std::vector<std::string> > statetab = {
        {{"кошка"}, {"собака", "кошка"}},
    };
    textGen.loadStatetab(statetab);
    std::string res = textGen.createText(2);
    EXPECT_EQ(true, res == "кошка собака" || res == "кошка кошка");
}

TEST(textgen, test5) {
    TextGen textGen(1);
    std::map<prefix, std::vector<std::string> > statetab = {
        {{"кошка"}, {"собака", "кошка"}},
        {{"собака"}, {"кошка", "собака"}},
    };
    textGen.loadStatetab(statetab);
    std::string res = textGen.createText(20);
    int words = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == ' ')
            words++;
    }
    words++
    EXPECT_EQ(20, words);
}
