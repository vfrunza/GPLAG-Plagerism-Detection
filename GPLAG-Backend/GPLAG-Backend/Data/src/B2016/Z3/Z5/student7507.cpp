/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};
int Korak(std::string s){
    int br=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ' || s[i]=='-')continue;
        br++;
    }
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int timovi){
    if(timovi<0 ||timovi > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n=v.size();
    
    std::vector<std::set<std::string>> v1(timovi);
    Dijete *pocetak(nullptr), *prethodni;
    for(int i=0; i<v.size(); i++){
        Dijete *novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    int br_po_timu, prvi, prvi_po_timu, br_djece=v.size(), br_koraka;
    auto temp=pocetak;
        if(n%timovi==0){
            br_po_timu=n/timovi;
            int k=0;
            while(br_djece!=0){
                std::set<std::string> skup;
                for(int i=0; i<br_po_timu; i++){
                    skup.insert(pocetak->ime);
                    //std::cout<<"prvi= "<<prethodni->ime<<std::endl;
                    br_djece--;
                    if(br_djece==0) { delete pocetak ; break;}
                    br_koraka=Korak(pocetak->ime);
                    //std::cout<<"br= "<<br_koraka<<std::endl;
                    temp=pocetak->sljedeci;
                    delete pocetak;
                    pocetak=temp;
                    prethodni->sljedeci=pocetak;
                    //std::cout<<"novi= "<<prethodni->ime<<std::endl;
                    
                    if(br_djece==1 && i+1<br_po_timu){
                        skup.insert(pocetak->ime);
                        delete pocetak;
                        br_djece--;
                        break;
                    }
                    for(int j=1; j<br_koraka; j++){
                        prethodni=pocetak;
                        pocetak=pocetak->sljedeci;
                    }
                }
                v1[k]=skup;
                k++;
            }
        }
        else {
            prvi=n%timovi;
            prvi_po_timu=n/timovi +1;
            int ostali=n/timovi;
            int k=0;
            while(br_djece!=0){
                std::set<std::string> skup1;
                if(k<prvi){
                    for(int i=0; i<prvi_po_timu; i++){
                        skup1.insert(pocetak->ime);
                        //std::cout<<"prvi= "<<pocetak->ime<<std::endl;
                        br_djece--;
                        if(br_djece==0){delete pocetak; break; }
                        br_koraka=Korak(pocetak->ime);
                        temp=pocetak->sljedeci;
                        delete pocetak;
                        pocetak=temp;
                        prethodni->sljedeci=pocetak;
                        //std::cout<<"novi= "<<pocetak->ime<<std::endl;
                        for(int j=1; j<br_koraka; j++){
                            prethodni=pocetak;
                            pocetak=pocetak->sljedeci;
                        }
                        //std::cout<<"Poslije for: "<<pocetak->ime<<std::endl;
                    }
                    v1[k]=skup1;
                }
                else {
                    std::set<std::string> skup2;
                    for(int i=0; i<ostali; i++){
                        skup2.insert(pocetak->ime);
                        //std::cout<<"prvi poslije : "<<pocetak->ime<<std::endl;
                        br_djece--;
                        if(br_djece==0) { delete pocetak; break;}
                        br_koraka=Korak(pocetak->ime);
                        temp=pocetak->sljedeci;
                        delete pocetak;
                        pocetak=temp;
                        prethodni->sljedeci=pocetak;
                        //std::cout<<"novi poslije = "<<pocetak->ime<<std::endl;
                        if(br_djece==1 && i+1<ostali){
                            skup2.insert(pocetak->ime);
                            br_djece--;
                            delete pocetak;
                            break;
                            
                        }
                        for(int j=1; j<br_koraka; j++){
                            prethodni=pocetak;
                            pocetak=pocetak->sljedeci;
                        }
                        //std::cout<<"For poslije= "<<pocetak->ime<<std::endl;
                    }
                    v1[k]=skup2;
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
        std::cin.ignore(10000, '\n');
        std::vector<std::string> v(n);
        for(int i=0; i<n; i++){
            std::getline(std::cin,v[i]);
        }
        std::cout<<"Unesite broj timova: ";
        int k=0;
        std::cin>>k;
        std::vector<std::set<std::string>> novi=Razvrstavanje(v,k);
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