#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.141592
int main () {
	double t1x,t1y,t2x,t2y,t3x,t3y;
	double prvaStranica,drugaStranica,trecaStranica;
	double hipotenuza,kateta1,kateta2;
	double pitagorinaTeorema;
	double ugaoAlfa,ugaoBeta,ugaoGama;
	double ugaoAlfaRadian,ugaoBetaRadian;
	int stepen,minute,sekunde;
   
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&t3x,&t3y);
	
	prvaStranica=sqrt(pow((t2x-t1x),2) + pow((t2y-t1y),2));
	drugaStranica=sqrt(pow((t3x-t2x),2) + pow((t3y-t2y),2));
	trecaStranica=sqrt(pow((t3x-t1x),2) + pow((t3y-t1y),2));
	if(prvaStranica>drugaStranica){
     if(prvaStranica>trecaStranica) {
     	hipotenuza=prvaStranica;
     	kateta1=drugaStranica;
     	kateta2=trecaStranica;
     } else{
     hipotenuza=trecaStranica;
     kateta1=drugaStranica;
     kateta2=prvaStranica;
     }
    } else if(drugaStranica>trecaStranica){
    	hipotenuza=drugaStranica;
    	kateta1=prvaStranica;
    	kateta2=trecaStranica;
    } else {
        hipotenuza=trecaStranica;
        kateta1=prvaStranica;
        kateta2=drugaStranica;
    }
    
   
    
    ugaoAlfaRadian=acos((pow(kateta1,2)+pow(hipotenuza,2)-pow(kateta2,2))/(2*kateta1*hipotenuza));
    ugaoBetaRadian=acos((pow(kateta2,2)+pow(hipotenuza,2)-pow(kateta1,2))/(2*kateta2*hipotenuza));
    
    
    ugaoAlfa=ugaoAlfaRadian*180/PI;
    ugaoBeta=ugaoBetaRadian*180/PI;
    ugaoGama=180-ugaoAlfa-ugaoBeta;
   pitagorinaTeorema=sqrtf(powf(kateta1,2)+powf(kateta2,2));
     	
     	if(fabs(hipotenuza-pitagorinaTeorema)<epsilon) {
     	    printf("Pravougli\n");
     	}

    if((int)ugaoAlfa==180 || (int)ugaoBeta==180 || (int)ugaoGama==180){
    	printf("Linija\n");
    } else {
    	if (fabs(prvaStranica - drugaStranica) < epsilon && fabs(prvaStranica - trecaStranica) < epsilon) {
    	    printf ("Jednakostranicni\n");
    	}
    	if(fabs(prvaStranica-drugaStranica)> epsilon && fabs(drugaStranica-trecaStranica)>epsilon && (fabs(trecaStranica-prvaStranica)>epsilon))
     	printf("Raznostranicni\n"); 
    
     	if ((fabs(prvaStranica-drugaStranica)>epsilon && fabs(drugaStranica-trecaStranica)<epsilon) || (fabs(prvaStranica-trecaStranica)<epsilon && fabs(drugaStranica-trecaStranica)>epsilon)|| (fabs(prvaStranica-trecaStranica)>epsilon && fabs(prvaStranica-drugaStranica)<epsilon)) 
     		printf("Jednakokraki\n"); 
     		
    }
        if(fabs(hipotenuza - pitagorinaTeorema) > epsilon) {
     	    if(ugaoAlfa > ugaoBeta) {
     	        if(ugaoAlfa > ugaoGama) {
     	            stepen = (int)ugaoAlfa;
     	            minute = (int)((ugaoAlfa - stepen) * 60);
     	            sekunde = (int)((((ugaoAlfa - stepen) * 60) - minute) * 60);
     	        } else {
     	            stepen = (int)ugaoGama;
     	            minute = (int)((ugaoGama - stepen) * 60);
     	            sekunde = (int)((((ugaoGama - stepen) * 60) - minute) * 60);
     	        }
     	    } else if(ugaoBeta > ugaoGama) {
     	         stepen = (int)ugaoBeta;
     	         minute = (int)((ugaoBeta - stepen) * 60);
     	         sekunde = (int)((((ugaoBeta - stepen) * 60) - minute) * 60);
     	    } else {
     	        stepen = (int)ugaoGama;
     	        minute = (int)((ugaoGama - stepen) * 60);
     	        sekunde = (int)((((ugaoGama - stepen) * 60) - minute) * 60);
     	    }
     	    
     	    printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minute, sekunde);
     	
} else {
    printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
}

    return 0; 
}
     			
     		
     		
     	
     
    