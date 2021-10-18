#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>

int Korak(std::string s){
    int br=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ' || s[i]=='-' ) continue;
        br++;
    }
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int timovi){
    if(timovi>v.size() ||timovi <1) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> v1(timovi);
    int n=v.size();
    std::list<std::string> lista;
    for(int i=0; i<v.size(); i++){
        lista.push_back(v[i]);
    }
    std::list<std::string>::iterator it(lista.begin()), it2(lista.begin()), it1(lista.begin()), it3(lista.begin());
    int br_po_timu, prvi, prvi_po_timu, br_djece=v.size(), br_koraka;
    if(n%timovi==0){
        br_po_timu=n/timovi; 
        int k=0;
        while(br_djece!=0){
            std::set<std::string> skup;
            for(int i=0; i<br_po_timu; i++){
                skup.insert(*it);
                br_koraka=Korak(*it);
                if(++it2==lista.end()) {
                    it1=it;
                    it=lista.begin();
                    it3=it;
                    it1=lista.erase(it1);
                }
                else it=lista.erase(it);
           br_djece--;
                if(br_djece==1 && i<br_po_timu){
                    skup.insert(*it); 
                    br_djece--;
                    break; 
                } 
                for(int j=1;j<br_koraka; j++){
                    it3=it;
                    if(++it3==lista.end()){ it=lista.begin();}
                    else it++;
                    
                }
                it2=it;
                if(it==lista.end()) it--;
                
            }
            v1[k]=skup;
           k++;
        }
    }
    else {
        prvi= n%timovi; 
        prvi_po_timu= n/timovi +1; 
        int ostali=n/timovi;
        int k=0;
        while(br_djece!=0){
            std::set<std::string> skup;
            if(k<prvi){
                for(int i=0; i<prvi_po_timu; i++){
                    skup.insert(*it);
                    //std::cout<<"Prvi= "<<*it<<std::endl;
                    br_koraka=Korak(*it);
                    if(++it2==lista.end()){
                        it1=it;
                        it=lista.begin();
                        it3=it;
                        it1=lista.erase(it1);
                    }
                    else it=lista.erase(it);
                  
                    br_djece--;
                    for(int j=1; j<br_koraka; j++){
                       
                        it3=it;
                        if(++it3==lista.end()) { it=lista.begin(); }
                        else it++;
                        
                    }
                    it2=it;
                    if(it==lista.end()){ it--;}
                    
                }
                v1[k]=skup;
            }
            else {
                it2++;
                std::set<std::string> skup1;
                for(int i=0; i<ostali; i++){
                    skup1.insert(*it);
                    
                    br_koraka=Korak(*it);
                    if(++it2==lista.end()){
                        it1=it;
                        it=lista.begin();
                        it3=it;
                        
                        it1=lista.erase(it1);
                    }
                    else{ it=lista.erase(it); }
                   
                    br_djece--;
                    if(br_djece==1 && i<ostali){
                        skup1.insert(*it);
                        br_djece--;
                        break;
                    }
                    for(int j=1; j<br_koraka; j++){
                       
                        if(++it3==lista.end()){ it=lista.begin(); }
                        else it++;
                        it3=it;
                    }
                    it2=it;
                    if(it==lista.end()) it--;
                   
                }
                v1[k]=skup1;
            }
            k++;
        }
    }
    return v1;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: \n";
    std::cin.ignore(10000,'\n');
    std::vector<std::string> v(n);
    for(int i=0; i<n; i++){
        std::getline(std::cin,v[i]);
    }
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    std::vector<std::set<std::string>> novi(Razvrstavanje(v,k));
    for(int i=0; i<k; i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto it2=novi[i].end();
        it2--;
        for(auto it=novi[i].begin(); it!=novi[i].end(); it++){
            std::cout<<*it;
            if(it!=it2) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
	return 0;
}