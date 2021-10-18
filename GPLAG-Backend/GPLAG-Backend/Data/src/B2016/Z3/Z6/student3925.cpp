/B2016/2017: Zadaća 3, Zadatak 5

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <set>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::shared_ptr<Dijete> napravilistu(std::vector<std::string> v){
    std::shared_ptr<Dijete> temp;
    std::shared_ptr<Dijete> prvi;
    std::vector<std::shared_ptr<Dijete>> q;
    try{
    for(int i(0);i<v.size();i++){
        std::shared_ptr<Dijete> p=std::make_shared<Dijete>();
        q.push_back(p);
        p->ime=v[i];
        if(!prvi) prvi=p;
        if(temp) temp->sljedeci=p;
        temp=p;
        p->sljedeci=temp;
        if(i==v.size()-1) p->sljedeci=prvi;
        
    }
    }
    catch(std::bad_alloc){
        for(int i(0);i<q.size();i++){
            q[i]->sljedeci=nullptr;
            q[i]=nullptr;
        }
        throw;
    }
    return prvi;
    
}
/*
void unisti(Dijete *pok){
    std::shared_ptr<Dijete> pamti=pok;
    if(pok==nullptr) return;
    do{
        auto temp=pok;
        delete pok;
        pok=temp;
        pok=pok->sljedeci;
        
    }while(pok!=pamti);
}
*/
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

std::shared_ptr<Dijete> dajprethodnika(std::shared_ptr<Dijete> p){
    auto temp=p;
    while(temp->sljedeci.get()!=p.get()){
        temp=temp->sljedeci;
    }
    return temp;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vs, int k){ //k je broj timova
if(k<1 || k>vs.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> p;
    int brojclanova=vs.size();
    std::vector<int> v(brojclanovautimu(brojclanova,k)); // v[0] brojclanova 1. tima, v[1] drugog...
    std::vector<std::set<std::string>> w(k); //ovo vracam, push_back(w[j]);
    int j(0);
    p=napravilistu(vs);
    int s;
    auto it=p;
    int x(0);
    while(it){
        s=brojslovaimena(it->ime);
        w[j].insert(it->ime);
        auto temp=it->sljedeci;
        auto t(dajprethodnika(it));
        if(t->sljedeci==t) {
            it->sljedeci = nullptr;
            it = nullptr;
            
        }
        else {
            it=temp;
            t->sljedeci=temp;
        }
        if(!it) break;
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
        std::cout << "Izuzetak: "<< izuzetak.what();
    }
    catch(std::bad_alloc){
        return 0;
    }
	return 0;
}