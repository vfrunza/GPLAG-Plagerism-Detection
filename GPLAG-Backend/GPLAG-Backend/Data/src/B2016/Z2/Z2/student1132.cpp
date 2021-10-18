#include<vector>
#include<deque>
#include<iostream>
#include<string>
#include<stdexcept>
#include<iomanip>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
std::string ispis(int n){
    std::vector<std::string> nz{"NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno","DesnoLijevo"};
    return nz.at(n);
}
int min(int a,int b) {if(a<b) return a; return b;}
int max(int a,int b) {if(a>b) return a; return b;}
template<typename T>
auto IzdvojiDijagonale3D(T kont,SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type{
     typename std::remove_reference<decltype(kont.at(0).at(0))>::type pr;
      typename std::remove_reference<decltype(kont.at(0))>::type pr1;
    if(kont.size() == 0 || kont.at(0).size()==0 || kont.at(0).at(0).size()==0) return pr1;
    typedef typename std::remove_reference<decltype(kont.at(0))>::type Povratni;
    for(int i=0;i<kont.size();i++)
        for(int j=1;j<kont.at(i).size();j++)
            if(kont.at(i).at(j).size()!=kont.at(i).at(j-1).size() || kont.at(i).at(0).size()!=kont.at(max(0,i-1)).at(0).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    for(int i=1; i<kont.size(); i++)  if(kont.at(i).size()!=kont.at(i-1).size() ) throw std::domain_error("Plohe nemaju isti broj redova");
    Povratni rez;
    if(smjer == SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed){
        for(int i=0;i<kont.size();i++){
            rez.push_back(pr);
            for(int j=0;j<min(kont.at(0).size(),kont.at(0).at(0).size());j++) {
                if(smjer==SmjerKretanja::NaprijedNazad) rez.at(i).push_back(kont.at(i).at(j).at(j));
                else rez.at(i).push_back( kont.at(kont.size()-1-i).at(j).at(kont.at(i).at(j).size()-1-j));
            }
        }
    }
    if(smjer == SmjerKretanja::GoreDolje || smjer == SmjerKretanja::DoljeGore){
        for(int i=0;i<kont.at(0).size();i++) {
            rez.push_back(pr);
            for(int j=0;j<min(kont.size(),kont.at(0).at(0).size());j++){
                if(smjer == SmjerKretanja::GoreDolje) rez.at(i).push_back(kont.at(kont.size()-j-1).at(i).at(j));
                else rez.at(i).push_back(kont.at(kont.size()-j-1).at(kont.at(0).size()-1-i).at(kont.at(0).at(0).size()-1-j));
            }
        }
    }
    if(smjer == SmjerKretanja::LijevoDesno || smjer == SmjerKretanja::DesnoLijevo ){
        for(int i=0;i<kont.at(0).at(0).size();i++){
            rez.push_back(pr);
            for(int j=0;j<min(kont.size(),kont.at(0).size());j++){
                if(smjer == SmjerKretanja::LijevoDesno) rez.at(i).push_back(kont.at(kont.size()-1-j).at(j).at(i));
                else rez.at(i).push_back(kont.at(j).at(j).at(kont.at(0).at(0).size()-1-i));
            }
        }
    }
    return rez;
}

int main (){
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z,sm;
    std::cin>>x>>y>>z;
    std::vector<std::deque<std::deque<int> > > vdv;
   try{
       vdv = std::vector<std::deque<std::deque<int> > >(x,std::deque<std::deque<int> >(y,std::deque<int>(z))) ;
   }
   catch(...) {
       std::cout<<"Neispravne dimenzije kontejnera!";
       return 0;
   }
    std::cout<<"Unesite elemente kontejnera:\n";
    for(int i=0;i<x;i++) for(int j=0;j<y;j++) for(int k=0;k<z;k++) std::cin>>vdv.at(i).at(j).at(k);
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin>>sm;
    if(sm<0 || sm>5) {std::cout<<"Smjer kretanja nije ispravan!\n"; return 0;}
    std::cout<<ispis(sm)<<":\n";
    auto dv = IzdvojiDijagonale3D(vdv,SmjerKretanja(sm));
    for(auto e:dv) {
        for(auto el:e)std::cout<<std::setw(4)<<el;
        std::cout<<"\n";
    }
	return 0;
}
// //= { { {1,2,3,0},{3,1,2,5},{4,2,1,4} },{ {5,2,3,1},{3,5,2,5},{1,7,7,0}} }