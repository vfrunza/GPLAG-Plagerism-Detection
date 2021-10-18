#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
#include <iomanip>

template<typename T1, typename T2, typename T3, typename T4>
std::vector<std::vector<T3>> UvrnutiPresjek(T1 It1, T1 It2, T2 It3, T2 It4, T3 f(T4));
template<typename T1, typename T2>
auto UvrnutiPresjek(T1 It1, T1 It2, T2 It3, T2 It4) ->  std::vector<std::vector<typename std::remove_reference<decltype(*It1)>::type>>;
template<typename T1, typename T2, typename T3, typename T4>
std::vector<std::vector<T3>> UvrnutaRazlika(T1 It1, T1 It2, T2 It3, T2 It4, T3 f(T4));
int SumaDjelilaca(long long int broj);
int BrojProstihFaktora(long long int broj);
bool DaLiJeProst(long long n);
int BrojSavrsenihDjelilaca(long long n);
int ZbirCifara(long long x);

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin >> n;
	std::deque<int> dek1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0); i < n; i++){
		bool nepostoji(true);
		int broj;
		std::cin>> broj;
		for(int j(0); j < i; j++)
			if(dek1[j] == broj){ //traži da li već postoji isti 
				nepostoji = false;
				i--;
				break;
			}
			
		if(nepostoji) 	//ako nema istog elementa ubaci taj novi elemenat
		dek1.push_back(broj);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin >> m;
	std::deque<int> dek2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0); i < m; i++){
		bool nepostoji(true);
		int broj;
		std::cin>> broj;
		for(int j(0); j < i; j++)
			if(dek2[j] == broj){ //praži da li već ima elemenat unešeni
				nepostoji = false;
				i--;
				break;
			}
		
		if(nepostoji) //ako nema zbaci novi elemenat
		dek2.push_back(broj);
	}
	
	auto ispis(UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),ZbirCifara));
	auto ispis2(UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora));
	
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i(0); i < ispis.size(); i++){
		for(int j(0); j < ispis[i].size(); j++){
			std::cout<< std::setw(6) << ispis[i][j] << " ";
		}
		std::cout << std::endl;
		
	}
	std::cout <<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i(0); i < ispis2.size(); i++){
		for(int j(0); j < ispis2[i].size(); j++){
			std::cout<< std::setw(6) << ispis2[i][j] << " ";
		}
		std::cout << std::endl;
		
	}
	
	std::cout << "Dovidjenja!";
	
	return 0;
}
template<typename T1, typename T2, typename T3, typename T4>
std::vector<std::vector<T3>> UvrnutiPresjek(T1 It1, T1 It2, T2 It3, T2 It4, T3 f(T4)){
	std::vector<std::vector<T3>> izlaz;
	int i(0);
	while(It1 != It2){
		T2 Itpomoc(It3);
		while(Itpomoc != It4){
		if(f(*It1) == f(*Itpomoc)){ //U ovisnosit od funkciej traži iste elemente
			izlaz.resize(i+1);
			izlaz[i].push_back(*It1);			//smještaj prvi elemenat
			izlaz[i].push_back(*Itpomoc);		//drugi
			izlaz[i].push_back(f(*It1));		//vrijednost funkcije
			i++;
	}
	Itpomoc++;
		}
	It1++;
	}
	
	std::sort(izlaz.begin(),izlaz.end(), [](std::vector<T3> x , std::vector<T3> y)
	{
		if(x[2] == y[2] && x[0] == y[0]) return x[1] < y[1]; 		//ako su zadnji i prvi elemenat jednaki poredaj po trećem
		else if(x[2] == y[2]) return x[0] < y[0];					//ako je samo zadnji elemenat jednak poredaj po prvom
		else return x[2] < y[2];									//poredaj po zadnjem
		
	});
	return izlaz;
}
template<typename T1, typename T2>
auto UvrnutiPresjek(T1 It1, T1 It2, T2 It3, T2 It4) -> typename std::vector<std::vector< typename std::remove_reference<decltype(*It1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*It1)>::type>> izlaz;

	
	int i(0);
	while(It1 != It2){
	T2 Itpomoc(It3);
		while(Itpomoc != It4){
		if(*It1 == *Itpomoc){		//traži standardni presjek
			izlaz.resize(i+1);
			izlaz[i].resize(3);
			izlaz[i][0] = *It1;
			i++;
			break;
	}
	Itpomoc++;
		}
	It1++;
	}
	
	typedef std::vector<typename std::remove_reference<decltype(*It1)>::type> vektor; //typedef da ne moram sve ono pisat više puta
	std::sort(izlaz.begin(),izlaz.end(), [](vektor x , vektor y){return x[0] < y[0];});	//sortiraj po elemntima
	
	return izlaz;
}

template<typename T1, typename T2, typename T3, typename T4>
std::vector<std::vector<T3>> UvrnutaRazlika(T1 It1, T1 It2, T2 It3, T2 It4, T3 f(T4)){
	std::vector<std::vector<T3>> izlaz;
	int i(0);
	T1 resIt1(It1);
	
	while(resIt1 != It2){
	bool razlika(true);
		T2 Itpomoc(It3);
		while(Itpomoc != It4){     //traži za svaki elemenat iz prvog skupa da li potoji neki koju mu 'paše' iz drugog po funkciji
			if(f(*resIt1) == f(*Itpomoc))
				razlika = false;
			Itpomoc++;
		}
		if(razlika){
			izlaz.resize(i+1);			//ako nema dodaj ga
			izlaz[i].push_back(*resIt1);
			izlaz[i].push_back(f(*resIt1));
			i++;
		}
	resIt1++;
	}
	
	while(It3 != It4){
	bool razlika(true);
		T2 Itpomoc(It1);
		while(Itpomoc != It2){
			if(f(*It3) == f(*Itpomoc))	//traži za svaki elemenat iz drugog skupa da li postoji neki koju mu 'paše' iz prvog po funkciji
				razlika = false;
			Itpomoc++;
		}
		if(razlika){			//ako nema dodaj ga 
			izlaz.resize(i+1);
			izlaz[i].push_back(*It3);
			izlaz[i].push_back(f(*It3));
			i++;
		}
	It3++;
	}
	
	typedef std::vector<typename std::remove_reference<decltype(*It1)>::type> vektor;
	
	std::sort(izlaz.begin(),izlaz.end(), [](vektor x , vektor y)
	{
		if(x[0] == y[0]) return x[1] > y[1]; 	//ako je prvi elemenat jednak sortiraj po drugom
		else return x[0] > y[0];				//sortiraj po prvom elementu
		}
	);
	
	return izlaz;
}

template<typename T1, typename T2>
auto UvrnutaRazlika(T1 It1, T1 It2, T2 It3, T2 It4) ->  std::vector<std::vector<typename std::remove_reference<decltype(*It1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*It1)>::type>> izlaz;

	int i(0);
	T1 resIt1(It1);
	
	while(resIt1 != It2){
	bool razlika(true);
		T2 Itpomoc(It3);
		while(Itpomoc != It4){		//traži da li 'paše' nekom elementu iz prvog neki elemenat u drugom 
			if(*resIt1 == *Itpomoc)
				razlika = false;
			Itpomoc++;
		}
		if(razlika){			//dodaj
			izlaz.resize(i+1);
			izlaz[i].resize(2);
			izlaz[i][0] = *resIt1;
			i++;
		}
	resIt1++;
	}
	
	while(It3 != It4){
	bool razlika(true);
		T2 Itpomoc(It1);
		while(Itpomoc != It2){		//traži da li 'paše' nekom elementu iz drugog neki elemenat u prvom
			if(*It3 == *Itpomoc)
				razlika = false;
			Itpomoc++;
		}
		if(razlika){			//dodaj
			izlaz.resize(i+1);
			izlaz[i].resize(2);
			izlaz[i][0] = *It3;
			i++;
		}
	It3++;
	}
	
	typedef std::vector<typename std::remove_reference<decltype(*It1)>::type> vektor;
	
	std::sort(izlaz.begin(),izlaz.end(), [](vektor x , vektor y){return x[0] > y[0];});	//sortiraj
	return izlaz;

	
}

int SumaDjelilaca(long long int broj){
	unsigned int djelilac(1), suma(0);
	
	while(djelilac <= std::abs(broj)){
		if(broj % djelilac == 0){	//ako je razlika pri djeljenu nula onda je djelioc i saberi ga
			suma += djelilac;
		}
		djelilac++;		//povećaj djelilac za 1 pa testiraj za njega
	}
	
	return suma;
}
int BrojProstihFaktora(long long int broj){
	int prosti(0);
	unsigned int djelilac(2);
	
	while(djelilac <= std::abs(broj)){
		if(broj % djelilac == 0){		//nađi djeliove 
			if(DaLiJeProst(djelilac))   //testiraj da li su prosti faktori
				prosti++;
			broj /= djelilac;	
			djelilac = 1;
		}
		djelilac++;
	}
	
	return prosti;
}
bool DaLiJeProst(long long n)
{
	//Ime kaže sve
    
    int c(std::sqrt(n)); 		//dovoljno je testirati samo do korijena nekog broja
    if(n < 2)
        return false;
        
    for(int i(2); i <= c; i++)
        if(n%i == 0)
            return false;

    return true;

}
int BrojSavrsenihDjelilaca(long long int n){
	int savrseni(0);
	unsigned int djelilac(2);
	
	while(djelilac <= std::abs(n)){
		if(n % djelilac == 0){	//ako je djelilac testiraj da li je savršeni
			if(std::abs(SumaDjelilaca(djelilac))-djelilac == djelilac)	//suma djelilaca uključuje i sam broj pa ga moramo oduzet i poredit
				savrseni++;
		}
		djelilac++;
	}
	
	return savrseni;
}
int ZbirCifara(long long int x){
	int suma(0);
	while(x != 0){
		suma += std::abs(x%10);		//saberi cifre
		x/=10;
	}
	
	return suma;	
}