#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	bool coord[20][20];
	int i,j,x, y, broj_tacaka;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			coord[i][j]=false;
		}
	}
		
	

	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	if(broj_tacaka>0 && broj_tacaka<=10)
	break;
	printf("Pogresan unos \n");
	} while(broj_tacaka<1 || broj_tacaka>10);
	
	for(x=0; x<broj_tacaka; x++){
		int _x,_y;
		printf("Unesite %d. tacku: ", x+1);
		scanf("%d %d", &_x, &_y);
		if(_x<0|| _y<0 ||_x>19 ||_y>19 ){
		printf("Pogresan unos \n");
		x--;
		continue;
		}
		coord[_x][_y]=true;
		
	
		
	}


for(y=0;y<20;y++){
	for(x=0; x<20;x++){
		if(coord[x][y]==true)
		printf("*");
		else
		printf(" ");
	}
	printf("\n");
}
return 0;
}

