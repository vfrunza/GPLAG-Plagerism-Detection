#include <stdio.h>
#include <math.h>

/*Funkcija svaki put kad se pozove daje sljedeci prosti broj, pomocu static varijable*/
int daj_prost ()
{
	static int pr=1;
	int i, prost, m;
	
	m=0;
	while (m==0)
	{
	   prost=-1;
	   pr++;
	
	/*Ako se prvi put poziva ova funkcija vratice broj 2 kao trazeni prosti broj*/
	   if (pr==2)
	   {
		  return 2;
	   }
	
	/*Ako nije 2 vrijednost koju funkcija vraca onda trazi sljedeci prosti broj*/
	   for (i=0; i<pr; i++)
	   {
		  if (i!=pr && i!=1 && i!=0)
		  {
		      if ((pr%i)==0)
			  {
				prost=0;
				break;
			  }
			
			  else
			  {
				prost=1;
			  }
		  }
	   }
	   
	   if (prost==1)
	   {
		  return pr;
	   }
	}
}


int main() 
{
    int a, b, m, suma, i, r; 
    double an, bn;
    
    suma=0;
    m=0;
	
	/*Unosenje brojeva A i B i provjera da li je A prirodan broj i je li A manje od B, 
	a ako nije prirodan broj i ako nije A manje od B trazi se od korisnika da se opet unesu vrijednosti za A i B*/
	
	while (m==0)
	{
	    printf ("Unesite brojeve A i B: ");
	    
	    scanf ("%lf %lf", &an, &bn);
	    
	    
	    if (an<=0) 
	    {
	        printf ("A nije prirodan broj.\n");
	    }
	    
	    
	    else if ((an==round(an)) && (bn==round(bn)))
	    {
	        a=(int)an;
	        b=(int)bn;
	        
	        if (a<b)
	        {
	            m=-1;
	        }
	        
	        else 
	        {
	            printf ("A nije manje od B.\n");
	        }
	    }
	    
	    
	    else if (an!=round(an)) 
	    {
	        printf ("A nije prirodan broj.\n");
	    }
	}
	
	/*Vrti petlju dok ne nadje sumu svih prostih brojeva izmedju brojeva A i B;
	a u toj petlji poziva funkciju daj_prost koja trazi te proste brojeve koji se 
	sabiraju u tu sumu ukoliko su izmedju A i B*/
	for (i=0; i<b; i++)
	{
		
	    r=daj_prost();
	    
	    if (r>a && r<b)
	    {
	    	suma=suma+r;
	    }
	    
	}
    
    printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	
	
	return 0;
}
