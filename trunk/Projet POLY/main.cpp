#include <iostream>
#include <fstream>
#include <string>
#include "Parser.hpp"
#include "Assembler.hpp"
#include "Interpreter.h"


#define TAILLE_MEMOIRE 512


using namespace std;

string affichage(string etq, string op, string ri, string rj, string rk, string nc){
	string aff;
	aff += (etq.empty()) ? "" : (etq + ": ");
	aff += op;
	aff += (ri.empty()) ? "" : (" " + ri);
	aff += (rj.empty()) ? "" : (", " + rj);
	aff += (rk.empty()) ? "" : (", " + rk);
	aff += (nc.empty()) ? "" : (", " + nc);
	return aff;
}

int main (int argc, char * const argv[]) {
	/*
	int a, b, c ,d, e;
	parseFile("test.txt");
	parseHexa(0x0207b800, &a, &b, &c, &d, &e);
	loadMemory("test2.txt");
	*/
	
	
	parseFile("test.txt");
	unsigned int* prog;
	prog = loadMemory("test.txt_asm");
	execMemory(prog);
	/**/
	
	//Test parsing
	/*
	string line, etq, op, ri, rj, rk, nc;
	
	ifstream inputFile ("test.txt", ios::in);
	ofstream outputFile ("test2.txt", ios::out | ios::trunc);
	while (getline(inputFile, line)) {
		parseText(&line, &etq, &op, &ri, &rj, &rk, & nc);
		outputFile << affichage(etq, op, ri, rj, rk, nc) << endl;
		line.clear(); etq.clear(); op.clear(); 
		ri.clear(); rj.clear(); rk.clear(); nc.clear();
	}
	inputFile.close();
	outputFile.close();
	*/
	
    return 0;
}