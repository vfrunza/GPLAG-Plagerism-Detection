/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v)
    {
        std::vector<double> v1;
      	std::vector<std::vector<double>> v2;
      	if( v.size() == 0 )
      	         return {};
          
          bool zadnji = false;
          for(int i = 0; i < v.size()-1; i++) {
              
          	     if( v[i] <= v[i+1] )
          	     	   v1.push_back (v[i]);
          	     	   
          	     if( v[i] > v[i+1]  || i == v.size() - 2)
          	     	 zadnji = true;
          	     	 
           	     if(zadnji){
           	         if(i == v.size() - 2)
          	            v1.push_back( v [i + 1]);
          	         else
          	            v1.push_back( v [i]);
          	        zadnji = false;
           	    }
          	     	 
          	     if( v[i] > v[i+1]  || i == v.size() - 2)
          	         if(v1.size() != 0U){
          	             v2.push_back(v1);
          	             v1.resize(0);
          	         }
          	     
             }
      	     return v2;
      }

std::vector<std::vector<double>> OpadajuciPodnizovi ( std::vector<double> v)
     {
      std::vector<double> v1;
      	std::vector<std::vector<double>> v2;
      	if( v.size() == 0 )
      	         return {};
          
          bool zadnji = false;
          for(int i = 0; i < v.size()-1; i++) {
              
          	     if( v[i] >= v[i+1] )
          	     	   v1.push_back (v[i]);
          	     	   
          	     if( v[i] < v[i+1]  || i == v.size() - 2)
          	     	 zadnji = true;
          	     	 
           	     if(zadnji){
           	         if(i == v.size() - 2)
          	            v1.push_back( v [i + 1]);
          	         else
          	            v1.push_back( v [i]);
          	        zadnji = false;
           	    }
          	     	 
          	     if( v[i] < v[i+1]  || i == v.size() - 2)
          	         if(v1.size() != 0U){
          	             v2.push_back(v1);
          	             v1.resize(0);
          	         }
          	     
             }
      	     return v2;
      }

int main ()
{
    int brEL;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> brEL;
    std::vector<double> Vektor(brEL);
    std::cout << "Unesite elemente vektora: ";
    for(int i = 0; i < brEL; i++){
        std::cin >> Vektor[i];
    }
    auto rastniz = RastuciPodnizovi(Vektor);
    int max = 0;
    for(auto niz : rastniz)
        if(int(niz.size()) > max)
            max = niz.size();
    std::cout << "Maksimalni rastuci podnizovi:\n";
    if(max != 0)
        for(auto niz : rastniz)
            if(int(niz.size()) == max)
            {
                for( auto elem : niz)
                    std::cout << elem << " ";
                std::cout << '\n';
            }
    max = 0;        
    auto opdniz = OpadajuciPodnizovi(Vektor);
    for(auto niz : opdniz)
        if(int(niz.size()) > max)
            max = niz.size();
    std::cout << "Maksimalni opadajuci podnizovi: \n";
    if(max != 0)
        for(auto niz : opdniz)
            if(int(niz.size()) == max)
            {
                for( auto elem : niz)
                    std::cout << elem << " ";
                std::cout << '\n';
            }
                
    
	return 0;
}