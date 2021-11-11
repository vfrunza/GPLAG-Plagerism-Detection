#include <stdio.h>

int main() {
	int a, novibroj=0, prvacifra, drugacifra, razlika, mnoz=1;
	printf("Unesite broj: ");
	scanf("%d", &a);
	if(a<0) a=a*(-1);
	if(a/10==0) printf("0");
	else{
	while((a/10)!=0){
		prvacifra=a%10;
		a=a/10;
		drugacifra=a%10;
		razlika=prvacifra-drugacifra;
		if(razlika<0) razlika=razlika*(-1);
		novibroj=razlika*mnoz+novibroj;
		mnoz=mnoz*10;
	}
	printf("%d", novibroj);}
	return 0;
}
