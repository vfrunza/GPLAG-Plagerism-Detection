#include <stdio.h>
#include <stdlib.h>
int main () {
	int d=0,a=0,b=0,niz[20][20],v=0,x=0,y=0,p=0,r=0,niza[20][20];
	printf ("Unesite broj tacaka: ");
	scanf ("%d",&d);
		while (d<1 || d>10) {
			printf ("Pogresan unos\n");
			printf ("Unesite broj tacaka: ");
			scanf ("%d",&d);
	}
	for (a=0;a<20;a++) {
		for (b=0;b<20;b++) {
			niz[a][b]=0;
			niza[a][b]=1;
		}
	}
	for (v=1;v<=d;v++) {
			printf ("Unesite %d. tacku: ",v);
			scanf ("%d %d",&x,&y);
				while ((x<0 && y<0) || (x>19 && y>19) || (x<1 && y>19) || (x>19 && y<1)|| (x<0 && y<20) || (x<20 && y<0) )
		{ 			printf ("Pogresan unos\n");
					printf ("Unesite %d. tacku: ",v);
					scanf ("%d %d",&x,&y);
		}
		niz[y][x]=1;
	}
	for (p=0;p<20;p++) {
		for (r=0;r<20;r++) {
			if (niz[p][r]==niza[p][r]) {
				printf ("*");}
			else {
				printf (" ");}
	}
		printf ("\n");
}
	return 0;
}