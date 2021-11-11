#include <stdio.h>

int main() {
	int i, j, a, b, c, brojac;
	do {
    scanf ("%d", &a);
    if ((a%4!=0) || (a<8))
    printf ("Unesite broj N: Neispravno N!\n");
    else
    printf ("Unesite broj N: \n");}
	while ((a%4!=0) || (a<8));

	/* Za crtanje X */ 
	
	b=a/2;
	brojac=a/4;
	c=b+brojac;
			printf ("\n");
			for (i=1;i<=b;i++){
			for (j=1;j<=a;j++){
			if (i==j) {
			printf ("\\");
			}else if (j==(b+1)-i)
			printf ("/");
			else  if (((i!=j || !(j==(b+1)-i)) && j<=b) || (((i!=j || !(j==(b+1)-i)) && (i>1 && i<b))))
			printf (" ");
		
	/* Za crtanke 1 kvadra */
		
			if (i==1 || i==b) {
			if (j==b+1 || j==a){
			printf ("+");
			}else if (j>b+1 && j<a)
			printf ("-");
			}else if (j==b || j==a-2)
			printf ("|");
			}printf ("\n");
			}
			
	/* Za crtanje 2 kvadra i plusa */		
			
			for (i=0;i<b;i++) {
			for (j=0;j<a;j++){
			if (i==0 || i==b-1){
			if ((j==0 || j==b-1) && (j<b))
			printf ("+");
			else if ((j>0 && j<b-1) && (j<b))
			printf ("-");
			}else if (j==0 || j==b-1 ){
			printf ("|");
			}else if (j>0 && j<b-1) {
			printf (" ");
			}
			
	/* Za crtanke 2 kvadra */		
			
			if (i==(b/2) || i==(b/2)-1) {
            if ((j==c || j==(c)-1) && (j>=b))
		    printf ("+");
		    else if (j>=b)
		    printf ("-");
		    } if (i!=(b/2) && i!=(b/2)-1) {
		    if (j==c || j==c-1) 
		    printf ("|");
		    else if (j>=b) 
		    printf (" ");
		    }
			} printf("\n");
			}
	return 0;
}