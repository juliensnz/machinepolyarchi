#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <string>
#include <map>

/* Cette fonction lis un fichier source, traduit les instructions une à une grâce
 * a la fonction de conversion, et remplis le fichier de sortie (avec des entiers
 * au format hexadécimal) Une première lecture du fichier source permet d'associer
 * les etiquettes à leur numéro de ligne dans un dictionnaire. Elle renvoie vrai
 * en cas de succès, faux en cas d'erreur.
 */
bool translateFile(std::string inputPath, std::string *outputPath);

/* Fonction qui prend en paramètre une instruction parsée, des dictionnaires, et
 * le numéro de ligne courrant; et qui retourne l'entier correspondant. L'entier 
 * est codé selon le schéma présenté dans le sujet. Cette fonction gère également
 * les étiquettes.
 */
unsigned int convert(std::string commande,
					 std::string ri,
					 std::string rj,
					 std::string rk,
					 std::string nc,
					 std::map <std::string, int> opcodeToInt,
					 std::map <std::string, int> regToInt,
					 std::map <std::string, int> etiquettes,
					 int currLine);

/* Fonction qui permet de convertir un entier contenu dans une chaine, passée en
 * paramètre, en entier signé ou non
 */
int toInt(std::string s);

#endif // ASSEMBLER_HPP
