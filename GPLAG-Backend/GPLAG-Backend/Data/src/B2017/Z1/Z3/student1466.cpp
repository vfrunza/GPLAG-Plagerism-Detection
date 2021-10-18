#include <iostream>
#include <vector>
#include <deque>
typedef std::deque<std::vector<int>> NizPodnizova;
enum Smjer { Rastuci=1, Opadajuci};
bool StepenDvojke(int broj)
{
    int temp(broj);
    if(temp<0) {
        temp*=-1;
    }
    if(temp==1) return true;
    if(temp==0) return false;
    while(temp!=1) {
        if(temp%2==1) return false;
        temp/=2;
    }
    return true;
}
std::vector<int> MaksimalniPodnizoviStepenaDvojke (std::vector<int> niz/*, Smjer monotonost*/)
{
    NizPodnizova podnizovi;
    int pocetak;
    int novi;
    std::vector<int> temp;
    for(int i=0; i<niz.size(); i++) {
        if(i<niz.size()-1) {
            int sljedeci(niz.at(i+1));
            if(StepenDvojke(niz.at(i)) && StepenDvojke(sljedeci)) {
                if(niz.at(i)<sljedeci) {
                    temp.push_back(niz.at(i));
                    temp.push_back(sljedeci);
                    i++;
                }

            }

        }
    }
    return temp;    
}
int main ()
{    
	std::cout << "Unesite broj elemenata vektora: "    
	int broj_el    
	std::cin >> broj_el    
	std::vector<int> niz    
	std::cout << "Unesite elemente vektora: " << std::endl    
	for(int i=0; i<broj_el; i ++)    
	    int broj    
	    std::cin>>broj   
	     niz.push_back(broj)    
	    }
/*	std::cout <<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: "    ;
	std::cin >> e    ;
	Smjer prekidac    ;
	prekidac=Smjer(e)    ;
	std::cout << StepenDvojke(broj_el) << std::endl;*    
	std::vector<int> c=MaksimalniPodnizoviStepenaDvojke(niz)    
	for(auto red :  c)  
	        std::cout << red<<" "


	 }  
	 
	/*if(StepenDvojke(niz.at(i))){
            pocetak=i;
            while(StepenDvojke(niz.at(i)) && i<niz.size()-1) i++;
            int kraj=i;
            if(kraj-pocetak>0){
                for(int j=pocetak; j<kraj; j++){
                    for(int k=j+1; k<kraj; k++)   
                    }
                }
               
        }*


    
	return 0;
}