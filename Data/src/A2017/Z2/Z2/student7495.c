#include <stdio.h>

int main() {
	int a[10],b[10],c[20],i,br1,br2;
	printf("Unesite elemente niza A: ");
	for(i=0;i<10;i++){
	    scanf("%d", &a[i]);
 	    if(a[i]==-1){
	    	break;
	    }
	    br1++;
	}
	printf("Unesite elemente niza B: ");
	for(i=0;i<10;i++){
		scanf("%d", &b[i]);
		
		br2++;
	}
	
	


for(i=0;i<10;i++){
	  if(i<br1){
	  	c[i]=a[i];
	  }
	  if(i<br2){
	  	c[i+br1]=b[i];
	  }
     }
	  printf("Finalni niz glasi: ");
	  for(i=0;i<br1+br2;i++){
	  	printf("%d",c[i]);
	  	if(i<br1+br2-1){
	  		printf(" ");
	  	}
	  }
	
	return 0;
}
