/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream> 
#include <sstream>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <type_traits>

using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::vector;



int f(long long int broj) {
	int suma(0),a;
	while(broj!=0) {
		a=broj%10;
		broj=broj/10;
		suma+=a;
	}
	return suma;
}

int SumaDjelilaca(long long int broj) {
	int suma(0);
	if(broj<0) broj*=(-1);
	for(int i=1; i<=broj; i++) 
		if(broj%i==0) suma+=i;
	
	return suma;
}


bool Prost (long long int x) {
	int br(1);
	if(x<=1) return false;
	for(int i=1; i<=std::sqrt(x); i++) {
		if(x%i==0) br++;
		if(br>2) return false;
	}
	if(br==2) return true;	
	
}

bool Savrsen(int x) {
	int br(0);
	
	for(int i=1; i<x; i++) 
		if(x%i==0) br+=i;
	
	if(br==x) return true;
	else return false;
	
}

int BrojSavrsenihDjelilaca(long long int broj){
	long long int suma(0);
	if(broj<0) broj*=(-1);
		for(int i=1; i<=broj; i++) 
			if(broj%i==0 && Savrsen(i)) suma++;
	
	return suma;
}

int BrojProstihFaktora(long long int broj) {
	int suma(0);
	
	for(int i=0; i<=broj; i++) 
		
		if(Prost(i) && broj%i==0) {
			while(broj%i==0) {
				broj=broj/i;
				suma++;
			}
		}
	
	
	return suma;
}

template <typename tip1, typename tip2, typename tip3, typename tip4>
	auto UvrnutiPresjek (tip1 p1, tip1 p2, tip2 q1, tip2 q2, tip3 f(tip4))-> vector<vector<typename std::remove_reference<decltype (*p1)> ::type> > {
		typedef typename std::remove_reference<decltype (*p1)> ::type t;
		vector<vector<t> > mat(100000, vector<t>(3));
		int i(0);
		while(p1!=p2) {
			tip2 q=q1;
			while(q!=q2) {
				if(f(*p1)==f(*q)) {
					mat[i][0]=*p1;
					mat[i][1]=*q;
					mat[i][2]=f(*p1);
		
					i++;
				}
				
				q++;
			}
			p1++;
		}
		mat.resize(i);
		
	
	std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[1]<b[1];});
	std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[0]<b[0];});
	
	std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[2]<b[2];});
		
		
		return mat;	
	}




template <typename tip1, typename tip2, typename tip3, typename tip4>
	auto UvrnutaRazlika (tip1 p1, tip1 p2, tip2 q1, tip2 q2, tip3 f(tip4))-> vector<vector<typename std::remove_reference<decltype (*p1)> ::type> > {
		typedef typename std::remove_reference<decltype (*p1)> ::type t;
		vector<vector<t> > mat(10000, vector<t>(2));
		int i(0),br(0);
		tip1 a=p1;
		while(a!=p2) {
			tip2 q=q1;
			br=0;
			while(q!=q2) {
				if(f(*a)==f(*q)) br++;	
				q++;
			}
			
			if(br==0) {
				mat[i][0]=*a;
				mat[i][1]=f(*a);
				i++;
			}
			a++;
		}
		
		tip2 b=q1;
		while(b!=q2) {
			tip1 q=p1;
			br=0;
			while(q!=p2) {
				if(f(*b)==f(*q)) br++;	
				q++;
			}
			
			if(br==0) {
				mat[i][0]=*b;
				mat[i][1]=f(*b);
				i++;
			}
			b++;
		}
		
		mat.resize(i);
		
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[1]>b[1];});
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[0]>b[0];});
	
		
		return mat;	
	}
	
	
template <typename tip1, typename tip2> 
	auto UvrnutiPresjek (tip1 p1, tip1 p2, tip2 q1, tip2 q2)-> vector<vector<typename std::remove_reference<decltype (*p1)> ::type> > {
		typedef typename std::remove_reference<decltype (*p1)> ::type t;
		vector<vector<t> > mat(100000, vector<t>(3));
		int i(0);
		while(p1!=p2) {
			tip2 q=q1;
			while(q!=q2) {
				if(*p1==*q) {
					mat[i][0]=*p1;
					i++;
				}
				q++;	
			}	
				
			p1++;
		}
		mat.resize(i);
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[1]<b[1];});
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[0]<b[0];});
	
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[2]<b[2];});
		return mat;
	}	
	
	
template <typename tip1, typename tip2>
	auto UvrnutaRazlika (tip1 p1, tip1 p2, tip2 q1, tip2 q2)-> vector<vector<typename std::remove_reference<decltype (*p1)> ::type> > {
		typedef typename std::remove_reference<decltype (*p1)> ::type t;
		vector<vector<t> > mat(10000, vector<t>(2));
		int i(0),br(0);
		tip1 a=p1;
		while(a!=p2) {
			tip2 q=q1;
			br=0;
			while(q!=q2) {
				if(*a==*q) br++;	
				q++;
			}
			
			if(br==0) {
				mat[i][0]=*a;
				i++;
			}
			a++;
		}
		
		tip2 b=q1;
		while(b!=q2) {
			tip1 q=p1;
			br=0;
			while(q!=p2) {
				if(*b==*q) br++;	
				q++;
			}
			
			if(br==0) {
				mat[i][0]=*b;
				i++;
			}
			b++;
		}
		
		mat.resize(i);
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[1]>b[1];});
		std::sort(mat.begin(),mat.end(), [] (vector<t> a, vector<t> b){return a[0]>b[0];});
		return mat;
	}	

int main ()
{
	int a,b;
	deque<long int> d1(0),d2(0);
	deque<long int>::iterator it1;
	deque<long int>::iterator it2;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>a;
	cout<<"Unesite elemente prvog kontejnera: ";
	
	for(int i=0; i<a; i++) {
		long int n;
		cin>>n;
		it1=std::find(d1.begin(),d1.end(),n);
		if(it1==d1.end()) d1.push_back(n);
		else a++;
	
	}


	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>b;
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<b; i++) {
		long int m;
		cin>>m;
		it2=std::find(d2.begin(),d2.end(),m);
		if(it2==d2.end()) d2.push_back(m);
		else b++;
		
		
	}
	cout<<"Uvrnuti presjek kontejnera: "<<endl;;
	
	vector<vector<long int>> mat;
	mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),f);
	
	
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<3; j++) {
			cout<<std::right<<std::setw(6)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	mat=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(), BrojProstihFaktora);
	
	
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<2; j++) {
			cout<<std::right<<std::setw(6)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	cout<<"Dovidjenja!";
	
	
	
	
	return 0;
}






