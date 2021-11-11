#include <stdio.h>
#include <math.h>

/*funkcija stepen koja radi isto kao funkcija pow iz biblioteke math.h*/
double stepen (double baza, int eksponent){
    int i;
    double pom=baza;
    for (i=1; i<fabs(eksponent); i++){
        pom*=baza;
    }
    if (eksponent<0) return 1/pom;
    if (eksponent==0) return 1;
    return pom;
}
int normalan(int broj, int niz_cifara[100],int duzina_niza_cifara){
    int novi_broj=0;
    int ima=0;
    int brojac=0,i=0,cifra;
    while (broj!=0){
        ima=0;
        cifra = fabs(broj%10);
        for(i=0;i<duzina_niza_cifara;i++){
            if(cifra == niz_cifara[i]) ima = 1;
        }
        if(ima==0){
            novi_broj+=broj%10*stepen(10, brojac);
            brojac++;
        }
        broj/=10;
    }
    return novi_broj;
}

int izbaci_cifre (int niz_brojeva[100], int duzina_niza_brojeva, int niz_cifara[100], int duzina_niza_cifara){
    int i, j;
    /*provjera ispravnosti niza cifara po uslovu zadatka */
    for (i=0; i<duzina_niza_cifara; i++){
        if (niz_cifara[i]<0 || niz_cifara[i]>9) return 0;
    }
    for (i=0; i<duzina_niza_cifara; i++){
        for (j=i+1; j<duzina_niza_cifara; j++){
            if (niz_cifara[i]==niz_cifara[j]) return 0;
        }
    }
    /**************************************************/
    for(i=0;i<duzina_niza_brojeva;i++){
        niz_brojeva[i] = normalan(niz_brojeva[i],niz_cifara,duzina_niza_cifara);
        /*printf("%d ",niz_brojeva[i]);*/
    }
    return 1;
}




int main(void) {
    int cifre[]={1,3,5,7,9};
    int brojevi[]={1423,53674,3231,4675,4325,325,8759,245,89,103050,2040,240,1230,0};
    izbaci_cifre(brojevi,14,cifre,5);
	return 0;
}
