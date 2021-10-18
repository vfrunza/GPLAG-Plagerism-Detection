/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>

int Velicina_stringa(std::string s){
    int vel(0);
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '|| s[i]=='-'||s[i]=='/' || s[i]=='\\') continue;
        vel++;
    }
    return vel;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int k){
    int n(v.size());
    if(k<1 || k>n)  throw std::logic_error ("Izuzetak: Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> finalni(k);
    std::list<std::string> lista;
    for(int i=0; i<v.size(); i++){
        lista.push_back(v[i]);
    }
    
    int prvi_timovi(n%k);
    int br_clanova_prvih_timova(int(n/k)+1);
    int ostali_timovi (int (n/k));
    
    std::vector<int> vektor_velicina;
    for(int i=0; i<k; i++){
        if(i<prvi_timovi){
        vektor_velicina.push_back(br_clanova_prvih_timova);}
        else vektor_velicina.push_back(ostali_timovi);
    }
    
    
   std::vector<std::string> pom;
    auto it=lista.begin();
    
    for(int i=0; i<k; i++){
        for(int l=0; l<vektor_velicina[i];l++){
            
                if(lista.size()==0) break;
                
                int br(Velicina_stringa(*it));
                
                finalni[i].insert(*it);
                it=lista.erase(it);
                if(lista.size()==0) break;
                if(it==lista.end()) it=lista.begin();
                
                for(int j=0; j<br-1; j++){
                if(it==--lista.end()) it=lista.begin();
                else it++;}
                
                
        
    
    }}
        
        
        
      return finalni;  
    
   
    
}
int main ()
{
    try{
    int n;
    std::cout<<"Unesite broj djece: ";

    std::cin>>n;
    std::cin.ignore(1000,'\n');
    std::cout<< "Unesite imena djece: ";
    
    std::vector<std::string> v(n);
   
    for(int i=0; i<n; i++){
        
        std::getline(std::cin, v[i]);
    }
    
    std::cout<<std::endl<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    std::vector<std::set<std::string>> finalni(Razvrstavanje(v,k));
    for(int i=0; i<k; i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it=finalni[i].begin(); it!=finalni[i].end(); it++){
            if(it!=--finalni[i].end()){
            std::cout<<*it<<", ";}
            else std::cout<<*it;
        }
       
        std::cout<<std::endl;
    }}
    catch(std::logic_error e){
        std::cout<<e.what();
    }
    
    
	return 0;
}