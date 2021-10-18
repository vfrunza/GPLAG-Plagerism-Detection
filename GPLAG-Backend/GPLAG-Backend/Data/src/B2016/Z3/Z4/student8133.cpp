/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <iterator>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

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
    if(br==0) br++;
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> lista;
    std::set<std::string> skup;
    std::vector<std::set<std::string>> pov;
    
    int d(v.size()%n);
    int broj_cl(v.size()/n);
    int broj_cl1((v.size()/n)+1);
    for(int i=0;i<v.size();i++){
        lista.push_back(v[i]);
    }
    auto it1(lista.begin());
    int b(0), b1(0), el(0);
    for(;;){
        
        for(int i=0;i<lista.size();i++){
        skup.insert(*it1);
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
        int br(Prebroj(*it1)-1);
        it1=lista.erase(it1);
        if(it1==lista .end()) it1=lista.begin();
        if(lista.size()==0) break;
        for(int i=0;i<br;i++){
            it1++;
            if(it1==lista.end()) it1=lista.begin();
        }
        
        }
        if((b+b1)==n && lista.size()==0) break;
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
        auto vek(Razvrstavanje(v,broj));
        for(int i=0;i<vek.size();i++){
            auto it1(vek[i].end());
            it1--;
            cout<<"Tim "<<i+1<<": ";
            for(auto it=vek[i].begin(); it!=vek[i].end();it++){
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
	return 0;
}