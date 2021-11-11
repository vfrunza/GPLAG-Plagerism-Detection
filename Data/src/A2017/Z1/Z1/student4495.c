#include <stdio.h>

int main() {
char mirza,tarik,bojan,nr;
float Hkonj, Htr, Hlor, Ckonj, Ctr, Clor, Pkonj, Ptr, Plor,HU=0, TU=0, PU=0;

do {	printf("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &nr);
	if (tarik!='H' && tarik!='C' && tarik!='P')
{	printf ("\nUnos je pogresan, dostupni karakteri su C,H i P\n"); }
} while (tarik!='H' &&  tarik!='C' && tarik!='P' );
do {	 printf("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &nr); 
		if (bojan!='H'  && bojan!='C' && bojan!='P')
	{	printf ("\nUnos je pogresan, dostupni karakteri su C,H i P\n"); }
	} while (bojan!='H' &&  bojan!='C' &&  bojan!='P');
do {	printf("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &nr);
	if (mirza!='H' && mirza!='C' && mirza!='P' )
		{	printf ("\nUnos je pogresan, dostupni karakteri su C,H i P\n"); }
} while (mirza!='H' &&  mirza!='C' &&  mirza!='P');

if (tarik== 'H')	
{
Hkonj=3.3;
Htr=3.0;  
Hlor=5.0; 
} 
if (mirza== 'H')	
{
Hkonj=3.3;
Htr=3.0;
Hlor=5.0; 
}
if (bojan== 'H')	
{
Hkonj=3.3;
Htr=3.0;
Hlor=5.0; 
}
if (tarik== 'C')	
{
 Ckonj=5.0;
 Ctr=3.9;
 Clor=6.0; 
}
if (bojan== 'C')	
{
 Ckonj=5.0;
 Ctr=3.9;
 Clor=6.0; 
}
if (mirza== 'C') 
{
 Ckonj=5.0;
 Ctr=3.9;
 Clor=6.0;	
	
}
if (tarik== 'P')	
{
 Pkonj=6.8;
Ptr=8.0;
Plor=5.3; 
}
if (bojan== 'P')	
{
 Pkonj=6.8;
Ptr=8.0;
Plor=5.3;
}
if (mirza== 'P') {
 Pkonj=6.8;
Ptr=8.0;
Plor=5.3;	
	
}
/*za tri kombinacije*/
HU=Hkonj+Pkonj+Ckonj;	
	TU=Htr+Ctr+Ptr;
	PU=Pkonj+Htr+Clor;
	if (PU>TU && PU> TU)	
	{
		printf ("Najjeftiniji je Fast-food \"trovic\" (%.2f KM).", TU);
	}
if (TU>HU && PU>HU)	
{	
	printf ("Najjeftiniji je Fast-food \"Kod konja i konjusara\" (%.2f KM).", HU );
	
}
if (HU>TU && TU>PU)
{
		printf ("Najjeftiniji je Bistor \"Lorelei\" (%.2f KM).", PU );
}
	
	
	
	
	return 0;

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
