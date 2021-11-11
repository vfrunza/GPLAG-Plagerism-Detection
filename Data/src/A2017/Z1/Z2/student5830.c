#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.14159265

int main() {
	
double x1, x2, x3, y1, y2, y3, a, b, c, alfa, beta, gama, alfa_, beta_, gama_ ;
int uk_sec_1, st_1, m_1, s_1, uk_sec_2, st_2, m_2, s_2, uk_sec_3, st_3, m_3, s_3 ;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	
	if ((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))==0) {
	printf("Linija\n");
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	}
	
	else if (fabs(a-b)<E && fabs(b-c)<E) {
	printf("Jednakostranicni\n");
	printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
	}
	
	else if(((fabs((a*a+b*b)-c*c)<E) || (fabs((a*a+c*c)-b*b)<E) || (fabs((c*c+b*b)-a*a)<E)) && ((fabs(a-b)<E) || (fabs(b-c)<E) || (fabs(a-c)<E))) {
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
		
	}
	
	else if((fabs((a*a+b*b)-c*c)<E) || (fabs((a*a+c*c)-b*b)<E) || (fabs((c*c+b*b)-a*a)<E)) {
	printf("Pravougli\n");
	printf("Raznostranicni\n");
	printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	}
	
	else if ((fabs(a-b)<E && fabs(b-c)>E && fabs(a-c)>E) || (fabs(b-c)<E && fabs(c-a)>E && fabs(b-a)>E) || (fabs(a-c)<E && fabs(c-b)>E && fabs(a-b)>E)) {
		printf("Jednakokraki\n");
		
	    gama=acos ((a*a+b*b-c*c)/(2*a*b));
		beta=acos ((a*a+c*c-b*b)/(2*a*c));
		alfa=acos ((c*c+b*b-a*a)/(2*c*b));
		
		gama_=(gama*180)/PI;
		beta_=(beta*180)/PI;
		alfa_=(alfa*180)/PI;
		
		uk_sec_1=gama_*60*60;
		uk_sec_2=beta_*60*60;
		uk_sec_3=alfa_*60*60;
		
		s_1=uk_sec_1 % 60;
		s_2=uk_sec_2 % 60;
		s_3=uk_sec_3 % 60;
		
		m_1=(uk_sec_1/60) % 60;
		m_2=(uk_sec_2/60) % 60;
		m_3=(uk_sec_3/60) % 60;
		
		st_1=uk_sec_1/3600;
		st_2=uk_sec_2/3600;
		st_3=uk_sec_3/3600;
		
        if(gama_<=alfa_ && alfa_<beta_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_2,m_2,s_2);
		
    	else if(gama_<=beta_ && beta_<alfa_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_3,m_3,s_3);
		
		else if(alfa_<=beta_ && beta_<gama_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_1,m_1,s_1);
		
		else if(alfa_<=gama_ && gama_<beta_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_2,m_2,s_2);
		
		else if(beta_<=alfa_ && alfa_<gama_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_1,m_1,s_1);
		
	    else if(beta_<=gama_ && gama_<alfa_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_3,m_3,s_3);
		
	}
	
	else { 
		printf("Raznostranicni\n");
	
	    gama=acos ((a*a+b*b-c*c)/(2*a*b));
		beta=acos ((a*a+c*c-b*b)/(2*a*c));
		alfa=acos ((c*c+b*b-a*a)/(2*c*b));
		
		gama_=(gama*180)/PI;
		beta_=(beta*180)/PI;
		alfa_=(alfa*180)/PI;
		
		uk_sec_1=gama_*60*60;
		uk_sec_2=beta_*60*60;
		uk_sec_3=alfa_*60*60;
		
		s_1=uk_sec_1 % 60;
		s_2=uk_sec_2 % 60;
		s_3=uk_sec_3 % 60;
		
		m_1=(uk_sec_1/60) % 60;
		m_2=(uk_sec_2/60) % 60;
		m_3=(uk_sec_3/60) % 60;
		
		st_1=uk_sec_1/3600;
		st_2=uk_sec_2/3600;
		st_3=uk_sec_3/3600;
		
		if(gama_<alfa_ && alfa_<beta_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_2,m_2,s_2);
		
    	else if(gama_<beta_ && beta_<alfa_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_3,m_3,s_3);
		
		else if(alfa_<beta_ && beta_<gama_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_1,m_1,s_1);
		
		else if(alfa_<gama_ && gama_<beta_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_2,m_2,s_2);
		
		else if(beta_<alfa_ && alfa_<gama_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_1,m_1,s_1);
		
	    else if(beta_<gama_ && gama_<alfa_)
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st_3,m_3,s_3);
	}
		
	return 0;
}


