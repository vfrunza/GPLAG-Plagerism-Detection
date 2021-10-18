#include <iostream>
#include <deque>
#include <cmath>

typedef std::deque<std::deque<int>> DekVektora;
typedef std::deque<int> Dek;
enum Smjer {
    Rastuci=1,
    Opadajuci=2

} rasti_padaj;
bool JeliKvadrat(int n)
{
	float broj(n);
	if(broj<=0 || broj==10) return false;
	long long test=sqrt(broj);
	if(test%1==0) return true;
	return false;
}
bool ProvjeriJelPodnizNekogDrugogNiza(DekVektora dekvektora,int n)
{
	for(int i=0; i<dekvektora.size(); i++) {
		for(int j=0; j<dekvektora.at(i).size(); j++) {
			if (n==dekvektora.at(i).at(j))
				return false;
		}
	}
	return true;
}
DekVektora MaksimalniPodnizoviStepenaDvojke(Dek vekt_cijelih_brojeva,Smjer rasti_padaj)
{

	DekVektora nikoJaciOdMene;

	// za rastuce od manjih ka vecim
	if(rasti_padaj==Rastuci) {
		int minimalac;
		int zapamti_indeks;
		Dek dodjiDaTiPomognem;
		for(int i=0; i<vekt_cijelih_brojeva.size(); i++) {
			if(JeliKvadrat(vekt_cijelih_brojeva.at(i))) {
				minimalac=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(minimalac);
				zapamti_indeks=i;
				break;

			}
		}
		for(int i=zapamti_indeks; i<vekt_cijelih_brojeva.size(); i++) {
			if(i!=zapamti_indeks && JeliKvadrat(vekt_cijelih_brojeva.at(i)) && vekt_cijelih_brojeva.at(i)>minimalac ) {
				minimalac=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(minimalac);
				continue;
			} else if(i!=zapamti_indeks && dodjiDaTiPomognem.size()==1 && JeliKvadrat(vekt_cijelih_brojeva.at(i)) && vekt_cijelih_brojeva.at(i)<=minimalac ) {
				minimalac=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.resize(0);
				dodjiDaTiPomognem.push_back(minimalac);
				continue;
			} else if(i!=zapamti_indeks && dodjiDaTiPomognem.size()>1 && JeliKvadrat(vekt_cijelih_brojeva.at(i)) && vekt_cijelih_brojeva.at(i)<=minimalac ) {
				nikoJaciOdMene.push_back(dodjiDaTiPomognem);
				dodjiDaTiPomognem.resize(0);
				minimalac=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(minimalac);



			}

		}
	}
	// za opadajuce od manjeg ka vecim
	if(rasti_padaj==Opadajuci) {
		int velikiSam;
		int zapamti_indeks;
		Dek dodjiDaTiPomognem;
		for(int i=0; i<vekt_cijelih_brojeva.size(); i++) {
			if(JeliKvadrat(vekt_cijelih_brojeva.at(i))) {
				velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
				zapamti_indeks=i;
				break;

			}
		}
		for(int i=zapamti_indeks; i<vekt_cijelih_brojeva.size(); i++) {
			if(i==vekt_cijelih_brojeva.size()-2 && JeliKvadrat(vekt_cijelih_brojeva.at(i+1))==false && vekt_cijelih_brojeva.at(i-1)>vekt_cijelih_brojeva.at(i)){
					velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
					nikoJaciOdMene.push_back(dodjiDaTiPomognem);
				return nikoJaciOdMene;
			}
			if(i==vekt_cijelih_brojeva.size()-1 && JeliKvadrat(vekt_cijelih_brojeva.at(i)) && velikiSam>vekt_cijelih_brojeva.at(i)){
					velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
					nikoJaciOdMene.push_back(dodjiDaTiPomognem);
				return nikoJaciOdMene;
			}
			if((JeliKvadrat(vekt_cijelih_brojeva.at(i))==false && vekt_cijelih_brojeva.at(i)<velikiSam && (i+1<=vekt_cijelih_brojeva.size()-1 )  && dodjiDaTiPomognem.size()>1)) {
				nikoJaciOdMene.push_back(dodjiDaTiPomognem);
				dodjiDaTiPomognem.resize(0);
				i++;
				velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
			} else if (JeliKvadrat(vekt_cijelih_brojeva.at(i))==false && vekt_cijelih_brojeva.at(i)<velikiSam && i+1<=vekt_cijelih_brojeva.size()-1  && dodjiDaTiPomognem.size()==1) {
				dodjiDaTiPomognem.resize(0);
				i++;
				velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
			} else if(JeliKvadrat(vekt_cijelih_brojeva.at(i))==false && i+1>=vekt_cijelih_brojeva.size()-1 || i==vekt_cijelih_brojeva.size() && dodjiDaTiPomognem.size()==1) {
			return nikoJaciOdMene;
		}


		if(i!=zapamti_indeks && JeliKvadrat(vekt_cijelih_brojeva.at(i)) && vekt_cijelih_brojeva.at(i)<velikiSam  ) {
			velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
				continue;
			} else if(i!=zapamti_indeks && dodjiDaTiPomognem.size()==1 && vekt_cijelih_brojeva.at(i)>=velikiSam && JeliKvadrat(vekt_cijelih_brojeva.at(i))) {
			velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.resize(0);
				dodjiDaTiPomognem.push_back(velikiSam);
				continue;
			} else if(i!=zapamti_indeks && dodjiDaTiPomognem.size()>1  && vekt_cijelih_brojeva.at(i)>=velikiSam && JeliKvadrat(vekt_cijelih_brojeva.at(i))) {
			nikoJaciOdMene.push_back(dodjiDaTiPomognem);
				dodjiDaTiPomognem.resize(0);
				velikiSam=vekt_cijelih_brojeva.at(i);
				dodjiDaTiPomognem.push_back(velikiSam);
			}



		}
	}
	return nikoJaciOdMene;

}
int main ()
{

	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::deque<int> glavni_niz;
	std::cout<<"Unesite elemente vektora: ";

	for (int i=0; i<n; i++) {
		int broj;
		std::cin>>broj;
		glavni_niz.push_back(broj);

	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";

	Smjer rasti_padaj;
	int unos;
	std::cin >> unos;
	rasti_padaj=Smjer(unos);
	DekVektora kraj(MaksimalniPodnizoviStepenaDvojke(glavni_niz,rasti_padaj));
	if(unos==1) {
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout <<std::endl;
	} else {
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout <<std::endl;
	}

	for(int i=0; i<kraj.size(); i++) {

		for(int j=0; j<kraj.at(i).size(); j++) {
			std::cout<<kraj.at(i).at(j)<<" ";
		}
		std::cout <<std::endl;
	}
	return 0;
}