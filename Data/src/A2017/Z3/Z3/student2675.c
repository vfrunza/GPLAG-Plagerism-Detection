#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz, int vel_niza, int *niz_cifri, int vel_niza_cifri)
{
    int i, j, temp, br_cifri,br, predznak;

    for (i = 0; i < vel_niza_cifri; i++) {
        for (j = i+1; j < vel_niza_cifri; j++)
            if (*(niz_cifri+i)==*(niz_cifri+j))
                return 0;
        if (*(niz_cifri+i)>9 || *(niz_cifri+i)<0)
            return 0;
    }

    for (i = 0; i < vel_niza; i++) {
        temp=fabs(*(niz+i));
        br_cifri=0;
        br=0;

        do {
            br_cifri++;
            temp/=10;
        } while (temp>=1);

        temp = fabs(*(niz+i));

        if (*(niz+i)>=0)
            predznak=1;
        else
            predznak=-1;

        *(niz+i)=0;
        do {
            for (j = 0; j < vel_niza_cifri; j++)
                if((temp%10)==*(niz_cifri+j))
                    break;
            if (j==vel_niza_cifri) {
                *(niz+i)+=(temp%10)*pow(10,br);
                br++;
            }
            temp/=10;
            br_cifri--;
        } while (br_cifri!=0);
        *(niz+i) = *(niz+i) * predznak;

    }


    return 1;

}


int main()
{
    int i;
    int niz[1]= {1};
    int niz_cifri[5]= {0,1,2,3,4};
    for (i = 0; i < 1; i++)
        printf("%d ", niz[i]);

    printf("\n");
    printf("Uspjesno: %d", izbaci_cifre(niz,1,niz_cifri,5));

    printf("\n");
    for (i = 0; i < 1; i++)
        printf("%d ", niz[i]);
    return 0;
}
