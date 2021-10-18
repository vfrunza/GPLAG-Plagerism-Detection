/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>

//provjera da li je znak dio rijeci
bool Tekst_ili_broj (char a) {
    if (a>='0' && a<='9') return true;
    if ((a>='A' && a<='Z') || (a>='a' && a<='z')) return true;
    return false;
}
//pretvara rijec u mala slova
std::string Pretvori_u_mala(std::string a) {
    for (int i=0; i<a.size(); i++)
        if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

//provjera da li su stringovi jednaki
bool Ista_rijec (std::string a, std::string b) {
    a=Pretvori_u_mala(a);
    b=Pretvori_u_mala(b);
    if (a.size()!=b.size()) return false;
    for (int i=0; i<a.size(); i++)
        if (a[i]!=b[i]) return false;
    return true;
}
//KREIRA MAPU KOJA SADRZAVA SVE RIJECI I POZICIJE SVAKE RIJECI U RECENICI
std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string t) {
    std::map<std::string,std::set<int>> rijeci;
    for (int i=0; i<t.size(); i++) {
//std::cout<<t[i]<<" prva ";
        if (Tekst_ili_broj(t[i])) {
            std::string pom;
            int pozicija=i;
            for (int j=i; Tekst_ili_broj(t[j]) && j<t.size(); j++,i++) //izdvajam rijec po rijec iz recenice
                pom+=t[j];
            pom=Pretvori_u_mala(pom);
            auto it=rijeci.find(pom);
            if (it==rijeci.end()) {
                std::set<int> skup;
                skup.insert(pozicija);
                for (int k=i; k<t.size(); k++) {        //u ovom dijelu izdvajam takodjer rijec iz recenice, ali iz ostatka recenice, i poredim sa prethodno zapamcenom rijeci
//std::cout<<t[k]<<" slova "; break;
                    if (Tekst_ili_broj(t[k])) {
                        int trenutna=k;
                        std::string drugi;
                        for (int m=k; Tekst_ili_broj(t[m]) && m<t.size(); m++,k++)
                            drugi+=t[m];
                        if (Ista_rijec(pom,drugi)) skup.insert(trenutna);       //poredim rijeci, ako su iste poziciju druge rijeci smijestam u skupo pozicija te rijeci
                    }
                }
                rijeci.insert(std::make_pair(pom,skup));
            }
            i--;
        }
    }
    return rijeci;
}
//FUNKCIJA PRETRAZUJE MAPU, DA LI SE U NJOJ NALAZI ZADANA RIJEC, I VARACA SKUP POZICIJA TE RIJECI, ILI AKO JE NEMA BACA IZUZETAK
std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> rijeci) {
    s=Pretvori_u_mala(s);
    auto it=rijeci.find(s);
    if (it==rijeci.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}
//FUNKCIJA ZA ISPIS MAPE NA EKRAN
void IspisiIndeksPojmova (std::map<std::string,std::set<int>> mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<Pretvori_u_mala(it->first)<<": ";
        int a=0;
        for(auto x : it->second) {
            if (a==0) { std::cout<<x; a=1; }
            else std::cout<<","<<x;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,tekst);
    auto indeks_pojmova=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeks_pojmova);
    std::string rijec;
    for (;;) {
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if (rijec==".") break;
        try {
            auto skup_pozicija=PretraziIndeksPojmova(rijec, indeks_pojmova);
            for (auto x : skup_pozicija) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch (std::logic_error nema_rijeci) {
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}