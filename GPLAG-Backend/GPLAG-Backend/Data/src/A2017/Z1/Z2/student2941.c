#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159
int main() {
	
	double x1,x2,x3,y1,y2,y3,a,b,c,alfa,alfa1,beta,beta1,gama,gama1;
	int stepen1,stepen2,stepen3,minuta1,minuta2,minuta3,sekunde1,sekunde2,sekunde3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
		printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

a=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
b=sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
c=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
alfa=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
beta=acos((-(b*b)+(c*c)+(a*a))/(2*a*c));
gama=acos(((b*b)-(c*c)+(a*a))/(2*b*a));
alfa1=alfa*(180/PI);
beta1=beta*(180/PI);
gama1=gama*(180/PI);
stepen1=(int)alfa1;
stepen2=(int)beta1;
stepen3=(int)gama1;
minuta1=(int)((alfa1-stepen1)*60);
minuta2=(int)((beta1-stepen2)*60);
minuta3=(int)((gama1-stepen3)*60);
sekunde1=(int)((((alfa1-stepen1)*60)-minuta1)*60);
sekunde2=(int)((((beta1-stepen2)*60)-minuta2)*60);
sekunde3=(int)((((gama1-stepen3)*60)-minuta3)*60);

if((stepen1==90 || stepen2==90 || stepen3==90) && (sekunde1==0 || sekunde2==0 || sekunde3==0 ) && ( minuta1==0 || minuta2==0 ||  minuta3==0)){
	printf("Pravougli\n");
	if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON)
	printf("Jednakostranicni\n");
	else if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON)
	printf("Raznostranicni \n");
	else if((fabs(a-b)<EPSILON && fabs(b-c)>EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>EPSILON) || (fabs(b-c)<EPSILON && fabs(a-b)>EPSILON))
	printf("Jednakokraki\n");
	
	if(stepen1==90)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen1,minuta1,sekunde1);
	else if(stepen2==90)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,minuta2,sekunde2);
	else if(stepen3==90)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,minuta3,sekunde3);
	return 0;
}
else if((stepen1==180 || stepen2==180 || stepen3==180) && (sekunde1==sekunde2 && sekunde3==sekunde2 && sekunde1==0 && minuta1==0 && minuta2==0 && minuta3==0)){
	printf("Linija\n");	if(stepen1==180)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen1,minuta1,sekunde1);
	else if(stepen2==180 )
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,minuta2,sekunde2);
	else if(stepen3==180)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,minuta3,sekunde3);
	return 0;
}
	
else if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON){
	printf("Jednakostranicni\n");
		if(stepen1>=stepen2 || stepen1>=stepen3)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen1,minuta1,sekunde1);
	else if(stepen2>=stepen1 || stepen2>=stepen3)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,minuta2,sekunde2);
	else if(stepen3>=stepen2 || sekunde3>=stepen1)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,minuta3,sekunde3); 
}
if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON)
{printf("Raznostranicni\n");
	if(stepen1>stepen2 && stepen1>stepen3)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen1,minuta1,sekunde1);
	else if(stepen2>stepen1 && stepen2>stepen3)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,minuta2,sekunde2);
	else if(stepen3>stepen2 && sekunde3>stepen1)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,minuta3,sekunde3);

	
}
else if(((fabs(a-b)<EPSILON && fabs(b-c)>EPSILON) || (fabs(a-c)<EPSILON && fabs(a-b)>EPSILON) || (fabs(b-c)<EPSILON && fabs(a-b)>EPSILON))){
	printf("Jednakokraki\n");
		if(stepen1>=stepen2 && stepen1>=stepen3)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen1,minuta1,sekunde1);
	else if(stepen2>=stepen1 && stepen2>=stepen3)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen2,minuta2,sekunde2);
	else if(stepen3>=stepen2 && sekunde3>=stepen1)
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen3,minuta3,sekunde3);
}

	return 0;
	
}
