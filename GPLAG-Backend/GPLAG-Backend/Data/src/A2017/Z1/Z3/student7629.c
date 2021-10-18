#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main()
{
    double a=0,b=0,c=0,x1=0,x2=0,x1rjesenje=0,x2rjesenje=0,diskriminanta=0,razlika=0;
    
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    diskriminanta=(b*b-4*a*c);
    if(a>0)
    {
        x1=((-b-sqrt(diskriminanta))/(2*a));
        x2=((-b+sqrt(diskriminanta))/(2*a));
    }
    if(a<0)
    {
        x1=((-b+sqrt(diskriminanta))/(2*a));
        x2=((-b-sqrt(diskriminanta))/(2*a));
    }
    if(a==0)
    {
        printf("Data jednacina je linearna!");
        return 0;
    }
    if(4*a*c>b*b)
    {
        printf("Rjesenja su imaginarni brojevi.");
        return 0;
    }
    else
    {
    do
    {
    printf("Unesite rjesenje x1: ");
    scanf("%lf",&x1rjesenje);
    razlika=fabs((x1rjesenje-x1));
    if(razlika<EPSILON)
    {
    printf("Tacno\n");
    }
    else{
    if(x1rjesenje>=x1)
    {
        if(razlika<=0.1){
            
    printf("Priblizno vece\n");
 
    }
    else
    {
        printf("Vece\n");
    }
    }
    if(x1rjesenje<=x1)
    {
        if(razlika>=0.1)
        {
    printf("Manje\n");
    
    }
   else
    {
    printf("Priblizno manje\n");
    }
    
     }
    }
    }
    while(razlika>=EPSILON);
    do{
        printf("\nUnesite rjesenje x2: ");
        scanf("%lf",&x2rjesenje);
        razlika=fabs((x2rjesenje-x2));
        if(razlika<=EPSILON)
        {
        printf("Tacno");
        }
        else
        {
        if(x2rjesenje>=x2)
        {
            if(razlika<=0.1)
            {
        printf("Priblizno vece");
       
        }
        else
        {
        printf("Vece");
        }
        }
        if(x2rjesenje<=x2)
        {
            if(razlika>=0.1)
            {
            printf("Manje");
            
        }
        else
        {
            printf("Priblizno manje");
        }
        }
        }
        
        }while(razlika>=EPSILON);
    
    };
    return 0;
    }
