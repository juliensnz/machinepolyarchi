#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

/* La fonction parseText permet de parser une chaine d'instruction,
 * et d'en récuperer les elements via les arguments.
 * La chaine instruction passée en argument est détruite par l'opération.
 */ 
void parseText(std::string *instruction,
			   std::string *etiquette,
			   std::string *commande,
			   std::string *ri,
			   std::string *rj,
			   std::string *rk,
			   std::string *nc);

/* De manière analogue à la fonction parseText, la fonction parseHexa extrait les
 * differents paramètres d'une instruction codée sous forme d'un entier hexadecimal.
 */
void parseHexa(int inst,
			   int *opcode,
			   int *ri,
			   int *rj,
			   int *rk,
			   int *nc);
/* La fonction getToken renvoie soit la sous-chaine délimitée par 0 et separator,
 * soit ""
 * Si une sous-chaine est trouvée, on la retire de la ligne passée en argument
 * Ex: getToken("aaaa,bbb", &token, ',') 
 * aura pour resultat token == "aaaa" et line == "bbb"
 * Si le separateur est '\0', on renvoie toute la ligne
 */
void getToken(std::string *line, std::string *token, char separator);
/* Adaptation réduite de la fonction parse, qui ne récupere que l'etiquette
 */
void getEtiq(std::string *line, std::string *etiquette);
/* Fonction dédiée à la suppression des eventuels commentaires
 * Si on trouve un ';', on renvoie la sous chaine délimitée par
 * le début et le ';'. Si la méthode find renvoie string::npos, 
 * le caractère ';' n'est pas dans la chaine et on renvoie alors
 * toute la chaine.
 */
void unComment(std::string *line);
/* Fonction dédiée à la suppression des espaces supperflus en début
 * et en fin de chaine. 
 * Par espaces, on entend les espaces, les tabulations, ...
 * On renvoie la sous-chaine délimitée par le premier non-espace
 * et le dernier non-espace. Les espaces à l'intérieur de la chaine
 * ne sont pas concernés.
 */
void trim(std::string *line);
/* Cette fonction renvoie True si la chaine contient un entier (relatif)
 * False sinon. On travaille sur une copie de la chaine, elle n'est donc pas
 * altérée par l'opération.
 */
bool isInt(std::string *s);

#endif // PARSER_HPP
