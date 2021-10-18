#include <iostream>
#include <string>
#include <vector>
#include <memory>

 class Skladiste {
     
 }; 
 class Spremnik {
     std::vector<std::shared_ptr<Spremnik>> pok;
        std::string ime;
        
     
 };

class Sanduk: public Spremnik {
    double klz;
 
    std::vector<double> predmeti;
    public:
    Sanduk (double tez, std::string naz, std::vector<double> lista) : klz(tez), ime(naz), predmeti(lista) { }
    
};

class Vreca: public Spremnik {
   double klz;
   std::vector<double> predmeti;
    public:
     Vreca (double tez, std::string naz, std::vector<double> lista) : klz(tez), ime(naz), predmeti(lista) { }
};

class Bure: public Spremnik {
    double gust, zpr;
    
   
    public:
    Bure (double tez, std::string naz, double specT, double vol) : klz(tez), ime(naz), gust (specT), zpr(vol) { }
};




int main ()
{
	return 0;
}
