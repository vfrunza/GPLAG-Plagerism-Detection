#include <stdio.h>
#define MAX 100
int main() {
int a,b,c,d,i,j,A[MAX][MAX],B[MAX][MAX],T[MAX][MAX],k=1,l;

printf("Unesite sirinu i visinu matrice A: ");
scanf("%d %d", &a, &b);
printf("Unesite clanove matrice A: ");
for(i=0; i<b;i++){
	for(j=0;j<a;j++){
		scanf("%d", &A[i][j]);}
}
printf("Unesite sirinu i visinu matrice B: ");
scanf("%d %d", &c, &d);
printf("Unesite clanove matrice B: ");
for(i=0; i<d;i++){
	for(j=0; j<c;j++){
		scanf("%d", &B[i][j]);}
}
if(a!=c || b!=d){printf("NE\n");
return 0;}

else if(a==c && b==d && a==b){

	for(i=0;i<a;i++){l=a-i-1;
	for(j=0;j<a;j++){
		T[j][l]=A[i][j];
	}
}
for(i=0;i<a;i++){for(j=0;j<b;j++){
		if(	T[i][j]==B[i][j]){if(j==b-1 && i==a-1)printf("DA\n");else continue;}
	else if(T[i][j]!=B[i][j]){k=0;printf("NE\n");break;}

}	if(k==0)break;

}}
else if(a==d && a==1 && b==c && b!=1){
	for(i=0;i<b;i++){
		l=b-1-i;
		for(j=0;j<a;j++){
			T[l][j]=A[i][j];
		}
	}
	for(i=0;i<d;i++){for(j=0;j<c;j++){
		if(	T[i][j]==B[i][j]){if(i==c-1)printf("DA\n");else continue;}
	else if(T[i][j]!=B[i][j]){k=0;printf("NE\n");break;}

}	if(k==0)break;

}
}
	return 0;
}
