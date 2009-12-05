#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <string>
#include <map>

void parseFile(std::string inputPath, std::string outputPath = "");
unsigned int convert(std::string commande,
					 std::string ri,
					 std::string rj,
					 std::string rk,
					 std::string nc,
					 std::map <std::string, int> opcodeToInt,
					 std::map <std::string, int> regToInt,
					 std::map <std::string, int> etiquettes,
					 int currLine);
int toInt(std::string s);

#endif // ASSEMBLER_HPP
