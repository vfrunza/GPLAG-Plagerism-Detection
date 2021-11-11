#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
int main() {
    
    double cijena1,cijena2,cijena3,cijena;
    int brojacp=0,brojach=0,brojacc=0;
    char tarik,bojan,mirza,novi_red;
    double istina=1;
     
     
     double p1=6.80;
     double h1=3.30;
     double c1=5.00;

    double p2=8.00;
     double h2=3.00;
     double c2=3.90;

    double p3=5.30;
     double h3=5.00;
     double c3=6.00;
     
 
    
     

printf("Unesite jelo za Tarika: ");
scanf("%c",&tarik);
scanf("%c",&novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&bojan);
    scanf("%c",&novi_red);

        printf("Unesite jelo za Mirzu: ");
        scanf("%c",&mirza);
        scanf("%c",&novi_red);
    



switch(tarik)
{
    case 'P':
    brojacp=brojacp+1;
    break;
        case 'H':
        brojach=brojach+1;
        break;
            case 'C':
            brojacc=brojacc+1;
            break;
    default:
    printf("Unijeli ste pogresnu vrijednost!\n");
    
}


     
switch(bojan)
{
    case 'P':
    brojacp=brojacp+1;
    break;
        case 'H':
        brojach=brojach+1;
        break;
            case 'C':
            brojacc=brojacc+1;
            break;
    default:
    printf("Unijeli ste pogresnu vrijednost!\n");
   
}
     
     
switch(mirza)
{
    case 'P':
    brojacp=brojacp+1;
    break;
        case 'H':
        brojach=brojach+1;
        break;
            case 'C':
            brojacc=brojacc+1;
            break;
    default:
    printf("Unijeli ste pogresnu vrijednost!\n");
   
}

     
 
     
     
     cijena1=brojacp*p1+brojach*h1+brojacc*c1;
      cijena2=brojacp*p2+brojach*h2+brojacc*c2;
       cijena3=brojacp*p3+brojach*h3+brojacc*c3;
     
        
     
  if ((brojacp*p1>brojach*h1) && (brojacp*p1>brojacc*c1))
  cijena=brojacp*p1*0.9+brojach*h1+brojacc*c1;
  else if ((brojach*h1<brojacp*p1) && (brojach*h1>brojacc*c1))
  cijena=brojacp*p1*0.9+brojach*h1+brojacc*c1;
    else if ((brojach*h1>brojacp*p1) && (brojach*h1>brojacc*c1))
  cijena=brojacp*p1+brojach*h1*0.9+brojacc*c1;
    else if ((brojacc*c1>brojach*h1) && (brojacc*c1>brojacp*p1))
  cijena=brojacp*p1*0.9+brojach*h1+brojacc*c1;
  
  

 double min=cijena1;
  
   
  if (cijena2<min) min=cijena2;
        else if (cijena3<=min) min=cijena3;
  

    
    
    
                
     if (fabs(cijena1-min)<epsilon) { 
         printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1); 
         istina=0;
         
     }
        else if(fabs(cijena2-min)<epsilon) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);
            else if(fabs(cijena3-min)<epsilon) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
    
    
      if(cijena<min && cijena<cijena1 && istina==1) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena);
      
               
               
    
        
     
     
     
     
    
	
	
	
	
	
	return 0;
}
