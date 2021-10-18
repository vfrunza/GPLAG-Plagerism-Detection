#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::set;

bool SlovoCifra(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;    
}

int DajBrojSlova(string s) {
    int ukupno(0);
    
    for(auto it = s.begin(); it != s.end(); it++) {
        if(SlovoCifra(*it))
            ukupno++;
    }
    
    return ukupno;
}

std::vector<std::set<string>> Razvrstavanje(std::vector<string> vs, int k) {
    
    int n;
    n = vs.size();
    
    if(k<1 || k>n)
        throw std::logic_error("Razvrstavanje nemoguce");
        
    std::list<string> lista_imena;
    
    for (int i = 0; i < n; i++) {
        lista_imena.push_back(vs[i]);
    }
    
    std::vector<std::set<string>> vss(k);
    
    int br_clanova;
    int br_djece = n;
    int br_skupova = k;
    int potezi;
    bool ulaz(true);
    auto it(lista_imena.begin());
    
    for (int i = 0; i < k; i++) {
         
        if(br_djece % br_skupova == 0)
            br_clanova = br_djece/br_skupova;
        else
            br_clanova = br_djece/br_skupova + 1;
        for (int j = 0; j < br_clanova; j++) {
            if(ulaz) {
                ulaz = false;
                vss[i].insert(*it);
                potezi = DajBrojSlova(*it);
                it = lista_imena.erase(it);
                if(it == lista_imena.end())
                    it = lista_imena.begin();
                continue;    
            }
            for(int m = 1; m < potezi; m++) {
                if(it == lista_imena.end())
                    it = lista_imena.begin();
                it++;
                if(it == lista_imena.end())
                    it = lista_imena.begin();
            }
            vss[i].insert(*it);
            potezi = DajBrojSlova(*it);
            it = lista_imena.erase(it);
            if(it == lista_imena.end())
                it = lista_imena.begin();
        }    
        br_djece -= br_clanova;
        br_skupova--;
    }
    return vss;
}

int main ()
{   
    int n;
    cout << "Unesite broj djece: ";
    cin >> n;
    cin.ignore(1000,'\n');
    
    std::vector<string> vs;
    string ime;
    cout << "Unesite imena djece:" << endl;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin,ime);
        vs.push_back(ime);
    }
    int k;
    cout << "Unesite broj timova: ";
    cin >> k;
    cin.ignore(1000,'\n');
    
    std::vector<std::set<string>> vss;
    try {
        vss=(Razvrstavanje(vs, k));
    }
    catch (std::logic_error err) {
        std::cout << "Izuzetak: " << err.what();
        return 0;
    }
    
    for (int i = 0; i < vss.size(); i++) {
        cout << "Tim " << i+1 << ": ";
        for (auto j = vss[i].begin(); j != vss[i].end(); j++) {
            if((++j) != vss[i].end())
                cout << *--j << ", ";
            else 
                cout << *--j;
        }   
        cout << endl;
    }
    
	return 0;
}