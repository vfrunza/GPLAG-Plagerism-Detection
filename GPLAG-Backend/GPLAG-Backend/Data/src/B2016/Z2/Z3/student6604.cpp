/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <type_traits>

int SumaCifara(long long int n){
	if(n<0) n*=-1;
	int suma(0), c;
	while(n!=0){
		c=n%10;
		suma+=c;
		n/=10;
	}
	return suma;
}
bool Prost(long long int n){
	if(n==0 || n==1 || n<0) return 0;
	if(n==2) return 1;
	for(int i=2; i<n; i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int SumaDjelilaca(long long int n){
	if(n<0) n*=-1;
	int suma(0);
	for(int i=1; i<=n; i++){
		if(n%i==0)suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int n){
	if(n<0) n*=-1;
	int br(0);
	for(int i=1; i<=n; i++){
		if(n%i==0 && Prost(i)){ br++;
		n/=i;
		i--;}
	}
	return br;
}
bool Savrsen(long long int n){
	int suma(0);
	for(int i=1; i<n; i++){
		if(n%i==0) suma+=i;
	}
	if(suma==n) return 1;
	return 0;
}
int BrojSavrsenihDjelilaca(long long int n){
	if(n<0) n*=-1;
	int br(0);
	for(int i=1; i<=n; i++){
		if(n%i==0 && Savrsen(i)) br++;
	}
	return br;
}
template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
	Tip2 pomocna3(p3);
	while(p1!=p2){
		while(p3!=p4){
			if(f(*p1)==f(*p3)){
				v.push_back(*p1);
				v.push_back(*p3);
				v.push_back(f(*p1));
				mat.push_back(v);
		    	v.resize(0);
			}
			p3++;
		}
		p3=pomocna3;
		p1++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
		if(v[2]<v2[2]) return 1;
		else if(v[2]==v2[2] && v[0]<v2[0]) return 1;
		else if(v[0]==v2[0]&& v[1]<=v2[1]) return 1;
		return 0;
	});
	
	return mat;
}
template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
	Tip2 pomocna3(p3);
	while(p1!=p2){
		while(p3!=p4){
			if(*p1==*p3){
				v.push_back(*p1);
				v.push_back(0);
				v.push_back(0);
				mat.push_back(v);
		    	v.resize(0);
			}
			p3++;
		}
		p3=pomocna3;
		p1++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
		if(v[0]<v2[0]) return 1;
		return 0;
	});
	
	return mat;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
	Tip2 pomocna(p3);
	Tip1 pomocna2(p1);
	while(p1!=p2){
		while(p3!=p4 && f(*p1)!=f(*p3)) p3++;
		if(p3==p4){
			v.push_back(*p1);
			v.push_back(f(*p1));
			mat.push_back(v);
		}
		v.resize(0);
		p3=pomocna;
		p1++;
	}
	p1=pomocna2;
	p3=pomocna;
	while(p3!=p4){
		while(p1!=p2 && f(*p3)!=f(*p1)) p1++;
		if(p1==p2){
			v.push_back(*p3);
			v.push_back(f(*p3));
			mat.push_back(v);
		}
		v.resize(0);
		p1=pomocna2;
		p3++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
		if(v[0]>v2[0]) return 1;
		else if(v[0]==v2[0]&&v[1]>v2[1]) return 1;
		return 0;
	});
	return mat;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
	Tip2 pomocna(p3);
	Tip1 pomocna2(p1);
	while(p1!=p2){
		while(p3!=p4 && *p3!=*p1) p3++;
		if(p3==p4){
			v.push_back(*p1);
			v.push_back(0);
			mat.push_back(v);
		}
		v.resize(0);
		p3=pomocna;
		p1++;
	}
	p1=pomocna2;
	p3=pomocna;
	while(p3!=p4){
		while(p1!=p2 && *p1!=*p3) p1++;
		if(p1==p2){
			v.push_back(*p3);
			v.push_back(0);
			mat.push_back(v);
		}
		v.resize(0);
		p1=pomocna2;
		p3++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type>v, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){
		if(v[0]>v2[0]) return 1;
		return 0;
	});
	return mat;
}


int main ()
{
std::cout<<"Unesite broj elemenata prvog kontejnera: ";
int n;
std::cin>>n;
std::cout<<"Unesite elemente prvog kontejnera: ";
std::deque<int>d(n);
for(int i=0; i<d.size(); i++){
	std::cin>>d[i];
	for(int j=0; j<i; j++){
		if(d[i]==d[j]) d.resize(d.size()+1);
	}
}
for(int i=0; i<d.size(); i++){
	for(int j=i+1; j<d.size(); j++){
		if(d[i]==d[j]) {d.erase(d.begin()+j); j--;}
	}
}



std::cout<<"Unesite broj elemenata drugog kontejnera: ";
int k;
std::cin>>k;
std::cout<<"Unesite elemente drugog kontejnera: ";
std::deque<int>d2(k);
for(int i=0; i<d2.size(); i++){
	std::cin>>d2[i];
	for(int j=0; j<i; j++){
		if(d2[i]==d2[j]) d2.resize(d2.size()+1);
	}
}
for(int i=0; i<d2.size(); i++){
	for(int j=i+1; j<d2.size(); j++){
		if(d2[i]==d2[j]) {d2.erase(d2.begin()+j); j--;}
	}
}


std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
std::vector<std::vector<int>> v1{UvrnutiPresjek(d.begin(), d.end(), d2.begin(), d2.end(), SumaCifara)};
for(int i=0; i<v1.size(); i++){
	for(int j=0; j<v1[0].size(); j++){
		std::cout<<std::setw(6)<<v1[i][j]<<" ";
	}
	std::cout<<std::endl;
}
std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
std::vector<std::vector<int>> v2{UvrnutaRazlika(d.begin(), d.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
for(int i=0; i<v2.size(); i++){
	for(int j=0; j<v2[0].size(); j++){
		std::cout<<std::setw(6)<<v2[i][j]<<" ";
		}
	std::cout<<std::endl;
}
std::cout<<"Dovidjenja!";

	return 0;
}