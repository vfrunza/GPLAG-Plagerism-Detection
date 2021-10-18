#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265359

int main() {
	
	double t1_k1,t1_k2,t2_k1,t2_k2,t3_k1,t3_k2,T1T2,T2T3,T3T1,alfa, beta, gama;
	int stepeni, minute, sekunde;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&t1_k1, &t1_k2);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&t2_k1, &t2_k2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&t3_k1, &t3_k2);
	
	T1T2 = sqrt((t1_k1-t2_k1)*(t1_k1-t2_k1)+(t1_k2-t2_k2)*(t1_k2-t2_k2));
	T2T3 = sqrt((t2_k1-t3_k1)*(t2_k1-t3_k1)+(t2_k2-t3_k2)*(t2_k2-t3_k2));
	T3T1 = sqrt((t3_k1-t1_k1)*(t3_k1-t1_k1)+(t3_k2-t1_k2)*(t3_k2-t1_k2));
	
	alfa = acos((T2T3*T2T3+T3T1*T3T1-T1T2*T1T2)/(2*T2T3*T3T1))*(180/PI);
   	beta = acos((T3T1*T3T1+T1T2*T1T2-T2T3*T2T3)/(2*T3T1*T1T2))*(180/PI);
    gama = acos((T1T2*T1T2+T2T3*T2T3-T3T1*T3T1)/(2*T1T2*T1T2))*(180/PI);
	   
	    
	if(fabs(T1T2-T2T3) < EPSILON && fabs(T2T3-T3T1) < EPSILON) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		
	}
	else if((fabs(T1T2-T2T3) < EPSILON && fabs(T2T3-T3T1) > EPSILON) || (fabs(T3T1-T1T2) < EPSILON && fabs(T1T2-T2T3) > EPSILON) || (fabs(T2T3-T3T1) < EPSILON && fabs(T3T1-T1T2) > EPSILON)) {
		if(fabs(T1T2*T1T2+T2T3*T2T3-T3T1*T3T1) < EPSILON || fabs(T2T3*T2T3+T1T2*T1T2-T2T3*T2T3) < EPSILON || fabs(T3T1*T3T1+T1T2*T1T2-T2T3*T2T3) < EPSILON)
		printf("Pravougli\n");
		printf("Jednakokraki\n");
	}
	else if(fabs(T1T2-T2T3) > EPSILON && fabs(T2T3-T3T1) > EPSILON) {
		printf("Raznostranicni\n");
	}
	
	
    if(alfa>beta && alfa>gama) {
           stepeni = (int)alfa;
           minute = (alfa-stepeni)*60;
    	   sekunde = (minute-(int)minute)*60;
    	
          printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
    else if(beta>gama && beta>alfa) {
            stepeni = (int)beta;
        	minute = (beta-stepeni)*60;
        	sekunde = (minute-(int)minute)*60;
    	
          printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }	
    else if(gama>alfa && gama>beta) {
       	   stepeni = (int)gama;
           minute = (gama-stepeni)*60;
    	   sekunde = (minute-(int)minute)*60;
    	
          printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
    }
	 
	 
	return 0;
}
