#include <stdio.h>
#include <math.h>
#define EPS 0.0001
int main() {
	double t1_x,t1_y,t2_x,t2_y,t3_x,t3_y;
	double s1,s2,s3,gama,alfa,beta,max_ugao,g,a,b;
	int broj_u_sekundama;
	int sekunde,minute,stepeni;
	gama = 0;
	alfa = 0; 
	beta = 0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&t1_x,&t1_y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&t2_x,&t2_y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&t3_x,&t3_y);
	
	
	
	s1=sqrt((t2_x-t1_x)*(t2_x-t1_x)+(t2_y-t1_y)*(t2_y-t1_y));
	s2=sqrt((t3_x-t2_x)*(t3_x-t2_x)+(t3_y-t2_y)*(t3_y-t2_y));
	s3=sqrt((t1_x-t3_x)*(t1_x-t3_x)+(t1_y-t3_y)*(t1_y-t3_y));
	
//	printf("%lf %lf %lf\n", s1, s2, s3);
	
	g=(s3*s3+s2*s2-s1*s1)/(s3*s2*2);
	a=(s1*s1+s3*s3-s2*s2)/(2*s1*s3);
	b=(s1*s1+s2*s2-s3*s3)/(2*s1*s2);
	
	
	gama=acos(g);
	alfa=acos(a);
	beta=acos(b);
	
	
	if(gama == 0 || alfa == 0 || beta ==0){
		printf("Linija\n");
	}
	
	else if(((t1_x==t2_x)&&(t2_x==t3_x))||((t1_y==t2_y)&&(t2_y==t3_y))){
		
		printf("Linija\n");
	} else {
	
	 
	if( (fabs(sqrt(pow(s1,2)+pow(s2,2))-s3)<=EPS) || (fabs(sqrt(pow(s2,2)+pow(s3,2))-s1)<=EPS) || (fabs(sqrt(pow(s1,2)+pow(s3,2))-s2)<=EPS) ) printf("Pravougli\n");
	 
	if(((fabs(s1-s2)<=EPS)&&(fabs(s3-s1)>EPS)) || ((fabs(s2-s3)<=EPS) && (fabs(s1-s2)>EPS)) || ((fabs(s3-s1)<=EPS) && (fabs(s1-s2)>EPS))) printf("Jednakokraki\n");
	
	if(fabs(s1-s2)<EPS && fabs(s3-s1)<EPS) printf("Jednakostranicni\n");
	
	if(fabs(s1-s2)>EPS && (fabs(s2-s3)>EPS) && (fabs(s3-s1)>EPS)) printf("Raznostranicni\n");
		
	}
	
 	max_ugao=alfa;
 	if(beta>max_ugao) max_ugao=beta;
 	else if(gama>max_ugao) max_ugao=gama;
 	
 	max_ugao = max_ugao*(180/3.14159);
 	broj_u_sekundama=max_ugao*3600;
 	sekunde=broj_u_sekundama%60;
 	broj_u_sekundama=broj_u_sekundama/60;
 	minute=broj_u_sekundama%60;
 	broj_u_sekundama=broj_u_sekundama/60;
 	stepeni = broj_u_sekundama;
 	
 	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni, minute, sekunde);
	
	return 0;
}
