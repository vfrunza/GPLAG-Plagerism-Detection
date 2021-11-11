#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
    int a, b, c, kontrolna;
    double D, x_1, x_2, temp, x_1_unos, x_2_unos, razlika = 0;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%d %d %d", &a, &b, &c);
    D = (b*b - 4*a*c);
    
    if(D < 0){
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    else if(D == 0)
    {
        x_1 = -b/(2.*a) - sqrt(D)/(2.*a);
        x_2 = x_1 ;
     
        do{
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x_1_unos);
            
            if(fabs(x_1_unos - x_1) < epsilon){
                printf("Tacno\n");
                break;
            }
            
            else if(fabs(x_1_unos - x_1) < 0.1 && x_1_unos < x_1) {
                printf("Priblizno manje\n");
            }
            else if (fabs(x_1_unos - x_1) < 0.1 && x_1_unos > x_1) {
               
                    printf("Priblizno vece\n");
                }
            else if (fabs(x_1_unos - x_1) > epsilon && x_1_unos < x_1 ) {
                printf("Manje\n");
            }
            else if(fabs(x_1_unos - x_1) > epsilon && x_1_unos > x_1) {
                printf("Vece\n"); 
            }
        
            /*else if((x_1_unos - x_1) < 0 && ((fabs(x_1_unos - x_1) < 0.1) && (fabs(x_1_unos - x_1) > epsilon))){
                printf("Priblizno manje\n");
            }
            else if((x_1_unos - x_1) > 0 && ((fabs(x_1_unos - x_1) < 0.1) && (fabs(x_1_unos - x_1) > epsilon))){
                printf("Priblizno vece\n");
            }
            else if((x_1_unos - x_1) < 0 && ((fabs(x_1_unos - x_1) > 0.1))){
                printf("Manje\n");
            }
            else if((x_1_unos - x_1) > epsilon && ((fabs(x_1_unos - x_1) > 0.1))){
                printf("Vece\n");
            }*/
        } while(1);
        kontrolna = 0;
        do{
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x_2_unos);
            
            if(fabs(x_2_unos - x_2) < epsilon){
                printf("Tacno\n");
                /*kontrolna = 1;*/
                break;
            }
            
               else if(fabs(x_2_unos - x_2) < 0.1 && x_2_unos < x_2) {
                printf("Priblizno manje\n");
            }
            else if (fabs(x_2_unos - x_2) < 0.1 && x_2_unos > x_2) {
               
                    printf("Priblizno vece\n");
                }
            else if (fabs(x_2_unos - x_2) > epsilon && x_2_unos < x_2 ) {
                printf("Manje\n");
            }
            else if(fabs(x_2_unos - x_2) > epsilon && x_2_unos > x_2) {
                printf("Vece\n"); 
            }
           /* else if((x_2_unos - x_2) < 0 && ((fabs(x_2_unos - x_2) < 0.1) && (fabs(x_2_unos - x_2) > epsilon))){
                printf("Priblizno manje\n");
            }
            else if((x_2_unos - x_2) > 0 && ((fabs(x_2_unos - x_2) < 0.1) && (fabs(x_2_unos - x_2) > epsilon))){
                printf("Priblizno vece\n");
            }
            else if((x_2_unos - x_2) < 0 && ((fabs(x_2_unos - x_2) > 0.1))){
                printf("Manje\n");
            }
            else if((x_2_unos - x_2) > epsilon && ((fabs(x_2_unos - x_2) > 0.1))){
                printf("Vece\n");
            }*/
        } while(1);
    }
    else if(D > 0){
        x_1 = -b/(2*a) - sqrt(D)/(2*a);
        x_2 = -b/(2*a) + sqrt(D)/(2*a);
        if(x_1 > x_2){
            temp = x_2;
            x_2 = x_1;
            x_1 = temp;
        }
        do{
            printf("Unesite rjesenje x1: ");
            scanf("%lf", &x_1_unos);
            
            if(fabs(x_1_unos - x_1) < epsilon){
                printf("Tacno\n");
                break;
                /*kontrolna = 1;*/
            }
            else if((x_1_unos - x_1) < 0 && ((fabs(x_1_unos - x_1) < 0.1) && (fabs(x_1_unos - x_1) > epsilon))){
                printf("Priblizno manje\n");
            }
            else if((x_1_unos - x_1) > 0 && ((fabs(x_1_unos - x_1) < 0.1) && (fabs(x_1_unos - x_1) > epsilon))){
                printf("Priblizno vece\n");
            }
            else if((x_1_unos - x_1) < 0 && ((fabs(x_1_unos - x_1) > 0.1))){
                printf("Manje\n");
            }
            else if((x_1_unos - x_1) > epsilon && ((fabs(x_1_unos - x_1) > 0.1))){
                printf("Vece\n");
            }
        } while(1);
        kontrolna = 0;
        do{
            printf("Unesite rjesenje x2: ");
            scanf("%lf", &x_2_unos);
            
            if(fabs(x_2_unos - x_2) < epsilon){
                printf("Tacno\n");
                /*kontrolna = 1;*/
                break;
            }
            else if((x_2_unos - x_2) < 0 && ((fabs(x_2_unos - x_2) < 0.1) && (fabs(x_2_unos - x_2) > epsilon))){
                printf("Priblizno manje\n");
            }
            else if((x_2_unos - x_2) > 0 && ((fabs(x_2_unos - x_2) < 0.1) && (fabs(x_2_unos - x_2) > epsilon))){
                printf("Priblizno vece\n");
            }
            else if((x_2_unos - x_2) < 0 && ((fabs(x_2_unos - x_2) > 0.1))){
                printf("Manje\n");
            }
            else if((x_2_unos - x_2) > epsilon && ((fabs(x_2_unos - x_2) > 0.1))){
                printf("Vece\n");
            }
        } while(1);
    }
    
	return 0;
}
