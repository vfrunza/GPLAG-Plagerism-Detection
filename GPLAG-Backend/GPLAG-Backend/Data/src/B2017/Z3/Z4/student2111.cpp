/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <stdexcept>

int duzina(std::string s){
    int br(0);
    for (int i=0;i<s.size();i++){
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            br++;
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vekt_imena, int k){
    int n(vekt_imena.size());
    if (k<1 || k>n) 
        throw (std::logic_error) "Razvrstavanje nemoguce";
    std::list<std::string> lista_imena;
    std::copy(vekt_imena.begin(),vekt_imena.end(),std::back_inserter(lista_imena));
    std::vector<int> pom;
    int br_clan;
    if (n%k==0) {
        br_clan=n/k;
        for (int i=0;i<k;i++)
            pom.push_back(br_clan);
    }
    else{
        int mod(n%k);
        br_clan=(n/k);
        for (int i=0;i<k;i++){
            if (i<mod)
                pom.push_back(br_clan+1);
            else
                pom.push_back(br_clan);
        }
    }
    std::vector<std::set<std::string>> povratniskup(k);
    std::list<std::string>::iterator it(lista_imena.begin());
    std::string prvoime(*it);
    povratniskup[0].insert(prvoime);
    int duzin=duzina(*it);
    pom[0]--;
    std::set<std::string> pom_skup;
    std::string pom_string;
    auto it2=it;
    it++;
    it=lista_imena.erase(it2);
    for (int i=0;i<pom.size();i++){
        for (int j=0;j<pom[i];j++){
            duzin--;
            while(true){
                it++;
                if(it == lista_imena.end()) it = lista_imena.begin();
                duzin--;
                if(duzin == 0) break;
            }
            duzin = duzina(*it);
            povratniskup[i].insert(*it);
            it = lista_imena.erase(it);
            if(it == lista_imena.end()) it = lista_imena.begin();
            }
    }
    return povratniskup;
    
}

int main ()
{
    try{
        std::cout << "Unesite broj djece: ";
        int br;
        std::cin >> br;
        std::cin.ignore(10000,'\n');
        std::vector<std::string> vekt;
        std::cout << "Unesite imena djece: ";
        for (int i=0;i<br;i++){
            std::string s;
            std::getline(std::cin,s);
            vekt.push_back(s);
        }
        std::cout << std::endl << "Unesite broj timova: ";
        int br_tim;
        std::cin >> br_tim;
        std::vector<std::set<std::string>> razvrst;
        razvrst=Razvrstavanje(vekt,br_tim);
        std::set<std::string>::iterator it;
       for (int i=0;i!=br_tim;i++){
            std::cout << "Tim " << i+1 << ": " ;
            for (it=razvrst[i].begin();it!=razvrst[i].end();it++)
                if (it==--(razvrst[i].end()))
                    std::cout << *it;
                else std::cout << *it << ", ";
            std::cout << std::endl;
        }

    }
    catch (std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
	return 0;
}