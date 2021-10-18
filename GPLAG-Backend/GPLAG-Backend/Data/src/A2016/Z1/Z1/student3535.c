#include <stdio.h>
#define A 0

int main() {
	double p1t,p2t,zt,prt,zvrt,p1b,p2b,zb,prb,zvrb,p1m,p2m,zm,prm,zvrm;
	double zbir1,zbir2,zbir3;
	int ocjena_tarik,ocjena_bojan,ocjena_mahir;
	
    printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&p1t);
	if(p1t<0||p1t>20)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&p2t);
	if(p2t<0||p2t>20)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prt);
	if(prt<0||prt>10)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zt);
	if(zt<0||zt>10)
	{printf("Neispravan broj bodova");
	 return 0;
	} 
	printf("Zavrsni ispit: ");
	scanf("%lf",&zvrt);
	if(zvrt<0||zvrt>40)
	{printf("Neispravan broj bodova");
	return 0;
	}
	
	printf("Unesite bodove za Bojana: ");
    printf("\nI parcijalni ispit: ");
    scanf("%lf",&p1b);
    if(p1b<0||p1b>20)
    {printf("Neispravan broj bodova");
	return 0;
	}
    printf("II parcijalni ispit: ");
    scanf("%lf",&p2b);
    if(p2b<0||p2b>20)
    {printf("Neispravan broj bodova");
	return 0;
	}
    printf("Prisustvo: ");
    scanf("%lf",&prb);
    if(prb<0||prb>10)
    {printf("Neispravan broj bodova");
	return 0;
	}
    printf("Zadace: ");
    scanf("%lf",&zb);
    if(zb<0||zb>10)
    {printf("Neispravan broj bodova");
	return 0;
	}
    printf("Zavrsni ispit: ");
    scanf("%lf",&zvrb);
    if(zvrb<0||zvrb>40)
    {printf("Neispravan broj bodova");
	return 0;
	}
    
    printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&p1m);
	if(p1m<0||p1m>40)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&p2m);
	if(p2m<0||p2m>20)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prm);
	if(prm<0||prm>10)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zm);
	if(zm<0||zm>10)
	{printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zvrm);
	if(zvrm<0||zvrm>40)
	{printf("Neispravan broj bodova");
	return 0;
	}
	
	   

	   	zbir1=p1t+p2t+zt+prt+zvrt;
     	zbir2=p1b+p2b+zb+prb+zvrb;
    	zbir3=p1m+p2m+zm+prm+zvrm;
    	
    	 if(zbir1+A<55) ocjena_tarik=5;
    	        else if(zbir1+A>=55&&zbir1<65) ocjena_tarik=6;
    	        else if(zbir1+A>=65&&zbir1<75) ocjena_tarik=7;
    	        else if(zbir1+A>=75&&zbir1<85) ocjena_tarik=8;
    	        else if(zbir1+A>=85&&zbir1<92) ocjena_tarik=9;
    	        else ocjena_tarik=10;
    	        
    	      if(zbir2+A<55) ocjena_bojan=5;
    	         else if(zbir2+A>=55&&zbir2<65) ocjena_bojan=6;
    	         else if(zbir2+A>=65&&zbir2<75) ocjena_bojan=7;
    	         else if(zbir2+A>=75&&zbir2<85) ocjena_bojan=8;
    	         else if(zbir2+A>=85&&zbir2<95) ocjena_bojan=9;
    	         else ocjena_bojan=10;
    	         
    	       if(zbir3+A<55) ocjena_mahir=5;
    	         else if(zbir3+A>=55&&zbir3<65) ocjena_mahir=6;
    	         else if(zbir3+A>=65&&zbir3<75) ocjena_mahir=7;
    	         else if(zbir3+A>=75&&zbir3<85) ocjena_mahir=8;
    	         else if(zbir3+A>=85&&zbir3<95) ocjena_mahir=9;
    	         else ocjena_mahir=10;
    	      
    	         if(zbir1<(55+A)&&zbir2<(55+A)&&zbir3<(55+A))
    	                   printf("Nijedan student nije polozio.");
    	            else if((zbir1>=(55+A)&&zbir2<(55+A)&&zbir3<(55+A))||
    	                    (zbir2>=(55+A)&&zbir1<(55+A)&&zbir3<(55+A))||
    	                    (zbir3>=(55+A)&&zbir1<(55+A)&&zbir2<(55+A)))
    	                   printf("Jedan student je polozio.");
    	            else if((zbir1>=(55+A)&&zbir2>=(55+A)&&zbir3<(55+A))||
    	                    (zbir1>=(55+A)&&zbir3>=(55+A)&&zbir2<(55+A))||
    	                    (zbir2>=(55+A)&&zbir3>=(55+A)&&zbir1<(55+A))||
    	                    (zbir3>=(55+A)&&zbir2>=(55+A)&&zbir1<(55+A)))
    	                    printf("Dva studenta su polozila.");
    	                    
    	           else 
    	           {
    	           	printf("Sva tri studenta su polozila.");
    	           	
    	        
    	           	
    	        if(ocjena_tarik==ocjena_bojan&& ocjena_tarik==ocjena_mahir)
    	           	            printf("\nSva tri studenta imaju istu ocjenu.");
    	       else if((ocjena_tarik==ocjena_bojan&&ocjena_tarik!=ocjena_mahir&&ocjena_bojan!=ocjena_mahir)||
    	           	   (ocjena_bojan==ocjena_mahir&&ocjena_bojan!=ocjena_tarik&&ocjena_mahir!=ocjena_tarik)||
    	           	   (ocjena_mahir==ocjena_tarik&&ocjena_mahir!=ocjena_bojan&&ocjena_tarik!=ocjena_bojan))
    	           	      printf("\nDva od tri studenta imaju istu ocjenu.");
    	           	 else printf("\nSvaki student ima razlicitu ocjenu.");
    	           	    }
    	            
    	         
    	        
            
	
	
    
    
	
	return 0;
}
