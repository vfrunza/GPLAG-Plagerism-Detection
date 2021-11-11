#include<stdio.h>

//Funkcija koja vraca prost broj
int daj_prost()
{
	 static int a=2; //staticka varijabla
	 int i,uslov;
	 do{
	 	uslov=1;
	 	for(i=2; i < a; i++)
	 	{
	 		if(a % i == 0) uslov = 0;
	 	}
	 	if(uslov == 1)
	 	{
	 		uslov=a; a++; return uslov;
	 	}
	 	else a++;
	 }
	 while(1);
}

int main()
{
	int A,B,suma=0,i,y;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A,&B);
	if(A <= 0)
	{
		printf("A nije prirodan broj.\n");
	}
	else if(A >= B)
	{
		printf("A nije manje od B.\n");
	}
	while(A <= 0 || A >= B)
	{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A <= 0)
		{
			printf("A nije prirodan broj.\n");
		}
		else if(A >= B)
		{
			printf("A nije manje od B.\n");
		}
	}
	
	//Poziv funkcije
	for(i=0; i < B; i++)
	{
		y=daj_prost();
		if(y > A && y < B)
			suma+=y;
	}
	//Ispis sume
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}