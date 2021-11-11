#include <stdio.h>

int main () {
    
    int sirina1, visina1,visina2,sirina2,i,j;
    float A[100][100], B[100][100];
    
    do {
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &sirina1, &visina1);
    } while( sirina1<=0 || visina1<=0);
    
     
 printf("Unesite clanove matrice A: ");
    for(i=0; i<visina1; i++)
for(j=0; j<sirina1; j++) 
scanf("%f", &A[i][j]);


  do {
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &sirina2, &visina2);
    } while( sirina2<=0 || visina2<=0);
    
    
    
      printf("Unesite clanove matrice B: ");
    for(i=0; i<visina2; i++)
for(j=0; j<sirina2; j++) 
scanf("%f", &B[i][j]);

    
   
    
  

    /*rotiraj A*/ 
    
    for (int i = 0; i < sirina1; i++)
    {
        for (int j = i + 1; j < visina1; j++)
        {
           float temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }



    for (int i = 0; i < sirina1; i++)
    {
        for (int j = 0; j < visina1 / 2; j++)
        {
           float temp = A[i][j];
            A[i][j] = A[i][visina1 - 1 - j];
            A[i][visina1 - 1 - j] = temp;
        }
}


/*provjeri jesul iste*/ 

if(sirina2!=visina1) {
    printf("NE");
    return 0;
}

if(visina2!=sirina1) {
    printf("NE");
    return 0;
}

int nisu_iste=0;
 for(i=0; i<visina2; i++) 
for(j=0; j<sirina2; j++) {
 if (A[i][j]!=B[i][j]) nisu_iste=1;
  }
  
  if(nisu_iste) printf("NE");
  else printf("DA");

return 0;

}