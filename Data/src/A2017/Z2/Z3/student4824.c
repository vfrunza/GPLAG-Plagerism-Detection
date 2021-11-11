#include <stdio.h>
#define MAX_VISINA 100
#define MAX_SIRINA 100

int main() {
	int i,j,k,l,matricaA[MAX_VISINA][MAX_SIRINA]={{0}},matricaB[MAX_VISINA][MAX_SIRINA]={{0}},SIRINA_A=0,SIRINA_B=0,VISINA_A=0,VISINA_B=0,ROT_MATRICAA[MAX_SIRINA][MAX_VISINA]={{0}};
	int poklapaju_se=0,max_visina=0,max_sirina=0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&SIRINA_A,&VISINA_A);

	printf("Unesite clanove matrice A: ");
	for(i=0;i<VISINA_A;i++) {
		for(j=0;j<SIRINA_A;j++){
			scanf("%d",&matricaA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&SIRINA_B,&VISINA_B);
	printf("Unesite clanove matrice B: ");
	for(k=0;k<VISINA_B;k++) {
		for(l=0;l<SIRINA_B;l++) {
			scanf("%d",&matricaB[k][l]);
		} 
	
	
	}
	if(VISINA_A>VISINA_B) max_visina=VISINA_A;
	else max_visina=VISINA_B;
	if(SIRINA_A>SIRINA_B) max_sirina=SIRINA_A;
	else max_sirina=SIRINA_B;
	
	for(i=VISINA_A-1;i>=0;i--){
		for(j=0;j<SIRINA_A;j++){
			ROT_MATRICAA[j][i]=matricaA[i][j];
		}
	}
	for(l=i=0;l<VISINA_B;l++){
		for(j=k=0;k<SIRINA_B;k++){
	if(ROT_MATRICAA[j][i]==matricaB[k][l]){
	poklapaju_se++;
	j++;
	} else poklapaju_se=0;
	break;
		}
		i++;
	}
	
	
	if (poklapaju_se==(SIRINA_B*VISINA_B)) printf("DA");
	else printf("NE");
	
return 0;
}
