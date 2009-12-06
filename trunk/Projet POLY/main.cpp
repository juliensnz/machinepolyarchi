#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Assembler.hpp"
#include "Interpreter.h"

using namespace std;

int main (int argc, char * const argv[]) {
	int a, b, c ,d, e;
	parseFile("test.txt");
	parseHexa(0x0207b800, &a, &b, &c, &d, &e);
	loadMemory("test2.txt");
    return 0;
}