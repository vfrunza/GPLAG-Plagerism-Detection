#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define epsilon 0.0001

int main()
{
	double x1,y1,x2,y2,x3,y3,a,b,c,M,N,O;
	int st1,min1,s1,st2,min2,s2,st3,min3,s3;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);

	a=(sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
	b=(sqrt(pow(x3-x2,2)+pow(y3-y2,2)));
	c=(sqrt(pow(x3-x1,2)+pow(y3-y1,2)));

	M=((acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c)))*180/PI);
	N=((acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c)))*180/PI);
	O=((acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b)))*180/PI);

	if((fabs(a+b-c)<=epsilon) || (fabs(a+c-b)<=epsilon) || (fabs(b+c-a)<=epsilon)) {
		printf("Linija\n");
	} else

		if((fabs(a-b)<epsilon) && (fabs(a-c)<epsilon)) {
			printf("Jednakostranicni\n");
		} else

			if(((fabs(a-b)<epsilon) && (fabs(a-c)>=epsilon)) || ((fabs(a-c)<epsilon) && (fabs(a-b)>=epsilon)) || ((fabs(b-c)<epsilon) && (fabs(a-b)>=epsilon))) {
				if (((fabs(pow(c,2)-pow(a,2)-pow(b,2)))<epsilon) || ((fabs(pow(b,2)-pow(a,2)-pow(c,2)))<epsilon) || ((fabs(pow(a,2)-pow(c,2)-pow(b,2)))<epsilon)) {

					printf("Pravougli\n");
				}
				printf("Jednakokraki\n");
			}

	if((fabs(a-b)>=epsilon && fabs(a-c)>=epsilon) && fabs(b-c)>=epsilon) {
		if (((fabs(pow(c,2)-pow(a,2)-pow(b,2)))<epsilon) || ((fabs(pow(b,2)-pow(a,2)-pow(c,2)))<epsilon) || ((fabs(pow(a,2)-pow(c,2)-pow(b,2)))<epsilon)) {

			printf("Pravougli\n");
		}
		printf("Raznostranicni\n");
	}

	if(a>=b && a>c) {
		st1=(int) M;
		min1=(int) ((M-st1)*60);
		s1=((((M-st1)*60)-min1)*60);
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st1,min1,s1);
	}

	if(b>a && b>=c) {
	st2=(int) N;
		min2=(int) ((N-st2)*60);
		s2=((((N-st2)*60)-min2)*60);
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st2,min2,s2);
	}

	if(c>=a && c>b) {
	st3=(int) O;
		min3=(int) ((O-st3)*60);
		s3=((((O-st3)*60)-min3)*60);
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st3,min3,s3);
	}




	return 0;
}