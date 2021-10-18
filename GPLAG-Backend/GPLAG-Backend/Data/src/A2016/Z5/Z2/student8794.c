#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    char string[12];
    int br_pon;
} Rijec;


int kompresuj (char* ime_ulaz, char* ime_izlaz)
{
    FILE* ulaz = fopen (ime_ulaz, "r+");
    if (ulaz == NULL) {
        printf ("Greska pri otvaranju ulazne datoteke :%s",ime_ulaz);
        return 1;
    }
    
    FILE* izlaz = fopen (ime_izlaz, "w+");

    if (izlaz == NULL) {
        printf ("Greska pri otvaranju datoteke izlaz: %s",ime_izlaz);
        return 2;
    }
    Rijec rijeci[1000];


    char token[20];
    char *p = token;
    int i;
    int flag = 0;


    int broj_rj = 0;

    int znak = fgetc(ulaz);

    while (znak != EOF) {
        if ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')) {
            i = 0;
            p = token;
            while (((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'))  && i < 12) {
                
                *p = znak;
                p++;
                znak = fgetc(ulaz);

                i++;
            }
            *p = '\0';
            
            while (((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'))) {
                if (znak == EOF)
                    break;
                znak = fgetc(ulaz);

            }
            flag = 0;
            
            if (strlen(token) > 1 && strlen(token) < 10) {
                flag = 1;
                for (i = 0; i < broj_rj; i++) {
                    if (strcmp(rijeci[i].string, token) == 0) {
                        flag = 2;
                        break;
                    }
                }
            }

            if (flag == 2) {
                rijeci[i].br_pon++;

                // dodajemo rijec u niz rijeci i povecavamo br_pon
            }
            if (flag == 1) {

                strcpy (rijeci[broj_rj].string, token);
                rijeci[broj_rj].br_pon = 1;
                broj_rj++;

            }
        }
        if (znak == EOF) {
            break;
        }
        znak = fgetc(ulaz);

    }

    Rijec temp;
    int min,j;

    for (i=0; i < broj_rj; i++) {
        min=i;
        for (j=i+1; j<broj_rj; j++) {
            if (rijeci[j].br_pon > rijeci[min].br_pon) {
                min = j;
            }

        }
        temp = rijeci[i];
        rijeci[i] = rijeci[min];
        rijeci[min] = temp;

    }
    for (i=0; i < broj_rj; i++) {
        min=i;
        for (j=i+1; j<broj_rj; j++) {

            if ((rijeci[j].br_pon == rijeci[min].br_pon) && strcmp(rijeci[j].string,rijeci[min].string) < 0) {
                min = j;
            }
        }
        temp = rijeci[i];
        rijeci[i] = rijeci[min];
        rijeci[min] = temp;

    }

    fseek (ulaz, 0, SEEK_SET);

    Rijec zamjena[10];
    char str2[2] = "\0";
    for (i = 0; i < 10; i++) {
        str2[0] = 20+i;
        strcpy(zamjena[i].string,str2);
    }

    for (i = 0; i < (10 < broj_rj ? 10 : broj_rj); i++) {
        fprintf (izlaz,"%s\n",rijeci[i].string);
    }
    fprintf (izlaz,"\n");

    fseek (ulaz, 0, SEEK_SET);
    znak = fgetc(ulaz);
    while (znak != EOF) {
    
        if ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')) {
            
            i = 0;
            p = token;
            while (((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'))  && i < 12) {
                if (znak == EOF)
                    break;
                *p = znak;
                p++;
                znak = fgetc(ulaz);

                i++;
            }
            *p = '\0';
            
            flag = 0;
            if (strlen(token) > 1 && strlen(token) < 10) {
                for (i = 0; i < broj_rj && i < 10; i++) {
                    if (strcmp(rijeci[i].string, token) == 0) {
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag == 1) {
                fputs(zamjena[i].string,izlaz);
            } else fputs (token,izlaz);

        }

        if (znak == EOF) {
            break;
        }
        fputc(znak,izlaz);
        znak = fgetc(ulaz);
    }
    fclose(ulaz);
    fclose(izlaz);
    printf ("Datoteka kompresovana.\n");
    return 0;
}

int dekompresuj (char* ime_ulaz, char* ime_izlaz)
{
    FILE* ulaz = fopen (ime_ulaz, "r+");
    if (ulaz == NULL) {
        printf ("Greska pri otvaranju datoteke ulaz");
        return 1;
    }
    FILE* izlaz = fopen (ime_izlaz, "w+");
    int i;
    if (izlaz == NULL) {
        printf ("Greska pri otvaranju datoteke izlaz: %s",ime_izlaz);
        return 2;
    }

    Rijec rijeci[10];
    char str2[2] = "\0";
    for (i = 0; i < 10; i++) {
        str2[0] = 20+i;
        strcpy(rijeci[i].string,str2);
    }

    Rijec zamjena[10];
    i = 0;
    char line[15];
    char *p = line;
    while (fgets(line,15,ulaz) && i < 10) {
        p = line;
        if (*p == '\n') {
            break;
        }
        while (*p != '\0') {
            if (*p == '\n') {
                *p = '\0';
                break;
            }
            p++;
        }
        strcpy (zamjena[i].string,line);
        i++;
    }


    char line2[20];


    fseek (ulaz, 0, SEEK_SET);
    while(fgets(line2,20,ulaz)) {
        if (line2[0] == '\n') {
            break;
        }
    }
    int flag = 0;
    int  znak = fgetc(ulaz);
    while (znak != EOF) {
        flag = 0;
        for (i = 0; i < 10; i++) {
            if (znak == 20 + i) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            fputs(zamjena[i].string,izlaz);
        } else fputc(znak,izlaz);
        znak = fgetc(ulaz);
    }
    fclose(ulaz);
    fclose(izlaz);
    printf ("Datoteka dekompresovana.\n");
    return 0;
}


void menu ()
{
    int opcija;
    char ime_ulaz[80];
    char ime_izlaz[80];
    
    do {
        printf ("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf ("%d", &opcija);
        
        if (opcija == 0)
            return;
        switch (opcija) {
        case 1: if (opcija == 0) { return; }
            
            printf("Unesite ime ulazne datoteke: ");
            scanf ("%s",ime_ulaz);
            printf("Unesite ime izlazne datoteke: ");
            scanf ("%s",ime_izlaz);
            kompresuj(ime_ulaz,ime_izlaz);
            printf("\n");
            break;
        case 2: if (opcija == 0) { return; }
            
            printf("Unesite ime ulazne datoteke: ");
            scanf ("%s",ime_ulaz);
            printf("Unesite ime izlazne datoteke: ");
            scanf ("%s",ime_izlaz);
            dekompresuj(ime_ulaz,ime_izlaz);
            printf("\n");
            break;
        case 0: if (opcija == 0) { return; } break;
        
        default: if (opcija == 0) if (opcija == 0) { return; } break;
            
        }
        if (opcija == 0) {
            return; 
        }
            
    } while (opcija != 0);
    
}






int main()
{
    
    menu();
    return 0;
}
