#include <stdio.h>

int main() {
	int r,ko,s,i,j,k;
	char e;
	
	do{
		ponovo:printf("Unesite broj redova: ");
   		scanf("%d", &r);
   		scanf("%c", &e);
   		if (r == 0 || r>10)goto ponovo;}
   	while(r<0 || r>10);
   		
	do{
		ne:printf("Unesite broj kolona: ");
		scanf("%d", &ko);
		scanf("%c", &e);
	if (ko == 0 || ko>10)goto ne;
	}while (ko<0 || ko>10);
	do{
		nr:printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
		scanf("%c", &e);
		if (s== 0 || s>10)goto nr;
	}while(s<0 || s>10);


	for(i=0;i<r*2;i++){
		if(i%2==0){
			for(j=0;j<ko;j++){
				printf("+");
				for(k=0;k<s;k++)printf("-");
			}
			printf("+\n");
		}
		else {
			for(j=0;j<ko;j++){
				printf("|");
				for(k=0;k<s;k++)printf(" ");
			}
			printf("|\n");
		}
	}
	for(j=0;j<ko;j++){
		printf("+");
		for(k=0;k<s;k++)printf("-");
	}
	printf("+\n");
	
	return 0;
}
