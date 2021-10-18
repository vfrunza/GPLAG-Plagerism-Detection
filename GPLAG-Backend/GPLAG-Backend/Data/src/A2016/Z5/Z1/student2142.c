#include <stdio.h>
struct Student {
    char ime[20], prezime[20];
    int ocjene[50], br_ocjena;
};

double zadovoljavaProsjek (struct Student kolega){
    int i = 0;
    if (kolega.br_ocjena == 0){
        return 0;
    }
    double postignuce = 0;
    while (i < kolega.br_ocjena){
        if (kolega.ocjene[i] == 5) return 0;
        postignuce += kolega.ocjene[i++];
    }
    postignuce = postignuce / kolega.br_ocjena;
    return postignuce;
}

int prednjaci(struct Student s1, struct Student s2){
    int i = 0, brojac = 0;
    while (s1.prezime[i] != '\0' && s2.prezime[i] != '\0' && s1.prezime[i] == s2.prezime[i]) i++;
    if ((s1.prezime[i] != '\0' && s2.prezime[i] == '\0') || (s1.prezime[i] > s2.prezime[i])) return 0;
    else if((s1.prezime[i] == '\0' && s2.prezime[i] != '\0') || (s1.prezime[i] < s2.prezime[i])) return 1;
    i = 0;
    while (s1.ime[i] != '\0' && s2.ime[i] != '\0' && s1.ime[i] == s2.ime[i]) i++;
    if ((s1.ime[i] != '\0' && s2.ime[i] == '\0') || (s1.ime[i] > s2.ime[i])) return 0;
    else if ((s1.ime[i] == '\0' && s2.ime[i] != '\0') || (s1.ime[i] < s2.ime[i])) return 1;
    return 0;
}

void najboljiPoRedu(struct Student *studenti, int vel){
    int i = 0, index, zabranjeni_index1 = -1, zabranjeni_index2 = -1;
    double max;
    struct Student najbolji[3];
    i = 0;
    while (i < 3 && i < vel){
        max = 0;
        int j;
        for (j = 0; j < vel; j++){
            if (zadovoljavaProsjek(studenti[j]) > max && j != zabranjeni_index1 && j != zabranjeni_index2){
                max = zadovoljavaProsjek(studenti[j]); index = j;
            }
            else if (zadovoljavaProsjek(studenti[j]) == max && j != zabranjeni_index1 && j != zabranjeni_index2){
                if (prednjaci(studenti[j], studenti[index])){
                    max = zadovoljavaProsjek(studenti[j]); index = j;
                }
            }
        }
        najbolji[i] = studenti[index];
        if (i == 0) zabranjeni_index1 = index;
        else if (i == 1) zabranjeni_index2 = index;
        i++;
    }
    int j;
    for (j = 0; j < i; j++){
        printf ("%s %s\n", najbolji[j].prezime, najbolji[j].ime);
    }
}

int genijalci (struct Student *studenti, int vel, double prosjek){
    int i = 0;
    while (i < vel){
        if (zadovoljavaProsjek(studenti[i]) < prosjek){
            int j = i;
            while (j < vel - 1){
                studenti[j] = studenti[j+1]; j++;
            }
            vel--; i--;
        }
        i++;
    }
    int j;
    najboljiPoRedu(studenti, vel);
    return vel;
}

int main() {
    struct Student studenti[5] ={
	    { "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	    { "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	    { "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	    { "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	    { "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
    };
    genijalci(studenti, 5, 6.5);
    return 0;
}