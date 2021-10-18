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

struct Dijete {
    string ime;
    Dijete *sljedeci;
};

void UnistiListu (Dijete *pocetak) {
     
    auto p=pocetak;
    auto q=pocetak;
     
    while (p != nullptr) {
        p = p -> sljedeci;
        delete q;
        q = p;
    }
}
 
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
    
    int n(vs.size());
    
    if(k<1 || k>n)
        throw std::logic_error("Razvrstavanje nemoguce");
    
    Dijete *pocetak=nullptr, *prethodni=nullptr, *novi=nullptr;
    
    for (int i = 0; i < n; i++) {
        try {
            novi = new Dijete;
        }
        catch (std::bad_alloc) {
            UnistiListu(pocetak);
            throw;
        }
        novi -> ime = vs[i];
        novi -> sljedeci = nullptr;
        if(!pocetak)
            pocetak = novi;
        else
            prethodni -> sljedeci = novi;
        prethodni = novi;    
    }
    prethodni -> sljedeci = pocetak;
        
    std::vector<std::set<string>> vss(k);
    
    int br_clanova, br_djece(n), br_skupova(k), potezi;
    bool ulaz(true);
    auto it = pocetak;
    auto p_it = prethodni;
    
    for (int i = 0; i < k; i++) {
        if(br_djece % br_skupova == 0)
            br_clanova = br_djece/br_skupova;
        else
            br_clanova = br_djece/br_skupova + 1;
        for (int j = 0; j < br_clanova; j++) {
            if(ulaz) {
                ulaz = false;
                vss[i].insert(it -> ime);
                potezi = DajBrojSlova(it -> ime);
                p_it -> sljedeci = it -> sljedeci;
                delete it;
                it = p_it -> sljedeci;
                continue;
            }
            for(int m = 1; m < potezi; m++) {
                p_it = it;
                it = it -> sljedeci;
            }
            if(p_it == it) {
                vss[i].insert(it -> ime);
                delete it;
                break;
            }
            vss[i].insert(it -> ime);
            potezi = DajBrojSlova(it -> ime);
            p_it -> sljedeci = it -> sljedeci;
            delete it;
            it = p_it -> sljedeci;
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
    catch (std::bad_alloc) {
        return 0;
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