/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include <type_traits>
#include <iomanip>
// typedef std::deque<std::deque<int>> Matrica;

// template <typename pok1>

int SumaCifara(long long int n)
{
	if(n<0) n=n*(-1);
	int suma(0);
	while(n!=0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}

int SumaDjelilaca( long long int n) {
	if(n<0) n=n*(-1);
	int suma=0;
	for(int i=1; i<=n; i++) if(n%i==0) suma+=i;
	return suma;
}
int SUmaDjelilacabez(long long int n) {
	if(n<0) n=n*(-1);
	int suma=0;
	for(int i=1; i<n; i++) if(n%i==0) suma+=i;
	return suma;
}

bool SavrsenBroj(long long int n){ int suma(0);
	if(n<0) n=n*(-1);
	for(int i=1; i<n; i++)  { if(n%i==0) suma+=i; }
if(suma==n) return true;
return false;
	
}

bool prost(long long int n) {
	if(n<0) n=n*(-1);
	for(int i=3; i<n; i++)  { if(n%i==0) return false; }
	return true;
}
int BrojProstihFaktora(long long int n) { 
	if(n<0) n=n*(-1);
	int br(0);
//	while(n!=0) {
//	for(int i=2; i<n; i++) { if(n%i==0 && prost(i))  br++; } }
for(int i=2; i<=n; i++) {
	while(n%i==0) { n/=i; br++; } }
	return br;
}

int BrojSavrsenihDjelilaca(long long int n) { if(n<0) n=n*(-1); int br=0;
	for(int i=2; i<=n; i++) if( (n%i==0) && SavrsenBroj(i)) br++;
	return br;
}

bool pripada(int n, std::deque<int> d) { 
	for(int i=0; i<d.size(); i++) if(n==d[i]) return true;
	return false;
}

template <typename T, typename T1, typename TIP, typename TIP2>
auto UvrnutiPresjek(T p1, T p2, T1 q1, T1 q2, TIP fun(TIP2))-> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	typedef typename std::remove_reference<decltype(*p1)>::type tip;
	std::vector<std::vector<tip>> mat(0, std::vector<tip>(3));
	//Matrica mat;
	int n(0);
	auto q3=q1;
	auto p3=p1;
	while(p1!=p2) {
		q1=q3;
		while(q1!=q2) {
			if(fun(*p1)==fun(*q1)) n++;
			q1++;
		}
		p1++;
	}
	mat.resize(n);
	for(int i=0; i<n; i++) mat[i].resize(3);
	p1=p3;
	
	for(int i=0; i<n; )  {
		while(p1!=p2) {
			q1=q3;
			while(q1!=q2) {
				if(fun(*p1)==fun(*q1)) {
					mat[i][0]=*p1;
					mat[i][1]=*q1;
					mat[i][2]=fun(*p1);
					i++;
				}
				q1++;
			}
			p1++;
		} 
	}

std::sort(mat.begin(), mat.end(), [](const std::vector<decltype(*p1+0)> &x, const std::vector<decltype(*p1+0)> &y)
{
	
	if(x[2]!=y[2]) return x[2]<y[2];
	else if(x[2]==y[2] && x[0]!=y[0]) return x[0]<y[0];
	else return x[1]<y[1];
	
	} ); 

	return mat;
}
template <typename T, typename T1, typename TIP, typename TIP2>
auto UvrnutaRazlika(T p1, T p2, T1 q1, T1 q2, TIP fun(TIP2)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	typedef typename std::remove_reference<decltype(*p1)>::type tip;
	auto p3=p1, q3=q1;
	int n(0);
	bool a=true;
	while(p1!=p2) { a=true;
		q1=q3;
		while(q1!=q2) { if(fun(*p1)==fun(*q1)) a=false; q1++; }
		if(a) n++;  p1++;
	}
	p1=p3; q1=q3;
	int n1(0);
	while(q1!=q2) { a=true; p1=p3; while(p1!=p2) { if(fun(*q1)==fun(*p1)) a=false; p1++; } if(a) n1++; q1++; }
	std::vector<std::vector<tip>> mat; int indeks(0);
	int vel=n+n1;
	mat.resize(vel);
	for(int i=0; i<vel; i++) mat[i].resize(2);
	p1=p3; q1=q3;
	a=true;
	for(int i=0; i<n; ) { 
		while(p1!=p2) { a=true;
			q1=q3;
			while(q1!=q2) {
				if(fun(*p1)==fun(*q1)) a=false; q1++; 
			} if(a==true) { mat[i][0]=*p1; mat[i][1]=fun(*p1); indeks++; i++; }
		 p1++; } 
	}
	p1=p3; q1=q3;
	indeks=n;
	for(int i=indeks; i<vel; ) { 
		while(q1!=q2) { a=true;
			p1=p3; while(p1!=p2) {
				if(fun(*p1)==fun(*q1)) a=false; p1++;
			} if(a==true) { mat[i][0]=*q1; mat[i][1]=fun(*q1); i++; }
			q1++;	
			}
		}
		if(mat.size()>0 && mat[0].size()!=0) {
		std::sort(mat.begin(), mat.end(), [](const std::vector<decltype(*p1+0)> &x, const std::vector<decltype(*p1+0)> &y)
		{  if(x[0]!=y[0] && x[0]>y[0]) return true; 
		if(x[0]==y[0]) return (x[1]>y[1]);
		return (x[0]>y[0]);
		return false;
		}
		);
} 
	return mat;
}




int main ()
{

	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<long long int> d1;
//	d1.resize(n);
	std::cout<<"Unesite elemente prvog kontejnera: ";
int broj=0;
	bool ima=true; for(int i=0; i<n; i++) {  ima=false; long long int el;
	std::cin>>el; if(broj==0) { broj++; d1.push_back(el);  continue; }
	else {
		for(int j=0; j<d1.size(); j++) { if(d1[j]==el) ima=true; }
	if(ima==false) d1.push_back(el); else i--;
	} 
	}
	broj=0;
	std::deque<long long int> d2;
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	ima=true; for(int i=0; i<n1; i++) { ima=false; long long int el;
	std::cin>>el; if(broj==0) { broj++; d2.push_back(el);  continue; }
	else {
		for(int j=0; j<d2.size(); j++) { if(d2[j]==el) ima=true; }
		if(ima==false) d2.push_back(el); else i--;
	} }
	 d2.resize(n1);


 //std::cout<<"Unesite elemente drugog kontejnera: ";

	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	std::vector<std::vector<long long int>> mat;
	mat=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<3; j++) { 
		 std::cout<<std::setw(6)<<mat[i][j]<<" ";  
		}
		std::cout<<std::endl;  }
	
	std::vector<std::vector<long long int>> mat1;
	mat1=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl; 
	for(int i=0; i<mat1.size(); i++) {
		for(int j=0; j<2; j++) { std::cout<<std::setw(6)<<mat1[i][j]<<" "; }  std::cout<<std::endl; 
	}
	std::cout<<"Dovidjenja!"; 
	// main iz autotesta (predugo izvrsavanje): 
	/*
std::deque<int> d1{6, 168, 28, 12}, d2{28, 51, 6, 173};
 std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	} 
	*/
	return 0;
}