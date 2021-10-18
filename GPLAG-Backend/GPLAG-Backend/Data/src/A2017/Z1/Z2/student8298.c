#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define E 0.0001
int main()
{
	double x1, x2, x3, y1, y2, y3, kva, kvb, kvc, a, b, c, A, B, C, max;
	int astepeni, bstepeni, cstepeni, aminuta, bminuta, cminuta, asekundi, bsekundi, csekundi;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	kva=(pow((x3-x2),(2.00)))+(pow((y3-y2),(2.00)));
	kvb=(pow((x1-x3),(2.00)))+(pow((y1-y3),(2.00)));
	kva=(pow((x2-x1),(2.00)))+(pow((y2-y1),(2.00)));

	a=sqrt(kva);
	b=sqrt(kvb);
	c=sqrt(kvc);

	A=((acos((kvb+kvc-kvb)/((2.00)*b*c)))*180)/PI;
	B=((acos((kvc+kva-kvb)/((2.00)*a*c)))*180)/PI;
	C=((acos((kva+kvb-kvc)/((2.00)*a*b)))*180)/PI;
	astepeni=(int)(A);
	aminuta=(int)((A-astepeni)*60.00);
	asekundi=(int)((((a-astepeni)*60)-aminuta)*60);
	bstepeni=(int)(B);
	bminuta=(int)((B-bstepeni)*60.00);
	bsekundi=(int)((((a-bstepeni)*60)-bminuta)*60);
	cstepeni=(int)(C);
	cminuta=(int)((C-cstepeni)*60.00);
	csekundi=(int)((((C-cstepeni)*60)-cminuta)*60);

	if(((a+b)>c) && ((b+c)>a) && ((a+c)>b)) {
		if((fabs(a-b)<E) && (fabs(a-c)<E) && (b-c)<E) {
			printf("Jednakostranicni\n");
			printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi");
		} else if((fabs(a*a+b*b-c*c)<E) || (fabs(a*a+c*c-b*b)<E) || (fabs(b*b+c*c-b*b)<E)) {
			if((fabs(a-b)<E) || (fabs(b-c)<E) || (fabs(a-c)<E)) {
				printf("Pravougli\n");
				printf("Jednakokraki\n");
			} else {
				printf("Pravougli\nRaznostranicni\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi");
			}

		} else if (fabs(A-B)<E) {
			if (A>C) {
				max=A;
				printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi", astepeni, aminuta, asekundi);
			}
		} else if (C>A) {
			max=C;
			printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d stepeni", cstepeni, cminuta, csekundi);
		} else if (fabs(A-C)<E) {
			if (A>B) {
				max=A;
				printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi", astepeni, aminuta, asekundi);
			} else if (B>A) {
				max=B;
				printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d stepeni", bstepeni, bminuta, bsekundi);
			}
		} else if (fabs(B-C)<E) {
			if (B>C) {
				max=B;
				printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi", bstepeni, bminuta, bsekundi);
			} else if (C>A) {
				max=C;
				printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d stepeni", cstepeni, cminuta, csekundi);
			}
		} else if (a!=b &&b!=c) {
			printf("Raznostranicni");
			if(A>B && A>C) {
				max=A;
				printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi", astepeni, aminuta, asekundi);
			} else if (B>A && B>C) {
				max=B;
				printf("Najveci ugao ima %d stepeni %d minuta i %d sekundi", bstepeni, bminuta, bsekundi);
			} else if (C>A && C>B) {
				max=C;
				printf("Najveci ugao ima %d stepeni, %d minuta %d sekundi", cstepeni, cminuta, csekundi);
			}
		}

	} else printf("Linija");
	return 0;

}
