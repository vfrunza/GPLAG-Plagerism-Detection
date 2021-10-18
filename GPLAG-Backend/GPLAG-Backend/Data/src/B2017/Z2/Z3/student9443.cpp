/*B 2017/2018, Zadaća 2, Zadatak 3 */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

int OdrediOsnovniPeriod(std::vector<int> v) {
	for(int p=1; p<v.size(); p++) {
		bool znak{true};
   	    for(int i=p; i<v.size(); i+=p) {
   	    	if( v.at(i) <= 0 ) throw std::domain_error("Neispravan vektor!");
       		for(int j=0; j<p; j++) {
   	    		if(i+j >= v.size()) break;
   		    	if(v.at(i+j) != v.at(j)) {
   		    		znak=false;
   		    		break;
   		    	}
       		}
       	}
       	if(znak) return p;
	}
	return 0;
}

template <typename Tip>
int **AlocirajFragmentirano( std::vector<Tip> &nekinesta, int &koliko_puta) {
	if(nekinesta.size() == 0) throw("Prazan vektor!");
 	int period{ OdrediOsnovniPeriod(nekinesta) };
 	if(period == 0) {
 		period=nekinesta.size();
 		koliko_puta=2;
 	}
 	else if((period > 0 && double(nekinesta.size()) / period - nekinesta.size()/period >0.000001)) {
 		koliko_puta = nekinesta.size() / period; 
        koliko_puta++;
 	}
 	else koliko_puta = nekinesta.size() / period; 
 	int najveci{0};
 	for(int i=0; i<nekinesta.size(); i++) if(najveci < nekinesta.at(i)) najveci=nekinesta.at(i);                    // Najveci broj u vector
 	int **dino{nullptr};
 	try{
     	dino = new Tip*[period*koliko_puta] {};
     	try{
    		int pomocna_najvece{najveci};
    		for(int k=0; k<koliko_puta; k++) {
    			for(int i=0; i<period; i++) {
    				dino[i+k*period]=new int[nekinesta.at(i)];
    				for(int j=nekinesta.at(i)-1; j>=0; j--) {
    					dino[i+k*period][j] = pomocna_najvece;
    					pomocna_najvece--;
    				}
    				pomocna_najvece=najveci;
    			}
    		}
	        
        }
        catch(std::bad_alloc) {
    	   	for(int i=0; i<period*koliko_puta; i++) delete[] dino[i];
    	   	delete[] dino;
 	     	throw;
        }
 	}
 	catch(std::bad_alloc) {
 		delete [] dino;
 		throw;
 	}
    return dino;

}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) std::cin >> v.at(i);
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int tip_alok;
	std::cin >> tip_alok;
	n=0;
	try{
		if(tip_alok == 1) {
        	int **pokpok (AlocirajFragmentirano(v,n));
        	int period{OdrediOsnovniPeriod(v)};
         	if(period==0) period=v.size();
        	std::cout << "Dinamicki alocirana matrica:" << std::endl;
        	for(int k=0; k<n; k++)
		    	for(int i=0; i<period; i++) {
			    	for(int j=0; j<v.at(i); j++) {
				    	std::cout << std::left << std::setw(3) << pokpok[i+k*period][j];
    				}
	    			std::cout << std::endl;
		    	}
	        for(int i=0; i<period*n; i++) delete[] pokpok[i];
     	   	delete[] pokpok;      
       	}
       	else if(tip_alok == 0) {
       		std::cout << "Bice i to aBd";
       	}
  	}
	catch(const char izuzetak[]) {
		std::cout << izuzetak;
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	catch(...) {
		std::cout << "Izuzetak!";
	}
	
	return 0;
}