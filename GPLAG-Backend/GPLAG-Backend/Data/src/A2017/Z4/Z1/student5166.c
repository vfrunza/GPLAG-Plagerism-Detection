#include <stdio.h>
#include <math.h>

char *ubaci_broj (char *tekst, int broj){
     int broj_cifara=1, i=0, temp=fabs(broj), pomocna=0, x=1;
	char *p=tekst, *kraj=tekst, *s;
	if (broj < 0) x=2;
	 
	while (*kraj != '\0') kraj++; /* uzimam pok. na kraj stringa */
	     s = kraj;
	     s--;
	 
     while (temp != 0){
     	broj_cifara++;
     	temp/=10;
     }
     
     if (broj < 0) broj_cifara++; /* dodavanje jos jednog mjesta za minus, ako je br. neg */
     kraj = s+broj_cifara;
	
     temp = fabs(broj);
     while (temp != 0){ /* okretanje broja radi lakseg ubacivanja */
         pomocna += (temp%10);
         temp/=10;
         if (temp == 0) break;
         pomocna*=10;
     }
     
     temp = fabs(pomocna);
     while (*p == ' ') p++; /* prelijecemo preko razmaka na pocetku stringa */
     
     while (*p != '\0'){
     	  if (*p == ' ' && *(p+1)!=' '){
     	   	     *(kraj+1) = '\0';
     	   	     while (s != p){ /* pravi se mjesto za broj pomjerajuci znakove unutar stringa udesno */
     	   	          *kraj = *s;
     	   	          kraj --;
     	   	          s--;
     	   	     }
     	   	     p++;
     	   	     
     	   	     if (broj < 0){
     	   	          *p='-';
     	   	          p++;
     	   	     }
     	   	     
     	   	     for (i=0; i<broj_cifara-x; i++){ /* ubacujemo onaj broj koji smo okrenuli */
     	   	     	  *p = '0' + temp%10;
     	   	     	  temp /= 10;
     	   	     	  p++;
     	   	     }
     	   	     temp = fabs (pomocna);
     	   	     *p = ' ';
     	   	     
     	   	     
     	        	kraj = p; /* na kraju svakog prolaska postaviti pokazivace na nove pozicije */
     	        	while (*kraj != '\0') kraj++;
     	   	     s=kraj;
     	   	     s--;
     	   	     kraj = s+broj_cifara;
     	   	
     	   	     
         }
     	while (*p == ' ') p++; /* prelijecemo eventualne razmake poslije razmaka */
     	p++;
     }
     p = tekst;
     	    
 return p;   
}
 
int main (){
	
	return 0;
}