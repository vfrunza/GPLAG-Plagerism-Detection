#include <stdio.h>
#include <math.h>
#define EPSILON 0.01

int main() {
	int c, b, s, v, p, suma, x;
	float pp, pv, ps, pb, pc, postotak;
	char boja; 
	c=0;
	b=0;
	s=0; 
	v=0;
	p=0;
	printf("Unesite vozila: ");
    while(1){
     scanf("%c", &boja);
    	
        
        
    	 if(boja=='c' || boja=='C'){
    		c=c+1;
    	}
    	else if(boja=='b' || boja=='B'){
    		b=b+1;
    	}
    	else if(boja=='s' || boja=='S'){
    		s=s+1;
    	}
    	else if(boja=='v' || boja=='V'){
    		v=v+1;
    	}
    	else if(boja=='p' || boja=='P'){
    		p=p+1;
    	}
    	else if(boja=='k' || boja=='K'){
    		break;
    	}
    else if(boja!='b' || boja!='B' || boja!='s' || boja!='S' || boja!='v' || boja!='V' || boja!='p' || boja!='P' || boja!='k' || boja!='K' || boja==' '){
    		printf("Neispravan unos\n");
    		continue; 
    }
    }
    
   suma= c + b + s + v + p;
   printf("Ukupno evidentirano %d vozila.", suma);
   pc = (float)(c)/suma*100;
   pb = (float)(b)/suma*100;
   ps = (float)(s)/suma*100;
   pv = (float)(v)/suma*100;
   pp = (float)(p)/suma*100;
   
   if(suma==0){
       printf("\nNajpopularnija boja je crna (0.00%%).");
   }
   x=c;
   
  
   if(b>=x){
       x=b;
       
   }
   if(s>=x){
      x=s;
   }
   if(v>=x){
       x=v;
   }
   if(p>=x){
       x=p;
   }
  
  
   postotak = (float)(x)/suma*100;
   
   if (EPSILON > fabs(pc-postotak)){
       printf("\nNajpopularnija boja je crna (%.2f%%).", pc);
   }
   else if (EPSILON > fabs(pb-postotak)){
       printf("\nNajpopularnija boja je bijela (%.2f%%).", pb);
   }
   else if (EPSILON > fabs(ps-postotak)){
       printf("\nNajpopularnija boja je siva (%.2f%%).", ps);
   }
   else if (EPSILON > fabs(pv-postotak)){
       printf("\nNajpopularnija boja je crvena (%.2f%%).", pv);
   }
   else if (EPSILON > fabs(pp-postotak)){
       printf("\nNajpopularnija boja je plava (%.2f%%).", pp);
   }
  
	return 0;
}
