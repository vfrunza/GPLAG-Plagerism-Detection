#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
using std::cout;
using std::cin;
using std::endl;
using std::domain_error;


//size”, “at” i “push_back”
template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner kont, SmjerKretanja smjer)-> typename std::remove_reference<decltype(kont.at(0))>::type {
     typename std::remove_reference<decltype(kont.at(0))>::type Rezultat;
     if(kont.size()==0) return Rezultat;
     if(kont.at(0).size()>0){
         int br_redova(kont.at(0).at(0).size());
         for(int p=0; p<kont.size(); p++){
             for(int i=0; i<kont.at(0).size(); i++){
                 if (kont.at(p).at(i).size()!=br_redova) throw domain_error("Redovi nemaju isti broj elemenata");
             }
         }
     }
     for(int p=0; p<int(kont.size()-1); p++) { if(kont.at(p).size()!=kont.at(p+1).size()) throw std::domain_error("Plohe nemaju isti broj redova");}
     if(smjer==SmjerKretanja::NazadNaprijed or smjer==SmjerKretanja::NaprijedNazad){//Po Plohama
         typename std::remove_reference<decltype(kont.at(0).at(0))>::type JedanRed;
         for(int p=0; p<kont.size(); p++){ //Ploha
            int ploha(p);
            if(smjer==SmjerKretanja::NazadNaprijed) ploha=kont.size()-1-p;
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type JedanRed;
            for(int i=0; i<kont.at(0).size(); i++){ //Red
                int kolona(i);
                if(smjer==SmjerKretanja::NazadNaprijed) kolona=kont.at(0).at(0).size()-1-i;
                if(kolona<kont.at(0).at(0).size() and kolona>=0) JedanRed.push_back(kont.at(ploha).at(i).at(kolona));
            }
            Rezultat.push_back(JedanRed);
         }
     }
     else if((smjer==SmjerKretanja::DesnoLijevo or smjer==SmjerKretanja::LijevoDesno) and kont.at(0).size()>0){ //PO KOLONAMA
        for(int j=0; j<kont.at(0).at(0).size(); j++){ // kolone
            int kolona(j);
            if(smjer==SmjerKretanja::DesnoLijevo) kolona=kont.at(0).at(0).size()-1-j;
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type JedanRed;
            for(int i=0; i<kont.at(0).size(); i++){
                int ploha(i);
                if(smjer==SmjerKretanja::LijevoDesno) ploha=kont.size()-1-i;
                if(ploha>=0 and ploha<kont.size())JedanRed.push_back(kont.at(ploha).at(i).at(kolona));
            }
            Rezultat.push_back(JedanRed);
        }
     }
     else{ //PO Redovima
        for(int i=0; i<kont.at(0).size(); i++){ //Redovi
            int red(i);
            if(smjer==SmjerKretanja::DoljeGore) red=kont.at(0).size()-1-i;
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type JedanRed;
            for(int j=0; j<kont.at(0).at(0).size(); j++){ //Kolone
                int kolona(j); int ploha(kont.size()-1-j);
                if(smjer==SmjerKretanja::DoljeGore) kolona=kont.at(0).at(0).size()-1-j;
                if(ploha>=0 and ploha<kont.size()) JedanRed.push_back(kont.at(ploha).at(red).at(kolona));
            }
            Rezultat.push_back(JedanRed);
        }
     }
    return Rezultat;
}


int main ()
{
    cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    cin>>x>>y>>z;
    if(x<0 or y<0 or z<0){
        cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> Kvadar (x,std::deque<std::deque<int>>(y,std::deque<int>(z)));
    cout<<"Unesite elemente kontejnera: ";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++) cin>>Kvadar.at(i).at(j).at(k);
        }
        cout<<endl;
    }
    cout<<"Unesite smjer kretanja [0 - 5]: ";
    int unos;
    cin>>unos;
    if(unos<0 or unos>5) {
        cout<<"Smjer kretanja nije ispravan!"<<endl;
        return 0;
    }
    try{
        SmjerKretanja smjer = SmjerKretanja(unos);
        std::deque<std::deque<int>> Dijagonale(IzdvojiDijagonale3D(Kvadar,smjer));
        switch(unos){
            case 0: cout<<"NaprijedNazad:"<<endl;break;
            case 1: cout<<"NazadNaprijed:"<<endl;break;
            case 2: cout<<"GoreDolje:"<<endl;break;
            case 3: cout<<"DoljeGore:"<<endl;break;
            case 4: cout<<"LijevoDesno:"<<endl;break;
            case 5: cout<<"DesnoLijevo:"<<endl;break;
        }
        for(auto &red: Dijagonale){
            for(auto el: red) cout<<std::setw(4)<<el;
            cout<<endl;
        }
    }
    catch(std::domain_error e){
        cout<<e.what()<<endl;
    }
    return 0;
}
