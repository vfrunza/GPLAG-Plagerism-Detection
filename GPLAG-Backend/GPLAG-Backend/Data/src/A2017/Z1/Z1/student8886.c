#include <stdio.h>

int main() {
	
	
float restoran1jelo1=6.8;
float restoran1jelo2=3.3;
float restoran1jelo3=5;

float restoran2jelo1=8;
float restoran2jelo2=3;
float restoran2jelo3=3.9;

float restoran3jelo1=5.3;
float restoran3jelo2=5;
float restoran3jelo3=6;

    char unos1, unos2, unos3;
    float suma1=0, suma2=0, suma3=0;
    
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &unos1);
    
    printf("Unesite jelo za Bojana: ");
    scanf(" %c", &unos2);
    
    printf("Unesite jelo za Mirzu: ");
    scanf(" %c", &unos3);
    
    
    switch (unos1) {
        
        case 'P':
        suma1=suma1+restoran1jelo1;
        suma2=suma2+restoran2jelo1;
        suma3=suma3+restoran3jelo1;
        break;
        
        case 'H':
        suma1=suma1+restoran1jelo2;
        suma2=suma2+restoran2jelo2;
        suma3=suma3+restoran3jelo2;
        break;
        
        case 'C':
        suma1=suma1+restoran1jelo3;
        suma2=suma2+restoran2jelo3;
        suma3=suma3+restoran3jelo3;
        break;
        
    }
    
    
        switch (unos2) {
            
            case 'P':
            suma1=suma1+restoran1jelo1;
            suma2=suma2+restoran2jelo1;
            suma3=suma3+restoran3jelo1;
            break;
            
            case 'H':
            suma1=suma1+restoran1jelo2;
            suma2=suma2+restoran2jelo2;
            suma3=suma3+restoran3jelo2;
            break;
            
            case 'C':
            suma1=suma1+restoran1jelo3;
            suma2=suma2+restoran2jelo3;
            suma3=suma3+restoran3jelo3;
            break;
            
        }
        
        
            switch (unos3) {
                
                case 'P':
                suma1=suma1+restoran1jelo1;
                suma2=suma2+restoran2jelo1;
                suma3=suma3+restoran3jelo1;
                break;
                
                case 'H':
                suma1=suma1+restoran1jelo2;
                suma2=suma2+restoran2jelo2;
                suma3=suma3+restoran3jelo2;
                break;
                
                case 'C':
                suma1=suma1+restoran1jelo3;
                suma2=suma2+restoran2jelo3;
                suma3=suma3+restoran3jelo3;
                break;
            
                
            }
            
            
	
	int nastavak=0;
	float najvecasuma=0;
	if (suma1<suma2) {
	    if (suma1<suma3) {
	        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1);        
	    }
	    else {
	        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);        
	        nastavak=1;
	        najvecasuma=suma3;
	    }
	}
	
    else {
        
        if (suma2<suma3)
        {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2);        
            nastavak=1;
            najvecasuma=suma2;
        }
        
        else {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);       
            nastavak=1;
            najvecasuma=suma3;
        }
        
    }
    
    
    if (nastavak==1){                                  
    suma1=0;                                              
    
    switch (unos1) {
        
        case 'P':
        suma1=suma1+restoran1jelo1;               
        
        case 'H':
        suma1=suma1+restoran1jelo2;                   
        break;
        
        case 'C':
        suma1=suma1+restoran1jelo3;                    
        break;
        
    }
    
        switch (unos2) {
            
            case 'P':
            suma1=suma1+restoran1jelo1;
            break;
            
            case 'H':
            suma1=suma1+restoran1jelo2;
            break;
            
            case 'C':
            suma1=suma1+restoran1jelo3;
            break;
            
        }
        
            switch (unos3) {
                
                case 'P':
                suma1=suma1+restoran1jelo1;
                break;
                
                case 'H':
                suma1=suma1+restoran1jelo2;
                break;
                
                case 'C':
                suma1=suma1+restoran1jelo3;                 
                break;
                
            }
        
            suma1=suma1 - (suma1 * 0.1); 
                                                           
        if (suma1<najvecasuma){
            if (suma1<suma2) {
        
                if (suma1<suma3) {
                    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1);
                }
                
                else {
                    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);
                    nastavak=1;
                }
            }
            
            else {
                
                if (suma2<suma3) {
                    printf("Najjeftiniji je Fasto-food \"Trovac\" (%.2f KM).\n", suma2);         
                    nastavak=1;
                }
            
                else {
                    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);
                    nastavak=1;
                }
            }
    
        }    
   
    } 
        



	return 0;
}
