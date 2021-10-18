#include <iostream>
#include <type_traits>
#include <deque>
#include <vector>
enum class SmjerKretanja{
  NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo  
};

template <typename KontTip>
    auto IzdvojiDijagonale3D(KontTip kont,SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type{
        typename std::remove_reference<decltype(kont.at(0))>::type mat;
        int granica1,granica2,poc1,poc2,velicina;
        if(smjer == SmjerKretanja::NaprijedNazad){
            velicina=kont.size();
            granica1=kont.size();poc1=0;poc2=0;
        if(kont.at(0).size() <= kont.at(0).at(0).size())granica2=kont.at(0).size();
        else granica2 = kont.at(0).at(0).size();
        }else if(smjer == SmjerKretanja::NazadNaprijed){
           granica1=kont.size()-1;
           poc1=-1;
           if(kont.at(0).size() <= kont.at(0).at(0).size())poc2=kont.at(0).size();
           
        }
        
        
        mat.resize(velicina);
        for(int i(poc1);i != granica1;i++){
            
            for(int j(poc2);j != granica2;j++){
                mat.at(abs(i)).push_back(kont.at(abs(i)).at(abs(j)).at(abs(j)));
            }
        }
        return mat;
    }
int main ()
{
	return 0;
}