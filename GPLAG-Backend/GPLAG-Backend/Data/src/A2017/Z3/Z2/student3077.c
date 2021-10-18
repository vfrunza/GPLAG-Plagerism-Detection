#include <stdio.h>
#include <math.h>
#include <stdlib.h>

    void zaokruzi1(float nizA[], int velA){
        int i,tmp1;
        double tmp2,tmp3,bro_zao;
        
        for(i=0;i<velA;i++){
            tmp1=(int)nizA[i];
            tmp2=nizA[i]-tmp1;
            tmp3=((round)(tmp2*10))/10;
            bro_zao=tmp1+tmp3;
            nizA[i]=bro_zao;
        }
    
}

    void preslozi(float nizA[], int velA, int k){
        int i=0,j=0,tmp1,tmp2,suma_cif=0,br=0;
        float tmp3=0;
        
        zaokruzi1(nizA,velA);

        for(i=0;i<velA;i++){
            tmp1=(fabs)(nizA[i]*10);
            
                while(tmp1!=0){
                    tmp2=tmp1%10;
                    suma_cif=suma_cif+tmp2;
                    tmp1=tmp1/10;}
                
                if(suma_cif>=k){
                
                for(j=i;j>br;j--){
                    tmp3=nizA[j-1];
                    nizA[j-1]=nizA[j];
                    nizA[j]=tmp3;
                }

                br++;
                
         }
        suma_cif=0;
        }
    }

int main() {
	
	return 0;
}
