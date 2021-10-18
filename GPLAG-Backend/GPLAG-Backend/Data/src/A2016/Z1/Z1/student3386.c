#include <stdio.h>
#include <math.h>
#define eps 0.001
int main() {
	float tO,bO,mO,t,b,m,prpT,prpB,prpM,drpT,drpB,drpM,pT,pB,pM,zT,zB,zM,zavrT,zavrB,zavrM;

	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&prpT);
	if(prpT<0 || prpT>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&drpT);
	if(drpT<0 || drpT>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pT);
	if(pT<0 || pT>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zT);
	if(zT<0 || zT>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zavrT);
	if(zavrT<0 || zavrT>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
		printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&prpB);
	if(prpB<0 || prpB>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&drpB);
	if(drpB<0 || drpB>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pB);
	if(pB<0 || pB>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zB);
	if(zB<0 || zB>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zavrB);
	if(zavrB<0 || zavrB>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
			printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&prpM);
	if(prpM<0 || prpM>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&drpM);
	if(drpM<0 || drpM>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&pM);
	if(pM<0 || pM>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zM);
	if(zM<0 || zM>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zavrM);
	if(zavrM<0 || zavrM>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	
	
	
	t=prpT+drpT+pT+zT+zavrT;
	b=prpB+drpB+pB+zB+zavrB;
	m=prpM+drpM+pM+zM+zavrM;
		
		if( t>=(55-eps) && (t<65-eps) )
		tO=6;
		else if( ( t>=65-eps) && (t<75-eps ) )
		tO=7;
		else if( (t>=75-eps) && (t<85-eps) )
		tO=8;
		else if( (t>=85-eps) && (t<92-eps) )
		tO=9;
		else if( (t>=92-eps) && (t<=100-eps) )
		tO=10;
	
		if( (b>=55-eps) && (b<65-eps) )
		bO=6;
		else if( (b>=65-eps) && (b<75-eps) )
		bO=7;
		else if( (b>=75-eps) && (b<85-eps) )
		bO=8;
		else if( (b>=85-eps) && (b<92-eps) )
		bO=9;
		else if( (b>=92-eps) && (b<=100-eps) )
		bO=10;
	
		if( (m>=55-eps) && (m<65-eps) )
		mO=6;
		else if( (m>=65-eps) && (m<75-eps) )
		mO=7;
		else if( (m>=75-eps) && (m<85-eps) )
		mO=8;
		else if( (m>=85-eps) && (m<92-eps) )
		mO=9;
		else if( (m>=92-eps) && (m<=100-eps) )
		mO=10;
	
	if( (t<55-eps) && (b<55-eps) && (m<55-eps) )
	
		printf("Nijedan student nije polozio.");
	
	else if( (t>=55-eps) && (b>=55-eps) && (m>=55-eps) )
	{
		printf("Sva tri studenta su polozila.\n");
		if( (fabs(tO-bO)<eps) && (fabs(bO-mO)<eps) )
			printf("Sva tri studenta imaju istu ocjenu.");
		else if( (tO!=bO) && (bO!=mO) && (tO!=mO) )
			printf("Svaki student ima razlicitu ocjenu.");
		else if ( (fabs(tO-bO)<eps) || (fabs(tO-mO)<eps) || (fabs(bO-mO))<eps )
			printf("Dva od tri studenta imaju istu ocjenu.");
		
	}
	else if( ( (t<55-eps)&&(b>=55-eps)&&(m>=55-eps) ) || ( (b<55-eps)&&(t>=55-eps)&&(m>=55-eps) ) || ( (m<55-eps)&&(b>=55-eps)&&(t>=55-eps) ) )
	
		printf("Dva studenta su polozila.");
	
	else if( ( (t>=55-eps)&&(b<55-eps)&&(m<55-eps) ) || ( (b>=55-eps)&&(t<55-eps)&&(m<55-eps) ) || ( (m>=55-eps)&&(b<55-eps)&&(t<55-eps) ) )
	
		printf("Jedan student je polozio.");
	return 0;
}




