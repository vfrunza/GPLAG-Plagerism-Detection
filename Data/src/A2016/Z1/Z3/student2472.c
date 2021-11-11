#include <stdio.h>

int main() {
	char x=0;
	int sc=0,sb=0,ss=0,sv=0,sp=0,su=0;
	float pc,pb,ps,pv,pp;
	printf("Unesite vozila: ");
	while(x!='k' && x!='K'){
		scanf("%c", &x);
		if(x!='c' && x!='C' && x!='b'&& x!='B' && x!='s' && x!='S' && x!='v' && x!='V' && x!='p' && x!='P' && x!='k' && x!='K'){printf("Neispravan unos\n");}
		else if(x=='c' || x=='C' || x=='b' || x=='B' || x=='s' || x=='S' || x=='v' || x=='V' || x=='p' || x=='P')  {
		if(x=='c'|| x=='C'){sc++;su++;}
		if(x=='b'|| x=='B'){sb++;su++;}
		if(x=='s'|| x=='S'){ss++;su++;}
		if(x=='v'|| x=='V'){sv++;su++;}
		if(x=='p'|| x=='P'){sp++;su++;}
		}
		
		}
	printf("Ukupno evidentirano %d vozila.\n", su);
	if(su==0){printf ("Najpopularnija boja je crna (0.00%%).");}
	else if(sc>=sb && sc>=ss && sc>=sv && sc>=sp){pc=(sc*100.00/su); printf("Najpopularnija boja je crna (%.2f%%).", pc);}
	else if(sb>=sc && sb>=ss && sb>=sv && sb>=sp){pb=(sb*100.00/su); printf("Najpopularnija boja je bijela (%.2f%%).", pb);}
	else if(ss>=sc && ss>=sb && ss>=sv && ss>=sp){ps=(ss*100.00/su); printf("Najpopularnija boja je siva (%.2f%%).", ps);}
	else if(sv>=sc && sv>=sb && sv>=ss && sv>=sp){pv=(sv*100.00/su); printf("Najpopularnija boja je crvena (%.2f%%).", pv);}
	else if(sp>=sc && sp>=sb && sp>=ss && sp>=sv){pp=(sp*100.00/su); printf("Najpopularnija boja je plava (%.2f%%).", pp);}
	
	return 0;
}
