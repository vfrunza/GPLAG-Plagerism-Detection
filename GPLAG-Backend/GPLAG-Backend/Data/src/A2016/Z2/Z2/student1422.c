#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#include <stdlib.h>

int main(){
	int n,i,j,step[500],min[500],sec[500],neg;
	double uglovi;
	do{
		printf("Unesite broj uglova: ");
		scanf("%d",&n);
		} while(n<=0 || n>500);
		
		for(i=0;i<n;i++){
			neg=0;
			scanf("%lf",&uglovi);
			uglovi*=180/PI;
			if(uglovi<0){
				neg=1;
				uglovi*=-1;
			}
			step[i]=(int)(uglovi);
			uglovi-=step[i];
			min[i]=(int)(uglovi*60);
			uglovi=uglovi*60-min[i];
			sec[i]=(int)round(uglovi*60);
			if(neg==1)
			step[i]*=-1;
			if(sec[i]==60){
				sec[i]=0;
				min[i]++;
				if(min[i]==60){
				min[i]=0;
				if(neg==1)
				step[i]--;
				else
				step[i]++;
				}
			}
			if(min[i]==60){
				min[i]=0;
			step[i]++;
			}
			if(sec[i]==-60){
				sec[i]=0;
				min[i]--;
				if(min[i]==-60){
				min[i]=0;
				step[i]--;
				}
			}
				if(min[i]==-60){
				min[i]=0;
			step[i]--;
			}
		}
		
		for(i=0;i<n;i++){
			if(sec[i]>30 || sec[i]<-30){
				for(j=i;j<n-1;j++){
					step[j]=step[j+1];
					min[j]=min[j+1];
					sec[j]=sec[j+1];
				}
				n--;
				i--;
			}
			
		}
		printf("Uglovi su: \n");
		for(i=0;i<n;i++)
		printf("%d stepeni %d minuta %d sekundi \n", step[i],min[i],sec[i]);
	return 0;
}