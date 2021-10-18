/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

int ponavljanjeCifara(int n) {	//0 nijedno br ponavljnanja, 2 paran, 1 neparan
	if(n == 0)
		return 1;
	std::vector<int>v(3,0);
	while(n != 0) {//
		int cifra = std::abs(n%3);
		v.at(cifra)++;
		n/=3;
	}
	bool paran(true), neparan(true);
	for(int i=0; i<3; i++) {
		if( v.at(i)%2 != 0)
			paran=false;
		if(v.at(i) != 0 && v.at(i) %2 == 0)
			neparan=false;
		}
	if(paran)	return 2;
	if(neparan)	return 1;
	return 0;

}

bool povratni_pojavljivanje(std::vector<int> v, int n) {
	for(int i=0; i<v.size(); i++)
		if(v.at(i)==n)
			return true;
	return false;
}

std::vector<int>IzdvojiGadne(std::vector<int> v, bool parnost) {
	std::vector<int> v_povratni;
	for(int i=0; i<v.size(); i++)
		if(((ponavljanjeCifara(v.at(i)) ==2 && parnost) || (ponavljanjeCifara(v.at(i))==1 && !parnost)) && !povratni_pojavljivanje(v_povratni, v.at(i)))
			v_povratni.push_back(v.at(i));
	
	
	return v_povratni;
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;) {
		int tmp;
		std::cin>>tmp;
		if(tmp == 0 && std::cin)
			break;
		else if(!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
		v.push_back(tmp);
	}
	std::vector<int> tmp(IzdvojiGadne(v, true));
	std::cout<<"Opaki: ";
	for(int i=0; i<tmp.size(); i++)
		std::cout<<tmp.at(i)<<" ";
	std::cout<<"\nOdvratni: ";
	tmp = IzdvojiGadne(v, false);
	for(int i=0; i<tmp.size(); i++)
		std::cout<<tmp.at(i)<<" ";


	return 0;
}
