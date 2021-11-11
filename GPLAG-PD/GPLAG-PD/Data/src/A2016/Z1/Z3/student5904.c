#include <stdio.h>

int main() {
    
	float postotak;
	char slovo;
	int  cbrojac, bbrojac, sbrojac, vbrojac, pbrojac, ukupno, max;
	
	cbrojac=0;
	bbrojac=0;
	sbrojac=0;
	vbrojac=0;
	pbrojac=0;
	
	    printf("Unesite vozila: ");
	    
	do{ 
	    scanf("%c", &slovo);
	    
	   /* printf("%c %d ", slovo, slovo); */
	        
	        switch (slovo){
    	
        	    case 'c':
        	    case 'C':
    	    
    	            cbrojac++;
    	            break;
	            
	            case 'b': 
	            case 'B':
	              
	                bbrojac++;
	                break;
	                
	            case 's':
	            case 'S':
	            
	                sbrojac++;
	                break;
	                
	            case 'v':
	            case 'V':
	            
	               vbrojac++;
	               break;
	               
	            case 'p':
	            case 'P':
	            
	              pbrojac++;
	              break;
	            
	            case 'k':
	            case 'K': 
	            
	               break;
	            
	            default:
	               printf("Neispravan unos\n");
	               break;
	               
	        }        
	   
    } while (slovo!='k' && slovo!='K'); 
    
    
	ukupno=cbrojac+bbrojac+sbrojac+vbrojac+pbrojac;

	printf("Ukupno evidentirano %d vozila.", ukupno);
	
	max=cbrojac;
	
	if (bbrojac>max) {
	    max=bbrojac;
	}
	
	if (sbrojac>max) {
	    max=sbrojac;
	}
	
	if (vbrojac>max) {
	    max=vbrojac;
	}
	
	if (pbrojac>max ) {
	    max=pbrojac;
	}
	
	postotak=max/(float)ukupno*100;
	
	if ((cbrojac==0) && (bbrojac==0) && (sbrojac==00) && (vbrojac==0) && (pbrojac==0)) {
		printf("\nNajpopularnija boja je crna (0.00%%).");
		return 0;
	}
	
	if (max==cbrojac) {
	    printf("\nNajpopularnija boja je crna (%.2f%%).", postotak);
	}
	
	if ((max==bbrojac) && (bbrojac>cbrojac)) {
	    printf("\nNajpopularnija boja je bijela (%.2f%%).", postotak);
	}
	
	if ((max==sbrojac) && (sbrojac>bbrojac) && (sbrojac>cbrojac)) {
	    printf("\nNajpopularnija boja je siva (%.2f%%).", postotak);
	}
	
	if ((max==vbrojac) && (vbrojac>sbrojac) && (vbrojac>bbrojac) && (vbrojac>cbrojac)) {
	    printf("\nNajpopularnija boja je crvena (%.2f%%).", postotak);
	}
	
	if ((max==pbrojac) && (pbrojac>vbrojac) && (pbrojac>sbrojac) && (pbrojac>bbrojac) && (pbrojac>cbrojac)) {
	    printf("\nNajpopularnija boja je plava (%.2f%%).", postotak);
	}
	
	
	
	
	return 0;
}
