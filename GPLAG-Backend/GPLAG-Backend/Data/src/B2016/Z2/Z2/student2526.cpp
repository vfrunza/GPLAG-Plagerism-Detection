#include <type_traits>
#include <iostream>
#include <stdexcept>
#include <deque>
#include <string>
#include <iomanip>
#include <vector>
typedef std::deque<std::vector<int>> Matrica;
enum class SmjerKretanja {NaprijedNazad,NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename tip>

auto IzdvojiDijagonale3D(tip D,SmjerKretanja smjer)->typename std::remove_reference<decltype(D.at(0))>::type{
    if(D.size()==0||D.at(0).size()==0||D.at(0).at(0).size()==0){
        typename std::remove_reference<decltype(D.at(0))>::type D2;
        return D2;
    }
    for(int i=0;i<D.size();i++){
        for(int j=0;j<D.at(i).size();j++) if(D.at(0).at(0).size()!=D.at(i).at(j).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    for(int i=0;i<D.size();i++) if(D.at(0).size()!=D.at(i).size()) throw std::domain_error("Plohe nemaju isti broj redova");
    if(smjer==SmjerKretanja::NaprijedNazad){
         typename std::remove_reference<decltype(D.at(0))>::type D2(D.size());
        for(int i=0;i<D.size();i++){
            for(int j=0;j<D.at(i).size();j++){
                if(j==D.at(0).at(0).size()) break;
                D2.at(i).push_back(D.at(i).at(j).at(j));
            }
        }
        return D2;
    }
   if(smjer==SmjerKretanja::NazadNaprijed){
       int f=0;
        typename std::remove_reference<decltype(D.at(0))>::type D2(D.size());
        for(int i=D.size()-1;i>=0;i--){
            int brojac=0;
            for(int j=0;j<D.at(i).size();j++){
                if(brojac==D.at(0).at(0).size()) break;
                int b=D.at(i).at(j).size()-1;
                D2.at(f).push_back(D.at(i).at(j).at(b-brojac));
                brojac++;
            }
            f++;
        }
        return D2;
    }
    if(smjer==SmjerKretanja::LijevoDesno){
        typename std::remove_reference<decltype(D.at(0))>::type D2(D.at(0).at(0).size());
        for(int i=0;i<D.at(0).at(0).size();i++){
            int brojac=0;
            for(int j=D.size()-1;j>=0;j--){
                if(brojac==D.at(0).size()) break;
                D2.at(i).push_back(D.at(j).at(brojac).at(i));
                brojac++;
            }
        }
        return D2;
    }
 if(smjer==SmjerKretanja::DesnoLijevo){
        typename std::remove_reference<decltype(D.at(0))>::type D2(D.at(0).at(0).size());
        int f=0;
        for(int i=D.at(0).at(0).size()-1;i>=0;i--){
            int brojac=0;
            for(int j=0;j<D.size();j++){
                if(brojac==D.at(0).size()) break;
                D2[f].push_back(D.at(j).at(brojac).at(i));
                brojac++;
            }
            f++;
        }
        return D2;
    }
    if(smjer==SmjerKretanja::GoreDolje){
        typename std::remove_reference<decltype(D.at(0))>::type D2(D.at(0).size());
        int f=0;
        for(int i=0;i<D.at(0).size();i++){
            int brojac=0;
            for(int j=D.size()-1;j>=0;j--){
                if(brojac==D.at(0).at(0).size()) break;
                D2.at(f).push_back(D.at(j).at(i).at(brojac));
                brojac++;
            }
            f++;
        }
        return D2;
    }
    if(smjer==SmjerKretanja::DoljeGore){
        typename std::remove_reference<decltype(D.at(0))>::type D2(D.at(0).size());
        int f=0;
        for(int i=D.at(0).size()-1;i>=0;i--){
            int brojac=0;
            for(int j=D.size()-1;j>=0;j--){
                int b=D.at(0).at(0).size()-1;
                if(brojac==D.at(0).at(0).size()) break;
                D2.at(f).push_back(D.at(j).at(i).at(b-brojac));
                brojac++;
            }
            f++;
        }
        return D2;
    }   
    
}
int main(){
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
   std::cin>>x>>y>>z;
    if(x<=0||y<=0||z<=0){
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    } 
    std::deque<Matrica> kont(x,Matrica(y,std::vector<int>(z))); 
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;;
   for(int i=0;i<kont.size();i++){
        for(int j=0;j<kont.at(i).size();j++){
            for(int zlj=0;zlj<kont.at(i).at(j).size();zlj++) std::cin>>kont.at(i).at(j).at(zlj);
        }
    } 
    int broj;
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin>>broj;
    if(broj>5||broj<0){
        std::cout<<"Smjer kretanja nije ispravan! "<<std::endl;
        return 0;
    }
    SmjerKretanja smjer[6]={SmjerKretanja::NaprijedNazad,SmjerKretanja::NazadNaprijed,SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    std::vector<std::string> ispis={"NaprijedNazad:","NazadNaprijed:","GoreDolje:","DoljeGore:", "LijevoDesno:","DesnoLijevo:"};
    try{
    auto k=IzdvojiDijagonale3D(kont,smjer[broj]);
    std::cout<<ispis[broj]<<std::endl;
    for(int i=0;i<k.size();i++){
        for(int j=0;j<k.at(i).size();j++) std::cout<<std::setw(4)<<k.at(i).at(j);
        std::cout<<std::endl;
    }
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    
}

