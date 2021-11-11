#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    char tarik, bojan, mirza;
    char novi_red;
    int brojach=0,brojacc=0,brojacp=0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);
    
    float skk=0, sft=0, sbl=0;
    switch(tarik)
    {
        case 'H':
        skk+=3.3;
        brojach++;
        sft+=3.0;
        sbl+=5.0;
        break;
        case 'P':
        skk+=6.8;
        brojacp++;
        sft+=8.0;
        sbl+=5.3;
        break;
        case 'C':
        skk+=5.0;
        brojacc++;
        sft+=3.9;
        sbl+=6.0;
        break;
    }
    switch(bojan)
    {
        case 'H':
        skk+=3.3;
        brojach++;
        sft+=3.0;
        sbl+=5.0;
        break;
        case 'P':
        skk+=6.8;
        brojacp++;
        sft+=8.0;
        sbl+=5.3;
        break;
        case 'C':
        skk+=5.0;
        brojacc++;
        sft+=3.9;
        sbl+=6.0;
        break;
    }
    switch(mirza)
    {
        case 'H':
        skk+=3.3;
        brojach++;
        sft+=3.0;
        sbl+=5.0;
        break;
        case 'P':
        skk+=6.8;
        brojacp++;
        sft+=8.0;
        sbl+=5.3;
        break;
        case 'C':
        skk+=5.0;
        brojacc++;
        sft+=3.9;
        sbl+=6.0;
        break;
    }
    float br=brojacc,novi_kk,procenat;
    if(brojach>brojacc && brojach>brojacp)
        br=brojach;
    if(brojacp>brojacc && brojacp>brojach)
        br=brojacp;
    if(brojacp==brojacc || brojacp==brojach)
        br=brojacp;
    novi_kk=skk;
    if(br=brojacc)
        {
            procenat=br*0.1*5;
           
        }
    if(br=brojach)
        {
            procenat=br*0.1*3.3;
            
        }
    if(br=brojacp)
        {
            procenat=br*0.1*6.8;
            
        }
    int t=0;
    float min=skk; 
    if(sft<min)
    {
        min=sft;
    }
    if(sbl<min)
    {
        min=sbl;
    }
    if(skk==min)
    {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",skk);
        t=1;
    }
    if(sft==min)
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",sft);
    if(sbl==min)
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",sbl);
    printf("\n");
    if(skk-procenat<min && t!=1)
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",skk-procenat);
    return 0;
}