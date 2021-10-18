#include <stdio.h>

int main() {
	char A,B,C,novi_red,O,n='"';
	float min,min_restoran;
	float restoran_pizza=6.80, restoran_hamburger=3.30, restoran_cevapi=5.00;
	float fastfood_pizza=8.00, fastfood_hamburger=3.00, fastfood_cevapi=3.90;
	float bistro_pizza=5.30, bistro_hamburger=5.00, bistro_cevapi=6.00;
	
	do
	{
    	printf("Unesite jelo za Tarika: ");
        scanf("%c", &A);
        scanf("%c", &novi_red);
	}while(A!='P'&&A!='H'&&A!='C');
	
	do
	{
        printf("Unesite jelo za Bojana: ");
        scanf("%c", &B);
        scanf("%c", &novi_red);
    }while(B!='P'&&B!='H'&&B!='C');

    do
	{
        printf("Unesite jelo za Mirzu: ");
        scanf("%c", &C);
        scanf("%c", &novi_red);
    }while(C!='P'&&C!='H'&&C!='C');
    
    if ((A=='P')&&(B=='P')&&(C=='P'))
    {
        min=restoran_pizza*3;
        O='R';
        if(fastfood_pizza*3<min)
        {
            min=fastfood_pizza*3;
            O='F';
            min_restoran=restoran_pizza*0.9*3;
        }
        if(bistro_pizza*3<min)
        {
            min=bistro_pizza*3;
            O='B';
            min_restoran=restoran_pizza*0.9*3;
        }
        
    }
    else
    if ((A=='H')&&(B=='H')&&(C=='H'))
    {
        min=restoran_hamburger*3;
        O='R';
        if(fastfood_hamburger*3<min)
        {
            min=fastfood_hamburger*3;
            O='F';
            min_restoran=restoran_hamburger*0.9*3;
        }
        if(bistro_hamburger*3<min)
        {
            min=bistro_hamburger*3;
            O='B';
            min_restoran=restoran_hamburger*0.9*3;
        }
        
    }
    else
    if ((A=='C')&&(B=='C')&&(C=='C'))
    {
        min=restoran_cevapi*3;
        O='R';
        if(fastfood_cevapi*3<min)
        {
            min=fastfood_cevapi*3;
            O='F';
            min_restoran=restoran_cevapi*0.9*3;
        }
        if(bistro_cevapi*3<min)
        {
            min=bistro_cevapi*3;
            O='B';
            min_restoran=restoran_cevapi*0.9*3;
        }
        
    }
    else
    if (((A=='P')&&(B=='P')&&(C=='H'))||((A=='P')&&(B=='H')&&(C=='P'))||((A=='H')&&(B=='P')&&(C=='P')))
    {
        min=restoran_pizza*2 + restoran_hamburger;
        O='R';
        if(fastfood_pizza*2+fastfood_hamburger<min)
        {
            min=fastfood_pizza*2+fastfood_hamburger;
            O='F';
            if (2*0.1*restoran_pizza>0.1*restoran_hamburger)
            min_restoran=restoran_pizza*0.9*2+restoran_hamburger;else
            min_restoran=(restoran_hamburger*0.9)+(2*restoran_pizza);
        }
        if(bistro_pizza*2+bistro_hamburger<min)
        {
            min=bistro_pizza*2+bistro_hamburger;
            O='B';
            if (2*0.1*restoran_pizza>0.1*restoran_hamburger)
            min_restoran=restoran_pizza*0.9*2+restoran_hamburger;else
            min_restoran=(restoran_hamburger*0.9)+(2*restoran_pizza);
        }
        
    }
    else
    if (((A=='P')&&(B=='P')&&(C=='C'))||((A=='P')&&(B=='C')&&(C=='P'))||((A=='C')&&(B=='P')&&(C=='P')))
    {
        min=restoran_pizza*2 + restoran_cevapi;
        O='R';
        if(fastfood_pizza*2+fastfood_cevapi<min)
        {
            min=fastfood_pizza*2+fastfood_cevapi;
            O='F';
            if (2*0.1*restoran_pizza>0.1*restoran_cevapi)
            min_restoran=restoran_pizza*0.9*2+restoran_cevapi;else
            min_restoran=(restoran_cevapi*0.9)+(2*restoran_pizza);
        }
        if(bistro_pizza*2+bistro_cevapi<min)
        {
            min=bistro_pizza*2+bistro_cevapi;
            O='B';
            if (2*0.1*restoran_pizza>0.1*restoran_cevapi)
            min_restoran=restoran_pizza*0.9*2+restoran_cevapi;else
            min_restoran=(restoran_cevapi*0.9)+(2*restoran_pizza);
        }
        
    }
    else
    if (((A=='H')&&(B=='H')&&(C=='P'))||((A=='H')&&(B=='P')&&(C=='H'))||((A=='P')&&(B=='H')&&(C=='H')))
    {
        min=restoran_hamburger*2 + restoran_pizza;
        O='R';
        if(fastfood_hamburger*2+fastfood_pizza<min)
        {
            min=fastfood_hamburger*2+fastfood_pizza;
            O='F';
            if (2*0.1*restoran_hamburger>0.1*restoran_pizza)
            min_restoran=restoran_hamburger*0.9*2+restoran_pizza;else
            min_restoran=(restoran_pizza*0.9)+(2*restoran_hamburger);
        }
        if(bistro_hamburger*2+bistro_pizza<min)
        {
            min=bistro_hamburger*2+bistro_pizza;
            O='B';
            if (2*0.1*restoran_hamburger>0.1*restoran_pizza)
            min_restoran=restoran_hamburger*0.9*2+restoran_pizza;else
            min_restoran=(restoran_pizza*0.9)+(2*restoran_hamburger);
        }
        
    }
    else
    if (((A=='H')&&(B=='H')&&(C=='C'))||((A=='H')&&(B=='C')&&(C=='H'))||((A=='C')&&(B=='H')&&(C=='H')))
    {
        min=restoran_hamburger*2 + restoran_cevapi;
        O='R';
        if(fastfood_hamburger*2+fastfood_cevapi<min)
        {
            min=fastfood_hamburger*2+fastfood_cevapi;
            O='F';
            if (2*0.1*restoran_hamburger>0.1*restoran_cevapi)
            min_restoran=restoran_hamburger*0.9*2+restoran_cevapi;else
            min_restoran=(restoran_cevapi*0.9)+(2*restoran_hamburger);
        }
        if(bistro_hamburger*2+bistro_cevapi<min)
        {
            min=bistro_hamburger*2+bistro_cevapi;
            O='B';
            if (2*0.1*restoran_hamburger>0.1*restoran_cevapi)
            min_restoran=restoran_hamburger*0.9*2+restoran_cevapi;else
            min_restoran=(restoran_cevapi*0.9)+(2*restoran_hamburger);
        }
        
    }
    else
    if (((A=='C')&&(B=='C')&&(C=='P'))||((A=='C')&&(B=='P')&&(C=='C'))||((A=='P')&&(B=='C')&&(C=='C')))
    {
        min=restoran_cevapi*2 + restoran_pizza;
        O='R';
        if(fastfood_cevapi*2+fastfood_pizza<min)
        {
            min=fastfood_cevapi*2+fastfood_pizza;
            O='F';
            if (2*0.1*restoran_cevapi>0.1*restoran_pizza)
            min_restoran=restoran_cevapi*0.9*2+restoran_pizza;else
            min_restoran=(restoran_pizza*0.9)+(2*restoran_cevapi);
        }
        if(bistro_cevapi*2+bistro_pizza<min)
        {
            min=bistro_cevapi*2+bistro_pizza;
            O='B';
            if (2*0.1*restoran_cevapi>0.1*restoran_pizza)
            min_restoran=restoran_cevapi*0.9*2+restoran_pizza;else
            min_restoran=(restoran_pizza*0.9)+(2*restoran_cevapi);
        }
        
    }
    else
    if (((A=='C')&&(B=='C')&&(C=='H'))||((A=='C')&&(B=='H')&&(C=='C'))||((A=='H')&&(B=='C')&&(C=='C')))
    {
        min=restoran_cevapi*2 + restoran_hamburger;
        O='R';
        if(fastfood_cevapi*2+fastfood_hamburger<min)
        {
            min=fastfood_cevapi*2+fastfood_hamburger;
            O='F';
            if (2*0.1*restoran_cevapi>0.1*restoran_hamburger)
            min_restoran=restoran_cevapi*0.9*2+restoran_hamburger;else
            min_restoran=(restoran_hamburger*0.9)+(2*restoran_cevapi);
        }
        if(bistro_cevapi*2+bistro_hamburger<min)
        {
            min=bistro_cevapi*2+bistro_hamburger;
            O='B';
            if (2*0.1*restoran_cevapi>0.1*restoran_hamburger)
            min_restoran=restoran_cevapi*0.9*2+restoran_hamburger;else
            min_restoran=(restoran_hamburger*0.9)+(2*restoran_cevapi);
        }
        
    }
    else
    
    {
        min=restoran_pizza+restoran_hamburger+restoran_cevapi;
        O='R';
        if(fastfood_pizza+fastfood_hamburger+fastfood_cevapi<min)
        {
            min=fastfood_pizza+fastfood_hamburger+fastfood_cevapi;
            O='F';
            if ((restoran_cevapi>restoran_hamburger)&&(restoran_cevapi>restoran_pizza))
            min_restoran=(restoran_cevapi*0.9)+restoran_pizza+restoran_hamburger;else
            if ((restoran_hamburger>restoran_pizza)&&(restoran_hamburger>restoran_cevapi))
            min_restoran=(restoran_hamburger*0.9)+restoran_cevapi+restoran_pizza;else
            min_restoran=(restoran_pizza*0.9)+restoran_cevapi+restoran_hamburger;
        }
        if(bistro_pizza+bistro_hamburger+bistro_cevapi<min)
        {
            min=bistro_pizza+bistro_hamburger+bistro_cevapi;
            O='B';
        }
        
    }
    
    if (O=='R')
    {
        printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",n,n,min);
        return 1;
    }
    else if (O=='F')
    printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).",n,n,min);
    else
    printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).",n,n,min);
    
    
    if (min_restoran<min)
    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",min_restoran);
    
    
	return 0;
}
