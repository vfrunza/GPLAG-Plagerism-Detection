#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
#define E 0.0001

int main() {
double x1,y1,x2,y2,x3,y3,a,b,c,Povrsina,alfa,beta,gama,astepeni,aminuta,asekundi,bstepeni,bminuta,bsekundi,gstepeni,gminuta,gsekundi;
printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf",&x1,&y1);
printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf",&x2,&y2);
printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf",&x3,&y3);
a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
b=sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
alfa=acos((b*b+c*c-a*a)/(2*c*b));
beta=acos((a*a+c*c-b*b)/(2*a*c));
gama=acos((a*a+b*b-c*c)/(2*a*b));
Povrsina=0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
alfa=(180/PI)*alfa;
beta=(180/PI)*beta;
gama=(180/PI)*gama;
astepeni=(int)alfa;
bstepeni=(int)beta;
gstepeni=(int)gama;
 aminuta=(alfa-astepeni)*60;
 bminuta=(beta-bstepeni)*60;
 gminuta=(gama-gstepeni)*60;
  asekundi=(aminuta-(int)aminuta)*60;	
  bsekundi=(bminuta-(int)bminuta)*60;
  gsekundi=(gminuta-(int)gminuta)*60;
   aminuta=(int)aminuta;
   bminuta=(int)bminuta;
   gminuta=(int)gminuta;
	asekundi=(int)asekundi;
	bsekundi=(int)bsekundi;
	gsekundi=(int)gsekundi;
	if(fabs(astepeni-90)<E || fabs(bstepeni-90)<E || fabs(gstepeni-90)<E)
{printf("Pravougli\n");
if(fabs(a-b)<E || fabs(c-b)<E || fabs(a-c)<E ) printf("Jednakokraki\n");
if(fabs(a-b)>E && fabs(c-b)>E && fabs(a-c)>E) printf("Raznostranicni\n");
printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");}
else if (fabs(a-b)<E && fabs(c-b)<E && fabs(a-c)<E) {
 printf("Jednakostranicni\n");
 printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");}
else if (fabs(Povrsina-0)<E)
{ printf("Linija\n");
 printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");}
else if(fabs(a-b)<E || fabs(c-b)<E || fabs(a-c)<E )
{printf("Jednakokraki\n");
if(alfa>=gama && alfa>=beta)
printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",astepeni,aminuta,asekundi);
else if(beta>=gama && beta>=alfa)
printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",bstepeni,bminuta,bsekundi);
else if(gama>=beta && gama>=alfa)
printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",gstepeni,gminuta,gsekundi);
}else if(fabs(a-b)>E && fabs(c-b)>E && fabs(a-c)>E){
    printf("Raznostranicni\n");
    if(alfa>gama && alfa>beta)
printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",astepeni,aminuta,asekundi);
else if(beta>gama && beta>alfa)
printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",bstepeni,bminuta,bsekundi);
else if (gama>beta && gama>alfa)
printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",gstepeni,gminuta,gsekundi);}	
return 0;
 
}
