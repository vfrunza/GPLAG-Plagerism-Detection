#include <stdio.h>

int main() {
    char vozilo;
    float p1,p2,p3,p4,p5;
    int p=0;
    p1=p2=p3=p4=p5=0;
    float procenat;
    printf("Unesite vozila: ");
    do{
        scanf("%c",&vozilo);
            p++;
            if(vozilo=='C'||vozilo=='c') p1++;
            else if(vozilo=='B'||vozilo=='b') p2++;
            else if(vozilo=='S'||vozilo=='s') p3++;
            else if(vozilo=='V'||vozilo=='v') p4++;
            else if(vozilo=='P'||vozilo=='p') p5++;
            else{
                if(vozilo!='K'&&vozilo!='k')
                printf("Neispravan unos\n");
                p--;
            }
            
        
    }while(vozilo!='K'&&vozilo!='k');
    printf("Ukupno evidentirano %d vozila.\n",p);
    
    
    
    if(p1>=p2&&p1>=p3&&p1>=p4&&p1>=p5)
    {
        procenat=(p1/p)*100.;
        printf("Najpopularnija boja je crna (%.2f%).",procenat);
        return 0;
    }
    if(p2>=p1&&p2>=p3&&p2>=p4&&p2>=p5)
    {
        procenat=(p2/p)*100;
        printf("Najpopularnija boja je bijela (%.2f%).",procenat);
        return 0;
    }
     if(p3>=p1&&p3>=p2&&p3>=p4&&p3>=p5)
     {
         procenat=(p3/p)*100;
         printf("Najpopularnija boja je siva (%.2f%).",procenat);
         return 0;
     }
    if(p4>=p1&&p4>=p2&&p4>=p3&&p4>=p5)
     {
         procenat=(p4/p)*100;
         printf("Najpopularnija boja je crvena (%.2f%).",procenat);
         return 0;
     }
     if(p5>=p1&&p5>=p2&&p5>=p3&&p5>=p4)
     {
         procenat=(p5/p)*100;
         printf("Najpopularnija boja je plava (%.2f%).",procenat);
     }
    
    
    

	return 0;
}
