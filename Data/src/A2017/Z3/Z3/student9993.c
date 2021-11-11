#include <stdio.h>
#include <math.h>
int izbaci_cifre (int brojevi[], int velicinabr, int cifre[], int velicinacif){
    
    int i, j, x;
	
/* Provjeravanje validnosti niza cifara */
	
	for (i=0; i<velicinacif; i++){
	    x=cifre[i];
	    for(j=0; j<velicinacif; j++){
	        if((x==cifre[j] && (i!=j)) || x<0 || x>9){
	            return 0;
	    }
	}
}

int* br=brojevi;
    int* cif=cifre;
    int koeficijent=1, ostatak=0, zavrsni=0;
    
/* Izbacivanje cifre iz clanova niza brojeva */

while (br<brojevi+velicinabr){
    while(cif<cifre+velicinacif){
        int bruniz=fabs(*br);  /* varijabla bruniz je temporalna vrijednost clana niza "brojevi" */
        while(bruniz!=0){
            ostatak=bruniz%10;
            bruniz=bruniz/10;
            if(ostatak!=*cif){
                zavrsni+=koeficijent*ostatak; /* varijabla ostatak je odsječak varijable bruniz koju poredimo sa ciframa */
                koeficijent*=10;
            }
        }
        if(*br<0){
            *br=-zavrsni;
        }
        else { *br=zavrsni;
        }
        cif++, zavrsni=0, koeficijent=1;
    }
    br++, cif=cif-velicinacif;
}
return 1;
}

int main(){
    return 0;
}
    
