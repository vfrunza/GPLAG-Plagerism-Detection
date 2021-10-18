#include <stdio.h>
#define VELICINA 100
int main() {
	
double mat_a[VELICINA][VELICINA],mat_b[VELICINA][VELICINA];
int i,j,visina_a,sirina_a,visina_b,sirina_b,tacno;
printf("Unesite sirinu i visinu matrice A: ");
scanf("%d %d",&sirina_a, &visina_a);
printf("Unesite clanove matrice A: ");
for(i=0;i<visina_a;i++)
for(j=0;j<sirina_a;j++){
    scanf("%lf",&mat_a[i][j]);
}
printf("Unesite sirinu i visinu matrice B: ");
scanf("%d %d", &sirina_b,&visina_b);
printf("Unesite clanove matrice B: ");
for(i=0;i<visina_b;i++)
for(j=0;j<sirina_b;j++){
    scanf("%lf",&mat_b[i][j]);
}
if(sirina_a!=visina_b || visina_a!=sirina_b){
    printf("NE");
    return 0;
}
tacno=0;
for(i=0;i<visina_a;i++)
for(j=0;j<sirina_a;j++){
    if(mat_a[i][j]==mat_b[j][visina_a-1-i]){
        tacno+=1;
    }
    else {
        tacno=0;
    }
}
if(tacno==visina_a*sirina_a){
    printf("DA");
}
else  {
    printf("NE");
}

return 0;
}