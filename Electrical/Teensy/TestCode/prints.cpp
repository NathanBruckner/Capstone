
/*
contains
 * the print functions that are used by both the asset class and
 *
 * main.
 *
This helps reduce duplicate code. I could include all of this at the
 *
 *
 * end of main and then include the extra lines, but it was easier (and
 *
 * cleaner,
 * in my opinion), to call some of these functions in both the
 * asset
 * class and
 * main

*/

#include "prints.h"

void printFlag(std::ostream &out) {

  symLineOut('-', 80, out);

  out << std::endl;

  centerWordOut(80, "Health Care Options Inc.", out);

  out << std::endl;

  symLineOut('-', 80, out);
}

void printOptions(std::ostream &out) {

  int leftw = 15;

  out << std::setw(leftw) << " " << "1. Enter inputs\n";

  out << std::setw(leftw) << " "

      << "2. Print depreciation schedule to screen\n";

  out << std::setw(leftw) << " "

      << "3. Print depreciation schedule to a file\n";

  out << std::setw(leftw) << " " << "4. Exit\n";

  out << std::endl;
}

void printExit(std::ostream &out) {

  symLineOut('-', 80, out);

  out << std::endl;

  centerWordOut(80, "Thank you for using the Depreciation Calcuator System",

                out);

  out << std::endl;

  symLineOut('-', 80, out);

  out << std::endl << std::endl;
}

void printEndFlag(std::ostream &out) {

  symLineOut('-', 80, out);

  out << std::endl;

  centerWordOut(80, "End of Report", out);

  out << std::endl;

  symLineOut('-', 80, out);
}
