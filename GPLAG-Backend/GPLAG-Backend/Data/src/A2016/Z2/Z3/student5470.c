#include <stdio.h>

int main() {
	int a[10],b[10];
	int n,i,m,p,k;
	do
	{printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if (n<1 || n>10) {printf("Pogresan unos\n"); continue;}
		}while (n<1 || n>10);
	
		do
		{for (i=0; i<n; i++)
			{
		unos:	printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]>19 || b[i]>19 || a[i]<0 || b[i]<0) {printf("Pogresan unos\n"); goto unos;}
			}
		break;
		}while (a[i]>19 || a[i]<0 || b[i]>19 || b[i]<0);

	
	for (m=0; m<20; m++)
		{for(p=0; p<20; p++)
		{for (k=0; k<i; k++){
			if(m==b[k] && p==a[k]) {printf("*"); break;}
			}if (k==i) printf(" ");
						
		}printf("\n");
}					

	return 0;
}
