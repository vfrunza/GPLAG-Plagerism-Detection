#include <stdio.h>

int daj_prost(){
    static int i=2;
    int j,c;
    while(1)
    {
        c=1;
        for(j=2;j<i/2+1;j++)
        {
            if(i%j==0){c=0;i++;break;}
        }
        if(c)return i++;
    }
    
}
int main(){
    int i,a,b,temp,suma=0;
    do{
        printf("Unesite brojeve A i B: ");
        scanf("%d %d",&a,&b);
        if(a<1)printf("A nije prirodan broj.\n");
        if(a>=b)printf("A nije manje od B.\n");
    }
    while(a>=b || a<1);
    temp=2;
    while(temp<b)
    {
        temp=daj_prost();
        for(i=a+1;i<b;i++){
        if(i==temp){suma+=i;break;}
    }
        
    }
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
    return 0;
}