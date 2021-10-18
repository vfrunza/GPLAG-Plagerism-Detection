/B2017/2018: Zadaća 3, Zadatak 2 #include
#include <iostream> 
#include <map> 
#include <string>
#include <stdexcept> 
#include <utility> 
#include <vector>
#include <iterator>
#include <cctype>
#include <set>

using namespace std;
typedef map <string, vector<string>> Knjiga;


string pretvoriUMala(string tekst){
    string rezultat;
    for(int i=0; i<tekst.size(); i++){
        rezultat.push_back(tolower(tekst.at(i)));
        
    }
    return rezultat;
}


map<string,set<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga k) {
    map<string, set<tuple<string,int,int>>> indeks;

    //Prolazak kroz poglavlja
    for(auto ite=k.begin(); ite!=k.end();ite++) {
        
        
        //Prolazak kroz stranice jednog poglavlja
        for(int j=0; j<(ite->second).size(); j++) {

            string tekst=(ite->second).at(j);
            bool razmak(true);
            
            //Pretrazivanje teksta jedne stranice unutar jednog poglavlja
            for(int i=0;i<tekst.size();i++) {

                //Algoritam za pronalke pocetka i kraja rijeci
                
                //Preskakanje  i detektovanje svih razmaka 
                if(!((tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9'))){
                    razmak=true;
                }
                
                else if(razmak){
                    int poc=i;
                    while( i< tekst.size() && ((tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9'))){
                        i++;
                    }
                    string rijec(tekst.substr(poc,i-poc));
                    rijec = pretvoriUMala(rijec);
                    bool ima_u_mapi(false);
                    
                    auto pravaPoz = indeks.begin();
                    for(auto it=indeks.begin(); it!=indeks.end(); it++){
                        if(rijec==pretvoriUMala(it->first)){
                            ima_u_mapi=true;
                            pravaPoz = it;
                            break;
                            
                        }
                    }
                    
                    if(ima_u_mapi){
                        pravaPoz->second.insert(make_tuple(ite->first,j+1,poc));
                        
                        
                        
                    }
                    else{
                        set<tuple<string,int,int>> mojSet{ make_tuple(ite->first,j+1,poc) };
                        indeks.insert(make_pair(rijec,mojSet));
                        
                    }
                    
                }


            }

        }
    }
    return indeks;
} 



set<tuple <string, int, int >> PretraziIndeksPojmova(string rijec, map<string, set<tuple <string, int, int >> > indeks) {
    set<tuple<string,int,int>> pozicija;
    
    rijec=pretvoriUMala(rijec);
    for(auto it=indeks.begin();it!=indeks.end();it++) {
        if(rijec==it->first) {
                /*get<0>(pozicija)=get<0>(indeks->second);
                get<1>(pozicija)=get<1>(indeks->second);
                get<2>(pozicija)=get<2>(indeks->second);*/
                return it->second;
        }    
    }
    throw logic_error("Pojam nije nadjen");
} 

void IspisiIndeksPojmova(map<string, set<tuple < string, int, int >>> indeks)
{
    for(auto it=indeks.begin(); it!=indeks.end(); it++) {
        cout<<it->first<< ": ";
           /* auto pok=ite;
            pok++;*/
            for(auto ite = (it->second).begin(); ite!=(it->second).end(); ite++) {
                cout<<get<0>(*ite)<<"/"<<get<1>(*ite)<<"/"<<get<2>(*ite);
                auto ite2=ite;
                ite2++;
                if(ite2!=(it->second).end())
                    cout<<", ";
            
        }
        cout<<endl;
    }
}

int main ()
{
    Knjiga k;
    vector<string> sadrzajs;
    string sadrzaj;
    string nazivp,rijec;
    for(; ; ) {
        cout<< "Unesite naziv poglavlja: ";
        getline(cin, nazivp);
        if(nazivp=="." ) break;
        int i(0);
        while(1) {
            cout<< "Unesite sadrzaj stranice "<<i+1<< ": ";
            getline(cin,sadrzaj);
            if(sadrzaj==".") {
                break;
            }
            sadrzajs.push_back(sadrzaj);
            i++;
        }
        k.insert(make_pair(nazivp,sadrzajs));
    }
    cout<<endl;
    map<string, set<tuple<string,int,int>>> indeks(KreirajIndeksPojmova(k));
    cout<<"Kreirani indeks pojmova:"<<endl;
    IspisiIndeksPojmova(indeks);
    cout<<endl;
    while(true) {
        cout<<"Unesite rijec: ";
        getline(cin,rijec);
        if(rijec==".")
            break;
        set<tuple<string,int,int>> pozicija;
        try {
            auto mojSet=PretraziIndeksPojmova(rijec,indeks);
           // auto it=pozicija.begin();
          //  for(it=pozicija.begin();it!=pozicija.end();it++)
            for(auto ite = mojSet.begin(); ite!=mojSet.end(); ite++) {
                cout<<get<0>(*ite)<<"/"<<get<1>(*ite)<<"/"<<get<2>(*ite);
                cout<<" ";
            
             }
             cout<<endl;
            // if (it!=pozicija.end()-1) cout<<",";  
            
        }
        catch(logic_error izuzetak){
            cout<<"Unesena rijec nije nadjena!"<<endl;
    
        }
    }
        return 0;
}


