#include <stdio.h>
#include <math.h>

int main()
{
	int nizA[100],nizE[10000],br_el,i,nizP[10000],dekad,k=0,n,e,pomoc,nizT[10000],br,l=0,z,j;
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d",&br_el);
	} while(br_el>100 || br_el<1);
	
		printf("Unesite clanove niza: ");
	for(i=0; i<br_el; i++) {
		scanf("%d",&nizA[i]);
		if(nizA[i]<0){
			i--;
		}
	}
	for(i=br_el-1;i>=0;i--){
		do{
			nizP[k]=nizA[i]%10;
			k++;
			nizA[i]=nizA[i]/10;
		}while(nizA[i]!=0);
			
		}
        n=k;
        //for(k=0;k<n;k++){
        	//printf("%d ",nizP[k]);
        //}
        for(e=0,k=n-1;e<n;k--,e++){
        	nizE[e]=nizP[k];
        }
        //printf("\n");
        //for(e=0;e<n;e++) printf("%d ",nizE[e]);
        nizE[n]=-1;
        for(i=0;i<n;){
        	br=1;
        	nizT[l]=nizE[i];
        	j=i;
        		
        		while(nizE[j]==nizE[j+1]){
        			br++;
        			j++;
        		}
        		
        		l++;
        		nizT[l]=br;
        		i=i+br;
        		l++;
        	}
        
        z=l;
        printf("Finalni niz glasi:\n");
        for(i=0;i<z;i++) printf("%d ",nizT[i]);


	return 0;
}
