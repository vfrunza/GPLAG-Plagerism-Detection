#include <stdio.h>

int main ()
{
	float a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,e1,e2,e3,o1,o2,o3,z1,z2,z3;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&a1);
	if(a1<=20 && a1>=0)
	{
	printf("II parcijalni ispit: ");
	scanf("%f",&b1);
	if(b1<=20 && b1>=0)
	{
	printf("Prisustvo: ");
	scanf("%f",&c1);
	if(c1<=10 && c1>=0)
	{
	printf("Zadace: ");
	scanf("%f",&d1);
	if(d1<=10 && d1>=0)
	{
	printf("Zavrsni ispit: ");
	scanf("%f",&e1);
	if(e1<=55 && e1>=0)
	{
	o1=a1+b1+c1+d1+e1;
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&a2);
	if(a2<=20 && a2>=0)
	{
	printf("II parcijalni ispit: ");
	scanf("%f",&b2);
	if(b2<=20 && b2>=0)
	{
	printf("Prisustvo: ");
	scanf("%f",&c2);
	if(c2<=10 && c2>=0)
	{
	printf("Zadace: ");
	scanf("%f",&d2);
	if(d2<=10 && d2>=0)
	{
	printf("Zavrsni ispit: ");
	scanf("%f",&e2);
	if(e2<=55 && e2>=0)
	{
	o2=a2+b2+c2+d2+e2;
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&a3);
	if(a3<=20 || a3>=0)
	{
	printf("II parcijalni ispit: ");
	scanf("%f",&b3);
	if(b3<=20 && b3>=0)
	{
	printf("Prisustvo: ");
	scanf("%f",&c3);
	if(c3<=10 && c3>=0)
	{
	printf("Zadace: ");
	scanf("%f",&d3);
	if(d3<=10 && d3>=0)
	{
	printf("Zavrsni ispit: ");
	scanf("%f",&e3);
	if(e3<=55 && e3>=0)
	{
		o3=a3+b3+c3+d3+e3;
		if(((o1-55)<-0.001) && ((o2-55)<-0.001) && ((o3-55)<-0.001))
		{
			printf("Nijedan student nije polozio.");
		} else if((((o1-55)<-0.001) && ((o2-55)<-0.001))||(((o1-55)<-0.001) && ((o3-55)<-0.001))||(((o2-55)<-0.001) && ((o3-55)<-0.001)))
		{
				printf("Jedan student je polozio.");
		} else if(((o1-55)<-0.001) || ((o2-55)<-0.001) ||((o3-55)<-0.001))
		{
					printf("Dva studenta su polozila.");
		} else
		{
			if((o1-65)<-0.001)
			{
				z1=6;
			} else if((o1-75)<-0.001)
			{
				z1=7;
			} else if((o1-85)<-0.001)
			{
				z1=8;
			} else if((o1-92)<-0.001)
			{
				z1=9;
			} else
			{
				z1=10;
			}
			if((o2-65)<-0.001)
			{
				z2=6;
			} else if((o2-75)<-0.001)
			{
				z2=7;
			} else if((o2-85)<-0.001)
			{
				z2=8;
			} else if((o2-92)<-0.001)
			{
				z2=9;
			} else
			{
				z2=10;
			}
			if((o3-65)<-0.001)
			{
				z3=6;
			} else if((o3-75)<-0.001)
			{
				z3=7;
			} else if((o3-85)<-0.001)
			{
				z3=8;
			} else if((o3-92)<-0.001)
			{
				z3=9;
			} else
			{
				z3=10;
			}
			printf("Sva tri studenta su polozila.\n");
			if (z1==z2 && z1==z3 && z2==z3)
			{
				printf("Sva tri studenta imaju istu ocjenu.");
			} else if(z1==z2 || z2==z3 || z1==z3)
			{
				printf("Dva od tri studenta imaju istu ocjenu.");
			} else 
			{
				printf("Svaki student ima razlicitu ocjenu.");
			}
		}
			}
		}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	} else
	{
		printf("Neispravan broj bodova");	
	}
	return 0;
}