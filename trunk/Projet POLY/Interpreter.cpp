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

/*
 * La fonction loadMemory se charge de stocker dans un tableau de sting
 * chaque ligne du fichier texte.
 * Elle fait les contrôles et supprime les lignes vides.
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
				//si la ligne n'est pas vide
				istringstream iss(line);
				//on initialise un nouveau flux
				iss >> hex >> memory[i];
				//on stocke dans le tableau la ligne en la convertissant en hexa.
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
				registres[ri] = getInt();
				break;
			case 2://Print ri
				cout << setw(3) << setfill('0') << registres[ri] << endl;
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
					i += nc;
					registres[1] += (registres[0] == 1) ? 1 : -1;
				}
				break;
			case 9://End
				cout << "Exit" << endl;
				i = TAILLE_MEMOIRE;
				return;
				break;
			default://Sinon, end
				cout << "Exit" << endl;
				i = TAILLE_MEMOIRE;
				return;
				break;
		}
	}	
}

//getInt récupère un entier et le retourne
int getInt(){
	int i = 0;
	cout << "Veuillez entrer un entier" << endl << "entrée : ";
	cin >> i;
	if (i < -255 || i > 255)
		return getInt();
		//si l'entier est trop grand ou trop petit
	else
		return i;
}