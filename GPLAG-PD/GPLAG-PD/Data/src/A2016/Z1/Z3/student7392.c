#include <stdio.h>

int main() {
    int b=0, c=0, s=0, v=0, p=0, brojac=0;
    int maxi;
    char ch;
    printf("Unesite vozila: ");
	do{
	    scanf("%c", &ch);
	    if(ch=='C' || ch=='c'){
	        c++;
	        brojac++;
	    } else if(ch=='B' || ch=='b'){
	        b++;
	        brojac++;
	    } else if(ch=='S' || ch=='s'){
	        s++;
	        brojac++;
	    } else if(ch=='V' || ch=='v'){
	        v++;
	        brojac++;
	    } else if(ch=='P' || ch=='p'){
	        p++;
	        brojac++;
	    } else if(ch!='K' && ch!='k'){
	        printf("Neispravan unos\n");
	    }
	}while(ch!='K' && ch!='k');
	
	printf("Ukupno evidentirano %d vozila.", brojac);
	if(brojac!=0){
		printf("\nNajpopularnija boja je ");
		if(c>=b && c>=s && c>=p && c>=v){
			maxi=c;
			printf("crna ");
		} else if(b>=c && b>=s && b>=p && b>=v){
			maxi=b;
			printf("bijela ");
		} else  if(s>=c && s>=b && s>=p && s>=v){
			maxi=s;
			printf("siva ");
		} else if(v>=c && v>=s && v>=p && v>=b){
			maxi=v;
			printf("crvena ");
		} else {
			maxi=p;
			printf("plava ");
		}
		printf("(%.2f%%).", (float)maxi/brojac*100);
	} else printf("\nNajpopularnija boja je crna (0.00%%).");
	return 0;
}
