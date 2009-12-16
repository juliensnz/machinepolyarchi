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


/* La fonction loadMemory se charge de stocker dans un tableau d'entiers les
 * instructions en hexadecimal contenues dans le fichier texte.
 */
unsigned int* loadMemory(string inputPath){
	unsigned int* memory = new unsigned int[TAILLE_MEMOIRE];
	int i = 0;
	string line = "";
	ifstream inputFile (inputPath.c_str(), ios::in);
	//Initialisation du fichier
	if (inputFile){
		while (getline(inputFile, line) && i < TAILLE_MEMOIRE) {
			if (!line.empty()){
				//Si la ligne n'est pas vide
				istringstream iss(line);
				//On initialise un nouveau flux
				iss >> hex >> memory[i];
				//On stocke dans le tableau la ligne contenant un entier, en faisant
				//la conversion
				i++;
			}
		}
	}
	else{
		cerr << "Erreur à l'ouverture du fichier" << endl;
		memory[0] = 0x90000000; 
		//Instruction de fin de programme dans la première case
	}	
	return memory;
	//On retourne un pointeur vers le tableau
}


void execMemory(unsigned int* memory){
	char registres[6] = {0};
	int opcode, ri, rj, rk, nc, i = 0;
	
	while (i < TAILLE_MEMOIRE) {
		if (memory[i] != 0) {
			parseHexa(memory[i], &opcode, &ri, &rj, &rk, &nc);
			i++;
			switch (opcode) {
				case 0: //Load ri, c
					registres[ri] = nc;
					break;
				case 1: //Read ri
					registres[ri] = getInt();
					break;
				case 2://Print ri
					cout << setw(3) << setfill('0') << (int)registres[ri] << endl;
					break;
				case 3://Pow sur un entier
					registres[ri] = pow(registres[rj], nc);
					break;
				case 4://Pow sur un registre
					registres[ri] = pow(registres[rj], registres[rk]);
					break;
				case 5://daxpy
					registres[ri] = registres[ri] + registres[rj] * registres[rk];
					break;
				case 6://setLr
					registres[0] = 1;
					break;
				case 7://resetLr
					registres[0] = 0;
					break;
				case 8://Loop
					if (registres[1] < registres[ri]){
						i += nc - 1;
						registres[1] += (registres[0] == 1) ? 1 : -1;
					}
					break;
				case 9://End
					cout << "Exit" << endl;
					return;
					break;
				default://Sinon, end
					cout << "Exit" << endl;
					return;
					break;
			}
		}
	}	
}

//getInt récupère un entier et le retourne
int getInt(){
	int i = 0;
	cout << "Veuillez entrer un entier" << endl << "entrée : ";
	cin >> i;
	if (i < -128 || i > 127)
		return getInt();
		//si l'entier est trop grand ou trop petit
	else
		return i;
}