#include <stdio.h>

int main() {
	int broj,t=0;
	do
	{
	printf("Unesite broj N: ");
		scanf("%d",&broj);
		if(broj>=8&&broj%4==0) t=1;
		if(t==0) printf("Neispravno N!\n");
	}
	while(t==0);
	int i=1,j=1,k=0;
	printf("\n");
	for(i=1;i<=broj;i++)
	{
		for(j=1;j<=broj;j++)
		{
			if(i==j&&i<=broj/2&&j<=broj/2) printf("\\");
			if((i+j)==((broj/2)+1)&&i<=broj/2&&j<=broj/2)  printf("/"); 
			if((i+j)!=(broj/2+1)&&i!=j&&i<broj/2+1&&j<broj/2+1) printf(" ");
			if((i==1)&&(j==broj/2)||(i==1)&&(j==broj)) printf("+");
			if((i==broj/2&&j==broj/2+1)||(i==broj/2&&j==broj)) printf("+");
			if((i==1&&j>broj/2+1&&j<broj)) printf("-");
			if(i==broj/2&&j>broj/2+1&&j!=broj) printf("-");
			if(i>1&&i<broj/2&&j==broj/2+1) printf("|");
			if(i>1&&i<broj/2&&j==broj) printf("|");
			if(i>1&&i<broj/2&&j>broj/2+1&&j!=broj) printf(" ");
			if((i==broj/2+1&&j==1)||(i==broj&&j==1)) printf("+");
			if((i==broj/2+1&&j==broj/2)||(i==broj&&j==broj/2)) printf("+");
			if(i==broj/2+1&&j>1&&j<broj/2) printf("-");
			if(i==broj&&j>1&&j<broj/2) printf("-");
			if(i>broj/2+1&&i<broj&&j==1) printf("|");
			if(j==broj/2&&i>broj/2+1&&i<broj) printf("|");
			if(i>broj/2+1&&i<broj&&j>1&&j<broj/2) printf(" ");
			if(i==broj/2+broj/4&&j==broj/2+broj/4) printf("+");
			if(i==broj/2+broj/4+1&&j==broj/2+broj/4+1) printf("+");
			if(i==broj/2+broj/4&&j==broj/2+broj/4+1) printf("+");
			if(i==broj/2+broj/4+1&&j==broj/2+broj/4) printf("+");
			if(i==broj/2+broj/4&&j>broj/2&&j<broj/2+broj/4) printf("-");
			if(i==broj/2+broj/4&&j>broj/2+broj/4+1&&j<=broj) printf("-");
			if(i==broj/2+broj/4+1&&j>broj/2&&j<broj/2+broj/4) printf("-");
			if(i==broj/2+broj/4+1&&j>broj/2+broj/4+1&&j<=broj) printf("-");
			if(j==broj/2+broj/4&&i>broj/2&&i<broj/2+broj/4) printf("|");
			if(j==broj/2+broj/4&&i>broj/2+broj/4+1&&i<=broj) printf("|");
			if(j==broj/2+broj/4+1&&i>broj/2&&i<broj/2+broj/4) printf("|");
			if(j==broj/2+broj/4+1&&i>broj/2+broj/4+1&&i<=broj) printf("|");
			if(i>broj/2&&i<broj/2+broj/4&&j>broj/2&&j<broj/2+broj/4) printf(" ");
			if(i>broj/2+broj/4+1&&i<=broj&&j>broj/2&&j<broj/2+broj/4) printf(" ");
		
		}
		printf("\n");
	}
	return 0;
}
