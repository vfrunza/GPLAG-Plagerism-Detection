#include <stdio.h>
#include <math.h>

int main() {
	double epsilon=0.0001;
	double x1,y1,x2,y2,x3,y3,sa,sb,sc,alfa,beta,gama,pommin,pomsec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	sa=fabs(sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
	sb=fabs(sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));
	sc=fabs(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	alfa=(sa*sa-sb*sb-sc*sc)/(-2*sb*sc);
	beta=(sb*sb-sa*sa-sc*sc)/(-2*sa*sc);
	gama=(sc*sc-sb*sb-sa*sa)/(-2*sa*sb);
	alfa=acos(alfa)*(180/(4*atan(1)));
	beta=acos(beta)*(180/(4*atan(1)));
	gama=acos(gama)*(180/(4*atan(1)));
	if((sa>=sb&&sb>sc)||(sa>=sc&&sc>sb))
	{
		pommin=alfa;
		alfa=(int)alfa;
		pommin=pommin-alfa;
		pommin=pommin*60;
		pomsec=pommin;
		pommin=(int)pommin;
		pomsec=(pomsec-pommin)*60;
		pomsec=(int)pomsec;
	}
	else if((sb>=sc&&sc>sa)||(sb>=sa&&sa>sc))
	{
		pommin=beta;
		beta=(int)beta;
		pommin=pommin-beta;
		pommin=pommin*60;
		pomsec=pommin;
		pommin=(int)pommin;
		pomsec=(pomsec-pommin)*60;
		pomsec=(int)pomsec;
	}
	else if((sc>=sa&&sa>sb)||(sc>=sb&&sb>sa))
	{
		pommin=gama;
		gama=(int)gama;
		pommin=pommin-gama;
		pommin=pommin*60;
		pomsec=pommin;
		pommin=(int)pommin;
		pomsec=(pomsec-pommin)*60;
		pomsec=(int)pomsec;
	}
	if((x1*y2-x1*y3-x2*y1+x2*y3+x3*y1-x3*y2)==0)
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		
	}
	else if(fabs(sa-sb<epsilon)&&fabs(sb-sc<epsilon)&&fabs(sc-sa<epsilon))
	{
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
	else if(fabs(sa-sb)>=epsilon&&fabs(sa-sc)>=epsilon&&fabs(sb-sc)>=epsilon)
	{
		if((sqrt(sa*sa+sb*sb==(sc*sc)))||(sqrt(sa*sa+sc*sc==(sb*sb)))||(sqrt(sc*sc+sb*sb==(sa*sa))))
		{
			printf("Pravougli\n");
			printf("Raznostranicni\n");
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		}
		else{
		printf("Raznostranicni\n");
		if(sa>sb&&sa>sc)
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",alfa,pommin,pomsec);
		else if(sb>sa&&sa>sc)
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",beta,pommin,pomsec);
		else
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",gama,pommin,pomsec);}
	}
	else if((fabs(sa-sb)<epsilon&&sa!=sc)||(fabs(sa-sc)<epsilon&&sa!=sb)||(fabs(sc-sb)<epsilon&&sb!=sa))
	{
		if((sqrt(sa*sa+sb*sb==(sc*sc)))||(sqrt(sa*sa+sc*sc==(sb*sb)))||(sqrt(sc*sc+sb*sb==(sa*sa))))
		{
			printf("Pravougli\n");
			printf("Jednakokraki\n");
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		}
		else
		{
			printf("Jednakokraki\n");
			if(sa>=sb&&sa>sc)
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",alfa,pommin,pomsec);
			else if(sb>=sa&&sa>sc)
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",beta,pommin,pomsec);
			else
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",gama,pommin,pomsec);
			
		}
	
	}
	return 0;
}
