#include <stdio.h>
//optimisation needed
//need better idea for priority

int main() {
	
	float m = 0;
	//Unos
	char a;
	//c-crna, b-bijela, d-plava, f-siva, g-crvena, h-ukupno, m-procenat
	//u,v,l,n i o - for priorities u-crna, v-bijela, o-siva, l-crvena, n-plava
	float b=0,c=0,d=0,f=0,g=0,u=0,v=0,l=0,n=0,o=0;
	int h = 0;
    printf("Unesite vozila: ");
    
 while(1)
 {
scanf("%c", &a);
 
//ASCII value of letters
    if (a==67 || a==99)
    {
 	c++;
 	h++;
 	u += (1./h);
     }

    else if (a==66 || a==98)
    {
 	b++;
 	h++;
 	v += (1./h);
    }
 
    else if (a==83 || a==115)
    {
 	f++;
 	h++;
    o += (1./h);
    }

    else if (a==86 || a==118)
    {
 	g++;
 	h++;
 	l += (1./h);
    }

    else if (a==80 || a==112)
    {
 	d++;
 	h++;
 	n += (1./h);
    }

    else if (a == 75 || a==107)
    {
 
    break;
 
    }
    
    else if (a==10)
    printf("");
    
    else
    printf("Neispravan unos\n");

 

 }

printf("Ukupno evidentirano %d vozila." , h);

if (h==0)
{
    m=0;
    printf("\nNajpopularnija boja je crna (%.2f%).",m);
}
//too lazy to optimise
else if( f < d && g < d && b < d && c < d || (f <= d && g <= d && b <= d && c <= d && n >l && n > o && n > v && n > u) )
{
	m = (d/h) * 100;
printf("\nNajpopularnija boja je plava (%.2f%).",m);
}
else if( d < f && g < f && b < f && c < f || (d <= f && g <= f && b <= f && c <= f && o >l && o > n && o > v && o > u))
{
	m = (f/h) * 100;
printf("\nNajpopularnija boja je siva (%.2f%).",m);
}
else if( d < g && f < g && b < g && c < g || (f <= g && d <= g && b <= g && c <= g && l > n && l > o && l > v && l > u))
{

	m = (g/h) * 100;
printf("\nNajpopularnija boja je crvena (%.2f%).",m);
}
else if( d < c && g < c && f < c & b < c || (f <= c && g <= c && b <= c && d <= c && u > m && u > o && u > v && u > n))
{
 
	m = (c/h) * 100;
printf("\nNajpopularnija boja je crna (%.2f%).",m);
}
else if( d < b && g < b && f < b & c < b || (f <= b && g <= b && d <= b && c <= b && v >m && v > o && v > n && v > u))
{
	m = (b/h) * 100;
printf("\nNajpopularnija boja je bijela (%.2f%).",m);
}
return 0;
}
