#include <stdio.h>
#include <math.h>
#define radian 57.295779513
#define eps 0.0001

int main()
{
	double x1,x2,x3,y1,y2,y3;
	double duzinaAB,duzinaBC,duzinaAC;
	double ugaoA,ugaoB,ugaoC;
	double alfa,beta,gama,alfa1,beta1,gama1,ugao,minuta,sekunda,P,MAX=0;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);

	duzinaAB=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	duzinaBC=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	duzinaAC=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

	ugaoA=(duzinaAC*duzinaAC+duzinaAB*duzinaAB-duzinaBC*duzinaBC)/(2*duzinaAC*duzinaAB);
	ugaoB=(duzinaBC*duzinaBC+duzinaAB*duzinaAB-duzinaAC*duzinaAC)/(2*duzinaBC*duzinaAB);
	ugaoC=(duzinaBC*duzinaBC+duzinaAC*duzinaAC-duzinaAB*duzinaAB)/(2*duzinaBC*duzinaAC);

	alfa1=acos(ugaoA);
	beta1=acos(ugaoB);
	gama1=acos(ugaoC);
	alfa=alfa1*radian;
	beta=beta1*radian;
	gama=gama1*radian;
    
    P=(1./2)*sqrt(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	
	
	

	
	
	if(alfa>=beta && alfa>=gama){
	MAX=alfa;
	ugao=(int)alfa;
	minuta=(int)((alfa-ugao)*60);
	sekunda=(int)((alfa-ugao-minuta/60)*3600);
	} 
	else if(beta>=alfa && beta>=gama){ 
	MAX=beta;
	ugao=(int)beta;
	minuta=(int)((beta-ugao)*60);
	sekunda=(int)((beta-ugao-minuta/60)*3600);
	}
	else if(gama>=alfa && gama>=beta){ 
	MAX=gama;
	ugao=(int)gama;
	minuta=(int)((gama-ugao)*60);
	sekunda=(int)((gama-ugao-minuta/60)*3600);
		
	}

if(x1==x2==x3==y1==y2==y3){
	printf("Tacka");
	ugao=0;
	minuta=0;
	sekunda=0;
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,minuta,sekunda);
}
else if(P==0){
	printf("Linija");
	if(fabs(180.-MAX)<eps){
		ugao=180;
		minuta=0;
		sekunda=0;
	}
	printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,minuta,sekunda);
}
else if(fabs(duzinaAB-duzinaBC)<eps && fabs(duzinaAB-duzinaAC)<eps && fabs(duzinaBC-duzinaAC)<eps){
	printf("Jednakostranicni\n");
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,minuta,sekunda);
}
else if(fabs(90.-alfa)<eps || fabs(90.-beta)<eps || fabs(90.-gama)<eps){
	printf("Pravougli\n");
	
	ugao=90;
	minuta=0;
	sekunda=0;
	if(fabs(duzinaAB-duzinaBC)<eps || fabs(duzinaAB-duzinaAC)<eps ||fabs(duzinaBC-duzinaAC)<eps) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,minuta,sekunda);
}
else if(fabs(duzinaAB-duzinaBC)<eps || fabs(duzinaAB-duzinaAC)<eps ||fabs(duzinaBC-duzinaAC)<eps){
	
	printf("Jednakokraki\n");
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,minuta,sekunda);
}
else{
	printf("Raznostranicni\n");
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ugao,minuta,sekunda);
}









	return 0;
}
