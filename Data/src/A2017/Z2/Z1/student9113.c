#include <stdio.h>

int main() {
	int i,j,n,k,d,e;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n<8 || n%4!=0) printf("Neispravno N!\n");
	}while(n<8 || n%4!=0);
	k=n/2;
	d=k/2;
	e=k+d;
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j && i<k && j<k ) printf("\\");
			if(((i+j)==(k-1)) && i<k && j<k) printf("/");
			if(i!=j && ((i+j)!=(k-1)) && i<k && j<k) printf(" ");
			if((i==0 || i==k-1) && (j==k || j==n-1)) printf("+");
			if((i==0 || i==k-1) && (j>k && j<n-1)) printf("-");
			if((j==k || j==n-1) && i>0 && i<k-1) printf("|");
		    if((j>k && j<n-1) && (i>0 && i<k-1)) printf(" ");
		    if((i==k || i==n-1) && (j==0 || j==k-1)) printf("+");
		    if((i==k || i==n-1) && (j>0 && j<k-1)) printf("-");
		    if((j==0 || j==k-1) && (i>k && i<n-1)) printf("|");
		    if((j>0 && j<k-1) && (i>k && i<n-1)) printf(" ");
		    if(((i>=k && i<e-1) || (i>e && i<=n-1)) && (j>=k && j<=n-1) && (j==e-1 || j==e)) printf("|");
		    if(((j>=k && j<e-1) || (j>e && j<=n-1)) && (i>=k && i<=n-1) && (i==e-1 || i==e)) printf("-");
		    if((j!=e-1 && j!=e) && (i!=e-1 && i!=e) && (i>=k && i<=n-1) && (j>=k && j<=n-1)) printf(" ");
		    if((i==e-1 || i==e) && (j==e-1 || j==e)) printf("+");
		   	}
		printf("\n");
	}
	return 0;
}
