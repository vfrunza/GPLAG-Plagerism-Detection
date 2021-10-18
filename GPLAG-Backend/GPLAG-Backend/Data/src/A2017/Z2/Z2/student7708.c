#include <stdio.h>

int main() {
	int N, i, j, k, duzina_niza1, duzina_niza2, a, b,br;
	int niz[100], n1[1000], n2[1000];
	br=0; j=0;
	printf("Unesite velicinu niza: ");
	scanf("%d", &N);
	while(N<0)
	{
		printf("Unesite velicinu niza: ");
		scanf("%d", &N);	
	}
	
	printf("Unesite clanove niza: ");
	for(i=0; i<N; i++)
	{
		scanf("%d", &niz[i]);
	}
	
	if(N==0) printf("DA");
	else
	{
		a=niz[0];
		do
		{
			b=a%10; 
			a=a/10;
			
		}while(a!=0);
	
		for(i=0; i<N; i++)
		{
			k=0;
			a=niz[i];
			do
			{
				n2[k]=a%10;
				a=a/10;
				k=k+1;
				duzina_niza2=k;
			}while(a!=0);
			
		
			duzina_niza2=duzina_niza2-1;
			k=duzina_niza2;
			do
			{
				if(b==n2[k]) br=br+1;
				else{
					n1[j]=b;
					n1[j+1]=br;
					br=1;
					j=j+2;
					b=n2[k];
				}
				if(i==N-1 && k==0)
				{
					n1[j]=b;
					n1[j+1]=br;
					br=1;
					j=j+2;
					b=n2[k];
				}
				k=k-1;
				duzina_niza1=j;
			}while(k>=0);
		}
		
	}
	
	printf("Finalni niz glasi: \n");
	for(i=0; i<duzina_niza1; i++)
	printf("%d ", n1[i]);
	
	
	return 0;
	
}
