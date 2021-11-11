#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void ubaci (int niz11[],int duzina){int i,j,k,l,m,n=0,c,d;

m=duzina*2-2;
for(j=duzina-1;j>=0;j--){ niz11[m]=niz11[j];m=m-2;}
for(k=0;k<2*duzina;k=k+2){
n=0;
l=fabs(niz11[k]);/*uzimamo apsolutnu vrijednost jer nam korisnik ima pravo ukucati negativan broj*/

do{
n=n+l%10;/*dodajemo cifre*/
l=l/10;
}while(l!=0);
niz11[k+1]=n;}
	
}
int izbaci(int niz11[], int duzina){
	int a,b,c,d,e,f,g,i,j,k;
	int niz12[100];
	niz12[0]=1;
	niz12[1]=1;
	for(j=2;j<100;j++){niz12[j]=niz12[j-1]+niz12[j-2];
}
for(i=0;i<duzina;i++){
	if(niz11[i]==1)
	{
	for(k=i;k<duzina-1;k++)
{
	niz11[k]=niz11[k+1]; 
	
}
duzina--;
i--;
k--;}
else{
	for(a=2;a<100;a++){
		if(niz11[i]==niz12[a]){g=duzina-1;
			for(b=i;b<g;b++){niz11[b]=niz11[b+1];
		
	}duzina--;i--;b--;break;}}}
}
return duzina;}
int main(){
	int niz11[100],i,j,k,l,m=10;
	printf("Unesite niz od 10 brojeva: ");
	for(j=0;j<m;j++){
		scanf("%d", &niz11[j]);
	}/*unos niza brojeva*/
	ubaci (niz11,10);l=izbaci(niz11,20);/*pozivanje funkcija izbaci i ubaci*/
	printf("Modificirani niz glasi: ");
    for(i=0;i<l;i++){
	if(i!=l-1){printf("%d, ",niz11[i]);}
	else printf("%d.",niz11[i]);}
	return 0;
}
