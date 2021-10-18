/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <iomanip>
#include <algorithm>

int SumaDjelilaca(long long int x){
	int suma=fabs(x);
	//if(x<0)x*=-1;
	//x=fabs(x);
	for(int i=1;i<=fabs(x/2);i++){
		if(x%i==0)suma+=i;
	}
	return suma;
}
int prost(long long x) {
    int p;
    for (p = 2; p <= x / 2; p++) {
        if (x / p * p == x) {
            return p;
        }
    }
    return 1;
}
int BrojProstihFaktora(long long int x){
	int faktor;
    int br=1;
    faktor = prost(x);
    while (faktor > 1) {
        x = x / faktor;
        faktor = prost(x);
        br++;
    }
    return br;
}
bool Savrsen(int n){
	int suma=0;
    for(int i=1;i<n;i++){
        if(n%i==0)suma+=i;
    }
    return suma==n;
}
int BrojSavrsenihDjelilaca(long long int x){
	if(x<0)x*=-1;
	int br=0;
	for(long long int i=1;i<=x;i++){
		if( x%i==0 && Savrsen(i))br++;
	}
	return br;
}
int Suma(long long int x){
	int suma=0;
	while(x>0){
		suma+=x%10;x/=10;
	} return suma;
}
template <typename tip1,typename tip2>
auto UvrnutiPresjek(tip1 poc1,tip1 kraj1,tip2 poc2,tip2 kraj2 )-> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>> m;
	while(poc1!=kraj1){
		//std::cout<<fun(*poc1)<<fun(*poc2);
		auto a=*poc1;
		//tip2 *as=poc2;
		tip2 as=poc2;
		while(poc2!=kraj2){
			auto b=*poc2;
			//if(dalijecetiriparametra==false){
			if(a==b){
				std::vector< typename std::remove_reference<decltype(*poc1)>::type> v;
				v.push_back(a);
				v.push_back(0);
				v.push_back(0);
				m.push_back(v);
			}
			poc2++;
		}
		poc1++;
		poc2=as;
	}
	std::sort(m.begin(),m.end(),[](std::vector< typename std::remove_reference<decltype(*poc1)>::type> v,std::vector<typename std::remove_reference<decltype(*poc1)>::type>b){
		if(fabs(v[2])==fabs(b[2])){
			if(fabs(v[0])==(b[0])){
				return fabs(v[1])<fabs(b[1]);
			}
			else return fabs(v[0])<fabs(b[0]);
		}
		else return fabs(v[2])<fabs(b[2]);
	});
	return m;
}
template <typename tip1,typename tip2,typename tipp,typename tip>
auto UvrnutiPresjek(tip1 poc1,tip1 kraj1,tip2 poc2,tip2 kraj2,tipp fun (tip) )-> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>> m;
	while(poc1!=kraj1){
		//std::cout<<fun(*poc1)<<fun(*poc2);
		auto a=*poc1;
		//tip2 *as=poc2;
		tip2 as=poc2;
		while(poc2!=kraj2){
			auto b=*poc2;
			//if(dalijecetiriparametra==false){
			if( fun(a)==fun(b) ){
				std::vector< typename std::remove_reference<decltype(*poc1)>::type>v ;
				v.push_back(a);
				v.push_back(b);
				v.push_back(fun(a));
				//std::cout<<"dda"<<v.size();
				m.push_back(v);
			}
			
			poc2++;
		}
		poc1++;
		poc2=as;
	}
	std::sort(m.begin(),m.end(),[](std::vector< typename std::remove_reference<decltype(*poc1)>::type> v,std::vector<typename std::remove_reference<decltype(*poc1)>::type>b){
		if(fabs(v[2])==fabs(b[2])){
			if(fabs(v[0])==(b[0])){
				return fabs(v[1])<fabs(b[1]);
			}
			else return fabs(v[0])<fabs(b[0]);
		}
		else return fabs(v[2])<fabs(b[2]);
	});
	return m;
}
template <typename tip1,typename tip2>
auto UvrnutaRazlika(tip1 poc1,tip1 kraj1,tip2 poc2, tip2 kraj2)-> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>> m;
	tip1 fa=poc1;
	while(poc1!=kraj1){
		//std::cout<<fun(*poc1)<<fun(*poc2);
		auto a=*poc1;
		//tip2 *as=poc2;
		tip2 as=poc2;
		bool g=true;
		while(poc2!=kraj2){
			auto b=*poc2;
			if( a==b ){g=false;
				/*std::vector<int>v ;
				v.push_back(a);
				v.push_back(b);
				v.push_back(fun(a));
				//std::cout<<"dda"<<v.size();
				m.push_back(v);*/
			}
			
			poc2++;
		}
		if(g){
				std::vector< typename std::remove_reference<decltype(*poc1)>::type>v ;
				v.push_back(a);
				v.push_back(0);
				m.push_back(v);
			}
		poc1++;
		poc2=as;
	}
	poc1=fa;
	while(poc2!=kraj2){
		//std::cout<<fun(*poc1)<<fun(*poc2);
		auto a=*poc2;
		//tip2 *as=poc2;
		tip1 as=poc1;
		bool g=true;
		while(poc1!=kraj1){
			auto b=*poc1;
			if( a==b ){g=false;
				/*std::vector<int>v ;
				v.push_back(a);
				v.push_back(b);
				v.push_back(fun(a));
				//std::cout<<"dda"<<v.size();
				m.push_back(v);*/
			}
			
			poc1++;
		}
		 if(g){
				std::vector< typename std::remove_reference<decltype(*poc1)>::type>v ;
				v.push_back(a);
				v.push_back(0);
				m.push_back(v);
			}
		poc2++;
		poc1=as;
	}
	std::sort(m.begin(),m.end(),[](std::vector<typename std::remove_reference<decltype(*poc1)>::type> v,std::vector<typename std::remove_reference<decltype(*poc1)>::type>b){
		if(v[0]==b[0]){
			return v[1]>b[1];
		}
		else return v[0]>b[0];
	});
	return m;
}
template <typename tip1,typename tip2,typename tip,typename tipp>
auto UvrnutaRazlika(tip1 poc1,tip1 kraj1,tip2 poc2,tip2 kraj2 ,tipp fun (tip))-> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>> m;
	tip1 fa=poc1;
	while(poc1!=kraj1){
		//std::cout<<fun(*poc1)<<fun(*poc2);
		auto a=*poc1;
		//tip2 *as=poc2;
		tip2 as=poc2;
		bool g=true;
		while(poc2!=kraj2){
			auto b=*poc2;
			if( fun(a)==fun(b) ){g=false;
				/*std::vector<int>v ;
				v.push_back(a);
				v.push_back(b);
				v.push_back(fun(a));
				//std::cout<<"dda"<<v.size();
				m.push_back(v);*/
			}
			
			poc2++;
		}
		if(g ){
				std::vector< typename std::remove_reference<decltype(*poc1)>::type>v ;
				v.push_back(a);
				v.push_back(fun(a));
				m.push_back(v);
			}
			
		poc1++;
		poc2=as;
	}
	poc1=fa;
	while(poc2!=kraj2){
		//std::cout<<fun(*poc1)<<fun(*poc2);
		auto a=*poc2;
		//tip2 *as=poc2;
		tip1 as=poc1;
		bool g=true;
		while(poc1!=kraj1){
			auto b=*poc1;
			if( fun(a)==fun(b) ){g=false;
				/*std::vector<int>v ;
				v.push_back(a);
				v.push_back(b);
				v.push_back(fun(a));
				//std::cout<<"dda"<<v.size();
				m.push_back(v);*/
			}
			
			poc1++;
		}
		if(g ){
				std::vector< typename std::remove_reference<decltype(*poc1)>::type>v ;
				v.push_back(a);
				v.push_back(fun(a));
				m.push_back(v);
			}
			
		poc2++;
		poc1=as;
	}
	std::sort(m.begin(),m.end(),[](std::vector<typename std::remove_reference<decltype(*poc1)>::type> v,std::vector<typename std::remove_reference<decltype(*poc1)>::type>b){
		if(v[0]==b[0]){
			return v[1]>b[1];
		}
		else return v[0]>b[0];
	});
	return m;
}
int main ()
{
	//std::cout<<BrojSavrsenihDjelilaca(1);
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<double>a,b;
	double br;
	for(int i=0;i<n;i++){
		std::cin>>br;
		if(find(a.begin(),a.end(),br)==a.end())
		a.push_back(br);
		else i--;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin>>m;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<m;i++){
		std::cin>>br;
		if(find(b.begin(),b.end(),br)==b.end())
		b.push_back(br);
		else i--;
	}
	std::vector<std::vector<double>> mat=UvrnutiPresjek(a.begin(), a.end(), b.begin(), b.end(),Suma
	);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++)
		std::cout<<std::setw(6)<<mat[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::vector<std::vector<double>> ma{UvrnutaRazlika(a.begin(), a.end(), b.begin(), b.end(), BrojProstihFaktora)};
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0;i<ma.size();i++){
		for(int j=0;j<ma[i].size();j++)
		std::cout<<std::setw(6)<<ma[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}