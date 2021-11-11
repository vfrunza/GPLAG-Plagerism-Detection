#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.141592654
int main() {
  double  xA,yA,xB,yB,xC,yC;
   float dAB=0,dAC=0,dBC=0;
 float str1=0,str2=0,str3=0;
    double ugao1=0,ugao2=0,ugao3=0;
    int stepeni1,minute1,sekunde;
  double ugaoMAX;
  
    
   printf("Unesite koordinate tacke t1: ");
   scanf("%lf %lf",&xA,&yA);
   printf("Unesite koordinate tacke t2: ");
   scanf("%lf %lf",&xB,&yB);
   printf("Unesite koordinate tacke t3: ");
   scanf("%lf %lf",&xC,&yC);
   

   dAB+=sqrt(pow(xB-xA,2)+pow(yB-yA,2));
    dAC+=sqrt(pow(xC-xA,2)+pow(yC-yA,2));
    dBC+=sqrt(pow(xC-xB,2)+pow(yC-yB,2));
    str1+= dAC*dAC+dBC*dBC;
    str2+=dAB*dAB+dAC*dAC;
    str3+=pow(dAB,2)+pow(dBC,2);
   
   
   
   ugao1+=acos((pow(dAB,2)+pow(dAC,2)-pow(dBC,2))/(2*dAB*dAC))*180/PI;
	 ugao2+=acos((pow(dAC,2)+pow(dBC,2)-pow(dAB,2))/(2*dAC*dBC))*180/PI;
	 ugao3+=acos((pow(dBC,2)+pow(dAB,2)-pow(dAC,2))/(2*dBC*dAB))*180/PI;

	 
	 if(ugao1>ugao2 && ugao1>ugao3)
	 { ugaoMAX=ugao1;
	 }else if(ugao2>ugao1 && ugao2 > ugao3){
	     ugaoMAX=ugao2; 
	 }else{
	     ugaoMAX=ugao3;
	 }
	 
	
	 stepeni1=(int)(ugaoMAX);
	
	 minute1=(int)((ugaoMAX-stepeni1)*60);

	 sekunde=(int)((ugaoMAX-stepeni1-minute1/60.0)*3600);
   
   if(stepeni1>175){
   printf("Linija\n");
   printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
   return 1;}
   if( (fabs(dAB-sqrt(str1))<EPSILON || fabs(dBC-sqrt(str2))<EPSILON || fabs(dAC-sqrt(str3))<EPSILON) && (fabs(dAB-dAC)>EPSILON && fabs(dAC-dBC)>EPSILON && fabs(dAB-dBC)>EPSILON)  )
     	{printf("Pravougli\n");
     	printf("Raznostranicni\n");
     	printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
     	 return 1;
     	}
     	
     	
     	if(fabs(dAB-sqrt(str1))<EPSILON || fabs(dBC-sqrt(str2))<EPSILON || fabs(dAC-sqrt(str3))<EPSILON )
printf("Pravougli\n");  
	
  if(fabs(dAB-dAC)<EPSILON && fabs(dAC-dBC)<EPSILON && fabs(dAB-dBC)<EPSILON)
        printf("Jednakostranicni\n");
        
        else if(fabs(dAB-dAC)<EPSILON || fabs(dAC-dBC)<EPSILON || fabs(dAB-dBC)<EPSILON)
	printf("Jednakokraki\n"); 
	
 else if(fabs(dAB-dAC)>EPSILON && fabs(dAC-dBC)>EPSILON && fabs(dAB-dBC)>EPSILON)
	 printf("Raznostranicni\n");
	 

	 
	
	 
	 printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni1,minute1,sekunde);

	return 0;
}
