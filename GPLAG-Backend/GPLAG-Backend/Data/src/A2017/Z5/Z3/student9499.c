#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define FILEDAT 	    "./oblici.dat"
#define TEMPFILE 	    "./temp.dat"
#define SEEK_START      0
#define X_SIZE          1
#define N_SIZE          2
#define BIT_DF          4
#define NAZIV_SIZE      20
#define N_PAGES         300

/* structure definition */
struct Oblik {
	char naziv[NAZIV_SIZE];
	int br_stranica;
	double stranice[N_PAGES];
};

/* number of elements */
int shapeNum() {
    int _num, check = 0;
    FILE *file = fopen(FILEDAT, "rb");
    if(file == NULL) {
        fclose(file);
        return 0;
    }
    check = fread(&_num, 1, N_SIZE, file);
    fclose(file);
    if(!check) return 0;
    return _num;
}

/* overwrite N-number of shapes */
void _numChange(int value) {
    int num = value;
    FILE *file = fopen(FILEDAT, "rb+");
    if(file == NULL) {
        fclose(file);
        return;
    }
    fseek(file, SEEK_START, SEEK_SET);
    fwrite(&num, 1, N_SIZE, file);
    fclose(file);
}
/* overwrite in temp file */
void _numChangeTemp(int value) {
    int num = value;
    FILE *file = fopen(TEMPFILE, "rb+");
    if(file == NULL) {
        fclose(file);
        return;
    }
    fseek(file, SEEK_START, SEEK_SET);
    fwrite(&num, 1, N_SIZE, file);
    fclose(file);
}

/* add shape in shape file */
void dodaj_oblik(struct Oblik shape) {
    float stranica;
    int newSize = 0, i = 0;
    FILE *file;
	
    newSize = shapeNum()+1;
    _numChange(newSize);
    
    file = fopen(FILEDAT, "ab");
    if(file == NULL) {
        fclose(file);
        return;
    }
    fwrite(&shape.naziv, NAZIV_SIZE, 1, file);
    fwrite(&shape.br_stranica, X_SIZE, 1, file);
    for(i = 0; i < shape.br_stranica && i < N_PAGES; i++) {
        stranica = (float)shape.stranice[i];   /* float->double cast */
        fwrite(&stranica, BIT_DF, 1, file);
    }
    fclose(file);
}

/* add shape in temp file */
void dodaj_oblikTemp(struct Oblik shape) {
    float stranica;
    int i = 0;
    FILE *file;
    file = fopen(TEMPFILE, "ab");
    if(file == NULL) {
        fclose(file);
        return;
    }
    fwrite(&shape.naziv, NAZIV_SIZE, 1, file);
    fwrite(&shape.br_stranica, X_SIZE, 1, file);
    for(i = 0; i < shape.br_stranica && i < N_PAGES; i++) {
        stranica = (float)shape.stranice[i];   /* float->double cast */
        fwrite(&stranica, BIT_DF, 1, file);
    }
    fclose(file);
}

/* remove doubles */
void izbaci_duple() {
    /* get the size of elements */
    struct Oblik oblik, tshape;
    int arrLength = 0, finalSize = 0, j = 0, i = 0, k = 0, _exists = 0;
    char broj_stranica = 0;
    int valid[3];
    float stranica = .0;
    FILE* file;
    FILE* tf;

    /* create temprorary file */
    tf = fopen(TEMPFILE, "wb+");
    _numChangeTemp(finalSize);
    
    /* read my main file */
    file = fopen(FILEDAT, "rb");
    if(file == NULL) {
        fclose(tf);
        return;
    }
    /* create stack of shapes with different names */
    fread(&arrLength, 1, N_SIZE, file);
    while(i < arrLength) {
        valid[0] = 0; valid[1] = 0; valid[2] = 0;
        valid[0] = fread(oblik.naziv, NAZIV_SIZE, 1, file);
        valid[1] = fread(&broj_stranica, X_SIZE,  1, file);
        oblik.br_stranica = broj_stranica;
        
        for(j = 0; j < oblik.br_stranica; j++) {
            valid[2] = fread(&stranica, BIT_DF, 1, file);
            oblik.stranice[j] = (double)stranica;
        }
        
        /* check if shape is already in temp file, if not, then add */
        _exists = 0;
        fseek(tf, N_SIZE, SEEK_SET); /* put cursor on first shape */
        for(j = 0; j < finalSize; j++) {
            fread(tshape.naziv, NAZIV_SIZE, 1, tf);
            fread(&broj_stranica, X_SIZE,  1, tf);
            tshape.br_stranica = broj_stranica;
            for(k = 0; k < tshape.br_stranica; k++) {
                fread(&stranica, BIT_DF, 1, tf);
                tshape.stranice[k] = (double)stranica;
            }
            
            /* check if any of the shapes in temp file has the same name */
            if(strcmp(tshape.naziv, oblik.naziv) == 0) {
                _exists = 1;
                break;
            }
        }
        
        /* add shape in temp file */
        if(!_exists && valid[0] && valid[1] && valid[2]) {
            finalSize++;
            _numChangeTemp(finalSize);
            dodaj_oblikTemp(oblik);
        }
        i++;
    }
    fclose(tf);
    fclose(file);
    
    /* rewrite my original file */
    remove(FILEDAT);
    rename(TEMPFILE, FILEDAT);
}

/* find the biggest shape in the stack */
struct Oblik daj_najveci() {
	struct Oblik shape, maxShape;
    double maxSize = 0.0, localSize = 0.0;
    int j = 0, i = 0, _num = 0;
    
    char broj_stranica;
    float stranica = 0.0;
    
    FILE *file = fopen(FILEDAT, "rb");
    if(file == NULL) {
        fclose(file);
        exit(1);
    }
    
    /* go through array and search for them */
    fread(&_num, 1, N_SIZE, file);
    while(i < _num) {
        fread(shape.naziv, NAZIV_SIZE, 1, file);
        fread(&broj_stranica, X_SIZE,  1, file);
        shape.br_stranica = broj_stranica;
        
        localSize = 0.0;
        for(j = 0; j < shape.br_stranica && j < N_PAGES; j++) {
            fread(&stranica, BIT_DF, 1, file);
            shape.stranice[j] = (double)stranica;
            localSize += shape.stranice[j];
        }
        
        /* swap shapes with maximum */
        if(localSize > maxSize) {
            maxSize = localSize;
            maxShape = shape;
        }
        i++;
    }
    
    fclose(file);
    return maxShape;
}

int main() {
    
	return 0;
}