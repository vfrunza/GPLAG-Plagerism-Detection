/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <new>

using std::cin;
using std::cout;
using std::endl;

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

bool SlovoCifra(char x){
    bool d(false);
    if((x>='a' && x<='z') || (x>='0' && x<='9') || (x>='A' && x<='Z')) d=true;
    return d;
}
int Prebroj(std::string s){
    int br(0);
    for(int i=0;i<s.size();i++){
        if(SlovoCifra(s[i])) br++;
    }
    return br;
}

Dijete* Kreiraj(std::vector<std::string> v){
    int br(1);
    Dijete* prvi(nullptr);
    try{
        prvi=new Dijete;
        try{
            prvi->ime=v[0];
            prvi->sljedeci=nullptr;
            Dijete* prethodni(prvi);
            for(int i=1;i<v.size();i++){
                Dijete* novi(new Dijete);
                br++;
                novi->ime=v[i];
                novi->sljedeci=nullptr;
                if(!(prvi->sljedeci)) prvi->sljedeci=novi;
                if(i==v.size()-1) {
                    prethodni->sljedeci=novi;
                    novi->sljedeci=prvi;
                    prethodni=nullptr;
                    break;
                }
                else prethodni->sljedeci=novi;
                prethodni=novi;
            }
        }
        catch(std::bad_alloc){
            for(int i=0;i<br;i++){
                auto pom(prvi);
                if(i!=br-1){
                    prvi=prvi->sljedeci;
                    delete pom;
                }
                else {
                    prvi=nullptr;
                    delete pom;
                }
            }
        throw;
        }
    }
    catch(std::bad_alloc){
        throw;
    }
    return prvi;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    if(n<1  || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int d(v.size()%n);
    int broj_cl(v.size()/n);
    int broj_cl1((v.size()/n)+1);
    Dijete* lista;
    try{
        lista=Kreiraj(v);
    }
    catch(std::bad_alloc){
        throw;
    }
    std::set<std::string> skup;
    std::vector<std::set<std::string>> pov;
    auto pok(lista);
    Dijete* pom(nullptr);
    Dijete* prethodni(nullptr);
    Dijete* poslije(nullptr);
    int b(0), b1(0), el(0);
    for(;;){
        for(int i=0;i<v.size();i++){
            skup.insert(pok->ime);
            el++;
            if(el==broj_cl1){
                pov.push_back(skup);
                b++;
                skup.clear();
                el=0;
            }
            if(b==d){
                if(el==broj_cl){
                    pov.push_back(skup);
                    b1++;
                    skup.clear();
                    el=0;
                }
            }
            if(i!=v.size()-1){
                int br(Prebroj(pok->ime));
                poslije=pok;
                poslije=poslije->sljedeci;
                prethodni=pok;
                do{
                    prethodni=prethodni->sljedeci;
                    poslije=poslije->sljedeci;
                }while(poslije!=pok);
                poslije=poslije->sljedeci;
                prethodni->sljedeci=poslije;
                pok->sljedeci=nullptr;
                pom=poslije;
                auto brisanje(pok);
                pok=pom;
                delete brisanje;
                int k(1);
                do{
                    if(prethodni==poslije) break;
                    else pom=pom->sljedeci;
                    k++;
                }while(k<br);
                pok=pom;
            }
            if(i==v.size()-1){
                pok->sljedeci=nullptr;
                pom=nullptr;
                poslije=nullptr;
                prethodni=nullptr;
                delete pok;
            }
        }
        if((b+b1)==n) break;
    }
    return pov;
}

int main ()
{
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cin.ignore(100000, '\n');
    std::vector<std::string>v;
    cout<<"Unesite imena djece: "<<endl;
    for(int i=0;i<n;i++){
        std::string el;
        std::getline(cin, el);
        v.push_back(el);
    }
    cout<<"Unesite broj timova: ";
    int broj;
    cin>>broj;
    try{
        auto cvor(Razvrstavanje(v,broj));
        for(int i=0;i<cvor.size();i++){
            auto it1(cvor[i].end());
            it1--;
            cout<<"Tim "<<i+1<<": ";
            for(auto it=cvor[i].begin(); it!=cvor[i].end();it++){
                if(it!=it1) cout<<*it<<", ";
                else cout<<*it;
            }
        cout<<endl;
        }
    }
    catch(std::logic_error iz){
        cout<<"Izuzetak: "<<iz.what();
        return 0;
    }
    catch(...){
        return 0;
    }
	return 0;
}