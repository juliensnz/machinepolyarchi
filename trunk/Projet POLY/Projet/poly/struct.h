/*
 *  struct.h
 *  poly
 *
 *  Created by Julien SANCHEZ on 25/11/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef STRUCT_H
#define STRUCT_H

typedef struct instruct{
	
	char * etiq;
	int cmd;
	int ri;
	int rj;
	int rk;
	char * nc;

}instruction;

instruction * newInstruction();

#endif