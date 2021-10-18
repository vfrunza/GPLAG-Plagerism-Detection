#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename kont>
    auto IzdvojiDijagonale3D(kont kontejner, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kontejner.at(0))>::type{
        typename std::remove_reference<decltype(kontejner.at(0))>::type kont2D;
        typename std::remove_reference<decltype(kont2D.at(0))>::type red;
        
        if((int)kontejner.size()!=0 && (kontejner.at(kontejner.size()-1)).size()!=0 && (int)((kontejner.at(kontejner.size()-1)).at((kontejner.at(kontejner.size()-1)).size()-1)).size()!=0){
            for(int mat=0;mat<(int)kontejner.size();mat++){
                if((kontejner.at(0)).size()!=((kontejner.at(mat))).size())
                    throw std::domain_error ("Plohe nemaju isti broj redova");
            for(int red=0;red<(int)(kontejner.at(mat)).size();red++)
                if((int)((kontejner.at(0)).at(0)).size()!=(int)((kontejner.at(mat)).at(red)).size())
                    throw std::domain_error ("Redovi nemaju isti broj elemenata");
            }  
        }else {return kont2D;}
        
        if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed)
            for(int i=0;i<(int)kontejner.size();i++) kont2D.push_back(red);
        if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo)
            for(int i=0;(int)kontejner.size()!=0 && (kontejner.at(kontejner.size()-1)).size()!=0 && i<(int)((kontejner.at(kontejner.size()-1)).at((kontejner.at(kontejner.size()-1)).size()-1)).size();i++) kont2D.push_back(red);
        if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore)
            for(int i=0;(int)kontejner.size()!=0 && i<(int)(kontejner.at(kontejner.size()-1)).size();i++) kont2D.push_back(red);
        
        int x{}, y{}, pozicija_z{};
        for(int mat=0;mat<(int)kontejner.size();mat++){
            int pozicija_y{}, pozicija_x{};
            for(int x1=0, y1=0; x1<(int)(kontejner.at(mat)).size() && y1<(int)((kontejner.at(mat)).at(x1)).size();){
                
                if(smjer==SmjerKretanja::DoljeGore){
                    (kont2D.at(pozicija_y)).push_back(((kontejner.at(kontejner.size()-mat-1)).at((kontejner.at(kontejner.size()-mat-1)).size()-x1-1)).at(((kontejner.at(mat)).at(x1)).size()-y-1));
                    x1++;
                }
                if(smjer==SmjerKretanja::GoreDolje){
                    (kont2D.at(pozicija_y)).push_back(((kontejner.at(kontejner.size()-mat-1)).at(x1)).at(y));
                    x1++;
                }
                if(smjer==SmjerKretanja::DesnoLijevo){
                    (kont2D.at(pozicija_x)).push_back(((kontejner.at(mat)).at(x)).at(((kontejner.at(mat)).at(x)).size()-y1-1));
                    y1++;
                }
                if(smjer==SmjerKretanja::LijevoDesno){
                    (kont2D.at(pozicija_x)).push_back(((kontejner.at(int(kontejner.size())-mat-1)).at(x)).at(y1));
                    y1++;
                }
                if(smjer==SmjerKretanja::NaprijedNazad){
                    (kont2D.at(pozicija_z)).push_back(((kontejner.at(mat)).at(x1)).at(y1));
                    x1++;y1++;
                }
                if(smjer==SmjerKretanja::NazadNaprijed){
                    (kont2D.at(kont2D.size()-pozicija_z-1)).push_back(((kontejner.at(mat)).at(x1)).at(((kontejner.at(mat)).at(x1)).size()-y1-1));
                    x1++;y1++;
                }
                pozicija_y++; pozicija_x++;
            }
            x++;y++;pozicija_z++;
        }
        return kont2D;
    }

int main (){
    try{
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    if(!(std::cin>>x>>y>>z) || x<0 || y<0 || z<0){
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    std::vector<std::deque<std::vector<int>>> kontejner;
    
    kontejner.resize(x);
    for(auto &dek: kontejner){
        dek.resize(y);
        for(auto &kolone: dek){
            kolone.resize(z);
            for(auto &elementi: kolone)
                std::cin>>elementi;
        }
    }
    std::cin.clear(); std::cin.ignore(1000,'\n');
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int smjer_broj;
    if(!(std::cin>>smjer_broj) || (smjer_broj<0 || smjer_broj>=6)){
        std::cout<<"Smjer kretanja nije ispravan!\n";
        return 0;
    }
    std::cin.clear(); std::cin.ignore(1000,'\n');
    SmjerKretanja smjer=SmjerKretanja(smjer_broj);
    
    auto kont2D(IzdvojiDijagonale3D(kontejner,smjer));
    if(smjer==SmjerKretanja::NaprijedNazad)std::cout<<"NaprijedNazad: "<<std::endl;
    if(smjer==SmjerKretanja::NazadNaprijed)std::cout<<"NazadNaprijed: "<<std::endl;
    if(smjer==SmjerKretanja::GoreDolje)std::cout<<"GoreDolje: "<<std::endl;
    if(smjer==SmjerKretanja::DoljeGore)std::cout<<"DoljeGore: "<<std::endl;
    if(smjer==SmjerKretanja::DesnoLijevo)std::cout<<"DesnoLijevo: "<<std::endl;
    if(smjer==SmjerKretanja::LijevoDesno)std::cout<<"LijevoDesno: "<<std::endl;
    for(auto red:kont2D){
        for(auto elementi:red)
            std::cout<<std::fixed<<std::setw(4)<<elementi;
        std::cout<<std::endl;
    }
	return 0;
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
        return 0;
    }
}