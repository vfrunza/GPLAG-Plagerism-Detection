/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <cmath>
#include <algorithm>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

typedef std::vector<long long int> IV;

template<typename Neki>
bool Provjera(long long int x, Neki vec){
	for(long long int i((vec.size())-1);i>=0;i--)
		if(x==vec[i]) return false;
	return true;
}


int Suma(long long int x){
	if(x==0){return 0;}
	return std::abs(x%10) + Suma(x/10);
}


//Iduuu funkcijee

int SumaDjelilaca(long long int x){
	int suma(0);
	if(x<0) x=-x;
	for(long long int i(1);i<=x;i++)
		if(x%i==0) suma+=i;
		
	return suma;
}

bool DaLiJeProst (long long int n){
	for(int i(2);i<=std::sqrt(n);i++){
		if(n%i==0)  {return false;}
	}
	return true;

}

int BrojProstihFaktora(long long int x){
	int br(0);
    for(long long int i(2);i<= x;i++){
    	
    	if((x%i==0)&& DaLiJeProst(i)){
    		br++;
    		x/=i;
    		i--;
    	}
    	if(x==0) break;
    }
	
	
	return br;
}

bool Savrsen(long long int n){
	long long int suma(0);
	for(long long int i=n;i>=1;i--){
                if(n%i==0) suma=suma+i;
                
            }
            suma=suma-n;
       if(suma==n) return true;
       else return false;
}

int BrojSavrsenihDjelilaca (long long int x){
	int br(0);
	for(int i(2);i<=x;i++)
		if(x%i==0){
			if(Savrsen(i))
			  br++;
		}
	
	return br;
}





template<typename Nesto1, typename Nesto3, typename Nesto4>
	auto UvrnutiPresjek (Nesto1 poc1, Nesto1 izakraja1, Nesto3 poc2,Nesto3 izakraja2,Nesto4 F) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
		typedef typename std::remove_reference<decltype(*poc1)>::type RR;
		std::vector<std::vector<RR>> mat(0,std::vector<RR>(3));
		int si(1);
		Nesto3 pomocni2(poc2);
	//	Nesto1 pomocni1(poc1);
		for(int i(0);izakraja1!=poc1;i++){
			auto br1(F(*poc1));
			for(int j(0);izakraja2!=poc2;j++){
				auto br2(F(*poc2));
				if(br1==br2){
					
					mat.resize(si);
					mat[si-1].push_back(*poc1);
					mat[si-1].push_back(*poc2);
					mat[si-1].push_back(int(F(*poc2)));
					si++;
					
				}
				poc2++;
			}
			poc1++;
			poc2=pomocni2;
		}
		std::sort(mat.begin(),mat.end(),[](std::vector<RR> x, std::vector<RR> y){
			if(x[2]==y[2]) {
				if(x[0]==y[0]){
					return x[1]<y[1];
				}else return x[0]<y[0];
				}
				else return x[2]<y[2];
			
		});
		return mat;
	}
template<typename Nesto1, typename Nesto3, typename Nesto4>
	auto UvrnutaRazlika (Nesto1 poc1, Nesto1 izakraja1, Nesto3 poc2,Nesto3 izakraja2,Nesto4 f) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
		typedef typename std::remove_reference<decltype(*poc1)>::type RR;
		std::vector<std::vector<RR>> mat(0,std::vector<RR>(2));
	
		int si(1);
		Nesto3 pomocni2(poc2);
		Nesto1 pomocni1(poc1);
		for(int i(0);izakraja1!=poc1;i++){
			
			int br1(f(*poc1));
			bool ima(false);
			for(int j(0);izakraja2!=poc2;j++){
				int br2(f(*poc2));
				if(br1==br2){
					ima=true;
					break;
				}
				poc2++;
			}
			if(!ima){
				mat.resize(si);
					mat[si-1].push_back(*poc1);
					mat[si-1].push_back(int(f(*poc1)));
					si++;
			}
			poc1++;
			poc2=pomocni2;
		}
		poc1=pomocni1;
		poc2=pomocni2;
		for(int i(0);izakraja2!=poc2;i++){
			
			int br2(f(*poc2));
			bool ima(false);
			for(int j(0);izakraja1!=poc1;j++){
				int br1(f(*poc1));
				if(br1==br2){
					ima=true;
					break;
				}
				poc1++;
			}
			if(!ima){
				mat.resize(si);
					mat[si-1].push_back(*poc2);
					mat[si-1].push_back(f(*poc2));
					si++;
			}
			poc2++;
			poc1=pomocni1;
		}
	std::sort(mat.begin(),mat.end(),[](std::vector<RR> x, std::vector<RR> y){
			
			if(x[0]==y[0]) {
				 return x[1]>y[1];
				
				}
				else return x[0]>y[0];
			
		});
		
	
	return mat;
}
template<typename Nesto1, typename Nesto3>
	auto UvrnutiPresjek (Nesto1 poc1, Nesto1 izakraja1, Nesto3 poc2,Nesto3 izakraja2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
		typedef typename std::remove_reference<decltype(*poc1)>::type RR;
		std::vector<std::vector<RR>> mat(0,std::vector<RR>(3));
		int si(1);
		Nesto3 pomocni2(poc2);
		for(int i(0);izakraja1!=poc1;i++){
			for(int j(0);izakraja2!=poc2;j++){
				if(*poc1==*poc2){
					mat.resize(si);
					mat[si-1].push_back(*poc1);
					mat[si-1].push_back(0);
					mat[si-1].push_back(0);
					si++;
					
				}
				poc2++;
			}
			poc1++;
			poc2=pomocni2;
		}
		std::sort(mat.begin(),mat.end(),[](std::vector<RR> x, std::vector<RR> y){
			return x[0]<y[0];
		});
		return mat;
	}

template<typename Nesto1, typename Nesto3>
	auto UvrnutaRazlika (Nesto1 poc1, Nesto1 izakraja1, Nesto3 poc2,Nesto3 izakraja2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
		typedef typename std::remove_reference<decltype(*poc1)>::type RR;
		std::vector<std::vector<RR>> mat(0,std::vector<RR>(2));
	
		int si(1);
		Nesto3 pomocni2(poc2);
		Nesto1 pomocni1(poc1);
		for(int i(0);izakraja1!=poc1;i++){
			
			int br1(*poc1);
			bool ima(false);
			for(int j(0);izakraja2!=poc2;j++){
				int br2(*poc2);
				if(br1==br2){
					ima=true;
					break;
				}
				poc2++;
			}
			if(!ima){
				mat.resize(si);
					mat[si-1].push_back(*poc1);
					mat[si-1].push_back(0);
					si++;
			}
			poc1++;
			poc2=pomocni2;
		}
		poc1=pomocni1;
		poc2=pomocni2;
		for(int i(0);izakraja2!=poc2;i++){
			
			int br2(*poc2);
			bool ima(false);
			for(int j(0);izakraja1!=poc1;j++){
				int br1(*poc1);
				if(br1==br2){
					ima=true;
					break;
				}
				poc1++;
			}
			if(!ima){
				mat.resize(si);
					mat[si-1].push_back(*poc2);
					mat[si-1].push_back(0);
					si++;
			}
			poc2++;
			poc1=pomocni1;
		}
	std::sort(mat.begin(),mat.end(),[](std::vector<RR> x, std::vector<RR> y){

				 return x[0]>y[0];

		});
		
	
	return mat;

}
int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	cin>>n;
	IV prvi;
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0);i<n;i++){
		long long int k;
		cin>>k;
		if(Provjera(k,prvi)){
		prvi.push_back(k);
		}else i--;
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	cin>>m;
	IV drugi;
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0);i<m;i++){
		long long int k;
		cin>>k;
		if(Provjera(k,drugi))
		drugi.push_back(k);
		else i--;
	}
	
	auto mat(UvrnutiPresjek(prvi.begin(),prvi.end(),drugi.begin(),drugi.end(),Suma));
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	for(int i(0);i<(mat.size());i++){
		for(int j(0);j<mat[i].size();j++){
			cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	mat = UvrnutaRazlika(prvi.begin(),prvi.end(),drugi.begin(),drugi.end(),BrojProstihFaktora);
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[i].size();j++){
			cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}