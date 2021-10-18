#include <stdio.h>
#include <math.h>
#define E 0.00001
int main() {
	int i,j,v1,v2,s1,s2, prolaz=1, x;
	double a[100][100], b[100][100], za[100][100];
	printf ("\nUnesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &s1, &v1);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<v1; i++){
		for (j=0; j<s1; j++){
			scanf ("%lf", &a[i][j]);
		}
	}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &s2, &v2);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<v2; i++){
		for (j=0; j<s2; j++){
			scanf ("%lf", &b[i][j]);
		} }
		if (v1!=s2 || s1!=v2){
			printf ("NE");
			return 0;
		}
		
	for (j=0; j<s1; j++){
		x=0;
		for (i=v1-1;i>=0; i--){
			za[j][x]=a[i][j];
			x++;
		}
	}
	for (i=0; i<v2; i++){
		for (j=0; j<s2; j++){
			if (fabs(za[i][j]-b[i][j])<E)
			prolaz=1;
			else {
			prolaz=0;
			break;
		} }
		
	} 
if (prolaz==1)
printf ("DA");
else 
printf ("NE");


	return 0;
}
