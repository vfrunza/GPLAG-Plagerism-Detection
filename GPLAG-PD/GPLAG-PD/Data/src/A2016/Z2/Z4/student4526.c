#include <stdio.h>
#define knj 100
int main() {
	int a,b,t='t',i,j,c='c';
	double m[knj][knj];
	
do{ printf("Unesite M i N: ");
scanf("%d %d", &a, &b); if(a<=0 || a>100 || b<=0 || b>100)printf("Pogresan unos!\n");
} while(a<=0 || b<=0 || a>100 || b>100);

printf("Unesite elemente matrice: ");
for(i=0;i<a;i++){
	for(j=0;j<b;j++){
		scanf("%lf", &m[i][j]);
	}}
	for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){if(m[i][j]!=m[i+1][j+1]) {t='nt';
		break;}
			}
		}
		for(i=0;i<a-1;i++){
		for(j=0;j<b-1;j++){if(m[i][b-1]!=m[i+1][0] || m[i][j]!=m[i+1][j+1] ){
			c='nc'; break;}}
		}if(a==1 && b==1)printf("Matrica je cirkularna");else{
		if(b==1)printf("Matrica je Teplicova"); else{
	if(c=='c' && t=='t'){printf("Matrica je cirkularna");}
else 	if(t=='t' && c=='nc'){printf("Matrica je Teplicova");
}else printf("Matrica nije ni cirkularna ni Teplicova");}}
	return 0;
}
