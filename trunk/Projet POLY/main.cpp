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
	string input = "", output = "";
	cout << "Veuillez entrer le chemin du fichier à assembler" << endl;
	getline(cin, input, '\n');
	cout << "Veuillez entrer le chemin du fichier de sortie" << endl;
	getline(cin, output, '\n');
	if (translateFile(input, &output))
		execMemory(loadMemory(output));
	else
		cout << "Erreur à l'assemblage du fichier texte" << endl << "Fin du programme" << endl;

    return 0;
}