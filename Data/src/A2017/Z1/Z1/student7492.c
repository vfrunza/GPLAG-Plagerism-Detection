#include <stdio.h>
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00
#define c1 5.00
#define c2 3.90
#define c3 6.00

int main() 
{
	char tarik,bojan,mirza,novi_red;
	double restoran1,restoran2,restoran3,popust,najjeftiniji;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&novi_red); 
	scanf("%c",&bojan);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&novi_red);
	scanf("%c",&mirza);

	if(tarik=='H' && bojan=='H' && mirza=='H')
	{
		restoran1=3*h1;
		restoran2=3*h2;
		restoran3=3*h3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	popust=3*h1/10;
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if(tarik=='P' && bojan=='P' && mirza=='P')
	{
		restoran1=3*p1;
		restoran2=3*p2;
		restoran3=3*p3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	popust=3*p1/10;
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if(tarik=='C' && bojan=='C' && mirza=='C')
	{
		restoran1=3*c1;
		restoran2=3*c2;
		restoran3=3*c3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	popust=3*c1/10;
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if( (tarik=='P' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='C' && bojan=='C' && mirza=='P') )
	{
		restoran1=2*c1+p1;
		restoran2=2*c2+p2;
		restoran3=2*c3+p3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	if(c1>p1) { popust=2*c1/10; }
	    	else { popust=p1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if( (tarik=='P' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='H' && bojan=='H' && mirza=='P') )
	{
		restoran1=2*h1+p1;
		restoran2=2*h2+p2;
		restoran3=2*h3+p3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	if(h1>p1) { popust=2*h1/10; }
	    	else { popust=p1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if( (tarik=='H' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='C' && bojan=='C' && mirza=='H') )
	{
		restoran1=2*c1+h1;
		restoran2=2*c2+h2;
		restoran3=2*c3+h3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	if(c1>h1) { popust=2*c1/10; }
	    	else { popust=h1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if( (tarik=='H' && bojan=='P' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='P' && mirza=='H') )
	{
		restoran1=2*p1+h1;
		restoran2=2*p2+h2;
		restoran3=2*p3+h3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	if(p1>h1) { popust=2*p1/10; }
	    	else { popust=h1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else if( (tarik=='C' && bojan=='P' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='P' && bojan=='P' && mirza=='C') )
	{
		restoran1=2*p1+c1;
		restoran2=2*p2+c2;
		restoran3=2*p3+c3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	if(p1>c1) { popust=2*p1/10; }
	    	else { popust=c1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	else if( (tarik=='C' && bojan=='H' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='H' && mirza=='C') )
	{
		restoran1=2*h1+c1;
		restoran2=2*h2+c2;
		restoran3=2*h3+c3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	if(h1>c1) { popust=2*h1/10; }
	    	else { popust=c1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
	else
	{
		restoran1=p1+c1+h1;
		restoran2=p2+c2+h2;
		restoran3=p3+c3+h3;
	    najjeftiniji=restoran1;
	    if(restoran2<najjeftiniji) { najjeftiniji=restoran2; }
	    if(restoran3<najjeftiniji) { najjeftiniji=restoran3; }
	    
	    if(najjeftiniji==restoran1) { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran1); }
	    else if(najjeftiniji==restoran2) { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",restoran2); }
	    else if(najjeftiniji==restoran3) { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",restoran3); }
	    
	    if(restoran1>restoran2 || restoran1>restoran3)
	    {
	    	popust=p1/10;
	    	if(c1>p1) { popust=c1/10; }
	    	if(h1>p1) { popust=h1/10; }
	    	restoran1-=popust;
	    	if(restoran1<restoran2 && restoran1<restoran3)
	    	{
	    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran1);
	    	}
	    }
	}
	
return 0;
}

	
	
	
	
