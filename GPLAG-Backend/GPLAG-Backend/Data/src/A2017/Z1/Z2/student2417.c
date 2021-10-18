#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14159265359
int main() {
	double x1, x2, x3, y1, y2, y3, a, b, c, alfa, beta, gama, stepen, minuta, sekunda;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf", &x3, &y3);
	a=sqrt(fabs((x1-x2)*(x1-x2))+fabs((y1-y2)*(y1-y2)));
	b=sqrt(fabs((x1-x3)*(x1-x3))+fabs((y1-y3)*(y1-y3)));
	c=sqrt(fabs((x2-x3)*(x2-x3))+fabs((y2-y3)*(y2-y3)));
	alfa=acos((a*a+b*b-c*c)/(2*a*b))*(180/PI);
	beta=acos((a*a+c*c-b*b)/(2*a*c))*(180/PI);
	gama=acos((b*b+c*c-a*a)/(2*b*c))*(180/PI);
    if ((fabs(x1-x2)<epsilon && fabs(x2-x3)<epsilon && fabs(x3-x1)<epsilon) || (fabs(y1-y2)<epsilon && fabs(y2-y3)<epsilon && fabs(y1-y3)<epsilon) || (fabs((x2-x1)-(x3-x2))<epsilon) && fabs((y2-y1)-(y3-y2))<epsilon)
    {
    printf("Linija");
    printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    } else if (fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) {
    if (fabs(a*a+b*b-c*c)<epsilon || fabs(b*b+c*c-a*a)<epsilon || fabs(c*c+a*a-b*b)<epsilon)
    {
    printf("Pravougli");
    printf("\nRaznostranicni");
    printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
    } else {
    printf("Raznostranicni");
    if(alfa>=beta && alfa>=gama) {
    stepen=(int)(alfa);
    minuta=(int)((alfa-(int)(alfa))*60);
    sekunda=(int)((alfa-(int)(alfa)-minuta/60)*3600);
    printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen, minuta, sekunda);
    } else if (beta>=alfa && beta>=gama) {
    stepen=(int)(beta);
    minuta=(int)((beta-(int)(beta))*60);
    sekunda=(int)((beta-(int)(beta)-minuta/60)*3600);
    printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen, minuta, sekunda);
    } else if (gama>=alfa && gama>=beta) {
    stepen=(int)(gama);
    minuta=(int)((gama-(int)(gama))*60);
    sekunda=(int)((gama-(int)(gama)-minuta/60)*3600);
    printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen, minuta, sekunda);
    } } } else if (fabs(a-b)<epsilon && fabs(a-c)<epsilon && fabs(b-c)<epsilon) {
    printf("Jednakostranicni");
    printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
    } else if (fabs(x1-y1)<epsilon && fabs(x2<y2) && fabs(x3-y3)<epsilon) {
    printf("Pravougli");
    printf("\nJednakokraki");
    printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
    } else {
    printf("Jednakokraki");
    if(alfa>=beta && alfa>=gama) {
    stepen=(int)(alfa);
    minuta=(int)((alfa-(int)(alfa))*60);
    sekunda=(int)((alfa-(int)(alfa)-minuta/60)*3600);
    printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen, minuta, sekunda);
    } else if (beta>=alfa && beta>=gama) {
    stepen=(int)(beta);
    minuta=(int)((beta-(int)(beta))*60);
    sekunda=(int)((beta-(int)(beta)-minuta/60)*3600);
    printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen, minuta, sekunda);
    } else if (gama>=alfa && gama>=beta) {
    stepen=(int)(gama);
    minuta=(int)((gama-(int)(gama))*60);
    sekunda=(int)((gama-(int)(gama)-minuta/60)*3600);
    printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.", stepen, minuta, sekunda);
    } }
	return 0;
}