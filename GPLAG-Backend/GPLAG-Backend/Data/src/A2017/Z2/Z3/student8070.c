#include <stdio.h>

int main()
{
	int d1,d2,s1,s2,a[100][100],b[100][100],c[100][100],x=1,i,j,temp;
	float y;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&s1,&d1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<d1; i++) {
		for(j=0; j<s1; j++) {
			scanf("%d",&a[i][j]);


		}
	}
	for(i=0; i<s1; i++) {
		for(j=0; j<d1; j++) {
			c[i][j]=a[j][i];

		}
	}



	y=d1/2;

	for(i=0; i<s1; i++) {
		for(j=0; j<y; j++) {
			temp=c[i][j];
			c[i][j]=c[i][d1-1-j];
			c[i][d1-1-j]=temp;
		}
	}





	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&s2,&d2);

	printf("Unesite clanove matrice B: ");
	for(i=0; i<d2; i++) {
		for(j=0; j<s2; j++) {
			scanf("%d",&b[i][j]);


		}
	}
	if(s2!=d1 || d2!=s1) x=0;
	else {
		for(i=0; i<d2; i++) {
			for(j=0; j<s2; j++) {

				if(c[i][j]!=b[i][j]) x=0;

			}
		}
	}

	if(x==0) printf("NE");
	else printf("DA");


	return 0;
}
