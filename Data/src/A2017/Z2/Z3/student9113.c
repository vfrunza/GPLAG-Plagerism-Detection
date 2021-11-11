#include <stdio.h>

int main() {
	int mat1[100][100]={{0}},mat2[100][100]={{0}},v1,s1,v2,s2,i,j,jel=1,mat3[100][100]={{0}},temp=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&s1,&v1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<v1;i++){
		for(j=0;j<s1;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&s2,&v2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<v2;i++){
		for(j=0;j<s2;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	if(s1!=v2){
		printf("NE");
		return 0;
	}
	if(s1!=s2 && v1!=v2){
		v1=v2;
		s1=s2;
	}
	for(i=0;i<v1;i++){
		for(j=0;j<s1;j++){
			mat3[i][j]=mat1[j][i];
		}
	}
	
	for(i=0;i<v1;i++){
		for(j=0;j<(s1/2);j++){
			temp=mat3[i][j];
			mat3[i][j]=mat3[i][s1-j-1];
			mat3[i][s1-1-j]=temp;
		}
	}
	
	for(i=0;i<v1;i++){
		for(j=0;j<s1;j++){
			if(mat3[i][j]!=mat2[i][j]) jel=0;
		}
	}
	if(jel) printf("DA");
	else printf("NE");
	
	return 0;
}
