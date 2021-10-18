#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define c 57.29577957
int main() {
	double x1,y1, x2, y2, x3, y3, d1, d2,d3, pug, pm;
	int ug, umin, usek, prolaz=0;
				
				
				
		
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
		
	/*JEDNAKOKRAKI ISPITIVANJE*/
	/*Tacka c je vrh trougla sa koordinatama x3 i y3 pa racunamo udaljenost AC i BC*/
		/*d1 je udaljenost AC*/
		d1=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		/*d2 je udaljenost BC*/
		d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		/*d3 je udaljenost AB*/
		d3=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			 
			 if(((fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))/2)<epsilon){
			printf("Linija");
			ug=180;
			umin=0;
			usek=0;
		}else
		{
		if((fabs(pow(d1,2)+pow(d2,2)-pow(d3,2))<epsilon)||(fabs(pow(d2,2)+pow(d3,2)-pow(d1,2))<epsilon)||(fabs(pow(d1,2)+(pow(d3,2)-pow(d2,2))<epsilon)))
		{	
			printf("Pravougli");
			ug=90;
			umin=0;
			usek=0;
			prolaz=1;
			printf("\n");
}
		if((fabs(d1-d2)<epsilon)&&(fabs(d2-d3)<epsilon)&&(fabs(d1-d3)<epsilon))
		{
			printf("Jednakostranicni");
			ug=60;
			umin=0;
			usek=0;
		}
	else if((fabs(d1-d2)<epsilon && fabs(d1-d3)>=epsilon) || (fabs(d1-d3)<epsilon && fabs(d1-d2)>=epsilon ) || (fabs(d2-d3)<epsilon && fabs(d2-d1)>=epsilon))
	{
	printf("Jednakokraki");
		if(prolaz==0)
		{
			if((d1>=d3)&&(d1>=d2))
			{
				
				pug=acos(((d3*d3)+(d2*d2)-(d1*d1))/(2*d2*d3))*c;
			}
			else if ((d2>=d1)&&(d2>=d3))
			{
				pug=acos(((d1*d1)+(d3*d3)-(d2*d2))/(2*d1*d3))*c;
			
				
		}
		else
		{
			pug=acos(((d1*d1)+(d2*d2)-(d3*d3))/(2*d1*d2))*c;
		}
				ug=pug;
				/*pm privremeni ugao za minute*/ 
				pm=(pug-ug)*60;
				umin=pm;
				usek=(pm-umin)*60;
				
	}
	}
	else 
	{
		printf("Raznostranicni");
			if(prolaz==0)
			{
				if((d1>=d2)&&(d1>=d3))
				{
					pug=acos(((d3*d3)+(d2*d2)-(d1*d1))/(2*d2*d3))*c;	
				}
				else if ((d2>=d1)&&(d2>=d3))
				{
					pug=acos(((d1*d1)+(d3*d3)-(d2*d2))/(2*d1*d3))*c;
				}
				else
				{
					pug=acos(((d1*d1)+(d2*d2)-(d3*d3))/(2*d1*d2))*c;
				}
				ug=pug;
				pm=(pug-ug)*60;
				umin=pm;
				usek=(pm-umin)*60;
			}
	}
		}
	
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", ug, umin, usek);
	return 0;
}

