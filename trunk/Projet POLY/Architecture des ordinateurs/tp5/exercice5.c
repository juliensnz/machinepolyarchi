#include <stdio.h>

int pgcd(int a,int b);




int main()
{
	
	int b = 12;
	int a = 3466;
	printf("%d\n",pgcd(a,b));
	return 1;
}


int pgcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return pgcd(b,a%b);
	}
}

/*

init :
	b
	a
debut :
	label calculerPgcd
calculerPgcd :
	
*/