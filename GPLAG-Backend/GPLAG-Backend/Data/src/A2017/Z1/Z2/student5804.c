#include <stdio.h>
#include <math.h>
#define e 0.0001
#define pi 3.1415926535897932384626433
#define dev 1.5707963267948966

int main() {
//	printf("Zadaća 1, Zadatak 2");
    double a1, b1, a2, b2, c1, c2, a , b, c, cosalfa, cosbeta, cosgama, alfa, beta, gama, alfa1, beta1, gama1;
    int stepenialfe, stepenibete, stepenigame, minutealfe, minutebete, minutegame, sekundealfe, sekundebete, sekundegame, najvecistepeni, najveceminute, najvecesekunde, enter=0;
    double pomoc1, pomoc2, pomoc3, pomoc4, pomoc5, pomoc6;
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf%lf", &a1, &a2);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf%lf", &b1, &b2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf%lf", &c1, &c2);
    
    a=sqrt((c1-b1)*(c1-b1) + (c2-b2)*(c2-b2));
    b=sqrt((c1-a1)*(c1-a1) + (c2-a2)*(c2-a2));
    c=sqrt((b1-a1)*(b1-a1) + (b2-a2)*(b2-a2)); 
    
//    printf("\na=%.3f b=%.3f c=%.3f\n", a, b, c);
    
    cosalfa=(b*b+c*c-a*a)/(2*b*c);
    cosbeta=(a*a+c*c-b*b)/(2*a*c);
    cosgama=(a*a+b*b-c*c)/(2*a*b);
    
//    printf("\ncal=%.3f cbet=%.3f cgam=%.3f\n", cosalfa, cosbeta, cosgama);
    
    alfa1=acos(cosalfa);                
    beta1=acos(cosbeta);
    gama1=acos(cosgama);
    
    alfa=acos(cosalfa)*180/pi;                 //RACUNANJEEE RADIJAAANAAA
    beta=acos(cosbeta)*180/pi;
    gama=acos(cosgama)*180/pi;
    
//    printf("\nal=%.3f bet=%.3f gam=%.3f\n", alfa, beta, gama);
    
    stepenialfe=alfa;                                //RACUNANJEEEE RADIJANAAAAA
    pomoc1=(alfa-stepenialfe)*60;
    minutealfe=pomoc1;
    pomoc4=(pomoc1-minutealfe)*60; 
    sekundealfe=pomoc4;
    
    stepenibete=beta;
    pomoc2=(beta-stepenibete)*60;
    minutebete=pomoc2;
    pomoc5=(pomoc2-minutebete)*60;
    sekundebete=pomoc5;
    
    stepenigame=gama;
    pomoc3=(gama-stepenigame)*60;
    minutegame=pomoc3;
    pomoc6=(pomoc3-minutegame)*60;
    sekundegame=pomoc6;
//    printf("\nSTEPENIALFE=%d MINUTEALFE=%d SEKUNDEALFE=%d\n", stepenialfe, minutealfe, sekundealfe);
//    printf("\nSTEPENIBETE=%d MINUTEBETE=%d SEKUNDEBETE=%d\n", stepenibete, minutebete, sekundebete);
//    printf("\nSTEPENIGAME=%d MINUTEGAME=%d SEKUNDEGAME=%d\n", stepenigame, minutegame, sekundegame);
    if((fabs(alfa1-dev)<=e) || (fabs(beta1-dev)<=e) || (fabs(gama1-dev)<=e)){ printf("Pravougli"); enter=1;}
//    if((fabs(alfa1-beta1)<=e) && (fabs(alfa1-gama1)<=e) && (fabs(beta1-gama1)<=e)) printf("Linija");        //LINIJA?????
    if((fabs(((a1*b2)+(b1*c2)+(c1*a2))-((b1*a2)+(c1*b2)+(a1*c2)))/2)-0<=e) printf("Linija");
    else if((fabs(a-b)<=e) && (fabs(a-c)<=e) && (fabs(b-c)<=e)){ if(enter==1) printf("\n"); printf("Jednakostranicni");}
    else if((fabs(a-b)<=e) || (fabs(a-c)<=e) || (fabs(b-c)<=e)){ if(enter==1) printf("\n"); printf("Jednakokraki");}
    else { if(enter==1) printf("\n"); printf("Raznostranicni");}
    najvecistepeni=stepenialfe;
    najveceminute=minutealfe;
    najvecesekunde=sekundealfe;
    if(stepenibete>najvecistepeni){ najvecistepeni=stepenibete; najveceminute=minutebete; najvecesekunde=sekundebete;}
    if(stepenigame>najvecistepeni){ najvecistepeni=stepenigame; najveceminute=minutegame; najvecesekunde=sekundegame;}
    if(stepenibete==najvecistepeni){ if(minutebete>najveceminute){ najvecistepeni=stepenibete; najveceminute=minutebete; najvecesekunde=sekundebete;}}
    if(stepenigame==najvecistepeni){ if(minutegame>najveceminute){ najvecistepeni=stepenigame; najveceminute=minutegame; najvecesekunde=sekundegame;}}
    if(stepenibete==najvecistepeni){ if(minutebete==najveceminute){ if(sekundebete>najvecesekunde){ najvecistepeni=stepenibete; najveceminute=minutebete; najvecesekunde=sekundebete;}}}
    if(stepenigame==najvecistepeni){ if(minutegame==najveceminute){ if(sekundegame>najvecesekunde){ najvecistepeni=stepenigame; najveceminute=minutegame; najvecesekunde=sekundegame;}}}
    printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", najvecistepeni, najveceminute, najvecesekunde);
    
	return 0;
}
