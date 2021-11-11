#include <stdio.h>
#include <math.h>

int main() {
    
	/* Unos varijabila */
    
    double a,b,c,x1,x2,x1k,x2k,D,xa,xb;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf", &a,&b,&c);
    
    /* Formule */
    
    D=b*b-4*a*c;
    xa=(-b-sqrt(D))/(2*a);
    xb=(-b+sqrt(D))/(2*a);
    
    /* Manji broj je x1 */
    
    if (xa>=xb) {
        x1=xb;
        x2=xa;
    } else if (xa<=xb) {
        x1=xa;
        x2=xb;
    }
    
    /* Imaginarna rjesenja */
    
    if (D<0) {
        printf ("Rjesenja su imaginarni brojevi.");
        return 1;
    }
    
    /* Rjesenje x1 */
    greska1:
    printf("Unesite rjesenje x1: ");
    scanf("%lf", &x1k);

    if (x1k-x1>=0.1) {
        printf("Vece \n");
        goto greska1;
    } else if (x1k-x1<=-0.1) {
        printf("Manje \n");
        goto greska1;
    } else if (x1k-x1>-0.001 && x1k-x1<0.001) {
        printf("Tacno \n");
    } else if (x1k-x1>-0.1 && x1k-x1<=-0.001) {
        printf("Priblizno manje \n");
        goto greska1;
    } else if (x1k-x1>=0.001 && x1k-x1 <0.1) {
        printf("Priblizno vece \n");
        goto greska1;
    } 
    
    /* Rjesenje x2 */
    greska2:
    printf("Unesite rjesenje x2: ");
    scanf("%lf", &x2k);
    
    if (x2k-x2>=0.1) {
        printf("Vece \n");
        goto greska2;
    } else if (x2k-x2<=-0.1) {
        printf("Manje \n");
        goto greska2;
    } else if (x2k-x2>-0.001 && x2k-x2<0.001) {
        printf("Tacno\n");
    } else if (x2k-x2>-0.1 && x2k-x2<=-0.001) {
        printf ("Priblizno manje \n");
        goto greska2;
    } else if (x2k-x2>=0.001 && x2k-x2<0.1) {
        printf ("Priblizno vece \n");
        goto greska2;
    }

    return 0;
}
