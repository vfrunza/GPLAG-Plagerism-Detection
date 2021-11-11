#include <stdio.h>
double piz1=6.80;
double piz2=8.00;
double piz3=5.30;
double ham1=3.30;
double ham2=3.00;
double ham3=5.00;
double cev1=5.00;
double cev2=3.90;
double cev3=6.00;

int main() {
    char novired;
    float rest = 0, bist = 0, fast = 0;
    char tarik,bojan,mirza;
	printf("Unesite jelo za Tarika: ");
	scanf ("%c",&tarik);
	scanf ("%c",&novired);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c",&bojan);
	scanf ("%c",&novired);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c",&mirza);
	
	if(tarik == 'P'){
		rest += piz1;
		fast +=piz2;
		bist += piz3;
	}else if(tarik == 'C'){
		rest += cev1;
		fast +=cev2;
		bist += cev3;
	}else if(tarik == 'H'){
		rest += ham1;
		fast +=ham2;
		bist += ham3;
	}
	
	if(bojan == 'P'){
		rest += piz1;
		fast +=piz2;
		bist += piz3;
	}else if(bojan == 'C'){
		rest += cev1;
		fast +=cev2;
		bist += cev3;
	}else if(bojan == 'H'){
		rest += ham1;
		fast +=ham2;
		bist += ham3;
	}
	
	if(mirza == 'P'){
		rest += piz1;
		fast +=piz2;
		bist += piz3;
	}else if(mirza == 'C'){
		rest += cev1;
		fast +=cev2;
		bist += cev3;
	}else if(mirza == 'H'){
		rest += ham1;
		fast +=ham2;
		bist += ham3;
	}
	
	
	float najjeft;
	
	if(rest < bist && rest < fast) najjeft = rest;
	else if(bist < rest && bist < fast) najjeft = bist;
	else if(fast < rest && fast < bist) najjeft = fast;
	
	if(rest == najjeft){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", rest);
	}else{
		if(fast == najjeft)
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", fast);
		else
		if(bist == najjeft)
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bist);
			
		if(tarik == 'P' && bojan == 'P' && mirza == 'P')
			rest -= 3 * 0.1 * piz1;
		else if(tarik == 'P' && bojan == 'P' && mirza == 'H')
		     rest -= 2 * 0.1 * piz1 * ham1;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'H')
		     rest -= 1 * 0.1 * piz1 * 2 * ham1;
		     else if (tarik == 'H' && bojan == 'H' && mirza == 'H')
		     rest -= 3 * 0.1 * ham1;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'H')
		     rest -= 1 * 0.1 * piz1 * 2 * ham1;
		     else if (tarik == 'C' && bojan == 'P' && mirza == 'P')
		     rest -= 2 * 0.1 * piz1 * cev1;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'P')
		     rest -= 2 * 0.1 * cev1 * piz1;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'H')
		     rest -= 2 * 0.1 * cev1 * ham1;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'C')
		     rest -= 3 * 0.1 * cev1;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'C')
		     rest -= 1 * 0.1 * piz2 * ham2 * cev2;
		     else if(tarik == 'P' && bojan == 'P' && mirza == 'H')
		     rest -= 2 * 0.1 * piz2 * ham2;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'H')
		     rest -= 1 * 0.1 * piz2 * 2 * ham2;
		     else if (tarik == 'H' && bojan == 'H' && mirza == 'H')
		     rest -= 3 * 0.1 * ham2;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'H')
		     rest -= 1 * 0.1 * piz2 * 2 * ham2;
		     else if (tarik == 'C' && bojan == 'P' && mirza == 'P')
		     rest -= 2 * 0.1 * piz2 * cev2;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'P')
		     rest -= 2 * 0.1 * cev2 * piz2;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'H')
		     rest -= 2 * 0.1 * cev2 * ham2;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'C')
		     rest -= 3 * 0.1 * cev2;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'C')
		     rest -= 1 * 0.1 * piz2 * ham2 * cev2;
		  else if (tarik == 'P' && bojan == 'H' && mirza == 'C')
		     rest -= 1 * 0.1 * piz3 * ham3 * cev3;
		     else if(tarik == 'P' && bojan == 'P' && mirza == 'H')
		     rest -= 2 * 0.1 * piz3 * ham3;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'H')
		     rest -= 1 * 0.1 * piz3 * 2 * ham3;
		     else if (tarik == 'H' && bojan == 'H' && mirza == 'H')
		     rest -= 3 * 0.1 * ham3;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'H')
		     rest -= 1 * 0.1 * piz3 * 2 * ham3;
		     else if (tarik == 'C' && bojan == 'P' && mirza == 'P')
		     rest -= 2 * 0.1 * piz3 * cev3;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'P')
		     rest -= 2 * 0.1 * cev3 * piz3;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'H')
		     rest -= 2 * 0.1 * cev3 * ham3;
		     else if (tarik == 'C' && bojan == 'C' && mirza == 'C')
		     rest -= 3 * 0.1 * cev3;
		     else if (tarik == 'P' && bojan == 'H' && mirza == 'C')
		     rest -= 1 * 0.1 * piz3 * ham2 * cev3;
	
		
		if(rest < najjeft)
			printf ("\nSa popustom bi Restoran bio jeftiniji (%g KM).", rest);
			
		
	}
	

	
	return 0;
}
