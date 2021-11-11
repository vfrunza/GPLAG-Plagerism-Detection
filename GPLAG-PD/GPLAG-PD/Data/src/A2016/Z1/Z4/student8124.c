#include <stdio.h>
#define zvijezda "*"
#define prazno " "


int main()
{

    int n, i, j;

    do {
        printf("\nUnesite broj n: ");
        scanf("%d", &n);

        if (n<0 || n>50)
            printf("\nPogresan unos");
    }
    while (n<0 || n>50);


    for (i=1; i<=n; i++) {


        if (i==1)
            printf(zvijezda);
        else
            printf(prazno);

        for (j=1; j<=i-2; j++)
            printf(prazno);

        if (i>1)
            printf("*");

        for (j=1; j<=2*n-1-2*i; j++)
            printf(prazno);

        if (i<n || n==1)
            printf(zvijezda);

        for (j=1; j<=i-1; j++)
            printf(prazno);


        for (j=1; j<=i-2; j++)
            printf(prazno);

        if (i>1)
            printf(zvijezda);

        for (j=1; j<=2*n-1-2*i; j++)
            printf(prazno);

        if (i<n || n==1)
            printf(zvijezda);

        for (j=1; j<=i-1; j++)
            printf(prazno);

        // prelom u novi red

        printf("\n");

    }

    return 0;
}