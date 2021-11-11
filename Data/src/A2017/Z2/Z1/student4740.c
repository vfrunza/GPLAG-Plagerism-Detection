#include <stdio.h>

int main() {
	int n,i,j;
	
do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if (n<8|| n%4!=0) printf ("Neispravno N!\n");
	} while (n<8 || n%4!=0);
	
	printf("\n");
	
	for (i=1; i<=n; i++){
		/*ispis prve polovine crteza */
		if (i<=(n/2)){
				/* ispis prvog reda */
			if (i==1)
			{for (j=1;j<=(n/2); j++){
				if (j==1) printf("\\");
				else if (j==(n/2))printf("/");
				else printf(" ");
			}	
			for (j==(n/2)+1; j<=n; j++){
			if (j==(n/2)+1) printf("+");
				else if (j==n) printf("+");
				else printf("-");
		} printf("\n");}
		
			/* ispis zadnjeg reda */
		else	if ( i==(n/2))
			{for (j=1;j<=(n/2); j++){
				if (j==1) printf("/");
				else if (j==(n/2))printf("\\");
				else printf(" ");
			}	
			for (j==(n/2)+1; j<=n; j++){
			if (j==(n/2)+1) printf("+");
				else if (j==n) printf("+");
				else printf("-");
		} printf("\n");}
		
		/* ispis srednjih redova */
		else { for (j=1;j<=n; j++){
			if (i==j){
				if (i<=(n/2)) printf("\\");
			}
			else if((i+j)==(n/2)+1){
				if(i<=(n/2)) printf("/");
			}
			else if (j==(n/2)+1 || j==n) printf ("|");
			else printf(" ");
		}
		printf("\n");
		}}
		
		/*ispis druge polovine crteza */
		else if (i>(n/2)){
				/* ispis prvog reda */
			if (i==(n/2)+1)
			{for (j=1;j<=n; j++){
				
				if (j<=(n/2)){
				if (j==1 || j==(n/2)) printf("+");
				else printf("-");}
				
				else if (j>(n/2)){
				if (j==((3*n)/4) || j==(((3*n)/4))+1)	printf("|");
				else printf(" ");
			}	} printf("\n");}
			
			/*ispis zadnjeg reda */
			if (i==n)
			{for (j=1;j<=n; j++){
				
				if (j<=(n/2)){
				if (j==1 || j==(n/2)) printf("+");
				else printf("-");}
				
				else if (j>(n/2)){
				if (j==((3*n)/4) || j==(((3*n)/4))+1)	printf("|");
				else printf(" ");
			}	}printf("\n");}
			
			/* ispis srednjih redova crteza */
			if (i>(n/2)+1 && i<n){
				if (i==((3*n)/4) || i==(((3*n)/4))+1){
					for (j=1; j<=n;j++){
					if (j<=(n/2)){
					if (j==1 || j==(n/2)) printf ("|");
					else printf (" ");}
					else if (j>(n/2)){
				if (j==((3*n)/4) || j==(((3*n)/4))+1)	printf("+");
				else printf("-"); }}
		printf("\n");}
			
			else {
				for (j=1; j<=n;j++){
					if (j<=(n/2)){
					if (j==1 || j==(n/2)) printf ("|");
					else printf (" ");}
					else if (j>(n/2)){
				if (j==((3*n)/4) || j==(((3*n)/4))+1)	printf("|");
				else printf(" ");
			}} printf("\n");}
		
			}}
	}
	return 0;
}
