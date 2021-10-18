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
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <algorithm>
template < typename NekiTipVek>
bool DaLiJePeriodican(NekiTipVek v, int period)
{
	int velicina=v.size();
	int i(0);
	if(period==0 ||velicina==1 || velicina==0) return false;
	if((i+period)>velicina) return false;
	for( int i=0; i<(velicina-period); i++)
		if(v[i]!=v[i+period]) return false;
	return true;

}
template <typename NekiTipVek>
int OdrediOP( NekiTipVek v)
{
	int period(1);
	while(period<v.size()) {
		if(DaLiJePeriodican(v,period)!=0) return period;
		period++;

	}
	return 0;
}
template <typename Tip>
int **AlocirajFragmentirano( const std::vector<Tip> &v, int &koliko_puta)
{
	if (v.size()==0) {
		throw std::domain_error("Prazan vektor!");
	}
	for (int i=0; i<v.size(); i++) {
		if (v[i]<=0) {
			throw std::domain_error("Neispravan vektor!");
			break;

		}
	}
	int period(OdrediOP(v));
	if(DaLiJePeriodican(v,period)!=0) {
		Tip broj=(v[period-1]);
		koliko_puta=0;
		for( int i=0; i<v.size(); i++) {
			if(v[i]==broj) koliko_puta++;

		}
		if(v.size()%period!=0) koliko_puta++;

	} else if(DaLiJePeriodican(v,period)==0) {
		koliko_puta=2;
	}
	Tip **matrica(nullptr);
	int nova_vel(0);
	if (koliko_puta==2 && v.size()%koliko_puta!=0  && period!=0) nova_vel=(v.size()+koliko_puta-1);
	else if(koliko_puta==2 && v.size()%koliko_puta!=0 && period==0) {
		nova_vel=v.size()*2;
		period=v.size();
	} else if(koliko_puta>=2 && v.size()%koliko_puta==0 && period!=0) nova_vel=v.size();
	try {
		matrica=new Tip*[nova_vel];
		int j(0);
		while(j<nova_vel) {
			for( int i=0; i<period; i++) {
				int velicina=v[i];
				matrica[j]=new Tip[velicina];
				j++;
			}

		}
		int k(0);
		while(k<nova_vel) {
			for( int i=0; i<period; i++) {
				Tip element(*std::max_element(v.begin(),v.end()));
				for( int j=v[i]-1; j>=0; j--) {
					matrica[k][j]=element;
					element--;

				}
				k++;

			}


		}

	} catch(...) {
		for( int i=0; i<nova_vel; i++) delete[] matrica[i];
		delete[] matrica;
		throw;
	}
	return matrica;

}
template <typename Tip>
int **AlocirajKontinualno(const std::vector<Tip> &v, int &koliko_puta)
{
	if (v.size()==0) throw std::domain_error("Prazan vektor!");
	for( int i=0; i<v.size(); i++) {
		if(v[i]<=0) {
			throw std::domain_error("Neispravan vektor!");
			break;
		}
	}
	int period(OdrediOP(v));
	if(DaLiJePeriodican(v,period)!=0) {
		Tip broj=v[period-1];
		koliko_puta=0;
		for( int i=0; i<v.size(); i++) {
			if(v[i]==broj) koliko_puta++;
			
		}
		if(v.size()%period!=0) koliko_puta++;



	} else if(DaLiJePeriodican(v,period)==0) {
		koliko_puta=2;
	}
	int nova_vel(0);
	if(koliko_puta==2 && v.size()%koliko_puta!=0 && period!=0) nova_vel=v.size()+koliko_puta-1;

	else if(koliko_puta==2 && v.size()%koliko_puta!=0 && period==0) {
		nova_vel=v.size()*2;
		period=v.size();
	} else if(koliko_puta>=2 && v.size()%koliko_puta==0 && period!=0) nova_vel=v.size();

Tip **matrica(nullptr);
	int broj_elemenata(0);
	int p(0);
	while(p<nova_vel) {
		for( int i=0; i<period; i++) {
				broj_elemenata+=v[i];
				p++;
			}
			
		}

	
	try {
	matrica=new Tip*[nova_vel+1];
		matrica[0]=new Tip[broj_elemenata];
		int s(1);
		do {
			for(int i=1; i<=period; i++) {
				Tip br(v[i-1]);
				matrica[s]=matrica[i-1]+br; 
			s++;
			}
		}while((s+1)<nova_vel);
		s=0;
		while(s<nova_vel){
			for( int i=0; i<period; i++){
				Tip element(v[i]);
				for( int j=0; j<v[i]; j++){
					matrica[s][j]=element;
					element--;
				}
				s++;
			}
		}
	} catch(...) {
		delete[] matrica[0];
		delete[] matrica;
		throw;
	}
	return matrica;
}
int main ()
{
	try {
		int broj_elemenata(0);
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>broj_elemenata;
		std::vector<int>v(broj_elemenata);
		std::cout<<"Unesite elemente vektora: ";
		for( int i=0; i<broj_elemenata; i++) {
			std::cin>>v[i];
		}
		int pomocni_period(OdrediOP(v));
		int biraj(0),period1(0), period2(0);
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin>>biraj;
		if(biraj==1) {
			auto *v_fragmentirano(AlocirajFragmentirano(v, period1));
			std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
			int nova_vel(0);
			if(period1==2 && v.size()%period1!=0 && pomocni_period==0) {
				nova_vel=v.size()*2;
				pomocni_period=v.size();

			} else if(period1==2 && v.size()%period1!=0 && pomocni_period!=0) nova_vel=v.size()+period1-1;
			else if(period1>=2 && v.size()%period1==0 && pomocni_period!=0 ) nova_vel=v.size();
			int k(0);
			while( k<nova_vel) {
				for( int i=0; i<pomocni_period; i++) {
					int velicina(v[i]);
					for(int j=0; j<velicina; j++) {
						std::cout<<std::fixed<<std::left<<std::setw(3)<<v_fragmentirano[k][j];
					}
					k++;
					std::cout<<std::endl;
				}

			}
			for( int i=0;  i<nova_vel; i++) delete[] v_fragmentirano[i];
			delete[] v_fragmentirano;

		} else if(biraj==0) {
			auto v_kontinualno(AlocirajKontinualno(v, period2));
			std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
			int nova_vel(0);
			if(v.size()%period2==0 && period2>=2 && pomocni_period!=0) nova_vel=v.size();
			else if(period2==2 && v.size()%period2!=0 && pomocni_period!=0) nova_vel=v.size()+period2-1;
			else if(period2==2 && v.size()%period2!=0 && pomocni_period==0) {
				nova_vel=v.size()*2;
				pomocni_period=v.size();
			}
			int k(0);
			while(k<nova_vel) {
				for( int i=0; i<pomocni_period; i++) {
					int velicina(v[i]);
					for(int j=0; j<velicina; j++) {
						std::cout<<std::fixed<<std::left<<std::setw(3)<<v_kontinualno[k][j];

					}
					k++;
					std::cout<<std::endl;

				}

			}
			delete[] v_kontinualno[0];
			delete[] v_kontinualno;
		}
	} catch(std::domain_error izuzetak1) {
		std::cout<<"Izuzetak: "<<izuzetak1.what()<<std::endl;
	}
	return 0;
}