#include "Parser.hpp"
#include "Assembler.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

void parseFile(string inputPath, string outputPath){
	if (!inputPath.empty()) {
		if (outputPath.empty())
			outputPath = inputPath + "_asm";
		//Si le chemin de sortie n'est pas spécifié, on crée le fichier dans
		//le même répertoire, nomSortie = nomEntree_asm
		
		map <string, int> opcodeToInt, regToInt;
		
		opcodeToInt["load"]    = 0;
		opcodeToInt["read"]    = 1;
		opcodeToInt["print"]   = 2;
		opcodeToInt["pow"]     = 3;
		opcodeToInt["daxpy"]   = 5;
		opcodeToInt["setlr"]   = 6;
		opcodeToInt["resetlr"] = 7;
		opcodeToInt["loop"]    = 8;
		opcodeToInt["end"]     = 9;
		//tableau associatif de correspondace entre les commandes et leur code opération.
		
		regToInt[""]   = 0;
		regToInt["r0"] = 1;
		regToInt["r1"] = 2;
		regToInt["r2"] = 3;
		regToInt["r3"] = 4;
		regToInt["r4"] = 5;
		//tableau associatif entre les différents registres et leur code valeur
		//Deux dictionnaires de conversion
		
    	ifstream inputFile(inputPath.c_str(), ios::in);
    	ofstream outputFile(outputPath.c_str(), ios::out | ios::trunc);
		//Ouverture des deux fichiers, ecrasement de l'eventuel fichier de sortie
		//preexistant
    	if(inputFile && outputFile){
    	    string line, etq, cmd, ri, rj, rk, nc;
    	    int nbLigne = 0;
			map <string, int> etiquettes;
			//Création de la map contenant les étiquètes
			
			while (!inputFile.eof()) {
				getline(inputFile, line);
				if (!line.empty()){
					//Si la ligne n'est pas vide
					nbLigne++;
					getEtiq(&line, &etq);
					//On récupere l'etiquette eventuelle					
					if (!etq.empty())
						//S'il y a une etiquette
						etiquettes[etq] = nbLigne;
					//cout << "|"+etq+"|" << " " << nbLigne << " " << etiquettes[etq] << endl;
						//On enregistre dans la table "etiquettes" le numero de ligne associé au nom de l'étiquette
				}
			}
			//Premier parcour du fichier pour enregistrer la position des étiquettes.
			
			inputFile.clear();
			inputFile.seekg(0, ios::beg);
			nbLigne = 0;
			//Retour au début du fichier et remise à 0 des paramètres de lecture.
			
    	    while(!inputFile.eof()){
    	        getline(inputFile, line);
    	        if (!line.empty()){
					nbLigne++;
					parseText(&line, &etq, &cmd, &ri, &rj, &rk, &nc);
					//parsing de la ligne par la fonction parseText
					outputFile << "0x" << setfill('0') << setw(8) << hex << convert(cmd, ri, rj, rk, nc, opcodeToInt, regToInt, etiquettes, nbLigne) << endl;
					//enregistrement dans le fichier de sortie la ligne assemblée.
				}
    	    }
			//Second parcour du fichier pour traitement
        inputFile.close();
        outputFile.close();
    	}
    	else
			cerr << "Echec de l'ouverture / creation d'un des fichiers" << endl;
    }
    else
    	cerr << "Pas de chemin de fichier" << endl;
}

unsigned int convert(string commande,
					 string ri,
					 string rj,
					 string rk,
					 string nc,
					 map <string, int> opcodeToInt,
					 map <string, int> regToInt,
					 map <string, int> etiquettes,
					 int currLine){
	
	unsigned int result = opcodeToInt[commande];
	//on initialise le résultat avec le code de la commande
	
	if (result == 3 && nc.empty())
		result = 4;
		//si la commande est pow et que la constante est vide on change le code en powBis
	else if (result == 8){
		//Si le code est "loop"
		if (!isInt(&rj)){
			//cout << "|"+rj+"|" << " ";
			//cout << etiquettes[rj] << endl;
			int i = etiquettes[rj] - currLine;
			stringstream iss;
			iss << i;
			iss >> nc;
			//cout << nc << endl;
			//rj prend pour valeur la difference entre la ligne actuelle et la ligne
			//correspondant a l'etiquette
		}
	}
	
	result <<= 3;
	//Probleme avec l'opcode 0, decalage de 0 = 0
	//Réglé a l'écriture dans le fichier
	result += regToInt[ri];
	result <<= 3;
	result += regToInt[rj];
	result <<= 3;
	result += regToInt[rk];
	result <<= 8;
	result += (0x000000ff & toInt(nc));
	result <<= 11;
	//conversion des commandes en int.
	return result;
}

int toInt(string s){
	int c;
	if (!s.empty()) {
		istringstream iss (s);
		if (s[0] == '-'){
			(signed int) c;
			iss >> c;
		}
		else {
			(unsigned int) c;
			iss >> c;
		}
		return c;
	}
	else return 0;
}
