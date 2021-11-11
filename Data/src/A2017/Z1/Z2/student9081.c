#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main() {
	double tx1,ty1,tx2,ty2,tx3,ty3,eps,a,b,c,alfa,beta,gama,max,raz1,raz2,raz3;
	double uraz1,uraz2,uraz3;
	int flag1=0,flag2=0,flag3=0;
	int stepen,minut,sekunda;
	eps=0.0001;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf",&tx1,&ty1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf",&tx2,&ty2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf",&tx3,&ty3);
	c=sqrt(pow((tx1-tx2),2)+pow((ty1-ty2),2));
	b=sqrt(pow((tx1-tx3),2)+pow((ty1-ty3),2));
	a=sqrt(pow((tx2-tx3),2)+pow((ty2-ty3),2));
	alfa=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	beta=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	gama=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	alfa=alfa*180/PI;
	beta=beta*180/PI;
	gama=gama*180/PI;
	raz1=a-b;
	raz2=a-c;
	raz3=b-c;
	uraz1=alfa-90;
	uraz2=beta-90;
	uraz3=gama-90;
	if (raz1<0) raz1=raz1*(-1);
	if (raz2<0) raz2=raz2*(-1);
	if (raz3<0) raz3=raz3*(-1);
	if (uraz1<0) uraz1=uraz1*(-1);
	if (uraz2<0) uraz2=uraz2*(-1);
	if (uraz3<0) uraz3=uraz3*(-1);
	if (raz1<=eps || raz2<=eps || raz3<=eps)
	flag1=1;
	if (uraz1<=eps || uraz2<=eps || uraz3<=eps)
	flag2=1;
	if (raz1>eps && raz2>eps && raz3>eps)
	flag3=1;
	if ((tx1*(ty2-ty3)+tx2*(ty3-ty1)+tx3*(ty1-ty2))/2==0)
	printf ("Linija\n");
	else if (raz1<=eps && raz2<=eps && raz3<=eps)
	printf ("Jednakostranicni\n");
    else if (flag1==1 && flag2==1)
	{printf ("Pravougli\n");
	 printf ("Jednakokraki\n");}
	 else if (flag1==1 && flag2==0)
	 printf ("Jednakokraki\n");
	 else if (flag3==1 && flag2==1)
	 {printf ("Pravougli\n");
	  printf ("Raznostranicni\n");}
	 else if (flag1==0 && flag2==1)
	 printf ("Pravougli\n");
	 else
	 printf ("Raznostranicni\n");
	 
	 if (alfa>beta && alfa>gama)
	 max=alfa;
	 else if (beta>alfa && beta>gama)
	 max=beta;
	 else if (gama>alfa && gama>beta)
	 max=gama;
	 stepen=(int)max;
	 minut=(int)((max-stepen)*60);
	 sekunda=(int)((((max-stepen)*60)-minut)*60);
	 printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen,minut,sekunda);
	 
	 return 0;
}
