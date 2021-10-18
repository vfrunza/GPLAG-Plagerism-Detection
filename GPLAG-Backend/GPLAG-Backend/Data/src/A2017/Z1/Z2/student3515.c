#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.1415926
int main() {
	double x1,x2,x3,y1,y2,y3,p,ugao,minute,sekunde,cosugao,min,mid,max,a,b,c,stepeni;
	printf("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf",&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3) + (y3-y2)*(y3-y2));
	c=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	p=(1.00/2*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));
	if(p<0) p=0-p;
	
	if(a>=b && a>=c){
		max=a;
		if(b>c) {mid=b; min=c;} else {mid=c; min=b;}
	}else if (b>=c && b>=a){
		max=b;
		if(a>c){mid=a; min=c;} else {mid=c; min=a;}
	} else {max=c; if (a>b){mid=a; min=b;} else{mid=b; min=a;} } 
		
	if(p<E && p>-E) 
		printf("Linija\n"); 
	else {
		if(max-mid<E && max-min<E) 
			printf("Jednakostranicni\n"); 
		else{
			if(mid*min/2<p+E && mid*min/2>p-E) 
				printf("Pravougli\n");
			if(max-mid<E || mid-min<E) 
				printf("Jednakokraki\n");
			if(max-mid>E && mid - min>E ) 
				printf("Raznostranicni\n");
		}
		
	}
	cosugao=(min*min + mid*mid -max*max)/(2*min*mid);
	ugao=(acos(cosugao)*180)/(4*atan(1));
	minute=(ugao-(int)ugao)*60;
	sekunde=(minute-(int)minute)*60;
	minute=(int)minute;
	sekunde=(int)sekunde;
	stepeni=(int)ugao;
	if(sekunde>59)
		{minute=minute+1; sekunde=sekunde-60;}
	if(minute>59)
		{stepeni++; minute-=60;}
	printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",stepeni,minute,sekunde);
	
		  
		  
	 
		  
		  
		  
	
	return 0;
}
