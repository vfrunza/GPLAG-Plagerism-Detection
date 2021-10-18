/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>
//pomocna funkcija koja broji kolika je velicina imena(u skladu s postavkom definisanim nacinom)
int Prebroji(std::string s){
    int br(0);
    for(int i=0; i<s.length(); i++){
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') ) br++;
    }
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> matrica, int broj_timova){
    if(broj_timova<1 || broj_timova>matrica.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> skup(broj_timova);
    //kopiranje imena djece iz vektora primljenog u funkciji u listu
    std::list<std::string> lista;
    for(int i=0; i<matrica.size(); i++){
        lista.push_back(matrica[i]);
    }
    int broj_vecih(matrica.size()%broj_timova), broj_djece(matrica.size()),velicina_tima(broj_djece/broj_timova);
    int br(0),vel(0), i(0);
    //while-petlja u kojoj vrsimo formiranje timova
    auto it(lista.begin());
    while(broj_djece>0){
        //blok naredbi koji se izvrsava ukoliko je u pitanju prvo dijete(od njega sve pocinje,stoga, poseban uslov)
        if(broj_djece==matrica.size()){
            skup[br].insert(*it);
            vel=Prebroji(*it)-1; //Prebroji je pomocna funkcija, broji slova u rijeci, "-1" zato sto erase pomjera iterator za jedno mjesto naprijed
            it = lista.erase(it); broj_djece--;
            i++;
            //pomjeranje iteratora za onoliko mjesta kolika je duzina imena izbacenog elementa iz liste
            while(vel>0){
                //ako je iterator na poziciji posljednjeg clana u listi postavlja se da pokazuje na prvi clan liste
                if(it==--lista.end()) it=lista.begin();
                else it++;
                vel--;
            }    
        }
        else{
            //broj_vecih predstavlja broj timova koji trebaju imati n/k+1 element,dok br predstavlja poziciju skupa u vektoru skupova
            //i predstavlja svojevrsni brojac prolaza kroz glavnu petlju, a sluzi da predjemo na novi skup, kada se sadasnji popuni dovoljnim brojem elemenata(djece)
            if(broj_vecih>0 && i==velicina_tima+1) {broj_vecih--;br++; i=0; }//broj_vecih-- jer ako je if-uslov tacan, to znaci da je fomiran tim od n/k+1 elemenata, te se treba formirati novi tim
            else if(broj_vecih==0 && i==velicina_tima) {br++; i=0;}
            bool zadnji(false);
            if( broj_djece>1 && it==--lista.end() ) zadnji=true; //ako se iterator nalazi na zadnjoj poziciji, erase bi ga pomjerio izvan opsega skupa
            skup[br].insert(*it);
            vel=Prebroji(*it)-1;
            if(zadnji){
                //blok naredbi kojim se element brise iz skupa ukoliko je rijec o elementu(tj. iteratoru na nj.) koji se nalazi na zadnjem mjestu
                //it1 je pomocni iterator koji nam sluzi samo za brisanje, dok se "glavni" iterator tj it stavlja na pocetak(kruzno kretanje)
                auto it1(it);
                it=lista.begin();
                it1=lista.erase(it1);
                broj_djece--;
            }
            if(!zadnji){
                //ukoliko nije rijec o iteratoru na posljednjoj poziciji, brisanje se odvija kao i inace
                it=lista.erase(it);
                broj_djece--;
            }
            i++;
            while(vel>0){
                //blok naredbi u kojem se odvija pomjeranje iteratora za odgovarajuci broj mjesta, nacin rada ovog bloka je vec opisan
                if(it==--lista.end()) it=lista.begin();
                else it++;
                vel--;
            }
        }
        
    }
    return skup;
}
int main ()
{   int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::vector<std::string> matrica(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(10000,'\n');
    for(int i=0; i<n; i++) {
        std::getline(std::cin, matrica[i]);
    }
    std::cout<<"Unesite broj timova: ";
    int tim;
    std::cin>>tim;
    try{
    auto skup(Razvrstavanje(matrica, tim));
    for(int i=0; i<skup.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it=skup[i].begin(); it!=skup[i].end(); it++){
            if(it==--skup[i].end()) std::cout<<*it;
            else std::cout<<*it<<", ";
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}