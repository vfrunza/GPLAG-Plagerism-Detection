#include <iostream>
#include <vector>
#include <deque>
enum class SmjerKretanja{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};
template<typename kont>
auto IzdvojiDijagonale3D(kont kontenjer,SmjerKretanja smjer)->decltype(*(kont.begin())){
    for(auto i=kont.begin();i!=kont.end();i++){
        for(auto j=(*i).begin();j!=(*i).end();j++){
            for(auto k=(*j).begin();k!=(*j).end;k++){
                if(smjer==SmjerKretanja:NazadNaprijed){
                    while(*i)
                }
            }
        }
    }
}
int main ()
{
	return 0;
}