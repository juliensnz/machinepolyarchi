/*
 *  struct.cpp
 *  poly
 *
 *  Created by Julien SANCHEZ on 25/11/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <stdlib.h>
#include "struct.h"

instruction * newInstruction()
{
	instruction * op = (instruction *)malloc(sizeof(instruction));
	return op;
}