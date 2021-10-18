#include <stdio.h>

int main() {
	char novi_red,m_izbor,t_izbor,b_izbor;
	double r_pizza=6.80,r_ham=3.30,r_cevap=5.00,ff_pizza=8.00,ff_ham=3.00,ff_cevap=3.90,b_pizza=5.30,b_ham=5.00,b_cevap=6.00;
	double r_cijena,ff_cijena,b_cijena;
	double r2_cijena;
	double min;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c",&t_izbor);
	scanf ("%c",&novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c",&b_izbor);
	scanf ("%c",&novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c",&m_izbor);
	if (m_izbor=='P' && t_izbor=='P' && b_izbor=='P')
	{
		r_cijena=3*r_pizza;
		ff_cijena=3*ff_pizza;
		b_cijena=3*b_pizza;
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
		{   r_pizza=(r_pizza*9)/10;
			r2_cijena=3*r_pizza;}

	}
	else if (m_izbor=='H' && t_izbor=='H' && b_izbor=='H')
	{
		r_cijena=3*r_ham;
		ff_cijena=3*ff_ham;
		b_cijena=3*b_ham; 
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
	   {r_ham=(9*r_ham)/10;	
	   	r2_cijena=3*r_ham;}
		
	}
	else if (m_izbor=='C' && t_izbor=='C' && b_izbor=='C')
	{
		r_cijena=3*r_cevap;
		ff_cijena=3*ff_cevap;
		b_cijena=3*b_cevap;
	    if (r_cijena<ff_cijena || r_cijena<b_cijena)
	    {   r_cevap=(r_cevap*9)/10;
	    	r2_cijena=3*r_cevap;}
	}
	else if ((m_izbor=='P' && t_izbor=='H' && b_izbor=='H') || (m_izbor=='H' && t_izbor=='P' && b_izbor=='H') || (m_izbor=='H' && t_izbor=='H' && b_izbor=='P'))
	{
		r_cijena=r_pizza+2*r_ham;
		ff_cijena=ff_pizza+2*ff_ham;
		b_cijena=b_pizza+2*b_ham; 
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
		{   if (r_pizza>2*r_ham)
		    r_pizza=(r_pizza*9)/10;
		    else 
		    r_ham=(r_ham*9)/10;
			r2_cijena=2*r_ham+r_pizza;}
	
 	}
	else if ((m_izbor=='P' && t_izbor=='C' && b_izbor=='C') || (m_izbor=='C' && t_izbor=='P' && b_izbor=='C') || (m_izbor=='C' && t_izbor=='C' &&b_izbor=='P'))
	{
		r_cijena=r_pizza+2*r_cevap;
		ff_cijena=ff_pizza+2*ff_cevap;
		b_cijena=b_pizza+2*b_cevap; 
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
		{	if (r_pizza>2*r_cevap)
		     r_pizza=(r_pizza*9/10);
		     else
		     r_cevap=(r_cevap*9)/10;
			r2_cijena=r_pizza+2*r_cevap;}
	
	}
	else if ((m_izbor=='H' && t_izbor=='P' && b_izbor=='P') || (m_izbor=='P' && t_izbor=='H' && b_izbor=='P') || (m_izbor=='P' && t_izbor=='P' && b_izbor=='H'))
	{
		r_cijena=r_ham+2*r_pizza;
		ff_cijena=ff_ham+2*ff_pizza;
		b_cijena=b_ham+2*b_pizza; 
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
		{   if (r_ham>2*r_pizza)
		    r_ham=(r_ham*9)/10;
		    else
		    r_pizza=(r_pizza*9)/10;
			r2_cijena=r_ham+2*r_pizza;}
	
	}
	else if ((m_izbor=='H' && t_izbor=='C' && b_izbor=='C') || (m_izbor=='C' && t_izbor=='H' && b_izbor=='C') || (m_izbor=='C' && t_izbor=='C' && b_izbor=='H'))
	{
		r_cijena=r_ham+2*r_cevap;
	    ff_cijena=ff_ham+2*ff_cevap;
		b_cijena=b_ham+2*b_cevap; 
		if (r_cevap<ff_cijena || r_cijena<b_cijena)
		{   if (r_ham>2*r_cevap)
		    r_ham=(r_ham*9)/10;
		    else
		    r_cevap=(r_cevap*9)/10;
			r2_cijena=r_ham+2*r_cevap;}
	
	}
	else if ((m_izbor=='C' && t_izbor=='P' && b_izbor=='P') || (m_izbor=='P' && t_izbor=='C' && b_izbor=='P') || (m_izbor=='P' && t_izbor=='P' && b_izbor=='C'))
	{
		r_cijena=r_cevap+2*r_pizza;
		ff_cijena=ff_cevap+2*ff_pizza;
		b_cijena=b_cevap+2*b_pizza; 
		if (r_cijena<ff_cijena)
		{   if (r_cevap>2*r_pizza)
		    r_cevap=(r_cevap*9)/10;
		    else
		    r_pizza=(r_pizza*9)/10;
			r2_cijena=r_cevap+2*r_pizza;}
	
	}
	else if ((m_izbor=='C' && t_izbor=='H' && b_izbor=='H') || (m_izbor=='H' && t_izbor=='C' && b_izbor=='H') || (m_izbor=='H' && t_izbor=='H' && b_izbor=='C'))
	{
		r_cijena=r_cevap+2*r_ham;
		ff_cijena=ff_cevap+2*ff_ham;
		b_cijena=b_cevap+2*b_ham; 
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
		{   if (r_cevap>2*r_ham)
		    r_cevap=(r_cevap*9)/10;
		    else
		    r_ham=(r_ham*9)/10;
			r2_cijena=r_cevap+2*r_ham;}
	
	}
	else if ((m_izbor=='C' && t_izbor=='P' && b_izbor=='H') || (m_izbor=='C' && t_izbor=='H' && b_izbor=='P') || (m_izbor=='H' && t_izbor=='P' && b_izbor=='C') || (m_izbor=='H' && t_izbor=='C' && b_izbor=='P') || (m_izbor=='P' && t_izbor=='H' && b_izbor=='C') || (m_izbor=='P' && t_izbor=='C' && b_izbor=='H'))
	{
		r_cijena=r_cevap+r_ham+r_pizza;
		ff_cijena=ff_cevap+ff_ham+ff_pizza;
		b_cijena=b_cevap+b_ham+b_pizza; 
		if (r_cijena<ff_cijena || r_cijena<b_cijena)
		{   if (r_pizza>r_cevap && r_pizza>r_ham)
		    r_pizza=(r_pizza*9)/10;
		    else if (r_ham>r_cevap && r_ham>r_pizza)
		    r_ham=(r_ham*9)/10;
		    else if (r_cevap>r_pizza && r_cevap>r_ham)
		    r_cevap=(r_cevap*9)/10;
			r2_cijena=r_cevap+r_ham+r_pizza;}
	}
	if (r_cijena<ff_cijena && r_cijena<b_cijena)
		{min=r_cijena;
		 printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",min);}
	else if (ff_cijena<r_cijena && ff_cijena<b_cijena)
		{min=ff_cijena;
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",min);}
	else if (b_cijena<r_cijena && b_cijena<ff_cijena)
		{min=b_cijena;
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",min);}
	if (r2_cijena<min && min!=r_cijena)
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",r2_cijena);
	
	return 0;
}
