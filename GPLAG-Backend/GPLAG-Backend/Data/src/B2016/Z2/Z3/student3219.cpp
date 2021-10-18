/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include <iomanip>

using namespace std;

template <typename T1,typename T2,typename T3,typename T4>

vector<vector<T3> > UvrnutiPresjek(T1 p1, T1 k1, T2 p2, T2 k2, T3 f(T4)) {
	vector<vector<T3> > mat;
	while(p1!=k1) {
		T2 p=p2;
		while(p!=k2) {
			if(f(*p1) == f(*p)) {
				vector<T3> vec;
				vec.push_back(*p1);
				vec.push_back(*p);
				vec.push_back(f(*p1));
				mat.push_back(vec);
			}
			p++;
		}
		p1++;
	}
	
	(mat.begin(), mat.end(), [](vector<T3> x, vector<T3> y) {
		if(x[2]!=y[2]) return x[2]<y[2]; 
		else if(x[0]!=y[0]) return x[0]<y[0]; 
		else return x[1]<y[1];
	});
	return mat;
	
}
template <typename P1,typename P2>
auto UvrnutiPresjek(P1 p1, P1 k1, P2 p2, P2 k2) -> vector<vector<decltype(*p1+0)> > {
	vector<vector<decltype(*p1+0)> > mat;						// *p1+0 se može koristiti umjesto remove refference, zato što tipovi s kojima mi radimo podržavaju sabiranje, a reference ne
	P1 p=p1;
	while(p1!=k1) {
		P2 p=p2;
		while(p!=k2) {
			if(*p==*p1) {
				mat.push_back({*p,0,0});
			}
			p++;
		}
		p1++;
	}
	sort(mat.begin(), mat.end(), [](vector<decltype(*p+0)> x,vector<decltype(*p+0)> y) { return x[0]<y[0];});
	return mat;
}

template <typename T1,typename T2,typename T3,typename T4>
vector<vector<T3> > UvrnutaRazlika(T1 p1, T1 k1, T2 p2, T2 k2, T3 f(T4)) {
	
	vector<vector<T3> > mat;
	vector<T3> vec;
	T1 pom1=p1;
	T2 pom2=p2;
	bool ima=false;
	while(pom1!=k1) {
		ima=false;
		pom2=p2;
		while(pom2!=k2) {
			if(f(*pom1) == f(*pom2)) ima=true;
			pom2++;
		}
		if(!ima) {
			vec.push_back(*pom1);
			vec.push_back(f(*pom1));
			mat.push_back(vec);
			vec.resize(0);
		}
		pom1++;
	}
	pom1=p1; pom2=p2;
	while(pom2!=k2) {
		ima=false;
		pom1=p1;
		while(pom1!=k1) {
			if(f(*pom1) == f(*pom2)) ima=true;
				
			pom1++;
		}
		if(!ima) {
			vec.push_back(*pom2);
			vec.push_back(f(*pom2));
			mat.push_back(vec);
			vec.resize(0);
		}
		pom2++;
	}
	sort(mat.begin(), mat.end(), [](vector<T3> a, vector<T3> b) {if(a[0]!=b[0]) return a[0]>b[0]; else return a[1]>b[1]; });
	return mat;
}
template <typename T1, typename T2>

auto UvrnutaRazlika(T1 p1, T1 k1, T2 p2, T2 k2) -> vector<vector<decltype(*p1+0)> > {
	vector<vector<decltype(*p1+0)> > mat;						// *p1+0 se može koristiti umjesto remove refference, zato što tipovi s kojima mi radimo podržavaju sabiranje, a reference ne
	T1 pom1=p1;
	T2 pom2=p2;
	while(pom1!=k1) {
		pom2=p2;
		bool nema=true;
		while(pom2!=k2) {
			if(*pom1==*pom2) nema=false;
			
			pom2++;	
		}
		if(nema) {
			mat.push_back({*pom1,0});
		}
		pom1++;
	}
	pom1=p1; pom2=p2;
	while(pom2!=k2) {
		pom1=p1;
		bool nema=true;
		while(pom1!=k1) {
			if(*pom1==*pom2) nema=false;
			
			pom1++;	
		}
		if(nema) {
			mat.push_back({*pom2,0});
		}
		pom2++;
	}
	sort(mat.begin(), mat.end(), [](vector<decltype(*p1+0)>  x, vector<decltype(*p1+0)>  y) { return x[0]>y[0];});
	return mat;
}

int SumaDjelilaca(long long int broj) {
	int suma=0;
	if(broj<0) broj=-broj;
	for(int i(1);i<=broj;i++){
		if(broj%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int broj) {
	int brojac=0;
	while(broj>=2) {
		for(int i(2);i<=broj;i++) {
			if(broj%i==0) {
				brojac++;
				broj/=i;
				break;
			}
		}
	}
	return brojac;
}
bool SavrsenBroj(long long int broj) {
	long long int suma=0;
	for(int i(1);i<broj;i++) {
		if(broj%i==0) suma+=i;
	}
	return (suma==broj);
}
int BrojSavrsenihDjelilaca(long long int broj) {
	int brojac=0;
	for(int i(2);i<=broj;i++) {
		if(broj%i==0) {
			if(SavrsenBroj(i)) brojac++;
		}
	}
	return brojac;
}

int SumaCifara(long long int broj) {
	int suma=0;
	while(broj!=0) {
		suma+=(broj%10);
		broj=broj/10;
	}
	return suma;
}

int main ()
{
	cout<< "Unesite broj elemenata prvog kontejnera: ";
	int n; cin>>n;
	cout<< "Unesite elemente prvog kontejnera: ";
	deque<int> dek;
	int i=0,k;
	
	while(i<n) {
		cin>> k;
		bool ima=false;
		for(int j(0);j<dek.size();j++) {
			if (dek[j]==k) ima=true;
		}
		if(!ima) { dek.push_back(k); i++; }
		
	}
	
	cout<< "Unesite broj elemenata drugog kontejnera: ";
	int n1;
	cin>>n1;
	cout<< "Unesite elemente drugog kontejnera: ";
	deque<int> dek1;
	i=0;
	
	while(i<n1) {
		cin>> k;
		bool ima=false;
		for(int j(0);j<dek1.size();j++) {
			if (dek1[j]==k) ima=true;
		}
		if(!ima) { dek1.push_back(k); i++; }
	}
	
	cout << "Uvrnuti presjek kontejnera:\n";
	vector<vector<int> > mat;
	mat=UvrnutiPresjek(dek.begin(),dek.end(),dek1.begin(),dek1.end(),SumaCifara);
	for(int i(0);i<mat.size();i++) {
		for(int j(0);j<mat[i].size();j++) {
			cout << setw(6) << mat[i][j]<< " ";
		}
		cout << endl;
	}
	cout << "Uvrnuta razlika kontejnera:\n";
	vector<vector<int> > mat1;
	mat1=UvrnutaRazlika(dek.begin(),dek.end(),dek1.begin(),dek1.end(),BrojProstihFaktora);
	for(int i(0);i<mat1.size();i++) {
		for(int j(0);j<mat1[i].size();j++) {
			cout << setw(6) << mat1[i][j]<<" " ;
		}
		cout<< endl;
	}
	cout << "Dovidjenja!";
	return 0;
}