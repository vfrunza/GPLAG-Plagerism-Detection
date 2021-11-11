#include <stdio.h>

int main() {
	int i,j,visina,isti=1,sirina,a[100][100], b[100][100], c[100][100], bra[10000]={0},brb[10000]={0},brc[10000]={0};
	
	
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &visina, &sirina);

	}while(visina>100 || visina<0 || sirina<0 || sirina>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			scanf("%d", &a[i][j]);
			if(a[i][j]<0) a[i][j]*=-1;
		}
	}
	
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			scanf("%d", &b[i][j]);
			if(b[i][j]<0) b[i][j]*=-1;
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			scanf("%d", &c[i][j]);
			if(c[i][j]<0) c[i][j]*=-1;
		}
	}
	
	if(visina==1 && sirina==1){
		if(a[0][0]!=b[0][0] || a[0][0]!=c[0][0]) printf("NE\n");
		else printf("DA");
	}
	else{
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			
				bra[a[i][j]]++;
				brb[b[i][j]]++;
				brc[c[i][j]]++;
		}
		
	}
	
	for(i=0;i<10000;i++){
		if(bra[i]!=brb[i] || bra[i]!=brc[i]){
			isti=0;
			break;
		}
	}
	if(isti) printf("DA\n");
	else printf("NE\n");
	
	
	}
	return 0;
}