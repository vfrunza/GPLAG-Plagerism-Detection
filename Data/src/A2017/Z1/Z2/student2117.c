#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define epsilon 0.0001
#define PI 3.14159

int main() {
    double a,b,c,x1,x2,x3,y1,y2,y3,AL,BE,GA,s,m,sec;
    
         /* Unos koordinata tačaka*/
        printf("Unesite koordinate tacke t1: ");
        scanf("%lf %lf",&x1,&y1);
       
        printf("Unesite koordinate tacke t2: ");
        scanf("%lf %lf",&x2,&y2);
       
        printf("Unesite koordinate tacke t3: ");
        scanf("%lf %lf",&x3,&y3);
        
        /* Stranice trougla a, b i c po formuli za udaljenost tačaka u koordinatnom sistemu */
        
        a=sqrt(fabs((x1-x2)*(x1-x2))+fabs((y1-y2)*(y1-y2)));
        b=sqrt(fabs((x1-x3)*(x1-x3))+fabs((y1-y3)*(y1-y3)));
        c=sqrt(fabs((x2-x3)*(x2-x3))+fabs((y2-y3)*(y2-y3)));
        
        AL=acos((a*a+b*b-c*c)/(2*a*b))*(180/PI);
        BE=acos((a*a+c*c-b*b)/(2*a*c))*(180/PI);
        GA=acos((b*b+c*c-a*a)/(2*b*c))*(180/PI);
        if(((fabs(x1-x2)<epsilon && fabs(x2-x3)<epsilon && fabs(x3-x1)<epsilon) || (fabs(y1-y2)<epsilon && fabs(y2-y3)<epsilon&& fabs(y3-y1)<epsilon))  || (fabs((x2-x1)-(x3-x2))<epsilon) && fabs((y2-y1)-(y3-y2))<epsilon){
            printf("Linija\n");
           printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
           return 0;
        }  
       
        
         else   if (fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) {
             if (fabs(a*a+b*b-c*c)< epsilon || fabs(b*b+c*c-a*a)<epsilon || fabs(c*c+a*a-b*b)<epsilon) {
             printf("Pravougli");
             printf("\nRaznostranicni");
             printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");}
             else {printf("Raznostranicni");
         
        
        if(AL>=GA && AL>=BE )
        { s = (int)(AL);
          m = (int)((AL - (int)(AL))*60);
          sec = (int)((AL - (int)(AL) - m/60)*3600);
          printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",s,m,sec);
        }
        
        else if(BE>=GA && BE>=AL )
        {
            s = (int)(BE);
          m = (int)((BE -(int)(BE))*60);
          sec = (int)((BE-(int)(BE) - m/60)*3600);
          printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",s,m,sec);
            
        }
        
        else if(GA>=BE && GA>=AL )
        {
            s = (int)(GA);
          m = (int)((GA -(int)(GA))*60);
          sec = (int)((GA-(int)(GA) - m/60)*3600);
          printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",s,m,sec);
        } } }
        else if(fabs(a-b)<epsilon && fabs(a-c)<epsilon && fabs(b-c)<epsilon)
            {
            printf("Jednakostranicni");
            printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
        }
        else if(fabs(x1-y1)<epsilon && fabs(x2<y2) && fabs(x3-y3)<epsilon){
            printf("Pravougli");
            printf("\nJednakokraki");
            printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
        }
        else  { printf("Jednakokraki");
        
        if(AL>=GA && AL>=BE )
        { s = (int)(AL);
          m = (int)((AL - (int)(AL))*60);
          sec = (int)((AL - (int)(AL) - m/60)*3600);
          printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",s,m,sec);
        }
        
        else if(BE>=GA && BE>=AL )
        {
            s = (int)(BE);
          m = (int)((BE -(int)(BE))*60);
          sec = (int)((BE-(int)(BE) - m/60)*3600);
          printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",s,m,sec);
            
        }
        
        else if(GA>=BE && GA>=AL )
        {
            s = (int)(GA);
          m = (int)((GA -(int)(GA))*60);
          sec = (int)((GA-(int)(GA) - m/60)*3600);
          printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",s,m,sec);
        }
        }
        
          	return 0;
}
