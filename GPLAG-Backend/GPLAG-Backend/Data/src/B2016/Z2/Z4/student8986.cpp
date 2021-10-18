#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <new>

int BrojZnakova(char *p) {
    int brojac(0);
    while(*p!='\0') {
        brojac++;
        p++;
    }
    return brojac;
}

int PotencijalniKrivci(char **&pocetak, std::vector<std::string> imena) {
    char **pok(nullptr);
try {
    
    pok=new char*[imena.size()];
    pocetak=pok;
    try {
    for(int i=0; i<imena.size(); i++) {
        pok[i]=nullptr;
    }
    for(int i=0; i<imena.size(); i++) {
        pok[i]=new char [imena[i].length()+1];
    }
    for(int i=0; i<imena.size(); i++) {
        int j;
        for(j=0; j<imena[i].length(); j++) {
            pok[i][j]=imena[i][j];
        }
        pok[i][j]='\0';
    }
    }
    catch(...) {
        for(int i=0; i<imena.size(); i++) {
            delete[] pok[i];
        }
        delete[] pok;
        pok=nullptr;
        throw;
    }
}
    catch(...) {
        delete[] pok;
        throw;
    }
    
    return imena.size();
    
}

int OdbaciOptuzbu(char **&pocetak, int n, std::string ime) {
    
    bool optuzen(false);
    int obrisani(0);
    for(int i=0; i<n; i++) {
        int j;
        if(pocetak[i]==nullptr) obrisani++;
        for(j=0; j<ime.size(); j++) {
            if(ime[j]!=pocetak[i][j]) break;
        }
        if(j==ime.size() && pocetak[i][j]=='\0') {
            optuzen=true;
            delete[] pocetak[i];
            pocetak[i]=nullptr;
            obrisani++;
            
        }
    }
    if(!optuzen) {
        std::string tekst("Osoba sa imenom ");
        tekst+=ime;
        tekst+=" nije bila optuzena";
        throw std::domain_error (tekst);
    }
    
    if(obrisani>10) {
        char **pom=nullptr;
        try {
        
        pom=new char*[n-obrisani];
        for(int i=0; i<n-obrisani; i++) pom[i]=nullptr;
        
        int k(0);
        for(int i=0; i<n-obrisani; i++) {
            if(pocetak[k]==nullptr) {
                k++;
                i--;
            }
            else {
                pom[i]=pocetak[k];
                k++;
            }
        }
        delete[] pocetak;
        
        pocetak=pom;
        n-=obrisani;
        }
        catch(...) {delete[] pom;}
    }
    
    
    
    return n;
    
}

int DodajOptuzbu(char **&pocetak, int n, std::string ime) {
    char *novi(nullptr);
    try {
    novi=new char [ime.length()+1];
    }
    catch(...) {
        delete[] novi; throw std::bad_alloc ();
    }
    int j;
    for(j=0; j<ime.length();j++)
        novi[j]=ime[j];
    novi[j]='\0';
    int i;
    for(i=0; i<n; i++) {
        if(pocetak[i]==nullptr) {
            pocetak[i]=novi;
            break;
        }
    }
    if(i==n) {
        char **pom(nullptr);
        try {
        pom=new char*[n+1];
        int i;
        for(i=0; i<n; i++) {
            pom[i]=pocetak[i];
        }
        pom[i]=novi;
        delete[] pocetak;
        pocetak=pom;
        }
        catch(...) {
            delete[] pom;
            throw std::bad_alloc ();
        }
        
        n+=1;
    }
    
    return n;
}

void IzlistajOptuzbu(char **p, int n) {
    for(int i=0; i<n; i++) {
        if(p[i]==nullptr) continue;
        for(int j=0; j<BrojZnakova(p[i]); j++)
            std::cout<<p[i][j];
        std::cout<<std::endl;
    }
}


int main ()
{
    
    try {
    std::vector<std::string> optuzeni;
    int br;
    std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
    std::cin>>br;
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite potencijalne krivce: "<<std::endl;
    for(int i=0; i<br; i++) {
        std::string clan;
        std::getline(std::cin, clan);
        optuzeni.push_back(clan);
    }
    int n, komanda;
    char **p(nullptr);
    n=PotencijalniKrivci(p, optuzeni);
    for(;;) {
        std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
        std::cin>>komanda;
        std::cin.ignore(10000, '\n');
        if(komanda==0) break;
        else if(komanda==1) {
            std::string ime;
            std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
            std::getline(std::cin, ime);
            n=DodajOptuzbu(p, n, ime);
        }
        else if(komanda==2) {
            std::string ime;
            std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
            std::getline(std::cin, ime);
            n=OdbaciOptuzbu(p, n, ime);
        }
        else if(komanda==3) {
            IzlistajOptuzbu(p, n);
        }
    }
    
    for(int i=0; i<n; i++)
        delete[] p[i];
    delete[] p;
    }
    
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    catch(std::bad_alloc) {
        
    }
    
    
    
	return 0;
}