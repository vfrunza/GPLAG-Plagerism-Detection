#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.141592653
int main() {
	double alfa,beta,gama;
	double x1,y1,x2,y2,x3,y3;
	double a,b,c;
	double ab,bc,ca;
	double najveci_ugao;
	int step,min,sek;
	double ugao1,ugao2,ugao3;
	printf("Unesite koordinate tacke t1: ");
   scanf("%lf %lf",&x1,&y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf",&x2,&y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf",&x3,&y3);

	a=sqrt((pow((x2-x1),2))+ pow((y2-y1),2));
	b=sqrt((pow((x3-x1),2))+ pow((y3-y1),2));
	c=sqrt((pow((x3-x2),2))+ pow((y3-y2),2));
	ab= a-b;
	bc=b-c;
	ca=c-a;
	if(ab<0) ab*=-1;
	if(bc<0) bc*=-1;
    if(ca<0) ca*=-1;

	alfa=acos(((-1)*a*a + b*b + c*c) / (2*b*c)) * (180.0/PI);
	beta=acos(((-1)*b*b + a*a + c*c) / (2*c*a)) * (180.0/PI);
	gama=acos(((-1)*c*c + a*a + b*b ) / (2*a*b)) * (180.0/PI);
	
	if((a+b-c>=eps) && (a+c-b>=eps) && (b+c-a>=eps)) {
		if(alfa>=beta && alfa>=gama){
			najveci_ugao=alfa;
		}
		if(beta>=alfa && beta>=gama){
			najveci_ugao=beta;
		}
		if(gama>=alfa && gama>=beta){
			najveci_ugao=gama;
			}
	
		ugao1= alfa-90;
		ugao2= beta-90;
		ugao3= gama-90;
		
		
		if(ugao1<0) ugao1*=-1;
		if(ugao2<0) ugao2*=-1;
		if(ugao3<0) ugao3*=-1;
		
		if((ugao1<eps || ugao2<eps || ugao3<eps )){
			printf("Pravougli\n");
			
		}
		if(((ab<eps)&& (bc>eps)) || ((ca<eps) && (bc>eps)) || ((bc<eps) && (ca>eps))){
			printf("Jednakokraki\n");
		} else if((ab>eps) && (ca>eps) && (bc>eps)){
			printf("Raznostranicni\n");
		} else if ((ab<eps) && (ca<eps)){
			printf("Jednakostranicni\n");
			
		}
		}
		else{
			printf("linija\n");
			najveci_ugao = 180;
		}
			
			
		step=(int)najveci_ugao;
		min=(int)((najveci_ugao - step)*60);
		sek=(int)(((najveci_ugao - step- (double) min/60.0)*3600));
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step,min,sek);
		
		
		
		
	
	
	return 0;
}
 