/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <stdexcept>
#include <utility>


typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

std::string PretvoriUMala (std::string s){
    std::string s1;
    for(auto c : s) {if (c>='A' && c<='Z') {c+=('a'-'A');} s1.push_back(c);}
    return s1;
}

//Funkcija kojoj proslijedim jedan string(stranicu) i jednu rijec iz skupa rijeci, a kao rez vrati vektor pozicija te rijeci u stringu
std::vector<int> VratiPoziciju (std::string recenica, std::string rijec)
{
    int pozicija=0;
    
    std::vector<int> vektor_pozicija_u_jednom_stringu;
    for(int i=0; i!=recenica.length(); ) {
        while(!((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9') || i==recenica.length()))  {
            i++;
            pozicija++;
        }
        std::string pomocna_rijec;
        int pamti_poziciju=pozicija;
        while(((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9')) && i!=recenica.length())  {
            pomocna_rijec.push_back(recenica[i]);
            i++;
            pozicija++;
        }
        if(pomocna_rijec==rijec) vektor_pozicija_u_jednom_stringu.push_back(pamti_poziciju);
    }
    return vektor_pozicija_u_jednom_stringu;
}

//Funkcija koja vraca skup rijeci iz knjige
std::set<std::string> VratiRijeci(Knjiga k)
{
    std::set<std::string> skup_rijeci;
    
    for(auto it=k.begin(); it!=k.end(); it++) {
        for(int i=0; i!=it->second.size(); i++) {
            
            std::string s(it->second[i]);

            for(int j=0; j!=s.length();) {
                while(!((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9') || j==s.length())) j++;
                std::string pomocni_string;
                while(((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')) && j!=s.length()) {
                    pomocni_string.push_back(s[j]);
                    j++;
                }
                if(pomocni_string.length()!=0) skup_rijeci.insert(PretvoriUMala(pomocni_string));
            }
        }
    }
    return skup_rijeci;
}

IndeksPojmova KreirajIndeksPojmova(Knjiga k)
{
    std::set<std::string> skup_rijeci_iz_knjige(VratiRijeci(k));
    IndeksPojmova indeks_pojmova;

    for(auto s:skup_rijeci_iz_knjige) {
        std::set<std::tuple<std::string, int, int>> skup_trojki;

        for(auto it=k.begin(); it!=k.end(); it++) { //prolazim kroz knjigu
            for(int i=0; i!=it->second.size(); i++) { //prolazim kroz vektor stringova jednog poglavlja
                std::string recenica(PretvoriUMala(it->second[i])); //ita recenica u vektoru
                std::vector<int> v(VratiPoziciju(recenica, s)); //vrati vektor pozicija rijeci s u itoj recenici
                if(v.size()==0) continue;//ako je velicina vektora 0 znaci nema pronadjene rijeci u itoj recenici ide na narednu recenicu
                for(int j=0; j!=v.size(); j++) { //suprotno ide kroz vraceni vektor
                    auto trojka=std::make_tuple(it->first, i+1, v[j]);//pravim trojku it->first je poglavlje, i+1 je br stranice, v[j] je pozicija
                    skup_trojki.insert(trojka);//ubacujem trojku u skup
                }
            }
        }
        indeks_pojmova.insert(std::make_pair(s, skup_trojki)); //ubacujem par (rijec, skup_trojki);

    }
    return indeks_pojmova;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string s, IndeksPojmova mapa)
{
    if(!mapa.count(PretvoriUMala(s))) throw std::logic_error("Unesena rijec nije nadjena!");
    else return mapa[PretvoriUMala(s)];
}

void IspisiIndeksPojmova(IndeksPojmova indeks_pojmova)
{
    for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
        std::cout<<it->first<<": ";
        for(auto x=it->second.begin(); x!=it->second.end(); x++) {
            std::cout<< std::get<0>(*x) << "/" << std::get<1>(*x) << "/" << std::get<2>(*x);
            if(x!=(--it->second.end())) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
}

void IspisiZaJednuRijec (std::set<std::tuple<std::string, int, int>> skup_t)
{
    for (auto it=skup_t.begin(); it!=skup_t.end(); it++) {
        std::cout<< std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it)<<" ";
    }
    std::cout<<std::endl;

}

int main ()
{
    Knjiga k;
    std::string s;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, s);
        if(s==".") break;
        std::vector<std::string> v;
        int i(1);
        std::string recenica;
        for(;;) {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin, recenica);
            if(recenica==".") break;
            v.push_back(recenica);
            i++;
        }
        k.insert(std::make_pair(s, v));
    }

    IndeksPojmova in(KreirajIndeksPojmova(k));
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(in);

    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if (rijec==".") break;
        try {
            IspisiZaJednuRijec(PretraziIndeksPojmova(rijec, in));

        } catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }

    }


    return 0;
}
