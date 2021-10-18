#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define EPS 0.0001
void izbacivanje(char *p)
{
    while (*++p != '\0') {
        if (*p == ',' && *(p + 1) == '\0')
            *p = *(p + 1);
    }
}
int prebroj(char *s)
{
    int zarez=0, zagrada1=0, zagrada2=0;
    while (*++s!='\0') {
        if (*s==',') zarez++;
        if (*s=='(') zagrada1++;
        if (*s==')') zagrada2++;
    }
    return (zagrada2+zagrada1-zarez==0);
}
int ispravan(char*s)
{
    char * p = s;
    if (s[0]=='\0') return 1;
    while(*++p != '\0') {
        if (s[0]!='(' || ((*p >= 48 && *p <= 57) && (*(p + 1) == '.' && *(p - 1) == '.')) || ((*p == ',') && (*(p - 1) == '(' || *(p - 1) == '-' || *(p + 1) == ',' || *(p + 1) == '.' || *(p + 1) == ')')) || ((*p == ')') && ((((int)*(p - 1) < 48 || (int)*(p - 1) >57) && *(p - 1) != '.') || (*(p + 1) != ',' && *(p + 1) != '\0'))) || ((*p == '(') &&((p > s && *(p - 1) != ',') || (*(p + 1) != '-' && ((int)*(p + 1) < 48 || (int)*(p + 1) > 57) && *(p + 1) != '\0'))) || ((*p == '-') && (*(p + 1) == '-' || *(p - 1) == '-')) || (((int)*p < 48 || (int)*p >57) && *p != '(' && *p != ')' && *p != ',' && *p != '-' && *p != '.')||(p == s && *p != '(') || (p == s && *p != '(') || (*(p + 1) == '\0' && *p != ')') || ((*p == '.') && (*(p + 1) == '.' || *(p - 1) == '.' || *(p + 1) == '-' || *(p - 1) == '-')))
            return 0;
    }
    if(!prebroj(s))return 0;
    return 1;
}
bool jednaki(double a, double b)
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPS);
}
bool manjiod(double a, double b)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : EPS));
}
char* obuhvat(char*s, int x1, int y1, int x2, int y2)
{

    if (!ispravan(s)) return NULL;
    char*p = s, *ppoc, *p2;
    float koord[100], cijeli = 0, decimala = 0, x, y;
    int br_decimala = 0;
    int i = 0, j = 0, iter, minus = 0, br_koor = 0, unutar;
    char*pok[1000];
    while (*++p != '\0') {
        if (*p == '-')
            minus = 1;
        if ((*p >= 48 && *p <= 57)) {
            ppoc = p;
            while (*p != '(') p--;
            pok[i] = p;
            p = ppoc;
            while (*p >= 48 && *p <= 57) {
                cijeli = cijeli*10 + (float)*p - 48;
                p++;
            }
            if (*p == '.') {
                p++;
                while (*p >= 48 && *p <= 57) {
                    decimala = decimala*10 + (float)*p - 48;
                    br_decimala++;
                    p++;
                }
                decimala /= pow(10, br_decimala);
            }
            koord[i] = cijeli + decimala;
            br_koor++;
            if (minus == 1)
                koord[i] = -koord[i];
            cijeli = 0;
            decimala = 0;
            br_decimala = 0;
            minus = 0;
            i++;
        }
    }
    br_koor = i;
    p = s;
    for (i = 0; i < br_koor; i = i + 2) {
        x = koord[i];
        y= koord[i + 1];
        //if((((manjiod(x1,x) || jednaki(x1,x)) && (manjiod(x,x2) || jednaki(x2,x))) && ((manjiod(y,y2)|| jednaki(y2,y)) &&  (manjiod(y1,y)|| jednaki(y1,y))) && (manjiod(x1,x2)|| jednaki(x1,x2)) && (manjiod(y1,y2)|| jednaki(y1,y2))))
        if (x1 > x2 || y1 > y2 || x < x1 || x > x2 || y < y1 || y > y2)
            unutar = 0;
        else
            unutar = 1;
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
                for (iter = 0; iter < br_koor; iter++) {
                    pok[iter]--;
                }
                p = ppoc;
            }
        }
    }
    p = s;
    izbacivanje(p);
    return s;
}

int main()
{
    char s[] = "(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
    char* rez = obuhvat(s, -3, -3, 3, 3);
    printf("%s %s", rez, s);
    return 0;
}
