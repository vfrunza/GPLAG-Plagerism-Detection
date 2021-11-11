#include <stdio.h>
int main() 
{
char tarik;
char bojan;
char mirza;
char novi_red;
double s1=0, s2=0,s3=0, s;
double p1 = 6.8, p2=8,p3=5.3;
double h1=3.3 ,h2=3  , h3=5;
double c1=5 ,c2=3.9 , c3=6 ;
printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red); 
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
		printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

switch (tarik == 'p')
{ 
	case 1:
		if ((bojan == 'p') && (mirza == 'p'))
		{
			s1=3*p1;
			s=s1;
			s2=3*p2;
			s3=3*p3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=3*0.9*p1;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	 	}		
break;
	case 2:
		if (((bojan == 'p') && (mirza == 'h')) || ((bojan == 'h') && (mirza == 'p')))
		{
			s1=2*p1+h1;
			s=s1;
			s2=2*p2+h2;
			s3=2*p3+h3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*p1 + 0.9*h1 ;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		}		
break;
	case 3:
		if ((bojan == 'h') && (mirza == 'h'))
		{
			s1=2*h1 + p1;
			s=s1;
			s2=2*h2 + p2;
			s3=2*h3 + p3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*h1 + p1*0.9;
				if (s1 < s2 && s1 < s3)
					{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
		}
break;
	case 4:
		if (((bojan == 'p' && mirza == 'c')) || ((bojan == 'c') && (mirza == 'p')))
		{
			s1=2*p1+c1;
			s=s1;
			s2=2*p2+c3;
			s3=2*p3+c3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*p1 + c1*0.9;
				if (s1 < s2 && s1 < s3)
				{	printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		}
break;
	case 5:
		if((bojan == 'c') && (mirza == 'c'))
		{
			s1=2*c1+p1;
			s=s1;
			s2=2*c2+p2;
			s3=2*c3+p3;
			
			if ((s1 > s2) || (s1>s3))
				{
					
					s1=2*c1 + p1*0.9;
					if (s1 < s2 && s1 < s3)
					{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
					}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		}
break;
	case 6:
		if (((bojan == 'h') && (mirza == 'c')) || ((bojan == 'h') && (mirza == 'c')))
		{
			s1=p1+c1+h1;
			s=s1;
			s2=p2+h2+c3;
			s3=h3+p3+c3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=h1 + p1*0.9 + c1;
				if (s1 < s2 && s1 < s3)
				{	printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		}
break;
}
switch (tarik == 'h')
{ 
	case 1: if ((bojan == 'p') && (mirza == 'p'))
	{
			s1=2*p1+h1;
			s=s1;
			s2=2*p2+h2;
			s3=2*p3+h3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=h1*0.9 + 2*p1;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	}
break;	
	case 2:
	if ((bojan == 'h') && (mirza == 'h'))
	{
			s1=2*h1 + p1;
			s=s1;
			s2=2*h2 + p2;
			s3=2*h3 + p3;
			
			if (s1 > s2 || s1>s3)
				{
				s1=2*h1 + h1*0.9;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
	}
break;		
	case 3:
	if (((bojan == 'h') && (mirza == 'p'))||((bojan == 'p')&&(mirza == 'h')))
	{
			s1=2*h1+p1;
			s=s1;
			s2=2*h2+p2;
			s3=2*h3+p3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*h1 + 0.9*p1;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
	}
break;
	case 4: 
	if (((bojan == 'h') && (mirza == 'c')) || ((bojan == 'c') && (mirza == 'h')))
	{
			s1=p1+h1+c1;
			s=s1;
			s2=p2+h2+c2;
			s3=p3+h3+c3;
			
			if (s1 > s2 || s1>s3)
				{
				s1=c1 + p1*0.9 + h1;
				if (s1 < s2 && s1 < s3)
				{	
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
	}
break;
	case 5: 
	if ((bojan == 'c') && (mirza == 'c'))
	{
			s1=2*c1+p1;
			s=s1;
			s2=2*c2+p2;
			s3=2*c3+p3;
			
			if (s1 > s2 || s1>s3)
				{
				s1=2*c1 + h1*0.9;
				if (s1 < s2 && s1 < s3)
				{	
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	}
break;	
	case 6: 
	if (((bojan == 'h') && (mirza == 'c')) || ((bojan == 'c') && (mirza == 'h')))
	{
			s1=2*h1+c1;
			s=s1;
			s2=2*h2+c2;
			s3=2*h3+c3;
			
			if (s1 > s2 || s1>s3)
			{
			s1=2*h1 + c1*0.9;
				if (s1 < s2 && s1 < s3)
				{	
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
	}
break;
}
switch (tarik == 'c')
{ 
	case 1: 
	if ((bojan == 'p') && (mirza == 'p'))
	{
			s1=2*p1+c1;
			s=s1;
			s2=2*p2+c3;
			s3=2*p2+c3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*p1 + h1*0.9;
				if (s1 < s2 && s1 < s3)
				{
					s1=2*c1 + p1*0.9;
					if (s1 < s2 && s1 < s3)
					{
						printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
						printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					}
				}	
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	}		
break;
	case 2:
	if (((bojan == 'p') && (mirza == 'h')) || ((bojan == 'h') && (mirza == 'p')))
	{
			s1=p1+h1+c1;
			s=s1;
			s2=p2+h2+c2;
			s3=p3+h3+c3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=c1 + p1*0.9 + h1;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}			
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	}		
break;	
	case 3:
	if ((bojan == 'h') && (mirza == 'h'))
	{
			s1=2*h1 + c1;
			s=s1;
			s2=2*h2 + c2;
			s3=2*h3 + c3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*h1 + c1*0.9;
				if (s1 < s2 && s1 < s3)
				{	
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
	}
break;	
	case 4: 
	if (((bojan == 'p') && (mirza == 'c')) || ((bojan == 'c') && (mirza == 'p')))
	{
			s1=2*c1+p1;
			s=s1;
			s2=2*c2+p3;
			s3=2*c3+p3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*c1 + p1*0.9;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
	 				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	}
break;
	case 5: if((bojan == 'c') && (mirza == 'c'))
	{
			s1=3*c1;
			s=s1;
			s2=3*c2;
			s3=3*c3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*c1+c1*0.9;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
	}
break;
	case 6: if (((bojan == 'h') && (mirza == 'c')) || ((bojan == 'c') && (mirza == 'h')))
	{
			s1=2*c1+h1;
			s=s1;
			s2=2*c2+h2;
			s3=2*c3+h3;
			
			if (s1 > s2 || s1>s3)
			{
				s1=2*c1 + h1*0.9;
				if (s1 < s2 && s1 < s3)
				{
					printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2fc KM)", s);
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
					
				}
				else if (s2 < s3)
				{
					printf("Najjeftiniji je Fast-food \"Trovač\": (%.2f KM)", s2);
				}
				else if (s3 < s2)
				{
					printf("Najjeftiniji je Bistro \"Lorelei\": (%.2f KM)", s3);
				}
			}
			else
			{
				printf("Najjeftiniji je Restoran \"Kod konja i konjušara\": (%.2f KM)", s);
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", s1);
			}
		
	}
break; 
}

return 0;
}
