#include <stdio.h>
#include<math.h>
#define epsilon 0.0001
int main(){
	char v='v';
	float pv=0,bv=0,sv=0,vv=0,cv=0;
	float a,d;
	
	printf("Unesite vozila: ");
	
	
	while(v!='k' && v!='K'){
	    
	    scanf("%c", &v);
	    if(v=='b' || v=='B'){ bv++;}
	else if(v=='c' || v=='C'){ cv++;
}
else if(v=='S' || v=='s'){sv=sv+1;}
else if(v=='v' || v=='V'){vv=vv+1;}
else if(v=='p' || v=='P'){pv=pv+1;}
else if(v=='k' || v=='K'){break;}
else printf("Neispravan unos\n");}
a=bv+cv+vv+pv+sv;
printf("Ukupno evidentirano %g vozila.", a);
if(fabs(a)<epsilon){ printf("\nNajpopularnija boja je crna (0.00%).");}
else{
 if(cv>=vv && cv>=pv && cv>=sv && cv>=bv){d=(cv/a)*100; printf("\nNajpopularnija boja je crna (%.2f%%).", d);}
 else if(bv>=vv && bv>=cv && bv>=sv && bv>=pv){d=(bv/a)*100; printf("\nNajpopularnija boja je bijela (%.2f%%).", d);}
 else if(sv>=vv && sv>=cv && sv>=bv && sv>=pv){d=(sv/a)*100; printf("\nNajpopularnija boja je siva (%.2f%%).", d);}
else if(vv>=pv && vv>=cv && vv>=sv && vv>=bv){d=(vv/a)*100; printf("\nNajpopularnija boja je crvena (%.2f%%).", d);}
else if(pv>=vv && pv>=cv && pv>=sv && pv>=bv){d=(pv/a)*100; printf("\nNajpopularnija boja je plava (%.2f%%).", d);}
}




return 0;}