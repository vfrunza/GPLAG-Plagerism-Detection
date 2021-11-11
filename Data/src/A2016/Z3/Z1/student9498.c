#include <stdio.h>
int daj_prost() {
static int mjesto=0, broj=1, brojac=-1;
    int i,k,da_li_je=0;
    for(i=broj+1;1000;i++){
        da_li_je=1;
        for(k=2;k<i && da_li_je==1;k++){
            if(i%k==0) da_li_je=0;
        }
        if(da_li_je==1){broj=i;break;mjesto++;}
        else if(da_li_je==0) brojac++;
    }
    return broj;

}
int main() {

int brojA,brojB,rezultat=0,i,neki_broj,radi=1;
do {
printf("Unesite brojeve A i B: ");
scanf("%d%d", &brojA,&brojB);
if(brojA<=0) printf("A nije prirodan broj.\n");
else if (brojA>=brojB) printf("A nije manje od B.\n");
		else radi=0;
	} while (radi==1);
	for(i=0; i<brojB; i++) {
	    neki_broj=daj_prost();
	    if(neki_broj>brojA && neki_broj<brojB) rezultat+=neki_broj;
	    if(neki_broj>brojB)
	  break;
	}
printf("Suma prostih brojeva izmedju %d i %d je %d.",brojA,brojB,rezultat);
return 0;
}
