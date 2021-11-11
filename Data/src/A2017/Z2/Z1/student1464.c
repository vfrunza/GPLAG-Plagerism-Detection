#include <stdio.h>

int main() {
int N;
int i, j;

do	{
    printf("Unesite broj N: ");
    scanf("%d", &N);
    if(N<8 || N %4 != 0){
        printf("Neispravno N!");
    }
    printf("\n");
}while (N<8 || N %4 != 0);

    for(i=0; i<=N-1; i++){
        for(j=0; j<=N-1; j++){
            if(i<=(N/2)-1 && j<=(N/2)-1){
                if(N/2-i==j+1){
                    printf("/");
                }
                else if(i==j){
                    printf("\\");
                }
                else{
                    printf(" ");
                }
            }
            else if(i<=(N/2)-1 && j>=N/2){
                if(i==0 || i==(N/2)-1){
                    if(j==N/2 || j==N-1){
                        printf("+");
                    }
                    else{
                        printf("-");
                    }
                }
                else{
                    if(j+1==(N/2)+1 || j==N-1)
                    {
                        printf("|");
                    }
                    else{
                        printf(" ");
                    }
                }
            }
            else if(i>=N/2 && j<=(N/2)-1){
                if(j==0 || j==(N/2)-1){
                    if(i==N/2 || i==N-1){
                        printf("+");
                    }
                    else{
                        printf("|");
                    }
                }
                else{
                    if(i+1==(N/2)+1 || i==N-1)
                    {
                        printf("-");
                    }
                    else{
                        printf(" ");
                    }
                }
            }
            else{
                if(i==(N-(N/4))-1 || i==(N-(N/4))){
                    if(j==(N-(N/4))-1 || j==(N-(N/4))){
                        printf("+");
                    }
                    else{
                        printf("-");
                    }
                }else if(j==(N-(N/4))-1 || j==(N-(N/4))){
                    printf("|");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
return 0;
}
