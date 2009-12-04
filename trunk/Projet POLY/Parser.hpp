#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <map>

void parse(std::string *instruction,
		   std::string *etiquette,
		   std::string *commande,
		   std::string *ri,
		   std::string *rj,
		   std::string *rk,
		   std::string *nc);

void getToken(std::string *line, std::string *token, char separator);
void getEtiq(std::string *line, std::string *etiquette);
void unComment(std::string *line);
void trim(std::string *line);
bool isInt(std::string *s);

#endif // PARSER_HPP
