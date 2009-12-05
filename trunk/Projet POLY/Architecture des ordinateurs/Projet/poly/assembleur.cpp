/*
 *  assembleur.cpp
 *  poly
 *
 *  Created by Julien SANCHEZ on 25/11/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "assembleur.h"
#include "poly_parser.h"
#include "struct.h"
#include <string>
#include <math.h>

int assembler(char * entree)
{

	
	return 0;
}


int traduire(string entree)
{
	int valeur =0;
	for(int i = 0;i<entree.length();i++)
	{
		valeur += ((int)entree[i]-(int)'0')*pow(2,i);
		//printf("%d",((int)entree[i]-(int)'0')*pow(2,i));
	}
	return valeur;
}
