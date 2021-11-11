#include <stdio.h>

int main() {
char mat[20][20];
int i,j;
int broj_tacki;
int tacke[10][2];
int t1,t2;
int s=0;
int k,l;
ok:
printf("Unesite broj tacaka: ");
scanf("%d",&broj_tacki);
if(broj_tacki<=0||broj_tacki>10){
    printf("Pogresan unos\n");
    goto ok;
}
while(s!=broj_tacki){
    printf("Unesite %d. tacku: ",s+1);
    scanf("%d %d",&k,&l);
    if(k>=20||k<0||l>=20||l<0){
        printf("Pogresan unos\n");
        continue;
    }
    tacke[s][0]=k;
    tacke[s][1]=l;
    s++;
  
}
for(i=0;i<20;i++){
    for(j=0;j<20;j++){
        mat[i][j]=' ';
    }
}
for(i=0;i<broj_tacki;i++){
    t1=tacke[i][0];
    t2=tacke[i][1];
    mat[t2][t1]='*';
}
for(i=0;i<20;i++){
    for(j=0;j<20;j++){
        printf("%c",mat[i][j]);
    }
    printf("\n");
}

	return 0;
}
