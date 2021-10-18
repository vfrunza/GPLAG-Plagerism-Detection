/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream> 
#include <vector>
#include <cmath>


std::vector<int> IzdvojiGadne (std::vector<int>a, bool je_li)
{
//Brisanje duplih elemenata
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a.size(); j++) {
			if((a.at(i)==a.at(j)) && (i!=j)) {
				a.erase(a.begin()+j);
				j--;
			}
		}
	}

	std::vector<int>izdvoji;

	for(auto e: a) { //Ucitavanje elementa

		int element(e); 	//pomocna varijabla
		int br_0(0); 		//brojaci cifara
		int br_1(0);
		int br_2(0);

		while(e!=0) {		//Pretvaranje elementa u bazu 3
			int x;
			x=abs(e)%3;
			(e)=(e)/3;

			if(x==0) br_0++;
			else if(x==1) br_1++;
			else if (x==2) br_2++;
		}

		if((br_2%2==0 && br_1%2==0 && br_0%2==0) && je_li==true) {	//parni brojaci --> opaki
			izdvoji.push_back(element);    
		} else if(((br_0%2!=0 || br_0==0) && (br_1%2!=0 || br_1==0) && (br_2%2!=0 || br_2==0)) && je_li==false) { //neparni brojaci ili =0 --> odvratni
			izdvoji.push_back(element);    
		}
	}

	return izdvoji;
}

int main ()
{

	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>vektor_a;
	int element;

	do {
		std::cin >> element;
		if(element==0) break;	//ako je element=0, ne treba se ubaciti u vektor
		vektor_a.push_back(element);
	} while(element!=0);

	std::vector<int>opaki (IzdvojiGadne(vektor_a, true));

	std::cout<< "Opaki: ";
	for(auto opaki_element: opaki) {

		std::cout << opaki_element << " ";
	}

	std::cout << std::endl;

	std::vector<int>gadni (IzdvojiGadne(vektor_a, false)) ;

	std::cout << "Odvratni: ";
	for(auto gadni_element: gadni) {

		std::cout << gadni_element << " ";
	}

	return 0;
}