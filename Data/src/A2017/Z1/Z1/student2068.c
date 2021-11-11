#include <stdio.h>

int main() {
	char tarik,bojan,mirza,novi_red;
	
	int brojacP=0;
	int brojacH=0;
	int brojacC=0;
	float restoran,trovac,bistro,najjfetiniji,p,popust,y;

	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if(tarik=='P')brojacP++;
	 else if(tarik=='H')brojacH++;
	 else if(tarik=='C')brojacC++;
	
	if(bojan=='P')brojacP++;
	 else if(bojan=='H')brojacH++;
	 else if(bojan=='C')brojacC++;
	 
	if(mirza=='P')brojacP++;
	 else if(mirza=='H')brojacH++;
	 else if(mirza=='C')brojacC++;
    
    
    restoran=(brojacP)*6.80+(brojacH)*3.30+(brojacC)*5.00;
    trovac=(brojacP)*8.00+(brojacH)*3.00+(brojacC)*3.90;
    bistro=(brojacP)*5.30+(brojacH)*5.00+(brojacC)*6.00;
    
    
    
    if(brojacH==2 && brojacP==1) {
    	najjfetiniji=restoran;
    	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",najjfetiniji);
    }
    if(brojacP==2 || brojacP==3) {
    	najjfetiniji=bistro;
    	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",najjfetiniji);
    }
    if(((brojacH==2)&&(brojacC==1)) || brojacH==3 || brojacC==2 || brojacC==3) {
    	najjfetiniji=trovac;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",najjfetiniji);
    }
    	
    if(brojacP==1 && brojacH==1 && brojacC==1) {
    	najjfetiniji=trovac;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",najjfetiniji);
    }
    if(restoran!=najjfetiniji){
    	  
          if(brojacP==1 && brojacC==1 && brojacH==1){
          	p=(6.80*0.1);
          	y=6.80-p;
          	popust=y+5.00+3.30;
           printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popust);
          }
    }
    
    if(restoran!=najjfetiniji){
    	if(brojacH==3){
    		p=(brojacH*3.30)*0.1;
    		popust=(3*3.30)-p;
    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popust);
    	}
    }
    if(restoran!=najjfetiniji){
    	if(brojacH==1 && brojacP==2){
    		p=brojacP*6.80*0.1;
    		y=(6.80*brojacP)-p;
    		popust=y+3.30;
    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popust);
    	}
    }
        
        
	return 0;
}

	
	