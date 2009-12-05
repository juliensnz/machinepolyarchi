/*#include "Interpreter.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>

#define TAILLE 100

using namespace std;

char * returnLigne(int numeroLigne) {
	char * ligne= (char*)malloc(sizeof(char)*100);
	char courant;
	int cpt = 0;
	ifstream pointFichier("instructions.txt", ios::in);
	if(pointFichier){
		for (int i=1; i<numeroLigne; i++){
			pointFichier.get(courant);
			while(courant!='\n'){
				pointFichier.get(courant);
			}
		}
		pointFichier.get(courant);
		while(courant != '\n'){
			cout << courant << endl;
			ligne[cpt] = courant;
			cpt++;
			pointFichier.get(courant);
		}
		
		pointFichier.close();
	}else{
		printf("Erreur ouverture flux fichier");
	}
	printf("%s\n", ligne);
	pointFichier.close();
	return ligne;
}

int nbLigne(){
	ifstream pointFichier("instructions.txt", ios::in);
	int cpt=0;
	char courant;
	if(pointFichier){
		while (!pointFichier.eof()){
			pointFichier.get(courant);
			if (courant == '\n'){cpt++;}
		}
		
		pointFichier.close();
	}else{
		printf("Erreur ouverture flux fichier");
	}
	return --cpt;
}


int main (int argc, char * const argv[]){
	int numeroLigne = 2;
	char * ligne;
	returnLigne(3);
	printf("Voici le nb de lignes : %d", nbLigne());
	
	int lr;
	int numeroInstruction;
	short int reg[4];
	
	//si l'opérateur == 9 alors fin du end du programme
	while (op!=9) {
		// je suppose que toutes les lignes de code assembleurs sont bien séparer par une fonction qui me retourne l'opcode, avec les trois registres, ainsi que la constante.
		//opérations possibles
		switch (op) {
				//load
			case 0:
				reg[ri] = cst;
				break;
				
				//read, lit un entier au clavier et le rentre dans ri
			case 1:
				int entier1;
				cout << "Veuillez rentrer un entier : " << endl;
				cin >> entier1;
				cout << endl;
				reg[ri] = (short int)entier1;
				break;
				
				//print
			case 2:
				printf("Voici le contenu de ri : %d\n", reg[ri]);
				break;
				
				//pow1
			case 3:
				reg[ri] = (short int)pow(reg[rj], cst);
				break;
				
				//pow2
			case 4:
				reg[ri] = (short int)pow(reg[rj], reg[rk]);
				break;
				//daxpy
			case 5:
				reg[ri] = reg[ri] + reg[rj] * reg[rk];
				break;
				
				//setlr
			case 6:
				lr = 1;
				break;
				//resetlr
			case 7:
				lr = 0;
				break;
				//loop
			case 8:
				if (reg[0] < reg[ri]){
					numeroInstruction = numeroInstruction + cst;
				}
				if(lr == 1){
					reg[0]++;
				}else {
					reg[0]--;
				}
				break;
			default:
				break;
		}
	}
	
	
}*/