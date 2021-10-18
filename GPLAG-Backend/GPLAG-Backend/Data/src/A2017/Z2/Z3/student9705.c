#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	
	int Ma,Na,Mb,Nb,i,j,logicki=0;
	int A[101][101];
	int B[101][101];
printf("Unesite sirinu i visinu matrice A: ");
scanf("%d %d",&Ma,&Na);
printf("Unesite clanove matrice A: ");
for(i=0;i<Na;i++)
{
    for(j=0;j<Ma;j++)
{
scanf("%d",&A[i][j]);
}

}
printf("Unesite sirinu i visinu matrice B: ");
scanf("%d %d",&Mb,&Nb);
printf("Unesite clanove matrice B: ");
for(i=0;i<Nb;i++)
{
    for(j=0;j<Mb;j++)
    {
        scanf("%d",&B[i][j]);
    }
}
if(Ma==Nb && Na==Mb)
{
    for(i=0;i<Na;i++)
    {
        for(j=0;j<Ma;j++)
        
            if(fabs(A[i][j]-B[j][Mb-1-i])>e)
            {
                printf("NE\n");
                return 1;
            }
            else logicki=1;
        
    }
    
}else
{
    printf("NE\n");
};

if(logicki==1) printf("DA\n");

return 0;
}
