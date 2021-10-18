#include <stdio.h>

int fx(int a, int b) 
{    
    int r;
    r=b++;   
    return r; 
    
}
int main()
{   
    int X[4][4]={1,2,3,4};    
    int Y[4]={50,60,70,80};    
    char g[]="Travnik";    
    int e=0,f=0,l;    
   
    printf("%d\n",f);    
    l=fx(e,&e);   
    printf("%d\n",l);   
       
    return 0; 
    
}