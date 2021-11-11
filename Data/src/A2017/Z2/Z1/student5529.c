#include <stdio.h>

int main() {
	int n, i ,j, cetvrtina, polovina;
	do{
		printf("Unesite broj N:\n");
		scanf("%d", &n);
	}while(!(n%4==0 && n>=8));
	
	polovina = n/2;
	cetvrtina = n/4;
	/*gornji dio- X i kvadrat */
	for(i=0; i<polovina; i++){
		for(j=0; j<polovina; j++)
			if(i==j) printf("\\");
			else if(j==polovina-i-1) printf("/");
			else printf(" ");
		for(j=0; j<polovina; j++)
			if(i==0 || i==polovina-1){
				if(j==0 || j==polovina-1) printf("+");
				else printf("-");
			}
			else if(j==0 || j==polovina-1){
				if(i==0 || i==polovina-1) printf("+");
				else printf("|");
			}
			else printf(" ");
		printf("\n");
	}
	for(i=0; i<polovina; i++){
		for(j=0; j<polovina; j++)
			if(i==0 || i==polovina-1){
				if(j==0 || j==polovina-1) printf("+");
				else printf("-");
			}
			else if(j==0 || j==polovina-1){
				if(i==0 || i==polovina-1) printf("+");
				else printf("|");
			}
			else printf(" ");
		for(j=0; j<polovina; j++)
			if(i<cetvrtina-1 && j<cetvrtina-1) printf(" ");
			else if((i==cetvrtina-1 || i==cetvrtina) && (j==cetvrtina-1 || j==cetvrtina)) printf("+");
			else if(i==cetvrtina-1 || i==cetvrtina) printf("-");
			else if(j==cetvrtina-1) printf("||");
			else printf(" ");
		
		printf("\n");
	}
	
	
	return 0;
}
