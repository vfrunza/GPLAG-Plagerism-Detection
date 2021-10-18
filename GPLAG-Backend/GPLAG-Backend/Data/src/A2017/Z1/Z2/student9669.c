#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.141592653589793238462643

int main() {

	double x1,y1,x2,y2,x3,y3,a,b,c,d,e,f,Sa,Sb,Sc,Ma,Mb,Mc,Mac,Mbc,Mcc,Na,Nb,Nc,Sac,Sbc,Scc;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf", &x3,&y3);
	
	a=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	b=sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	c=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
	
	d=(((a*a)+(b*b)-(c*c))/(2*a*b));
	e=(((c*c)+(a*a)-(b*b))/(2*c*a));
	f=(((b*b)+(c*c)-(a*a))/(2*b*c));
	
	Sa=acos(d)*(180./PI);
	Sb=acos(e)*(180./PI);
	Sc=acos(f)*(180./PI);
	
	Sac=(int)Sa;
	Ma=(Sa-Sac)*60;
	Sbc=(int)Sb;
	Mb=(Sb-Sbc)*60;
	Scc=(int)Sc;
	Mc=(Sc-Scc)*60;
	
	Mac=(int)Ma;
	Na=(Ma-Mac)*60;
	Mbc=(int)Mb;
	Nb=(Mb-Mbc)*60;
	Mcc=(int)Mc;
	Nc=(Mc-Mcc)*60;
	
	if((fabs(Sa-90)<epsilon)||(fabs(Sb-90)<epsilon)||(fabs(Sc-90)<epsilon)){
		printf("Pravougli\n");
	}
	if((fabs(Sa-180)<epsilon)||(fabs(Sb-180)<epsilon)||(fabs(Sc-180)<epsilon)){
		printf("Linija\n");
	}
	else if((round(Sa)==round(Sb))&&(round(Sb)==round(Sc))){
		printf("Jednakostranicni\n");
	}
	else if(((round(Sa)==round(Sb))&&(round(Sb)!=round(Sc)))||(((round(Sa)==round(Sc))&&(round(Sa)!=round(Sb)))||((round(Sc)==round(Sb)&&(round(Sb)!=round(Sa)))))){
		printf("Jednakokraki\n");
	}
	else if((round(Sa)!=round(Sb))&&(round(Sb)!=round(Sc))){
		printf("Raznostranicni\n");
	}
	
	if((Sa>Sb)&&(Sa>Sc)){
		printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.", floor(Sa),floor(Ma),floor(Na));
	}
	else if((Sb>Sc)&&(Sb>Sc)){
		printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.", floor(Sb),floor(Mb),floor(Nb));
	}
	else if((Sc>Sa)&&(Sc>Sb)){
		printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.", floor(Sc),floor(Mc),floor(Nc));
	}
	
	return 0;
}
