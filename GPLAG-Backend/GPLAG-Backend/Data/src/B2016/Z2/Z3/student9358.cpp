/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <cmath>

template <typename itertip1, typename itertip2, typename tip, typename povtip>
auto UvrnutiPresjek(itertip1 poc1, itertip1 izakraja1, itertip2 poc2, itertip2 izakraja2, povtip funkcija(tip)) -> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> Matrica;
	for(itertip1 i=poc1;i<izakraja1;i++){
	    for(itertip2 j=poc2;j<izakraja2;j++){
	        if(funkcija(*i)==funkcija(*j)) {
	        	std::vector<typename std::remove_reference<decltype(*poc1)>::type> v;
	            v.push_back(*i);                         //dodavanje elemenata u vektor, zatim vektora u matricu//                     
	            v.push_back(*j);
	            v.push_back(funkcija(*i));
	            Matrica.push_back(v);
	        }
	    }
	}
	//sortiranje vektora matrice po zadanom kriteriju//
	std::sort(Matrica.begin(),Matrica.end(),[] (const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a, const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b) 
	{
		if(a[2]!=b[2]) return a[2]<b[2];
		else if(a[2]==b[2] && a[0]!=b[0]) return a[0]<b[0];
		return a[1]<b[1];
	});
	return Matrica;
}

template <typename itertip1, typename itertip2>                            //obicni presjek//
auto UvrnutiPresjek(itertip1 poc1, itertip1 izakraja1, itertip2 poc2, itertip2 izakraja2) -> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> Matrica;
	for(itertip1 i=poc1;i<izakraja1;i++){
		for(itertip2 j=poc2;j<izakraja2;j++){
			if(*i==*j){
				std::vector<typename std::remove_reference<decltype(*poc1)>::type> v;
				v.push_back(*i);
				v.push_back(0);
				v.push_back(0);
				Matrica.push_back(v);
			}
		}
	}
	std::sort(Matrica.begin(),Matrica.end(), [] (const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a, const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b)
	{
		return(a[0]<b[0]);
	});
	return Matrica;
}


template <typename itertip1, typename itertip2, typename tip, typename povtip>
auto UvrnutaRazlika(itertip1 poc1, itertip1 izakraja1, itertip2 poc2, itertip2 izakraja2, povtip funkcija(tip)) -> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> Matrica;
	bool postoji=false;
	for(itertip1 i=poc1;i<izakraja1;i++){                    //provjera za elemente prvog bloka da li imaju svoj par u drugom bloku
		postoji=false;
		for(itertip2 j=poc2;j<izakraja2;j++){
			if(funkcija(*i)==funkcija(*j)) {postoji=true; break;}   //ako postoji element za koji je zadovoljen uslov, ne treba ga smjestati u matricu
		}
		if(postoji==false){
			std::vector<typename std::remove_reference<decltype(*poc1)>::type> v;
	     	v.push_back(*i);                                  //smjestanje elemenata koji nemaju svog "para"
			v.push_back(funkcija(*i));
			Matrica.push_back(v);
		}
	}
	postoji=false;
	for(itertip2 i=poc2;i<izakraja2;i++){                     //provjera za elemente drugog bloka da li imaju svoj par u prvom bloku
		postoji=false;
		for(itertip1 j=poc1;j<izakraja1;j++){
			if(funkcija(*i)==funkcija(*j)) {postoji=true; break;}
		}
		if(postoji==false){
			std::vector<typename std::remove_reference<decltype(*poc2)>::type> v1;
			v1.push_back(*i);
			v1.push_back(funkcija(*i));
			Matrica.push_back(v1);
		}
	}
	//sortiranje dobijene matrice po zadanom kriteriju
	std::sort(Matrica.begin(),Matrica.end(),[] (const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a, const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b){
		if(a[0]!=b[0]) return a[0]>b[0];
		else return a[1]<b[1];
	});
	return Matrica;
}

template<typename itertip1, typename itertip2>
auto UvrnutaRazlika(itertip1 poc1, itertip1 izakraja1, itertip2 poc2, itertip2 izakraja2) -> std::vector<std::vector< typename std::remove_reference<decltype(*poc1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> Matrica;
	bool postoji=false;
	for(itertip1 i=poc1;i<izakraja1;i++){
		postoji=false;
		for(itertip2 j=poc2;j<izakraja2;j++){
			if(*i==*j) {postoji=true;break;}
		}
		if(postoji==false){
			std::vector<typename std::remove_reference<decltype(*poc1)>::type> v;
			v.push_back(*i);
			v.push_back(0);
			Matrica.push_back(v);
		}
	}
	postoji=false;
	for(itertip2 i=poc2;i<izakraja2;i++){
		postoji=false;
		for(itertip1 j=poc1;j<izakraja1;j++){
			if(*i==*j) {postoji=true;break;}
		}
		if(postoji==false){
			std::vector<typename std::remove_reference<decltype(*poc2)>::type> v1;
			v1.push_back(*i);
			v1.push_back(0);
			Matrica.push_back(v1);
		}
	}
	std::sort(Matrica.begin(), Matrica.end(), [] (const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &a, const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &b){
    return a[0]>b[0];		
	});
	
	return Matrica;
}
	
int SumaCifara(long long int a){
	int suma=0;
	while(a!=0){
		suma=suma+a%10;
		a=a/10;
	}
    return suma;
}

int BrojProstihFaktora(long long int a){
	int broj(0);
	for(int i=2;i<=a;i++){
		if(a%i==0) {
			broj++;
			a=a/i;
		}
		while(a%i==0){
			a=a/i;
			broj++;
		}
	}
	return broj;
}

int SumaDjelilaca(long long int a){
	int suma(0);
	for(int i=1;i<=std::abs(a);i++){
		if(std::abs(a)%i==0) suma=suma+i;
	}
	return suma;
}

int BrojSavrsenihDjelilaca(long long int a){
	int br(0), suma(0);
	for(int i=1;i<=std::abs(a);i++){
		suma=0;
		if(std::abs(a)%i==0){
			for(int j=1;j<i;j++){
				if(i%j==0) suma=suma+j;
			}
		if(i==suma) br++;
		}
	}
	return br;
}

int main ()
{   std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    int n1,n2;
    std::cin>>n1;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    int broj;
    bool postoji=false;
    std::deque<int> v1;
    std::deque<int> v2;
    for(int i=0;i<n1;i++){
    	postoji=false;
    	std::cin>>broj;
    	for(int j=0;j<v1.size();j++){
    		if(v1[j]==broj) {postoji=true; i--;}
    	}
    	if(postoji==false) v1.push_back(broj);
    }
    std::cout<<"Unesite broj elemenata drugog kontejnera: ";
    std::cin>>n2;
    std::cout<<"Unesite elemente drugog kontejnera: ";
    for(int i=0;i<n2;i++){
    	postoji=false;
    	std::cin>>broj;
    	for(int j=0;j<v2.size();j++){
    		if(v2[j]==broj) {postoji=true;i--;}
    	}
    	if(postoji==false) v2.push_back(broj);
    }
    auto Matrica=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara);
    std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
    for(int i=0;i<Matrica.size();i++){
    	for(int j=0;j<3;j++){
    		std::cout<<std::right<<std::setw(6)<<Matrica[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }
    auto Matrica1=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora);
    std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    for(int i=0;i<Matrica1.size();i++){
    	for(int j=0;j<2;j++){
    		std::cout<<std::right<<std::setw(6)<<Matrica1[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }
    std::cout<<"Dovidjenja!"<<std::endl;
	return 0;
}