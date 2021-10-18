/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<type_traits>

using namespace std;

long long int SumaDjelilaca(int x)
{
	int suma=0;
	for(int i=1;i<=x;i++){
		if(x%i==0) suma+=i;
	}
	return suma;
}
long long int SumaCifara(int x){
	int suma=0;
	while(x!=0){
		int cifra=x%10;
		if(cifra<0) cifra*=(-1);
		suma+=cifra;
		x/=10;
	}
	return suma;
}
bool JelProst(int x){
	if(x<2) return false;
	for(int i=2;i<x/2;i++)
	if(x%i==0) return false;
	return true;
}
long long int BrojProstihFaktora(int x){
	long long int brojac(0);
	int i(2);
	while(x!=1 && x!=-1){
		if(JelProst(i) && (x%i==0)){
			brojac++;
			x/=i;
			i=1;
		}
		i++;
	}
	return brojac;
}
bool JelSavrsen(int x){
	int suma=0;
	for(int i=1;i<x;i++)
	if(x%i==0) suma+=i;
	return(x==suma);
}
long long int BrojSavrsenihDjelilaca(int x){
	int brojac(0);
	for(int i=1;i<=x;i++){
	if(JelSavrsen(i) && (x%i==0)) brojac++;
}
return brojac;
}

template<typename pokit1,typename pokit2,typename tip>

auto UvrnutiPresjek(pokit1 p1,pokit1 p2,pokit2 p3,pokit2 p4,tip f)->vector<vector<typename remove_reference<decltype(*p1)>::type>>{
	vector<vector<typename remove_reference<decltype(*p1)>::type>>matrica;
	auto pamtip1(p1);
	auto pamtip3(p3);
	while(p1!=p2){
		p3=pamtip3;
		while(p3!=p4){
			if((*f)(*p1)==(*f)(*p3)){
				vector<typename remove_reference<decltype(*p1)>::type> pomocni(3);
				pomocni[0]=*p1;
				pomocni[1]=*p3;
				pomocni[2]=(*f)(*p1);
				matrica.push_back(pomocni);
			}
			p3++;
		}
		p1++;
	}
	sort(matrica.begin(),matrica.end(),[](vector<typename remove_reference<decltype(*p1)>::type>v1,vector<typename remove_reference<decltype(*p1)>::type>v2)->bool{
		if(v1[2]>v2[2]) return false;
		else if(v1[2]<v2[2]) return true;
		else{
			if(v1[0]>v2[0]) return false;
			else if(v1[0]<v2[0]) return true;
			else{
				if(v1[1]>v2[1])  return false;
				else return true;
			}
		}
	});
	return matrica;
}

template<typename pokit1,typename pokit2>

auto UvrnutiPresjek(pokit1 p1,pokit1 p2,pokit2 p3,pokit2 p4)->vector<vector<typename remove_reference<decltype(*p1)>::type>>{
	vector<vector<typename remove_reference<decltype(*p1)>::type>>matrica;
	auto pamtip1(p1);
	auto pamtip3(p3);
	while(p1!=p2){
		p3=pamtip3;
		while(p3!=p4){
			if((*p1)==(*p3)){
				vector<typename remove_reference<decltype(*p1)>::type>pomocni(3);
				pomocni[0]=*p1;
				pomocni[1]=0;
				pomocni[2]=0;
				matrica.push_back(pomocni);
			}
			p3++;
		}
		p1++;
	}
	sort(matrica.begin(),matrica.end(),[](vector<typename remove_reference<decltype(*p1)>::type>v1,vector<typename remove_reference<decltype(*p1)>::type>v2)->bool{
		return v1[0]<v2[0];
	});
	return matrica;
}

template<typename pokit1,typename pokit2,typename tip>

auto UvrnutaRazlika(pokit1 p1,pokit1 p2,pokit2 p3,pokit2 p4,tip f)->vector<vector<typename remove_reference<decltype(*p1)>::type>>{
	vector<vector<typename remove_reference<decltype(*p1)>::type>>matrica;
	auto pamtip1(p1);
	auto pamtip3(p3);
	while(p1!=p2){
		bool stavi=true;
		p3=pamtip3;
		while(p3!=p4){
			if((*f)(*p1)==(*f)(*p3)){
				stavi=false;
			}
			p3++;
		}
		if(stavi){
			vector<typename remove_reference<decltype(*p1)>::type>pomocni(2);
			pomocni[0]=*p1;
			pomocni[1]=(*f)(*p1);
			matrica.push_back(pomocni);
		}
		p1++;
	}
	p1=pamtip1;
	p3=pamtip3;
	while(p3!=p4){
		bool stavi=true;
		p1=pamtip1;
		while(p1!=p2){
			if((*f)(*p1)==(*f)(*p3)){
				stavi=false;
				
			}
			p1++;
		}
		if(stavi){
			vector<typename remove_reference<decltype(*p1)>::type>pomocni(2);
			pomocni[0]=*p3;
			pomocni[1]=(*f)(*p3);
			matrica.push_back(pomocni);
		}
		p3++;
	}
	sort(matrica.begin(),matrica.end(),[](vector<typename remove_reference<decltype(*p1)>::type>v1,vector<typename remove_reference<decltype(*p1)>::type>v2)->bool{
		if(v1[0]>v2[0]) return true;
		else if(v1[0]<v2[0]) return false;
		else{
			return v1[1]>v2[1];
		}
	});
	return matrica;
}

template<typename pokit1,typename pokit2>

auto UvrnutaRazlika(pokit1 p1,pokit1 p2,pokit2 p3,pokit2 p4)->vector<vector<typename remove_reference<decltype(*p1)>::type>>{
	vector<vector<typename remove_reference<decltype(*p1)>::type>>matrica;
	
	auto pamtip1(p1);
	auto pamtip3(p3);
	while(p1!=p2){
		bool stavi=true;
		p3=pamtip3;
		while(p3!=p4){
			if((*p1)==(*p3)){
				stavi=false;
				
			}
			p3++;
		}
		if(stavi){
			vector<typename remove_reference<decltype(*p1)>::type>pomocni(2);
			pomocni[0]=*p1;
			pomocni[1]=0;
			matrica.push_back(pomocni);
		}
		p1++;
	}
	p1=pamtip1;
	p3=pamtip3;
	while(p3!=p4){
		bool stavi=true;
		p1=pamtip1;
		while(p1!=p2){
			if((*p1)==(*p3)){
				stavi=false;
			}
			p1++;
		}
		if(stavi){
			vector<typename remove_reference<decltype(*p1)>::type>pomocni(2);
			pomocni[0]=*p3;
			pomocni[1]=0;
			matrica.push_back(pomocni);
		}
		p3++;
	}
	sort(matrica.begin(),matrica.end(),[](vector<typename remove_reference<decltype(*p1)>::type>v1,vector<typename remove_reference<decltype(*p1)>::type>v2)->bool{
		return v1[0]>v2[0];
	});
	return matrica;
}


int main()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	cin>>n;
	deque<int>d1(n);
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n;i++){
		cin>>d1[i];
		for(int j=0;j<i;j++){
			if(d1[i]==d1[j]){
				i--;
				break;
			}
		}
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	cin>>n2;
	deque<int>d2(n2);
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n2;i++){
		cin>>d2[i];
		for(int j=0;j<i;j++){
			if(d2[i]==d2[j]){
				i--;
				break;
			}
		}
	}
	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	auto x=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
	for(auto a:x){
		for(auto b:a) cout<<setw(6)<<b<<" ";
		cout<<endl;
	}
	auto s=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	for(auto a:s){
		for(auto b:a) cout<<setw(6)<<b<<" ";
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}


