#include <stdio.h>
#include <stdlib.h>

int main(){
    int niz[100];
    int final[1000];
    int n;

    printf("Unesite velicinu niza: ");
    while(1){
    scanf("%d",&n);
    if(n>0 && n<=100)break; 
    }

    printf("Unesite clanove niza: ");
    int a;
    int i=0;

    while(i<n){
        scanf("%d", &a);
        if(a<=0)continue;
        niz[i]=a;
        i++;
    }

    int q=0;
    for(i=n-1;i>=0;i--){
        int broj=niz[i];
        if(broj==0){
                final[q]=broj;
                q++;

        }
        while(broj!=0){
            final[q]=broj%10;   
            q++;
            broj/=10;
        }
    }

    int m=0;
    int kopija[1000];
    for(i=q-1;i>=0;i--){
        kopija[m]=final[i];         
        m++;
    }


    int koord=0;

    for(i=0;i<q;i++){
        int b=kopija[i];
        int brojac=0;
        while(kopija[i]==b){
            brojac++;                  
            i++;
            if(i==q )break;
        }
        i--;
        final[koord]=b;
        final[koord+1]=brojac;
        koord+=2;

    }
    printf("Finalni niz glasi: \n%d",final[0]);             
    for(i=1;i<koord;i++){
        printf(" %d",final[i]);
    }


    return 0;
}
