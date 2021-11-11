#include <stdio.h>

int main() {
	int n,i,j;
	do {
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if((n%4!=0)||(n<8)) printf("Neispravno N!\n");
	}
	while((n%4!=0) || (n<8));
	printf("\n");
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		//x
			if((i==j)&&(i<=(n/2))&&(j<=(n/2))) printf("\\");
			else if((j==(n/2)-i+1)&&j<=(n/2)&&i<=(n/2)) printf("/");
		//kvadrat
		    else if(((i==1)||(i==n/2))&&((j==n)||(j==((n/2)+1)))&&(i<=(n/2))&&(j<=n)&&(j>n/2)){ printf("+");}
			else if(((j==n)||(j==(n/2)+1))&&(i<=(n/2))&&(j<=n) && j>n/2){ printf("|");}
			else if(((i==(n/2))||(i==1))&&(j<=n)&&(i<=(n/2)) && j>n/2){ printf("-");}
		//kvadrat
	 		else if(((j==(n/2))||(j==1))&&((i==(n/2)+1)||(i==n))&&(i<=n)&& i>n/2 &&(j<=(n/2))){ printf("+");}
			else if(((j==1)||(j==(n/2)))&&(i<=n) && i>n/2){ printf("|");}
			else if(((i==(n/2)+1)||(i==n))&&(j<=(n/2))) {printf("-");}
		//plus
			else if(((j==(n-n/4))||(j==n-(n/4)+1))&&((i==n-(n/4))||(i==n-(n/4)+1))) printf("+");
			else if(((j==n-(n/4))||(j==n-(n/4)+1))&&(i<=n)&&(i>n/2))	printf ("|");
			else if(((i==n-(n/4)+1)||(i==n-(n/4)))&&(j<=n)&&(j>n/2)) printf("-");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
