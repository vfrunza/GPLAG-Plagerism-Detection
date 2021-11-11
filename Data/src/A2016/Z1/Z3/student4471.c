#include <stdio.h>
 
int main() {
    char x;
    
    int crna=0,plava=0,bijela=0,siva=0,crvena=0, suma=0,bb=0 ,bc=0, bp=0, bs=0, bv=0;
    printf("Unesite vozila: ");
    while(1)
    {
        scanf("%c",&x);
        if(x=='c'||x=='C')
        {
            crna++;
            suma++;
            if(crna==1)
                bc=suma;
            
        }
        else if(x=='B'||x=='b')
        {
            bijela++;
            suma++;
            if(bijela==1)
                bb=suma;
        }
        else if(x=='s'||x=='S')
        {
            siva++;
            suma++;
            if(siva==1)
                bs=suma;
        }
        else if(x=='v'||x=='V')
        {
            crvena++;
            suma++;
            if(crvena==1)
                bv=suma;
        }
        else if(x=='p'||x=='P')
        {
            plava++;
            suma++;
            if(plava==1)
                bp=suma;
        }
        else if(x=='k'||x=='K')
        {
            break;
        }
        else{
            printf("Neispravan unos\n");
        }
       
    }
    
    
    printf("Ukupno evidentirano %d vozila.\n",suma);
    
    
    int max, min,boja=1;
    max=crna;
    min=bc;
    if(max<crvena||(min>bv&&max==crvena)){
        max=crvena;
        min=bv;
        boja=2;
    }
    if(max<plava||(min>bp&&max==plava))
    {
        max=plava;
        min=bp;
        boja=3;
    }
    if(max<siva||(min>bs&&max==siva))
    {    max=siva;
        min=bs;   
        boja=4;
    }
    if(max<bijela||(min>bb&&max==bijela))
    {    max=bijela;
        min=bb;
        boja=5;
    }
    double f,g;
    f=max;
    g=suma;
    if(suma==0)
        g=1;
    printf("Najpopularnija boja je ");
    switch (boja){
        case 1:
            printf("crna (%.2f%).",f/g*100);
            break;
        case 2:
            printf("crvena (%.2f%).",f/g*100);
            break;
        case 3:
            printf("plava (%.2f%).",f/g*100);
            break;
        case 4:
            printf("siva (%.2f%).",f/g*100);
            break;
        case 5:
            printf("bijela (%.2f%).", f/g*100);
            break;
   
    }
   
   return 0;
}
