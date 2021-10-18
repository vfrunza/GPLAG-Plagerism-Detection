#include <stdio.h>

int main() {
	char mat[20][20];
	int brojtacaka;
    int i,j,k,t,unos;
    for(k=0;k<20;k++){
        for(t=0;t<20;t++){
            mat[k][t]=' ';
        }
    }
do{
   printf("Unesite broj tacaka: ");
   scanf("%d",&brojtacaka);
   if(brojtacaka<=0){printf("Pogresan unos\n");continue;}
   if(brojtacaka>10){printf("Pogresan unos\n");continue;}
   }while(brojtacaka<=0 || brojtacaka>10);

    for(unos=1; unos<=brojtacaka;unos++){
    printf("Unesite %d. tacku: ",unos);
 //       for(unosi=0;unosi<brojtacaka;unosi++){
   // for(unosj=0;unosj<brojtacaka;unosj++){
  
    scanf("%d %d",&i, &j);//}
   // if(i==-1){printf("Pogresan unos\n");unos--;}
//else    if(i<0 || j<0 || i>=20 || j>=20){printf("Pogresan unos\n");unos--;}
  while(i<0 || j<0 || i>19 || j>19){
      printf ("Pogresan unos\n");
      printf ("Unesite %d. tacku: ",unos);
      scanf ("%d %d",&i,&j);
  }
    mat[i][j]='*';
        
    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%c",mat[j][i]);
        }
        printf("\n");
    }
	return 0;
}