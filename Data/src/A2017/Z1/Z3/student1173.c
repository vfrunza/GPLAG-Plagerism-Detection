#include <stdio.h>
#include <math.h>
 
int main() {
    double a, b, c, D, x1, x2, uneseno_x1, uneseno_x2;
    double epsilon = 0.001;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
   
    D = b*b - (4*a*c);
    if (D < 0){
        printf("Rjesenja su imaginarni brojevi.");
    } else if(D >= 0){
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
       
        do{
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &uneseno_x1);
       
            if(fabs(uneseno_x1 - x1) < epsilon) {
                printf("Tacno\n"); break;
            }
            else if(uneseno_x1 < x1){
                if(fabs(uneseno_x1 - x1) < 0.1) {
                    printf("Priblizno manje\n");
                }else if(uneseno_x1 < x1) {
                    printf("Manje\n");
                }
            }else if(uneseno_x1 > x1){
                    if(fabs(uneseno_x1 - x1) < 0.1) {
                    printf("Priblizno vece\n");
                }   else if(uneseno_x1 > x1) {
                    printf("Vece\n");
                }  
            }
        } while(fabs(uneseno_x1 - x1) > epsilon);
       
       
        do{
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &uneseno_x2);
       
            if(fabs(uneseno_x2 - x2) < epsilon) {
                printf("Tacno\n");
                break;
                }
            else if(uneseno_x2 < x2){
                 if(fabs(uneseno_x2 - x2) < 0.1) {
                    printf("Priblizno manje\n");
                }else if(uneseno_x2 < x2) {
                    printf("Manje\n");
                }
            }  
            else if(uneseno_x2 > x2){
                    if(fabs(uneseno_x2 - x2) < 0.1){
                        printf("Priblizno vece\n");
                    }else if(uneseno_x2 > x2) {
                        printf("Vece\n");
                    }  
                }
            } while(fabs(uneseno_x2 - x2) > epsilon);
        }
       
    return 0;
}