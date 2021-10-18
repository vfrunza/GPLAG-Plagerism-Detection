#include<stdio.h>
#include<math.h>
#define PI 3.14

int main(){
    float X1,X2,X3,Y1,Y2,Y3,a,b,c,a2,b2,c2;
    double max_ugao=0;
    double ugao,stepen,minuta,sekunda,minuta1,sekunda1,alfa,beta,gama;
    
    printf("Unesite koordinate tacke t1: ");
    scanf("%f %f", &X1,&Y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%f %f", &X2,&Y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%f %f", &X3,&Y3);
    
    a=sqrt((X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1));
    b=sqrt((X3-X2)*(X3-X2)+(Y3-Y2)*(Y3-Y2));
    c=sqrt((X3-X1)*(X3-X1)+(Y3-Y1)*(Y3-Y1));
    a2=a*a;
    b2=b*b;
    c2=c*c;
    alfa=acos((b*b+c*c-a*a)/(2*b*c));
    beta=acos((a*a+c*c-b*b)/(2*a*c));
    gama=acos((a*a+b*b-c*c)/(2*a*b));
    if(alfa>max_ugao)max_ugao=alfa;
    else if(beta>max_ugao)max_ugao=beta;
    else if(gama>max_ugao)max_ugao=gama;
    
    
    if((X2-X1)/(X3-X1)==(Y2-Y1)/(Y3-Y1)) printf("Linija\n");
    if(a==b && b==c && c==a) printf("Jednakostranicni\n");
    if(c2==a*a+b*b || b2==a*a+c*c || a2==b*b+c*c || alfa==90 || beta==90 || gama==90)  printf("Pravougli\n");
    if(((a==b && c!=a) || (b==c && a!=b) || (c==a && b!=a)) && (X2-X1)/(X3-X1)!=(Y2-Y1)/(Y3-Y1) ) printf("Jednakokraki\n");
    if(a!=b && b!=c && c!=a ) printf("Raznostranicni\n");
    
    
    
    ugao=(max_ugao)*(180/(4*atan(1)));/*ugao u stepenima*/
    stepen=(int)(ugao);
    minuta=(ugao-(int)ugao)*60;
    sekunda=(minuta-(int)minuta)*60;
    minuta1=(int)minuta;
    sekunda1=(int)sekunda;
    if((X2-X1)/(X3-X1)==(Y2-Y1)/(Y3-Y1) ){
        stepen=180;
        minuta=0;
        sekunda=0;}
    
       if( c2==a*a+b*b || b2==a*a+c*c || a2==b*b+c*c){
        minuta=0;
        sekunda=0;
    }
    printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",stepen,minuta1,sekunda1);
    
    
    
    
return 0;
}
    
    
    
    
    
    
    
    
    
    