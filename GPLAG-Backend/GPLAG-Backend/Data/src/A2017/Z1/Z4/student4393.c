#include <stdio.h>

int main() {
	int brred,brkol,sirkol,i,j,m,n;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &brred);
	}
	while(brred<1 || brred>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &brkol);
	}
	while(brkol<1 ||  brkol>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirkol);
	}
	while(sirkol<1 || sirkol>10);
	m=2*brred+1;
	n=(sirkol*brkol)+brkol+1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j%(sirkol+1)==0 && i%2==0) printf("+");
			else if(j%(sirkol+1)!=0 && i%2==0) printf("-");
				else if(j%(sirkol+1)==0 && i%2!=0) printf("|");
				else { printf(" "); }
		}
		printf("\n");
	}
	return 0;
}
