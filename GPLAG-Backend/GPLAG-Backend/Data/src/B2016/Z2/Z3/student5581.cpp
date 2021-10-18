/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <iomanip>

bool JeProst(long long int n){
	if(n<=1) return false;
	
	n=std::fabs(n);
	long long int korijen=std::sqrt(n);
	
	for(int i=2;i<=korijen;i++)
		if(n%i==0)
			return false;
	return true;
}

bool Ima(int broj, std::deque<int> dek){
	for(int i=0;i<dek.size();i++)
		if(broj==dek[i])
			return true;
	return false;
}

int SumaDjelilaca(long long int n){
	
	n=std::fabs(n);
	
	int suma(n);
	
	for ( int i=1 ; i<=n/2 ; i++ ){
		if(n % i == 0)
			suma+=i;
	}
	
	return suma;
}

bool JeSavrsen(long long int n){
	n=std::fabs(n);
	long long int suma_djelilaca=SumaDjelilaca(n);
	return suma_djelilaca-n==n;
}

int SumaCifara(long long int n){
	int suma=0;
	while(n!=0){
		suma+=std::abs(n%10);
		n/=10;
	}
	return suma;
}

int BrojProstihFaktora(long long int n){
	
	int brojac(0);
	
	n=std::fabs(n);
	
	for(int i=1;i<=n;i++){
		while(JeProst(i)&&n%i==0){
			brojac++;
			n/=i;
		}
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int n){
	
	int brojac(0);
	
	for(int i=1;i<=n/2;i++){
		if(n%i==0&&JeSavrsen(i))
			brojac++;
	}
	if(JeSavrsen(n)) brojac++;
	return brojac;
}

template<typename TipPrvogBloka, typename TipDrugogBloka, typename ParametarFunkcije, typename PovratniTipFunkcije>

std::vector<std::vector<PovratniTipFunkcije>> UvrnutiPresjek(TipPrvogBloka pocetak1, TipPrvogBloka kraj1, TipDrugogBloka pocetak2, TipDrugogBloka kraj2, PovratniTipFunkcije funkcija(ParametarFunkcije)){
	
	std::vector<std::vector<PovratniTipFunkcije>> presjek;
	
	std::vector<PovratniTipFunkcije> red;
	
	while(pocetak1!=kraj1){
		
		TipDrugogBloka pom=pocetak2;
		while(pom!=kraj2){
			
			if(funkcija(*pocetak1)==funkcija(*pom)){
				std::vector<PovratniTipFunkcije> red(3);
				red[0]=*pocetak1;
				red[1]=*pom;
				red[2]=funkcija(*pocetak1);
				presjek.push_back(red);
			}
			pom++;
		}
		pocetak1++;
	}
	
	std::sort(presjek.begin(),presjek.end(),[](std::vector<PovratniTipFunkcije> a, std::vector<PovratniTipFunkcije> b){
		if(a[2]<b[2]) return true;
		else if(a[2]>b[2]) return false;
		else {
			if(a[0]<b[0]) return true;
			else if(a[0]>b[0]) return false;
			else return (a[1]<b[1]);
		}
	});
	
	return presjek;
}

template <typename TipPrvogBloka, typename TipDrugogBloka>

auto UvrnutiPresjek(TipPrvogBloka pocetak1, TipPrvogBloka kraj1, TipDrugogBloka pocetak2, TipDrugogBloka kraj2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	
	typename std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> red(3);
	while(pocetak1!=kraj1){
		TipDrugogBloka pom=pocetak2;
		while(pom!=kraj2){
			if(*pom == *pocetak1){
				red[0] = *pom;
				red[1] = typename std::remove_reference<decltype(*pocetak1)>::type {};
				red[2] = typename std::remove_reference<decltype(*pocetak1)>::type {};
				matrica.push_back(red);
			}
			pom++;
		}
		pocetak1++;
	}
	
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> a, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> b){return a[0]<b[0];});
	
	return matrica;
}

template<typename TipPrvogBloka, typename TipDrugogBloka, typename ParametarFunkcije, typename PovratniTipFunkcije>

std::vector<std::vector<PovratniTipFunkcije>> UvrnutaRazlika(TipPrvogBloka pocetak1, TipPrvogBloka kraj1, TipDrugogBloka pocetak2, TipDrugogBloka kraj2, PovratniTipFunkcije funkcija(ParametarFunkcije)){
	
	std::vector<std::vector<PovratniTipFunkcije>> matrica;
	
	std::vector<PovratniTipFunkcije> red(2);
	
	bool ima(0);
	
	TipPrvogBloka pom2=pocetak1;
	TipDrugogBloka pom=pocetak2;
	
	while(pom2!=kraj1){
		pom=pocetak2;
		ima=0;
		while(pom!=kraj2){
			if(funkcija(*pom2) == funkcija(*pom)){
				ima=1;
				break;
			}
			pom++;
		}
		if(!ima){
			red[0]=*pom2;
			red[1]=funkcija(*pom2);
			matrica.push_back(red);
		}
		pom2++;
	}
	pom=pocetak2;
	pom2=pocetak1;
	while(pom!=kraj2){
		pom2=pocetak1;
		ima=0;
		while(pom2!=kraj1){
			if(funkcija(*pom2)==funkcija(*pom)){
				ima=1;
				break;
			}
			pom2++;
		}
		if(!ima){
			red[0]=*pom;
			red[1]=funkcija(*pom);
			matrica.push_back(red);
			
		}
		pom++;
	}
	
	std::sort(matrica.begin(), matrica.end(), [](std::vector<PovratniTipFunkcije> a, std::vector<PovratniTipFunkcije> b){
		if(a[0]>b[0]) return true;
		else if(b[0]>a[0]) return false;
		else return a[1]<b[1];
	} );
	
		return matrica;
	}

template <typename TipPrvogBloka, typename TipDrugogBloka>
auto UvrnutaRazlika(TipPrvogBloka pocetak1, TipPrvogBloka kraj1, TipDrugogBloka pocetak2, TipDrugogBloka kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {
	
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> matrica;
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> red(2);
	
	bool ima=0;
	
	TipPrvogBloka pom1=pocetak1;
	TipDrugogBloka pom2=pocetak2;
	
	while(pom1!=kraj1){
		pom2=pocetak2;
		ima=0;
		while(pom2!=kraj2){
			if(*pom1==*pom2){
				ima=1;
				break;
			}
			pom2++;
		}
		if(!ima){
			red[0]=*pom1;
			red[1]=typename std::remove_reference<decltype(*pocetak1)>::type {};
			matrica.push_back(red);
		}
		pom1++;
	}
	pom1=pocetak1;
	pom2=pocetak2;
	while(pom2!=kraj2){
		pom1=pocetak1;
		ima=0;
		while(pom1!=kraj1){
			if(*pom1==*pom2){
				ima=1;
				break;
			}
			pom1++;
		}
		if(!ima){
			red[0]=*pom2;
			red[1]=typename std::remove_reference<decltype(*pocetak1)>::type {};
			matrica.push_back(red);
		}
		pom2++;
	}
	
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> a, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> b){
		return a[0]>b[0];
	});
	
	return matrica;
}

int main ()
{
	std::deque<int> dek1,dek2;
	int x;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>x;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int broj;
	
	for(int i=0 ; i<x ; i++){
		std::cin>>broj;
		while(Ima(broj,dek1))std::cin>>broj;
		
		dek1.push_back(broj);
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>x;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	
	for(int i=0;i<x;i++){
		std::cin>>broj;
		while(Ima(broj, dek2)) std::cin>>broj;
		
		dek2.push_back(broj);
	}
	
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	auto presjek = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	
	for(int i=0;i<presjek.size();i++){
		for(int j=0;j<3;j++){
			std::cout<<std::setw(6)<<presjek[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	auto razlika = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	
	for(int i=0;i<razlika.size();i++){
		for(int j=0;j<2;j++){
			std::cout<<std::setw(6)<<razlika[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Dovidjenja!";
	return 0;
}