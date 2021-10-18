#include <stdio.h>

int main() {
	//printf("Zadaća 2, Zadatak 1");
	
	int a;
	int tmp1=0;
	int tmp2=0;
	int b=0;
	int tmp3=0;
	int br=1;

	printf ("Unesite broj: ");
	scanf ("%d", &a);

	if (a<0) a*=-1;
	
	for (;; ) {
		if ((int) a==0 || a<10)  break;
		tmp1=a%10;
		a=a/10;
		tmp2=a%10;
	
		tmp3=tmp1-tmp2;
		if (tmp3<0) tmp3*=-1;
	//	tmp1=tmp2;
	//	tmp2=(tmp3*br);
	//	b+=tmp2;
		b+=(tmp3*br);
		br*=10;
		
	}
	
	printf ("%d", b);
	return 0;
}
