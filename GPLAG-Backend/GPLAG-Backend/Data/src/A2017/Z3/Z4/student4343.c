#include <stdio.h>
#include <math.h>

int cifre(int niz[],int vel,int niz1[100])
{
    int i,j,ima,temp,vel1=0;
    for(i=0; i<vel; i++) {
        temp=niz[i];
        while(temp!=0) {
            ima=0;
            for(j=0; j<vel1; j++) {
                if(temp%10==niz1[j]) {
                    ima=1;
                    break;
                }
            }
            if(ima==0) {
                niz1[vel1]=temp%10;
                vel1++;
            }

            temp/=10;
        }
    }
    return vel1;
}

int main()
{
    int niz[100],i,j,n,br,niz1[100],min,temp;
    for(i=0; i<100; i++) {
        printf("Unesi %d element niza: ",i+1);
        scanf("%d",&niz[i]);
        if(niz[i]==-1) break;
    }

    n=i;
    br=cifre(niz,n,niz1);

    for(i=0; i<br; i++) {
        min=i;
        for(j=i+1; j<br; j++) {
            if(niz1[j]<niz1[min]) {
                min=j;
            }
        }
        temp=niz1[i];
        niz1[i]=niz1[min];
        niz1[min]=temp;
    }
    for(i=0; i<br-1; i++)
        printf("%d,",niz1[i]);
    if(i==br-1)
        printf("%d",niz1[i]);

    return 0;

}
