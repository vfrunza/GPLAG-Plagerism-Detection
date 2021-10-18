#include<stdio.h>
#include<math.h>
int main()
{
    char tarik,mirza,bojan;
    float Kod_konja_i_konjusara,Fast_food,Bistro;
    printf("Unesite jelo za tarika:\n");
    scanf("%c",&tarik);
    printf("Unesite jelo za bojana:\n");
    scanf("%c",&bojan);
    printf("Unesite jelo za mirzu:\n");
    scanf("%c",&mirza);
    if(tarik==mirza==bojan)
    {
        Kod_konja_i_konjusara=3*3.30;
        printf("Cijena je %f",Kod_konja_i_konjusara);}
    else if (tarik==bojan!=mirza){
     Kod_konja_i_konjusara=(2*tarik)+mirza;
     printf("cijena %d je",Kod_konja_i_konjusara);
    }
return 0;
}