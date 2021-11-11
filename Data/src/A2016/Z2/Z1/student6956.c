#include <stdio.h>
#include <math.h>

int main() {
	int x, c, nx=0,s, p, d, cif, br=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0) x=-x;
	if(x<10 && x>=0) printf("%d", br);
	else {
		if(x%10==0) s=x%100/10; else s=0;
	while(x!=0){
		c=x%10;
		nx=c+nx*10;
		x/=10;
	}
	while(nx!=0){
		p=nx%10;
		d=nx%100/10;
		cif=p-d;
		if(cif<0) cif=-cif;
		br=cif+br*10;
		nx/=10;
		if(nx<10) break;
	} 
	if(s!=0 && br%10==0) br=br*10+s;
	else br=br+s;
	printf("%d",br);
	}
	return 0;
}
