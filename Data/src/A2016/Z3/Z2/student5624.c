#include <stdio.h>
// funkcija sabira cifre broja, te izbacuje taj broj kao pozitivan
int suma(int n){
	int cifra, s=0;
	if(n<0)
		n=-n;
	while(n!=0){
		cifra=n%10;
		s+=cifra;
		n/=10;
	}
	return s;
}
// funckija nakon svakog člana niza ubacuje u niz pozitivan broj koji predstavlja sumu cifara prethodnog člana.
void ubaci(int *niz, int vel){
	int i,j;
	for(i=0;i<vel;i++){
		for(j=vel-1;j>i;j--)
			niz[j+1]=niz[j];
		niz[i+1]=suma(niz[i]);
		vel++;
		i++;
	}
}
//funkcija ispituje da li je broj fibonacijev
int fibonacijev_niz(int m){
	int a=1, b=1;
	if(m<1)
		return 0;
	while(a<m&&b<m){
		a=a+b;
		b=a+b;
	}
	if(a==m||b==m) 
		return 1;
	return 0;
}
//funkcija izbacuje sve fibonacijeve brojeve iz niza
int izbaci(int *niz, int vel){
	int i,j;
	for(i=0;i<vel;i++){
		if(fibonacijev_niz(niz[i])){
			for(j=i; j<vel-1; j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}
int main() {
	int i, niz[20], vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<vel;i++)
		scanf("%d",&niz[i]);
	ubaci(niz,vel);
	vel=izbaci(niz, vel*2);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i==vel-1) 
			printf("%d.", niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
