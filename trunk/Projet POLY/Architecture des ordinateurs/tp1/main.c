#include <stdio.h>
#include <math.h>
#include <string.h>
#define TAILLE 5;

typedef unsigned int Index;

typedef struct machin {
	double *ptTab;
	Index nbElement;
} Tableau;

void afficherTableau(Tableau tab)
{
		for (int i = 0; i<tab.nbElement; i++) {
			printf("valeur %d : %f\n",i,tab.ptTab[i]);
		}
}

void echange(Tableau tab,Index index1, Index index2)
{
	if(index1 != index2)
	{
		int temp = tab.ptTab[index1];
		tab.ptTab[index1] = tab.ptTab[index2];
		tab.ptTab[index2] = temp;
	}
	else
	{
		printf("les deux index entrées sont identiques !");
	}
}
		

int main (int argc, const char * argv[]) {

	double tableauDeTest[5] = { 3.4, -6.5, 19.2, 9, 4.23 } ;
	Tableau test = {tableauDeTest,5};
	afficherTableau(test);
	echange(test,2,3);
	afficherTableau(test);
	}
