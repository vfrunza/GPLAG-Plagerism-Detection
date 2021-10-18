#include <stdio.h>

int main() {
    
	char tarik,bojan,mirza,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf ("%c",&tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&mirza);
    scanf("%c", &novi_red);
    

    double trovac=0 ;
    double kkk=0;
    double lor =0;
    
    double trovacpizaa=8;
    double trovachamb=3;
    double trovaccevapi=3.9;
    
    double kkkpizza=6.8;
    double kkkhamb=3.3;
    double kkkcevapi=5;
    
    double lorpizza=5.3;
    double lorhamb=5;
    double lorcevapi=6;
    
    double pizza=0;
    double hamburger=0;
    double cevapi=0;
    double racun = 0;
    
    if(tarik=='P') {
    	trovac+=trovacpizaa;
    	kkk+=kkkpizza;
    	pizza+=kkkpizza;
    	lor+=lorpizza;
    }
    
    
    if(tarik=='H'){
    	trovac+=trovachamb;
    	kkk+=kkkhamb;
    	hamburger+=kkkhamb;
    	lor+=lorhamb;
    }
    
    
    
    if(tarik=='C'){
    	trovac+=trovaccevapi;
    	kkk+=kkkcevapi;
    	cevapi+=kkkcevapi;
    	lor+=lorcevapi;
    }
    
    
    
    if(bojan=='P'){
    	trovac+=trovacpizaa;
    	kkk+=kkkpizza;
    	pizza+=kkkpizza;
    	lor+=lorpizza;
    	
    }
    
    if(bojan=='H'){
    	trovac+=trovachamb;
    	kkk+=kkkhamb;
    	hamburger+=kkkhamb;
    	lor+=lorhamb;
    }
    	
    if(bojan=='C'){
    	trovac+=trovaccevapi;
        kkk+=kkkcevapi;
    	cevapi+=kkkcevapi;
    	lor+=lorcevapi;
    }	
  
    	
    if(mirza=='P'){
    	trovac+=trovacpizaa;
        kkk+=kkkpizza;
    	pizza+=kkkpizza;
    	lor+=lorpizza;
    	
    }	
    	
    	if(mirza=='H'){
    	trovac+=trovachamb;
        kkk+=kkkhamb;
    	hamburger+=kkkhamb;
    	lor+=lorhamb;
    	}
    	
    	if (mirza=='C'){
        trovac+=trovaccevapi;
        kkk+=kkkcevapi;
    	cevapi+=kkkcevapi;
    	lor+=lorcevapi;
    	}
    	
    	
    	
    	if(trovac<=kkk && trovac<=lor){
    		racun=trovac;
    		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", racun);
    		
    	}
    	
    	if(kkk<=trovac && kkk<=lor){
    		racun=kkk;
    		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", racun);
    	}
    	
    	if(lor<=trovac && lor<=kkk){
    	    racun=lor;
    	    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", racun);
    	    
    }
    
    if(!(kkk<=trovac && kkk<=lor)){
        if(pizza>=hamburger && pizza>=cevapi)
        kkk=kkk-pizza/10;
        
        else if (hamburger>=pizza && hamburger>=cevapi)
        kkk=kkk-hamburger/10;
        else kkk=kkk-cevapi/10;
    }
    
    
    
    if(kkk<racun) 
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",kkk);
    
	return 0;
}
