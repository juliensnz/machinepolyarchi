#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <string>
#include <map>

void parseFile(std::string path, std::string input, std::string *output = NULL);
std::string convert(std::string commande,
					std::string ri,
					std::string rj,
					std::string rk,
					std::string nc,
					std::map <std::string, std::string> translate,
					std::map <std::string, std::string> reg,
					std::map <std::string, std::string> binToHex,
					std::map <std::string, int> etiquettes
					int currLine);
std::string toBin(std::string s);
std::string toHex(std::string s, std::map <std::string, std::string> binToHex);


#endif // ASSEMBLER_HPP
