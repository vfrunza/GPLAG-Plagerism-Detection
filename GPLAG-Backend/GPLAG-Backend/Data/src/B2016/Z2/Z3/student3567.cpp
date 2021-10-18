#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<type_traits>
using namespace std;
template<typename T3,typename T4>
T4 ObicanPresjek(T3 broj){
	return 1;
}
template<typename T1,typename T2,typename T3,typename T4>
vector<vector<T3>> UvrnutiPresjek(T1 p1,T1 p2, T2 p3,T2 p4, T4 f(T3)=ObicanPresjek ) {
	vector<vector<T3>> mat;
	if(f(*p1)==f(*p2)==1)
	{
		int br(0);
	while(p1!=p2){
		T2 pom=p3;
		while(p3!=p4){
			if(*p1==*p3){
				br++;
				mat.push_back({*p1});
			}
		pom++;	
		}
		p1++;
	}
	return mat;
}
else{
	int br(0);
	while(p1!=p2){
		T2 pom=p3;
		while(p3!=p4){
			if(f(*p1)==f(*p3)){
				br++;
				mat.push_back({*p1,*pom,f(*p1)});
			}
		pom++;	
		}
		p1++;
	}
	for(int i(0);i<br;i++){
		for(int j(0);j<3;j++)
			sort(mat.begin(),mat.end(),[] (T3 x,T3 y) { return x[2]> y[2];});
		}

	return mat;
}
}
int SumaDjelilaca(long long int broj){
	int suma(0);
	for(unsigned int i(1);i<broj;i++){
		if(broj%i==0) suma+=i;
	}
	suma+=broj;
	return broj;
}
int BrojProstihFaktora (long long int broj){
	int br(0);
	for(int i(2);i<10;i++){
		if(broj%i==0) br++;
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int broj){
	int br(0);
	for(int i(1);i<broj;i++){
	if(broj%i==0){
		int suma(0);
		for(int j(2);j<i;j++){
			if(i%j==0) suma+=j;
		}
		if(suma==i) br++;
	}
}
return br;
}

int main ()
{
	int n,m;
	int broj;
	deque<int> niz1;
	deque<int> niz2;
	vector<vector<int>> m1;
	vector<vector<int>> n1;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0);i<n;i++){
	cin>> broj;
	niz1.push_back(broj);
}
cout<<"Unesite broj elemenata drugog kontejnera: ";
cin>>m;
cout<<"Unesite elemente drugog kontejnera: ";
for(int j(0);j<n;j++){
	cin>>broj;
	niz2.push_back(broj);
}
cout<<"Uvrnuti presjek kontejnera: ";
m1=UvrnutiPresjek(niz1.begin(),niz1.end(),niz2.begin(),niz2.end());
for(int i(0);i<m1.size();i++){
	for(int j(0);j<m1[i].size();j++)
	cout<<m1[i][j];
	cout<<endl;
}
cout<<"Uvrnuta razlika kontejnera: ";
	return 0;
}