#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int n)
{
    int i;
    for(i=0; i<n; i++) {
        niz[i]= round(niz[i]*10) /10;

    }
}

void preslozi(float niz[],int n,int k)
{
    int i,l=0,m,q,j;
    int suma[100]= {0};

    float niz2[100];


    int temp;

    zaokruzi1(niz,n);
    for(i=0; i<n; i++) {
        if(niz[i]<0) {

            temp=niz[i]* -10;

            do {

                suma[i]+=temp%10;
                temp= temp/10;


            } while(temp !=0);
        } else {

            temp=niz[i]* 10;

            do {

                suma[i]+=temp%10;
                temp= temp/10;


            } while(temp !=0);

        }

    }



    for(j=0; j<n; j++) {

        if(suma[j]>=k) {
            niz2[l]=niz[j];
            l++;
        }
    }

    for(q=0; q<n; q++) {

        if(suma[q]<k) {
            niz2[l]=niz[q];
            l++;
        }
    }
    for(m=0; m<l; m++) {
        niz[m]=niz2[m];
    }

}



int main()
{
    int i,n,k,rez;
    float niz[100];
    printf("Unesite velicinu niza: ");
    scanf("%d",&n);

    for(i=0; i<n; i++) {
        scanf("%f",&niz[i]);
    }


    printf("Unesite k: ");
    scanf("%d",&k);
    preslozi(niz,n,k);
    printf("Niz glasi: ");
    preslozi(niz,n,k);
    
    


    return 0;
}
