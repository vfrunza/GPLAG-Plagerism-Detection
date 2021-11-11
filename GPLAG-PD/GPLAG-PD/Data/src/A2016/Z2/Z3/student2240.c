#include <stdio.h>
#include <stdlib.h>
int main() {
	int brtacaka, i, j, temp1, temp2;
	int graf[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d",&brtacaka);
	while(brtacaka>10 || brtacaka <=0) {
	    printf("Pogresan unos\n");
	    printf("Unesite broj tacaka: ");
	    scanf("%d",&brtacaka);
	}
	for(i=0;i<20;i++) {
	    for(j=0;j<20;j++) {
	    graf[i][j]=' ';
	}
    
}
i=1;
while(brtacaka>0)
{
    printf("Unesite %d. tacku: ",i );
    scanf("%d %d", &temp1, &temp2);
    while(temp1>=20 || temp1<0 || temp2>=20 || temp2<0){
        printf("Pogresan unos \n");
        printf("Unesite %d. tacku: ", i);
        scanf("%d %d", &temp1, &temp2);
    }
    graf[temp2][temp1]='*';
    brtacaka--;
    i++;
}
for (i=0;i<20;i++){
    for (j=0;j<20;j++){
        printf("%c", graf[i][j]);
    }
    printf("\n");
}
return 0; }