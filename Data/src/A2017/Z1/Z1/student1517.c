#include <stdio.h>

int main() {
	char a,b,c,novi_red,g;
	int P,H,C,k;
	float x,y,z,x1,p,h,m;
	P=0; H=0; C=0; x=0; y=0; z=0; g='"';
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&a); scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b); scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&c); scanf("%c", &novi_red);
	
	if(a=='P') {P++; x=x+6.8; y=y+8; z=z+5.3;}
	else if(a=='H') {H++; x=x+3.3; y=y+3; z=z+5;}
	else {C++; x=x+5; y=y+3.9; z=z+6;}
	
	if(b=='P') {P++; x=x+6.8; y=y+8; z=z+5.3;}
	else if(b=='H') {H++; x=x+3.3; y=y+3; z=z+5;}
	else {C++; x=x+5; y=y+3.9; z=z+6;}
	
	if(c=='P') {P++; x=x+6.8; y=y+8; z=z+5.3;}
	else if(c=='H') {H++; x=x+3.3; y=y+3; z=z+5;}
	else {C++; x=x+5; y=y+3.9; z=z+6;}
	
	if(x<y && x<z)
	{
		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", g,g,x); k=1;
	}
	
	if(y<x && y<z)
	{
		printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", g,g,y); k=2;
	}
	
	if(z<y && z<y)/*ako se desi da je moguce da cijene budu iste*/
	{
		printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", g,g,z); k=3;
	}
	
	p=P*6.8; h=H*3.3; m=C*5;
	if(p>=h && p>=m) x1=x-0.1*p;
	else if(h>=p && h>=m) x1=x-0.1*h;
	else x1=x-0.1*m;
	
	if(k!=1 && x1<y && x1<z) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",x1);
	
	
	return 0;
}
