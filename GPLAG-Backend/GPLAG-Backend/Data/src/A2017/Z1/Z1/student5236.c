#include <stdio.h>
#define p_r 6.80
#define p_f 8.00
#define p_b 5.30
#define h_r 3.30
#define h_f 3.00
#define h_b 5.00
#define c_r 5.00
#define c_f 3.90
#define c_b 6.00

int main() {
    char tarik,bojan,mirza,novi_red;
    double suma_r=0,suma_f=0,suma_b=0;
    int br_p=0,br_h=0,br_c=0;
    char znak;
    znak='"';
   printf("Unesite jelo za Tarika: ");
   scanf("%c",&tarik);
   scanf("%c",&novi_red);
   printf("Unesite jelo za Bojana: ");
   scanf("%c",&bojan);
   scanf("%c",&novi_red);
   printf("Unesite jelo za Mirzu: ");
   scanf("%c",&mirza);
   scanf("%c",&novi_red);
   if(tarik=='P'){
   	suma_r+=p_r;suma_f+=p_f;suma_b+=p_b;
   	br_p+=1;
   }else if(tarik == 'H'){
   	suma_r+=h_r;suma_f+=h_f;suma_b+=h_b;
   	br_h+=1;
   }else if(tarik == 'C'){
   	suma_r+=c_r;suma_f+=c_f;suma_b+=c_b;
   	br_c+=1;
   }
   if(bojan == 'P'){
   	suma_r+=p_r;suma_f+=p_f;suma_b+=p_b;
   	br_p+=1;
   }else if(bojan == 'H'){
   	suma_r+=h_r;suma_f+=h_f;suma_b+=h_b;
   	br_h+=1;
   }else if(bojan == 'C'){
   	suma_r+=c_r;suma_f+=c_f;suma_b+=c_b;
   	br_c+=1;
   }
   if(mirza == 'P'){
   	suma_r+=p_r;suma_f+=p_f;suma_b+=p_b;
   	br_p+=1;
   }else if(mirza == 'H'){
   	suma_r+=h_r;suma_f+=h_f;suma_b+=h_b;
   	br_h+=1;
   }else if(mirza == 'C'){
   	suma_r+=c_r;suma_f+=c_f;suma_b+=c_b;
   	br_c+=1;
   }
   if(suma_r < suma_f && suma_r < suma_b){
   	printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",znak,znak,suma_r);
   }else if(suma_f < suma_r && suma_f < suma_b){
   	printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",znak,znak,suma_f);
   	if(br_p > br_h && br_p > br_c){
   		suma_r=suma_r-br_p*(p_r/10);
   		if(suma_r < suma_f){
   			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   		}
   	}else if(br_h > br_p && br_h > br_c){
   		suma_r=suma_r - br_h*(h_r/10);
   		if(suma_r < suma_f){
   			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   		}
   	}else if(br_c > br_p && br_c > br_h){
   		suma_r=suma_r - br_c*(c_r/10);
   		if(suma_r < suma_f){
   			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   		}
   	}else if(br_c == br_h && br_h == br_p){
   		suma_r=suma_r - (p_r/10);
   		if(suma_r < suma_f){
   			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   		}
   	}
   	}else if( suma_b < suma_f && suma_b < suma_r){
   		printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",znak,znak,suma_b);
   		if(br_p > br_h && br_p> br_c){
   			suma_r=suma_r - br_p*(p_r/10);
   			if(suma_r < suma_b){
   				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   			}
   		}else if(br_h > br_p && br_h > br_c){
   			suma_r=suma_r - h_r*(h_r/10);
   			if(suma_r < suma_b){
   				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   			}
   		}else if(br_c > br_h && br_c > br_p){
   			suma_r=suma_r - br_c*(c_r/10);
   			if(suma_r < suma_b){
   				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   			}
   		}else if(br_c == br_h && br_h == br_p){
   			suma_r=suma_r - (p_r/10);
   			if(suma_r < suma_b){
   				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_r);
   			}
   		}
   	}
	return 0;
}
