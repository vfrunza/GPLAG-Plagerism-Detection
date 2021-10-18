/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>

template <typename CjelobrojniTip>
auto AlocirajFragmentirano(std::vector<CjelobrojniTip> &v,int &koliko_puta) -> typename std::remove_reference<decltype(v.at(0))>::type** {
	if(v.size()==0) throw ("Prazan vektor!");
	int brojac(0);
	int Period(0);
	typename std::remove_reference<decltype(v.at(0))>::type max(v.at(0));
	for(int i=0; i<v.size(); i++) if(v.at(i)>max) max=v.at(i);
	for (int i = 1; i < v.size(); i++) {
		if(v.size()==1) break;
		int j(0);
		for( j=0; j<v.size()-i; j++) if(v.at(j)!=v.at(j+i)) break;
		if(j==v.size()-i) {
			Period=i;
			break;
		}
	}
	for (int i = v.size()-Period; i < Period; i++) brojac++;
	if(v.size()%Period==0) brojac=0;
	if(Period==0) brojac=v.size();

	koliko_puta=(v.size()+brojac)/Period;

	typename std::remove_reference<decltype(v.at(0))>::type** Glavni(nullptr);
	try{
		Glavni=new typename std::remove_reference<decltype(v.at(0))>::type*[v.size()+brojac]{};

		int Pozicija(0);
		for(int j=0; j<koliko_puta; j++) {
			for(int k=0; k<Period; k++) {
				Glavni[Pozicija]=new typename std::remove_reference<decltype(v.at(0))>::type [v.at(k)];
				Pozicija++;
			}
		}

		int velicina(0);
		Pozicija=0;
		int tempmax(max);
		for(int j=0; j<koliko_puta; j++) {
			for(int k=0; k<Period; k++) {
				velicina=v.at(k);
				tempmax=max;
				for(int m=velicina-1;m>=0;m--){
					Glavni[Pozicija][m]=max;
					tempmax--;
				}
				Pozicija++;
			}
		}

	} catch(std::bad_alloc) {
		for(int i=0; i<v.size()+brojac; i++) delete[] Glavni[i];
		delete Glavni;
	}
	return Glavni;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	int m;
	std::cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) std::cin>>v.at(i);
	int **poki(AlocirajFragmentirano(v,m));
	std::cout<<"Koliko puta mi iznosi "<<m<<std::endl;
	std::cout<<std::endl<<"matrica izgleda vako: ";
	
    for(int i=0;i<n;)
	return 0;
}