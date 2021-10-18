#include <stdio.h>

char* ubaci_broj (char* s, int n){
	char *povratni  = s, *temp, *novi;
	int broj_razmaka = 0;
	int je_li_prva_iteracija = 0;
	int brcifara=0;
	int tempbroj=n ,i ;
	while (tempbroj>0){
	    tempbroj/=10;
	    brcifara++; //brojim cifre
	    
	}
	while(*s != '\0'){
	    if(je_li_prva_iteracija == 0){ 
	        je_li_prva_iteracija = 1;
	        while(*s == ' ') s++;
	    }
	    while(*s != ' ') s++;
	    temp = s;
        while(*s == ' ')s++;
        broj_razmaka = s - temp;
        if(broj_razmaka == 1){
            //pomjeramo sve za broj_cifara + 1 (+1 zbog space-a poslije broja)
            novi = s;
            while(*novi != '\0')novi++;
            while(novi != s){
                if()
                *(novi + brcifara +1) = *novi; 
                novi--;
            }
            /*s = s + brcifara;
            *s = ' ';
            for(i = 0; i < brcifara; i++){
                *s = n/10;
                n /= 10;
                s--;
            }*/
        }
        s++;
        
	}
	return povratni;
}

int main() {
	char string[150] = "Ovo je neki rimjer teksta";
	printf("%s", ubaci_broj(string, 123));
	return 0;
}
