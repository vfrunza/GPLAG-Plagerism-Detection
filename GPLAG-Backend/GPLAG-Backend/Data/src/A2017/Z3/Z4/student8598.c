#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina){
	int i,j,k,n,broj1,broj2,brojac=0,max=0,max1=matrica[0][0],temp;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			broj1=matrica[i][j];
			for(k=0; k<visina; k++) {
				for(n=0; n<sirina; n++) {
					broj2=matrica[k][n];
					if(broj1==broj2) {
						brojac++;}}}
			if(brojac>=max) {
				temp=max1;
				max1=broj1;
				if(brojac==max && broj1>temp)
					max1=temp;
				max=brojac;}
			brojac=0;}}
	return max1;
}
int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N){
	int i,j,k,n,s;
	s=sirina;
	for (i=0; i<visina; i++)
		for (j=0; j<s; j++) {
			if (N==matrica[i][j]) {
				for (n=j; n<sirina; n++)
					for (k=0; k<visina; k++)
						matrica[k][n]=matrica[k][n+1];
				s--;}}
	return s;
}
int main()
{
	int  v,s,i,j,mat[100][100],a=0,b,ponavljanje,v1,s1,brojac=1;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf("%i %i", &s,&v);
	for (i=0; i<v; i++) {
		printf ("Unesite elemente %i. reda: ", i+1);
		for (j=0; j<s; j++)
			scanf ("%i", &mat[i][j]);}
	ponavljanje=1;
	v1=v;
	s1=s;
	do{
		a=0;
		if(s>1)
			while(a<v1) {
				for(b=1; b<s; b++) {
					if(mat[a][0] == mat[a][b]){
						brojac++;}}
				if(brojac==s1) {
					printf ("\nNakon 1. prolaza matrica je prazna!");
					return 0;}
					else {
					brojac=1;
					a++;}}
		int N=max(mat,v,s);
		s=izbaci_kolone(mat,v,s,N);

		if (s!=0){
			printf ("\nNakon %i. prolaza matrica glasi:\n", ponavljanje);
			for (i=0; i<v; i++) {
				for (j=0; j<s; j++) {
					if(j==0 && mat[i][0]<10) printf("    ");
					else if(j==0 && mat[i][0]>=10) printf("   ");
					else if(j==0 && mat[i][0]>=100) printf("  ");
					if(j==s-1) printf ("%i",mat[i][j]);
					if(j!=s-1)printf ("%-5i",mat[i][j]);}
				printf ("\n");}} 
				else {
			printf ("\nNakon %i. prolaza matrica je prazna!", ponavljanje);
			return 0;}
		ponavljanje+=1;}
		while (s!=0);
	return 0;
}