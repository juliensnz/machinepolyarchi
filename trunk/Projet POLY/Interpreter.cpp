#include "Interpreter.h"
#include "Parser.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

#define TAILLE_MEMOIRE 512

using namespace std;

unsigned int* loadMemory(string inputPath){
	unsigned int* memory = new unsigned int[TAILLE_MEMOIRE];
	int i = 0;
	string line = "";
	ifstream inputFile (inputPath.c_str(), ios::in);
	
	if (inputFile){
		while (getline(inputFile, line) && i < TAILLE_MEMOIRE) {
			if (!line.empty()){
				istringstream iss(line);
				iss >> hex >> memory[i];
				i++;
			}
		}
	}
	else
		cerr << "Erreur à l'ouverture du fichier" << endl;
	
	return memory;
}

void execMemory(unsigned int* memory){
	int registres[6] = {0};
	int opcode, ri, rj, rk, nc;
	
	for (int i = 0; i < TAILLE_MEMOIRE; i++) {
		parseHexa(memory[i], &opcode, &ri, &rj, &rk, &nc);
		switch (opcode) {
			case 0: //Load ri, c
				registres[ri] = nc;
				break;
			case 1: //Read ri
					//registres[ri] = getInt();
				break;
			case 2:
				cout << setw(3) << setfill('0') << registres[ri];
				break;
			case 3:
				registres[ri] = pow(registres[rj], nc);
				break;
			case 4:
				registres[ri] = pow(registres[rj], registres[rk]);
				break;
			case 5:
				registres[ri] = registres[ri] + registres[rj] * registres[rk];
				break;
			case 6:
				registres[0] = 1;
				break;
			case 7:
				registres[0] = 0;
				break;
			case 8:
				if (registres[1] < registres[ri]){
					i += nc;
					registres[1] += (registres[0] == 1) ? 1 : -1;
				}
				break;
			case 9:
				i = TAILLE_MEMOIRE;
				break;
			default:
				i = TAILLE_MEMOIRE;
				break;
		}
	}	
}