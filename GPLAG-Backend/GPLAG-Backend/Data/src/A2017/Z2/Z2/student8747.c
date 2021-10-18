#include <stdio.h>

int main() {
	int A[500],B[1000];
	int i,v=0,Broj,j=0,S=0,D=0,r=0,suma=0,G=1,Ponavljanje=0;
	printf("Unesite velicinu niza: ");
	scanf ("%d",&Broj);
	printf("Unesite clanove niza: ");
	  
	   for (i=0;i<Broj;i++){
	   	 scanf("%d",&S);D=S;G=S;
	   	 while(D!=0){
	   	 	suma++;
	   	 	D=D/10;
	   	 }
	 if (S==0){++suma;j=suma-1;A[j]=0;}
	  j=suma-1;
	  while(S!=0){
	  r=S%10; A[j]=r;
	  	S=S/10;j--;
	  }
	  	} 
   for(i=0;i<suma;i++){
   	Ponavljanje=0;
   	for (j=i;j<suma;j++){
   		if (A[j]==A[i] )Ponavljanje++;
   		else break;
   	}
   	B[v]=A[i];
   	B[++v]=Ponavljanje;
   	v++;
   	i=i+Ponavljanje-1;
   }
       printf("Finalni niz glasi:\n");
	   for (i=0;i<v;i++){
	 	printf("%d ",B[i]);} 
	 //	printf ("\n  G  %d",suma);
	
	
	return 0;
}
