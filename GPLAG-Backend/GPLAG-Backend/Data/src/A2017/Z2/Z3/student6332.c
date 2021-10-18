#include <stdio.h>
#define visina 10
#define sirina 10
int main() {
	int i,j;
	int matricaA1[visina][sirina],matricaB1[visina][sirina],matricaT1[visina][sirina];
	int sirA1,visA1,sirB1,visB1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirA1,&visA1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visA1; i++){
		for(j=0; j<sirA1;j++){
			scanf("%d",&matricaA1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirB1, &visB1);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visB1; i++){
		for(j=0; j<sirB1; j++){
			scanf("%d", &matricaB1[i][j]);
	
		}
	}
	for(i=0;i<visA1;i++){
		for(j=0;j<sirA1;j++){
			matricaT1[j][visA1-i-1]=matricaA1[i][j];
			
			}

	}

		for(i=0,j=0; i<visA1 && j<sirA1; i++,j++){
			
			if(matricaT1[i][j]==matricaB1[i][j])printf("DA");break;
	           
		}
	  	for(i=0,j=0; i<visA1 && j<sirA1; i++,j++){
	  		
			if(matricaT1[i][j]!=matricaB1[i][j])printf("NE");break;
	           }
	  	
	  
     


		
return 0;
}
	
	