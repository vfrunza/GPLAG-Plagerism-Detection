#include <stdio.h>
	int s (int a){
	if(a<0) 
	a=a*(-1); //ako se posalje negativan broj, suma ce biti negativna
	
	int s1=0;
	while(a!=0){
	int a1=a%10;
	s1=s1+a1;
	a=a/10;

	
	}
	return s1;}
	void ubaci (int* niz,int vel)
	{
	int pn[20],i,k;
	for(i=0;i<vel;i++)
	pn[i*2]=niz[i];// nas pomniz je duplo veci i u njega na parnim indeksima ubacujemo elemente
	
	int pns[20]; //pom niz suma
	for(i=0;i<vel;i++)
	pns[i]=s(niz[i]);//popunimo pomocni niz suma , sumama elemenata naseg niza
	k=0;
	
	for(i=0;i<vel*2;i++){ 
		if(i%2==1){			
			pn[i]=pns[k];  
			k++;
		}
	}
	for(i=0;i<vel*2;i++){ //to sve iz pom niza vratimo u nas niz 
		niz[i]=pn[i];
	}
	}
	void fun (int niz[5]){
	int i;
	for(i=0;i<5;i++){
		if(i%2==1)
		niz[i]=0;
	}}
	int fibo (int x)
	{
	int prvi=1,drugi=1,slj=0;  //po defaultu prvi i drugi 1 uvijek
	while(slj<=x){ 		 
		slj=prvi+drugi;   
		if(slj==x || prvi==x) return 1;  
		prvi=drugi;   
		drugi=slj;
		
	}
	return 0;
	}
	// mogla je  i da primi INT* NIZ, INT VEL
	int izbaci (int niz[],int vel){
	int i,j;
	for(i=0;i<vel;i++){ //idemo po nizu i svaki element provjeravamo da li je fib broj 
		int vr=fibo(niz[i]);  //ako je niz[i] fiboacijev broj, nasa vr ce biti 1, a ako nije vr ce biti 0
		if(vr==1){
			for(j=i;j<vel-1;j++){ //izbacivanje
				*(niz+j)=niz[j+1];// NIZ[J]=*(NIZ+J),*(NIZ+J+1)
			}
			vel--;
			i--;
		}
	}
	return vel;
	}

	int main() {
  int niz[20]; //napravili smo veci niz
  int i;
  printf("Unesite niz od 10 brojeva: ");
  for(i=0;i<10;i++){
  	scanf("%d",&niz[i]);
  }
  ubaci(niz,10); 
  int vr=izbaci(niz,20); 

	printf("Modificirani niz glasi: ");
 	for(i=0;i<vr;i++){  
 	if(i==vr-1) printf("%d.",niz[i]);
 	else
 	printf("%d, ",niz[i]);}
	return 0;
	}
