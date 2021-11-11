#include <stdio.h>
int dva_od_tri(int nizA[], int velA, int nizB[], int velB, int nizC[], int velC){
    int i,j,k,brojac=0,nizP[100],l=0,br=0,m=0;
    
    for(i=0;i<velA;i++){
        for(j=0;j<l;j++){
            if(nizA[i]==nizP[j]){
                br=1;
            }
        }
        if(br==0){
            for(j=0;j<velB;j++){
                if(nizA[i]==nizB[j]){   
                    brojac++;
                    nizP[l]=nizA[i];
                    l++;
                    for(k=0;k<velC;k++){
                        if(nizA[i]==nizC[k]){
                            brojac--;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        br=0;
    }
    for(i=0;i<velA;i++){
        for(j=0;j<l;j++){
            if(nizA[i]==nizP[j]){
                br=1;
            }
        }
        if(br==0){
        for(j=0;j<velC;j++){
            if(nizA[i]==nizC[j]){
                brojac++;
                nizP[l]=nizA[i];
                l++;
                for(k=0;k<velB;k++){
                    if(nizA[i]==nizB[k]){
                        brojac--;
                    }
                }
            }
        }}
        br=0;
    }
	for(i=0;i<velB;i++){
	    for(j=0;j<l;j++){
	        if(nizB[i]==nizP[j]){
	            br=1;
	        }
	    }
	    if(br==0){
	    for(j=0;j<velC;j++){
	        if(nizB[i]==nizC[j]){
	            brojac++;
	            nizP[l]=nizB[i];
	            l++;
	            for(k=0;k<velA;k++){
	                if(nizB[i]==nizA[k]){
	                    brojac--;
	                }
	            }
	        }
	    }}
	    br=0;
	}

	return brojac;
}
int main(){
    return 0;
}
	