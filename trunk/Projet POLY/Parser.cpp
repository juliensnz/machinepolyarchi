#include "Parser.hpp"
#include <iostream>
#include <sstream>

using namespace std;

/* La fonction parse permet de parser une chaine d'instruction,
 * et d'en récuperer les elements via les arguments.
 * La chaine instruction passée en argument est détruite par l'opération.
 */ 
void parse(string *instruction,
		   string *etiquette,
		   string *commande,
		   string *ri,
		   string *rj,
		   string *rk,
		   string *nc) {
	
	if (!instruction->empty()){
	//Si la ligne est non vide
	    unComment(instruction); 
		//On retire les commentaires eventuels
        trim(instruction);
		//On retire les espaces en début et en fin de chaine
        getToken(instruction, etiquette, ':');
		//On récupere l'etiquette ou ""
        getToken(instruction, commande, ' ');
		//On recupere la commande ou ""
        getToken(instruction, ri, ',');
		//On recupere le premier paramètre ou ""
        getToken(instruction, rj, ',');
		//On recupere le second paramètre ou ""
        getToken(instruction, rk, '\0');
		//On recupere le reste de la ligne
		/* Les valeurs sont stockée respectivement dans
		 * etiquette, commande, ri, rj, rk
		 */
        if (commande->empty()) {
		/* Si commande est vide, on est en présence d'un instruction simple
		 * l'instruction {end, resetlr, setlr} se trouve alors dans rk,
		 * on copie le contenu de rk dans commande,
		 * on vide les autre parametres et on quitte la fonction.
		 */
			*commande = *rk;
            ri->clear(); rj->clear(); rk->clear(); nc->clear();
            return;
        }
        if (ri->empty()) {
		/* De manière similaire on à ici {read ri, print ri}
		 * On copie alors rk dans ri, et on vide les autres parametre et on quitte
		 */
            *ri = *rk;
            rj->clear(); rk->clear(); nc->clear();
            return;
        }
		// Si on arrive ici, on a une instruction de type cmd ri, rj [, rk]
		if (isInt(rk)) {
		//On teste si rk contient un entier
            *nc = *rk;
			//Si oui on le copie dans nc
            rk->clear();
			//Et on vide rk
        }
		else
            nc->clear();
			//Sinon on vide nc
		
		if (rj->empty()) {
		/* Si rj est vide, on y copie rk.
		 * /!\ rk == "" s'il avait été détecté comme un entier a l'etape precedente
		 */
            *rj = *rk;
            rk->clear();
        }
		/* Si le if précédent n'a pas été exécuté, rj est non vide.
		 * Même remarque que precedemment pour rk
		 */
		
        instruction->clear();
		//On vide instruction
	}
}

/* La fonction getToken renvoie soit la sous-chaine délitée par 0 et separator, soit ""
 * Si une sous-chaine est trouvée, on la retire de la ligne passée en argument
 * Ex: getToken("aaaa,bbb", &token, ',') aura pour resultat token == "aaaa" et line == "bbb"
 * Si le separateur est '\0', on renvoie toute la ligne
 */
void getToken(string *line, string *token, char separator){
	if (separator != '\0') {
	//Si le separateur n'est pas '\0'
		size_t i = ((line->find(separator) != string::npos) ? line->find(separator) : 0);
		//On trouve le separateur dans la chaine, et on stocke son index dans i
		//Si l'on ne trouve rien, i = 0
		
        *token = line->substr(0, i);
		//On extrait la sous-chaine, "" si i == 0
		if (i != 0) {
		//Si i different de 0, on efface la sous-chaine et le separateur de la chaine principale
			line->erase(0, ++i);
			trim(line);
			//On enleve les eventuels espaces en début de chaine
		}
	}
	else {
	//Si le separateur est '\0', on renvoie toute la chaine.
		*token = *line;
		line->clear();
	}

}

void getEtiq(string *line, string *etiquette){
	unComment(line);
	trim(line);
	getToken(line, etiquette, ':');
	line->clear();
}

void unComment(string *line){
	*line = line->substr(0, ((line->find(';') != string::npos) ? line->find(';') : line->size()));
}

void trim(string *line){
    if (!line->empty()){
        const char *separator = " \t\r\n";
        size_t i, j;

        i = line->find_first_not_of(separator);
        j = line->find_last_not_of(separator) - i + 1;
        *line = line->substr(i, j);
    }
}

bool isInt(string *s){
	string str =  *s;
	int test;
	
	if (str[0] == '-') str.erase(0,1);
	istringstream iss (str);
	return (iss >> test) && (iss.eof());
}
