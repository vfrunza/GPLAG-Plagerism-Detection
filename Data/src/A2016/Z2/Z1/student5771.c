#include <stdio.h>
#include<math.h>
#include <stdlib.h>
int main() {
	int a,b,brc,f,c1,d,c2, ispis=0;;

	printf("Unesite broj: ");
	scanf("%d", &a);
	b=abs(a);
f=abs(a);
	brc=1;
	if(a/10==0){printf("0");}
		else{
	do{brc=brc*10; 
		b=b/10;
	}while((b/10)!=0);
	do{
	d=f%brc;
	f=f/brc;
     brc=brc/10;
	 c1=d/brc;
	if(c1!=f)	        
	{ ispis=1;}
	if(ispis==1)
		 { c2=abs(c1-f);
		  printf("%d", c2);}      
		f=d;
	}while(brc>9);
		if(ispis==0){ printf("0");}
		}
	return 0;
}
