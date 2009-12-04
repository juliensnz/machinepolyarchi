#include "Parser.hpp"
#include "Assembler.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;



void parseFile(string path, string input, string *output){
    string inputPath = path + input;
    string outputPath = (output) ? (path + *output) : (path + input + "_asm");
	map <string, string> translate, reg, binToHex;
	
	translate["load"]    = "0000";
	translate["read"]    = "0001";
	translate["print"]   = "0010";
	translate["pow"]     = "0011";
	translate["daxpy"]   = "0101";
	translate["setlr"]   = "0110";
	translate["resetlr"] = "0111";
	translate["loop"]    = "1000";
	translate["end"]     = "1001";
	
	reg[""]   = "000";
	reg["r0"] = "001";
	reg["r1"] = "010";
	reg["r2"] = "011";
	reg["r3"] = "100";
	reg["r4"] = "101";
	
	binToHex["0000"] = "0";
	binToHex["0001"] = "1";
	binToHex["0010"] = "2";
	binToHex["0011"] = "3";
	binToHex["0100"] = "4";
	binToHex["0101"] = "5";
	binToHex["0110"] = "6";
	binToHex["0111"] = "7";
	binToHex["1000"] = "8";
	binToHex["1001"] = "9";
	binToHex["1010"] = "A";
	binToHex["1011"] = "B";
	binToHex["1100"] = "C";
	binToHex["1101"] = "D";
	binToHex["1110"] = "E";
	binToHex["1111"] = "F";

    if (!inputPath.empty()) {
    	ifstream inputFile(inputPath.c_str(), ios::in);
    	ofstream outputFile(outputPath.c_str(), ios::out | ios::trunc);
    	if(inputFile && outputFile){
    	    string line, etq, cmd, ri, rj, rk, c, code;
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
					parse(&line, &etq, &cmd, &ri, &rj, &rk, &c);
					outputFile << '$' << convert(cmd, ri, rj, rk, c, translate, reg, binToHex, etiquettes, nbLigne) << endl;
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

string convert(string commande,
			   string ri,
			   string rj,
			   string rk,
			   string nc,
			   map <string, string> translate,
			   map <string, string> reg,
			   map <string, string> binToHex,
			   map <string, int> etiquettes,
			   int currLine){
	string result;
	
	result = translate[commande];
	
	if (result == "0011" && nc.empty()){
		result = "0100";
	}	
	if (result == "1000"){
		//Gérer le loop
	}
	result += reg[ri];
	result += reg[rj];
	result += reg[rk];
	result += toBin(nc);
	result += "00000000000";
	result = toHex(result, binToHex);
	
	return result;
}

string toBin(string s){
	string result;
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
		for (int i = 31; i >= 0; i--) {
			result += (((c >> i) & 1) ? "1" : "0");
		}
		return result.substr(result.size() - 8, 8);
	}
	else return "00000000";
}

string toHex(string s, map <string, string> binToHex){
	string result;
	
	if (s.size()%4 == 0) {
		while (!s.empty()) {
			result += binToHex[s.substr(0, 4)];
			s.erase(0, 4);
		}
	}
	return result;
}
