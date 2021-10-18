#include <iostream>
#include <vector>
#include <iterator>
#include <type_traits>
#include <algorithm>
#include <iomanip>
#include <deque> 
#include <cmath>
using namespace std;
int SumaDjelilaca(long long int x){
	int suma=0;
	for(long long int i=1;i<=abs(x);i++) if(x%i==0) suma+=i;
	return suma;
}
bool Prost(int x){
	for(int i=2;i<sqrt(abs(x));i++) if(x%i==0) return false;
	return true;
}
int BrojProstihFaktora(long long int x){
	int brojac=0;
	int temp=abs(x);
	for(long long int i=2;i<=temp;i++)
		if(x%i==0)
			if(Prost(i)){
				brojac++;
				x/=i;
				i--;
			} 
	return brojac;
}
bool Savrsen(long long int x){
	long long int suma=0;
	for(long long int i=1;i<abs(x);i++) if(x%i==0) suma+=i;
	return x==suma;
}
int BrojSavrsenihDjelilaca(long long int x){
	long long int brojac=0;
	for(long long int i=1;i<=abs(x);i++)
		if(x%i==0 && Savrsen(i)) brojac++;
	return brojac;
}
int SumaCifara(long long int broj){
	int suma=0;
	while(broj!=0){
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}
template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutiPresjek(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, Tip2 (*Fun)(Tip1))-> vector<vector<typename remove_reference<decltype(*poc1)>::type>> {
	vector<vector<typename remove_reference<decltype(*poc1)>::type>> vektor;
	IterTip2 tempic=poc2;
	while(poc1!=kraj1){
		poc2=tempic;
		while(poc2!=kraj2){
			if(Fun(*poc1)==Fun(*poc2)){
				vector<typename remove_reference<decltype(*poc1)>::type> temp;
				temp.push_back(*poc1); temp.push_back(*poc2); temp.push_back(Fun(*poc1));
				vektor.push_back(temp);
			}
			poc2++;
		}
		poc1++;
	}
	if(vektor.size()==0) return vektor;
	sort(vektor.begin(),vektor.end(),[](vector<typename remove_reference<decltype(*poc1)>::type> v1,vector<typename remove_reference<decltype(*poc1)>::type> v2){
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2] && v1[0]<v2[0])
			return true;
		else if(v1[2]==v2[2] && v1[0]==v2[0] && v1[1]<v2[1]) return true;
		else return false;
		
	});
	return vektor;
}
template <typename IterTip1,typename IterTip2>
auto UvrnutiPresjek(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2)->vector<vector<typename remove_reference<decltype(*poc1)>::type>>{
	vector<vector<typename remove_reference<decltype(*poc1)>::type>> vektor;
	IterTip2 tempic=poc2;
	while(poc1!=kraj1){
		poc2=tempic;
		while(poc2!=kraj2){
			if(*poc1==*poc2){
				vector<typename remove_reference<decltype(*poc1)>::type> temp;
				temp.push_back(*poc1); temp.push_back(0); temp.push_back(0);
				vektor.push_back(temp);
			}
			poc2++;
		}
		poc1++;
	}
	if(vektor.size()==0) return vektor;
	sort(vektor.begin(),vektor.end(),[](vector<typename remove_reference<decltype(*poc1)>::type> v1,vector<typename remove_reference<decltype(*poc1)>::type> v2){
		if(v1[0]<v2[0]) return true;
		return false;
	});
	return vektor;
}
template <typename IterTip1, typename IterTip2>
auto UvrnutaRazlika(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2)->vector<vector<typename remove_reference<decltype(*poc1)>::type>>{
	vector<vector<typename remove_reference<decltype(*poc1)>::type>> vektor;
	bool ima = false;
	for(auto it=poc1; it!=kraj1;it++){
		for(auto it2=poc2;it2!=kraj2;it2++){
			if(*it==*it2){
				ima=false;
				break;
			}
			else ima=true;
		}
		if(ima){
			vector<typename remove_reference<decltype(*poc1)>::type> temp;
			temp.push_back(*it); temp.push_back(0);
			vektor.push_back(temp);
			ima=false;
		}
	}
	ima=false;
	for(auto it2=poc2;it2!=kraj2;it2++){
		for(auto it=poc1;it!=kraj1;it++){
			if(*it==*it2){
				ima=false;
				break;
			}
			else ima=true;
		}
		if(ima){
			vector<typename remove_reference<decltype(*poc1)>::type> temp;
			temp.push_back(*it2); temp.push_back(0);
			vektor.push_back(temp);
			ima=false;
		}
	}
	if(vektor.size()==0) return vektor;
	sort(vektor.begin(),vektor.end(),[](vector<typename remove_reference<decltype(*poc1)>::type> v1, vector<typename remove_reference<decltype(*poc1)>::type> v2){
		if(v1[0]>v2[0]) return true;
		return false;
	});
	return vektor;
}
template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutaRazlika(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, Tip2 (*Fun)(Tip1))-> vector<vector<typename remove_reference<decltype(*poc1)>::type>>{
	vector<vector<typename remove_reference<decltype(*poc1)>::type>> vektor;
	bool ima=false;
	for(auto i=poc1;i!=kraj1;i++){
		for(auto j=poc2;j!=kraj2;j++){
			if(Fun(*i)==Fun(*j)){
				ima=false;
				break;
			} 
			else ima=true;
		}
		if(ima){
			vector<typename remove_reference<decltype(*poc1)>::type> temp;
			temp.push_back(*i); temp.push_back(Fun(*i));
			vektor.push_back(temp);
			ima=false;
		}
	}
	ima=false;
	for(auto j=poc2;j!=kraj2;j++){
		for(auto i=poc1;i!=kraj1;i++){
			if(Fun(*i)==Fun(*j)) {
				ima=false;
				break;
			}
			else ima=true;
		}
		if(ima){
			ima=false;
			vector<typename remove_reference<decltype(*poc1)>::type> temp;
			temp.push_back(*j); temp.push_back(Fun(*j));
			vektor.push_back(temp);
		}
	}
	if(vektor.size()==0) return vektor;
	sort(vektor.begin(),vektor.end(),[](vector<typename remove_reference<decltype(*poc1)>::type> v1, vector<typename remove_reference<decltype(*poc1)>::type> v2){
		if(v1[0]>v2[0]) return true;
		else if(v1[0]==v2[0] && v1[1]>v2[1]) return true;
		return false;
	});
	return vektor;
}
bool imaLiGa(deque<int> dek, int broj){
	for(auto it=dek.begin();it!=dek.end();it++)
		if(*it==broj) return true;
	return false;
}
int main ()
{
	/*vector<int> v1={15,16,17,12,13,14};
	vector<int> v2={31,51,91,71,21,23,24,22};
	auto v=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<setw(6)<<v[i][j];	
		}
		cout<<endl;
	}
	cout<<endl;
	v=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<setw(6)<<v[i][j];	
		}
		cout<<endl;
	}*/
	deque<int> dek1, dek2;
	int broj;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>broj;
	bool ima=false;
	cout<<"Unesite elemente prvog kontejnera: ";
	while(dek1.size()<broj){
		int temp;
		cin>>temp;
		if(imaLiGa(dek1,temp)) continue;
		else dek1.push_back(temp);
	}
	ima=false;
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>broj;
	cout<<"Unesite elemente drugog kontejnera: ";
	while(dek2.size()<broj){
		int temp;
		cin>>temp;
		if(imaLiGa(dek2,temp)) continue;
		else dek2.push_back(temp);
	}
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	auto v=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
	auto v1=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	for(auto x:v){
		for(auto z:x){
			cout<<setw(6)<<z<<" ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	for(auto x:v1){
		for(auto z:x){
			cout<<setw(6)<<z<<" ";
		}
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}