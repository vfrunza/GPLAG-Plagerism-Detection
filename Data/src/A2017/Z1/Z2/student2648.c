#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define EPSILON 0.0001

int main() {
    
    double x1,x2,x3,y1,y2,y3,d1,d2,d3,alfa1,beta1,gama1,alfa2,alfa3,alfa4,beta2,beta3,beta4,gama2,gama3,gama4,k1,k2;
    int  alfa_stepen,alfa_minuta,alfa_sekunda,beta_minuta,beta_sekunda,beta_stepen,gama_stepen,gama_minuta,gama_sekunda;
    
    
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &x3, &y3);
    
   
    
    d1 = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    d2 = sqrt(pow((x3-x2),2) + pow((y3-y2),2));
    d3 = sqrt(pow((x3-x1),2) +  pow((y3-y1),2));
    
    k1=(y2-y1)/(x2-x1);
    k2=(y3-y2)/(x3-x2);
    
    
    
    
    
   
    
    
    
    alfa1 = acos((d3*d3+d2*d2-d1*d1)/(2*d3*d2));
    beta1 = acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
    gama1 = acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
    
    alfa2 = (alfa1*(180/PI));
    beta2 = (beta1*(180/PI));
    gama2 = (gama1*(180/PI));
    
     alfa_stepen = (int)alfa2;
     alfa3 = ((alfa2-alfa_stepen)*60);
     gama_stepen = (int)gama2;
    gama3 = ((gama2-gama_stepen)*60);
     beta_stepen = (int)beta2;
    beta3 = ((beta2-beta_stepen)*60);
    
   
    
    
    
    
    
    
    
    
     if (fabs(k1-k2)<EPSILON)
      {
          printf("Linija");
          if ((alfa1>beta1) && (alfa1>gama1))
          { 
              alfa_stepen = (int)alfa2;
              alfa3 = ((alfa2-alfa_stepen)*60);
    
              alfa_minuta = (int)alfa3;
              alfa4 = ((alfa3-alfa_minuta)*60);
    
              alfa_sekunda = (int)alfa4;
              printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa_stepen,alfa_minuta,alfa_sekunda);
         
          }
     
           else if ((beta1>alfa1) && (beta1>gama1))
          {
         beta_stepen = (int)beta2;
    beta3 = ((beta2-beta_stepen)*60);
    
    beta_minuta = (int)beta3;
    beta4 = ((beta3-beta_minuta)*60);
    
    beta_sekunda = (int)beta4;
     printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta_stepen,beta_minuta,beta_sekunda);
           }
     
     else if ((gama1>alfa1) && (gama1>beta1))
        {
         gama_stepen = (int)gama2;
    gama3 = ((gama2-gama_stepen)*60);
    
    gama_minuta = (int)gama3;
    gama4 = ((gama3-gama_minuta)*60);
    
    gama_sekunda = (int)gama4;
    printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama_stepen,gama_minuta,gama_sekunda);
         }
      }
     
    
    
    
    
    
   else  if ((fabs(d1-d2)<EPSILON) && (fabs(d1-d3)<EPSILON) && (fabs(d2-d3)<EPSILON))
     {
         printf("Jednakostranicni");
         if ((alfa1>beta1) && (alfa1>gama1))
          { 
              alfa_stepen = (int)alfa2;
              alfa3 = ((alfa2-alfa_stepen)*60);
    
              alfa_minuta = (int)alfa3;
              alfa4 = ((alfa3-alfa_minuta)*60);
    
              alfa_sekunda = (int)alfa4;
              printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa_stepen,alfa_minuta,alfa_sekunda);
         
          } 
     
           else if ((beta1>alfa1) && (beta1>gama1))
          {
         beta_stepen = (int)beta2;
    beta3 = ((beta2-beta_stepen)*60);
    
    beta_minuta = (int)beta3;
    beta4 = ((beta3-beta_minuta)*60);
    
    beta_sekunda = (int)beta4;
     printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta_stepen,beta_minuta,beta_sekunda);
           }
           
     
     else if ((gama1>alfa1) && (gama1>beta1))
        {
         gama_stepen = (int)gama2;
    gama3 = ((gama2-gama_stepen)*60);
    
    gama_minuta = (int)gama3;
    gama4 = ((gama3-gama_minuta)*60);
    
    gama_sekunda = (int)gama4;
    printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama_stepen,gama_minuta,gama_sekunda);
         }
         
     }
     
    
     
     
     
     
     
      
     else if (((fabs(d1-d2)<EPSILON) && alfa_stepen!=180 && gama_stepen!=180 && beta_stepen!=180) || ((fabs(d1-d3)<EPSILON) && alfa_stepen!=180 && gama_stepen!=180 && beta_stepen!=180)|| ((fabs(d2-d3)<EPSILON) && alfa_stepen!=180 && gama_stepen!=180 && beta_stepen!=180))
     {
        
        
        if ((d2==(sqrt(pow(d1,2) + pow(d3,2)))) || (d3==(sqrt(pow(d1,2) + pow(d2,2)))) || (d1==(sqrt(pow(d2,2) + pow(d3,2)))))
          { printf("Pravougli\n"); }
          
           printf("Jednakokraki");
          
          if ((alfa1>beta1) && (alfa1>gama1))
          { 
              alfa_stepen = (int)alfa2;
              alfa3 = ((alfa2-alfa_stepen)*60);
    
              alfa_minuta = (int)alfa3;
              alfa4 = ((alfa3-alfa_minuta)*60);
    
              alfa_sekunda = (int)alfa4;
              printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa_stepen,alfa_minuta,alfa_sekunda);
         
          }
     
           else if ((beta1>alfa1) && (beta1>gama1))
          {
         beta_stepen = (int)beta2;
    beta3 = ((beta2-beta_stepen)*60);
    
    beta_minuta = (int)beta3;
    beta4 = ((beta3-beta_minuta)*60);
    
    beta_sekunda = (int)beta4;
     printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta_stepen,beta_minuta,beta_sekunda);
           }
     
     else if ((gama1>alfa1) && (gama1>beta1))
        {
         gama_stepen = (int)gama2;
    gama3 = ((gama2-gama_stepen)*60);
    
    gama_minuta = (int)gama3;
    gama4 = ((gama3-gama_minuta)*60);
    
    gama_sekunda = (int)gama4;
    printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama_stepen,gama_minuta,gama_sekunda);
         }
     }
     
     
     
     
      
      else 
      {   
            if ((d2==(sqrt(pow(d1,2) + pow(d3,2)))) || (d3==(sqrt(pow(d1,2) + pow(d2,2)))) || (d1==(sqrt(pow(d2,2) + pow(d3,2)))))
          { printf("Pravougli\n"); }
            printf("Raznostranicni");
          
          
          if ((alfa1>beta1) && (alfa1>gama1))
          { 
              alfa_stepen = (int)alfa2;
              alfa3 = ((alfa2-alfa_stepen)*60);
    
              alfa_minuta = (int)alfa3;
              alfa4 = ((alfa3-alfa_minuta)*60);
    
              alfa_sekunda = (int)alfa4;
              printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", alfa_stepen,alfa_minuta,alfa_sekunda);
         
          }
     
           else if ((beta1>alfa1) && (beta1>gama1))
          {
         beta_stepen = (int)beta2;
    beta3 = ((beta2-beta_stepen)*60);
    
    beta_minuta = (int)beta3;
    beta4 = ((beta3-beta_minuta)*60);
    
    beta_sekunda = (int)beta4;
     printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", beta_stepen,beta_minuta,beta_sekunda);
           }
     
     else if ((gama1>alfa1) && (gama1>beta1))
        {
         gama_stepen = (int)gama2;
    gama3 = ((gama2-gama_stepen)*60);
    
    gama_minuta = (int)gama3;
    gama4 = ((gama3-gama_minuta)*60);
    
    gama_sekunda = (int)gama4;
    printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", gama_stepen,gama_minuta,gama_sekunda);
         }
          
          
      }
      
      return 0;
}
     
     
     
      