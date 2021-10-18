#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};


void swap(struct Student *a, struct Student *b)
{
    struct Student temp = *b;
    *b = *a;
    *a = temp;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

double get_prosjek(struct Student s)
{
    int i;
    double sum = 0.0;
    if (s.br_ocjena == 0)
        return 5;
    for (i = 0; i < s.br_ocjena; i++)
        sum += s.ocjene[i];
    return sum / s.br_ocjena;
}

int prosjek_cmp(struct Student a, struct Student b)
{
    int i, acnt, bcnt, agcd, bgcd, asum = 0, bsum = 0;
    
    acnt = a.br_ocjena;
    bcnt = b.br_ocjena;
    
    for (i = 0 ; i < a.br_ocjena; i++)
    {
        asum += a.ocjene[i];
        if (a.ocjene[i] == 5)
        {
            asum = 5;
            acnt = 1;
        }
    }
    for (i = 0 ; i < b.br_ocjena; i++)
    {
        bsum += b.ocjene[i];
        if (b.ocjene[i] == 5)
        {
            bsum = 5;
            bcnt = 1;
        }
    }
    if (asum == 0)
    {
        acnt = 1;
        asum = 5;
    }

    if (bsum == 0)
    {
        bcnt = 1;
        bsum = 5;
    }
    
    agcd = gcd(asum, acnt);
    bgcd = gcd(bsum, bcnt);
    
    asum /= agcd;
    bsum /= bgcd;
    
    acnt /= agcd;
    bcnt /= bgcd;
    
    if (asum == bsum && acnt == bcnt)
        return 0;
    else
        return (asum * bcnt > bsum * acnt) ? -1 : 1;
}

int student_cmp(struct Student a, struct Student b)
{
    int cmp;
    if (prosjek_cmp(a, b) != 0)
        return prosjek_cmp(a, b);
    else
    {
        cmp = strcmp(a.prezime, b.prezime);
        if (cmp != 0)
            return cmp;
        cmp = strcmp(a.ime, b.ime);
        return cmp;
    }
}

void remove_at(struct Student *students, int index, int *n_students)
{
    int i, j;
    for (i = 0; i < *n_students; i++)
    {
        if (i == index)
        {
            for (j = i; j < *n_students - 1; j++)
                swap(&students[j], &students[j + 1]);
            (*n_students)--;
            return;
        }
    }
}

int genijalci(struct Student *students, int n, double prosjek)
{
    int i, gen[3], t, j;
    char found = 0;
    for (i = 0; i < n; i++)
    {
        double p = get_prosjek(students[i]);
        if (p < prosjek)
        {
            remove_at(students, i, &n);
            i--;
        }
    }
    
    for (i = 0; i < 3; i++)
        gen[i] = -1;
        
    for (t = 0; t < 3; t++)
    {
        for (i = 0; i < n; i++)
        {
            found = 0;
            for (j = 0; j < t; j++)
            {
                if (gen[j] == i)
                {
                    found = 1;
                    break;
                }
            }
            if (found)
                continue;
                
            if (gen[t] == -1 || student_cmp(students[gen[t]], students[i]) > 0)
                gen[t] = i;
        }
    }
    
    for (i = 0; i < 3; i++)
        if (gen[i] != -1)
            printf("%s %s\n", students[gen[i]].prezime, students[gen[i]].ime);
    
    return n;
}

int main()
{
struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 6, 6.5);

    
    return 0;
}















