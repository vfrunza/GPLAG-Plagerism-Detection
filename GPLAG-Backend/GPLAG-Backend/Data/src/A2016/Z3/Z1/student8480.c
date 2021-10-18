#include <stdio.h>

int trazenjeprostogbroja(int x){
	
long int i=0;
	
	for(i=2;i<x;i++)
	
		{if(x%i==0) return 0;}
	
	return 1;
}

int daj_prost ()
{ long int i;
	 long int static s=1;
	
	for(i=s+1;i<100000;i++)   // Svaki put petlja krene od sljedeceg prostog broja 
	{
		
		if(i==2) {s=i; return 2;} // Ako se pozove prvi put i ce biti 2, jer to i treba vratiti funkcija
		
		if(trazenjeprostogbroja(i)==1) {s=i; return i;} /* Kada nadje prost broj staticku promjenjivu promijeni da bi
		petlja sljedeci put radila od s+1, tj od sljedeceg prostog broja */
		
	}
	}


int main() {

long int i,a,b,prostbroj,suma=0;

do {
	
printf("Unesite brojeve A i B: ");
scanf("%ld %ld", &a,&b);

if(a<1) printf("A nije prirodan broj.\n");
else if(a>b) printf("A nije manje od B.\n");
else if (a==b) printf("A nije manje od B.\n");

}
while (a<1 ||  a>b || a==b); 

prostbroj=a+1;

do /* Do while petlja sve dok funkcija vraca proste brojeve koji su manji od b */
{ 
prostbroj=daj_prost();

if(prostbroj>a && prostbroj<b) {suma=suma+prostbroj;} // Ako je prost broj izmedju a i b, sabiramo ga

	prostbroj++;
}
while(prostbroj<b);

printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a,b,suma);


	return 0;
}
