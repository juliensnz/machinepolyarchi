#include <stdio.h>

typedef unsigned char byte; 
typedef signed char shortint; 
typedef unsigned short int word; 
void separer(word instr, byte *op, byte *ra, byte *rb, byte *rc, shortint *cst);


int main (int argc, const char * argv[]) {
	word inst;
	int continuer = 1;
	int reg[4] = {0};
	int i =0;
	byte op, ra, rb, rc;
	shortint constante;
	do {
		
		printf("Commande : ");
		scanf("%hx",&inst);
		separer(inst, &op, &ra, &rb, &rc, &constante);
		switch ((int)op) {
			case 0:
				reg[(int)ra]=constante;
				break;
			case 1:
				reg[ra]=reg[(int)rb]+reg[(int)rc];
				break;
			case 2:
				reg[(int)ra]=reg[(int)rb]-reg[(int)rc];
				break;
			case 3:
				reg[(int)ra]=reg[(int)rb]*reg[(int)rc];
				break;
			case 4:
				printf("Resultat : %hx\n",reg[(int)ra]);
				break;
			default:
				continuer = 0;
				break;
		}
		i++;
		
	} while (continuer || i < 200);
	
    return 0;
}



void separer(word instr, byte *op, byte *ra, byte *rb, byte *rc, shortint *cst){
	*op = (instr & 0xE000) >> 13;
	*ra = (instr & 0x1800) >> 11;
	*rb = (instr & 0x0600) >> 9;
	*rc = (instr & 0x0180) >> 7;
	*cst = (instr & 0x007F);
	*cst = *cst | ((*cst & 0x40) << 1);
	
}
