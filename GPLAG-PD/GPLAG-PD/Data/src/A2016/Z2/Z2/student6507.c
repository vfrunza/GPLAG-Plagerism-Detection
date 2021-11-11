#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
    int n, i=0, j, stepeni[500], minute[500], k, l, z;
    double ugao=0, ug, min;
    double rad[500], sekunde[500];
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    while(i<n){
        scanf("%lf", &rad[i]);
        
        i++;
    }
    
    for(j=0; j<n; j++){
        
        ugao=(rad[j]*180)/PI;
        stepeni[j]=ugao;
        ug=fabs(ugao-stepeni[j]);
        minute[j]=ug*60;
        
        min=ug*60-minute[j];
        sekunde[j]=min*60;
        sekunde[j]=(int)(sekunde[j]+0.5);
        if(sekunde[j]==60){
            sekunde[j]=0;
            minute[j]++;
        }
        if(rad[j]<0 && minute[j]==60){
            minute[j]=0;
            stepeni[j]--;
        }
        else if(rad[j]>=0 && minute[j]==60){
            minute[j]=0;
            stepeni[j]++;
        }
        
        
    }
    
    for(k=0; k<n; k++){
        if(fabs(sekunde[k])>30){
            for(l=k; l<n-1; l++){
                stepeni[l]=stepeni[l+1];
                minute[l]=minute[l+1];
                sekunde[l]=sekunde[l+1];
            }
            n--;
            k--;
        }
    }
    printf("Uglovi su:\n");
    for(z=0; z<n; z++){
        printf("\n%d stepeni %d minuta %g sekundi", stepeni[z], minute[z], sekunde[z]);
    }
	return 0;
}
