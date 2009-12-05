#include <stdio.h>
#include <string.h>
#include <math.h>

int main (int argc, const char * argv[]) {
	char chaine[]= "0000000000000000";
	unsigned short int trans[16];
	unsigned short int trans2[16];
	printf("Entrez votre nombre : ");
	scanf("%s",chaine);
	int resultat, resultat2,resultat3 = 0;
	for(int i=0; i<16; i++) 
	{
		trans[i] = (int)chaine[i]-(int)'0';
		
		resultat += pow(2,15-i)*trans[i];
		if (i<8) {
			resultat2 += pow(2,7-i)*trans[i];
		}
		else {
			resultat3 += pow(2,15-i)*trans[i];
		}
		
		
		printf("%d",trans[i]);
	}
	for (int i = 15; i>=0; i--) {
		if(trans[i])
		{
			trans2[i] = 1;
		}
		else {
			trans2[i] = 0;
		}
	}
	printf("\n%d\n%d : %c\n",resultat,resultat2,(char)resultat3);
	
    return 0;
}
