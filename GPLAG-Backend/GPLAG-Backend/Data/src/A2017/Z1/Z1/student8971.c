#include <stdio.h>

/*Kod Konja i Konjušara*/
#define P1 6.80 
#define H1 3.30
#define C1 5.00 
/*fast-food TROVAC*/
#define P2 8.00 
#define H2 3.00 
#define C2 3.90 
/*BISTRO Lorelei*/
#define P3 5.30 
#define H3 5.00 
#define C3 6.00 

int main()
{
	char tarik, mirza, bojan, novi_red;
	float P1,P2,P3,H1,H2,H3,C1,C2,C3,R1,R2,R3,R4;

	/*Unos jela za svakog ponaosob*/
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	
	if(tarik=='P' && mirza=='P' && bojan=='P') {
		R1 = P1 + P1 + P1;
		R2 = P2 + P2 + P2;
		R3 = P3 + P3 + P3;
		R4 = R1 - R1/100;
	} else if(tarik=='H' && mirza=='H' && bojan=='H') {
		R1 = H1 + H1 + H1;
		R2 = H2 + H2 + H2;
		R3 = H3 + H3 + H3;
		R4 = R1 - R1/100;
	} else if (tarik =='C' && mirza=='C' && bojan=='C') {
		R1 = C1 + C1 + C1;
		R2 = C2 + C2 + C2;
		R3 = C3 + C3 + C3;
		R4 = R1 - R1/100;
	}
	if(R1<R2 && R1<R3) {
		printf("Najjeftiniji je restoran Kod Konja i Konjušara. %f", R1);
		printf("\n");
	} else if (R2<R1 && R2<R3){
		printf("Najjeftiniji je fast-food TROVAC %f", R2);
		printf("\n");
	} else if (R3<R1 && R3<R2) {
	printf("Najjestiniji je BISTRO Lorelei %f", R3);
    }
    
    
    if((tarik=='P' && mirza=='P' && bojan=='H') || (tarik=='H' && mirza=='P' && bojan=='P') || (tarik=='P' && mirza=='H' && bojan=='P')) {
    	R1=P1+P1+H1;
    	R2=P2+P2+H2;
    	R3=P3+P3+H3;
    	R4=R1 - R1/100;
    } if (R1<R2 && R1<R3){
    	printf("Najjeftiniji je restoran kod Konja i Konjusara %f", R1);
    	printf("\n");
         } else if (R2<R1 && R2<R3){
        	printf("Najjeftiniji je fast food TROVAC %f", R2);
        	printf("\n");
             }else if (R3<R1 && R3<R2) {
            	printf("Najjeftiniji je BISTRO Lorelei %f", R3);
            	printf("\n");
             }
        
        if((tarik=='H' && mirza=='H' && bojan=='P') || (tarik=='H' && mirza=='P' && bojan=='H') || (tarik=='P' && mirza=='H' && bojan=='H')){
        	R1=H1+H1+P1;
        	R2=H2+H2+P2;
        	R3=H3+H3+P3;
        	R4=...
        }  if(R1<R2 && R1<R3){
        	printf("Najjeftiniji je restoran kod onja i Konjusara %f", R1);
        	printf("\n");
            } else if (R2<R1 && R2<R3) {
              	printf("najjeftiniji je fast-food TROVAC %f", R2);
             	printf("\n");
               } else if(R3<R1 && R3<R2) {
                	printf("Najjeftiniji je Bistro Lorelei %f", R3);
                	printf("\n");
               }
        
        
        if((tarik=='C' && mirza=='P' && bojan=='P') || (tarik=='P' && mirza=='C' && bojan=='P') || (tarik=='P' && mirza=='P' && bojan=='C')) {
        	R1=P1+P1+C1;
        	R2=P2+P2+C2;
        	R3=P3+P3+C3;
        	R4=..
        } if(R1<R2 && R1<R3){
             printf("Najjeftiniji je resotran kod Konja i Konjusara %f", R1);
             printf("\n");
             } else if(R2<R1 && R2<R3) {
             	printf("Najjeftiniji je fast-food TROVAC %f", R2);
             	printf("\n");
                } else if(R3<R1 && R3<R2) {
                	printf("najjeftiniji je Bisto Lorelei %f", R3);
                	printf("\n");
                }
                
       
       if((tarik=='C' && mirza=='H' && bojan=='H') || (tarik=='H' && mirza=='C' && bojan=='H') || (tarik=='H' && mirza=='H' && bojan=='C')) {
       	R1=C1+H1+H1;
       	R2=C2+H2+H2;
       	R3=C3+H3+H3;
       	R4=..
       } if(R1<R2 && R1<R3) {
       	   printf("Najjeftiniji je restoran kod Konja i Konjusara %f", R1);
       	   printf("\n");
            } else if(R2<R1 && R2<R3) { 
         	 printf("Najjeftiniji je fast-food TROVAC", R2);
         	 printf("\n");
             } else if (R3<R1 && R3<R2) {
             	printf("Najjeftiniji je Bistro Lorelei %f", R3);
             	printf("\n");
             	}
             	
      
      if((tarik=='C' && mirza=='C' && bojan=='H') || (tarik=='C' && mirza=='H' && bojan=='C') || (tarik=='H' && mirza=='C' && bojan=='C')) {
      	R1=C1+C1+H1;
      	R2=C2+C2+H2;
      	R3=C3+C3+H3;
      	R4=..
      } if(R1<R2 && R1<R3) {
      	  printf("Najjeftiniji je restoran Kod Konja i Konjusara %f", R1);
      	  printf("\n");
         } else if (R2<R1 && R2<R3) {
         	 printf("Najjeftiniji je fast-food TROVAC %f", R2);
         	 printf("\n");
             } else if(R3<R1 && R3<R2) {
             	printf("najjeftiniji je BISTRO Lorelei %f", R3);
             	printf("\n");
             	}
             	
     
     if((tarik=='C' && mirza=='C' && bojan=='P') || (tarik=='C' && mirza=='P' && bojan=='C') || (tarik=='P' && mirza=='C' && bojan=='C')) {
     	R1=C1+C1+P1;
     	R2=C2+C2+P2;
     	R3=C3+C3+P3;
     	R4=..
     	} if(R1<R2 && R1<R3) {
     		printf("Najjeftiniji je restoran Kod Konja i Konjusara %f", R1);
     		printf("\n");
     	    } else if(R2<R1 && R2<R3) {
     	    	printf("Najjeftiniji je fast-food TROVAC %f", R2);
     	    	printf("\n");
     	        } else if (R3<R1 && R3<R2) {
     	        	printf("najjeftiniji je BISTRO Lorelei %f", R3);
     	        	printf("\n");
     	            }
     	            
    
     if(tarik=='P' && mirza=='H' && bojan=='C') {
     	R1=P1+H1+C1;
     	R2=P2+H2+C2;
     	R3=P3+H3+C3;
     	R4=...
     } if(R1<R2 && R1<R3){
     	printf("Najjeftiniji je restoran Kod Konja i Konjusara %f", R1);
        printf("\n");
     } else if(R2<R1 && R2<R3){
     	printf("Najjeftiniji je fast-food TROVAC %f", R2);
     	printf("\n");
        } else if (R3<R1 && R3<R2) {
        	printf("Najjeftiniji je BISTRO Lorelei %f", R3);
        	printf("\n");
        }
     	
            
        
return 0;
}
	
	
	
	
	
	
	
	

