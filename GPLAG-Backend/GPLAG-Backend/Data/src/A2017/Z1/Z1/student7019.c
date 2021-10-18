#include <stdio.h>
#define CIJENAPICERESTORAN 6.80
#define CJENAPICEFF 8.00
#define CIJENAPICEBISTRO 5.30 
#define CIJENAHAMBURGERARESTORAN 3.30 
#define CIJENAHAMBURGERAFF 3.00 
#define CIJENAHAMBURGERABISTRO 5.00 
#define CIJENACEVAPARESTORAN 5.00 
#define CIJENACEVAPAFF 3.90 
#define CIJENACEVAPABISTRO 6.00 

int main() {
	char Tarik, Mirza, Bojan, novired, P, H, C, R, FF, B;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&Tarik);
	scanf("%c",&novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&Bojan);
	scanf("%c",&novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&Mirza);
	scanf("%c",&novired);
	if(Tarik==P && Bojan==P && Mirza==P)
	{
		if(R==3*CIJENAPICERESTORAN && FF==3*CIJENAPICEFF && B==3*CIJENAPICEBISTRO)
		{
			if(R<FF && R<B)
		printf("Najjeftiniji je R");
	else if(FF<R && FF<B) printf("Najjeftiniji je FF");
	else if(B<R && B<FF) printf("Najjeftiniji je B");
	}
}
	if(Tarik==H && Bojan==H && Mirza==H)
	{
		if(R==3*CIJENAHAMBURGERARESTORAN && FF=3*CIJENAHAMBURGERAFF && B==3*CIJENAHAMBURGERABISTRO)
		{
		 if(R<FF && R<B)
		 printf("Najjeftiniji je RR");
		 else if(FF<R && FF<B) printf("Najjeftiniji je FF");
		 else if(B<R && B<FF) printf("Najjeftiniji je B");
		}
		}
		if(Tarik==C && Bojan==C && Mirza==C)
		{
			if(R==3*CIJENACEVAPARESTORAN && FF==3*CIJENACEVAPAFF && B==3*CIJENACEVAPABISTRO)
			{
				if(R<FF && R<B) printf("Najjeftiniji je RR");
				else if(B<R && B<FF) printf("Najjeftiniji je B");
				else if(FF<R && FF<B) printf("Najjeftiniji je FF");
			}
		}
		if(Tarik==H && Bojan==P && Mirza==C){
			if(R==(CIJENAHAMBURGERARESTORAN+CIJENAPICERESTORAN+CIJENACEVAPARESTORAN) && FF==(CIJENAHAMBURGERAFF+CIJENAPICEFF+CIJENACEVAPAFF) && B==(CIJENAHAMBURGERABISTRO+CIJENAPICEBISTRO+CIJENACEVAPABISTRO))
{
	if(R<FF && R<B) printf("Najjeftiniji je R");
	else if(FF<R && FF<B) printf("Najjeftiniji je FF");
	else if(B<FF && B<R) printf("Najjeftiniji je B");
}
		}
		if(Tarik==P && Bojan==P && Mirza==C)
		{
			if(R==(CIJENAPICERESTORAN+CIJENAPICERESTORAN+CIJENACEVAPARESTORAN) && FF==(CIJENAPICEFF+CIJENAPICEFF+CIJENACEVAPAFF) && B==(CIJENAPICEBISTRO+CIJENAPICEBISTRO+CIJENACEVAPAFF)
{
 if(R<FF && R<B) printf("Najjeftiniji je R");
 else if(FF<R && R<B) printf("Najjeftiniji je FF");
 else if(B<R && B<FF) printf("Najjeftiniji je B");
}
		}
		
	
	return 0;
}
