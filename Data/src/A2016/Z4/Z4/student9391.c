#include <stdio.h>
#include <math.h>
#define E 0.0001

void unesi(char*s, int duzina)
{

    int i = 0;
    char znak = getchar();
    if (znak == '\n') znak = getchar();

    while (znak != '\n' && i < duzina - 1) {

        s[i] = znak;
        i++;
        znak = getchar();
    }
    s[i] = '\0';

}

int pravilan(char*unos)
{

    int lijevih = 0, desnih = 0, zareza = 0;
    char * p = unos;

    if (*unos == '\0')
        return 1;

    while(*p != '\0') {

        if (((int)*p < 48 || (int)*p >57) && *p != '(' && *p != ')' && *p != ',' && *p != '-' && *p != '.')
            return 0;

        if (p == unos && *p != '(')
            return 0;

        if (*(p + 1) == '\0' && *p != ')')
            return 0;

        if (*p == '(') {
            lijevih++;
            if ((p > unos && *(p - 1) != ',') || (*(p + 1) != '-' && ((int)*(p + 1) < 48 || (int)*(p + 1) > 57) && *(p + 1) != '\0'))
                return 0;
        }
        if (*p == ')') {
            desnih++;
            if ((((int)*(p - 1) < 48 || (int)*(p - 1) >57) && *(p - 1) != '.') || (*(p + 1) != ',' && *(p + 1) != '\0'))
                return 0;
        }

        if (*p == ',') {
            zareza++;
            if (*(p - 1) == '(' || *(p - 1) == '-' || *(p + 1) == ',' || *(p + 1) == '.' || *(p + 1) == ')')
                return 0;
        }

        if (*p == '.')
            if (*(p + 1) == '.' || *(p - 1) == '.' || *(p + 1) == '-' || *(p - 1) == '-')
                return 0;

        if (*p == '-')
            if (*(p + 1) == '-' || *(p - 1) == '-')
                return 0;

        if(*p >= 48 && *p <= 57)
            if (*(p + 1) == '.' && *(p - 1) == '.')
                return 0;
        p++;

    }

    if (desnih + lijevih - zareza != 1)
        return 0;

    return 1;
}

char* obuhvat(char*unos, int x1,int y1,int x2,int y2)
{
    if(pravilan(unos)==0)
        return 0;

    char*p=unos, *ppoc, *p2;
    float koord[100];
    float cijeli=0, decimala=0;
    int br_decimala=0;
    int i=0,j=0,m,minus=0,br_koor=0,unutar;
    float xT, yT;
    char*pok[100];

    while(*p!='\0') {
        if(*p=='-')
            minus=1;
        if((*p>=48 && *p<=57)) {
            ppoc=p;
            while(*p!='(')
                p--;
            pok[i]=p;
            p=ppoc;
            while(*p>=48 && *p<=57) {
                cijeli=cijeli*10+(float)*p-48;
                p++;
            }
            if(*p=='.') {
                p++;
                while(*p>=48 && *p<=57) {
                    decimala=decimala*10+(float)*p-48;
                    br_decimala++;
                    p++;
                }
                decimala/=pow(10,br_decimala);
            }
            koord[i]=cijeli+decimala;
            br_koor++;
            if(minus==1)
                koord[i]=-koord[i];
            cijeli=0;
            decimala=0;
            br_decimala=0;
            minus=0;
            i++;
        }
        p++;
    }
    br_koor=i;
    p=unos;

    for (i = 0; i < br_koor; i = i + 2) {
        xT = koord[i];
        yT = koord[i + 1];

        if (x1 > x2 || y1 > y2 || xT < x1 || xT > x2 || yT < y1 || yT > y2)
            unutar = 0;
        else
            unutar = 1;
      //  printf("%d ", unutar);

        if (unutar == 0) {

            p = pok[i];
            ppoc = p;

            while (*p != ')' && *p != '\0')
                p++;
            p2 = p;
            p = ppoc;

            for (j = 0; j <= p2 - p + 1; j++) {

                while (*p != '\0') {

                    *p = *(p + 1);

                    p++;
                }

                for (m = 0; m < br_koor; m++) {
                    pok[m]--;
                }

                p = ppoc;

            }

        }

    }

    p=unos;
    while(*p!='\0') {
        if(*p==',' && *(p+1)=='\0')
            *p=*(p+1);
        p++;
    }
    return unos;
}

int main()
{
    char unos[100];
    unesi(unos,1000);
    obuhvat(unos, 3, 3, 1, 7);
    //printf("Zadaća 4, Zadatak 4");
    return 0;
}
