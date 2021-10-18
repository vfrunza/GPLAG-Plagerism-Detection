/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> Vvektor;

Vvektor RastuciPodnizovi(std::vector<double> x){
	Vvektor povratni;
	int brojac(0);
	for(int i=(0);i<x.size();i++)
	{
	    if(i==(x.size()-1))break;
		int brojac2(0);
		while(x[i+1]-x[i]>=-(0.00000000000001)){
				if(brojac2==0){
                    brojac++;
					povratni.resize(brojac);
					brojac2++;
				}
				povratni[brojac-1].push_back(x[i]);
		i++;
		if(i==(x.size()-1))break;
		}
		if(brojac2!=0)povratni[brojac-1].push_back(x[i]);
	}
return povratni;
}
Vvektor OpadajuciPodnizovi(std::vector<double> x){
	Vvektor povratni;
	int brojac(0);
	for(int i=(0);i<x.size();i++)
	{
    if(i==(x.size()-1))break;
		int brojac2(0);
		while(x[i+1]-x[i]<=0.0000000000001){
				if(brojac2==0){
                    brojac++;
					povratni.resize(brojac);
					brojac2++;
				}
				povratni[brojac-1].push_back(x[i]);
		i++;
		if(i==(x.size()-1))break;
		}
		if(brojac2!=0)povratni[brojac-1].push_back(x[i]);
	}
return povratni;
}
int main ()
{
	int a;
	double broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;
	if(a<0){
        std::cout<<"Broj elemenata vektora moraja biti nenegativan!";
        return 0;
	}
	std::vector<double> x;
	x.resize(a);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<a;i++){
		std::cin>>broj;
		x[i]=broj;
	}
	Vvektor rastuci;
	Vvektor opadajuci;
	rastuci=RastuciPodnizovi(x);
	opadajuci=OpadajuciPodnizovi(x);
	if(rastuci.size()!=0){
	std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
    for(auto i:rastuci){
		for(auto j:i){
			std::cout<<std::setprecision(30)<<j<<" ";
		}
		std::cout<<std::endl;
	}
	}
	if(opadajuci.size()!=0){
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(auto i:opadajuci){
		for(auto j:i){
			std::cout<<std::setprecision(30)<<j<<" ";
		}
		std::cout<<std::endl;
	}
	}
	return 0;
}
