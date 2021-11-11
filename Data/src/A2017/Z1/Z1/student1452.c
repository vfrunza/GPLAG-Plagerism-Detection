#include <stdio.h>
#include <math.h>
#define e 0.0001

int main() {
	float s1=0,s2=0,s3=0,s4=0;
	char o1,o2,o3;
	/* Indeksi 1,2,3 oznacavaju restoran,fast food i bistro i pripadajuce cijene*/
	printf("Unesite jelo za Tarika: ");
    scanf(" %c",&o1);
    printf("Unesite jelo za Bojana: ");
    scanf(" %c",&o2);
    printf("Unesite jelo za Mirzu: ");
    scanf(" %c",&o3);
    
    switch(o1)
    {
    	case 'P':
    	s1=s1+6.80;
    	s2=s2+8.00;
    	s3=s3+5.30;
    	break;
    	
    	case 'H':
    	s1=s1+3.30;
    	s2=s2+3.00;
    	s3=s3+5.00;
    	break;
    	
    	case 'C':
    	s1=s1+5.00;
    	s2=s2+3.90;
    	s3=s3+6.00;
    	break;
    }
    switch(o2)
    {
    	case 'P':
    	s1=s1+6.80;
    	s2=s2+8.00;
    	s3=s3+5.30;
    	break;
    	
    	case 'H':
    	s1=s1+3.30;
    	s2=s2+3.00;
    	s3=s3+5.00;
    	break;
    	
    	case 'C':
    	s1=s1+5.00;
    	s2=s2+3.90;
    	s3=s3+6.00;
    	break;
    }
    switch(o3)
    {
    	case 'P':
    	s1=s1+6.80;
    	s2=s2+8.00;
    	s3=s3+5.30;
    	break;
    	
    	case 'H':
    	s1=s1+3.30;
    	s2=s2+3.00;
    	s3=s3+5.00;
    	break;
    	
    	case 'C':
    	s1=s1+5.00;
    	s2=s2+3.90;
    	s3=s3+6.00;
    	break;
    }
    if(fabs(s1-20.40)<=e || fabs(s1-9.9)<=e || fabs(s1-15.00)<=e) s4=s1-s1/10;
    else if(fabs(s1-15.1)<=e || fabs(s1-13.4)<=e) s4=s1-0.68;
    else if(fabs(s1-16.9)<=e || fabs(s1-18.6)<=e ) s4=s1-2*0.68;
    else if(fabs(s1-13.3)<=e || fabs(s1-16.8)<=e ) s4=s1-1.0;
    else if(fabs(s1-11.6)<=e) s4=s1-2*0.33;
    
    if(s1<s2 && s1<s3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s1);
    else if(s2<s3 && s2<s1) {
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s2);
    	if(s4<s2) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s4);
    }
    else if(s3<s2 && s3<s1) {
    	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s3);
    	if(s4<s3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s4);
    }
   return 0;
    
   }
