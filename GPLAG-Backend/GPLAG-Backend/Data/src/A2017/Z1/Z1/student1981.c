#include <stdio.h>

int main() {
   double  tp1,tp2,tpr,tzd,tzi,bp1,bp2,bpr,bzd,bzi,mp1,mp2,mpr,mzd,mzi;
   printf("Unesite bodove za Tarika:");
    printf("\nI parcijalni ispit: ");
	scanf("%lf", &tp1);
	if(tp1<0 || tp1>20)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("II parcijalni ispit: ");
	scanf("%lf",&tp2);
	if(tp2<0 || tp2>20)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Prisustvo: ");
	scanf("%lf",&tpr);
	if(tpr<0 || tpr>10)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zadace: ");
	scanf("%lf",&tzd);
	if( tzd<0 || tzd>10)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zavrsni ispit: ");
	scanf("%lf",&tzi);
	if( tzi<0 || tzi>40)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Unesite bodove za Bojana:");
    printf("\nI parcijalni ispit: ");
	scanf("%lf", &bp1);
	if(bp1<0 || bp1>20)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("II parcijalni ispit: ");
	scanf("%lf",&bp2);
	if(bp2<0 || bp2>20)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Prisustvo: ");
	scanf("%lf",&bpr);
	if(bpr<0 || bpr>10)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zadace: ");
	scanf("%lf",&bzd);
	if(bzd<0 || bzd>10)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zavrsni ispit: ");
	scanf("%lf",&bzi);
	if( bzi<0 || bzi>40)
{	printf("Neispravan broj bodova");
	return 0;
}
    printf("Unesite bodove za Mirzu:");
    printf("\nI parcijalni ispit: ");
	scanf("%lf", &mp1);
	if( mp1<0 || mp1>20)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("II parcijalni ispit: ");
	scanf("%lf",&mp2);
	if( mp2<0 || mp2>20)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Prisustvo: ");
	scanf("%lf",&mpr);
	if(mpr<0 || mpr>10)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zadace: ");
	scanf("%lf",&mzd);
	if( mzd<0 || mzd>10)
{	printf("Neispravan broj bodova");
	return 0;
}
	printf("Zavrsni ispit: ");
	scanf("%lf",&mzi);
	 if(  mzi<0 || mzi>40) 
{	printf("Neispravan broj bodova");
return 0;
	
}
	
else
{
	
 float uk1=0.0,uk2=0.0,uk3=0.0;
    uk1=tp1+tp2+tpr+tzd+tzi;
	uk2=bp1+bp2+bpr+bzd+bzi;
	uk3=mp1+mp2+mpr+mzd+mzi;

	if(uk1<55 && uk2<55 && uk3<55)
     	printf("Nijedan student nije polozio.");
	else    if((uk1<55 && uk2>55 && uk3>55) || (uk1>55 && uk2<55 && uk3>55) || (uk1>55 && uk2>55 && uk3<55))
    	printf("Dva studenta su polozila.");
	else    if((uk1>=55 && uk2<55 && uk3<55) || (uk1<55 && uk2>=55 && uk3<55) || (uk1<55 && uk2<55 && uk3>=55))
    	printf("Jedan student je polozio.");
	else
	{    if(uk1>55 && uk2>55 && uk3>55)
    	printf("Sva tri studenta su polozila.");
          
   	if(uk1>=55 && uk1<65 && uk2>=55 && uk2<65 && uk3>=55 && uk3<65)
    	printf("\nSva tri studenta imaju istu ocjenu.");
    else	if(uk1>=65 && uk1<75 && uk2>=65 && uk2<75 && uk3>=65 && uk3<75)
    	printf("\nSva tri studenta imaju istu ocjenu.");
    else	if(uk1>=75 && uk1<85 && uk2>=75 && uk2<85 && uk3>=75 && uk3<85)
    	printf("\nSva tri studenta imaju istu ocjenu.");
    else	if(uk1>=85 && uk1<92 && uk2>=85 && uk2<92 && uk3>=85 && uk3<92)
    	printf("\nSva tri studenta imaju istu ocjenu.");
    else	if(uk1>=92 && uk1<100 && uk2>=92 && uk2<100 && uk3>=92 && uk3<100)
    	printf("\nSva tri studenta imaju istu ocjenu.");
    else	if(uk1>=55 && uk1<65 && uk2>=55 && uk2<65 && uk3>=65)  
    	printf("\nDva od tri studenta imaju istu ocjenu.");
	else    if(uk1>=55 && uk1<65 && uk3>=55 && uk3<65 && uk2>=65)
     	printf("\nDva od tri studenta imaju istu ocjenu.");
    else	if((uk1>=65 && uk1<75 && uk2>=65 && uk2<75) && (uk3>=75 || uk3<65)) 
    	printf("\nDva od tri studenta imaju istu ocjenu.");
    else    if((uk1>=65 && uk1<75 && uk3>=65 && uk3<75) &&( uk2>=75 || uk2<65))
        printf("\nDva od tri studenta imaju istu ocjenu.");
	else	if((uk1>=75 && uk1<85 && uk2>=75 && uk2<85) && (uk3>=85 || uk3<75))  
    	printf("\nDva od tri studenta imaju istu ocjenu.");
	else    if((uk1>=75 && uk1<85 && uk3>=75 && uk3<85) && (uk2>=85 || uk2<75))
    	printf("\nDva od tri studenta imaju istu ocjenu.");
    else	if((uk1>=85 && uk1<92 && uk2>=85 && uk2<92) && (uk3>=92|| uk3<85) )  
    	printf("\nDva od tri studenta imaju istu ocjenu.");	
    else    if((uk1>=85 && uk1<92 && uk3>=85 && uk3<92) && (uk2>=92 || uk2<85))
        printf("\nDva od tri studenta imaju istu ocjenu.");	
    else	if(uk1>=92 && uk1<=100 && uk2>=92 && uk2<=100 && uk3<92) 
    	printf("\nDva od tri studenta imaju istu ocjenu.");	
	else    if (uk1>=92 && uk1<=100 && uk3>=92 && uk3<=100 &&  uk2<92)
     	printf("\nDva od tri studenta imaju istu ocjenu.");
    else	if(uk2>=55 && uk2<65 && uk3>=55 && uk3<65 && uk1>=65)  
    	printf("\nDva od tri studenta imaju istu ocjenu.");
    else	if((uk2>=65 && uk2<75 && uk3>=65 && uk3<75) && (uk1>=75 || uk1<65)) 
    	printf("\nDva od tri studenta imaju istu ocjenu.");
	else	if((uk2>=75 && uk2<85 && uk3>=75 && uk3<85) && (uk1>=85 || uk1<75))  
    	printf("\nDva od tri studenta imaju istu ocjenu.");
    else	if((uk2>=85 && uk2<92 && uk3>=85 && uk3<92) && (uk1>=92|| uk1<85) )  
    	printf("\nDva od tri studenta imaju istu ocjenu.");	
    else	if(uk3>=92 && uk3<=100 && uk2>=92 && uk2<=100 && uk1<92) 
    	printf("\nDva od tri studenta imaju istu ocjenu.");	
    else    
        printf("\nSvaki student ima razlicitu ocjenu.");  

		
	}
		
	
}



	return 0;
}
