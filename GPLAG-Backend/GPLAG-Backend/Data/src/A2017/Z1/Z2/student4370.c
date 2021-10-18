#include <stdio.h>
#include <math.h>

int main() {
		double PI = 4*atan(1.0);
		double maxstepeni,maxminute,maxsekunde;
		double x1,y1,x2,y2,x3,y3,d1,d2,d3,u1,u2,u3;
		double max;
		printf("Unesite koordinate tacke t1: ");
		scanf("%lf %lf", &x1,&y1);
		printf("Unesite koordinate tacke t2: ");
		scanf("%lf %lf", &x2,&y2);
		printf("Unesite koordinate tacke t3: ");
		scanf("%lf %lf", &x3,&y3);
		d1 = sqrt(pow((x2-x1),2)+pow((y2-y1),2)); 
		d2 = sqrt(pow((x3-x1),2)+pow((y3-y1),2));
		d3 = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
		u1 = acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
		u2 = acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
		u3 = acos((d2*d2+d1*d1-d3*d3)/(2*d1*d2));
		if(u1 > u2 && u1 > u3) max = u1;
		if(u2 > u1 && u2 > u3) max = u2;
		if(u3 > u2 && u3 > u1) max = u3;
		max = max * 180 / PI;
		maxstepeni = (int)max;
	  	maxminute = (int)(((max - maxstepeni)*60));
	  	maxsekunde = ((max - maxstepeni)*60 - maxminute)*60;
	  	if(fabs(maxsekunde-60)<0.0001){
	  		maxsekunde = 0;
	  		maxminute += 1;
	  	}
	  	if(fabs(maxminute-60)<0.0001){
	  		maxminute = 0;
	  		maxstepeni += 1;
	  	}
	  
	  if(fabs((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3))<0.0001){
	  	printf("Linija\n");
	  }
	  else{
		  if(fabs(max-90) < 0.0001) printf("Pravougli\n");
		  if((fabs(d1 - d2) < 0.001) && (fabs(d2 - d3) < 0.001) && (fabs(d3 - d1) < 0.0001) ) printf("Jednakostranicni\n");
		  else if((fabs(d1 - d2) < 0.001) || (fabs(d2 - d3) < 0.001) || (fabs(d3 - d1) < 0.0001) ) printf("Jednakokraki\n");
		  else printf("Raznostranicni\n");
	  		}
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)maxstepeni,(int)maxminute,(int)maxsekunde);
	  return 0;
}
