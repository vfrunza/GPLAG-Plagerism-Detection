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
#include <stdexcept>
#include <type_traits>

template<typename Tiiip>
int Period(const std::vector<Tiiip> &v)
{
	int period(0);
	bool jest=true;

	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if((i+1)!=v.size() && v.at(i)==v.at(j)) {
				int h=j;
				int k=i;

				do {
					if(h!=v.size() && v.at(k)!=v.at(h)) {
						jest=false;
						break;
					}

					h++;
					k++;
				} while(h!=v.size());

				if(jest) {
					period=j-i;
					break;
				}
			}

		}
	}

	return period;
}

template<typename Tip1>
auto AlocirajFragmentirano(const std::vector<Tip1> &v, int &koliko_puta)-> Tip1 ** {
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)<=0)
			throw std::domain_error("Neispravan vektor!");
	}
	if(v.size()==0)
	throw "Prazan vektor!";
	
	int period=Period(v);

	koliko_puta=0;
	Tip1** dupli=nullptr;

	Tip1 najveci(0);
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)>najveci)
			najveci=v.at(i);
	}

	//slucaj1
	if(period!=0) {
		for(int i=0; i<v.size(); i+=period)
			koliko_puta++;

		dupli=new Tip1*[koliko_puta*period];

		for(int i=0; i<koliko_puta*period; i++)
			dupli[i]=nullptr;

		try {
			int j=0;
			for(int i=0; i<koliko_puta*period; i++) {
				dupli[i]=new Tip1[v.at(j)];
				j++;
				if(j==period)
					j=0;
			}
		} catch(...) {
			for(int i=0; i<koliko_puta*period; i++)
				delete [] dupli[i];

			delete[] dupli;
			throw;
		}

		int l=0;
		for(int i=0; i<period*koliko_puta; i++) {
			int k=0;
			for(int j=v.at(l)-1; j>=0; j--) {
				dupli[i][j]=najveci-v.at(k)+1;
				k++;
			}
			l++;
			if(l==period)
				l=0;
		}
	}

	//slucaj2
	if(period==0) {
		koliko_puta=2;
		period=v.size();

		dupli=new Tip1*[koliko_puta*period];

		for(int i=0; i<koliko_puta*period; i++)
			dupli[i]=nullptr;

		try {
			int j=0;
			for(int i=0; i<koliko_puta*period; i++) {
				dupli[i]=new Tip1[v.at(j)];
				j++;
				if(j==period)
					j=0;
			}
		} catch(...) {
			for(int i=0; i<koliko_puta*period; i++)
				delete [] dupli[i];

			delete[] dupli;
			throw;
		}

		int l=0;
		for(int i=0; i<period*koliko_puta; i++) {
			int k=0;
			for(int j=v.at(l)-1; j>=0; j--) {
				dupli[i][j]=najveci-v.at(k)+1;
				k++;
			}
			l++;
			if(l==period)
				l=0;
		}
	}
	return dupli;
}

template<typename Tip1>
auto AlocirajKontinualno(const std::vector<Tip1> &v, int &koliko_puta) -> Tip1 ** 
{
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)<=0)
			throw std::domain_error("Neispravan vektor!");
	}
	if(v.size()==0)
	throw "Prazan vektor!";

	int period=Period(v);

	koliko_puta=0;
	Tip1** dupli=nullptr;

	Tip1 najveci(0);
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)>najveci)
			najveci=v.at(i);
	}

	if(period!=0) {
		for(int i=0; i<v.size(); i+=period)
			koliko_puta++;
	
		dupli=new Tip1*[koliko_puta*period];

		for(int i=0; i<koliko_puta*period; i++)
			dupli[i]=nullptr;

		try {
			int duzina(0);

			for(int i=0; i<v.size(); i++)
				duzina+=v.at(i);

			duzina*=koliko_puta;

			dupli[0]=new Tip1[duzina];

			int j=0;
			for(int i=1; i<koliko_puta*period; i++) {
				dupli[i]=dupli[i-1]+v.at(j);                /////DOBRA RASPODJELA POKAZIVACA???
				j++;
				if(j==period)
					j=0;
			}

		} catch(...) {
			delete[] dupli;
			throw;
		}

		int l=0;
		for(int i=0; i<period*koliko_puta; i++) {
			int k=0;
			for(int j=v.at(l)-1; j>=0; j--) {
				dupli[i][j]=k+1;
				k++;
			}
			l++;
			if(l==period)
				l=0;
		}
	}

	//slucaj2-kontinualna
	if(period==0)
	{
		koliko_puta=2;
		period=v.size();
	
		dupli=new Tip1*[koliko_puta*period];

		for(int i=0; i<koliko_puta*period; i++)
			dupli[i]=nullptr;

		try {
			int duzina(0);

			for(int i=0; i<v.size(); i++)
				duzina+=v.at(i);

			duzina*=koliko_puta;

			dupli[0]=new Tip1[duzina];

			int j=0;
			for(int i=1; i<koliko_puta*period; i++) {
				dupli[i]=dupli[i-1]+v.at(j);             
				j++;
				if(j==period)
					j=0;
			}

		} catch(...) {
			delete[] dupli;
			throw;
		}

		int l=0;
		for(int i=0; i<period*koliko_puta; i++) {
			int k=0;
			for(int j=v.at(l)-1; j>=0; j--) {
				dupli[i][j]=k+1;
				k++;
			}
			l++;
			if(l==period)
				l=0;
		}
	}
	return dupli;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int br_el;
	std::cin>>br_el;

	try {
		std::vector<int> v(br_el);
		std::cout<<"Unesite elemente vektora: ";
		for(int i=0; i<v.size(); i++)
			std::cin>>v.at(i);

		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int odabir;
		std::cin>>odabir;
		
		int koliko_puta;
		int period=Period(v);
		
		if(period==0) {
		koliko_puta=2;
		period=v.size();}

		if(odabir==1) {
			auto dupli=AlocirajFragmentirano(v, koliko_puta);
			int l=0; 
			std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
			for(int i=0; i<period*koliko_puta; i++) {
				int k=0;
				for(int j=0; j<v.at(l); j++) {
					std::cout<<dupli[i][j]<<"  ";
					k++;
				}
				l++;
				if(l==period)
					l=0;
				std::cout<<std::endl;
			}
			for(int i=0; i<period*koliko_puta; i++) delete[] dupli[i];
			delete[] dupli;
		}
		else if(odabir==0) {
			auto dupli=AlocirajKontinualno(v, koliko_puta);
			int l=0;
			std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
			for(int i=0; i<period*koliko_puta; i++) {
				int k=0;
				for(int j=0; j<v.at(l); j++) {
					std::cout<<dupli[i][j]<<"  ";
					k++;
				}
				l++;
				if(l==period)
					l=0;
				std::cout<<std::endl;
			}
			
			delete[] dupli[0];
			delete[] dupli;
		}

	} 
	catch(std::domain_error poruka)
	{
		std::cout<<"Izuzetak: "<<poruka.what();
	}
	catch(const char poruka2[])
	{
			std::cout<<"Izuzetak: "<<poruka2;
	}

	return 0;
}