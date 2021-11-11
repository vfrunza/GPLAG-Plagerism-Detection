#include <stdio.h>
#include <math.h>
#define PR 6.80
#define HR 3.30
#define CR 5.00
#define PF 8.00
#define HF 3.00
#define CF 3.90
#define PB 5.30
#define HB 5.00
#define CB 6.00
#define EPSILON 0.001

int main(){
    char tarik, bojan, mirza, novi_red;
    int t, b, m, s;
    float  c_bistro, c_fast, c_rest, min, c_popust;
    
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);
    
    
    
    if(tarik=='P') t=0;
    else if(tarik=='H') t=3;
    else if(tarik=='C') t=4;
    
    if(bojan=='P') b=0;
    else if(bojan=='H') b=3;
    else if(bojan=='C') b=4;
    
    if(mirza=='P') m=0;
    else if(mirza=='H') m=3;
    else if(mirza=='C') m=4;
    
    
    
    s=t+b+m;
    
    switch(s){
        case 0:
            c_rest=3*PR;
            c_fast=3*PF;
            c_bistro=3*PB;
            c_popust=3*PR-3*((PR*10)/100);
            break;
        
        case 3:
            c_rest=2*PR+HR;
            c_fast=2*PF+HF;
            c_bistro=2*PB+HB;
            c_popust=HR+2*PR-2*((PR*10)/100);
            break;
        
        case 4:
            c_rest=2*PR+CR;
            c_fast=2*PF+CF;
            c_bistro=2*PB+CB;
            c_popust=CR+2*PR-2*((PR*10)/100);
            break;
        
        case 7:
            c_rest=PR+CR+HR;
            c_fast=PF+CF+HF;
            c_bistro=PB+CB+HB;
            c_popust=CR+HR+PR-((PR*10)/100);
            break;
        
        case 6:
            c_rest=PR+2*HR;
            c_fast=PF+2*HF;
            c_bistro=PB+2*HB;
            c_popust=2*HR+PR-((PR*10)/100);
            break;
        
        case 8:
            c_rest=PR+2*CR;
            c_fast=PF+2*CF;
            c_bistro=PB+2*CB;
            c_popust=2*CR+PR-((PR*10)/100);
            break;
        
        case 9:
            c_rest=3*HR;
            c_fast=3*HF;
            c_bistro=3*HB;
            c_popust=3*HR-3*((HR*10)/100);
            break;
            
        case 10:
            c_rest=CR+2*HR;
            c_fast=CF+2*HF;
            c_bistro=CB+2*HB;
            c_popust=2*HR+CR-((CR*10)/100);
            break;
        
        case 11:
            c_rest=2*CR+HR;
            c_fast=2*CF+HF;
            c_bistro=2*CB+HB;
            c_popust=2*CR+HR-2*((CR*10)/100);
            break;
        
        case 12:
            c_rest=3*CR;
            c_fast=3*CF;
            c_bistro=3*CB;
            c_popust=3*CR-3*((CR*10)/100);
            break;

    }
    
    
    
    if(c_rest-c_bistro>EPSILON && c_fast-c_bistro>EPSILON)
    {
        printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", c_bistro);
        min=c_bistro;
    }
    else if(c_rest-c_fast>EPSILON && c_bistro-c_fast>EPSILON)
    {
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", c_fast);
        min=c_fast;
    }
    else if(c_bistro-c_rest>EPSILON && c_fast-c_rest>EPSILON) 
    {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", c_rest);
        min=c_rest;
    } 
    
    if(min-c_popust>EPSILON && fabs(min-c_rest)>EPSILON)
    {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", c_popust);
    } 
    
    

    return 0;
}







