#include <stdio.h>


struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};

double dajProsjek(struct Student student)
{
    int i;
    double suma = 0;
    if(student.br_ocjena == 0)
    {
        return 5.0;
    }
    for(i = 0; i < student.br_ocjena; i++)
    {
        if(student.ocjene[i] == 5)
        {
            return 5.0;
        }
        suma += student.ocjene[i];
    }

    return suma/student.br_ocjena;
}

int uporedi(struct Student prvi, struct Student drugi)
{
    int i = 0;
    for(i = 0; i < 20; i++)
    {
        if(prvi.prezime[i] < drugi.prezime[i])
        {
            return 0;
        } else if(prvi.prezime[i] > drugi.prezime[i])
        {
            return 1;
        }
    }
    for(i = 0; i < 20; i++)
    {
        if(prvi.ime[i] < drugi.ime[i])
        {
            return 0;
        } else if(prvi.ime[i] > drugi.ime[i])
        {
            return 1;
        }
    }
    return 0;
}

int uporedi_tri(struct Student prvi, struct Student drugi, struct Student treci)
{
    if(uporedi(prvi,drugi) == 0 && uporedi(prvi, treci) == 0 && uporedi(drugi,treci) == 0)
    {
        return 123;
    } else if(uporedi(prvi,drugi) == 0 && uporedi(prvi, treci) == 0 && uporedi(drugi,treci) == 1)
    {
        return 132;
    } else if(uporedi(prvi,drugi) == 1 && uporedi(prvi, treci) == 0 && uporedi(drugi,treci) == 0)
    {
        return 213;
    } else if(uporedi(prvi,drugi) == 1 && uporedi(prvi, treci) == 1 && uporedi(drugi,treci) == 0)
    {
        return 231;
    } else if(uporedi(prvi,drugi) == 1 && uporedi(prvi, treci) == 1 && uporedi(drugi,treci) == 1)
    {
        return 321;
    } else if(uporedi(prvi,drugi) == 0 && uporedi(prvi, treci) == 1 && uporedi(drugi,treci) == 1)
    {
        return 312;
    }
}

void printaj(struct Student* niz, int vel)
{
    if(vel == 0);
    else if(vel == 1)
    {
        printf("%s %s", niz[0].prezime, niz[0].ime);
    } else if(vel == 2)
    {
        if(dajProsjek(niz[0]) > dajProsjek(niz[1]))
        {
            printf("%s %s\n", niz[0].prezime, niz[0].ime);
            printf("%s %s\n", niz[1].prezime, niz[1].ime);
        } else if(dajProsjek(niz[0]) < dajProsjek(niz[1]))
        {
            printf("%s %s\n", niz[1].prezime, niz[1].ime);
            printf("%s %s\n", niz[0].prezime, niz[0].ime);
        } else
        {
            if(uporedi(niz[0],niz[1]) == 0)
            {
                printf("%s %s\n", niz[0].prezime, niz[0].ime);
                printf("%s %s\n", niz[1].prezime, niz[1].ime);
            } else
            {
                printf("%s %s\n", niz[1].prezime, niz[1].ime);
                printf("%s %s\n", niz[0].prezime, niz[0].ime);
            }
        }
    } else
    {
        int i,j;
        for(i = 0; i < 3; i++)
        {
            int pozicija_najboljeg = 0;
            double najbolji_prosjek = 0;

            for(j = 0; j < vel; j++)
            {
                if(dajProsjek(niz[j]) > najbolji_prosjek)
                {
                    najbolji_prosjek = dajProsjek(niz[j]);
                    pozicija_najboljeg = j;
                }
            }

            struct Student temp = niz[vel-1];
            niz[vel-1] = niz[pozicija_najboljeg];
            niz[pozicija_najboljeg] = temp;
            vel--;
        }

        if(dajProsjek(niz[vel]) == dajProsjek(niz[vel+1]) && dajProsjek(niz[vel]) == dajProsjek(niz[vel+2]))
        {
            int redoslijed = uporedi_tri(niz[vel],niz[vel+1],niz[vel+2]);
            switch (redoslijed)
            {
                case 123:
                    printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                    printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                    printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                    break;

                case 132:
                    printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                    printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                    printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                    break;

                case 213:
                    printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                    printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                    printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                    break;

                case 231:
                    printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                    printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                    printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                    break;

                case 321:
                    printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                    printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                    printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                    break;

                case 312:
                    printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                    printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                    printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                    break;
            }
        } else if(dajProsjek(niz[vel]) == dajProsjek(niz[vel+1]) && dajProsjek(niz[vel]) != dajProsjek(niz[vel+2]))
        {
            printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
            if(uporedi(niz[vel],niz[vel+1]) == 0)
            {
                printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
                printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
            } else
            {
                printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
            }
        } else if(dajProsjek(niz[vel]) != dajProsjek(niz[vel+1]) && dajProsjek(niz[vel+1]) == dajProsjek(niz[vel+2]))
        {
            if(uporedi(niz[vel+1],niz[vel+2]) == 0)
            {
                printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
                printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
            } else
            {
                printf("%s %s\n", niz[vel+2].prezime, niz[vel+2].ime);
                printf("%s %s\n", niz[vel+1].prezime, niz[vel+1].ime);
            }
            printf("%s %s\n", niz[vel].prezime, niz[vel].ime);
        }
        else
        {
            for(i = vel+3; i > 0; i--)
            {
                printf("%s %s\n", niz[i].prezime, niz[i].ime);
            }
        }
    }
}

int genijalci(struct Student* niz, int vel, double prosjek)
{
    int i;
    struct Student pomocni_niz[100];
    int velicina_pomocnog_niza = 0;

    for(i = 0; i < vel; i++)
    {
        if(dajProsjek(niz[i]) >= prosjek)
        {
            pomocni_niz[velicina_pomocnog_niza] = niz[i];
            velicina_pomocnog_niza++;
        }
    }

    for(i = 0; i < velicina_pomocnog_niza; i++)
    {
        niz[i] = pomocni_niz[i];
    }

    printaj(pomocni_niz,velicina_pomocnog_niza);

    return  velicina_pomocnog_niza;
}

int main() {

    struct Student niz[3] = {{"Mujo","Mujic",{8},1},{"Suljo","Suljic",{},0}, {"Haso", "Hasic",{6,9,10},3}};

    genijalci(niz,3,7.0);

    return 0;
}
