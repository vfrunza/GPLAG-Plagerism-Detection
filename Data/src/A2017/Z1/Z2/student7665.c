#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define eps 0.0001
#define PI 3.14159265

double UdaljenostIzmedjuDvijeTacke(double x1, double y1, double x2, double y2) {
	double x, y, udaljenost;
	x=x2-x1;
	y=y2-y1;
	udaljenost=x*x+y*y;
	udaljenost=sqrt(udaljenost);
	return udaljenost;
}

double TrazenjeOStalihUglova(double ugao, double NajvecaUdaljenost, double NajmanjaUdaljenost) {
	double ugao1;
	ugao1=NajmanjaUdaljenost*sin(ugao*PI);
	ugao1=ugao1/NajvecaUdaljenost;
	ugao1=((asin(ugao1))*180.0)/PI;
	return ugao1;
}

double VeciUgao(double NajvecaUdaljenost, double NajmanjaUdaljenost1, double NajmanjaUdaljenost2) {
	double ugao;
	ugao=NajmanjaUdaljenost1*NajmanjaUdaljenost1+NajmanjaUdaljenost2*NajmanjaUdaljenost2-NajvecaUdaljenost*NajvecaUdaljenost;
	ugao=fabs(ugao/(2*NajmanjaUdaljenost1*NajmanjaUdaljenost2));
	ugao=((acos(ugao))*180.0)/PI;
	return ugao;
}

void Trokut(double x1, double y1, double x2, double y2, double x3, double y3) {
	double Stranica1, Stranica2, Stranica3;
	double ugao1, ugao2, ugao3;
	int stepen, minuta, sekunda;
	double NajUgao;
	
	Stranica1=UdaljenostIzmedjuDvijeTacke(x1, y1, x2, y2);
	Stranica2=UdaljenostIzmedjuDvijeTacke(x2, y2, x3, y3);
	Stranica3=UdaljenostIzmedjuDvijeTacke(x1, y1, x3, y3);
	
	if(Stranica1>Stranica2 && Stranica1>Stranica3) {
		ugao1=VeciUgao(Stranica1, Stranica2, Stranica3);
		ugao2=TrazenjeOStalihUglova(ugao1, Stranica1, Stranica2);
		ugao3=TrazenjeOStalihUglova(ugao1, Stranica1, Stranica3);
		NajUgao=ugao1;
	} else {
		if(Stranica2>Stranica3 && Stranica2>Stranica1) {
			ugao2=VeciUgao(Stranica2, Stranica1, Stranica3);
			ugao1=TrazenjeOStalihUglova(ugao2, Stranica2, Stranica1);
			ugao3=TrazenjeOStalihUglova(ugao2, Stranica2, Stranica3);
			NajUgao=ugao2;
		} else {
			ugao3=VeciUgao(Stranica3, Stranica1, Stranica2);
			ugao1=TrazenjeOStalihUglova(ugao3, Stranica3, Stranica2);
			ugao2=TrazenjeOStalihUglova(ugao3, Stranica3, Stranica1);
			NajUgao=ugao3;
		}
	}
	if(NajUgao<0) {
		sekunda=(double)(NajUgao-0.5);
		sekunda=(abs(sekunda));
		minuta=sekunda/60;
		sekunda=(sekunda%60);
		stepen=minuta/60;
		minuta=minuta%60;
		if(stepen>=360) {
			stepen-=360;
		}
	} else {
		if(NajUgao>=0) {
			sekunda=(double)(NajUgao+0.5);
			sekunda=(abs(sekunda));
			minuta=sekunda/60;
			sekunda=(sekunda%60);
			stepen=minuta/60;
			minuta=minuta%60;
			if(stepen>=360) {
				stepen-=360;
			}
		}
	}
	
	if(((Stranica1+Stranica2)<Stranica3) || ((Stranica1+Stranica3)<Stranica2) || ((Stranica2+Stranica3)<Stranica1) || (x1==x2 && x1==x3) || (y1==y2 && y1==y3)) {
		printf("Linija\n");
		stepen=180;
		printf("Najveci ugao ima %d stepeni, 0 minuta i 0 sekundi.", stepen);
		return;
	}
	else if(((fabs(Stranica1-Stranica2)<eps) && (fabs(Stranica3-Stranica1*sqrt(2)<eps))) || ((fabs(Stranica3-Stranica2)<eps) && (fabs(Stranica1-Stranica2*sqrt(2))<eps)) || ((fabs(Stranica1-Stranica3)<eps) && (fabs(Stranica2-Stranica1*sqrt(2))<eps))) {
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		stepen=90;
		minuta=0;
		sekunda=0;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
	} 
	else if((Stranica1==Stranica2 && (Stranica1!=Stranica3 || Stranica2!=Stranica3)) || (Stranica1==Stranica3 &&(Stranica1!=Stranica2 || Stranica3!=Stranica2)) || (Stranica2==Stranica3 &&(Stranica3!=Stranica1 || Stranica2!=Stranica1))) {
			printf("Jednakokraki\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
	}
	else if((Stranica1*Stranica1==Stranica2*Stranica2+Stranica3*Stranica3) || (Stranica2*Stranica2==Stranica1*Stranica1+Stranica3*Stranica3) || (Stranica3*Stranica3==Stranica2*Stranica2+Stranica1*Stranica1)) {
			printf("Pravougli\n");
			stepen=90;
			printf("Najveci ugao je %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
	} else {
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sekunda);
	}
}


int main() {
	double x1, x2, x3;
	double y1, y2, y3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	Trokut(x1, y1, x2, y2, x3, y3);
	return 0;
}
