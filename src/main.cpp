// Copyright 2024 Darya Rybakova
#include "../include/textgen.h"

const int NPREF=2; // количество слов в префиксе
const int MAXGEN=1000; //объем текста на выходе

int main() {
    TextGen textGen(NPREF);
    std::ifstream ifsteam("balda.txt");
    textGen.loadInput(ifsteam);
    std::cout << textGen.createText(1000) << "\n";
}
