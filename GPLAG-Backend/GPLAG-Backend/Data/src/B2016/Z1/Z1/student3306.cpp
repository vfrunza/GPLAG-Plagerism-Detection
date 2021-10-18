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
#include <limits>

std::vector<int> IzdvojiGadne(std::vector<int> a, bool istinitost){
	std::vector<int> OpakiVekt;
	std::vector<int> OdvratniVekt;
	std::vector<int> PrazanVekt;
	if (a.size()==0)
		return a;
	for (int i=0;i<a.size()-1;i++){
		for (int j=i+1;j<a.size();j++){
			if (a[i]==a[j]){
				a.erase(a.begin()+j);
				j--;
			}
		}
	}
	for (int i=0;i<a.size();i++){
		std::vector<int> PomVekt{0,0,0};
		int tmp(a[i]);
		int ostatak1;
		while (tmp!=0){
			ostatak1=tmp%3;
			tmp=tmp/3;
			PomVekt[std::abs(ostatak1)]++;
		}
		bool opaki(false);
		for (int i=0;i<3;i++){
			if (PomVekt[i]==0)
				continue;
			else if (PomVekt[i]%2==0){
				opaki=true;
			}
			else if (PomVekt[i]%2!=0){
				opaki=false;
				break;
			}
		}
		bool odvratni(false);
		for (int i=0;i<3;i++){
			if (PomVekt[i]==0)
				continue;
			else if (PomVekt[i]%2==0){
				odvratni=false;
				break;
			}
			else if (PomVekt[i]%2!=0){
				odvratni=true;
			}
		}
		if (opaki==true)
			OpakiVekt.push_back(a[i]);
		else if (odvratni==true)
			OdvratniVekt.push_back(a[i]);
	}
		

	if (istinitost==true)
		return OpakiVekt;
	else if (istinitost==false)
		return OdvratniVekt;
	else
		return PrazanVekt;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int brojevi;
	std::vector<int> a;
	while(1){
		std::cin >> brojevi;
		if (brojevi==0)
			break;
		a.push_back(brojevi);
	}

	std::vector<int> b;
	b=IzdvojiGadne(a,true);
	std::cout << "Opaki: ";
	for (int i=0;i<b.size();i++){
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> c;
	c=IzdvojiGadne(a,false);
	std::cout<< "Odvratni: ";
	for (int i=0;i<c.size();i++)
		std::cout << c[i] << " " ;
	std::cout << std::endl;
	return 0;
}