#include <stdio.h>

int main() {

int m,n,i,j,s,e, k, brojac=0;
int mat[200][200];

do {
printf("Unesite brojeve M i N: ");
scanf("%d %d", &m, &n);


if(m<1 || n<1 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
}
while(m<1 || n<1 || m>200 || n>200);


printf("Unesite elemente matrice: ");

for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	
{	scanf("%d", &mat[i][j]); }

}

//Poredimo svaki red sa redovima poslije njega
for(i=0;i<m;i++) //Petlja koja ide po redovima
{
	
	for(j=i+1;j<m;j++) //Ova petlja poredi redove sa redom iz prve petlje
	{ brojac=0; //Broj razlicitih elemenata je nula
	
	for(k=0;k<n;k++) //Jos jedna petlja za kolone
	
	{if(mat[i][k]!=mat[j][k]) brojac++;} //Brojanje razlicitih elemenata
		
		
if(brojac==0) { /*Ako je broj razlicitih elemenata 0, tj isti su, treba ih izbaciti */
	
	for(s=j;s<m-1;s++) //Izbacivanje kao u predavanju, samo treba jos jedna petlja za kolone
{
	for(e=0;e<n;e++) //Kolone
	{
		mat[s][e]=mat[s+1][e]; //Elemenat postaje elemenat u istoj koloni, ali u redu ispod
	} 
}
	m--;
	j--;
	
}

}}


for(i=0;i<n;i++)//Petlja koja ide po kolonama
{
	
	for(j=i+1;j<n;j++) 	//Petlja za kolone koja poredi sve ostale kolone sa kolonom iz prve petlje
	{brojac=0; 			//broj razlicitih elemenata je nula
		for(k=0;k<m;k++) //Treba nam i petlja za redove
		{
			if(mat[k][i]!=mat[k][j]) brojac++; //Brojanje razlicitih elemenata u kolonama
			
		}
		
		if(brojac==0) { //Ako je broj razlicitih elemenata ostao isti, slijedi izbacivanje
			
			for(s=j;s<n-1;s++)
			{
				for(e=0;e<m;e++)
				{
				mat[e][s]=mat[e][s+1];
		
				}
			}
			n--;
			j--;
		}
		
			}
	
	
	}


printf("Nakon izbacivanja redova/kolona matrica glasi: \n");

for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%5d", mat[i][j]);
		
	}
	
	printf("\n");
}
	return 0;
}
