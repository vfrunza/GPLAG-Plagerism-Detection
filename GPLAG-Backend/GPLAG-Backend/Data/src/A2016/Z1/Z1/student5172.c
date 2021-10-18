#include <stdio.h>

int main()
{ 
	double I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB,I_parcM,II_parcM,PrisustvoM,ZadaceM,ZavrsniM,BodoviT,BodoviB,BodoviM;
	
	scanf("%lf",&I_parcT);
	if(I_parcT<0 || I_parcT>20)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: Neispravan broj bodova");
	    return 0;
	}
		scanf("%lf",&II_parcT);
	    if(II_parcT<0 || II_parcT>20)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&PrisustvoT);
	if(PrisustvoT<0 || PrisustvoT>10)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&ZadaceT);
	if(ZadaceT<0 || ZadaceT>10)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&ZavrsniT);
	if(ZavrsniT<0 || ZavrsniT>40)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Neispravan broj bodova");
	    return 0;
	}
	
	
	
	
	
	
    
    	scanf("%lf",&I_parcB);
	if(I_parcB<0 || I_parcB>20)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: Neispravan broj bodova");
	    return 0;
	}
		scanf("%lf",&II_parcB);
	if(II_parcB<0 || II_parcB>20)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&PrisustvoB);
	if(PrisustvoB<0 || PrisustvoB>10)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&ZadaceB);
	if(ZadaceB<0 || ZadaceB>10)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&ZavrsniB);
	if(ZavrsniB<0 || ZavrsniB>40)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Neispravan broj bodova");
	    return 0;
	}
	
	
	
	
	
		scanf("%lf",&I_parcM);
	if(I_parcM<0 || I_parcM>20)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: Neispravan broj bodova");
	    return 0;
	}
		scanf("%lf",&II_parcM);
	if(II_parcM<0 || II_parcM>20)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&PrisustvoM);
	if(PrisustvoM<0 || PrisustvoM>10)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&ZadaceM);
	if(ZadaceM<0 || ZadaceM>10)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Neispravan broj bodova");
	    return 0;
	}
	scanf("%lf",&ZavrsniM);
	if(ZavrsniM<0 || ZavrsniM>40)
	{
	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Neispravan broj bodova");
	    return 0;
	}







   if(I_parcT<=20 && I_parcT>=0 && II_parcT<=20 && II_parcT>=0 && PrisustvoT<=10 && PrisustvoT>=0 && ZadaceT<=10 && ZadaceT>=0 && ZavrsniT<=40 && ZavrsniT>=0 && I_parcB<=20 && I_parcB>=0 && II_parcB<=20 && II_parcB>=0 && PrisustvoB<=10 && PrisustvoB>=0 && ZadaceB<=10 && ZadaceB>=0 && ZavrsniB<=40 && ZavrsniB>=0 && I_parcM<=20 && I_parcM>=0 && II_parcM<=20 && II_parcM>=0 && PrisustvoM<=10 && PrisustvoM>=0 && ZadaceM<=10 && ZadaceM>=0 && ZavrsniM<=40 && ZavrsniM>=0)
    {
    	BodoviT=I_parcT+II_parcT+PrisustvoT+ZadaceT+ZavrsniT;
        BodoviB=I_parcB+II_parcB+PrisustvoB+ZadaceB+ZavrsniB;
    	BodoviM=I_parcM+II_parcM+PrisustvoM+ZadaceM+ZavrsniM;
    
    	if(BodoviT<55 && BodoviM<55 && BodoviB<55)
    	{
    		printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Nijedan student nije polozio.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB,I_parcM,II_parcM,PrisustvoM,ZadaceM,ZavrsniM);
    	}
    	else if(BodoviT>=55 && BodoviM<55 && BodoviB<55)
    	{
    		printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Jedan student je polozio.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB);
    	}
    	else if(BodoviT<55 && BodoviM<55 && BodoviB>=55)
    	{
      printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Jedan student je polozio.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB);
     }
    	else if(BodoviT<55 && BodoviM>=55 && BodoviB<55)
    	{
    		printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Jedan student je polozio.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB);
    	}
    	else if(BodoviT>=55 && BodoviM>=55 && BodoviB<55)
    	{
    	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Dva studenta su polozila.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB,I_parcM,II_parcM,PrisustvoM,ZadaceM,ZavrsniM);
    	}
    	else if(BodoviT>=55 && BodoviM<55 && BodoviB>=55)
    	{
    	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Dva studenta su polozila.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB,I_parcM,II_parcM,PrisustvoM,ZadaceM,ZavrsniM);
    	}
    	else if(BodoviT<55 && BodoviM>=55 && BodoviB>=55)
    	{
    	    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Dva studenta su polozila.",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB,I_parcM,II_parcM,PrisustvoM,ZadaceM,ZavrsniM);
    	}
    	else if(BodoviT>=55 && BodoviM>=55 && BodoviB>=55)
    	{
    		    printf("Unesite bodove za Tarika:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Bojana:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Unesite bodove za Mirzu:\nI parcijalni ispit: II parcijalni ispit: Prisustvo: Zadace: Zavrsni ispit: Sva tri studenta su polozila.\n",I_parcT,II_parcT,PrisustvoT,ZadaceT,ZavrsniT,I_parcB,II_parcB,PrisustvoB,ZadaceB,ZavrsniB,I_parcM,II_parcM,PrisustvoM,ZadaceM,ZavrsniM);
    		
    		if(BodoviT>=55 && BodoviT<=65 && BodoviB>=55 && BodoviB<=65 && BodoviM>=55 && BodoviM<=65)
    		{
    			printf("Sva tri studenta imaju istu ocjenu.\n");
    		}
    		else if(BodoviT>65 && BodoviT<=75 && BodoviB>65 && BodoviB<=75 && BodoviM>65 && BodoviM<=75)
    		{
    			printf("Sva tri studenta imaju istu ocjenu.\n");
    		}
    		else if(BodoviT>75 && BodoviT<=85 && BodoviB>75 && BodoviB<=85 && BodoviM>75 && BodoviM<=85)
    		{
    			printf("Sva tri studenta imaju istu ocjenu.\n");
    		}
    		else if(BodoviT>85 && BodoviT<=92 && BodoviB>85 && BodoviB<=92 && BodoviM>85 && BodoviM<=92)
    		{
    			printf("Sva tri studenta imaju istu ocjenu.\n");
    		}
    		else if(BodoviT>92 && BodoviT<=100 && BodoviB>92 && BodoviB<=100 && BodoviM>92 && BodoviM<=100)
    		{
    			printf("Sva tri studenta imaju istu ocjenu.\n");
    		}
    		else if(BodoviT>=55 && BodoviT<=65 && BodoviB>=55 && BodoviB<=65 && BodoviM>65)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>=55 && BodoviT<=65 && BodoviB>65 && BodoviM>=55 && BodoviM<=65)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>65 && BodoviB>=55 && BodoviB<=65 && BodoviM>=55 && BodoviM<=65)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		
      else if(BodoviT>65 && BodoviT<=75 && BodoviB>65 && BodoviB<=75 && BodoviM>75 && BodoviM<=65)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>65 && BodoviT<=75 && BodoviB>75 && BodoviB<=65 && BodoviM>65 && BodoviM<=75)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>75 && BodoviT<=65 && BodoviB>65 && BodoviB<=75 && BodoviM>65 && BodoviM<=75)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		
    	 else if(BodoviT>75 && BodoviT<=85 && BodoviB>75 && BodoviB<=85 && BodoviM>85 && BodoviM<=75)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>75 && BodoviT<=85 && BodoviB>85 && BodoviB<=75 && BodoviM>75 && BodoviM<=85)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>85 && BodoviT<=75 && BodoviB>75 && BodoviB<=85 && BodoviM>75 && BodoviM<=85)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		
    		else if(BodoviT>85 && BodoviT<=92 && BodoviB>85 && BodoviB<=92 && BodoviM>92 && BodoviM<=85)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>85 && BodoviT<=92 && BodoviB>92 && BodoviB<=85 && BodoviM>85 && BodoviM<=92)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>92 && BodoviT<=85 && BodoviB>85 && BodoviB<=92 && BodoviM>85 && BodoviM<=92)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		
      else if(BodoviT>92 && BodoviT<=100 && BodoviB>92 && BodoviB<=100 && BodoviM<=92)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT>92 && BodoviT<=100 && BodoviB<=92 && BodoviM>92 && BodoviM<=100)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		else if(BodoviT<=92 && BodoviB>92 && BodoviB<=100 && BodoviM>92 && BodoviM<=100)
    		{
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		}
    		
    		 else
    		{
    			printf("Svaki student ima razlicitu ocjenu.");
    		}
    	}
    	
    }
 
   
 return 0;
}
