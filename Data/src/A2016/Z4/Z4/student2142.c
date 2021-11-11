#include <stdio.h>
#include <math.h>

int jesteNije(char* niz_tacaka, int* i){
    if (niz_tacaka[*i] == '-') (*i)++;
    if (niz_tacaka[*i] >= 48 && niz_tacaka[*i] <= 57)
        while(niz_tacaka[*i] >= 48 && niz_tacaka[*i] <= 57) (*i)++;
    else return 0;
    if(niz_tacaka[*i] == '.'){
        (*i)++;
        while(niz_tacaka[*i] >= 48 && niz_tacaka[*i] <= 57) (*i)++;
    }
    return 1;
}
// Ovom funkcijom se provjerava da li je dobiveni string tacaka pravilno napisan
int provjeriKriterij(char* niz_tacaka){
    int i = 0;
    while(niz_tacaka[i] != '\0'){
        if (niz_tacaka[i++] != '(') return 0;
        if (!jesteNije(niz_tacaka, &i)) return 0;
        if (niz_tacaka[i++] != ',') return 0;
        if (!jesteNije(niz_tacaka, &i)) return 0;
        if (niz_tacaka[i++] != ')') return 0;
        if (niz_tacaka[i] != ',') {
            if (niz_tacaka[i] != '\0') return 0;
            else break;
        }
        if (niz_tacaka[i] == ',' && niz_tacaka[i+1] == '\0') return 0;
        i++;
    }
    return 1;
}
// Funkcija koja na primljenoj adresi detektovani broj pretvara u int i gleda jel se nalazi u povrsini pravougaonika
int provjeraOpsega(double maximum, double minimum, char* niz_tacaka){
    int j = 0;
    int mnozilac = 1;
    double decimalni = 0.1;
    // Predznak mi sluzi da ako je bio znak '-' prije broja zapamti to i pretvori ga u negativni
    int predznak = 1;
    double broj_za_provjeriti = 0;
    while (niz_tacaka[j+1] != '.' && niz_tacaka[j+1] != ',' && niz_tacaka[j+1] != ')') j++;
    while (niz_tacaka[j] >= 48 && niz_tacaka[j] <= 57){
        broj_za_provjeriti += (niz_tacaka[j] - 48) * mnozilac;
        j--;
        mnozilac *= 10;
    }
    if (niz_tacaka[j] == '-') predznak = -1;
    j++;
    while (niz_tacaka[j] != '.' && niz_tacaka[j] != ',' && niz_tacaka[j] != ')') j++;
    if (niz_tacaka[j] == '.'){
        j++;
        while (niz_tacaka[j] >= 48 && niz_tacaka[j] <= 57){
            broj_za_provjeriti += (niz_tacaka[j] - 48)*decimalni;
            decimalni /= 10;
            j++;
        }
    }
    broj_za_provjeriti *= predznak;
    if (broj_za_provjeriti <= maximum && broj_za_provjeriti >= minimum) return 1;
    else return 0;
}
// Funkcija kojom izbacujem tacku koja se ne nalazi u povrsini pravougaonika
void izbaciKoordinatuTacke(char* niz_tacaka, int index){
    char* temp = niz_tacaka;
    int k = index;
    int duzina = 0;
    while (niz_tacaka[k++] != ')') {
        duzina++;
    }
    k = duzina;
    if (niz_tacaka[index + k + 1] != '\0'){
        duzina++;
    }
    else if (index != 0){
        index--; duzina++;
    }
    niz_tacaka += index;
    while(duzina >= 0){
        k = 0;
        while (niz_tacaka[k] != '\0'){
            niz_tacaka[k] = niz_tacaka[k+1];
            k++;
        }
        duzina--;
    }
    niz_tacaka = temp;
}

char* obuhvat(char* niz_tacaka, double min_x, double min_y, double max_x, double max_y){
    if (niz_tacaka[0] == '\0') return niz_tacaka;
    if (!provjeriKriterij(niz_tacaka)){
        return NULL;
    }
    int j = 0;
    while (niz_tacaka[j] != '\0'){
        if (niz_tacaka[j] == '\0') break;
        if (j != 0) j++;
        if (!provjeraOpsega(max_x, min_x, niz_tacaka+j)){
            while (niz_tacaka[j] != '(') j--;
            izbaciKoordinatuTacke(niz_tacaka, j);
            continue;
        }
        if (niz_tacaka[j] == '\0') break;
        while (niz_tacaka[j++] != ',');
        if (!provjeraOpsega(max_y, min_y, niz_tacaka+j)){
            while (niz_tacaka[j] != '(') j--;
            izbaciKoordinatuTacke(niz_tacaka, j);
            continue;
        }
        if (niz_tacaka[j] == '\0') break;
        while (niz_tacaka[j] != ')' && niz_tacaka[j] != '\0') j++;
        j++;
    }
    return niz_tacaka;
}

int main() {
    char s[] = "(3.0001,3),(3,3),(3,3)";
    printf("%s", obuhvat(s, 3, 3, 3.0001, 3));
    return 0;
}