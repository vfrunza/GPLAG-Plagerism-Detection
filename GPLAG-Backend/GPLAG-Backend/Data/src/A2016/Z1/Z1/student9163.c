#include <stdio.h>
#include <math.h>
#define EPS 0.001
int main() {
	float Ipt,IIpt,pt,zt,kt,Ipb,IIpb,pb,zb,kb,Ipm,IIpm,pm,zm,km,t,b,m;
	int oc1=0,oc2=0,oc3=0;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Ipt);
	if(Ipt<0 || Ipt>20)
	{printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIpt);
	if(IIpt<0 || IIpt>20)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&pt);
	if(pt<0 || pt>10)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&zt);
	if(zt<0 || zt>10)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&kt);
	if(kt<0 || kt>40)
	{printf("Neispravan broj bodova"); return 0;}
    t=Ipt+IIpt+pt+zt+kt; 
    printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Ipb);
	if(Ipb<0 || Ipb>20)
	{printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIpb);
	if(IIpb<0 || IIpb>20)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&pb);
	if(pb<0 || pb>10)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&zb);
	if(zb<0 || zb>10)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&kb);
	if(kb<0 || kb>40)
	{printf("Neispravan broj bodova"); return 0;}
	b=Ipb+IIpb+pb+zb+kb;
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&Ipm);
	if(Ipm<0 || Ipm>20)
	{printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIpm);
	if(IIpm<0 || IIpm>20)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%f",&pm);
	if(pm<0 || pm>10)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f",&zm);
	if(zm<0 || zm>10)
	{printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&km);
	if(km<0 || km>40)
	{printf("Neispravan broj bodova"); return 0;}
	m=Ipm+IIpm+pm+zm+km;
	 
    if (fabs(t+EPS)<55)                 oc1=5;
    else if(fabs(t+EPS)>=55 && fabs(t+EPS)<65)  oc1=6;
    else if(fabs(t+EPS)>=65 && fabs(t+EPS)<75)  oc1=7;
    else if(fabs(t+EPS)>=75 && fabs(t+EPS)<85)  oc1=8;
    else if(fabs(t+EPS)>=85 && fabs(t+EPS)<92)  oc1=9;
    else if(fabs(t+EPS)>=92 && fabs(t+EPS)<=100) oc1=10;
    
    if(fabs(b+EPS)<55)                         oc2=5;
    else if(fabs(b+EPS)>=55 && fabs(b+EPS)<65)  oc2=6;
    else if(fabs(b+EPS)>=65 && fabs(b+EPS)<75)  oc2=7;
    else if(fabs(b+EPS)>=75 && fabs(b+EPS)<85)  oc2=8;
    else if(fabs(b+EPS)>=85 && fabs(b+EPS)<92)  oc2=9;
    else if(fabs(b+EPS)>=92 && fabs(b+EPS)<=100) oc2=10;
    
    if(fabs(m+EPS)<55)                         oc3=5;
    else if(fabs(m+EPS)>=55 && fabs(m+EPS)<65)  oc3=6;
    else if(fabs(m+EPS)>=65 && fabs(m+EPS)<75)  oc3=7;
    else if(fabs(m+EPS)>=75 && fabs(m+EPS)<85)  oc3=8;
    else if(fabs(m+EPS)>=85 && fabs(m+EPS)<92)  oc3=9;
    else if(fabs(m+EPS)>=92 && fabs(m+EPS)<=100) oc3=10;
    
    
    if(oc1==5 && oc2==5 && oc3==5)     printf("Nijedan student nije polozio.");
    else if(oc1>5 && oc2>5 && oc3>5)  
     {
     	printf("Sva tri studenta su polozila.\n");
     	if(oc1==oc2 && oc1==oc3) printf("Sva tri studenta imaju istu ocjenu.");
     	else if(oc1!=oc2 && oc2!=oc3 && oc1!=oc3) printf("Svaki student ima razlicitu ocjenu.");
     	else if(oc1==oc2 && oc1!=oc3) printf("Dva od tri studenta imaju istu ocjenu.");
     	else if(oc1==oc3 && oc1!=oc2) printf("Dva od tri studenta imaju istu ocjenu.");
     	else if(oc2==oc3 && oc2!=oc1) printf("Dva od tri studenta imaju istu ocjenu.");
     }
    else if (oc1>5 && oc2==5 && oc3==5)printf("Jedan student je polozio.");
    else if(oc1>5 && oc2>5 &&  oc3==5) printf("Dva studenta su polozila.");
    else if(oc1>5 && oc2==5 && oc3>=5) printf("Dva studenta su polozila.");
    else if(oc1==5 && oc2>5 && oc3>=5) printf("Dva studenta su polozila.");
    else if(oc1==5 && oc2==5 && oc3>5) printf("Jedan student je polozio.");
    else if(oc1==5 && oc2>5 && oc3==5) printf("Jedan student je polozio.");
    
    	return 0;
}
