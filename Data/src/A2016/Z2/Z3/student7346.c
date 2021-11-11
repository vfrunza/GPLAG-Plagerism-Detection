#include <stdio.h>
int main() {
	int a,c,d,m,i,z,n;
	int b=1;
	int kreativna[20][20]={{0}};
	do {
	    printf("Unesite broj tacaka: ");
	    scanf("%d", &a);
	    if(a<1 || a>10) printf("Pogresan unos\n"); 
	} while(a>10 || a<=0);
	    if(a<=10 && a>0){
	    	n=a;
	    	do{
	        for(i=0; i<n; i++){
	          printf("Unesite %d. tacku: ", b);
	          scanf("%d %d", &c,&d);
	          if(c>19){ printf("Pogresan unos\n"); n++; }
	          else if(c<0){ printf("Pogresan unos\n"); n++; }
	          else if(d<0){ printf ("Pogresan unos\n"); n++; }
	          else if(d>=20){ printf("Pogresan unos\n"); n++; }
	          else{ b++; kreativna[c][d]=1;}
	        } 
	      } while(c>=20 || c<0 || d<0 || d>19);
	    }
	for(m=0; m<=19; m++){
		for(z=0; z<=19; z++){
			d=m;
			c=z;
			if(kreativna[c][d]==1) printf("*");
			else printf(" ");
		} printf("\n");
	}
	return 0;
}
