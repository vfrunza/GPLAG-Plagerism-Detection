#include <stdio.h>
#include <stdlib.h>
#define lenght 10
void ubaci (int *niz, int vel);
int izbaci (int *niz, int vel);
int main(){
	int niz[2*lenght]={0},i,pozovi;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<lenght;i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,lenght);
	pozovi=izbaci(niz,2*lenght);
	printf("Modificirani niz glasi: ");
	for(i=0;i<pozovi;i++){
		if(i==pozovi-1){
			printf("%d. ", niz[i]);
	}
	else printf("%d, ", niz[i]);
	}
	return 0;
}
/*Funkcija ubaci prima niz cijelih brojeva te nakon svakog člana niza ubacuje u niz pozitivan broj koji predstavlja sumu cifara prethodnog člana. 
Funkcija ne treba vraćati ništa jer je broj članova nakon poziva funkcije poznat (iznosi tačno dvostruku vrijednost primljenog broja članova).
U funkciji pretpostavite da je niz deklarisan tako da je dovoljno velik da primi sve dodatne članove.*/
void ubaci (int *niz, int vel){
	int br1=0,br2=0,n,i,j;
	for(i=vel-1;i>=0;i--)
		niz[2*i]=niz[i];
		for(j=0;j<2*vel;j+=2){
			br1=abs(niz[j]);
			if(br1<10)
			br2=br1;
			
			else {
				do{
					n=br1%10;
					br2+=n;
					br1/=10;
				}while(br1 != 0);
			}
		
			niz[j+1]=br2;
		br2=0;
		}
}
/*Funkcija izbaci prima niz cijelih brojeva i iz njega izbacuje sve članove niza koji su Fibonaccijevi brojevi. 
Funkcija treba vratiti broj članova niza nakon izbacivanja.*/
int izbaci (int *niz, int vel){
	int i,j,st=0,nd=0,rd=0;
	for(i=0;i<vel;i++){
		st=0;
		nd=1;
		for(j=1;j<1000;j++){
			if(j==1){
				rd=1;
			}
			else{
				rd=st+nd;
				st=nd;
				nd=rd; 
			}
			if(niz[i]==rd){
				int n;
				for(n=i;n<vel-1;n++)
					niz[n]=niz[n+1];
				
				vel--;
				i--;
				break;
			}
		}
	}
	return vel;
}



