#include <iostream>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;
using std::cin;
static int brojac_stranica(0);
typedef std::map<string, std::vector<string>> Knjiga;
std::map<string,std::set<std::tuple<string,int,int>>>Funkcija(string nazivP,std::vector<string> &stranice)
{
    std::map<string,std::set<std::tuple<string,int,int>>> Mapa;
    //krecemo se po stranicama jednog poglavlja
    //jedna stranica jedan string       
    
    std::vector<string> vektorRijeci;
    std::vector<int> vektorStranica;
    std::vector<int> vektorPozicije; 
    for(int i=0; i<stranice.size(); i++) {
        brojac_stranica++;
        for(int j=0; j<stranice[i].length(); ) {
            //kroz citavu jednu stranicu
            string rijec;
            //preskace sve sto nije slovo niti cifra
            while (j < stranice[i].length() && stranice[i][j] == ' ') j++;
            while (j < stranice[i].length() && !(isalpha(stranice[i][j])) && !(isdigit(stranice[i][j])) ) j++;


            int kontrola(0);
//kada je slovo ili broj...
            int prviPut(1);
            int indeks(0);
            while (j < stranice[i].length() && (isalpha(stranice[i][j]) || isdigit(stranice[i][j]))) {
                if(prviPut) indeks=j;
                prviPut=0;
                kontrola=1;
                rijec+=stranice[i][j];
                j++;
            }
            if(kontrola==1) {
                //kada nadje citavu rijec u vektor str upisuje strna kojoj se nalazi ta rijec
                vektorRijeci.push_back(rijec);
                vektorStranica.push_back(brojac_stranica);
                vektorPozicije.push_back(indeks);
            }
            //ubacuje se svaka rijec u vektor rijeci kao string zaseban
        }

    }

    //mala slova...
    for(int i=0; i<vektorRijeci.size(); i++)
        std::transform(vektorRijeci[i].begin(),vektorRijeci[i].end(),vektorRijeci[i].begin(),tolower);

    
    std::tuple<string,int,int> par;
    std::set<std::tuple<string,int,int>> PomocniSkup;
    for(int i=0; i<vektorRijeci.size(); i++) {
        if(i!=0) {
            auto it(Mapa.find(vektorRijeci[i]));
            //ako nije bilo te rijeci prije
            if(it==Mapa.end()) {
                par=std::make_tuple(nazivP,vektorStranica[i],vektorPozicije[i]);
                PomocniSkup.clear();
                PomocniSkup.insert(par);
                Mapa.insert(std::make_pair(vektorRijeci[i],PomocniSkup));
            } else {
                //ako vec postoji ta rijec u mapi,u njen skup dodaje novi tuple pozicije
                par=std::make_tuple(nazivP,vektorStranica[i],vektorPozicije[i]);
                (it->second).insert(par); //ubacujem u skup
            }

        } else {
            par=std::make_tuple(nazivP,vektorStranica[i],vektorPozicije[i]);
            PomocniSkup.clear();
            PomocniSkup.insert(par);
            Mapa.insert(std::make_pair(vektorRijeci[i],PomocniSkup));
        }
    }
    return Mapa;
}
//vracena mapa za jedno poglavlje
std::map<string,std::set<std::tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga tekst)
{
    //kretanje kroz mapu
    //dodati uslove ako je mapa prazna...
    std::map<string,std::set<std::tuple<string,int,int>>> Mapa;
    for(auto it=tekst.begin(); it!=tekst.end(); it++) {
        if(int(tekst.size())==1) {
            auto RezMapa(Funkcija(it->first,it->second));
            return RezMapa;
        } else {
            //preuzimam mapu za jedno poglavlje iz funkcije
            auto RezMapa(Funkcija(it->first,it->second));
            for(auto iterator=RezMapa.begin(); iterator!=RezMapa.end(); iterator++) {
                auto it1(Mapa.find(iterator->first));
                //ako ne postoji ta rijec prije
                if(it1==Mapa.end())
                    Mapa.insert(std::make_pair(iterator->first,iterator->second));
                else {
                    //auto something(it1->second); //skup iz mape
                    auto something2(iterator->second);//skup koji se treba dodat u postojeci
                    //otvoriti skup
                    for(auto it2=something2.begin(); it2!=something2.end(); it2++)
                        (it1->second).insert(*it2);
                    //brise se stari par..
                   // Mapa.insert(std::make_pair(iterator->first,it1->second));
                }
            }


        }

    }
    return Mapa;
}

std::set<std::tuple<string,int,int>> PretraziIndeksPojmova(string rijec,std::map<string,std::set<std::tuple<string,int,int>>> &IndeksP)
{
    auto it(IndeksP.find(rijec));
    if(it==IndeksP.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    else
        return it->second;
}
void IspisiIndeksPojmova(std::map<string,std::set<std::tuple<string,int,int>>> &IndeksPojmova)
{
    for(auto it=IndeksPojmova.begin(); it!=IndeksPojmova.end(); it++) {
        cout<<it->first<<": ";
        for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++) {
            cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
            auto pomocni(it2);
            pomocni++;
            if(pomocni == (it->second).end()) break;
            cout<<", ";
        }
        cout<<endl;
    }
}

int main ()
{
     Knjiga mapa;
    
     int i(1);
     string sadrzaj;
     for(;;){
          cout<<"Unesite naziv poglavlja: ";
          string naziv;
            std::getline(cin,naziv);
            if(naziv==".") break;
            std::vector<string> stranice;
            for(;;){
            cout<<"Unesite sadrzaj stranice "<<i<<": ";

            std::getline(cin,sadrzaj);

            if(sadrzaj==".") break;
            else stranice.push_back(sadrzaj);
            i++;
            }
          mapa.insert(std::make_pair(naziv,stranice));
     }
     
   
     
     cout<<std::endl;
     cout<<"Kreirani indeks pojmova:"<<std::endl;
     auto Mapa( KreirajIndeksPojmova(mapa));
     IspisiIndeksPojmova(Mapa);
     cout<<std::endl;
     
     for(;;){
          cout<<"Unesite rijec: ";
          string rijec;
            std::getline(cin,rijec);
            if(rijec==".") break;
            
           try{auto rez(PretraziIndeksPojmova(rijec,Mapa)); //vraca skup
           for(auto it=rez.begin();it!=rez.end();it++)
          cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
           cout<<std::endl;
           }catch(std::logic_error e){
               cout<<e.what();
               cout<<std::endl;
   }
     }
    return 0;
}
 