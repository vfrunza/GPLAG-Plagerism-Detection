/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <cctype>
#include <vector>
using std::vector;
using std::make_pair;
using std::string;
using std::map;
using std::set;

map<string, set<int>> KreirajIndeksPojmova (string s) {
    map<string, set<int>> mapa;
    for (int i=0; i<s.length(); i++) {
        if ((i==0 && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) || (((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && !((s[i-1]>='A' && s[i-1]<='Z') || (s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='0' && s[i-1]<='9')))) {
            int pozicija(i);
            string rijec;
            while (i<s.length() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) {
                rijec+=s[i];
                i++;
            }
            bool postoji(false);
            map<string, set<int>>::iterator iter;
            for (auto it=mapa.begin(); it!=mapa.end(); it++) {
                iter=it;
                string pom_rijec(rijec);
                for (int j=0; j<pom_rijec.length(); j++)
                    pom_rijec[j]=std::toupper(pom_rijec[j]);
                string m_rijec(it->first);
                for (int j=0; j<m_rijec.length(); j++)
                    m_rijec[j]=std::toupper(m_rijec[j]);
                if (pom_rijec==m_rijec) {
                    postoji=true;
                    break;
                }
            }
            set<int> skup;
            if (!postoji) {
                skup.insert(pozicija);
                for (int i=0; i<rijec.length(); i++) {
                    if (rijec[i]>='A' && rijec[i]<='Z')
                        rijec[i]+='a'-'A';
                }
                mapa.insert(make_pair(rijec, skup));
            }
            else {
                iter->second.insert(pozicija);
            }
        }
    }
    return mapa;
}

set<int> PretraziIndeksPojmova (string rijec, map<string, set<int>> mapa) {
    set<int> skup;
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        string pom_rijec(rijec);
        for (int i=0; i<pom_rijec.length(); i++)
            pom_rijec[i]=std::toupper(pom_rijec[i]);
        string m_rijec(it->first);
        for (int i=0; i<m_rijec.length(); i++)
            m_rijec[i]=std::toupper(m_rijec[i]);
        if (pom_rijec==m_rijec)
            return it->second;
    }
    throw std::logic_error ("Pojam nije nadjen");
}

void IspisiIndeksPojmova (const map<string, set<int>> &mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        vector<int> v;
        std::cout << it->first << ": ";
        for (auto it2=it->second.begin(); it2!=it->second.end(); it2++) {
            v.push_back(*it2);
        }
        for (int i=0; i<v.size(); i++) {
            if (i!=v.size()-1)
                std::cout << v[i] << ",";
            else 
                std::cout << v[i];
        }
        std::cout << std::endl;
    }
}

int main ()
{
    string s;
    std::cout << "Unesite tekst: ";
    std::getline (std::cin, s);
    map<string, set<int>> mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    for (;;) {
        try {
            string rijec;
            std::cout << "Unesite rijec: ";
            std::getline (std::cin, rijec);
            if (rijec==".")
                break;
            set<int> skup(PretraziIndeksPojmova(rijec, mapa));
            for (int x : skup)
                std::cout << x << " ";
            std::cout << std::endl;
        }
        catch (...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}