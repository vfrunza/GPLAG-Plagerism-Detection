/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<string>
#include<set>
#include<vector>
#include<iterator>
#include<list>
std::vector<int> duzineskupa(int n,int k){
    std::vector<int> rez(k);
    int brskupova=n/k,viskadjece=n%k;
    for(int i=0; i<k; i++) {
        if(viskadjece>0) {
            rez[i]=brskupova+1;
            viskadjece--;
        } 
        else
            rez[i]=brskupova;
        
    }
    
    return rez;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vs,int k){
    std::list<std::string> lista;
    //popunili listu
    for(int i=0; i<vs.size(); i++)
        lista.push_back(vs[i]);
    std::list<std::string>::iterator it(lista.begin());
    std::vector<std::set<std::string>> rez;
    //rez.resize(k);
    //vektor s duzinom skupova
    std::vector<int> vskupova=duzineskupa(vs.size(),k);
    //ubacili prvog na spisku
    std::string prvi=vs[0];
    //duzina prvog
    int duzina=(*it).size()-1;
    //izbrisali prvog
    it=lista.erase(it);
    int n=vs.size()-1;
    int br=0;
    for(int i=0; i<k; i++) {
        std::set<std::string> skup;
        if(i==0){
            skup.insert(prvi);
        }
        for(int l=0; l<vskupova[i]; l++) {
            for(int j=0; j<duzina; j++) {
                if(it==lista.end())
                it=lista.begin();
                it++;
            }
            skup.insert(*it);
            duzina=(*it).size()-1;
            it=lista.erase(it);
          //  n--;
        }
        rez.push_back(skup);
    }
    return rez;

}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece:";
    std::vector<std::string> vs;
    std::cin.ignore(100000,'\n');
    for(int i=0; i<n; i++) {
        std::string pom;
        std::getline(std::cin,pom);
        vs.push_back(pom);
    }
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    auto rez=Razvrstavanje(vs,k);
    for(int i=0;i<rez.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto x: rez[i]) std::cout<<x<<" ";
        std::cout<<std::endl;
    }
    return 0;
}