/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<deque>
#include<vector>
#include<type_traits>
#include<iterator>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
template <typename Tip1, typename Tip2, typename TipFunkc, typename TipVrac> 
vector<vector<TipVrac>> UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, TipFunkc (*f) (TipVrac)=nullptr)
 {
	vector<vector<TipVrac>> Matrix;
	
	for(int i{0}; i<distance(poc1,kraj1); i++){
		
		for(int j{0}; j<distance(poc2,kraj2); j++){
			std::vector<TipVrac>red ;
			if(f!=nullptr){
			if (f(*(poc1+i))==f(*(poc2+j))){
				red.push_back(*(poc1+i));
				red.push_back(*(poc2+j));
				red.push_back(f(*(poc1+i)));
				Matrix.push_back(red);
			}
			}else{
				if(*(poc1+i)==*(poc2+j)){
					red.push_back(*(poc1+i));
					red.push_back(0);
					red.push_back(0);
					Matrix.push_back(red);
				}
			}
			
		}
		
	}
	
	sort(begin(Matrix),
	end(Matrix),
	[](vector<TipVrac> a, vector<TipVrac> b){
		
		if(a.at(2)!=b.at(2))	return a.at(2)<b.at(2);
		
		if(a.at(0)!=b.at(0))	return a.at(0)<b.at(0);
		
		if(a.at(1)!=b.at(1))	return a.at(1)<b.at(1);
	});
	return Matrix;
}
template <typename Tip1, typename Tip2, typename TipFunkc, typename TipVrac>
vector<vector<TipVrac>> UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, TipFunkc (*f) (TipVrac)=nullptr)
{
	vector<vector<TipVrac>> Matrix;
	
	for(int i{0}; i<distance(poc1, kraj1); i++){
		
		for(int j{0}; j<distance(poc2, kraj2); j++){
			std::vector<TipVrac>red ;
			if(f!=nullptr){
				//Ukoliko je proslijedjena fkt neka funkcija 
				//A ne idemo po defaultu
				int prebrojani{0};
				for(; prebrojani<distance(poc2,kraj2); prebrojani++ ){
					if(f(*(poc1+i))==f(*(poc2+j))) break;
				}
				if(prebrojani==distance(poc2,kraj2)){
					red.push_back(*(poc1+i));
					red.push_back(f(*(poc1+i)));
					Matrix.push_back(red);
				}
			} else {
				int prebrojani{0};
				for(; prebrojani<distance(poc2, kraj2); prebrojani++){
					if(*(poc1+i)==*(poc2+j)) break;
					if(prebrojani==distance(poc2,kraj2)){
						red.push_back(*(poc1+i));
						red.push_back(0);
						Matrix.push_back(red);
					}
				}
			}
		}
		
		
	}
	sort(begin(Matrix), end(Matrix),
	[](vector<TipVrac>  a, vector<TipVrac> b){
		if(a.at(0) != b.at(0) ) return a.at(0)<b.at(0);
		return a.at(1)<b.at(1);
	});
	
	return Matrix;
}
int SumaDjelilaca (long long int x){
	int suma{0};
	for(long long int i{0}; i<x/2; i++ ){
		//Uslov djeljivosti
		if(x % i ==0) suma+=i;
	}
	return suma;
}
bool IsPrime( long long int x ){
	int num_divisors{0};
	if(x==2) return true;
	for( long long int i{1}; i<=sqrt(x); i+=2){
		if(x%i==0) num_divisors++;
		if(num_divisors>2) return false;
	}
	return true;
}
int BrojProstihFaktora( long long int x){
	int br_prostih{0};
	for(long long int i{1}; i<x; i++){
		if(x%i==0 && IsPrime(i)) {br_prostih++;x/=i;i--;}
	}
	return br_prostih;
}
int BrojSavrsenihDjelilaca( long long int x ){
	int br_savrsenih{0};
	for(long long int i{2}; i<=x; i++){
		if(x%i==0){
			//  auto pom ( x );
			long long int suma_djelilaca{0};
			for(long long int i{1}; i<x; i++) if (x%i==0)suma_djelilaca++;
			if(suma_djelilaca==x) br_savrsenih++;
		}
	}
	return br_savrsenih;
}
int SumaCifara(int x){
	int suma{0};
	while(x>0){ suma+=x%10; x=x/10; }
	return suma;
}

int main (){
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	cin>>n;
	deque<int> dek1(n);
	int br_pon{0};
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i{0}; i<n; i++){
		int x;
		cin>>x;
		if(binary_search(begin(dek1), end(dek1), x)) {br_pon++; continue;}
		dek1.at(i)=x;
	}
	dek1.resize(n-br_pon);
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	cin>>m;
	deque<int> dek2;
	cout<<"Unesite elemente drugog kontejnera: ";
	br_pon=0;
	for(int i{0}; i<m; i++){
		
		int x;
		cin>>x;
		if(binary_search(begin(dek2),end(dek2), x)) {br_pon++;continue;}
		dek2.at(i)=x;
	}
	dek2.resize(m-br_pon);
	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	auto Presjek = UvrnutiPresjek( begin(dek1), end(dek1), begin(dek2), end(dek2), SumaCifara );
	for(auto red : Presjek){
		for(auto x : red ){
			cout<<setw(6)<<x;
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	auto Razlika ( UvrnutaRazlika( begin(dek1), end(dek1), begin(dek2), end(dek2),  BrojProstihFaktora ));
	for(auto red : Razlika){
		for( auto x:red ){
			cout<<setw(6)<<x;
		}
		cout<<endl;
	}
	return 0;
}