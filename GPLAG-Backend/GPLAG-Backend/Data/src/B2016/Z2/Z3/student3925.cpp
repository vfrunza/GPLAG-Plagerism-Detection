/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <type_traits>
#include <algorithm>
#include <deque>
#include <iomanip>

bool valjali(long long int a){
	int s(0);
	for(int i(1);i<a;i++){
		if(a%i==0) s+=i;
	}
	if(s==a) return true;
	else return false;
}

bool Dalijeprost(long long int a){
	if(a<2) return false;
	for(int i(2);i<=sqrt(a);i++){
		if(a%i==0) return false;
	}
	return true;
}

int SumaDjelilaca (long long int a){
	int s(0);
	for(int i(1);i<=a;i++){
		if(a%i==0) s+=i;
	}
	return s;
}

int BrojProstihFaktora(long long int a){
	int s(0);
	for(int i(2);i<=a;i++){
		if(a%i==0 && Dalijeprost(i)){
			s++;
			a/=i;
			i--;
		}
	}
	return s;
}
int BrojSavrsenihDjelilaca (long long int a){
	int s(0);
	for(int i(1);i<=a;i++){
		if(a%i==0 && valjali(i)) s++;
	}
	return s;
}

int SumaCifara(long long int a){
	int s(0);
	while(a!=0){
		s+=abs(a%10);
		a=a/10;
	}
	return s;
}
template <typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutiPresjek(tip1 p1, tip1 k1, tip2 p2, tip2 k2, tip4 f(tip3)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> m;
	tip1 p12=p1;
	tip2 p22=p2;
	while(p1!=k1){
		while(p2!=k2){
			if(f(*p1)==f(*p2)){
				std::vector<typename std::remove_reference<decltype(*p1)>::type> v {*p1,*p2,f(*p1)};
				m.push_back(v);
			}
			p2++;
		}
		p2=p22;
		p1++;
	}
	p1=p12;
	std::sort(m.begin(),m.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector<typename std::remove_reference<decltype(*p1)>::type> b){
		if(a[2]==b[2]){ if(a[0]==b[0]) return a[1]<b[1];} return a[0]<b[0]; 
		return a[2]<b[2];});
		return m;
	
}

template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 p1, tip1 k1, tip2 p2, tip2 k2) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> m;
	tip1 p12=p1;
	tip2 p22=p2;
	while(p1!=k1){
		while(p2!=k2){
			if(*p1==*p2){
				std::vector<typename std::remove_reference<decltype(*p1)>::type> v {*p1,0,0};
				m.push_back(v);
			}
			p2++;
		}
		p2=p22;
		p1++;
	}
	p1=p12;
	std::sort(m.begin(),m.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector<typename std::remove_reference<decltype(*p1)>::type> b){
		return a[0]<b[0];});
		return m;
	
}

template <typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutaRazlika (tip1 p1, tip1 k1, tip2 p2, tip2 k2, tip4 f(tip3)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> m,k;
	tip1 p12=p1;
	tip2 p22=p2;
	k=UvrnutiPresjek(p12,p2,p22,k2,f);
	p12=p1;
	p22=p2;
	while(p1!=k1){
		bool a(false);
		for(int i(0);i<k.size();i++){
			if(*p1==k[i][0]) a=true;
		}
		if(a==false){
			std::vector<typename std::remove_reference<decltype(*p12)>::type> v {*p1,f(*p1)};
			m.push_back(v);
		}
		p1++;
	}
	while(p2!=k2){
		bool a(false);
		for(int i(0);i<k.size();i++){
			if(*p2==k[i][1]) a=false;
		}
		if(a==false){
			std::vector<typename std::remove_reference<decltype(*p22)>::type> v {*p2,f(*p2)};
			m.push_back(v);
		}
	}
	p1=p12;
	p2=p22;
	std::sort(m.begin(),m.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector<typename std::remove_reference<decltype(*p1)>::type> b){
		if(a[0]==b[0]) return a[1]>b[1]; return a[0]>b[0];});
		return m;
}
bool isti(int a, int b){
	if(a==b) return true;
	else return false;
}
int main ()
{
	int a,b;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> a;
	std::deque<int> dek,dek2;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int c;
	for(int i(0);i<a;i++){
		std::cin >> c;
		bool ubacitiiline(false);
		for(int j(0);j<dek.size();j++){
			if(c==dek[j]) ubacitiiline=true;
		}
		if(ubacitiiline==true) i--;
		else dek.push_back(c);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> b;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i(0);i<b;i++){
		std::cin >> c;
		bool ubacitiiline(false);
		for(int j(0);j<dek2.size();j++){
			if(c==dek2[j]) ubacitiiline=true;
		}
		if(ubacitiiline==true) i--;
		else dek2.push_back(c);
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for(auto i: UvrnutiPresjek(dek.begin(),dek.end(),dek2.begin(),dek2.end(),SumaCifara)){
		for(auto j: i) std::cout << std::setw(6)<< j<<" ";
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for(auto i:UvrnutaRazlika(dek.begin(),dek.end(),dek2.begin(),dek2.end(),BrojProstihFaktora)){
		for(auto j: i) std::cout << std::setw(6)<<j <<" ";
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}