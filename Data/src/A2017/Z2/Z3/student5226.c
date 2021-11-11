#include <stdio.h>

int main() {
	int i,j,x,y,a,b;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&x,&y);
	float A[100][100],TA[100][100],temp=0;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			scanf("%f",&A[i][j]);
		}
	}
	for(i=0;i<x;i++) {
    	for(j=0;j<y;j++) {
    		TA[i][j]=A[j][i];
    	}
    }
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&a,&b);
	float B[100][100];
	printf("Unesite clanove matrice B: ");
	for(i=0;i<b;i++) {
		for(j=0;j<a;j++) {
			scanf("%f",&B[i][j]);
		}
	}
    for(i=0;i<y-i;i++) {
    	for(j=0;j<x;j++) {
    		temp=TA[j][i];
    		TA[j][i]=TA[j][y-i-1];
    		TA[j][y-1-i]=temp;
    	}
    }
    if(y==a && x==b) {
    	for(i=0;i<b;i++) {
    		for(j=0;j<a;j++) {
    			if((TA[i][j]-B[i][j])>0.001)  {
    				printf("NE\n");
    				return 0;
    		}
    	}
    }
    }
     printf("DA\n");
     return 0;
}
