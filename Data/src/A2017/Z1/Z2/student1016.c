//Radio zadatak slucajno u T4 Z2 pa kopirao
#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main() {
	double x1,x2,y1,y2,x3,y3,t1,t2,t3,ALFA,ALFA1,BETA,BETA1,GAMA,Stepeni,Minute,Sekunde,Minute1;
	const double Eps=0.0001;
	  printf ("Unesite koordinate tacke t1: ");
	  scanf ("%lf %lf",&x1,&y1);
	  printf ("Unesite koordinate tacke t2: ");
	  scanf ("%lf %lf",&x2,&y2);
	  printf ("Unesite koordinate tacke t3: ");
	  scanf ("%lf %lf",&x3,&y3);
	  t1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	  t2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	  t3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	  ALFA=acos((t1*t1+t3*t3-t2*t2)/(2*t1*t3));
	  BETA=acos((t1*t1+t2*t2-t3*t3)/(2*t1*t2));
	  ALFA1=ALFA*(180/PI);
	  BETA1=BETA*(180/PI);
	  GAMA=180-BETA1-ALFA1;
	  if (ALFA1==0){printf ("Linija\n");}
	  if ((int)ALFA1==90 || (int)BETA1==90 || (int)GAMA==90) {printf ("Pravougli\n");}
	  if (fabs((float)t2-(float)t1)<=Eps  && fabs((float)t1-(float)t3)>Eps && ALFA1!=0 && (ALFA1-GAMA)<Eps){printf ("Jednakokraki\n");}
	  //if ((t1-t2)<Eps && fabs(t2-t3)>Eps && fabs(t3-t1)>Eps && ALFA1!=0){printf("Jednakokraki\n");}
	  if ((t1-t2)<Eps && (t3-t2)<Eps && (int)(ALFA1-BETA1)<Eps ){printf ("Jednakostranicni\n");}
	  if ((float)t1!=(float)t2 && (float)t2!=(float)t3 && (float)t1!=(float)t3 ){printf ("Raznostranicni\n");}
	// printf ("%lf %lf %lf ",t1,t2,t3);
	// printf ("%lf %lf %lf ",ALFA1,BETA1,GAMA);
	  if ((ALFA1-180)<Eps || ((BETA1-180)<Eps) || ((GAMA-180)<Eps)){
	  if (ALFA1>=BETA1 && ALFA1>=GAMA){
	     Stepeni=(int)ALFA1;
	  	 Minute=(ALFA1-Stepeni)*60;
	  	 Sekunde=(Minute-(int)Minute)*60;
	  	printf ("Najveci ugao ima %0.lf stepeni, %0.f minuta i %0.lf sekundi.",Stepeni,Minute,Sekunde); return 0;}
	  	if (ALFA1<=BETA1 && BETA1>=GAMA){
	     Stepeni=(int)BETA1;
	  	 Minute=(BETA1-Stepeni)*60;
	  	 Sekunde=(Minute-(int)Minute)*60;
	  	printf ("Najveci ugao ima %0.lf stepeni, %0.f minuta i %0.lf sekundi.",Stepeni,Minute,Sekunde);return 0;}
	  	if (GAMA>=ALFA1 && GAMA>=BETA1);{
	  	 Stepeni=(int)GAMA;
	  	 Minute1=(GAMA-Stepeni)*60;
	  	 Minute=(int)Minute1;
	  	 Sekunde=(Minute1-(int)Minute)*60;
	  	printf ("Najveci ugao ima %0.lf stepeni, %0.f minuta i %0.lf sekundi.",Stepeni,Minute,Sekunde); return 0;}
	  }
	return 0;
}
