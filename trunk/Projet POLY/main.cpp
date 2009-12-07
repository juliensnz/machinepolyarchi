#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Assembler.hpp"
#include "Interpreter.h"


#define TAILLE_MEMOIRE 512


using namespace std;

int main (int argc, char * const argv[]) {
	/*
	int a, b, c ,d, e;
	parseFile("test.txt");
	parseHexa(0x0207b800, &a, &b, &c, &d, &e);
	loadMemory("test2.txt");
	*/
	
	
	parseFile("test.txt");
	
	unsigned int* prog = new unsigned int[TAILLE_MEMOIRE];
<<<<<<< .mine
	prog = loadMemory("test.txt_asm");
=======
	
	prog = loadMemory("test.txt_asm");
	
>>>>>>> .r28
	execMemory(prog);
	
	
    return 0;
}