#include <stdio.h>

int dva_od_tri(int niz1[],int v1,int niz2[],int v2,int niz3[],int v3)
{
    int k=0,j,p;
    int isti=0;
    int i =0;



    while(i<v1) {
        for(j=0; j<v2; j++) {
            if(niz1[i]==niz2[j]) {
                isti++;
                break;
            }
        }

        for(j=0; j<v3; j++) {
            if(niz1[i]==niz3[j]) {
                isti++;
                break;
            }
        }

        if(isti==1) k++;
        isti=0;
        i++;
    }
    isti=0;
    i=0;

    while(i<v2) {
        for(j=0; j<v3; j++) {
            if(niz2[i]==niz3[j]) {
                isti++;

                for(p=0; p<v1; p++) {
                    if (niz3[j]==niz1[p]) {
                        isti++;

                    }
                }
            }
        }


        if(isti==1)
            k++;
        isti=0;
        i++;
    }


    return k;

}


int main()
{
    int y;
    int niza[]= {1,2,3,5};
    int nizb[]= {1,2,4,7};
    int nizc[]= {1,3,4,8,9,10};

    y=dva_od_tri(niza,4,nizb,4,nizc,6);
    printf("%d",y);





    return 0;
}
