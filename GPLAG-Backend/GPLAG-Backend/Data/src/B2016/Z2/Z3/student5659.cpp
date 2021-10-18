/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>

typedef std::vector<std::vector<int>> Matrica;

int SumaDjelilaca(long long int x)
{
	int suma(0);
	for(long long int i=1; i<=x; i++) {
		if(x%i==0)
			suma+= int(i);
	}
	return suma;
}
int BrojProstihFaktora(long long int x)
{
	int br(0);
	while(x>=2){
	for(int i=2; i<=x; i++) {
		if(x%i==0){
			br++;
			x/=i;
			break;
		} 
	}
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int x)
{
	int br(0);
	int suma;

	for(int i=1;i<x;i++){
			suma=0;
		if(x%i==0){
			for(int j=1;j<=i;j++){
				if(i%j==0) {
					suma+=j;
				}
					if(suma==i) br++;
			}
		}
	}
return br;
}
template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>

Matrica UvrnutiPresjek(Tip1 p1,Tip1 p2, Tip2 s1, Tip2 s2,Tip3 f(Tip4 x))
{
	Matrica m;
	Tip1 broj1;
	Tip2 broj2;
	int br;
	for(auto i=p1; i<p2; i++) {
		
		for(auto j=s1; j<s2; j++) {
			std::vector<int> v;
			if(f(*i)==f(*j)) {
				br=f(*i);
				v.push_back(*i);
				v.push_back(*j);
				v.push_back(br);
				m.push_back(v);
			}
		}
	}
	std::sort(m.begin(),m.end(), [](std::vector<Tip3> a, std::vector<Tip3> b) {
		if(a[2]!=b[2]) return a[2]<b[2];
		else if(a[0]!=b[0]) return a[0]<b[0];
		else return a[1]<b[1];
	});
	return m;
}
int fun(long long int x) {
	int suma=0;
	int temp;
	while(x!=0) {
		temp=x%10;
		suma+=temp;
		x/=10;
	}
	return suma;
}
template <typename Tip1, typename Tip2>
Matrica UvrnutiPresjek(Tip1 p1,Tip1 p2, Tip2 s1, Tip2 s2)
{
	Matrica m;
	Tip1 broj1;
	Tip2 broj2;
	int br;
	for(auto i=p1; i<p2; i++) {
		std::vector<int> v;
		for(auto j=s1; j<s2; j++) {
			if(fun(*i)==fun(*j)) {
				br=fun(*i);
				v.push_back(*i);
				v.push_back(0);
				v.push_back(0);
				m.push_back(v);
				break;
			}
		}
	}
	std::sort(m.begin(),m.end(), [](std::vector<int> a, std::vector<int> b) {
		if(a[2]!=b[2]) return a[2]<b[2];
		else if(a[0]!=b[0]) return a[0]<b[0];
		else return b[2]<a[2];
	});
	return m;
}
template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
Matrica UvrnutaRazlika(Tip1 p1,Tip1 p2, Tip2 s1, Tip2 s2,Tip3 f(Tip4 x))
{
	Matrica m;
	int br(0);
	for(auto i=p1; i<p2; i++) {
		std::vector<int> v;
		std::vector<int> v1;
		for(auto j=s1; j<s2; j++) {
			if(f(*i)==f(*j)) break;
			else
			if(f(*i)!=f(*j));
			if(j==s2-1){
				br=f(*i);
				v.push_back(*i);
				v.push_back(br);
				m.push_back(v);
			}
		}
	}
		for(auto i=s1; i<s2; i++) {
		std::vector<int> v;
		std::vector<int> v1;
		for(auto j=p1; j<p2; j++) {
			if(f(*i)==f(*j)) break;
			else
			if(f(*i)!=f(*j));
			if(j==p2-1){
				br=f(*i);
				v.push_back(*i);
				v.push_back(br);
				m.push_back(v);
			}
		}
	}
	std::sort(m.begin(),m.end(), [](std::vector<Tip3> a, std::vector<Tip3> b) {
		if(a[0]!=b[0]) return a[0]>b[0];
		else if(a[1]!=b[1]) return a[1]>b[1];
		else return a[0]>b[0];
	});
	return m;
}
template <typename Tip1, typename Tip2>
Matrica UvrnutaRazlika(Tip1 p1,Tip1 p2, Tip2 s1, Tip2 s2)
{
	Matrica m;
	int br(0);
	for(auto i=p1; i<p2; i++) {
		std::vector<int> v;
		std::vector<int> v1;
		for(auto j=s1; j<s2; j++) {
			if(BrojProstihFaktora(*i)==BrojProstihFaktora(*j)) break;
			else
			if(BrojProstihFaktora(*i)!=BrojProstihFaktora(*j));
			if(j==s2-1){
				br=BrojProstihFaktora(*i);
				v.push_back(*i);
				v.push_back(0);
				m.push_back(v);
			}
		}
	}
		for(auto i=s1; i<s2; i++) {
		std::vector<int> v;
		std::vector<int> v1;
		for(auto j=p1; j<p2; j++) {
			if(BrojProstihFaktora(*i)==BrojProstihFaktora(*j)) break;
			else
			if(BrojProstihFaktora(*i)!=BrojProstihFaktora(*j));
			if(j==p2-1){
				br=BrojProstihFaktora(*i);
				v.push_back(*i);
				v.push_back(0);
				m.push_back(v);
			}
		}
	}
	std::sort(m.begin(),m.end(), [](std::vector<int> a, std::vector<int> b) {
		if(a[0]!=b[0]) return a[0]>b[0];
		else if(a[1]!=b[1]) return a[1]>b[1];
		else return a[0]>b[0];
	});
	return m;
}
int main ()
{
	std::deque<int> x;
	std::deque<int> x1;
	int n1;
	int broj;
	int n2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int i=0;
	while(i<n1){
		std::cin>>broj;
		bool pon=false;
		for(int j=0;j<x.size();j++){
			if(x[j]==broj)
			pon=true;
		}
		if(pon==false){
		x.push_back(broj);
		i++;}
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	i=0;
	while(i<n2){
		std::cin>>broj;
		bool pon=false;
		for(int j=0;j<x1.size();j++){
			if(x1[j]==broj)
			pon=true;
		}
		if(pon==false){
		x1.push_back(broj);
		i++;}
	}
	auto p1(x.begin());
	auto p2(x.end());
	auto p3(x1.begin());
	auto p4(x1.end());
	Matrica a;
	int br;
	for(auto i=p1; i<p2; i++) {
		for(auto j=p3; j<p4; j++) {
				std::vector<int> v;
			if(fun(*i)==fun(*j)) {
				br=fun(*i);
				v.push_back(*i);
				v.push_back(*j);
				v.push_back(br);
				a.push_back(v);
			
			}
		}
	}
	std::sort(a.begin(),a.end(), [](std::vector<int> a, std::vector<int> b) {
		if(a[2]!=b[2]) return a[2]<b[2];
		else if(a[0]!=b[0]) return a[0]<b[0];
		else return b[2]<a[2];
	});
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<3; j++) {
			std::cout<<std::setw(6)<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	Matrica b;
		br=0;
	for(auto i=p1; i<p2; i++) {
		std::vector<int> v;
		std::vector<int> v1;
		for(auto j=p3; j<p4; j++) {
			if(BrojProstihFaktora(*i)==BrojProstihFaktora(*j)) break;
			else
			if(BrojProstihFaktora(*i)!=BrojProstihFaktora(*j));
			if(j==p4-1){
				br=BrojProstihFaktora(*i);
				v.push_back(*i);
				v.push_back(*j);
				b.push_back(v);
			}
		}
	}
		for(auto i=p3; i<p4; i++) {
		std::vector<int> v;
		std::vector<int> v1;
		for(auto j=p1; j<p2; j++) {
			if(BrojProstihFaktora(*i)==BrojProstihFaktora(*j)) break;
			else
			if(BrojProstihFaktora(*i)!=BrojProstihFaktora(*j));
			if(j==p2-1){
				br=BrojProstihFaktora(*i);
				v.push_back(*i);
				v.push_back(br);
				b.push_back(v);
			}
		}
	}
	std::sort(b.begin(),b.end(), [](std::vector<int> a, std::vector<int> b) {
		if(a[0]!=b[0]) return a[0]>b[0];
		else if(a[1]!=b[1]) return a[1]>b[1];
		else return a[0]>b[0];
	});
	
	
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<2; j++) {
			std::cout<<std::setw(6)<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!"<<std::endl;
	return 0;
}