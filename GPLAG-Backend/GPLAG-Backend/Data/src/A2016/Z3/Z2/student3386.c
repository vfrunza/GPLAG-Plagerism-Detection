#include <stdio.h>
#include <math.h>
void ubaci(int *niz,int vel)
{
	int i,suma=0,c=0,x=0,vel1;
	/*postavljam pokazivac na 
	posljednje mjesto trenutnog niza*/
	niz+=vel-1;
	vel1=vel-1;
	/*prepisujem vrijednost unazad tj.
	prvo prepisujem posljednji clan na pretposljednje mjesto
	pa onda pretposljedni itd.*/
	for(i=0;i<vel-1;i++)
	{
		
		*(niz+vel1)=*niz;
		niz--;
		vel1--;
	}
	for(i=0;i<vel;i++)
	{
		suma=0;
		/*trebaju nam pozitivne vrijednosti zbog sume*/
		x=fabs(*niz);
		do
    	{
			c=x%10;
			x=x/10;
			suma+=c;
        
		}while(x>0);
	/*upisujem sumu u slj. clan i 
	onda taj clan preskacem*/
	niz++;
	*niz=suma;
	niz++;
	}
	niz-=(2*vel);
}
int Fib_niz (int x)
{
	/*pretpostavljam da ne 
	pripada fib. nizu*/
	int fib=1;
	int rezultat;
	int posljednji = 1;
	int pretposljednji = 0;
	do{
		rezultat = posljednji + pretposljednji;
		pretposljednji = posljednji;
		posljednji = rezultat;
		/*ako pripada vrati nulu*/
		if(posljednji==x) 
			fib=0;
		
	}while(posljednji<x);
    
    return fib;
	
} 
int izbaci(int *niz,int vel)
{
	int i,j;
	for(i=0;i<vel;i++)
	{
		if(Fib_niz(*(niz+i))==0)
		{
			/*ako pripada fib. nizu slijedi 
			klasicno izbacivanje iz niza*/
			for(j=i;j<vel-1;j++)
				{
					*(niz+j)=*(niz+j+1);
				}
			i--;
			vel--;
		}
	}
	return vel;
}
int main() {
	int i,vel=10,niz[20]={0};
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<vel;i++)
	{
		scanf("%d",&niz[i]);
	}
	ubaci(niz,vel);
	/*velicina nakon funkcije ubaci je 
	duplo veca nego ona s kojom smo poceli*/
	vel*=2;
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++)
	{
		if(i==vel-1)
		printf("%d.",niz[i]);
		else
		printf("%d, ",niz[i]);
	}
	return 0;
}
