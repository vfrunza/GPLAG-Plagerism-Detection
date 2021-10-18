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
#include <cmath>

int SumaCifara(long long int n){
	int suma(0);
	while(n!=0){
		suma+=(n%10);
		n/=10;
	}
	return suma;
}
bool ProstBroj (int n){
	if(n<=1) return false;
	if(n%2==0) return false;
	int a(std::sqrt(n)+1);
	for(int i(2); i<a; i++){
		if(n%i==0) return false;
	}
	return true;
}
int SumaDjelilaca(long long int n){
	int suma(n+1);
	for(long long int i(2); i<=n/2; i++){
		if(n%i==0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora (long long int n){
	int brojac(0);
	int i(2);
	while(n!=1){
		if(ProstBroj(i) && (n%i==0)){
			brojac++;
			n/=i;
			i--;
		}
		i++;
	}
	return brojac;
}
bool Savrsen(int n){
	int suma=0;
    for(int i(1); i<=n/2; i++){
        if (int(n) % i == 0) suma+=i;
    }
    if(suma==n) return true;
    return false;
        
}
int BrojSavrsenihDjelilaca(long long int n ){
	int brojac(0);
	int i(1);
	while(n!=1){
		if(Savrsen(i) && (n%i==0)){
			brojac++;
			n/=i;
			i--;
		}
		i++;
	}
	return brojac;
}
template <typename ItTip1, typename ItTip2>
auto UvrnutiPresjek(ItTip1 poc, ItTip1 ikraj, ItTip2 poc1, ItTip2 ikraj1) ->std::vector<std::vector<decltype(*poc+*poc)>>{
	
	std::vector<decltype(*poc+*poc)> v;
	while(poc++!=ikraj){
		while(poc1++!=ikraj1){
			if(*poc==*poc1) v.push_back(*poc);
		}
	}
	std::vector<std::vector<decltype(*poc+*poc)>> mat;
	
	for(int i(0); i<v.size(); i++){
		for(int j(0); j<3; j++){
			if(j==0) mat[i][j]=v.at(i);
			else mat[i][j]=0;
		}
	}
	return mat;
	
}

template <typename ItTip1, typename ItTip2, typename Tip2, typename Tip3>
auto UvrnutiPresjek(ItTip1 poc, ItTip1 ikraj, ItTip2 poc1, ItTip2 ikraj1, Tip2 f (Tip3)) -> std::vector<std::vector<decltype(*poc + *poc)>>{
	
	std::vector<decltype(*poc + *poc)> x;
	std::vector<decltype(*poc1+ *poc1)>y;
	std::vector<Tip2>z;
	while(poc!=ikraj){
		while(poc1!=ikraj1){
			if(f(*poc)==f(*poc1)) {x.push_back(*poc); y.push_back(*poc1); z.push_back(f(*poc));}
			poc1++;
		}
		poc++;
	}
	std::vector<std::vector<decltype(*poc + *poc)>> mat;
	mat.resize(std::min(x.size(), y.size()));
	for(int i(0); i<mat.size(); i++){
		mat[i].resize(3);
	}
	
	for(int i(0); i<std::min(x.size(), y.size()); i++){
		for(int j(0); j<3; j++){
			if(j==0) mat[i][j]=x.at(i);
			else if( j==1) mat[i][j]=y.at(i);
			else mat[i][j]=z.at(i);
		}
	}
	std::sort(mat.begin(), mat.end(), [] (const std::vector<decltype(*poc+*poc)> &x, const std::vector<decltype(*poc+*poc)> &y){
										if (x[2]==y[2]){
											if(x[0]==y[0]) return x[1]>y[1];
											return x[0]<y[0];
										}
										return (x[2]>y[2]); } );
	
	return mat;
}
template <typename ItTip1, typename ItTip2>
auto UvrnutaRazlika(ItTip1 poc, ItTip1 ikraj, ItTip2 poc1, ItTip2 ikraj1) -> std::vector<std::vector<decltype(*poc+*poc)>>{
	ItTip1 pomocna(poc);
	ItTip2 pomocna1(poc1);
	std::vector<decltype(*poc+*poc)> x, y;
	while(poc++!=ikraj){
		poc1=pomocna1;
		while(poc1++!=ikraj1){
			if(*poc==*poc1) break;
		}
		if(poc1==ikraj1) x.push_back(*poc), y.push_back(0);
	}
	poc=pomocna;
	poc1=pomocna1;
	while(poc1++!=ikraj1){
		poc=pomocna;
		while(poc++!=ikraj){
			if(*poc1==*poc) break;
		}
		if(poc==ikraj) x.push_back(*poc1),  y.push_back(0);
	}
	
	poc=pomocna;
	poc1=pomocna1;
	
	std::sort(x.begin(), x.end());
	x.erase( unique( x.begin(), x.end() ), x.end() );
	
	std::vector<std::vector<decltype(*poc+*poc)>> mat;
	
	mat.resize(x.size());
	for(int i(0); i<mat.size(); i++){
		mat[i].resize(2);
	}
	
	for(int i(0); i<x.size(); i++){
		for(int j(0); j<2; j++){
			if(j==0) mat[i][j]=x.at(i);
			else mat[i][j]=f(x.at(i));
		}
	}
	std::sort(mat.begin(), mat.end(), [] (const std::vector<decltype(*poc+*poc)> &x, const std::vector<decltype(*poc+*poc)> &y){
										if (x[0]==y[0]) return x[1]>y[1];
										return (x[0]>y[0]); } );
	
	return mat;
}
template <typename ItTip1, typename ItTip2, typename Tip2, typename Tip3>
auto UvrnutaRazlika(ItTip1 poc, ItTip1 ikraj, ItTip2 poc1, ItTip2 ikraj1, Tip2 f (Tip3)) -> std::vector<std::vector<decltype(*poc+*poc)>>{
	ItTip1 pomocna(poc);
	ItTip2 pomocna1(poc1);
	std::vector<decltype(*poc+*poc)> x, y;
	while(poc++!=ikraj){
		poc1=pomocna1;
		while(poc1++!=ikraj1){
			if(f(*poc)==f(*poc1)) break;
		}
		if(poc1==ikraj1) x.push_back(*poc), y.push_back(f(*poc));
	}
	poc=pomocna;
	poc1=pomocna1;
	while(poc1++!=ikraj1){
		poc=pomocna;
		while(poc++!=ikraj){
			if(f(*poc1)==f(*poc)) break;
		}
		if(poc==ikraj) x.push_back(*poc1),  y.push_back(f(*poc1));
	}
	
	poc=pomocna;
	poc1=pomocna1;
	
	std::sort(x.begin(), x.end());
	x.erase( unique( x.begin(), x.end() ), x.end() );
	
	std::vector<std::vector<decltype(*poc+*poc)>> mat;
	
	mat.resize(x.size());
	for(int i(0); i<mat.size(); i++){
		mat[i].resize(2);
	}
	
	for(int i(0); i<x.size(); i++){
		for(int j(0); j<2; j++){
			if(j==0) mat[i][j]=x.at(i);
			else mat[i][j]=f(x.at(i));
		}
	}
	std::sort(mat.begin(), mat.end(), [] (const std::vector<decltype(*poc+*poc)> &x, const std::vector<decltype(*poc+*poc)> &y){
										if (x[0]==y[0]) return x[1]<y[1];
										return (x[0]<y[0]); } );
	
	return mat;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::vector<double> a(n);
	for(int i(0); i<n; i++) {
		int temp;
		int j;
		std::cin>>temp;
		for(j=0; j<i; j++){
			if (temp==a[j]) break;
		}
		if(j==i) a[i]=temp;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int p;
	std::cin>>p;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::vector<double> b(p);
	for(int i(0); i<p; i++) {
		int temp;
		int j;
		std::cin>>temp;
		for(j=0; j<i; j++){
			if (temp==b[j]) break;
		}
		if(j==i) b[i]=temp;
	}
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::vector<std::vector<double>> mat;
	mat=UvrnutiPresjek(a.begin(), a.end(), b.begin(), b.end(), SumaCifara);
	for(int i(0); i<mat.size(); i++){
		for(int j(0); j<mat[i].size(); j++){
			std::cout<<std::setw(6)<<mat[i][j]<<std::endl;
		}
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	std::vector<std::vector<double>> mat1;
	mat1=UvrnutaRazlika(a.begin(), a.end(), b.begin(), b.end(), SumaCifara);
	for(int i(0); i<mat1.size(); i++){
		for(int j(0); j<mat1[i].size(); j++){
			std::cout<<std::setw(6)<<mat1[i][j]<<std::endl;
		}
	}
	
	
		
		
	return 0;
}