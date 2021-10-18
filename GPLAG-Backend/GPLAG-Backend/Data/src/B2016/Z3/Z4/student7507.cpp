/B2016/2017: Zadaća 3, Zadatak 4
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
        br_po_timu=n/timovi; // Jednak broj djece po timovima i to je br_po_timu
        int k=0;
        while(br_djece!=0){
            std::set<std::string> skup;
            for(int i=0; i<br_po_timu; i++){
                //std::cout<<"Prvi="<<*it<<std::endl;
                skup.insert(*it);
                br_djece--;
                if(br_djece==0) break;
                br_koraka=Korak(*it);
                
                if(++it2==lista.end()) {
                    it1=it;
                    it=lista.begin();
                    it3=it;
                    //std::cout<<"Prije brisanja: "<<*it<<std::endl;
                    it1=lista.erase(it1);
                }
                else it=lista.erase(it);
                //std::cout<<"novi="<<*it<<std::endl;
                
                if(br_djece==1 && i+1<br_po_timu){
                    skup.insert(*it); 
                    br_djece--;
                    break; 
                } 
                for(int j=1;j<br_koraka; j++){
                    it3=it;
                    if(++it3==lista.end()){ it=lista.begin(); /*std::cout<<"pocetak= "<<*it<<std::endl;*/}
                    else it++;
                    
                }
                it2=it;
                if(it==lista.end()) it--;
                //std::cout<<"Poslije for= "<<*it<<std::endl;
            }
            v1[k]=skup;
            //std::cout<<"upisan"<<std::endl;
            k++;
        }
    }
    else {
        prvi= n%timovi; // Prvih (n%k) timova koji ce imati vise djece
        prvi_po_timu= n/timovi +1; // Broj djece u tim timovima koji imaju vise djece od ostalih
        int ostali=n/timovi;
        int k=0;
        while(br_djece!=0){
            std::set<std::string> skup;
            if(k<prvi){
                for(int i=0; i<prvi_po_timu; i++){
                    skup.insert(*it);
                   // std::cout<<"Prvi= "<<*it<<std::endl;
                    br_koraka=Korak(*it);
                    //std::cout<<"br= "<<br_koraka<<std::endl;
                    if(++it2==lista.end()){
                        it1=it;
                        it=lista.begin();
                        it3=it;
                        it1=lista.erase(it1);
                    }
                    else it=lista.erase(it);
                    //std::cout<<"Novi= "<<*it<<std::endl;
                    br_djece--;
                   
                    int br=0;
                    for(int j=1; j<br_koraka; j++){
                        //std::cout<<" j= "<<j;
                        it3=it;
                        if(++it3==lista.end()) { it=lista.begin(); /*std::cout<<"Pocetak "<<j<<" "<<*it<<std::endl;*/}
                        else it++;
                        br++;
                        
                    }
                    it2=it;
                    if(it==lista.end()){ it--;}
                    //std::cout<<"Poslije for: "<<*it<<std::endl;
                }
                v1[k]=skup;
            }
            else {
                //it2++;
                std::set<std::string> skup1;
                for(int i=0; i<ostali; i++){
                    skup1.insert(*it);
                    br_djece--;
                    if(br_djece==0) break;
                   // std::cout<<"Prvi Poslije prvih: "<<*it<<std::endl;
                    br_koraka=Korak(*it);
                    //std::cout<<"br: "<<br_koraka<<std::endl;
                    if(++it2==lista.end() && br_djece!=1){
                        it1=it;
                        it=lista.begin();
                        it3=it;
                        //std::cout<<"Prije brisanja: "<<*it<<std::endl;
                        it1=lista.erase(it1);
                    }
                    else{ it=lista.erase(it); }
                    //std::cout<<"Novi poslije prvih: "<<*it<<std::endl;
                    if(br_djece==1 && i+1<ostali){
                        skup1.insert(*it);  
                        br_djece--;
                        break;
                    }
                    for(int j=1; j<br_koraka; j++){
                        it3=it;
                        if(++it3==lista.end()){ it=lista.begin(); /*std::cout<<"j "<<j<<" "<<*it<<std::endl;*/}
                        else it++;
                    }
                    it2=it;
                    if(it==lista.end()) it--;
                    //std::cout<<"For poslije: "<<*it<<std::endl;
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
    try{
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
            int vel=novi[i].size();
            
            for(auto it=novi[i].begin(); it!=novi[i].end(); it++){
                std::cout<<*it;
                if(vel>1) std::cout<<", ";
                vel--;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}