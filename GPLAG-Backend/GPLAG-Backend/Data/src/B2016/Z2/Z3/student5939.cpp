/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <deque>
#include <iomanip>

// broj ne smije pocinjati nulom
int SumaCifara(long long int broj) {
	
	int rezultat{};
	broj = fabs(broj);
	
	while (broj != 0) {
		rezultat = rezultat + (broj % 10);
		broj = broj / 10;
	}
	
	return rezultat;
	
	
}


int SumaDjelilaca(long long int broj) {
	
	int rezultat = 0;
	broj = fabs(broj);
	
	for (long long int i = 1; i <= broj; i++) {
		
		if (broj % i == 0) 
		    rezultat = rezultat + i;
		    
	}
	return rezultat;
}

int BrojProstihFaktora(long long int broj) {
	int rezultat {};
	broj = fabs(broj);
	
	if (broj == 0)
	    rezultat = 0;
	else if (broj == 1) 
	    rezultat = 1;
	else {
		int ostatak = broj % 2;
		
		while (ostatak == 0) {
			rezultat = rezultat + 1;
			broj = broj / 2;
			ostatak = broj % 2;
			
		}
		
		for (long long int i=3; i <= broj; i = i + 2) {
			int ostatak = broj % i;
			
			while (ostatak == 0) {
				rezultat++;
				broj = broj / i;
				ostatak = broj % i;
			}
		}
	}
	
	return rezultat;
}


int BrojSavrsenihDjelilaca(long long int broj) {
	int rezultat {};
	broj = fabs(broj);
	
	for (long long int i = 1; i <= broj; i++) {
		int suma = SumaDjelilaca(i) - i;
		
		if (suma == i && broj % i == 0)
		    rezultat++;
		    
	}
	
	return rezultat;
}


template <typename T1>

bool Jednaki(T1 x, T1 y, double eps = 1e-10) {
	bool uslov = (x < 0 && y > 0) || (x > 0 && y < 0);
	
	if (uslov) return false;
	    return std::fabs(x-y) <= eps*(std::fabs(x)+std::fabs(y));
}

template <typename T1, typename T2, typename T3, typename T4>

auto UvrnutiPresjek (T1 pocetak1, T1 kraj1, T2 pocetak2, T2 kraj2, T4 funkcija_kriterija(T3))-> typename std::vector<std::vector<typename std::remove_reference<decltype (*pocetak1)>::type>> {
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak2)>::type>> matrica;
	while (pocetak1 != kraj1) {
		T4 br_vrij1 = funkcija_kriterija(*pocetak1);
		T2 temp = pocetak2;
		
		while (temp != kraj2) {
			T4 br_vrij2 = funkcija_kriterija(*temp);
			
			if (Jednaki(br_vrij1, br_vrij2)) {
				std::vector <typename std::remove_reference<decltype(*pocetak1)>::type> pomocni(3);
				pomocni[0] = *pocetak1;
				pomocni[1] = *temp;
				pomocni[2] = br_vrij1;
				matrica.push_back(pomocni);
			}
			temp++;
		}
		pocetak1++;
	}

	
	std::sort(matrica.begin(), matrica.end(), [](typename std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> vek1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> vek2) {
		if (!Jednaki(vek1[2],vek2[2])) return vek1[2] < vek2[2];
		else if((Jednaki(vek1[2], vek2[2])) && !Jednaki(vek1[0], vek2[0])) return vek1[0] < vek2[0];
		return vek1[1] < vek2[1];});
	return matrica;
	
	}
	
template <typename T1, typename T2>
auto UvrnutiPresjek (T1 pocetak1, T1 kraj1, T2 pocetak2, T2 kraj2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	typename std::vector <std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	while(pocetak1 != kraj1) {
		T2 temp=pocetak2;
		while(temp != kraj2) {
			if(Jednaki(*pocetak1, *temp)) {
				std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni(3);
				pomocni[0]=*pocetak1;
				pomocni[1]=0;
				pomocni[2]=0;
				matrica.push_back(pomocni);
			}
			temp++;
		}
		pocetak1++;
	}
	std::sort (matrica.begin(), matrica.end(),[](typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>vek1, typename std::vector <typename std::remove_reference <decltype(*pocetak1)>::type> vek2) {
		return vek1[0] < vek2[0];});
		return matrica;
	}
	
	template <typename T1, typename T2, typename T3, typename T4>
	auto UvrnutaRazlika (T1 pocetak1, T1 kraj1, T2 pocetak2, T2 kraj2, T4 funkcija_kriterija(T3)) -> typename std::vector<std::vector <typename std::remove_reference<decltype(*pocetak1)>::type>> {
		typename std::vector <std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	T1 temp1=pocetak1;
	while (temp1 != kraj1) {
		T4 br_vrij1 = funkcija_kriterija (*temp1);
		bool status = false;
		T2 temp2 = pocetak2;
		while (temp2 != kraj2) {
			T4 br_vrij2 = funkcija_kriterija (*temp2);
			if (Jednaki(br_vrij1, br_vrij2)) {
				status = true;
				break;
			}
			temp2++;
		}
		if (!status) {
			std::vector <typename std::remove_reference<decltype(*pocetak1)>::type> pomocni(2);
			pomocni[0]=*temp1;
			pomocni[1]=br_vrij1;
			matrica.push_back(pomocni);
		}
		temp1++;
	}
	while (pocetak2 != kraj2) {
		T4 br_vrij2 = funkcija_kriterija(*pocetak2);
		bool status = false;
		T1 temp = pocetak1;
		while (temp != kraj1) {
			T4 br_vrij1 = funkcija_kriterija (*temp);
			if (Jednaki(br_vrij1, br_vrij2)) {
				status = true;
				break;
			}
			temp++;
		}
		if (!status) {
			std::vector <typename std::remove_reference<decltype(*pocetak2)>::type> pomocni(2);
			pomocni[0] = *pocetak2;
			pomocni[1] = br_vrij2;
			matrica.push_back(pomocni);
		}
		pocetak2++;
	}
	
	std::sort (matrica.begin(), matrica.end(), [](typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vek1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vek2) {
		if (!Jednaki(vek1[0], vek2[0])) return vek1[0] > vek2[0];
		return vek1[1] > vek2[1];});
		return matrica;
}

template <typename T1, typename T2>
	auto UvrnutaRazlika (T1 pocetak1, T1 kraj1, T2 pocetak2, T2 kraj2) -> typename std::vector<std::vector <typename std::remove_reference<decltype(*pocetak1)>::type>> {
	typename std::vector<std::vector <typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	T1 temp1=pocetak1;
	while (temp1==kraj1) {
		bool status=false;
		T2 temp2 = pocetak2;
		while (temp2 != kraj2) {
			if (Jednaki(*temp1, *temp2)) {
				status = true;
				break;
			}
			temp2++;
		}
		if(!status) {
			std::vector <typename std::remove_reference<decltype(*pocetak1)>::type> pomocni(2);
			pomocni[0] = *temp1;
			pomocni[1] = 0;
			matrica.push_back(pomocni);
		}
		temp1++;
	}
	while (pocetak2 != kraj2) {
		bool status = false;
		T1 temp = pocetak1;
		while (temp != kraj1) {
			if(Jednaki(*temp, *pocetak2)) {
				status = true;
				break;
			}
			temp++;
		}
		if (!status) {
				std::vector <typename std::remove_reference<decltype(*pocetak1)>::type> pomocni(2);
				pomocni[0] = *pocetak2;
				pomocni[1] = 0;
				matrica.push_back(pomocni);
		}
		pocetak2++;
	}
	std::sort (matrica.begin(), matrica.end(), [](typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vek1,
	typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> vek2) {
		return vek1[0] > vek2[0];});
		return matrica;
		
	}
	
int main ()
{
	int ukupno {};
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> ukupno;
	std::cout << "Unesite elemente prvog kontejnera: ";
    std::deque<int> d1(ukupno);
    int unos {};
    
    for (int i = 0; i < ukupno; i++) {
    	std::cin >> unos;
    	bool status = false;
    	
    	for (int j = 0; j < d1.size(); j++) {
    		if (Jednaki(unos, d1[j])) {
    			status = true;
    			break;
    		}
    	}
    	if (!status) d1[i] = unos;
    	else i--;
    	}
    	
    int ukupno2 {};
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> ukupno2;
    std::cout << "Unesite elemente drugog kontejnera: ";
    std::deque<int> d2 (ukupno2);
    
    for(int i = 0; i < ukupno2; i++) {
    	std::cin >> unos;
    	bool status = false;
    	
    	for(int j = 0; j < d1.size(); j++)
    	    if (Jednaki(unos, d2[j])) {
    	    	status = true;
    	    	break;
    	    }
    	    
    	 if (!status) d2[i] = unos;
    	 else i--;
    }
    
    std::vector<std::vector<int>> uvrnutiPresjek = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
    std::vector<std::vector<int>> uvrnutaRazlika = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    std::cout << "Uvrnuti presjek kontejnera: \n";	
    
    for (int i = 0; i < uvrnutiPresjek.size(); i++) {
    	for (int j = 0; j < uvrnutiPresjek[i].size(); j++) {
    	    std::cout << std::right << std::setw(6) << uvrnutiPresjek[i][j] << " ";
    	}
    	    std::cout << std::endl;
    }
    
    std::cout << "Uvrnuta razlika kontejnera: \n";
    for (int i = 0; i < uvrnutaRazlika.size(); i++) {
    	for (int j = 0; j < uvrnutaRazlika[i].size(); j++){
    	    std::cout << std::right << std::setw(6) << uvrnutaRazlika[i][j] << " ";
    	}
    std::cout << std::endl;
    }
    std::cout << "Dovidjenja!";
	return 0;

}