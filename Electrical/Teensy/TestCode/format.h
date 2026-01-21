
#ifndef __FORMAT__
#define __FORMAT__

#include <iomanip>
#include <iostream>
#include <string>
void symLineOut(char symbol, int width, std::ostream &out);
void symLine(char symbol, int width);
void symLineWord(char symbol, int width, std::string word);
void centerWord(int width, std::string word);
void centerWordOut(int width, std::string word, std::ostream &out);
void centerWordNR(int width, std::string word, std::ostream &out);
#endif
