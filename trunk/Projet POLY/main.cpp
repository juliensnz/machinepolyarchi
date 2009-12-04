#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Assembler.hpp"

using namespace std;

int main (int argc, char * const argv[]) {
    /*
	test("ET1: setlr");
	test("ET3: read r0");
	test("ET2: load r0, 3");
	test("pow r0, r1, r2;00000");
	test("pow r0, r1, 0;00000");
	*/
	parseFile("", "test.txt");

    return 0;
}
