#include <stdio.h>
#include <math.h>
#define pi atan(1)*4

int main() {
	double x1,x2,x3,y1,y2,y3,d1,d2,d3;
	double ugao;
	int st,m,s,mpomocni,mpomocni1;
	double najveca,dr,tr;
	double epsilon=0.01;
	//Unos kordinata tacaka:
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	//Odredzivanje duzina stranica trogla
	     d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	     d2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	     d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	     
	//Provjera koja je najveca stranica trougla.
	if(d1>d2 & d1>d3)
  {najveca=d1; dr=d2; tr=d3;}
  else if (d2>d1 && d2>d3)
  {najveca=d2; dr=d1; tr=d3;}
  else{najveca=d3; dr=d1; tr=d2;}
  //Odredzivanje najveceg ugla trougla koji se nalazi naspram najvece stranice.
         ugao=acos((dr*dr+tr*tr-najveca*najveca)/(2*dr*tr));
         ugao=ugao*180;
         ugao=ugao/pi;
         if(fabs(ugao-90)<epsilon)//ugao==90
         printf("Pravougli\n");
         st=(int)ugao;
         mpomocni=(ugao-st)*3600;
         (int)mpomocni;
         m=mpomocni/60;
         s=(ugao-st)*3600;
         (int)s;  
         s%=60;
        
//Provjera koji je trougao u pitanju.

if(fabs(d1-d2)<epsilon && fabs(d2-d3)<epsilon && fabs(d1-d3)<epsilon)//d1==d2 || d2==d3 || d3==d1
{
	printf("Jednakostranicni\n");
}	
 else if((x3-x1)==(x3-x2) && (y3-y1)==(y3-y2) || (x2-x1)==(x3-x1) && (y2-y1)==(y3-y1) || (x2-x1)==(x3-x2) && (y2-y1)==(y3-y2) || x1==x2 && x1==x3 || y1==y2 && y1==y3)
 {
 	printf("Linija\n");
 }
 	else if(fabs(d1-d2)<epsilon || fabs(d2-d3)<epsilon || fabs(d1-d3)<epsilon)
 	{
 		printf("Jednakokraki\n");
 	}
 else printf("Raznostranicni\n");
 printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st,m,s);
 return 0;
}
