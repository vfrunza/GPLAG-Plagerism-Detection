#include<stdio.h>
#include<string.h>

int main()
{
    char c;
    char crna[10]="crna";
    char bijela[10]="bijela";
    char siva[10]="siva";
    char plava[10]="plava";
    char crvena[10]="crvena";
    int br=0,br1=0,br2=0,br3=0,br4=0,br5=0,max=0;
    
    double p;
    
    printf("Unesite vozila: ");
    
    for(;;)
    {
        scanf("%c",&c);
        if(c=='K' || c=='k')
        {break;}
        
        else if(c=='c'|| c=='C'||c=='b' || c=='B' || c=='s'|| c=='S' || c=='p'|| c=='P'||c=='v'|| c=='V')
        {
            br++;
        }
        else
        {
            printf("Neispravan unos\n");
        }
        
        if(c=='C'||c=='c')br1++;
        if(c=='b'||c=='B')br2++;
        if(c=='s'||c=='S')br3++;
        if(c=='p'||c=='P')br4++;
        if(c=='v'||c=='V')br5++;
    }
    
    if(br1>=br2 && br1>=br3&& br1>=br4 && br1>=br5)max=br1;
    if(br2>=max && br2>=br3&& br2>=br4 && br2>=br5)max=br2;
    if(br3>=max && br3>=br1 && br3>=br4 && br2>=br5)max=br3;
    if(br4>=max && br4>=br5 && br4>=br2 && br4>=br1)max=br4;
    if(br5>=max && br5>=br3 && br5>=br2 && br5>=br1)max=br5;
    
    
    printf("Ukupno evidentirano %d vozila.\n",br);
    
    if(br==0)
    {
        p=0;
    }
    else{
        p=100.*max/br;
    }
    
    if(br1==max)
    {
        printf("Najpopularnija boja je %s (%.2lf%%).",crna,p);
    }
    else if(br2==max)
    {
        printf("Najpopularnija boja je %s (%.2lf%%).",bijela,p);
    }
    else if(br3==max)
    {
        printf("Najpopularnija boja je %s (%.2lf%%).",siva,p);
    }
    else if (br4==max)
    {
        printf("Najpopularnija boja je %s (%.2lf%%).",plava,p);
    }
    else {
        printf("Najpopularnija boja je %s (%.2lf%%).",crvena,p);
    }
    
    return 0;
    }
