#include <stdio.h>
#include <math.h>

int main() {
	
	int a1,a2,b1,b2,a[100][100],b[100][100],i,j,red=0,istina=0,br,kontrola=0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&a1,&a2);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a2;i++){
	    for(j=0;j<a1;j++){
	        scanf("%d",&a[i][j]);
	    }
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&b1,&b2);
	
	printf("Unesite clanove matrice B: ");
    for(i=0;i<b2;i++){
	    for(j=0;j<b1;j++){
	        scanf("%d",&b[i][j]);
	    }
	}

br=1;

    
    
    
    for(i=0;i<br;i++){
    
    
    for(j=0;j<a1;j++){
        if(a[i][j]==b[j][a1-i-1])istina++;
    
    else {
    	red=0;kontrola=1;break;
    	
    }
        
        //printf("\n%d",istina);
        
    }
    if(kontrola==1)break;
  //  if(istina==3)br++;
  /*   red=red+istina/a1;
     istina=0;
     if(red==a1)break;*/
}

if(kontrola==1)printf("NE");
else printf("DA");

/*
red=istina/a1;
printf("%d",red);
istina=0;
br++;







for(j=0;j<a1;j++){
        if(a[br][j]==b[j][a1-br])istina++;
    }
red=red+istina/a1;
printf("%d",red);
istina=0;
br++;


*/













	return 0;
}
