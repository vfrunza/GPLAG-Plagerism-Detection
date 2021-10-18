/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <iomanip>

int SumaCifara(int n){
	int suma(0);
	while(n!=0){
		suma = suma + n%10;
		n/=10;
	}
		return suma;
}
bool DaLiJeProst(int n){
	for(int i=2 ; i<n ; i++){
		if(n%i==0) return false;
	}
		return true;
}


int SumaDjelilaca(long long int n){
	long long int suma(0);
	for(int i=1 ; i<=n ; i++){
		if(n%i==0) suma+=i;
	}
		return suma;
}

int BrojProstihFaktora(long long int n){
	int brojac(0);
	for(int i=2 ; i<=n ; i++){
		if(n%i==0){
			if(DaLiJeProst(i)) {
				brojac++;
				n = n/i;
				i--;
		}
	}
}
		return brojac;	
}

bool DaLiJeSavrsen(int n){
	int suma(0);
	for(int i=1 ; i<n ; i++){
		if(n%i==0) suma+=i;
	}
		if(n == suma) return true;
		return false;
}

int BrojSavrsenihDjelilaca(long long int n){
	int br(0);
	for(int i=1 ; i<=n ; i++){
		if(n%i==0){
			if(DaLiJeSavrsen(i)){
				br++;
				n = n/i;
				i--;
			} 
		}
	}
		return br;
}
template <typename Tip1, typename Tip, typename povratna, typename prima>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip q1, Tip q2, povratna f(prima), decltype(*p1+0) cijelibroj=0) -> std::vector<std::vector<decltype(cijelibroj)>> {
	decltype(*p1+0) a;
	std::vector<std::vector<decltype(a)>> mat;
	int n(0);
	int br(0);
	auto p11 = p1;
 	while(p11!=p2){
 		auto pom = q1;
 		while(pom!=q2){
 			if(f(*p11) == f(*pom)) n++; 
 				pom++;
 		}
 			p11++;
 	}
 		if(n==0) return mat;
 		mat.resize(n);
 		while(p1!=p2){
 			auto temp = f(*p1);
 			auto pom = q1;
 			while(pom!=q2){
 			if(temp == f(*pom)){
 				std::vector<decltype(a)> v(3);
 				v[0] = *p1;
 				v[1] = *pom;
 				v[2] = temp;
 				for(int i=0 ; i<3 ; i++){
 				mat[br].push_back(v[i]);
 				
 			}
 				br++;
 		}	
 				pom++;
 	}
 			p1++;
}
 		std::sort(mat.begin(), mat.end(), [](std::vector<decltype(a)> v1, std::vector<decltype(a)> v2){ if(v1[2] == v2[2]){
 		if(v1[0] == v2[0]) return v1[1]<v2[1];
 		return v1[0]<v2[0];} 
 		return v1[2]<v2[2];});
 		
 		return mat;
 }
 
template <typename IterTip1, typename IterTip2>
auto UvrnutiPresjek(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2, decltype(*p1+0) cijelibroj=0) -> std::vector<std::vector<decltype(cijelibroj)>>{
	decltype(*p1+0) a;
	std::vector<std::vector<decltype(a)>> mat;
	int n(0);
	int br(0);
	auto p11 = p1;
	while(p11!=p2){
		auto pom = q1;
		while(pom!=q2){
			if(*p11 == *pom) n++; 
			pom++;
		}
			p11++;
	}
		if(n==0) return mat;
		mat.resize(n);
		while(p1!=p2){
				auto temp = *p1;
				auto pom = q1;
				while(pom!=q2){
				if(temp == *pom){
				std::vector<decltype(a)> v(3);
				v[0] = *p1;
				v[1] = 0;
				v[2] = 0;
				for(int i=0 ; i<3 ; i++) 
					mat[br].push_back(v[i]);
					br++;
				}
				pom++;
		}
			p1++;
	}
		std::sort(mat.begin(), mat.end(), [] (std::vector<decltype(a)> v1, std::vector<decltype(a)> v2){ return v1[0]<v2[0];});
		return mat;
}

 
 
 
 template <typename IterTip1, typename IterTip2, typename povratna, typename prima>
auto UvrnutaRazlika(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2, povratna f(prima), decltype(*p1+0) cijelibroj=0) -> std::vector<std::vector<decltype(cijelibroj)>>{
 	decltype(*p1+0) a;
 	std::vector<std::vector<decltype(a)>> mat;
 	int brojac(0), br(0), n(0), velicina(q2-q1), velicina1(p2-p1);
 	auto p11 = p1;
 	while(p11!=p2){
 		auto pom = q1;
 		while(pom!=q2){
 			if(f(*p11)!=f(*pom)) brojac++;
 			pom++;
 		}
 			if(brojac == velicina) n++; 
 			p11++;
 			brojac = 0;
 	}
 			auto q11 = q1;
 			while(q11!=q2){
 				auto pom = p1;
 				while(pom!=p2){
 					if(f(*q11)!=f(*pom)) brojac++;
 					pom++;
 				}
 					if(brojac == velicina1) n++;
 					q11++;
 					brojac = 0;
 			}
 				if(n==0) return mat;
 				mat.resize(n);
 				brojac = 0;
 				auto p111 = p1;
 				while(p1!=p2){
 					auto temp = f(*p1);
 					auto pom = q1;
 					while(pom!=q2){
 						if(temp != f(*pom)) brojac++;
 						pom++;
 					}
 				if(brojac == velicina){
 				std::vector<decltype(a)>v(2);
 				v[0] = *p1;
 				v[1] = temp;
 				for(int i=0 ; i<2 ; i++){
 					mat[br].push_back(v[i]);
 				}
 				br++;
 			}
 			brojac = 0;
 			p1++;
 	}
 		while(q1!=q2){
 			auto temp = f(*q1);
 			auto pom = p111;
 			while(pom!=p2){
 				if(temp != f(*pom)) brojac++;
 						pom++;
 			}
 				if(brojac==velicina1){
 						std::vector<decltype(a)>v(2);
 				v[0] = *q1;
 				v[1] = temp;
 				for(int i=0 ; i<2 ; i++){
 					mat[br].push_back(v[i]);
 				}
 					br++;
 			}
 				brojac = 0;
 				q1++;
 		}
 	std::sort(mat.begin(), mat.end() , [](std::vector<decltype(a)> v1, std::vector<decltype(a)> v2){ if(v1[0] ==v2[0]) return v1[1]>v2[1];
 	return v1[0]>v2[0];});

 	return mat;
 	
 }

int main ()
{
	int m, n;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> d1;
	for(int i=0 ; i<n ; i++){
		int x;
		std::cin>>x;
		auto it = std::find(d1.begin(), d1.end(), x);
		if(it!=d1.end()) {i--; continue;}
		d1.push_back(x);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>m;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> d2;
	for(int i=0 ; i<m ; i++){
		int x;
		std::cin>>x;
		auto it = std::find(d2.begin(), d2.end(), x);
		if(it!=d2.end()) {i--; continue;}
		d2.push_back(x);
	}
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::vector<std::vector<int>> mat = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	for(int i=0; i<mat.size() ; i++){
		for(int j=0 ; j<mat[i].size() ; j++){
			std::cout<<std::setw(6)<<mat[i][j]<<" ";
		}
			std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;;
	std::vector<std::vector<int>> raz = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	for(int i=0 ; i<raz.size(); i++){
		for(int j=0 ; j<raz[i].size() ; j++){
			std::cout<<std::setw(6)<<raz[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}