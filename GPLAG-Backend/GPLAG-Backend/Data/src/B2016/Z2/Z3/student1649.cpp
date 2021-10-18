/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <deque>
#include <iomanip>
int SumaDjelilaca(long long int x){
	int Suma(0);
	if(x<0){ for(int i=-1;i>=x;i--) if(!(x%i)) Suma-=i;}
	else{ for(int i=1;i<=x;i++) if(!(x%i)) Suma+=i;}
	return Suma;
}
int BrojProstihFaktora(long long int x){
	int Brojac(0);
	while(1){
		for(int i=2;i<=x;i++) if(!(x%i)){
			Brojac++;
			x/=i;
			break;
		}
		if(x==1) break;
	}
	return Brojac;
}
int BrojSavrsenihDjelilaca(long long int x){
	int Brojac(0);
	for(int i=1;i<=x;i++){
		if(!(x%i)){
			int Suma(0);
			for(int j=1;j<i;j++) if(!(i%j)) Suma+=j;
			if(Suma==i) Brojac++;
		}
	}
	return Brojac;
}
int SumaCifara(long long int x){
	int Suma(0);
	while(x!=0){
		Suma+=x%10;
		x/=10;
	}
	if(Suma<0) Suma=-Suma;
	return Suma;
}
template <typename Tip1,typename Tip2,typename Tip3, typename Tip4>
auto UvrnutiPresjek (Tip1 Pocetak1, Tip1 Kraj1, Tip2 Pocetak2, Tip2 Kraj2, Tip3 Funkcija (Tip4) ) -> std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>> Matrica;
	while(Pocetak1!=Kraj1){
		auto Pomocna(Pocetak2);
		while(Pomocna!=Kraj2){
			if(Funkcija(*Pocetak1)==Funkcija(*Pomocna)){
				Matrica.push_back(std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>());
				Matrica[Matrica.size()-1].push_back(*Pocetak1);
				Matrica[Matrica.size()-1].push_back(*Pomocna);
				Matrica[Matrica.size()-1].push_back(Funkcija(*Pocetak1));
			}
			Pomocna++;
		}
		Pocetak1++;
	}
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v2){if (v1[2]<v2[2]) return true; else{ if(v1[2]==v2[2]){ if(v1[0]<v2[0]) return true; else{ if(v1[0]==v2[0]) if(v1[1]<v2[1]) return true;}}}  return false;});
	return Matrica;
}
template <typename Tip1,typename Tip2>
auto UvrnutiPresjek (Tip1 Pocetak1, Tip1 Kraj1, Tip2 Pocetak2, Tip2 Kraj2)-> std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>> Matrica;
	while(Pocetak1!=Kraj1){
		auto Pomocna(Pocetak2);
		while(Pomocna!=Kraj2){
			if((*Pocetak1)==(*Pomocna)){
				Matrica.push_back(std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>());
				Matrica[Matrica.size()-1].push_back(*Pocetak1);
				Matrica[Matrica.size()-1].push_back(0);
				Matrica[Matrica.size()-1].push_back(0);
			}
			Pomocna++;
		}
		Pocetak1++;
	}
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v2) {return v1[0]<v2[0];} );
	return Matrica;
}
template <typename Tip1,typename Tip2,typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 Pocetak1, Tip1 Kraj1, Tip2 Pocetak2, Tip2 Kraj2, Tip3 Funkcija (Tip4) ) -> std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>> Matrica;
	auto Pomocna1(Pocetak1);
	while(Pomocna1!=Kraj1){
		auto Pomocna2(Pocetak2);
		bool Jednaki(false);
		while(Pomocna2!=Kraj2){
			if(Funkcija(*Pomocna1)==Funkcija(*Pomocna2)){
				Jednaki=true;
				break;
			}
			Pomocna2++;
		}
		if(!Jednaki){
			Matrica.push_back(std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>());
			Matrica[Matrica.size()-1].push_back(*Pomocna1);
			Matrica[Matrica.size()-1].push_back(Funkcija(*Pomocna1));
		}
		Pomocna1++;
	}
	auto Pomocna2(Pocetak2);
	while(Pomocna2!=Kraj2){
		Pomocna1=Pocetak1;
		bool Jednaki(false);
		while(Pomocna1!=Kraj1){
			if(Funkcija(*Pomocna1)==Funkcija(*Pomocna2)){
				Jednaki=true;
				break;
			}
			Pomocna1++;
		}
		if(!Jednaki){
			Matrica.push_back(std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>());
			Matrica[Matrica.size()-1].push_back(*Pomocna2);
			Matrica[Matrica.size()-1].push_back(Funkcija(*Pomocna2));
		}
		Pomocna2++;
	}
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v2){if (v1[0]>v2[0]) return true; else if(v1[0]==v2[0]) if(v1[1]>v2[1]) return true; return false; });
	return Matrica;
}
template<typename Tip1,typename Tip2>
auto UvrnutaRazlika(Tip1 Pocetak1,Tip1 Kraj1,Tip2 Pocetak2, Tip2 Kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>> Matrica;
	auto Pomocna1(Pocetak1);
	while(Pomocna1!=Kraj1){
		auto Pomocna2(Pocetak2);
		bool Jednaki(false);
		while(Pomocna2!=Kraj2){
			if(*Pomocna1==*Pomocna2){
				Jednaki=true;
				break;
			}
			Pomocna2++;
		}
		if(!Jednaki){
			Matrica.push_back(std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>());
			Matrica[Matrica.size()-1].push_back(*Pomocna1);
			Matrica[Matrica.size()-1].push_back(0);
		}
		Pomocna1++;
	}
	auto Pomocna2(Pocetak2);
	while(Pomocna2!=Kraj2){
		Pomocna1=Pocetak1;
		bool Jednaki(false);
		while(Pomocna1!=Kraj1){
			if(*Pomocna1==*Pomocna2){
				Jednaki=true;
				break;
			}
			Pomocna1++;
		}
		if(!Jednaki){
			Matrica.push_back(std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type>());
			Matrica[Matrica.size()-1].push_back(*Pomocna2);
			Matrica[Matrica.size()-1].push_back(0);
		}
		Pomocna2++;
	}
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v1,std::vector<typename std::remove_reference<decltype(*Pocetak1)>::type> v2){if(v1[0]>v2[0]) return true; return false;});
	return Matrica;
}
int main (){
	int Vel1,Vel2;
	std::deque<int> Dek1,Dek2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>Vel1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	while(Dek1.size()<Vel1){
		int x;
		bool VecUnesen(false);
		std::cin>>x;
		for(auto &y:Dek1) if(y==x){ VecUnesen=true; break;}
		if(!VecUnesen) Dek1.push_back(x);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>Vel2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	while(Dek2.size()<Vel2){
		int x;
		bool VecUnesen(false);
		std::cin>>x;
		for(auto &y:Dek2) if(y==x){ VecUnesen=true; break;}
		if(!VecUnesen) Dek2.push_back(x);
	}
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	auto Presjek(UvrnutiPresjek(Dek1.begin(),Dek1.end(),Dek2.begin(),Dek2.end(), SumaCifara));
	for(auto &x: Presjek){
		for(auto &y: x){
			std::cout<<std::right<<std::setw(6)<<y<<" ";
		}	
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	auto Razlika(UvrnutaRazlika(Dek1.begin(),Dek1.end(),Dek2.begin(),Dek2.end(), BrojProstihFaktora));
	for(auto &x: Razlika){
		for(auto &y: x){
			std::cout<<std::right<<std::setw(6)<<y<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}
