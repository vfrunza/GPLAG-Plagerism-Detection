#include <stdio.h>
int negativno(int n){
 int a; 
 a=-n; 
 return a; 
}
int cifra(int n) {
 int c;
 c=n%10; 
 return c; 
}
int f(int n){
 int b; 
 b=n/10; 
 return b;
}
/*Funkcija za izracunavanje sume*/
int suma(int n) {
 int c, suma=0; 
  if(n<0) 
  n=negativno(n);
while(n!=0){
 c=cifra(n) ; 
 suma=suma+c; 
 n=f(n); 
}
return suma; 
}
/*Fukcija za ubacivnje elemenata*/
void ubaci(int*niz, int vel) {
 int i,j;  
  for(i=0; i<vel; i++) {
	for(j=vel-1; j>i; j--) {
	niz[j+1]=niz[j];
	}
	niz[i+1]=suma(niz[i]); 
	vel++;
	i++; 
	}	
	return;
	}
int fibonaci(int n) {
 int a=1; int b=1; 
 if(n<1) 
 return 0; 
 while (a<n && b<n)
	{
		a=b+a; 
		b=b+a; 
	}
	if(a==n || b==n)
	return 1; 
	return 0; 
}
/*Funkcija za izbacijanje elemenata*/
int izbaci(int*niz, int vel) {
 int i; 
 int j; 
 for(i=0; i<vel;i++) {
  if(fibonaci(niz[i])) { 
  	for(j=i; j<vel-1; j++) {
	 niz[j]=niz[j+1];
	}
	vel--; 
	i--;
	}
}
return vel;
}

int main() {
 int i, niz[20]; 
 int vel=10; 
 printf("Unesite niz od 10 brojeva: "); 
 for(i=0; i<vel; i++) {
 scanf("%d", &niz[i]); 
}
ubaci(niz,vel);
vel=izbaci(niz, vel*2);
printf("Modificirani niz glasi: "); 
for(i=0; i<vel; i++) {
 if(i==vel-1) printf("%d.", niz[i]); 
 else printf("%d, ",niz[i]);
}
return 0; 
}