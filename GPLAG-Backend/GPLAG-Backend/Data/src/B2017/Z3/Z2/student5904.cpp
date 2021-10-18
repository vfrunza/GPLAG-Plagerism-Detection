/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ctype.h>
std::string PretvoriUMalo(std::string s)
{
    for(int i=0; i<s.length(); i++) {
        s[i]=tolower(s[i]);
    }
    return s;
}
typedef std::tuple<std::string,int,int> Trojka;
typedef std::map<std::string,std::vector<std::string>>Knjiga;

std::map<std::string,std::set<Trojka>> KreirajIndeksPojmova(Knjiga k)
{

    std::map<std::string,std::set<Trojka>> povratna;
    std::string pomocni;
    for(auto it=k.begin(); it!=k.end(); it++) { //prolazim kroz mapu sa iteratorom
        for(int i=0; i!=it->second.size(); i++) { //obicna for petlja prolazi kroz vektor
            for(int j=0; j<it->second[i].length(); j++) {//stanica
                it->second[i]= PretvoriUMalo(it->second[i]); //prolazim kroz string
                if((it->second[i][j]>='A' && it->second[i][j]<='Z') || (it->second[i][j]>='a' && it->second[i][j]<='z') || (it->second[i][j]>='0' || it->second[i][j]<='9')) {
                   int pocetak=j;
                    while(j<it->second[i].length() &&( (it->second[i][j]>='A' && it->second[i][j]<='Z')|| (it->second[i][j]>='a' && it->second[i][j]<='z') || (it->second[i][j]>='0' && it->second[i][j]<='9'))) {
                        pomocni.push_back(it->second[i][j]);
                        //i++;
                         j++;
                         
                    }

                    auto pomit= povratna.find(pomocni); //trazim string
                    if(pomit!=povratna.end()) {
                         Trojka skup;
                        skup=(std::make_tuple(it->first,i+1,pocetak));//u skup ubacujem trojku
                        
                        pomit->second.insert(skup);
                  
                    } else {
                         std::set<Trojka> skup;
                        skup.insert(std::make_tuple(it->first,i+1,pocetak));
                        povratna.insert(std::make_pair(pomocni,skup));
                      
                        
                    }
                    pomocni.resize(0);
                }
            }
        }
    }
      auto nekiit=povratna.begin();//mapa
    povratna.erase(nekiit->first);
    return povratna;
}

std::set<Trojka> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<Trojka>> indeks_pojmova){
    PretvoriUMalo(s);
    auto it = indeks_pojmova.find(s);
    if(it==indeks_pojmova.end()) throw std::logic_error("Unesena rijec nije nadjena!\n");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<Trojka>> indeks_pojmova){
    std::cout<<"\nKreirani indeks pojmova:\n";

    for( auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++){
      std::cout<<it->first;    
      std::cout<<": ";
       
       auto skupit=it->second.begin();
        while(skupit!=it->second.end()){
           if(skupit!= (it->second).begin()) std::cout<<", ";
            std::cout<<std::get<0>(*skupit)<<"/";
            std::cout<<std::get<1>(*skupit)<<"/";
            std::cout<<std::get<2>(*skupit);
            skupit++;
        }
        
        std::cout << std::endl;
    }
}
int main ()
{
    std::string tekst,t;
    Knjiga k;
    std::map<std::string,std::set<Trojka>>rezultat;
    std::vector<std::string> v;
    do{
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,tekst);
        if(tekst == ".") break;
        int i=0;
        do{
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
            std::getline(std::cin,t);
            v.push_back(t);
            if(t == ".") break;
            i++;
        }while(true);
        k.insert(std::make_pair(tekst,v));
    }while(true);

        rezultat = KreirajIndeksPojmova(k);
        IspisiIndeksPojmova(rezultat);
        std::string s;
   do{
        try{
            std::cout<<"Unesite rijec: ";
       
            std::getline(std::cin, s);
            if(s == "." ) break;
            std::set<Trojka> a=PretraziIndeksPojmova(s,rezultat);
                
                auto its=a.begin();
                while(its!=a.end()){
                    if(its!=a.begin()) std::cout<<" ";
                    std::cout<<std::get<0>(*its)<<"/";
                    std::cout<<std::get<1>(*its)<<"/";
                    std::cout<<std::get<2>(*its);
                    its++;
            }
            std::cout<<std::endl;
        }
        
        catch(std::logic_error e){
            std::cout<<e.what();
        }
   }while(s!="."); 
    
    return 0;
}
