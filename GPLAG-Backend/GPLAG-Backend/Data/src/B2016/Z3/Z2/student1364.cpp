/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

std::string PretvoriUMala (const std::string &s) {
    std::string t(s);
    for (int i=0; i<t.size(); i++) {
        if (t[i]>='A' && t[i]<='Z') t[i]+='a'-'A';
    }
    return t;
}

std::vector<std::string> PronadjiRijeci (const std::string &tekst) {
    //Pretvorimo sva velika u mala slova
    auto t(PretvoriUMala(tekst));
    std::vector<std::string> vektor_rijeci;
    bool neispravan_znak (true);
    for (int i=0; i<t.size(); i++) {
        if (!((t[i]>='a' && t[i]<='z') || (t[i]>='0' && t[i]<='9'))) neispravan_znak=true;
        else if (neispravan_znak) {
            neispravan_znak=false;
            std::string rijec;
            while ((t[i]>='a' && t[i]<='z') || (t[i]>='0' && t[i]<='9')) {
                rijec.push_back(t[i]);
                i++;
            }
            //Provjerimo da li se rijec vec nalazi u vektoru
            int j(0);
            for (j=0; j<vektor_rijeci.size(); j++) {
                if (vektor_rijeci[j]==rijec) break; //Poredimo dva stringa
            }
            if (j==vektor_rijeci.size()) vektor_rijeci.push_back(rijec); //Nije doslo do prekida petlje, nova rijec
            i--;
        }
    }
    //Sortirajmo vektor_rijeci po abecedi
    std::sort(vektor_rijeci.begin(), vektor_rijeci.end());
    return vektor_rijeci;
}

std::set<int> PopuniSkupIndeksima (const std::string &tekst_za_analizu, const std::string &rijec_tekst) {
    std::set<int> rez;
    std::string tekst(PretvoriUMala(tekst_za_analizu));
    bool neispravan_znak (true);
    for (int j=0; j<tekst.size(); j++) {
        if (!((tekst[j]>='a' && tekst[j]<='z') || (tekst[j]>='0' && tekst[j]<='9'))) neispravan_znak=true;
        else if (neispravan_znak) {
        neispravan_znak=false;
        std::string rijec; 
        int poc(j);
        while ((tekst[j]>='a' && tekst[j]<='z') || (tekst[j]>='0' && tekst[j]<='9')) {
            rijec.push_back(tekst[j]);
            j++;
        }
        if (rijec==rijec_tekst) {
            rez.insert(poc);
        }
        j--;
        }
    }
    return rez;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst_za_analizu) {
    std::map<std::string, std::set<int>> m_rezultat;
    //Ne pravimo razliku izmedju velikih i malih slova, u mapi rijeci samo sa malim slovima
    //rijeci od slova i cifara
    auto vektor_rijeci(PronadjiRijeci(tekst_za_analizu));
    std::vector<std::set<int>> vektor_skupova;
    for (int i=0; i<vektor_rijeci.size(); i++) {
        //Prolazimo kroz vektor rijeci, pravimo vektor skupova
        vektor_skupova.push_back(PopuniSkupIndeksima(tekst_za_analizu, vektor_rijeci[i]));
    }
    //Popunimo mapu
    for (int i=0; i<vektor_rijeci.size(); i++) {
        m_rezultat.insert(std::make_pair(vektor_rijeci[i], vektor_skupova[i]));
    }
    return m_rezultat;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    for (auto it=mapa.begin(); it != mapa.end(); it++) {
        if (it->first==rijec) return it->second;
    }
    throw std::logic_error ("Pojam nije nadjen");
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for (auto it=mapa.begin(); it != mapa.end(); it++) {
        cout << it->first << ": ";
        int i(0);
        for (int x: it->second) {
            if (i!=(it->second).size()-1) cout << x << ",";
            else cout << x;
            i++;
        }
        cout << endl;
    }
}

int main ()
{
    cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(cin, tekst);
    std::vector<std::string> vektor_rijeci;
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    std::string unos;
    for (;;) {
        cout << "Unesite rijec: ";
        std::getline(cin, unos);
        if (unos==".") return 0;
        try {
            auto s=PretraziIndeksPojmova(unos, KreirajIndeksPojmova(tekst));
            for (int x: s) cout << x << " ";
            cout << endl;
        }
        catch(std::logic_error) {
            cout << "Unesena rijec nije nadjena!" << endl;
        }
    }
	return 0;
}