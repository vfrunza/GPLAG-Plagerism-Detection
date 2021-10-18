/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>

int SumaCifara (int x){
	int suma(0);
	while(x!=0){
		suma+=x%10;
		x/=10;
	}
	return suma;
}

int BrojProstihFaktora(int x){
	int brojac(0);
	for(int i=2; i<=x; i++){
		bool indikator(true);
		for(int j=2; j<i/2 && x%i==0; j++){
			if(i%j==0){
				indikator=false;
				break;
			}
		}
		if(indikator && x%i==0){
			x/=i;
			brojac++;
			i=1;
		}
	}
	return brojac;
}

int SumaDjelilaca(int x){
	int suma(0);
	if(x<0)x*=(-1); 
	for(int i=1; i<=x; i++){
		if(x%i==0)suma+=i;
	}
	return suma;
}

int BrojSavrsenihDjelilaca (int x){
	int brojac(0);
	for(int i=1; i<=x; i++){
		if(x%i==0){
			int suma_2(0);
			for(int j=1; j<i; j++){
				if(i%j==0)suma_2+=j;
			}
			if(i==suma_2)brojac++;
		}
	}
	return brojac;
}

template<typename Tip1, typename Tip2, typename Tip3>
	auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 (*f)(Tip3)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
		int brojac(0);
		for(Tip1 i=p1; i<p2; i++){
			for(Tip2 j=p3; j<p4; j++){
				if(f(*i)==f(*j)){
					matrica.resize(matrica.size()+1);
					matrica[brojac].push_back(*i);
					matrica[brojac].push_back(*j);
					matrica[brojac].push_back(f(*i));
					brojac++;
				}
			}
		}
		
		std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type> v1, std::vector<typename std::remove_reference<decltype(*p1)>::type> v2){
			if(v1[2]<v2[2]) return true;
			else if(v1[2]>v2[2]) return false;
			else if(v1[2]==v2[2]){
				if(v1[0]<v2[0]) return true;
				else if(v1[0]>v2[0]) return false;
				else if(v1[0]==v2[0]){
					if(v1[1]<v2[1]) return true;
					else return false;
				}
			}
		
			
		});
		return matrica;
	}

template<typename Tip1, typename Tip2, typename Tip3>
	auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 (*f)(Tip3)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
		int brojac(0);
		for(Tip1 i=p1; i<p2; i++){
			bool indikator(true);
			for(Tip2 j=p3; j<p4; j++){
				if(f(*i)==f(*j))indikator=false;
			}
			if(indikator){
				matrica.resize(matrica.size()+1);
				matrica[brojac].push_back(*i);
				matrica[brojac].push_back(f(*i));
				brojac++;
			}
		}
		for(Tip2 j=p3; j<p4; j++){
			bool indikator(true);
			for(Tip1 i=p1; i<p2; i++){
				if(f(*j)==f(*i))indikator=false;
			}
			if(indikator){
				matrica.resize(matrica.size()+1);
				matrica[brojac].push_back(*j);
				matrica[brojac].push_back(f(*j));
				brojac++;
			}
		}
		
		std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type> v1, std::vector< typename std::remove_reference<decltype(*p1)>::type> v2){
			if(v1[0]>v2[0]) return true;
			else if (v1[0]<v2[0]) return false;
			else if(v1[0]==v2[0]){
				if(v1[1]>v2[1]) return true;
				else return false;
			}
		});
		return matrica;
	}
	
	// sad ove s 4 parametra
	
template<typename Tip1, typename Tip2>
	auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
		int brojac(0);
		for(Tip1 i=p1; i<p2; i++){
			for(Tip2 j=p3; j<p4; j++){
				if(*i==*j){
				matrica.resize(matrica.size()+1);
				matrica[brojac].push_back(*i);
				matrica[brojac].push_back(0);
				matrica[brojac].push_back(0);
				brojac++;
					}
			}
		}
		
		//fali sort za ovu
		
		std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type> v1, std::vector<typename std::remove_reference<decltype(*p1)>::type> v2){
			if(v1[0]<v2[0]) return true;
			else return false;
		});
		return matrica;
	}
	
template<typename Tip1, typename Tip2>
	auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
		int brojac(0);
		for(Tip1 i=p1; i<p2; i++){
			bool indikator(true);
			for(Tip2 j=p3; j<p4; j++){
				if(*i==*j)indikator=false;
			}
			if(indikator){
				matrica.resize(matrica.size()+1);
				matrica[brojac].push_back(*i);
				matrica[brojac].push_back(0);
				brojac++;
			}
		}
		for(Tip2 j=p3; j<p4; j++){
			bool indikator(true);
			for(Tip1 i=p1; i<p2; i++){
				if(*j==*i)indikator=false;
			}
			if(indikator){
				matrica.resize(matrica.size()+1);
				matrica[brojac].push_back(*j);
				matrica[brojac].push_back(0);
				brojac++;
			}
		}
		
		//sort trebo dodat
		
		std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type> v1, std::vector<typename std::remove_reference<decltype(*p1)>::type> v2){
			if(v1[0]>v2[0])return true;
			else return false;
		});
		return matrica;
	}

int main (){
	int vel_1, vel_2;
	std::deque<int> kont_1, kont_2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> vel_1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i(0); i<vel_1; i++){
		int broj;
		std::cin >> broj;
		bool indikator(false);
		for(int j=0; j<kont_1.size(); j++){
			if(kont_1[j]==broj){
				indikator=true;
				i--;
				break;
			}
		}
		if(indikator)continue;
		kont_1.push_back(broj);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> vel_2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i(0); i<vel_2; i++){
		int broj;
		std::cin >> broj;
		bool indikator(false);
		for(int j=0; j<kont_2.size(); j++){
			if(kont_2[j]==broj){
				indikator=true;
				i--;
				break;
			}
		}
		if(indikator)continue;
		kont_2.push_back(broj);
	}
	std::cout << "Uvrnuti presjek kontejnera:\n";
	std::vector<std::vector<int>> matrica(UvrnutiPresjek(kont_1.begin(), kont_1.end(), kont_2.begin(), kont_2.end(), SumaCifara));
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			std::cout << std::setw(6) << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:\n";
	matrica=UvrnutaRazlika(kont_1.begin(), kont_1.end(), kont_2.begin(), kont_2.end(), BrojProstihFaktora);
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			std::cout << std::setw(6) << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	
	
	return 0;
}