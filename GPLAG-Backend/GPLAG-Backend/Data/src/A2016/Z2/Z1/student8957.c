#include <stdio.h>

int main() {
	int n,cz,cp,nc,kb=0,pb1=0,pb2=0,n1,bc=0,c1,c2,pkb;
	printf ("Unesite broj: ");
	scanf ("%d",&n);
	if (n==0){ printf ("0"); return 0; }
	n1=n;
	
	while (n1!=0){
		bc++;
		n1/=10;
	}
	n1=n;
	
	while (n!=0){
		cz=n%10;
		cp=(n/10)%10;
		nc=cz-cp;
		if (nc<0) nc=-1*nc;
		pkb=(pb1+nc)*10;
		pb1=pkb;
		pb2++;
		if (pb2==(bc-1)) break;
		n/=10;
	}
	cz=0;pb1=0;
	
	while (pkb != 0){
		cz=pkb%10;
		kb=(pb1+cz)*10;
		pb1=kb;
		pkb/=10;
	}
	c1=n1%10;
	c2=(n1/10)%10;
	
	if (bc==1) 
		printf ("0");
	else if (c1==c2)
		printf("%d",kb);
	else 
		printf ("%d",kb/10);
	return 0;
}
