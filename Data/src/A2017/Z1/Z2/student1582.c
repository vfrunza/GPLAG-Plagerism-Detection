#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define PI 3.141593

int main() {
	
	int UAukupno, UAstepeni, UAminute, UAsekunde, UBukupno, UBstepeni, UBminute, UBsekunde, UCukupno, UCstepeni, UCminute, UCsekunde ;
	double x1, x2, x3, y1, y2, y3, a, b, c, UA, UB, UC ;
	
	/*Unos koordinata*/
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	/*Računanje stranica*/

	a=sqrt((pow((x2-x1), 2) + pow((y2-y1), 2)));
	b=sqrt((pow((x3-x1), 2) + pow((y3-y1), 2)));
	c=sqrt((pow((x2-x3), 2) + pow((y2-y3), 2)));
	
	/*Računanje uglova*/
	
	UA=acos((pow(c,2)+pow(b,2)-pow(a,2))/(2*b*c));
	UB=acos((pow(c,2)+pow(a,2)-pow(b,2))/(2*a*c));
	UC=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*b*a));
	
	
	UAukupno=(int)round(UA*360*60*60/(2*PI));
	UAsekunde = UAukupno % 60;
	UAminute = (UAukupno / 60) % 60;
	UAstepeni = UAukupno / (60 * 60);
	
	UBukupno=(int)round(UB*360*60*60/(2*PI));
	UBsekunde = UBukupno % 60;
	UBminute = (UBukupno / 60) % 60;
	UBstepeni = UBukupno / (60 * 60);
	
	UCukupno=(int)round(UC*360*60*60/(2*PI));
	UCsekunde = UCukupno % 60;
	UCminute = (UCukupno / 60) % 60;
	UCstepeni = UCukupno / (60 * 60);
	
	
	
	/*Vrsta trougla - LINIJA*/
	
	
		if ((UCstepeni==0)||(UAstepeni==0)||(UBstepeni==0))
			{
			printf ("Linija\n");
			}
			
			
	else {
	/*Vrsta trougla - JEDNAKOSTRANIČNI*/
	
	if ((fabs(a-b)<EPSILON)&&(fabs(a-c)<EPSILON)&&(fabs(c-b)<EPSILON))
		{
		printf ("Jednakostranicni\n");
		}
	
	/*Vrsta trougla - PRAVOUGLI*/
	
	if ((UAstepeni==90)&&(UAminute==0)&&(UAsekunde==0))
		{
		printf ("Pravougli\n");
		}
			else if ((UBstepeni==90)&&(UBminute==0)&&(UBsekunde==0))
				{
				printf ("Pravougli\n");
				}
					else if ((UCstepeni==90)&&(UCminute==0)&&(UCsekunde==0))
						{
						printf ("Pravougli\n");
						}
	
	/*Vrsta trougla - JEDNAKOKRAKI*/
	
	if (((fabs(a-b)<EPSILON)==(fabs(c-b)<EPSILON))&&((fabs(a-b)<EPSILON)!=(fabs(a-c)<EPSILON)))
		{
		printf ("Jednakokraki\n");
		}
			else if (((fabs(a-b)<EPSILON)==(fabs(c-a)<EPSILON))&&((fabs(a-b)<EPSILON)!=(fabs(b-c)<EPSILON)))
				{
				printf ("Jednakokraki\n");
				}
					else if (((fabs(c-b)<EPSILON)==(fabs(c-a)<EPSILON))&&((fabs(c-b)<EPSILON)!=(fabs(b-a)<EPSILON)))
						{
						printf ("Jednakokraki\n");
						}

	/*Vrsta trougla - RAZNOSTRANIČNI*/
	
	if ((UAstepeni!=UBstepeni)&&(UBstepeni!=UCstepeni)&&(UAstepeni!=UCstepeni))
		{
		printf ("Raznostranicni\n");
		}
	}
	
	
	
	/*Najveći ugao*/
	
	
	if ((UA>UB)&&(UA>UC))
		{
		printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", UAstepeni, UAminute, UAsekunde);
		}
			else if ((UB>UA)&&(UB>UC))
				{
				printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", UBstepeni, UBminute, UBsekunde);
				}
					else if ((UC>UA)&&(UC>UB))
					{
					printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", UCstepeni, UCminute, UCsekunde);
					}
	
return 0;
}