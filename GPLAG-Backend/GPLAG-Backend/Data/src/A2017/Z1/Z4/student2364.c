#include <stdio.h>
#include <math.h>

int main() {
	int  rows,columns,columnWidth,i,j,g;
	
	
	do{ printf("Unesite broj redova: ");
		scanf("%d", &rows);
	    
	} while(rows>10 || rows<=0);
	
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &columns);
		
	} while(columns>10 || columns<=0);
	
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &columnWidth);
		
	} while(columnWidth>10 || columnWidth<=0);
	
	for(g=0;g<2*rows+1;g++) {
		if(g%2==0){
			for(i=0;i<columns;i++){
				printf("+");
				for(j=0;j<columnWidth;j++)
				printf("-");
			}
			printf("+\n");
		}
		else{
			for(i=0;i<columns;i++){
				printf("|");
				for(j=0;j<columnWidth;j++)
				printf(" ");
			}
			printf("|\n");
		}
	}
	
	return 0;
}