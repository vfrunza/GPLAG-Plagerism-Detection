#include <stdio.h>
#include <math.h>
#define MAX 100
 
void zaokruzi1 (float* niz_1,int velicina_1) {
	float* p=niz_1;
	while(p<niz_1+velicina_1) {
		*p*=10;
		*p=round(*p);
		*p=(*p)/10;
		*p++;
	}
	
	
}

int main() {
	float niz_1[MAX];
	int i,velicina_1=0;
	printf("Unesite velicinu niza: ");
	scanf("%d",&velicina_1);
	printf("Unesite clanove niza: ");
	for(i=0;i<velicina_1;++i) {
		scanf("%f",&niz_1[i]);
}
zaokruzi1(niz_1,velicina_1);
for(i=0;i<velicina_1;i++){
	printf("%g",niz_1[i]);
}
		
	
	return 0;
}
