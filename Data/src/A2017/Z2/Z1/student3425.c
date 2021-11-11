#include <stdio.h>

int main() {
	int i,j,n;

	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if (n%4!=0 || n<8){
			printf("Neispravno N!\n");
			continue;
		}
	}
	while(n<8);
	printf("\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){ 
				if (i<(n/2) && j<(n/2)){ // gornja lijeva slika
					if(i==j) printf ("\\");
					else if((j+i)==((n/2)-1)) printf("/");
					else printf(" ");
				}
				if (i<(n/2) && j>=(n/2)){ // gornja desna slika
					if((i==0 || i==((n/2)-1)) && (j==(n/2) || j==(n-1))) printf("+");
					if ((i==0 || i==((n/2)-1)) && (j<(n-1) && j>(n/2))) printf ("-");
					else if ((i<((n/2)-1) && i>0) && (j==(n/2) || j==(n-1))) printf("|");
					else if((i<(n/2) && i>0) && (j>(n/2) && j<(n-1)))  printf(" ");
				}
				if(i>=(n/2) && j<(n/2)){ //donja lijeva slika
					if((i==(n/2) || i==(n-1)) && (j==0 || j==((n/2)-2))) printf("+");
					if ((i==(n/2) || i==(n-1)) && (j<((n/2)-2))) printf ("-");
					else if ((i<(n-1) && i>(n/2)) && (j==0 || j==((n/2)-1))) printf("|");
					else if ((i<(n-1) && i>(n/2)) && (j>0 && j<(n/2))) printf (" ");	
				}
				if (i>=(n/2) && j>=(n/2)){ //donja desna slika
					if ((i==((n/2)+((n/4)-1)) || (i==((n/2)+((n/4)-1))+1)) && (j==((n/2)+((n/4)-1)) || (j==((n/2)+((n/4)-1))+1))) printf ("+");
					else if ((i==((n/2)+((n/4)-1)) || (i==((n/2)+((n/4)-1))+1)) && (j>=(n/2) && j<((n/2)+((n/4)-1)) || j>((n/2)+((n/4)-1)+1))) printf ("-");
					else if ((i>=(n/2) && i<=(n-1)) && (j==((n/2)+((n/4)-1)) || (j==((n/2)+((n/4)-1)+1)))) printf ("|");
					else printf (" ");
				}
			}
			printf("\n");
	}
	
	return 0;
}
