// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>

 enum class SmjerKretanja{NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename NekiTIp>

auto IzdvojiDijagonale3D(NekiTIp &kont, enum SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type Tip;
    typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type Tip2;
     int duzina(kont.at(0).at(0).size());
     int visina(kont.at(0).size());
     int sirina(kont.size());
     if(visina==0 || sirina==0 || duzina==0){
     Tip NoviKontejner(0, Tip2(0));
     return NoviKontejner;
     }
     for(int i=0; i<sirina; i++)
        for(int j=0; j<visina; j++)
            if(kont.at(i).at(j).size()!=duzina) throw std::domain_error("Redovi nemaju isti broj elemenata");
            
     for(int i=0; i<sirina; i++)
            if(kont.at(i).size()!=visina) throw std::domain_error("Plohe nemaju isti broj redova");
            
    int min;
    if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed){
    if(duzina<visina)
    min=duzina;
    else min=visina;
    Tip NoviKontejner(sirina,Tip2(min));
            for(int i=0; i<sirina; i++){
                for(int j=0; j<visina; j++)
                    for(int k=0; k<duzina; k++)
                    if(smjer==SmjerKretanja::NaprijedNazad && k==j)
                    NoviKontejner.at(i).at(j)=kont.at(i).at(j).at(k);
            }
            for(int i=sirina-1; i>=0; i--){
                for(int j=0; j<visina; j++)
                    for(int k=duzina-1; k>=0; k--)
                    
                    if(smjer==SmjerKretanja::NazadNaprijed && k==duzina-1-j)
                    NoviKontejner.at(sirina-1-i).at(j)=kont.at(i).at(j).at(k);
            }       
             return NoviKontejner;       
    }
    
    if(smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore){
        if(duzina<sirina)
            min=duzina;
        else min=sirina;
        Tip NoviKontejner(visina, Tip2(min));
        for(int i=0; i<visina; i++)
            for(int j=sirina-1; j>=0; j--)
                for(int k=0; k<duzina; k++){
                    if(smjer==SmjerKretanja::GoreDolje && j+k==sirina-1)
                        NoviKontejner.at(i).at(sirina-1-j)=kont.at(j).at(i).at(k);
                    if(smjer==SmjerKretanja::DoljeGore && k-j==duzina-sirina)
                        NoviKontejner.at(visina-1-i).at(sirina-1-j)=kont.at(j).at(i).at(k);
                }
            return NoviKontejner;
    }
                
    if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo){
        if(visina<sirina)
            min=visina;
        else min=sirina; 
        Tip NoviKontejner(duzina, Tip2(min));
        for(int i=0; i<duzina; i++)
            for(int j=0; j<visina; j++){
                for(int k=sirina-1; k>=0; k--){
                if(smjer==SmjerKretanja::LijevoDesno && j+k==sirina-1)
                    NoviKontejner.at(i).at(j)=kont.at(k).at(j).at(i);
                if(smjer==SmjerKretanja::DesnoLijevo && j==k)
                    NoviKontejner.at(duzina-1-i).at(k)=kont.at(k).at(j).at(i);
            }}
                    return NoviKontejner;
    }  
}        

int main() 
{
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0){
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
  std::deque<std::deque<std::vector<short int>>> kont(x, std::deque<std::vector<short int>>(y, std::vector<short int>(z)));
  std::cout << "Unesite elemente kontejnera: ";
  for(int i=0; i<x; i++)
    for(int j=0; j<y; j++)
        for(int k=0; k<z; k++)
            std::cin >> kont[i][j][k];
            int s;
std::cout << std::endl << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> s;
    if(s<0 || s>5){
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    if(s==0) std::cout << "NaprijedNazad: ";
    else if(s==1) std::cout << "NazadNaprijed: ";
    else if(s==2) std::cout <<"GoreDolje: ";
    else if(s==3) std::cout << "DoljeGore: ";
    else if(s==4) std::cout << "LijevoDesno: ";
    else if(s==5) std::cout << "DesnoLijevo: ";
    std::cout << std::endl;
 for (const auto &red : IzdvojiDijagonale3D(kont,SmjerKretanja(s)))
 {
 for (const auto &x : red)
 std::cout.width (4), std::cout << x;
 std::cout << std::endl;
 }

    
	return 0;
}