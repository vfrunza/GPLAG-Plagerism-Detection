#include <stdio.h>
#include <math.h>

int main() {
	int broj,i,dio,dio2,rez,ob=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	while (broj!=0){
		i=broj%10;
		dio=(broj-i)/10;
		if(dio==0)
		break;
		dio2=dio%10;
		rez=i-dio2;
		if(rez<0)
		rez=rez*(-1);
		broj=dio;
		ob=ob+k*rez;
		k*=10;
	}
	printf("%d",ob);
	return 0;
}
