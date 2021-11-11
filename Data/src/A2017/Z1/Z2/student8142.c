#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define E 0.0001
int main() {
	
	double tx1,ty1,tx2,ty2,tx3,ty3,a,b,c,alfa,beta,gama,max_ugao;
	int min,sec,stepeni;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &tx1,&ty1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &tx2,&ty2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &tx3,&ty3);
	
	a=sqrt(pow(tx2-tx3,2)+(pow(ty2-ty3,2)));
	b=sqrt(pow(tx1-tx3,2)+(pow(ty1-ty3,2)));
	c=sqrt(pow(tx1-tx2,2)+(pow(ty1-ty2,2)));
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((c*c+a*a-b*b)/(2*c*a));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	alfa*=180/PI;
	beta*=180/PI;
	gama*=180/PI;
	
	max_ugao=alfa;
	if(beta>max_ugao) max_ugao=beta;
	else if(gama>max_ugao) max_ugao=gama;
	
	stepeni = max_ugao;
	
	min=((max_ugao)-stepeni)*60;
	sec=(((max_ugao-stepeni)*60)-min)*60;
	
	if((max_ugao+E)>90&&(max_ugao-E)<90) printf("Pravougli\n");
	
	if((max_ugao+E)>180&&(max_ugao-E)<180) printf("Linija\n");
	
	else if(fabs(a-b)<E&&fabs(a-c)<E) printf("Jednakostranicni\n");
	else if(fabs(a-b)<E||fabs(a-c)<E) printf("Jednakokraki\n");
	
	else printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,min,sec);
	
	return 0;
}
