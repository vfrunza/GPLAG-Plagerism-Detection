#include <iostream>
    
    enum class SmjerKretanja{NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};
    
    template < typename kont >
   auto IzdvojiDijagonale3D ( kont a , SmjerKretanja smjer ) -> typename std::remove_reference<decltype>(a.at(0))::type {
        
        
    }
int main ()
{
    std::cout<<"Unesite dimenzije (x y z) : ";
    std::cout<<"Unesite elemente kontejnera: ";
    
	return 0;
}