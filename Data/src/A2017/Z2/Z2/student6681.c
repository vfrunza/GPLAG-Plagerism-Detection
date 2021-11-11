#include <stdio.h>

int main()
{

	int a[100], i,n,temp, br2=0,k;
	int  b[1000],d1,obrnuti=0,d2, br=0,j=0;

	printf("Unesite velicinu niza: ");
	do {
		scanf("%d", &n);

	} while(n<=0);

	printf("Unesite clanove niza: ");

	for(i=0; i<n; i++) {
		do {
			scanf("%d", &a[i]);

		} while(a[i]<0);


	}
	for(i=0; i<n; i++) {
		while(a[i]!=0) {
			d1=a[i]%10;
			obrnuti=(obrnuti*10)+d1;
			a[i]/=10;
			br++;


		}

		while(obrnuti!=0) {
			d2=obrnuti%10;
			obrnuti/=10;

			temp=d2;
			d2=b[j];
			b[j]=temp;
			j++;

		}
	}
	for(i=0; i<br; i++) {
		
				printf("%d %d", b[i]);
			
		
	}



	return 0;
}
