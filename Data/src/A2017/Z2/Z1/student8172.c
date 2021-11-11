#include <stdio.h>

int main() {
	int i,j,br;
	do{ printf("Unesite broj N: ");
	scanf("%d",&br);
	if(br%4!=0 || br<8){printf("Neispravno N!\n");}
	}
	while(br%4!=0 || br<8);
	printf("\n");
	for(i=1;i<=br;i++)
	{for(j=1;j<=br;j++)
	{if((i==br && j==br/2) || ((i==(br/2)+1) && j==1) || (i==br && j==1) || ((i==(br/2)+1) && j==br/2) || (i==br/2 && j==br) || (i==1 && j==(br/2)+1) || (i==1 && j==br) || (i==br/2 && j==(br/2)+1))
	{printf("+");}
	else if((i>br/2 && j==1) || (i>br/2 && j==br/2) || (i<br/2 && j==br) || (i<br/2 && j==(br/2)+1)){printf("|");}
	else if((i==1 && j>br/2) || (i==br/2 && j>br/2) || (i==(br/2)+1 && j<br/2) || (i==br && j<br/2)){printf("-");}
	else if(i<=br/2 && i==j && j<=br/2){printf("\\");}
	else if(i<=br/2 && j<=br/2 && (i+j)==(br/2)+1){printf("/");}
	else if((i==br/2+br/4 && j==br/2+br/4) || (i==br/2+br/4 && j==br/2+br/4+1) || (i==br/2+br/4+1 && j==br/2+br/4) || (i==br/2+br/4+1 && j==br/2+br/4+1)){printf("+");}
	else if((i==br/2+br/4 && j>br/2) || (i==br/2+br/4+1 && j>br/2)){printf("-");}
	else if((i>br/2 && j==br/2+br/4) || (i>br/2 && j==br/2+br/4+1)){printf("|");}
	else{printf(" ");}
	}
	printf("\n");
	}
	return 0;
	
	
}
