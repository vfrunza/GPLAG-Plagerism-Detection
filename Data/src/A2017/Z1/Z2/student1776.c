#include <stdio.h>
#include <math.h> 
#define PI 3.14159265358979 
#define EPSILON 0.0001

main() {
  float x1, y1, x2, y2, x3, y3;
  float a, b, c, u, z, g, p, r, v,min1, min2, min3, sec1, sec2, sec3;
  float ugao1, ugao2, ugao3;
  printf("Unesite koordinate tacke t1: "); 
  scanf("%f %f",&x1,&y1);
  printf("Unesite koordinate tacke t2: ");
  scanf("%f %f",&x2,&y2);
  printf("Unesite koordinate tacke t3: "); 
  scanf("%f %f",&x3,&y3);
 
  a=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  b=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)); 
  c=sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
  
 if(((fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)))/2)==0){
    printf("Linija");
    printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    return 0;

  }
  if((fabs(a*a-b*b-c*c)<=EPSILON) || (fabs(c*c-b*b-a*a)<=EPSILON) || (fabs(b*b-c*c-a*a)<=EPSILON)){
    printf("Pravougli\n");
  }
  
  if((fabs(a-b)<=EPSILON) && (fabs(b-c)<=EPSILON)){
    printf("Jednakostranicni\n");
  }
  if(((fabs(a-b)<=EPSILON) && (fabs(b-c)>EPSILON)) || ((fabs(a-c)<=EPSILON) && (fabs(c-b)>EPSILON))|| ((fabs(b-c)<=EPSILON) && (fabs(b-a)>EPSILON))){
    printf("Jednakokraki\n");
  }
  if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON){
    printf("Raznostranicni\n");
  }
  
  ugao1=acos((b*b+c*c-a*a)/(2*b*c));
  ugao1=(180*ugao1)/(PI);
  z=ugao1-(int)ugao1;
  min1=z*60;
  g=min1-(int)min1;
  sec1=g*60;
  
  ugao2=acos((a*a+c*c-b*b)/(2*a*c));
  ugao2=(180*ugao2)/(PI);
  p=ugao2 -(int)ugao2;
  min2=p*60;
  r=min2-(int)min2;
  sec2=r*60;
  
  ugao3=acos((a*a+b*b-c*c)/(2*a*b));
  ugao3=(ugao3*180)/(PI);
  v=ugao3-(int)ugao3;
  min3=v*60;
  u=min3-(int)min3;
  sec3=u*60;
  
  if(((a>=b) && (b>=c)) || ((a>=c) &&(c>=b))){
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)ugao1, (int)min1, (int)sec1);
  }
  else if(((b>=a) && (a>=c)) || ((b>=c) && (c>=a))){
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)ugao2, (int)min2,  (int)sec2);
  }
  else if(((c>=b)&& (b>=a)) || ((c>=a)&&(a>=b))){
    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)ugao3, (int)min3, (int)sec3);
  }
  return 0;
}
