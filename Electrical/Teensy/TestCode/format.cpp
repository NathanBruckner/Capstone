
/*
This file contains various formatting functions written by Nathan Bruckner
*/

#include "format.h"

void centerWord(int width,
                std::string word) { // function that outputs a centered string
  // in a fixed width
  int edges = (width - word.length()) /
              2; // finds how many characters belong on each side of the string
  // to center it in the given width
  std::cout << std::setfill(' ') << std::setw(edges) << " " << word
            << std::setw(edges) << " " << std::endl
            << std::setfill(' ') << std::setfill(' ');
}

void symLineWord(
    char symbol, int width,
    std::string word) { // outputs a word in the middle of a line of characters
  // with a width corresponding to "width"
  int edges = (width - word.length()) /
              2; // finds how many characters belong on each side of the string
  std::cout << std::setfill(symbol) << std::setw(edges) << word
            << std::setw(edges) << symbol << std::endl
            << std::setfill(' ');
}

void symLine(char symbol,
             int width) { // just fills a set width with a specified character
  std::cout << std::setfill(symbol) << std::setw(width) << symbol << std::endl
            << std::setfill(' ');
}

void centerWordOut(int width, std::string word,
                   std::ostream &out) { // like centerWord, but able to specify
  // the output stream
  int edges = (width - word.length()) / 2;
  out << std::setfill(' ') << std::setw(edges) << " " << word
      << std::setw(edges) << " " << std::endl
      << std::setfill(' ') << std::setfill(' ');
}

void symLineOut(
    char symbol, int width,
    std::ostream &out) { // like symLine, but able to specify the output stream
  out << std::setfill(symbol) << std::setw(width) << symbol << std::endl
      << std::setfill(' ');
}
void centerWordNR(int width, std::string word, std::ostream &out) {

  int edges = (width - word.length()) / 2;

  out << std::setfill(' ') << std::setw(edges) << " " << word

      << std::setw(edges) << " ";
}
