#include "Parser.hpp"
#include "Assembler.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

void parseFile(string path, string input, string *output){
    string inputPath = path + input;
	//Chemin + nom du fichier entrée
    string outputPath = (output) ? (path + *output) : (path + input + "_asm");
	//Si output est défini, chemin + nom fichier sortie,
	//Sinon chemin + nom du fichier entrée + _asm
	map <string, int> opcodeToInt, regToInt;
	
	if (!inputPath.empty()) {
		opcodeToInt["load"]    = 0;
		opcodeToInt["read"]    = 1;
		opcodeToInt["print"]   = 2;
		opcodeToInt["pow"]     = 3;
		opcodeToInt["daxpy"]   = 5;
		opcodeToInt["setlr"]   = 6;
		opcodeToInt["resetlr"] = 7;
		opcodeToInt["loop"]    = 8;
		opcodeToInt["end"]     = 9;
		
		regToInt[""]   = 0;
		regToInt["r0"] = 1;
		regToInt["r1"] = 2;
		regToInt["r2"] = 3;
		regToInt["r3"] = 4;
		regToInt["r4"] = 5;
		//Deux dictionnaires de conversion
		
    	ifstream inputFile(inputPath.c_str(), ios::in);
    	ofstream outputFile(outputPath.c_str(), ios::out | ios::trunc);
		//Ouverture des deux fichiers
    	if(inputFile && outputFile){
    	    string line, etq, cmd, ri, rj, rk, nc;
    	    int nbLigne = 0;
			map <string, int> etiquettes;

			while (!inputFile.eof()) {
				getline(inputFile, line);
				if (!line.empty()){
					nbLigne++;
					getEtiq(&line, &etq);
					etiquettes[etq] = nbLigne;
				}
			}
			inputFile.clear();
			inputFile.seekg(0, ios::beg);
			nbLigne = 0;
			
    	    while(!inputFile.eof()){
    	        getline(inputFile, line);
    	        if (!line.empty()){
					nbLigne++;
					parse(&line, &etq, &cmd, &ri, &rj, &rk, &nc);
					outputFile << "0x" << setfill('0') << setw(8) << hex << convert(cmd, ri, rj, rk, nc, opcodeToInt, regToInt, etiquettes, nbLigne) << endl;
				}
    	    }
        inputFile.close();
        outputFile.close();
    	}
    	else
            cerr << "Echec de l'ouverture du fichier" << endl;
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
	
	if (result == 3 && nc.empty())
		result = 4;
	else if (result == 8){
		//Gérer le loop
	}
	cout << hex << result << endl;
	result <<= 3;
	//Probleme avec l'opcode 0, decalage de 0 = 0
	cout << hex << result << endl;
	result += regToInt[ri];
	result <<= 3;
	cout << hex << result << endl;
	result += regToInt[rj];
	result <<= 3;
	cout << hex << result << endl;
	result += regToInt[rk];
	result <<= 8;
	cout << hex << result << endl;
	result += (0x000000ff & toBin(nc));
	result <<= 11;
	cout << hex << result << endl;
	return result;
}

int toBin(string s){
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
