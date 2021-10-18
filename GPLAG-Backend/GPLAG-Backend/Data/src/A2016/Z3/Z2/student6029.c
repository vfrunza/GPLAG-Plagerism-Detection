#include <stdio.h>

/*sabiramo cifre broja poslanog u funkciju f1*/
int f1 (int x) {
    int c=0,sum=0;
    while (x!=0) {
        c=x%10;
        sum=sum+c;
        x/=10;
    }
    if (sum<0) 
        sum*=-1;
    return sum;
} 
/*Ispitujemo da li broj a pripada Fibonaccijevom nizu*/
int f2 (int a) {
    int x=1, y=1;
    while (x<a && y<a) {
        x+=y;
        y+=x;
    }
    if (x==a || y==a)
        return 1;
    else
        return 0;
}
/*prosirujemo niz i ubacujemo nove elemente*/ 
void ubaci (int *niz, int duz) {
    int i=0, j=0,noviNiz[200],a=0;
    for (i=0; i<duz; i++) {
        noviNiz[j]=niz[i];
        j++;
        a=niz[i];
        noviNiz[j]=f1(a);
        j++;
    }
    for (i=0; i<2*duz; i++)
            niz[i]=noviNiz[i];
}
int izbaci (int *niz, int duz) {
    int j=0,i=0,a=0;
    for (i=0; i<duz; i++) {
        a=niz[i];
        if (f2(a)==1) {
            for (j=i; j<duz-1; j++) {
                niz[j]=niz[j+1];
            }
        duz--;
        i--;
    }
}
return duz;
}
int main() {
    int i=0, niz[100],duz=10;;
    printf ("Unesite niz od 10 brojeva: ");
    for (i=0; i<duz; i++) {
        scanf ("%d",&niz[i]);
    }
    ubaci(niz,duz);
    duz=2*duz;
    duz=izbaci(niz,duz);
    printf ("Modificirani niz glasi: ");
    for (i=0; i<duz; i++) {
        if (i==duz-1)
            printf ("%d.",niz[i]);
        else
            printf ("%d, ",niz[i]);
    }
	return 0;
}
