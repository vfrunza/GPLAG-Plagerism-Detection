#include <stdio.h>
#include <math.h>
#define e 0.001

int main() {
//  printf("Zadaća 1, Zadatak 3");
    double x1, x2, r1, r2, a, b, c, D, o, w=0, pom;
    int poz1, poz2, znak;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    D=b*b-4*a*c;
    if(D<0){ printf("Rjesenja su imaginarni brojevi."); return 0;}
    x1=(-b-sqrt(D))/(2*a);
    x2=(-b+sqrt(D))/(2*a);
    if(x1>x2){ pom=x1; x1=x2; x2=pom;}
    
//    printf("\n X1=%.5f   X2=%.5f\n", x1, x2);

    
    do{
    	if(w==0){ printf("Unesite rjesenje x1: "); w=1;}
    	else printf("\nUnesite rjesenje x1: ");
        scanf("%lf", &r1);
        o=r1-x1;
        if(o>=e) znak=1; 
        else if(o<e) znak=0;
        
//        printf("\n O=%.5f\n", o);
        if(r1>=e) poz1=1;
        else if(r1<e) poz1=0;
        if(x1>=e) poz2=1;
        else if(x1<e) poz2=0;
//        printf("\nPOZ 1 %d POZ 2 %d\n", poz1, poz2);
        
        if(poz1==1 && poz2==0){
            if(o<0.1) printf("Priblizno vece");
            else printf("Vece");}
        else if(poz1==0 && poz2==1) printf("Manje");
        else if(fabs(r1-x1)<e && poz1==poz2) printf("Tacno");
        else if(poz1==0 && poz2==0){
        if(znak==1 && fabs(r1-x1)<0.1) printf("Priblizno vece");
        else if(znak==0 && fabs(r1-x1)<0.1) printf("Priblizno manje");
        else if(znak==1 && fabs(r1-x1)>=0.1) printf("Vece");
        else if(znak==0 && fabs(r1-x1)>=0.1) printf("Manje");
     //   else if(o<0) printf("Manje");
     //   else if(o>0) printf("Vece");
        }
        else if(poz1==1 && poz2==1){
        if(znak==1 && fabs(r1-x1)<0.1) printf("Priblizno vece");
        else if(znak==0 && fabs(r1-x1)<0.1) printf("Priblizno manje");
        else if(znak==1 && fabs(r1-x1)>=0.1) printf("Vece");
        else if(znak==0 && fabs(r1-x1)>=0.1) printf("Manje");
        }
        } while(fabs(r1-x1)>=e);
    
    do{
    	printf("\nUnesite rjesenje x2: ");
        scanf("%lf", &r2);
        o=r2-x2;
        if(o>=0) znak=1; 
        else if(o<0) znak=0;
        if(r2>=0) poz1=1;
        else if(r2<0) poz1=0;
        if(x2>=0) poz2=1;
        else if(x2<0) poz2=0;
        
        if(poz1==1 && poz2==0){
            if(o<0.1) printf("Priblizno vece");
            else printf("Vece");}
        
        else if(poz1==0 && poz2==1) printf("Manje");
        else if(fabs(r2-x2)<e && poz1==poz2) printf("Tacno");
        else if(poz1==0 && poz2==0){
        if(znak==1 && fabs(r2-x2)<0.1) printf("Priblizno vece");
        else if(znak==0 && fabs(r2-x2)<0.1) printf("Priblizno manje");
        else if(znak==1 && fabs(r2-x2)>=0.1) printf("Vece");
        else if(znak==0 && fabs(r2-x2)>=0.1) printf("Manje");}
        
        else if(poz1==1 && poz2==1){
        if(znak==1 && fabs(r2-x2)<0.1) printf("Priblizno vece");
        else if(znak==0 && fabs(r2-x2)<0.1) printf("Priblizno manje");
        else if(znak==1 && fabs(r2-x2)>=0.1) printf("Vece");
        else if(znak==0 && fabs(r2-x2)>=0.1) printf("Manje");}
        } while(fabs(r2-x2)>=e);
    
    
	return 0; 
}
