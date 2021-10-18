#include <stdio.h>
#include <math.h>


int main() 
{
 double x1,y1,x2,y2,x3,y3;
 double d1,d2,d3,ugao,m,o,o1,sek,epsilon=0.0001;
 
 printf("Unesite koordinate tacke t1: ");
 scanf("%lf %lf",&x1,&y1);
 printf("Unesite koordinate tacke t2: ");
 scanf("%lf %lf",&x2,&y2);
 printf("Unesite koordinate tacke t3: ");
 scanf("%lf %lf",&x3,&y3);
 
 d1=sqrt((pow(x2-x1,2))+(pow(y2-y1,2)));
 d2=sqrt((pow(x2-x3,2))+(pow(y2-y3,2)));
 d3=sqrt((pow(x1-x3,2))+(pow(y1-y3,2)));

if(d1>d2 && d1>d3) {
ugao=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));}
if(d2>d1 && d2>d3) {
ugao=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));}
if(d3>d1 && d3>d1){
ugao=acos((d1*d1+d2*d2-d3*d3)/(2*d2*d1));}

ugao=ugao/0.0174532925;

     ugao=fabs(ugao);
    	o=ugao-(int)ugao;
     ugao=ugao-o;
    	m=o*60;
    	o1=m-(int)m;
    	m=m-o1;
    	sek=o1*60;
    	sek=(int)(sek);
    if(sek<0) { sek=-sek;}
    	if(sek>59)
    	{
    	m=m+1;
    	sek=0;
    	}
    	
    	if(m>59)
    	{
    	ugao=ugao+1;
    	m=0;
    	}

if(fabs(ugao-90)<0.0001) { printf("Pravougli\n");}


if(fabs(ugao-60)<0.0001)
{ 
 printf("Jednakostranicni\n");
 printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,m,sek);
 return 0;
}



if(fabs(ugao-180)<0.0001)
{ 
 printf("Linija\n");
 printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,m,sek);
 return 0;
}

if((fabs(d1-d2)<epsilon && fabs(d2-d3)>epsilon  && fabs(d3-d1)>epsilon )|| ((fabs(d1-d3)<epsilon && fabs(d2-d1)>epsilon  && fabs(d3-d2)>epsilon )) || (fabs(d3-d2)<epsilon && fabs(d2-d1)>epsilon  && fabs(d3-d1)>epsilon))
{
 printf("Jednakokraki\n");
 printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,m,sek);
 return 0;
}



if((fabs(d1-d2)>epsilon && fabs(d2-d3)>epsilon  && fabs(d3-d1)>epsilon )) 
{
 printf("Raznostranicni\n"); 
 printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,m,sek);
 return 0;
}





return 0;
}
