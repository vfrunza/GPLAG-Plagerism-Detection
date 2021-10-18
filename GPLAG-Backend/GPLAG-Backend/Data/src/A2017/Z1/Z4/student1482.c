#include <stdio.h>

int main() {
	int i, j, k, l, r, kl, sk, m;
	printf("Unesite broj redova: ");
	scanf("%d", &r);
if(r>10 || r<=0){
	do	
		{printf("Unesite broj redova: ");
		scanf("%d", &r);}while(r>10 || r<=0);}
		printf("Unesite broj kolona: ");
		scanf("%d", &kl);
if(kl>10 || kl<=0){
	do
		{printf("Unesite broj kolona: ");
		scanf("%d", &kl);}while(kl>10 || kl<=0);}
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
if(sk>10 || sk<=0){
	do	
		{printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);}while(sk>10 || sk<=0);}

	
	for(m=0; m<=r*2; m++)
	{
		for(i=0; i<kl; i++)
		{
			if(m%2==0)
			{
				printf("+");
					for(j=0; j<sk; j++)
						printf("-");
			}
		}
			if(m%2==0)
			{
			printf("+");
			}
		for(l=0; l<kl; l++)
		{
			if(m%2==1)
			{
				printf("|");
					for(k=0; k<sk; k++)
						printf(" ");
			}	
			
		}
		if(m%2==1){printf("|");}
		printf("\n");
	}
	return 0;
}
