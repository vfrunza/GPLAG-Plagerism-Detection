#include <stdio.h>
#include<math.h>
int main() {
	
	int a[100],b[1000],c[1000];
	int n,i,k,j,br_c=0,br=0,pom,pom2,w,temp[100],l;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<0 || n>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0) 
		i--;
	}
	
    k=0;                      
	for(i=0;i<n;i++){
		if(a[i]==0){b[k]=0; k++;}
	    pom=a[i];
	    pom2=a[i]; 
	    br_c=0;
	    while(pom>0){
	        br_c++;
	        pom/=10;
	    }
	    w=br_c;
	    
	    for(j=0;j<br_c;j++){
	    temp[j]=pom2%10;
	    pom2/=10;
	    } 
    	 
	
	  for(l=w-1;l>=0;l--){
	  b[k]=temp[l];
	  k++;
	  }
	}

j=0;
	
	for(i=0;i<k;i++){
		br=1;

		while(i<k-1 && b[i]==b[i+1] ){
			br++;
			i++;
		}
		
		c[j]=b[i];
		c[j+1]=br;
		j+=2;
		
	}
	i--;
	printf("Finalni niz glasi:\n");
	for(i=0;i<j;i++)
	printf("%d ",c[i]);
	return 0;
}
