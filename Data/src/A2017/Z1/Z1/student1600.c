#include <stdio.h>
#define P_R 6.8
#define P_F 8.0
#define P_B 5.3
#define H_R 3.3
#define H_F 3.0
#define H_B 5.0
#define C_R 5.0
#define C_F 3.9
#define C_B 6.0
#define P_ 6.12
#define H_ 2.97
#define C_ 4.5


int main() {
	char T, B, M, novi_red;
	float s_1,s_2,s_3,s_4,s_5,s_6,s_7,s_8,s_9,s_10,s_11,s_12,s_13,s_14,s_15,s_16,s_17,s_18,s_19,s_20,s_21,s_22,s_23,s_24,s_25,s_26,s_27,s_28,s_29,s_30,s_31,s_32,s_33,s_34,s_35,s_36,s_37,s_38,s_39,s_40,s_41,s_42,s_43,s_44,s_45,s_46,s_47,s_48,s_49,s_50;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c",&novi_red);

	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c",&novi_red);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c",&novi_red);
	
    if(T=='P' && B=='P' && M=='P'){
        
        
    if( (3*(P_R) < 3*(P_F)) && (3*(P_R) < 3*(P_B))) {
    s_1=3*(P_R);
    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_1);}
    
    else if ( (3*(P_B) < 3*(P_R)) && (3*(P_B) < 3*(P_F))){
    s_2=3*(P_B);
    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_2);
    if (3*(P_)<3*(P_B)){
    s_3=3*(P_);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_3);} }
    
    else if ( (3*(P_F) < 3*(P_R)) && (3*(P_F) < 3*(P_B))){
    s_4=3*(P_F);
    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_4);
    if (3*(P_)<3*(P_F)){
    s_5=3*(P_);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_5);} }
    
    }
    
    if(T=='C' && B=='C' && M=='C') {
    
    if( (3*(C_R) < 3*(C_F)) && (3*(C_R) < 3*(C_B))) {
    s_6=3*(C_R);
    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_6);}
    
    else if ( (3*(C_B) < 3*(C_R)) && (3*(C_B) < 3*(C_F))){
    s_7=3*(C_B);
    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_7);
    if (3*(C_)<3*(C_B)){
    s_8=3*(C_);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_8);} }
    
    else if ( (3*(C_F) < 3*(C_R)) && (3*(C_F) < 3*(C_B))){
    s_9=3*(C_F);
    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_9);
    if (3*(C_)<3*(C_F)){
    s_10=3*(C_);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_10);} }
    
    }
    
    if(T=='H' && B=='H' && M=='H') {
        
    if( (3*(H_R) < 3*(H_F)) && (3*(H_R) < 3*(H_B))) {
    s_11=3*(H_R);
    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_11);}
    
    else if ( (3*(H_B) < 3*(H_R)) && (3*(H_B) < 3*(H_F))){
    s_12=3*(H_B);
    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_12);
    if (3*(H_)<3*(H_B)){
    s_13=3*(H_);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_13);} }
    
    else if ( (3*(H_F) < 3*(H_R)) && (3*(H_F) < 3*(H_B))){
    s_14=3*(H_F);
    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_14);
    if (3*(H_)<3*(H_F)){
    s_15=3*(H_);
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_15);} }
    
    }
    
    if((T=='P' && B=='H' && M=='H') || (T=='H' && B=='P' && M=='H') || (T=='H' && B=='H' && M=='P')){
        
        if(((2*(H_R)+P_R) < (2*(H_F)+P_F)) && ((2*(H_R)+P_R) < (2*(H_B)+P_B))) {
            s_16=(2*(H_R)+P_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_16); }
            
        else if (((2*(H_B)+P_B) < (2*(H_F)+P_F)) && ((2*(H_B)+P_B) < (2*(H_R)+P_R))) {
        s_17=(2*(H_B)+P_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_17);
        if((2*(H_)+P_R) < (2*(H_B)+P_B)) {
        s_18=(2*(H_)+P_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_18);} }
        
        else if (((2*(H_F)+P_F) < (2*(H_B)+P_B)) && ((2*(H_F)+P_F) < (2*(H_R)+P_R))) {
        s_19=(2*(H_F)+P_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_19);
        if((2*(H_)+P_R) < (2*(H_F)+P_F)) {
        s_20=(2*(H_)+P_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_20);} }
        
            }
            
        if((T=='P' && B=='P' && M=='H') || (T=='P' && B=='H' && M=='P') || (T=='H' && B=='P' && M=='P')){
        
        if(((2*(P_R)+H_R) < (2*(P_F)+H_F)) && ((2*(P_R)+H_R) < (2*(P_B)+H_B))) {
            s_21=(2*(P_R)+H_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_21); }
            
        else if (((2*(P_B)+H_B) < (2*(P_F)+H_F)) && ((2*(P_B)+H_B) < (2*(P_R)+H_R))) {
        s_22=(2*(P_B)+H_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_22);
        if((2*(P_)+H_R) < (2*(P_B)+H_B)) {
        s_23=((2*(P_))+H_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_23);} }
        
        else if (((2*(P_F)+H_F) < (2*(P_B)+H_B)) && ((2*(P_F)+H_F) < (2*(P_R)+H_R))) {
        s_24=(2*(P_F)+H_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_24);
        if((2*(P_)+H_R) < (2*(P_F)+H_F)) {
        s_25=((2*(P_))+H_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_25);} }
        
            }
            
        if((T=='P' && B=='C' && M=='C') || (T=='C' && B=='P' && M=='C') || (T=='C' && B=='C' && M=='P')){
        
        if(((2*(C_R)+P_R) < (2*(C_F)+P_F)) && ((2*(C_R)+P_R) < (2*(C_B)+P_B))) {
            s_26=(2*(C_R)+P_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_26); }
            
        else if (((2*(C_B)+P_B) < (2*(C_F)+P_F)) && ((2*(C_B)+P_B) < (2*(C_R)+P_R))) {
        s_27=(2*(C_B)+P_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_27);
        if((2*(C_)+P_R) < (2*(C_B)+P_B)) {
        s_28=(2*(C_)+P_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_28);} }
        
        else if (((2*(C_F)+P_F) < (2*(C_B)+P_B)) && ((2*(C_F)+P_F) < (2*(C_R)+P_R))) {
        s_29=(2*(C_F)+P_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_29);
        if((2*(C_)+P_R) < (2*(C_F)+P_F)) {
        s_30=(2*(C_)+P_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_30);} }
        
            }
        
         if((T=='P' && B=='P' && M=='C') || (T=='P' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='P')){
        
        if(((2*(P_R)+C_R) < (2*(P_F)+C_F)) && ((2*(P_R)+C_R) < (2*(P_B)+C_B))) {
            s_31=(2*(P_R)+C_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_31); }
            
        else if (((2*(P_B)+C_B) < (2*(P_F)+C_F)) && ((2*(P_B)+C_B) < (2*(P_R)+C_R))) {
        s_32=(2*(P_B)+C_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_32);
        if((2*(P_)+C_R) < (2*(P_B)+C_B)) {
        s_33=((2*(P_))+C_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_33);} }
        
        else if (((2*(P_F)+C_F) < (2*(P_B)+C_B)) && ((2*(P_F)+C_F) < (2*(P_R)+C_R))) {
        s_34=(2*(P_F)+C_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_34);
        if((2*(P_)+C_R) < (2*(P_F)+C_F)) {
        s_35=((2*(P_))+C_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_35);} }
        
         }
         
        if((T=='H' && B=='C' && M=='C') || (T=='C' && B=='H' && M=='C') || (T=='C' && B=='C' && M=='H')){
        
        if(((2*(C_R)+H_R) < (2*(C_F)+H_F)) && ((2*(C_R)+H_R) < (2*(C_B)+H_B))) {
            s_36=(2*(C_R)+H_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_36); }
            
        else if (((2*(C_B)+H_B) < (2*(C_F)+H_F)) && ((2*(C_B)+H_B) < (2*(C_R)+H_R))) {
        s_37=(2*(C_B)+H_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_37);
        if((2*(C_)+H_R) < (2*(C_B)+H_B)) {
        s_38=(2*(C_)+H_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_38);} }
        
        else if (((2*(C_F)+H_F) < (2*(C_B)+H_B)) && ((2*(C_F)+H_F) < (2*(C_R)+H_R))) {
        s_39=(2*(C_F)+H_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_39);
        if((2*(C_)+H_R) < (2*(C_F)+H_F)) {
        s_40=(2*(C_)+H_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_40);} }
        
            } 
            
        if((T=='C' && B=='H' && M=='H') || (T=='H' && B=='C' && M=='H') || (T=='H' && B=='H' && M=='C')){
        
        if(((2*(H_R)+C_R) < (2*(H_F)+C_F)) && ((2*(H_R)+C_R) < (2*(H_B)+C_B))) {
            s_41=(2*(H_R)+C_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_41); }
            
        else if (((2*(H_B)+C_B) < (2*(H_F)+C_F)) && ((2*(H_B)+C_B) < (2*(H_R)+C_R))) {
        s_42=(2*(H_B)+C_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_42);
        if((2*(H_)+C_R) < (2*(H_B)+C_B)) {
        s_43=(2*(H_)+C_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_43);} }
        
        else if (((2*(H_F)+C_F) < (2*(H_B)+C_B)) && ((2*(H_F)+C_F) < (2*(H_R)+C_R))) {
        s_44=(2*(H_F)+C_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_44);
        if((2*(H_)+C_R) < (2*(H_F)+C_F)) {
        s_45=(2*(H_)+C_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_45);} }
        
            }  
            
        if((T=='P' && B=='H' && M=='C') || (T=='P' && B=='C' && M=='H') || (T=='H' && B=='P' && M=='C') || (T=='H' && B=='C' && M=='P') || (T=='C' && B=='P' && M=='H') || (T=='C' && B=='H' && M=='P')){
        
        if(((P_R+H_R+C_R) < (P_F+H_F+C_F)) && ((P_R+H_R+C_R) < (P_B+H_B+C_B))) {
            s_46=(P_R+H_R+C_R);
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",s_46); }
            
        else if (((P_B+H_B+C_B) < (P_R+H_R+C_R)) && ((P_B+H_B+C_B) < (P_F+H_F+C_F))) {
        s_47=(P_B+H_B+C_B);
        printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",s_47);
        if((P_+H_R+C_R) < (P_B+H_B+C_B)) {
        s_48=(P_+H_R+C_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_48);} }
        
        else if (((P_F+H_F+C_F) < (P_R+H_R+C_R)) && ((P_F+H_F+C_F) < (P_B+H_B+C_B))) {
        s_49=(P_F+H_F+C_F);
        printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",s_49);
        if((P_+H_R+C_R) < (P_F+H_F+C_F)) {
        s_50=(P_+H_R+C_R);
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",s_50);} }
        
            } 
        
	return 0;
}


