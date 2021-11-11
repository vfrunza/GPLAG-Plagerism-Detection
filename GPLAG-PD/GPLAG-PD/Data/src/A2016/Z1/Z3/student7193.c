#include <stdio.h>

int main() {
	char n;
	int c=0,b=0,s=0,v=0,p=0,a=0;
	float c1,b1,s1,v1,p1;
	printf("Unesite vozila: ");
	scanf("%c",&n);
	while(n!='k' || n!='K')
	{
	 
	 if(n=='c' || n=='C') 
	 c++;
	 else if(n=='b' || n=='B') 
      b++; 
	 else if(n=='s' || n=='S') 
	  s++; 
	 else if(n=='v' || n=='V') 
	  v++; 
	 else if(n=='p' || n=='P') 
	  p++; 
	 else if(n=='k' || n=='K')
	   break;
	 else 
	 printf("Neispravan unos\n");
	 scanf("%c",&n);
     }
     a=c+b+s+v+p;
     printf("Ukupno evidentirano %.1d vozila.\n",a);
     if(a==0)
     printf("Najpopularnija boja je crna (%.2f%%).",(float)a);
     else if(c>=b && c>=s && c>=v && c>=p)
        { c1=((float)c/a)*100; printf("Najpopularnija boja je crna (%.2f%%).",c1);}
    else if(b>=c && b>=s && b>=v && b>=p)
        { b1=((float)b/a)*100; printf("Najpopularnija boja je bijela (%.2f%%).",b1);}
     else if (s>=c && s>=b && s>=v && s>=p)
        { s1=((float)s/a)*100; printf("Najpopularnija boja je siva (%.2f%%).",s1);}
     else if(v>=c && v>=b && v>=s && v>=p)
        { v1=((float)v/a)*100; printf("Najpopularnija boja je crvena (%.2f%%).",v1);}
    else if(p>=c && p>=b && p>=s && p>=v)
        { p1=((float)p/a)*100; printf("Najpopularnija boja je plava (%.2f%%).",p1);}
      
    return 0;
}
