#include <stdio.h>
#define PI 3.1415926
struct stepeni{
	int stepen;
	int minuta;
	int sekunda;
};
struct stepeni pretvorbaUglova(double rad){
	struct stepeni var;
	int a;
	if(rad>=0)
		a=((rad*180*3600/PI) + 0.5);
	if(rad<0)
		a=((rad*180*3600/PI) - 0.5);
	var.stepen= a/3600;
	if(a<0)
		a*=-1;
	var.sekunda= a%60;
	a/=60;
	var.minuta= a%60;
	return var;
}
int main() {
	//printf("Zadaća 2, Zadatak 2");
	int broj, i;
	struct stepeni uglovi[500];
	double ugao;
	printf("Unesite broj uglova: ");
	scanf("%d", &broj);
	for(i=0; i<broj; i++){
		scanf("%lf", &ugao);
		uglovi[i]= pretvorbaUglova(ugao);
		if(uglovi[i].sekunda>30 || uglovi[i].sekunda<-30){
			i--;
			broj--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<broj; i++){
		printf("%d stepeni %d minuta %d sekundi\n", uglovi[i].stepen, uglovi[i].minuta, uglovi[i].sekunda);
	}
	return 0;
}
