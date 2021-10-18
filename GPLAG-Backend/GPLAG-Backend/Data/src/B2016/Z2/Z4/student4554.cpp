#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <algorithm>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int Prebroj_nulte(char **&optuzeni, int vel) {

    int brojac(0);

    for (int i = 0; i < vel; i++) {
        if(!optuzeni[i])
            brojac++;
    }
    return brojac;
}

bool JednakiSu(char *optuzeni, string ime) {
    if(!optuzeni)
        return false;
    for (int i = 0; i < ime.length(); i++) {
        if(optuzeni[i] != ime[i] || optuzeni[i] == '\0')
            return false;
   }
    return true;
}

int DodajOptuzbu (char **& optuzeni, int vel, string ime) {

    bool ima_li_nultog=false;
    int br_nultog;

    for (int i = 0; i < vel; i++) {
        if(!optuzeni[i]) {
            ima_li_nultog=true;
            br_nultog=i;
            break;
        }
    }
    char *pok=nullptr;
    try {
        pok = new char[ime.length()+1];
        std::copy(ime.begin(), ime.end(), pok);
        pok[ime.length()] = '\0';
    }
    catch (std::bad_alloc) {
        return vel;
    }

    if(ima_li_nultog) {
        optuzeni[br_nultog] = pok;
        return vel;
    }

    char **brisac(optuzeni);
    optuzeni = nullptr;

    try {

        optuzeni = new char *[vel+1];

        for (int i = 0; i < vel+1; i++) {
            optuzeni[i] = nullptr;
        }

        for (int i = 0; i < vel; i++) {
            optuzeni[i] = new char [strlen(brisac[i])+1];
        }

        for (int i = 0; i < vel; i++) {
            strcpy(optuzeni[i], brisac[i]);
        }
        optuzeni[vel] = pok;

    }
    catch (std::bad_alloc) {
        for (int i = 0; i < vel+1; i++) {
            delete[] optuzeni[i];
        }
        delete[] optuzeni;
        optuzeni = brisac;
        return vel;
    }
    for (int i = 0; i < vel; i++) {
        delete[] brisac[i];
    }
    delete[] brisac;

    return ++vel;
 }

int OdbaciOptuzbu (char **& optuzeni, int vel, string ime) {    // NE ZABORAVI IZUZETAK

    for (int i = 0; i < vel; i++) {
        if(JednakiSu(optuzeni[i],ime)) {
            delete[] optuzeni[i];
            optuzeni[i] = nullptr;
            break;
        }
//        if(i == vel-1)
 //           throw;
    }

    if(Prebroj_nulte(optuzeni, vel)<=10) {
        return vel;
    }

    char **brisac(optuzeni);
    int br_nultih(0);
    int duz;
    int br_imena;

    duz = vel-Prebroj_nulte(optuzeni, vel);
    try {
        optuzeni = new char *[duz];
    } catch (std::bad_alloc) {
        optuzeni = brisac;
        return vel;
    }
    for (int i = 0; i < duz; i++) {
        optuzeni[i] = nullptr;
    }
    try {
        for (int i = 0; i < duz; i++) {
            for (int j = i+br_nultih; j < vel; j++) {
                if(brisac[j]) {
                    br_imena = j;
                    break;
                }
                br_nultih++;
            }
            optuzeni[i] = new char [strlen(brisac[br_imena]+1)];
            strcpy(optuzeni[i], brisac[br_imena]);
            optuzeni[i][strlen(brisac[br_imena])] = '\0';
        }
    }
    catch (std::bad_alloc) {
        for (int i = 0; i < duz; i++) {
            delete[] optuzeni[i];
        }
        delete[] optuzeni;
        optuzeni = brisac;
        return vel;
    }

    for (int i = 0; i < vel; i++) {
        delete[] brisac[i];
    }
    delete[] brisac;

    return duz;
}

void IzlistajOptuzbu (char **optuzeni, int vel) {
    char *p;
    for (int i = 0; i < vel; i++) {
        p = optuzeni[i];
        if(p) {
            while (*p != '\0') {
                cout << *p++;
            }
            cout << endl;
        }
    }
}

int PotencijalniKrivci (char **& optuzeni, std::vector<string> imena) {

    int brojac(0);

    try {
        optuzeni = new char *[imena.size()];

        for (int i = 0; i < imena.size(); i++) {
            optuzeni[i] = nullptr;
        }

        for (int i = 0; i < imena.size(); i++) {
            optuzeni[i] = new char [imena[i].length()+1];
            brojac++;
        }
    }
    catch (std::bad_alloc) {
        for (int i = 0; i < brojac; i++) {
            delete[] optuzeni[i];
        }
        delete[] optuzeni;
        throw std::bad_alloc();                           // Za sad neka ovdje zaustavlja program
    }

    for (int i = 0; i < brojac; i++) {
        std::copy(imena[i].begin(), imena[i].end(), optuzeni[i]);
        optuzeni[i][imena[i].length()] = '\0';
    }
    return brojac;
}

int main ()
{
    int n;
    cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl;
    cin >> n;

    cout << "Unesite potencijalne krivce: " << endl;
    std::cin.ignore(1000,'\n');

    std::vector<string> vecstr;
    std::string krivac;

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, krivac);
        vecstr.push_back(krivac);
    }

    char **optuzeni;

    try{
        PotencijalniKrivci(optuzeni,vecstr);
    } catch(std::bad_alloc) {
        return 0;
    }
    int opcija;
    string ime;

    do {
        cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje"
              << " nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<< endl;
        cin >> opcija;

        switch (opcija) {
            case 0:
                break;
            case 1:
                cin.ignore(1000,'\n');
                cout << "Unesite ime novog optuzenog: " << endl;
                std::getline(std::cin, ime);
                n = DodajOptuzbu(optuzeni, n, ime);
                break;
            case 2:
                cin.ignore(1000,'\n');
                cout << "Unesite ime koje zelite izbaciti: " << endl;
                std::getline(std::cin, ime);
                try {
                   n = OdbaciOptuzbu(optuzeni, n, ime);
                }
                catch (...) {
                    std::cout << "Osoba sa imenom "<< ime << " nije bila optuzena" << endl;
                }

                break;

            case 3:
                IzlistajOptuzbu(optuzeni, n);
                break;
        }

    } while (opcija);
    for (int i = 0; i < n; i++) {
        delete[] optuzeni[i];
    }
    delete[] optuzeni;
    
	return 0;
}
