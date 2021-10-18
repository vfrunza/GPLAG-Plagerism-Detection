/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <deque>
#include <vector>
#include <cmath>
#include <iomanip>

int SumaCifara(long long int broj) {
	broj=fabs(broj);
	int suma_cifara{};
	while(1) {
		if (broj==0) break;
		suma_cifara+=(broj%10);
		broj/=10;
	}
	return suma_cifara;
}

int SumaDjelilaca(long long int broj) {
	broj=fabs(broj);
	int suma_djelilaca{};
	for (long long int i=1; i<=broj; i++)
		if (broj%i==0) suma_djelilaca+=i;
	return suma_djelilaca;
}

int BrojProstihFaktora(long long int broj) {
	int broj_prostih_faktora{};
	broj=fabs(broj);
	if (broj==0) broj_prostih_faktora=0;
	else if (broj==1) broj_prostih_faktora=1;
	else {
		int ostatak=broj%2;
		while (ostatak==0) {
			broj_prostih_faktora++;
			broj=broj/2;
			ostatak=broj%2;
		}
		for (long long int i=3; i<=broj; i+=2) {
			int ostatak=broj%i;
			while (ostatak==0) {
				broj_prostih_faktora++;
				broj=broj/i;
				ostatak=broj%i;
			}
		}
	}
	return broj_prostih_faktora;
}

int BrojSavrsenihDjelilaca(long long int broj) {
	broj=fabs(broj);
	int broj_savrsenih_djelilaca{};
	for (long long int i=1; i<=broj; i++)
		if (broj%i==0 && (SumaDjelilaca(i)-i)==i) broj_savrsenih_djelilaca++;
	return broj_savrsenih_djelilaca;
}

template <typename TipElementa1>
bool JesuLiJednaki(TipElementa1 x1, TipElementa1 x2, double Eps=1e-10) {
	if ((x1<0 && x2>0) || (x1>0 && x2<0)) return false;
	return std::fabs(x1-x2) <= Eps*(std::fabs(x1)+std::fabs(x2));
}

template <typename TipElementa1, typename TipElementa2, typename TipElementa3, typename TipElementa4>
auto UvrnutiPresjek(TipElementa1 pocetak1, TipElementa1 kraj1, TipElementa2 pocetak2, TipElementa2 kraj2, 
					TipElementa4 funkcija_kriterija(TipElementa3)) 
					-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak2)>::type>> matrica;
	while(pocetak1!=kraj1) {
		TipElementa4 vrijednost1=funkcija_kriterija(*pocetak1);
		TipElementa2 tmp=pocetak2;
		while(tmp!=kraj2) {
			TipElementa4 vrijednost2=funkcija_kriterija(*tmp);
			if (JesuLiJednaki(vrijednost1, vrijednost2)) {
				std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni_vektor(3);
				pomocni_vektor[0]=*pocetak1;
				pomocni_vektor[1]=*tmp;
				pomocni_vektor[2]=vrijednost1;
				matrica.push_back(pomocni_vektor);
			}
			tmp++;
		}
		pocetak1++;
	}
	std::sort(matrica.begin(), matrica.end(), 
	[](typename std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> vektor1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> vektor2){
		if (!JesuLiJednaki(vektor1[2], vektor2[2])) return vektor1[2]<vektor2[2];
		else if ((JesuLiJednaki(vektor1[2], vektor2[2])) && !JesuLiJednaki(vektor1[0], vektor2[0])) return vektor1[0]<vektor2[0];
		return vektor1[1]<vektor2[1];});
	return matrica;
}

template <typename TipElementa1, typename TipElementa2>
auto UvrnutiPresjek(TipElementa1 pocetak1, TipElementa1 kraj1, TipElementa2 pocetak2, TipElementa2 kraj2)
					-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	while(pocetak1!=kraj1) {
		TipElementa2 tmp=pocetak2;
		while(tmp!=kraj2) {
			if (JesuLiJednaki(*pocetak1, *tmp)) {
				std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni_vektor(3);
				pomocni_vektor[0]=*pocetak1;
				pomocni_vektor[1]=0;
				pomocni_vektor[2]=0;
				matrica.push_back(pomocni_vektor);
			}
			tmp++;
		}
		pocetak1++;
	}
	std::sort(matrica.begin(), matrica.end(),
	[](typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vektor1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vektor2){
		return vektor1[0]<vektor2[0];});
	return matrica;
}

template <typename TipElementa1, typename TipElementa2, typename TipElementa3, typename TipElementa4>
auto UvrnutaRazlika(TipElementa1 pocetak1, TipElementa1 kraj1, TipElementa2 pocetak2, TipElementa2 kraj2,
					TipElementa4 funkcija_kriterija(TipElementa3)) 
					-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	TipElementa1 tmp1=pocetak1;
	while(tmp1!=kraj1) {
		TipElementa4 vrijednost1=funkcija_kriterija(*tmp1);
		bool pronadjen=false;
		TipElementa2 tmp2=pocetak2;
		while(tmp2!=kraj2) {
			TipElementa4 vrijednost2=funkcija_kriterija(*tmp2);
			if (JesuLiJednaki(vrijednost1, vrijednost2)) {
				pronadjen=true;
				break;
			}
			tmp2++;
		}
		if (!pronadjen) {
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni_vektor(2);
			pomocni_vektor[0]=*tmp1;
			pomocni_vektor[1]=vrijednost1;
			matrica.push_back(pomocni_vektor);
		}
		tmp1++;
	}
	while(pocetak2!=kraj2) {
		TipElementa4 vrijednost2=funkcija_kriterija(*pocetak2);
		bool pronadjen=false;
		TipElementa1 tmp=pocetak1;
		while(tmp!=kraj1) {
			TipElementa4 vrijednost1=funkcija_kriterija(*tmp);
			if (JesuLiJednaki(vrijednost1, vrijednost2)) {
				pronadjen=true;
				break;
			}
			tmp++;
		}
		if (!pronadjen) {
			std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> pomocni_vektor(2);
			pomocni_vektor[0]=*pocetak2;
			pomocni_vektor[1]=vrijednost2;
			matrica.push_back(pomocni_vektor);
		}
		pocetak2++;
	}
	std::sort(matrica.begin(), matrica.end(),
	[](typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vektor1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vektor2){
		if (!JesuLiJednaki(vektor1[0], vektor2[0])) return vektor1[0]>vektor2[0];
		return vektor1[1]>vektor2[1];});
	return matrica;
}

template <typename TipElementa1, typename TipElementa2>
auto UvrnutaRazlika(TipElementa1 pocetak1, TipElementa1 kraj1, TipElementa2 pocetak2, TipElementa2 kraj2) 
					-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	TipElementa1 tmp1=pocetak1;
	while(tmp1!=kraj1) {
		bool pronadjen=false;
		TipElementa2 tmp2=pocetak2;
		while(tmp2!=kraj2) {
			if (JesuLiJednaki(*tmp1, *tmp2)) {
				pronadjen=true;
				break;
			}
			tmp2++;
		}
		if (!pronadjen) {
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni_vektor(2);
			pomocni_vektor[0]=*tmp1;
			pomocni_vektor[1]=0;
			matrica.push_back(pomocni_vektor);
		}
		tmp1++;
	}
	while(pocetak2!=kraj2) {
		bool pronadjen=false;
		TipElementa1 tmp=pocetak1;
		while(tmp!=kraj1) {
			if (JesuLiJednaki(*tmp, *pocetak2)) {
				pronadjen=true;
				break;
			}
			tmp++;
		}
		if (!pronadjen) {
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni_vektor(2);
			pomocni_vektor[0]=*pocetak2;
			pomocni_vektor[1]=0;
			matrica.push_back(pomocni_vektor);
		}
		pocetak2++;
	}
	std::sort(matrica.begin(), matrica.end(),
	[](typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vektor1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vektor2){
		return vektor1[0]>vektor2[0];});
	return matrica;
}

int main () {
	int broj_elemenata1{};
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> broj_elemenata1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	std::deque<int> dek1(broj_elemenata1);
	int unesena_vrijednost{};
	for (int i=0; i<broj_elemenata1; i++) {
		std::cin >> unesena_vrijednost;
		bool pronadjen=false;
		for (int k=0; k<dek1.size(); k++)
			if (JesuLiJednaki(unesena_vrijednost, dek1[k])) {
				pronadjen=true;
				break;
			}
		if (!pronadjen) dek1[i]=unesena_vrijednost;
		else i--;
	}
	int broj_elemenata2{};
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> broj_elemenata2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	std::deque<int> dek2(broj_elemenata2);
	for (int i=0; i<broj_elemenata2; i++) {
		std::cin >> unesena_vrijednost;
		bool pronadjen=false;
		for (int k=0; k<dek1.size(); k++)
			if (JesuLiJednaki(unesena_vrijednost, dek2[k])) {
				pronadjen=true;
				break;
			}
		if (!pronadjen) dek2[i]=unesena_vrijednost;
		else i--;
	}
	std::vector<std::vector<int>> uvrnuti_presjek = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	std::vector<std::vector<int>> uvrnuta_razlika = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	std::cout << "Uvrnuti presjek kontejnera: \n";
	for (int i=0; i<uvrnuti_presjek.size(); i++) {
		for (int j=0; j<uvrnuti_presjek[i].size(); j++)
			std::cout << std::right << std::setw(6) << uvrnuti_presjek[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera: \n";
	for (int i=0; i<uvrnuta_razlika.size(); i++) {
		for (int j=0; j<uvrnuta_razlika[i].size(); j++)
			std::cout << std::right << std::setw(6) << uvrnuta_razlika[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}