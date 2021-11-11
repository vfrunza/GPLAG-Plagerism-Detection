#include <stdio.h>

int main() {
	int kordinatax[10],kordinatay[10],i=0,j,br_tacaka,br=0,br1=0,k=0;
		while(1){
			printf("Unesite broj tacaka: ");
			scanf("%d", &br_tacaka);
			if(br_tacaka>0 && br_tacaka<11) {
				break;
			}
			else printf("Pogresan unos\n");
		}
		while(1){
		    if(br_tacaka>10) break;
		    for(i=0;i<br_tacaka;i++){
		    printf("Unesite %d. tacku: ", i+1);
		    scanf("%d %d", &kordinatax[i],&kordinatay[i]);
		    if(kordinatax[i]<0 || kordinatax[i]>19 || kordinatay[i]<0 || kordinatay[i]>19){
			   printf("Pogresan unos\n");
               i--;
		    }
	    }
	    break;
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(br=0;br<br_tacaka;br++){
			if(kordinatax[br]==j && kordinatay[br]==i){
				if(kordinatax[br]==kordinatax[k] && kordinatay[br]==kordinatay[k] && br!=0) {k++; break;}
				printf("*");
		        br1++;
			} 
		}
		if(br1==0) printf(" ");
		br1=0;
		}
		printf("\n");
	}
	return 0;
}
