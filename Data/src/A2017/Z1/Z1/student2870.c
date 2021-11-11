#include <stdio.h>
#define kkH 3.3
#define kkP 6.8
#define kkC 5.0
#define trovacH 3.0
#define trovacP 8.0
#define trovacC 3.9
#define bistroH 5.0
#define bistroP 5.3
#define bistroC 6.0


int main() {
	char tarik, bojan,mirza, novi_red;
	float r1,r2,r3,r4,r5,r6;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if (tarik=='H' && bojan=='H' && mirza=='H')
	{
		r1=3.*kkH;
		r2=3.*bistroH;
		r3=3.*trovacH;
		r4=3.*(kkH-(kkH*0.1));
		
		if ((r1<r2)&&(r1<r3)){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		}
	
		else if ((r2<r1)&&(r2<r3)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		}
		
		else printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
		
		if(r4<r1 && r4<r2 && r4<r3)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
	}
	
	else if (tarik=='P' && bojan=='P' && mirza=='P')
	{
		r1=3.*kkP;
		r2=3.*bistroP;
		r3=3.*trovacP;
		r4=3.*(kkP-(kkP*0.1));
		
		if ((r1<r2)&&(r1<r3)){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		}
	
		else if ((r2<r1)&&(r2<r3)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		}
		
		else printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
		
		if(r4<r1 && r4<r2 && r4<r3)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
	}
	
	else if (tarik=='C' && bojan=='C' && mirza=='C')
	{
		r1=3.*kkC;
		r2=3.*bistroC;
		r3=3.*trovacC;
		r4=3.*(kkC-(kkC*0.1));
		
		if ((r1<r2)&&(r1<r3)){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		}
	
		else if ((r2<r1)&&(r2<r3)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		}
		
		else printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
		
		if(r4<r1 && r4<r2 && r4<r3)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
	}
	
	else if ((tarik=='H'|| bojan=='H' || mirza=='H') && (tarik=='P'|| bojan=='P' || mirza=='P') && (tarik=='C'|| bojan=='C' || mirza=='C'))
	{
		r1=kkH+kkC+kkP;
		r2=bistroC+bistroH+bistroP;
		r3=trovacC+trovacH+trovacP;
		
		r4=(kkH-(kkH*0.1))+kkC+kkP;
		r5=(kkC-(kkC*0.1))+kkH+kkP;
		r6=(kkP-(kkP*0.1))+kkH+kkC;
		
		if ((r1<r2)&&(r1<r3)){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		}
	
		else if ((r2<r1)&&(r2<r3)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		}
		
		else printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
		
		if (r4<r1 && r4<r2 && r4<r3 && r4<r5 && r4<r6)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if (r5<r1 && r5<r2 && r5<r3 && r5<r4 && r5<r6)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		else if (r6<r1 && r6<r2 && r6<r3 && r6<r4 && r6<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r6);
	}
	
	else if (((tarik=='H' && bojan=='P' && mirza=='P') || (tarik=='P' && bojan=='H' && mirza=='P')) || ((tarik=='P' && bojan=='P' && mirza=='H')))
	{
		r1=kkH+(2*kkP);
		r2=bistroH+(2*bistroP);
		r3=trovacH+(2*trovacP);
		
		r4=(kkH-(kkH*0.1))+(2*kkP);
		r5=kkH+(2*(kkP-(kkP*0.1)));
		
		
		if (r1<r2 && r1<r3)
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		else if (r2<r1 && r2<r3)
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		else if (r3<r1 && r3<r2) 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
			
			
		if ((r1>r2 || r1>r3) && r4<r2 && r4<r3 && r4<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if ((r1>r2 || r1>r3) && r5<r2 && r5<r3 && r5<r4)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		
	}
	
	else if (((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H')) || ((tarik=='P' && bojan=='H' && mirza=='H')))
	{
		r1=kkP+(2*kkH);
		r2=bistroP+(2*bistroH);
		r3=trovacP+(2*trovacH);
		
		r4=(kkP-(kkP*0.1))+(2*kkH);
		r5=kkP+(2*(kkH-(kkH*0.1)));
		
			if (r1<r2 && r1<r3)
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		else if (r2<r1 && r2<r3)
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		else if (r3<r1 && r3<r2) 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
			
			
		if ((r1>r2 || r1>r3) && r4<r2 && r4<r3 && r4<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if ((r1>r2 || r1>r3) && r5<r2 && r5<r3 && r5<r4)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		
	}
	
	else if (((tarik=='H' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='C')) || ((tarik=='C' && bojan=='C' && mirza=='H')))
	{
		r1=kkH+(2*kkC);
		r2=bistroH+(2*bistroC);
		r3=trovacH+(2*trovacC);
		
		r4=(kkH-(kkH*0.1))+(2*kkC);
		r5=kkH+(2*(kkC-(kkC*0.1)));
		
			if (r1<r2 && r1<r3)
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		else if (r2<r1 && r2<r3)
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		else if (r3<r1 && r3<r2) 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
			
			
		if ((r1>r2 || r1>r3) && r4<r2 && r4<r3 && r4<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if ((r1>r2 || r1>r3) && r5<r2 && r5<r3 && r5<r4)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		
	}
	
	else if (((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H')) || ((tarik=='C' && bojan=='H' && mirza=='H')))
	{
		r1=kkC+(2*kkH);
		r2=bistroC+(2*bistroH);
		r3=trovacC+(2*trovacH);
		
		r4=(kkC-(kkC*0.1))+(2*kkH);
		r5=kkC+(2*(kkH-(kkH*0.1)));
		
			if (r1<r2 && r1<r3)
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		else if (r2<r1 && r2<r3)
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		else if (r3<r1 && r3<r2) 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
			
			
		if ((r1>r2 || r1>r3) && r4<r2 && r4<r3 && r4<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if ((r1>r2 || r1>r3) && r5<r2 && r5<r3 && r5<r4)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		
	}
	
		else if (((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P')) || ((tarik=='C' && bojan=='P' && mirza=='P')))
	{
		r1=kkC+(2*kkP);
		r2=bistroC+(2*bistroP);
		r3=trovacC+(2*trovacP);
		
		r4=(kkC-(kkC*0.1))+(2*kkP);
		r5=kkC+(2*(kkP-(kkP*0.1)));
		
			if (r1<r2 && r1<r3)
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		else if (r2<r1 && r2<r3)
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		else if (r3<r1 && r3<r2) 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
			
			
		if ((r1>r2 || r1>r3) && r4<r2 && r4<r3 && r4<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if ((r1>r2 || r1>r3) && r5<r2 && r5<r3 && r5<r4)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		
	}
	
		else if (((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='C')) || ((tarik=='P' && bojan=='C' && mirza=='C')))
	{
		r1=kkP+(2*kkC);
		r2=bistroP+(2*bistroC);
		r3=trovacP+(2*trovacC);
		
		r4=(kkP-(kkP*0.1))+(2*kkC);
		r5=kkP+(2*(kkC-(kkC*0.1)));
		
			if (r1<r2 && r1<r3)
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", r1);
		else if (r2<r1 && r2<r3)
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", r2);
		else if (r3<r1 && r3<r2) 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", r3);
			
			
		if ((r1>r2 || r1>r3) && r4<r2 && r4<r3 && r4<r5)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r4);
		else if ((r1>r2 || r1>r3) && r5<r2 && r5<r3 && r5<r4)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", r5);
		
	}
		
	
	
	return 0;
}
