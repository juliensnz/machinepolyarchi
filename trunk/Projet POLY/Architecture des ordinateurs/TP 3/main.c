#include <stdio.h>

typedef unsigned char byte; 
typedef signed char shortint; 
typedef unsigned short int word; 
void separer(word instr, byte *op, byte *ra, byte *rb, byte *rc, shortint *cst);


int main (int argc, const char * argv[]) {
	word inst;
	int continuer=1;
	
	int reg[4];
	int r0,r1,r2,r3;
	byte op, ra, rb, rc;
	shortint constante;
	separer(inst, &op, &ra, &rb, &rc, &constante);
	while (continuer) {
		inst=NULL;
		printf("entrez votre code en binaire : ");
		scanf("%hx",&inst);
		switch (op) {
			case 000:
				reg[ra]=constante;
				break;
			case 001:
				reg[ra]=reg[rb]+reg[rc];
				break;
			case 010:
				reg[ra]=reg[rb]-reg[rc];
				break;
			case 011:
				reg[ra]=reg[rb]*reg[rc];
				break;
			case 100:
				printf("%d",reg[ra]);
				break;
			default:
				break;
		}
	}
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
