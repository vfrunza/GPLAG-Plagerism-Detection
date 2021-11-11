#include <stdio.h>
#define broj 20

int main() {
int i,j,n,p,x,y,mat[broj][broj];
printf("\nUnesite broj tacaka: ");
scanf("%i", &n);
for(i=0; i<20; i++) {
	for(j=0; j<20; j++) {
		for(p=1; p<=n; p++) 
		printf("Unesite %i. tacku: ",p);
		scanf("%d %d",&x,&y);
		if(x<0 || x>19 || y<0 || y>19) { printf("Pogresan unos");
		j--; }
		else
			printf("*", mat[x][y]);  
		i=j=20;
}
}
return 0;
}
