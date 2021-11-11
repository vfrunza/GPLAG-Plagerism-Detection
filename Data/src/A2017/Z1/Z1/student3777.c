#include <stdio.h>
#define PKK 6.80 
#define HKK 3.30 
#define CKK 5.00 
#define TP 8.00 
#define TH 3.00 
#define TC 3.90 
#define LP 5.30 
#define LH 5.00 
#define LC 6.00 


int main() {
	char Tarik, Bojan, Mirza, novi_red, P, H, C,n,CH,cr;
	n='"';
	cr='-';
	
	
	double x1=0,x2=0,x3=0,x4=0;
	
	printf("Unesite jelo za Tarika:");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf(" Unesite jelo za Bojana:");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf(" Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	
	if(Tarik=='P' && Mirza=='P' && Bojan=='P'){
		x1=3.*PKK;
		x2=3.*TP;
		x3=3.*LP;
		
		if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast%cfood %cTrovac%c (%.2f KM). ",cr,n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=x1*0.9;
	    
     	if (x1>=x2 && x1>=x3){
		    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
	
    if(Tarik=='C' && Bojan=='C' && Mirza=='C'){
    	x1=3.*CKK;
		x2=3.*TC;
		x3=3.*LC;
		
		if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast%cfood %cTrovac%c (%.2f KM). ",cr,n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=x1*0.9;
	    
     	if (x1>=x2 && x1>=x3){
		    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
    
     if(Tarik=='H' && Bojan=='H' && Mirza=='H'){
    	x1=3.*HKK;
		x2=3.*TH;
		x3=3.*LH;
		
		if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast%cfood %cTrovac%c (%.2f KM). ",cr,n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=x1*0.9;
	    
     	if (x4<x2 && x4<x3){
		    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
    		
    if((Tarik=='H' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='H')){
    	x1=2.*HKK+PKK;
    	x2=2.*TH+TP;
    	x3=2.*LH+LP;
    	
    	if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM). ",n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=0.9*PKK+HKK;
	    
     	if (x1>=x2 && x1>=x3){
		    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
	
	if((Tarik=='H' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='H')){
		x1=2.*HKK+CKK;
		x2=2.*TH+TC;
		x3=2.*LH+CH;
	  
	  if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast%cfood %cTrovac%c (%.2f KM).",cr,n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=2.*HKK*0.9+CKK;
	    
     	if (x4<x2 && x4<x3){
		    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
    	
    if((Tarik=='C' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='C')){
    	x1=2.*CKK+PKK;
    	x2=2.*TC+TP;
    	x3=2.*LC+LP;
    	
    	if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM). ",n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=2.*CKK*0.9+PKK;
	    
     	if (x1>=x2 && x1>=x3){
		    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
    if((Tarik=='C' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='C')){
    	x1=2.*CKK+HKK;
    	x2=2.*TC+TH;
    	x3=2.*LC+LH;
    	
    	if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM). ",n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=2.*CKK*0.9+HKK;
	    
     	if (x1>=x2 && x1>=x3){
		    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
	
	if ((Tarik=='P' && Bojan=='P' && Mirza=='H') || (Tarik=='P' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='P')){
		x1=2.*PKK+HKK;
		x2=2.*TP+TH;
		x3=2.*LP+LH;
	
	    if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM). ",n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=2.*PKK*0.9+HKK;
	    
     	if (x4<x2 && x4<x3){
		    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
   
    if((Tarik=='P' && Bojan=='P' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='P')){
    	x1=2.*PKK+CKK;
    	x2=2.*TP+TC;
    	x3=2.*LP+LC;
    
       if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM). ",n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=2.*PKK*0.9+CKK;
	    
     	if (x1>=x2 && x1>=x3){
		    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}
	
	if((Tarik=='P' && Bojan=='H' && Mirza=='C') || (Tarik=='P' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='P' && Mirza=='H') || (Tarik=='C' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='P' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='P')){
		x1=PKK+HKK+CKK;
		x2=TP+TH+TC;
		x3=LP+LH+LC;
	
	if(x1<x2 && x1<x3) {
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,x1);
		} else if (x2<x1 && x2<x3) {
			printf("Najjeftiniji je Fast%cfood %cTrovac%c (%.2f KM). ",cr,n,n, x2);
		} else if (x3<x1 && x3<x2){
		    printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM). ",n,n, x3);
	}
	    x4=PKK*0.9+HKK+CKK;
	    
     	if (x4<x2 && x4<x3){
		    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", x4);
	} return 1;
	}    

	return 0;
}


















