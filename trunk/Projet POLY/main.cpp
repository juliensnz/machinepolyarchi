#include <iostream>
#include <fstream>
#include <string>
#include "Parser.hpp"
#include "Assembler.hpp"
#include "Interpreter.h"


#define TAILLE_MEMOIRE 512


using namespace std;

/*string affichage(string etq, string op, string ri, string rj, string rk, string nc){
	string aff;
	aff += (etq.empty()) ? "" : (etq + ": ");
	aff += op;
	aff += (ri.empty()) ? "" : (" " + ri);
	aff += (rj.empty()) ? "" : (", " + rj);
	aff += (rk.empty()) ? "" : (", " + rk);
	aff += (nc.empty()) ? "" : (", " + nc);
	return aff;
}*/

int main (int argc, char * const argv[]) {
	
	parseFile("test.txt");
	execMemory(loadMemory("test.txt_asm"));
    return 0;
}