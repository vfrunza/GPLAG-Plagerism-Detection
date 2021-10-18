#include <stdio.h>
/*sky full of starrrsssssss*/
int main() {
int k,r,n;
printf ("Unesite broj n: ");
scanf ("%d", &n);
while (n<=0 || n>50){
	printf ("Pogresan unos\n");
    printf ("Unesite broj n: ");
	scanf ("%d",&n);}

/*k=kolona, r=redovi, n=broj*/

if (n==1) {printf ("***");
	return 0; 
}

for (r=1; r<=n;r++) {
	for (k=1;k<=n*4-3; k++){
		if (r==k || r==n*2-k || k==(n*3-2-(n-r)) || k==(n*4-r)-2){printf ("*");
		}
		else { printf (" ");}
	}printf ("\n");
	} 
	return 0;
}

