/B2016/2017: Zadaća 3, Zadatak 5

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include <set>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

Dijete* napravilistu(std::vector<std::string> v){
    Dijete *temp=nullptr;
    Dijete *prvi=nullptr;
    std::vector<Dijete*> q;
    try{
    for(int i(0);i<v.size();i++){
        Dijete* p=new Dijete;
        q.push_back(p);
        p->ime=v[i];
        if(prvi==nullptr) prvi=p;
        if(temp!=nullptr) temp->sljedeci=p;
        temp=p;
        p->sljedeci=temp;
        if(i==v.size()-1) p->sljedeci=prvi;
        
    }
    }
    catch(std::bad_alloc){
        for(int i(0);i<q.size();i++) delete q[i];
        throw;
    }
    return prvi;
    
}

void unisti(Dijete *pok){
    Dijete *pamti=pok;
    if(pok==nullptr) return;
    do{
        auto temp=pok;
        delete pok;
        pok=temp;
        pok=pok->sljedeci;
        
    }while(pok!=pamti);
}

std::vector<int> brojclanovautimu(int n, int k){ // k broj timova, n broj ljudi
    std::vector<int> v;
    int o=n%k;
    for(int i(0);i<o;i++){
        v.push_back(int(n/k)+1);
    }
    o=k-o;
    for(int i(0);i<o;i++){
        v.push_back(int(n/k));
    }
    return v;
}

bool dalijeslovo(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
    return false;
}

bool dalijebroj(char c){
    return c>='0' && c<='9';
}

int brojslovaimena(std::string s){
    int br(0);
    for(int i(0);i<s.size();i++){
        if(!(dalijebroj(s[i])) && !(dalijeslovo(s[i]))) br++;
    }
    return s.size()-br;
}

Dijete* dajprethodnika(Dijete *p){
    auto temp=p;
    while(temp->sljedeci!=p){
        temp=temp->sljedeci;
    }
    return temp;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vs, int k){ //k je broj timova
if(k<1 || k>vs.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete* p;
    int brojclanova=vs.size();
    std::vector<int> v(brojclanovautimu(brojclanova,k)); // v[0] brojclanova 1. tima, v[1] drugog...
    std::vector<std::set<std::string>> w(k); //ovo vracam, push_back(w[j]);
    int j(0);
    p=napravilistu(vs);
    int s;
    auto it=p;
    int x(0);
    while(it!=nullptr){
        s=brojslovaimena(it->ime);
        w[j].insert(it->ime);
        auto temp=it->sljedeci;
        auto t(dajprethodnika(it));
        delete it;
        if(t==it) it=nullptr;
        else {
            it=temp;
            t->sljedeci=temp;
        }
        if(it==nullptr) break;
        x++;
        if(x==v[j]){
            x=0;
            j++;
        }
        for(int i(0);i<s-1;i++){
            it=it->sljedeci;
        }
        
    }
    
    
    return w;
    
}


int main ()
{
    std::cout << "Unesite broj djece: ";
    int a;
    std::cin >> a;
    std::vector<std::string> v ;
    std::string s;
    std::cout << "Unesite imena djece:" << std::endl;
    std::cin.ignore(10000,'\n');
    for(int i(0);i<a;i++){
        std::getline(std::cin,s);
        v.push_back(s);
    }
    
    std::cout << "Unesite broj timova: ";
    int n;
    std::cin>> n;
    try{
    auto vs=Razvrstavanje(v,n);
    for(int i(0);i<vs.size();i++){
        std::cout << "Tim "<<i+1<<": ";
        bool prvi=true;
        for(auto j:vs[i]){
            if(prvi) prvi=false;
            else std::cout << ", ";
            std::cout << j ;
    }
    std::cout <<  std::endl;
    }
    }
    catch(std::logic_error izuzetak){
        std::cout <<"Izuzetak: "<< izuzetak.what();
    }
    catch(std::bad_alloc){
        return 0;
    }
	return 0;
}