#include <stdio.h>

int main() {
	int unos, tmp1, tmp2, rezultat=0;
	printf("Unesite broj: ");
	scanf("%i", &unos);
	if(unos>=0 && unos<=9) {
		printf("0");
		return 0;
	}
	if(unos<0) unos*=-1;
	while(unos){
		tmp1=unos%10;
		unos/=10;
		tmp2=unos%10;
		if(tmp1-tmp2<0)
			rezultat+=tmp2-tmp1;
		else
			rezultat+=tmp1-tmp2;
		rezultat*=10;
	}
	rezultat/=100;
	unos=0;
	while(rezultat){
		unos+=rezultat%10;
		unos*=10;
		rezultat/=10;
	}
	unos/=10;
	printf("%i", unos);
	return 0;
}
