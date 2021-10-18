#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
unsigned short velicina;
FILE * bin;
FILE * bin_tmp;

struct Oblik {
    char naziv[20];
    int br_stranica;
    double stranice[300];
} o;


void dodaj_oblik(struct Oblik o1)
{
    int i;
    float stranice2[300];
    unsigned char br_stranica = (unsigned char) o1.br_stranica;

    bin = fopen("oblici.dat","a+b");
    fread(&velicina,sizeof(unsigned short),1,bin);
    rewind(bin);
    for(i=0; i<300; i++) stranice2[i]=(float) o1.stranice[i];

    if(!bin)
        exit(1);

    fwrite(o1.naziv,sizeof(char),20,bin);
    fwrite(&br_stranica,sizeof(unsigned char),1,bin);
    fwrite(stranice2,sizeof(float),(int)br_stranica,bin);
    fclose(bin);

    velicina++;
    bin=fopen("oblici.dat","r+b");
    fwrite(&velicina,sizeof(unsigned short),1,bin);
    fclose(bin);
}

struct Oblik daj_najveci()
{
    float stranice3[300]= {0};
    float O=0.0,temp_O=0.0;
    int i;
    unsigned char pomak , br_stranica;
    long int pozicija,pozicija_struct=0;
    FILE*bin=fopen("oblici.dat","rb");

    fseek(bin,22,SEEK_SET);
    fread(&pomak,sizeof(unsigned char),1,bin);

    do {
        fread(stranice3,sizeof(float),(int)pomak,bin);
        pozicija=ftell(bin);
        for(i=0; i<(int)pomak; i++)
            temp_O+=stranice3[i];
        stranice3[i]=0;

        if(temp_O>O) {
            O=temp_O;
            pozicija_struct=pozicija-(int)pomak*4-20*sizeof(char)-sizeof(unsigned char);
        }

        pozicija=ftell(bin);
        fseek(bin,pozicija+20,SEEK_SET);
        fread(&pomak,sizeof(unsigned char),1,bin);
        temp_O=0.0;
    } while(!feof(bin));

    fseek(bin,pozicija_struct,SEEK_SET);
    fread(&o.naziv,sizeof(char),20,bin);
    fread(&br_stranica,sizeof(unsigned char),1,bin);
    o.br_stranica = (int) br_stranica;
    fread(stranice3,sizeof(float),(int)br_stranica,bin);

    for(i=0; i<(int)br_stranica; i++)
        o.stranice[i]=(double)stranice3[i];

    fclose(bin);

    return o;
}


int pripada(long *l,int n,long p)
{
    int i;
    for (i=0; i<n; i++) {
        if(p==l[i])
            return 1;
    }

    return 0;
}

void izbaci_duple()
{
    int n=20;
    int i=0;
    long pos, pos2, kraj;
    char naziv[20];
    char naziv_temp[20];
    float stranice[300]= {0};
    unsigned char br_stranica;
    unsigned short br_oblika;
    long pozicije[100];
    for(i=0; i<100; i++) pozicije[i]=-1;
    i=0;

    bin=fopen("oblici.dat","rb");
    if(!bin) exit(1);
    bin_tmp = fopen("oblici_temp.dat","wb");
    if(!bin_tmp) exit(1);

    fread(&br_oblika,sizeof(unsigned short),1,bin);
    fwrite(&br_oblika,sizeof(unsigned short),1,bin_tmp);
    pos=ftell(bin);
    fseek(bin,0,SEEK_END);
    kraj=ftell(bin);
    fseek(bin,pos,SEEK_SET);


    do {
        pos=ftell(bin);
        fread(naziv,sizeof(char),20,bin);
        fread(&br_stranica,sizeof(unsigned char),1,bin);
        fread(stranice,sizeof(float),(int)br_stranica,bin);
        if(ferror(bin)) break;

        if(!pripada(pozicije,100,pos)) {
            pos=ftell(bin);
            do {
                pos2=ftell(bin);
                fread(naziv_temp,sizeof(char),20,bin);
                fread(&br_stranica,sizeof(unsigned char),1,bin);
                fread(stranice,sizeof(float),(int)br_stranica,bin);
                stranice[(int)br_stranica]=0;
                if(ferror(bin)) break;
                if(strcmp(naziv,naziv_temp)==0) {
                    pozicije[i]=pos2;
                    i++;
                }
            } while(!feof(bin));

        }

        else pos=ftell(bin);
        fseek(bin,pos,SEEK_SET);

    } while(pos!=kraj);

    br_oblika=0;
    fseek(bin,2,SEEK_SET);
    pos=ftell(bin);

    do {
        fread(naziv,sizeof(char),20,bin);
        fread(&br_stranica,sizeof(unsigned char),1,bin);
        fread(stranice,sizeof(float),(int)br_stranica,bin);

        if(!pripada(pozicije,n,pos)) {
            br_oblika++;
            fwrite(naziv,sizeof(char),20,bin_tmp);
            fwrite(&br_stranica,sizeof(unsigned char),1,bin_tmp);
            fwrite(stranice,sizeof(float),(int)br_stranica,bin_tmp);
        }

        pos=ftell(bin);

    } while(pos!=kraj);

    fseek(bin_tmp,0,SEEK_SET);
    fwrite(&br_oblika,sizeof(unsigned short),1,bin_tmp);

    fclose(bin);
    fclose(bin_tmp);

    remove("oblici.dat");
    rename("oblici_temp.dat","oblici.dat");
}

int main()
{
    FILE* fp;
    int c, i=0;

    struct Oblik niz[] = {
        {"Trougao", 3, {1.1, 1.1, 1.1}},
        {"Trougao", 3, {1.1, 1.1, 1.1}},
        {"Trougao", 3, {100.1, 100.1, 100.1}},
        {"Kvadrat", 4, {1.1, 1.1, 1.1, 1.1}},
        {"Trougao", 3, {1.1, 1.1, 1.1}}
    };
    dodaj_oblik(niz[0]);
    dodaj_oblik(niz[1]);
    dodaj_oblik(niz[2]);
    dodaj_oblik(niz[3]);
    dodaj_oblik(niz[4]);

    izbaci_duple();

    fp = fopen("oblici.dat", "rb");
    i=0;
    do {
        c = fgetc(fp);
        if (i<2) printf("%d ", c);
        i++;
    } while (c != EOF);
    fclose(fp);


    return 0;
}
