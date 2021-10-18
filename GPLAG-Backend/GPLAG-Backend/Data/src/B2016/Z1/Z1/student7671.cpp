/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>



std::vector<int> IzdvojiGadne (std::vector<int> v, bool dalije){
    std::vector<int> Opaki, Odvratni;
    for(int i=0; i<v.size(); i++){
        int kopija=v[i], brojac1(0), brojac2(0), brojac0(0),ostatak;
        while(kopija!=0){
        	ostatak=kopija%3;
        	if(ostatak==1)
        		brojac1++;
        	else if(ostatak==2)
        		brojac2++;
        	else if(ostatak==0)
        		brojac0++;
        	kopija/=3;
        }
        if((brojac0%2==0 && brojac1%2==0 && brojac2%2==0) || (brojac0%2==0 && brojac1==0 && brojac2==0) || (brojac0%2==0 && brojac1%2==0 && brojac2==0) || (brojac0==0 && brojac1%2==0 && brojac2%2==0) || (brojac0==0 && brojac1%2==0 && brojac2==0) || (brojac0==0 && brojac1==0 && brojac2%2==0)){
        	int jest(1), kopija(v[i]);
        	for(int i=0; i<Opaki.size(); i++){
        		if(Opaki[i]==kopija)
        			jest=0;
        	}
        	if(jest)
        		Opaki.push_back(v[i]);
        }
        else if((brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0) || (brojac0%2!=0 && brojac1==0 && brojac2==0) || (brojac0%2!=0 && brojac1%2!=0 && brojac2==0) || (brojac0==0 && brojac1%2!=0 && brojac2%2!=0) || (brojac0==0 && brojac1%2!=0 && brojac2==0) || (brojac0==0 && brojac1==0 && brojac2%2!=0)){
        	int jest(1), kopija(v[i]);
        	for(int i=0; i<Odvratni.size(); i++){
        		if(Odvratni[i]==kopija)
        			jest=0;
        	}
        	if(jest)
        		Odvratni.push_back(v[i]);
        	
        }
    }
    if(dalije)
    	return Opaki;
   	else
   		return Odvratni;
}




void Ispisi(std::vector<int> v){
	for(int i=0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
}

int main ()
{
	std::vector<int> v;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(int i=0; i<1000; i++){
		std::cin>>n;
		v.push_back(n);
		if(v[i]==0)
			break;
	}
	v.resize(v.size()-1);
	std::cout<<"Opaki: ";
	Ispisi(IzdvojiGadne(v,true));
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	Ispisi(IzdvojiGadne(v,false));
	return 0;
}