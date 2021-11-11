#include <stdio.h>

#define p_konj 6.80
#define h_konj 3.30
#define c_konj 5.00
#define p_trovac 8.00
#define h_trovac 3.00
#define c_trovac 3.90
#define p_bistro 5.30
#define h_bistro 5.00
#define c_bistro 6.00

int main() {
	char tarik, bojan, mirza, novi_red;
	double c_min, h_min, p_min, A, B, C;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
		
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan );
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
		if (h_bistro<=h_konj && h_bistro<=h_trovac)                          /*odredjivanje najjeftinijeg hamburgera*/
		h_min=h_bistro;
		else if (h_konj<=h_bistro && h_konj<=h_trovac)
		h_min=h_konj;
		else if (h_trovac<=h_bistro && h_trovac<=h_konj)
		h_min=h_trovac;
		
		if(c_bistro<=c_konj && c_bistro<=c_trovac)                        /*odredjivanje najjeftinijih cevapa*/
		c_min=c_bistro;
		else if (c_konj<=c_bistro && c_konj<=c_trovac)
		c_min=h_konj;
		else if (c_trovac<=c_bistro && c_trovac<=c_konj)
		c_min=c_trovac;
		
		if(p_bistro<=p_konj && p_bistro<=p_trovac)                        /*odredjivanje najjeftinije pice*/
		p_min=p_bistro;
		else if (p_konj<=p_bistro && p_konj<=p_trovac)
		p_min=p_konj;
		else if (p_trovac<=p_bistro && p_trovac<=p_konj)
		p_min=p_trovac;
		
	
	if(tarik==bojan && bojan==mirza)                                          /*SVA TROJICA ISTO JELO*/
	{
	
	if( tarik=='H' && bojan=='H' && mirza=='H' )                              /*sva trojica hambas*/
	{
		if(h_min==p_bistro)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 3*h_bistro);
		else if(h_min==h_trovac)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 3*h_trovac);
		else if(h_min==h_konj)
			{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 3*h_konj);
		return 0;
			}
		
		if( (h_konj*0.9)<=h_min )
		printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", 3*h_konj*0.9);
	}	
		
	if( tarik=='P' && bojan=='P' && mirza=='P' )                            /*sva trojica picu*/
	{
		if(p_min==p_bistro)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 3*p_bistro);
		else if(p_min==h_trovac)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 3*h_trovac);
		else if(p_min==p_konj)
			{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 3*p_konj);
		return 0;
			}
		
		if( (p_konj*0.9)<=p_min )
		printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", 3*p_konj*0.9);
	}
		
		
	if( tarik=='C' && bojan=='C' && mirza=='C' )                            /*sva trojica cevape*/
	{
		if(c_min==c_bistro)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 3*c_bistro);
		else if(c_min==c_trovac)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 3*c_trovac);
		else if(c_min==c_konj)
			{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 3*c_konj);
		return 0;
			}
		
		if( (c_konj*0.9)<c_min )
		printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", 3*c_konj*0.9);
	}
	}
	
	
	
	
	if( (bojan=='P' && tarik=='P' && mirza=='C') || (bojan=='P' && mirza=='P' && tarik=='C') || (mirza=='P' && tarik=='P' && bojan=='C') )                   /*dvije pice i jedni cevapi*/
	{
		if( (2*p_konj+c_konj)<(2*p_bistro+c_bistro) && (2*p_konj+c_konj)<(2*p_trovac+c_trovac) )
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 2*p_konj+c_konj );
		return 0;
			}
		else if( (2*p_bistro+c_bistro)<(2*p_konj+c_konj) && (2*p_bistro+c_bistro)<(2*p_trovac+c_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 2*p_bistro+c_bistro );
		else if ( (2*p_trovac+c_trovac)<(2*p_konj+c_konj) && (2*p_trovac+c_trovac)<(2*p_bistro+c_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 2*p_trovac+c_trovac );
		
		
		if(2*p_konj>c_konj)
		{
			A=(2*p_konj)*0.9+c_konj;
			if( (A<(2*p_konj+c_konj) ) && (A<(2*p_bistro+c_bistro) ) && (A<(2*p_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(c_konj>2*p_konj)
		{
			B=2*p_konj+c_konj*0.9;
			if( (B<(2*p_konj+c_konj) ) && (B<(2*p_bistro+c_bistro) ) && (B<(2*p_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
	
		
	}
	
	
	
	if( (bojan=='P' && tarik=='P' && mirza=='H') || (bojan=='P' && mirza=='P' && tarik=='H') || (mirza=='P' && tarik=='P' && bojan=='H') )          /*dvije pice i jedan hamburger*/
	{
		if( (2*p_konj+h_konj)<(2*p_bistro+h_bistro) && (2*p_konj+h_konj)<(2*p_trovac+h_trovac) )
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 2*p_konj+h_konj );
		return 0;
			}
		else if( (2*p_bistro+h_bistro)<(2*p_konj+h_konj) && (2*p_bistro+h_bistro)<(2*p_trovac+h_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 2*p_bistro+h_bistro );
		else if ( (2*p_trovac+h_trovac)<(2*p_konj+h_konj) && (2*p_trovac+h_trovac)<(2*p_bistro+h_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 2*p_trovac+h_trovac );
		
		
		if(2*p_konj>h_konj)
		{
			A=(2*p_konj)*0.9+h_konj;
			if( (A<(2*p_konj+h_konj) ) && (A<(2*p_bistro+h_bistro) ) && (A<(2*p_trovac+h_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(h_konj>2*p_konj)
		{
			B=2*p_konj+h_konj*0.9;
			if( (B<(2*p_konj+h_konj) ) && (B<(2*p_bistro+h_bistro) ) && (B<(2*p_trovac+h_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
		
	}
	
	if( (bojan=='C' && tarik=='C' && mirza=='P') || (bojan=='C' && mirza=='C' && tarik=='P') || (mirza=='C' && tarik=='C' && bojan=='P') )           /*dvoje cevapa i jedna pica*/
	{
		if( (2*c_konj+p_konj)<(2*c_bistro+p_bistro) && (2*c_konj+p_konj)<(2*c_trovac+p_trovac) )
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 2*c_konj+p_konj );
		return 0;
			}
		else if( (2*c_bistro+p_bistro)<(2*c_konj+p_konj) && (2*c_bistro+p_bistro)<(2*c_trovac+p_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 2*c_bistro+p_bistro );
		else if ( (2*c_trovac+p_trovac)<(2*c_konj+p_konj) && (2*c_trovac+p_trovac)<(2*c_bistro+p_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 2*c_trovac+p_trovac );
		
		
		if(2*c_konj>p_konj)
		{
			A=(2*c_konj)*0.9+p_konj;
			if( (A<(2*c_konj+p_konj) ) && (A<(2*c_bistro+p_bistro) ) && (A<(2*c_trovac+p_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(p_konj>2*c_konj)
		{
			B=2*c_konj+p_konj*0.9;
			if( (B<(2*c_konj+p_konj) ) && (B<(2*c_bistro+p_bistro) ) && (B<(2*c_trovac+p_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
	}
	
	
	
	if( (bojan=='C' && tarik=='C' && mirza=='H') || (bojan=='C' && mirza=='C' && tarik=='H') || (mirza=='C' && tarik=='C' && bojan=='H') )               /*dvoje cevapa i jedan hamburger*/
	{
		if( (2*c_konj+h_konj)<(2*c_bistro+h_bistro) && (2*c_konj+h_konj)<(2*c_trovac+h_trovac) )
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 2*c_konj+h_konj );
		return 0;
			}
		else if( (2*c_bistro+h_bistro)<(2*c_konj+h_konj) && (2*c_bistro+h_bistro)<(2*c_trovac+h_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 2*c_bistro+h_bistro );
		else if ( (2*c_trovac+h_trovac)<(2*c_konj+h_konj) && (2*c_trovac+h_trovac)<(2*c_bistro+h_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 2*c_trovac+h_trovac );
		
		if(2*c_konj>h_konj)
		{
			A=(2*c_konj)*0.9+h_konj;
			if( (A<(2*c_konj+h_konj) ) && (A<(2*c_bistro+h_bistro) ) && (A<(2*c_trovac+h_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(h_konj>2*c_konj)
		{
			B=2*c_konj+h_konj*0.9;
			if( (B<(2*c_konj+h_konj) ) && (B<(2*c_bistro+h_bistro) ) && (B<(2*c_trovac+h_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
	}
	
	
	
	if( (bojan=='H' && tarik=='H' && mirza=='C') || (bojan=='H' && mirza=='H' && tarik=='C') || (mirza=='H' && tarik=='H' && bojan=='C') )             /*dva hamburgera i jedni cevapi*/
	{
		if( (2*h_konj+c_konj)<(2*h_bistro+c_bistro) && (2*h_konj+c_konj)<(2*h_trovac+c_trovac) )
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 2*h_konj+c_konj );
		return 0;
			}
		else if( (2*h_bistro+c_bistro)<(2*h_konj+c_konj) && (2*h_bistro+c_bistro)<(2*h_trovac+c_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 2*h_bistro+c_bistro );
		else if ( (2*h_trovac+c_trovac)<(2*h_konj+c_konj) && (2*h_trovac+c_trovac)<(2*h_bistro+c_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 2*h_trovac+c_trovac );
		
		if(2*h_konj>c_konj)
		{
			A=(2*h_konj)*0.9+c_konj;
			if( (A<(2*h_konj+c_konj) ) && (A<(2*h_bistro+c_bistro) ) && (A<(2*h_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(c_konj>2*h_konj)
		{
			B=2*h_konj+c_konj*0.9;
			if( (B<(2*h_konj+c_konj) ) && (B<(2*h_bistro+c_bistro) ) && (B<(2*h_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
		
	}
	
	
	
	if( (bojan=='H' && tarik=='H' && mirza=='P') || (bojan=='H' && mirza=='H' && tarik=='P') || (mirza=='H' && tarik=='H' && bojan=='P') )                /*dva hamburgera i jedna pica*/
	{
		if( (2*h_konj+p_konj)<(2*h_bistro+p_bistro) && (2*h_konj+p_konj)<(2*h_trovac+p_trovac) )
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", 2*h_konj+p_konj );
		return 0;
			}
		else if( (2*h_bistro+p_bistro)<(2*h_konj+p_konj) && (2*h_bistro+p_bistro)<(2*h_trovac+p_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", 2*h_bistro+p_bistro );
		else if ( (2*h_trovac+p_trovac)<(2*h_konj+p_konj) && (2*h_trovac+p_trovac)<(2*h_bistro+p_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", 2*h_trovac+p_trovac );
		
		if(2*h_konj>p_konj)
		{
			A=(2*h_konj)*0.9+p_konj;
			if( (A<(2*h_konj+p_konj) ) && (A<(2*h_bistro+p_bistro) ) && (A<(2*h_trovac+p_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(p_konj>2*h_konj)
		{
			B=2*h_konj+p_konj*0.9;
			if( (B<(2*h_konj+p_konj) ) && (B<(2*h_bistro+p_bistro) ) && (B<(2*h_trovac+p_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
		
	}
	
	
	
	if( (bojan=='H' && tarik=='P' && mirza=='C') || (bojan=='H' && tarik=='C' && mirza=='P') || (bojan=='P' && tarik=='H' && mirza=='C') || (bojan=='P' && tarik=='C' && mirza=='H') || (bojan=='C' && tarik=='H' && mirza=='P') ||(bojan=='C' && tarik=='P' && mirza=='H') )
	{
		if( (h_konj+p_konj+c_konj)<(h_bistro+p_bistro+c_bistro) && (h_konj+p_konj+c_konj)<(h_trovac+p_trovac+c_trovac) )                      /*tri razlicita jela*/
			{
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", h_konj+p_konj+c_konj );
		return 0;
			}
		else if( (h_bistro+p_bistro+c_bistro)<(h_konj+p_konj+c_konj) && (h_bistro+p_bistro+c_bistro)<(h_trovac+p_trovac+c_trovac) )
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", h_bistro+p_bistro+c_bistro );
		else if ( (h_trovac+p_trovac+c_trovac)<(h_konj+p_konj+c_konj) && (h_trovac+p_trovac+c_trovac)<(h_bistro+p_bistro+c_bistro) )
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", h_trovac+p_trovac+c_trovac );
		
		if(h_konj>p_konj && h_konj>c_konj)
		{
			A=h_konj*0.9+p_konj+c_konj;
			if( (A<(h_konj+p_konj+c_konj)) && (A<(h_bistro+p_bistro+c_bistro) ) && (A<(h_trovac+p_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", A);
		}
		else if(p_konj>h_konj && p_konj>c_konj)
		{
			B=h_konj+p_konj*0.9+c_konj;
			if( (B<(h_konj+p_konj+c_konj) ) && (B<(h_bistro+p_bistro+c_bistro) ) && (B<(h_trovac+p_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", B);
		}
		else if(c_konj>h_konj && c_konj>p_konj)
		{
			C=h_konj+p_konj+c_konj*0.9;
			if( (C<(h_konj+p_konj+c_konj) ) && (C<(h_bistro+p_bistro+c_bistro) ) && (C<(h_trovac+p_trovac+c_trovac) ) )
			printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", C);
			
		}
		
		
	}
	return 0;
	
}
