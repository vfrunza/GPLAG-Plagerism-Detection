#include <stdio.h>


char *ubaci_broj(char *s, int x) {
    
	char *povratni = s, *pomocni;
    int broj = x, broj2 = 0, brojac = 0;
    if(broj < 0)
    	brojac++;
    while(broj != 0)
    {
    	broj /= 10;
    	brojac++;
    }
    while(*s != '\0' && *s == ' ')
    	s++;
    while(*s != '\0')
    {
        if(*s == ' ')
    	{
    	    /* test ima li rijeci iza */
    	    pomocni = s;
    	    while(*s != '\0' && *s == ' ')
                s++;
            if(*s == '\0')
                break;
            s = pomocni;

    		/*pomocni ide na kraj stringa*/
    		s++;
    		pomocni = s;
    		while(*pomocni != '\0')
    			pomocni++;

            /*pravimo prostor za broj u stringu*/
    		while(pomocni >= s)
    		{
    			*(pomocni+brojac) = *pomocni;
    			pomocni--;
    		}
    		broj = x;
    		broj2 = 0;
    		/*broj izvrcemo naopako da bi ga mogli lakse upisivati*/
    		while(broj != 0)
    		{
    		    broj2*=10;
				broj2 += broj % 10;
				broj /= 10;
			}
			/*provjera da li je broj negativan te da li treba ubaciti char '-'*/
			if(x < 0){
				*s = '-';
				broj2 *= -1;
				s++;
			}
			/*ubacivanje broja*/
			while(broj2 != 0)
			{
				*s = broj2 % 10 + '0';
				broj2 /= 10;
				s++;
			}
			/*u slucaju da se iza broja ne nalazi razmak*/
			/*pravimo prostor za razmak i ubacujemo razmak*/
			if(*s != ' ')
            {
                while(*pomocni != '\0') pomocni++;
                while(pomocni > s)
                {
                    *pomocni = *(pomocni -1);
                    pomocni--;
                }
                *s = ' ';
            }
            /*tjeramo pokazivac do kraja razamak tj. do pocetka nove rijeci*/
            while(*s == ' ' && *s != '\0') s++;
            /*tjeranje broja do kraja eventualno pronadjene rijeci*/
			while(*s != ' ' && *s != '\0') s++;
			/*s-- zato sto se iza desi s++, pa da ne bi preskocili taj char*/
			s--;
		}
		s++;
    }

	return povratni;
}
int main() {
	return 0;
}