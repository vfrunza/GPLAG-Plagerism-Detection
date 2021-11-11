#include <stdio.h>

int main() {
	 int a,b=22,c=22,i,j,nizi[20],nizj[20],k=0;
    
    do{
        printf("Unesite broj tacaka: ");
        scanf("%d",&a);
        if(a<=0||a>10)
        printf("Pogresan unos\n");
    }while(a<=0||a>10);
    
        for(i=0;i<a;i++){
    printf("Unesite %d. tacku: ",i+1);
    scanf("%d %d",&nizj[i],&nizi[i]);
    if(nizj[i]<0 || nizj[i]>19||nizi[i]<0 || nizi[i]>19){
        printf("Pogresan unos\n");
        i--;    }    }
        
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            for(k=0;k<a;k++){
                if(i==nizi[k] && j==nizj[k]){
                    printf("*");
                    b=nizi[k];
                    c=nizj[k];
                    break;  }
                
            }
           if(i==b && j==c){
            continue;}
            printf(" ");
    }
    printf("\n");
    }
    	return 0;
}

