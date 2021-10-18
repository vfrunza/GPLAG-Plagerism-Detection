#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

int BrojSlovBr(std::string s){
    int brojac(0);
    for(auto x : s)
        if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')) brojac++;
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int k){
    if(k<1 || k>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vrati(k);
    std::vector<int> velicine(k);
    
    int nk=imena.size()%k;
    for(int i=0; i<k; i++)
        if(nk){
            velicine[i]=int(imena.size()/k)+1; nk--;
        }else{
            velicine[i]=int(imena.size()/k);
        }
    
    Dijete* pocetak(nullptr), *preth(nullptr);
    for(int i=0; i<imena.size(); i++){
        Dijete* novi=new Dijete;
        novi->ime=imena[i];
        if(!i){pocetak=novi; novi->sljedeci=nullptr;}
        else preth->sljedeci=novi;
        preth=novi;
        if(i==imena.size()-1) novi->sljedeci=pocetak;
    }
    
    int pomjeri_za(0);
    Dijete* izbrisi(nullptr);
    if(pocetak){
        pomjeri_za=BrojSlovBr(pocetak->ime); vrati[0].insert(pocetak->ime);
        preth->sljedeci=pocetak->sljedeci;
        izbrisi=pocetak;
        pocetak=pocetak->sljedeci;
        delete izbrisi;
    }
    
    for(int i=0; i<k; i++){ //grupe djece
        while(vrati[i].size()!=velicine[i]){
            for(int j=0; j<pomjeri_za-1; j++){
                pocetak=pocetak->sljedeci;
                preth=preth->sljedeci;
            }
            pomjeri_za=BrojSlovBr(pocetak->ime);
            izbrisi=pocetak;
            pocetak=pocetak->sljedeci;
            preth->sljedeci=pocetak;
            vrati[i].insert(izbrisi->ime);
            delete izbrisi;
        }
    }
    return vrati;
    
}

int main (){
    /*main() i BrojSlovBr() sam kopirao iz prethodnog zadatka, kao i odredjivanje velicine pojedinih
    grupa djece.*/
    std::cout<<"Unesite broj djece: ";
    int n; std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::vector<std::string> imena(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++)
        std::getline(std::cin, imena[i]);
    std::cout<<"Unesite broj timova: ";
    int k; std::cin>>k;
    std::vector<std::set<std::string>> razvrst;
    try{
        razvrst=Razvrstavanje(imena, k);
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    int i(0);
    for(auto x : razvrst){
        std::cout<<"Tim "<<++i<<": ";
        int b(1);
        for(auto y : x){
            if(b==razvrst[i-1].size())
                std::cout<<y;
            else std::cout<<y<<", ";
            b++;
        }
        std::cout<<std::endl;
    }
	return 0;
}