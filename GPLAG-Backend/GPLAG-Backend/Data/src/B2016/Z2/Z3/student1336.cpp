/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <vector>

int SumaDjelilaca (long long int n){
	int suma(0);
	if(n<0)n=n*(-1);
	for(int i(1); i<=n/2; i++){
		if(n%i==0) suma=suma+i;
	}
	suma=suma+n;
	return suma;
}



int BrojProstihFaktora(long long int n){
	int bpf(0);
	if(n<0) n=n*(-1);
	for(int i(2); i<=n; i++){
		
		
		bool prost(true);
		for(int j(2); j<=i/2; j++){
			if(i%j==0) prost=false;
		}
		if(prost==false) continue;
		while(n%i==0) {
			n=n/i;
			bpf++;
			if(n==0) break;
		}
		
	}
	
	return bpf;
}


int BrojSavrsenihDjelilaca (long long int n){
	int bsd(0);
	if(n<0) n=n*(-1);
	for(int i(1); i<=n; i++ ){
		int suma(0);
		if(n%i==0){
			for(int j(1); j<=i/2; j++){
				if(i%j==0) suma=suma+j;
			}
			if(i==suma) bsd++;		}
		 
	}
	return bsd;
}

int SumaCifara(long long int n){
	int suma(0);
	if(n<0) n=n*(-1);
	while(n!=0){
		suma=suma+n%10;
		n=n/10;
	}
	return suma;
}



template <typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutiPresjek (tip1 p1, tip1 k1, tip2 p2, tip2 k2, tip3 (*f)(tip4)=([](tip3 x) {return x;})() ) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>> {
	int  redovi(0);
	auto pk1(p1);
	
	bool obicno(false);
	while(pk1!=k1){
		auto pk2(p2);
		while((pk2)!=k2){
			if(f(*pk1)==f(*pk2)) redovi++;
			if(f(*pk1)==f(*pk2) && *pk1!=*pk2) obicno=false;
			pk2++;
		}
		pk1++;
	}
	
	
	std::vector<std::vector<decltype(*p1+*p2)>> mat(redovi, std::vector<decltype(*p1+*p2)>(3));
	if(redovi!=0){
		redovi=0;
		while(p1!=k1){
			auto pk2(p2);
			while(pk2!=k2){
			
				if(obicno && f(*p1)==f(*pk2) ){
					mat.at(redovi).at(0)=*p1; mat.at(redovi).at(1)=0; mat.at(redovi).at(2)=0; redovi++;
				}
				else if(f(*p1)==f(*pk2)){
					mat.at(redovi).at(0)=*p1; mat.at(redovi).at(1)=*pk2; mat.at(redovi).at(2)=f(*p1); redovi++;
				} 
				pk2++;
			}
			p1++;
		}
	}
	 std::sort(mat.rbegin(), mat.rend(), [] ( std::vector<decltype(*p1+*p2)> x, std::vector<decltype(*p1+*p2)> y ){ if(x.at(2)!=y.at(2)) return x.at(2)>y.at(2);
																														if(x.at(0)!=y.at(0)) return x.at(0)>y.at(0);
																														return x.at(1)>y.at(1);});
	
	return mat;
}

template <typename T1, typename T2, typename T3, typename  T4>
auto UvrnutaRazlika (T1 p1, T1 k1, T2 p2, T2 k2, T3 (*f)(T4)=([](T4 x) {return x;} )() ) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>>{
	
	int redovi(0);
	auto pk1(p1);
	auto pk2(p2);
	while(pk1!=k1){
		auto pk2(p2);
		bool nemapojave(true);
		while(pk2!=k2){
			if( f(*(pk1))==f(*pk2)) nemapojave=false;
			pk2++;
		}
		if(nemapojave) redovi++;
		pk1++;
	}
	
	
	auto pkk2(p2);
	
	while(pkk2!=k2){
		auto pkk1(p1);
		bool nemapojave(true);
		while(pkk1!=k1){
			if( f(*pkk1) == f(*pkk2) ) nemapojave=false;
			pkk1++;
		}
		if(nemapojave) redovi++; pkk2++;
	}
	
	std::vector<std::vector<decltype(*p1+*p2)>> mat(redovi, std::vector<decltype(*p1+*p2)>(2));
	
	
	int i(0);
	auto a1(p1);
	
	while(a1!=k1){
		auto b2(p2);
		bool nemapojave(true);
		while(b2!=k2){
			if(f(*a1)==f(*b2))
				 nemapojave=false;
				 
			b2++;
		}
		if(nemapojave){
			mat[i][0]=*(a1); mat[i][1]=f(*a1); i++;
		}
		a1++;
		
	}
	auto b2(p2);
	while(b2!=k2){
		auto p(p1);
		bool nemapojave(true);
		while(p!=k1){
			if(f(*p)==f(*b2)) 
				nemapojave=false;
			p++;
		}
		if(nemapojave){
			mat[i][0]=*b2; mat[i][1]=f(*b2); i++;
		}
		b2++;
	}
	
	typename std::remove_reference<decltype(*p1+*p2)>::type prva(mat[0][0]);
	bool vjednako(true);
	for(int j(1); j<redovi; j++){
		if(mat[j][0]!=prva) {
			vjednako=false;
			break;
		}
	}
	if(vjednako){
		std::sort(mat.begin(), mat.end(), [](std::vector<decltype(*p1+*p2)> x, std::vector<decltype(*p1+*p2)> y) {return x.at(1)>y.at(1); });
	}
	else std::sort(mat.begin(), mat.end(), []( std::vector<decltype(*p1+*p2)> x,  std::vector<decltype(*p1+*p2)> y) { return x.at(0)>y.at(0); } );
	
	return mat;
}

void UnosKontejnera(std::deque<int> &kont, int n){
	for(int i(0); i<n; i++){
		int t;
		std::cin>>t;
		bool ponavljanje(false);
		for(int j(0); j<int(kont.size()); j++ ){
			if(t==kont.at(j)){
				ponavljanje=true;
				
			}
		}
		if(ponavljanje){
			i--;
			continue;
		}
		kont.push_back(t);
	}

}



int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> prvi;
	UnosKontejnera(prvi,n);
	
	
	
	
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin>>m;
	
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> drugi;
	UnosKontejnera(drugi,m);
	
	
	auto presjek(UvrnutiPresjek(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), SumaCifara ));
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(std::vector<int> x: presjek){
		for(int y: x) std::cout<<std::setw(6)<<y<<" ";
		std::cout<<std::endl;
	}

	auto razlika(UvrnutaRazlika(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), BrojProstihFaktora ));
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(std::vector<int> x: razlika){
		for(int y: x) std::cout<<std::setw(6)<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	
	
	
	
	return 0;
}