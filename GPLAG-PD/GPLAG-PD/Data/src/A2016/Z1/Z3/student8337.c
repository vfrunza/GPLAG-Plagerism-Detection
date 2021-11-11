#include <stdio.h>

int main() {
	
	char n;
	int a, b=0, c=0, s=0, v=0, p=0, suma=0;
	float prosjekc, prosjekb, prosjeks, prosjekv, prosjekp;
	printf("Unesite vozila: ");
	
	do{
		    
	        scanf("%c", &n);
	        a= (int)n;
	        if(a==67 || a==99 || a==66 || a==98 || a==83 || a==115 || a==86 || a==118 || a==80 || a==112 || a==75 || a==107){
	        if(a==67 || a==99) c++;
	        if(a==66 || a==98) b++;
	        if(a==83 || a==115) s++;
	        if(a==86 || a==118) v++;
	        if(a==80 || a==112) p++;
	        }else{
	        	printf("Neispravan unos\n");
	        }
	}while(a!=75 && a!=107);
	suma=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.\n", suma);
	if(suma!=0){
    if(c>=b && c>=s && c>=v && c>=p){
    	prosjekc= (float) c / suma;
    	printf("Najpopularnija boja je crna (%.2f%%).", prosjekc*100);
    	
    }else if(b>=s && b>=v && b>=p && b>c){
    	prosjekb= (float) b / suma;
    	printf("Najpopularnija boja je bijela (%.2f%%).", prosjekb*100);
    }else if(s>=v && s>=p && s>c && s>b){
    	prosjeks= (float) s / suma;
    	printf("Najpopularnija boja je siva (%.2f%%).", prosjeks*100);
    }else if(v>=p && v>s && v>b && v>c){
    	prosjekv= (float) v / suma;
    	printf("Najpopularnija boja je crvena (%.2f%%).", prosjekv*100);
    }else if(p>v && p>s && p>b && p>c){
    	prosjekp= (float) p / suma;
    	printf("Najpopularnija boja je plava (%.2f%%).", prosjekp*100);
    }
	}else{
		printf("Najpopularnija boja je crna (0.00%%).");
	}
	return 0;
}
