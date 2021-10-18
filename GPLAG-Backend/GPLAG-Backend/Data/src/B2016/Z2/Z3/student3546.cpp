#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
bool Prost(long long int x){
	for(int i=2;i<=std::sqrt(x);i++){
		if(x%i==0)
		return false;
	}
	return true;
}
int SumaDjelilaca(long long int x){
	int suma(0);
	for(int i=1;i<=std::abs(x);i++){
		if(std::abs(x)%i==0)
		suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int x){
	int brojac(1);
	for(int i=2;i<=std::sqrt(x);i++){
		if(x%i==0 && Prost(i)){
		brojac++;
		x/=i;
		i--;
		}
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int x){
	int brojac(0);
	for(int i=1;i<=x;i++){
		if(x%i==0 && SumaDjelilaca(i)-i==i)
		brojac++;
	}
	return brojac;
}
int SumaCifara(long long int x){
	int suma(0);
	do{
		suma+=x%10;
		x/=10;
	}while(x!=0);
	return suma;
}
template <typename tip1,typename tip2, typename itertip1, typename itertip2>
auto UvrnutiPresjek(itertip1 it1,itertip1 it2,itertip2 it3,itertip2 it4,tip1 f(tip2))-> std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>> mat;
	int brojac(0);
	auto it(it3);
	while(it1!=it2){
		it=it3;
		while(it!=it4){
			if(f(*it1)==f(*it)){
				brojac++;
				mat.resize(brojac);
				mat[brojac-1].resize(3);
				mat[brojac-1][0]=*it1;
				mat[brojac-1][1]=*it;
				mat[brojac-1][2]=f(*it1);
			}
			it++;
		}
		it1++;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2)-> bool{
		if(v1[2]<v2[2]) return true;
		else if(v1[2]>v2[2]) return false;
		else{
			if(v1[0]<v2[0]) return true;
			else if(v1[0]>v2[0]) return false;
			else{
				if(v1[1]<v2[1]) return true;
				else return false;
			}
		}
	});
	return mat;
}

template <typename itertip1, typename itertip2>
auto UvrnutiPresjek(itertip1 it1,itertip1 it2,itertip2 it3,itertip2 it4)-> std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>> mat;
	int brojac(0);
	auto it(it3);
	while(it1!=it2){
		it=it3;
		while(it!=it4){
			if(*it1==*it){
				brojac++;
				mat.resize(brojac);
				mat[brojac-1].resize(3);
				mat[brojac-1][0]=*it1;
				mat[brojac-1][1]=0;
				mat[brojac-1][2]=0;
			}
			it++;
		}
		it1++;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2)-> bool{
		if(v1[2]<v2[2]) return true;
		else if(v1[2]>v2[2]) return false;
		else{
			if(v1[0]<v2[0]) return true;
			else if(v1[0]>v2[0]) return false;
			else{
				if(v1[1]<v2[1]) return true;
				else return false;
			}
		}
	});
	return mat;
}

template <typename tip1,typename tip2,typename itertip1, typename itertip2>
auto UvrnutaRazlika(itertip1 it1,itertip1 it2,itertip2 it3,itertip2 it4,tip1 f(tip2))-> std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>> mat;
	auto it(it3);
	auto it5(it1);
	int brojac(0);
	while(it1!=it2){
		it=it3;
		while(it!=it4){
			if(f(*it1)==f(*it))
			break;
			it++;
		}
		if(it==it4){
			brojac++;
			mat.resize(brojac);
			mat[brojac-1].resize(2);
			mat[brojac-1][0]=*it1;
			mat[brojac-1][1]=f(*it1);
		}
		it1++;
	}
	auto it6(it5);
	while(it3!=it4){
		it6=it5;
		while(it6!=it2){
			if(f(*it3)==f(*it6))
			break;
			it6++;
		}
		if(it6==it2){
			brojac++;
			mat.resize(brojac);
			mat[brojac-1].resize(2);
			mat[brojac-1][0]=*it3;
			mat[brojac-1][1]=f(*it3);
		}
		it3++;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2)->bool{
	if(v1[0]>v2[0]) return true;
	else if(v1[0]<v2[0]) return false;
	else{
		if(v1[1]>v2[1]) return true;
		else return false;
	}
	});
	return mat;
}

template <typename itertip1, typename itertip2>
auto UvrnutaRazlika(itertip1 it1,itertip1 it2,itertip2 it3,itertip2 it4)-> std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>> mat;
	auto it(it3);
	auto it5(it1);
	int brojac(0);
	while(it1!=it2){
		it=it3;
		while(it!=it4){
			if(*it1==*it)
			break;
			it++;
		}
		if(it==it4){
			brojac++;
			mat.resize(brojac);
			mat[brojac-1].resize(2);
			mat[brojac-1][0]=*it1;
			mat[brojac-1][1]=0;
		}
		it1++;
	}
	auto it6(it5);
	while(it3!=it4){
		it6=it5;
		while(it6!=it2){
			if(*it3==*it6)
			break;
			it6++;
		}
		if(it6==it2){
			brojac++;
			mat.resize(brojac);
			mat[brojac-1].resize(2);
			mat[brojac-1][0]=*it3;
			mat[brojac-1][1]=0;
		}
		it3++;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2)->bool{
	if(v1[0]>v2[0]) return true;
	else if(v1[0]<v2[0]) return false;
	else{
		if(v1[1]>v2[1]) return true;
		else return false;
	}
	});
	return mat;
}

int main ()
{
	int n1;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n1;
	cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<long long int> d1;
	long long int broj;
	for(int i=0;i>-1;i++){
		if(d1.size()==n1)
		break;
		cin>>broj;
		bool pronadjen(false);
		for(int j=0;j<d1.size();j++){
			if(d1[j]==broj){
				pronadjen=true;
				break;
			}
		}
		if(!pronadjen)
		d1.push_back(broj);
	}
	int n2;
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n2;
	cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<long long int> d2;
	for(int i=0;i>-1;i++){
		if(d2.size()==n2)
		break;
		cin>>broj;
		bool pronadjen(false);
		for(int j=0;j<d2.size();j++){
			if(d2[j]==broj){
				pronadjen=true;
				break;
			}
		}
		if(!pronadjen)
		d2.push_back(broj);
	}
	auto mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
	cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<3;j++){
			cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	auto mat2=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	for(int i=0;i<mat2.size();i++){
		for(int j=0;j<2;j++){
			cout<<std::setw(6)<<mat2[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Dovidjenja!";
	return 0;
}