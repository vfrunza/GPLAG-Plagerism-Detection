#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define epsilon 0.0001

int main() 
{
    double x1, x2, x3, y1, y2, y3, a, b, c;
    int stepeni, minute, sekunde;
    double alfa, beta, gama, step;
    printf ("Unesite koordinate tacke t1: ");
    scanf ("%lf %lf", &x1, &y1);
    printf ("Unesite koordinate tacke t2: ");
    scanf ("%lf %lf", &x2, &y2);
    printf ("Unesite koordinate tacke t3: ");
    scanf ("%lf %lf", &x3, &y3);
    
    //printf ("t1(%g %g)", x1, y1); printf ("t2(%g %g)", x2, y2); printf ("t3(%g %g)", x3, y3);
    
    a = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ); //printf ("%g\n", a);
    b = sqrt( (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2) ); //printf ("%g\n", b);
    c = sqrt( (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) ); //printf ("%g\n", c);
    
    alfa = acos((b*b + c*c - a*a) / (2*b*c)); //printf ("al = %d ", alfa);
    beta = acos((a*a + c*c - b*b) / (2*a*c)); //printf ("be = %d ", beta);
    gama = acos((a*a + b*b - c*c) / (2*a*b)); //printf ("ga = %d ", gama);
    
    if (alfa < beta && alfa < gama) step = alfa;
    else if (beta < gama && beta < alfa) step = beta;
    else if (gama < alfa && gama < beta) step = gama;
    //step = (int)step;
    step = (step * 180/PI);
    stepeni = (int)step *60;
    sekunde = (int) ( (step-stepeni) * 60);
    minute = (int) ( ( ( (step-stepeni) *60) - sekunde) * 60);
    //minute = stepeni * 60;
    //sekunde = minute * 60;
    
    
    // if (((fabs(a)!=fabs(b) && fabs(a)!=fabs(c) && fabs(b)==fabs(c)) || (fabs(a)==fabs(b) && fabs(b)!=fabs(c) && fabs(c)!=fabs(a)) || (c==a && a!=b && b!=c)) && (c*c == a*a + b*b || b*b == a*a + c*c || a*a == c*c + b*b))
    // {
    //     printf ("Pravougli\n");
    //     printf ("Jednakokraki\n");
    //     printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    // }
    // else if ((0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) == 0)
    // {
    //     printf ("Linija\n");
    //     printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    // }
    // else if (fabs(a) != fabs(b) && fabs(b) != fabs(c) && fabs(c) != fabs(a))
    // {
    //     printf ("Raznostranicni\n");
    //     printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    // }
    // else if (fabs(a)==fabs(b) && fabs(b)==fabs(c) && fabs(c)==fabs(a))
    // {
    //     printf ("Jednakostranicni\n");
    //     printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    // }
    // else if ( (fabs(a)!=fabs(b) && fabs(b)==fabs(c) && fabs(c)!=fabs(a) ) || (fabs(a)==fabs(b) && fabs(b)!=fabs(c) && fabs(c)!=fabs(a) ) || (fabs(a)!=fabs(b) && fabs(b)!=fabs(c) && fabs(c)==fabs(a) ) )
    // {
    //     printf ("Jednakokraki\n");
    //     printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    // }
    // else if (c*c == a*a + b*b || b*b == a*a + c*c || a*a == c*c + b*b)
    // {
    //     printf ("Pravougli\n");
    //     printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    // }
    
    if ( (fabs(a - b) <= epsilon) && (fabs(b - c) <= epsilon) && (fabs(c - a) <= epsilon) ) 
    {
        printf ("Jednakostranicni\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if ( ( (fabs(c*c - a*a - b*b) <= epsilon) || (fabs(b*b - c*c - a*a) <= epsilon) || (fabs(a*a - b*b - c*c) <= epsilon) ) && ( ( !(fabs(a - b) <= epsilon) && (fabs(b - c) <= epsilon) && (fabs(c - a) <= epsilon) ) || ( !(fabs(a - b) <= epsilon) && !(fabs(b - c) <= epsilon) && (fabs(c - a) <= epsilon) ) || ( (fabs(a - b) <= epsilon) && !(fabs(b - c) <= epsilon) && !(fabs(c - a) <= epsilon) ) ) )
    {
        printf ("Pravougli\n");
        printf ("Jednakokraki\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if ( (fabs(a + b - c) < epsilon) ) // || (fabs(b - a - c) <= epsilon) || (fabs(c - b - a) <= epsilon))
    {
        printf ("Linija\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if ( ( !(fabs(a - b) <= epsilon) && (fabs(b - c) <= epsilon) && (fabs(c - a) <= epsilon) ) || ( !(fabs(a - b) <= epsilon) && !(fabs(b - c) <= epsilon) && (fabs(c - a) <= epsilon) ) || ( (fabs(a - b) <= epsilon) && !(fabs(b - c) <= epsilon) && !(fabs(c - a) <= epsilon) ) )
    {
        printf ("Jednakokraki\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if ( ( (fabs(c*c - a*a - b*b) <= epsilon) || (fabs(b*b - c*c - a*a) <= epsilon) || (fabs(a*a - b*b - c*c) <= epsilon) ) && ( !(fabs(a - b) <= epsilon) && !(fabs(b - c) <= epsilon) && !(fabs(c - a) <= epsilon) ) )
    {
        printf ("Pravougli\n");
        printf ("Raznostranicni\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if ( (fabs(c*c - a*a - b*b) <= epsilon) || (fabs(b*b - c*c - a*a) <= epsilon) || (fabs(a*a - b*b - c*c) <= epsilon) )
    {
        printf ("Pravougli\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if ( !(fabs(a - b) <= epsilon) && !(fabs(b - c) <= epsilon) && !(fabs(c - a) <= epsilon) )
    {
        printf ("Raznostranicni\n");
        printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    
    
	return 0;
}
