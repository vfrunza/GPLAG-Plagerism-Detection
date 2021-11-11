#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define pi 3.14159265358979323846
#define e 0.0001
int main ()
{
    float xa,ya,xb,yb,xc,yc,cosAlfa,cosBeta,cosGama;
    double alfa,beta,gama,a,b,c;
    bool jednakokraki=false;
    int alfaStepeni, alfaMinute, alfaSekunde, betaStepeni, betaMinute, betaSekunde, gamaStepeni, gamaMinute, gamaSekunde;
    printf("Unesite koordinate tacke t1: ");
    scanf("%f", &xa);
    scanf("%f", &ya);
    printf("Unesite koordinate tacke t2: ");
    scanf("%f", &xb);
    scanf("%f", &yb);
    printf("Unesite koordinate tacke t3: ");
    scanf("%f", &xc);
    scanf("%f", &yc);
    b=sqrt(pow((xa-xc),2)+pow((ya-yc),2));
           a=sqrt(pow((xb-xc),2)+pow((yb-yc),2));
    c=sqrt(pow((xa-xb),2)+pow((ya-yc),2));
    cosAlfa=(b*b+c*c-a*a)/(2*b*c);
    cosBeta=(a*a+c*c-b*b)/(2*a*c);
    cosGama=(b*b+a*a-c*c)/(2*a*c);
    alfa=acos(cosAlfa)*360/(2*pi);
    beta=acos(cosBeta)*360/(2*pi);
    gama=acos(cosGama)*360/(2*pi);
    int TotalnoSekundiAlfa=round(alfa*60*60);
    int SekundiAlfa=TotalnoSekundiAlfa%60;
    int MinutaAlfa=(TotalnoSekundiAlfa/60);
    int StepeniAlfa=TotalnoSekundiAlfa/(60*60);
    int TotalnoSekundiBeta=round(beta*60*60);
    int SekundiBeta=TotalnoSekundiBeta%60;
    int MinutaBeta=(TotalnoSekundiBeta/60)%60;
    int StepeniBeta=TotalnoSekundiBeta/(60*60);
    int TotalnoSekundiGama=round(gama*60*60);
    int SekundiGama=TotalnoSekundiGama%60;
    int MinutaGama=(TotalnoSekundiGama/60)%60;
    int StepeniGama=TotalnoSekundiGama/(60*60);
    if(fabs(alfa-180)<e || fabs(beta-180)<e || fabs(gama-180)<e) {
        printf("Linija\n");

    } 
    
    if((fabs(alfa-90)<e || fabs(beta-90)<e || fabs(gama-90)<e) &&(fabs(a-c)<e || fabs(a-b)<e || fabs(b-c)<e))
    {
        printf("Pravougli\n");
        printf("Jednakokraki\n");
         if(alfa>beta && alfa>gama) {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekindi.", StepeniAlfa, MinutaAlfa, SekundiAlfa);
        } else if(beta>alfa && beta>gama) {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniBeta, MinutaBeta, SekundiBeta);

        } else {
            printf("Najveci ugao ima &d stepeni, %d minuta i %d sekundi.", StepeniGama, MinutaGama, SekundiGama);
        }
        jednakokraki=true;
    }
    else if((fabs(alfa-90)<e || fabs(beta-90)<e || fabs(gama-90)<e) && jednakokraki!=true)
    {
        printf("Pravougli\n");
        if(alfa>beta && alfa>gama)
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniAlfa, MinutaAlfa,SekundiAlfa);
        }
        else if(beta>alfa && beta>gama)
        {
            printf("Najveci ugao ima %d stepeni %d minuta i %d sekundi.", StepeniBeta, MinutaBeta, SekundiBeta);
            
        }
        else
        {
            printf("Najveci ugao ima %d stepeni %d minuta i %d sekundi.", StepeniGama, MinutaGama, SekundiGama);
        }
    }
    else if(fabs(alfa-60)<e && fabs(beta-60)<e && fabs(gama-60)<e)
    {
        printf("Jednakostranicni");
        if(alfa>beta && alfa>gama)
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniAlfa, MinutaAlfa, SekundiAlfa);
        }
    else
    {
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniGama, MinutaGama, SekundiGama);
    }
    }
    else if(fabs(a-c)<e || fabs(a-b)<e || fabs(b-c)<e)
    {
        printf("Jednakokraki\n");
        if(alfa>beta && alfa>gama)
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniAlfa, MinutaAlfa, SekundiAlfa);
        }
        else if(beta>alfa && beta>gama)
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniBeta, MinutaBeta, SekundiBeta);
            
        }
        else
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniGama, MinutaGama, SekundiGama);
        }
    }
    else 
    {
        printf("Raznostranicni\n");
        if(alfa>beta && alfa>gama)
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniAlfa, MinutaAlfa, SekundiAlfa);
        }
        else if(beta>alfa && beta>gama)
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniBeta, MinutaBeta, SekundiBeta);
        }
        else
        {
            printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", StepeniGama, MinutaGama, SekundiGama);
        }
    }
    return 0;
    }