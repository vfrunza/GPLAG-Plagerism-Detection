#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.0001
#define PI 3.1415926

int main ()
{
	int pp1=1, s_1, s_2, s_3, m_1, m_2, m_3, t_1, t_2, t_3;    /*pp1,pp2-pomocna varijabla...*/
	double x1, x2, x3, y1, y2, y3, s1, s2, s3, u1, u2, u3, hm_1, hm_2, hm_3, w1, w2, w3;  /*s-stranica 1, s2-stranica 2, s3-stranica 3, u1,2,3 - uglovi, x_1...,y_1...,z_1...-za uglove pomocne varijable...*/
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	s1 = pow (x1-x2,2) + pow (y1-y2,2);
	s1 = sqrt(s1);
	s2 = pow (x1-x3,2) + pow (y1-y3,2);
	s2 = sqrt(s2);
	s3 = pow (x2-x3,2) + pow (y2-y3,2);
	s3 = sqrt(s3);
	w1 = (pow(s1,2)+pow(s2,2)-pow(s3,2))/(2*s1*s2);
	w2 = (pow(s3,2)+pow(s2,2)-pow(s1,2))/(2*s3*s2);
	w3 = (pow(s3,2)+pow(s1,2)-pow(s2,2))/(2*s3*s1);
	u1 = acos (w1);
	u2 = acos (w2);
	u3 = acos (w3);
	if (((u1-u2)>E) && ((u1-u3)>E)) 
	{
		u1 = (u1*180) / PI;
		hm_1 = u1;
		s_1 = (int) hm_1;
		hm_1 -= s_1;
		hm_1 *=60;
		m_1 = (int) hm_1;
		hm_1 -= m_1;
		hm_1 *=60;
		t_1 = (int) hm_1;
	}
	else if (((u2-u1)>E) && ((u2-u3)>E)) 
	{
		u2 = (u2*180) / PI;
		hm_2 = u2;
		s_2 = (int) hm_2;
		hm_2 -= s_2;
		hm_2 *=60;
		m_2 = (int) hm_2;
		hm_2 -= m_2;
		hm_2 *=60;
		t_2 = (int) hm_2;
	}
	else
	{
		u3 = (u3*180) / PI;
		hm_3 = u3;
		s_3 = (int) hm_3;
		hm_3 -= s_3;
		hm_3 *=60;
		m_3 = (int) hm_3;
		hm_3 -= m_3;
		hm_3 *=60;
		t_3 = (int) hm_3;
	}
	if ((fabs (u1-180)<=E) || (fabs (u2-180)<=E) || (fabs(u3-180)<=E))
		printf ("Linija");
	else if ((fabs (s1-s2)<=E) && (fabs(s1-s3)<=E) && (fabs(s2-s3)<=E))
		printf ("Jednakostranicni");
	else if (pp1)
		{
			if (((fabs (s1-s2)<=E) && (fabs (s1-s3)>E)) || ((fabs (s1-s3)<=E) && (fabs (s1-s2)>E)) || ((fabs(s2-s3)<=E) && (fabs (s1-s2)>E)))
			{
				if ((fabs (u1-90)<=E) || (fabs (u2-90)<=E) || (fabs (u3-90)<=E))
					printf ("Pravougli\nJednakokraki");
				else 
					printf ("Jednakokraki");
			}
			else 
				pp1=0;
			if (pp1==0)
				{
					if ((fabs (s1-s2)>E) && (fabs (s1-s3)>E) && (fabs (s2-s3)>E))
					{
						if ((fabs (u1-90)<=E) || (fabs (u2-90)<=E) || (fabs (u3-90)<=E))
							printf ("Pravougli\nRaznostranicni");
						else 
							printf ("Raznostranicni");
					}
				}
		}
	if (((u1-u2)>E) && ((u1-u3)>E)) 
			printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", s_1, m_1, t_1);
	else if (((u2-u1)>E) && ((u2-u3)>E)) 
			printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", s_2, m_2, t_2);
	else
			printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", s_3, m_3, t_3);
	return 0;
}