#include <stdio.h>
#include <math.h>
int main() {
    int i, x, br=0, b1, b2, a, zadnjacifra, br2=0, br3=0;
    printf("Unesite broj: ");
    scanf("%d", &x);
    a=x;
    while(a!=0) {
        a=a/10;
        br++;
        
    }
    if (br==1 || x==0) printf("0");
    else {
    
    for (i=br; i>1; i--) {
        zadnjacifra=x%10;
        b1=x/(pow(10, i-1));
        b2=(x-b1*pow(10, i-1))/(pow(10, i-2));
        x=x-b1*pow(10, i-1);
        if(i==br) {
            br2++;
        }
        if (i==2) {
            br3=1;
        }
        
        if (b1==b2 && br2==1) {
            if (br2==1 && br3==1 && zadnjacifra==br2)  { br2=0; printf("0"); return 0; }
            else { br2=1; 
            continue; } }
        
        else br2=0;
            
    
         if(b1>b2) {
            printf("%d", b1-b2);
         }
         else printf("%d", b2-b1);
    } }
    return 0;
}