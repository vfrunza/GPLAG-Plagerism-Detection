#include <stdio.h>
#include <math.h>

int br_pon;
int provjera(int broj)
{
    static int x=0;
    x++;
    return x;
}


double stepen(double x)
{
    int i;
    static int brojac=0;
    static double temp=0;
    double st=x;

    if(x==temp)brojac++;
    else brojac=0;


    for(i=0; i<brojac; i++) {
        st=st*x;
    }
    temp = x;
    return st;
}

void stepenuj_niz(double A[], int s[], int duzina)
{
    int i;
    for(i=0;i<duzina;i++){
        *(A+i)=pow(*(A+i), *(s+i));
    }

}

int main()
{
    int x=2;
    printf("%.2lf\n", stepen(2));
    printf("%.2lf", stepen(2));
    printf("%.2lf", stepen(1));
    return 0;
    double A[]= {2,2,2,4,4};
    int s[]= {3,2,1,2,1};
    int i;
    stepenuj_niz(A,s,5);
    for (i = 0; i < 5; i++) {
        printf("%.2lf \n", A[i]);
    }
    return 0;
}
