#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#include<stdlib.h>

int main() {
    double rad[500];
    double stepen;
    double minuta;
    double sekunda;
    double ugao;
    int x, i, j;
    printf("Unesite broj uglova: ");
    scanf("%d", &x);
    for (i = 0; i < x; i++){
        scanf("%lf", &rad[i]);
    }
    for(i = 0; i < x; i++){
    ugao = fabs((rad[i]*180)/PI); minuta = (ugao - (int)ugao)*60;
    sekunda = round((minuta - (int)minuta)*60);
    /*Algoritam za izbacivanje clanove iz niza uz ocuvanje redoslijeda*/
    if (sekunda == 60){
        sekunda = 0;
        minuta++;
    }
    if (sekunda > 30){
        for(j = i; j < x - 1; j++){
            rad[j] = rad[j+1];
        }
        i--;
        x--;
    }
    }
    printf("Uglovi su:\n");
    for(i = 0; i < x; i++){
        ugao = (rad[i]*180)/PI;
        minuta = fabs((ugao - (int)ugao)*60);
        sekunda = round((minuta - (int)minuta)*60);
        stepen = (int)ugao;
        sekunda = round(sekunda);
        minuta = (int)minuta;
        if(stepen < 0){
            if(sekunda == 60){
                sekunda = 0;
                minuta++;
            }if (minuta == 60){
                minuta = 0;
                stepen--;
            }
        }
        if(stepen >= 0){
            if (sekunda == 60){
                sekunda = 0;
                minuta++;
            }if (minuta == 60){
                minuta = 0;
                stepen++;
            }
        }
        printf("%.f stepeni %.f minuta %.f sekundi\n", stepen, minuta, sekunda);
    }
    return 0;
}   

