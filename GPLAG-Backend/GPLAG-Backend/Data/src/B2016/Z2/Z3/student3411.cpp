/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <cmath>

template <typename Tip1, typename Tip2, typename TipFunkcije, typename TipParametra>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, TipFunkcije fun(TipParametra)/*=[] (typename std::remove_reference<decltype(*p1)>::type x) {return x;}*/) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*p1)>::type >> matrica;
	Tip1 pomocna1(p1);
	Tip2 pomocna2(p3);
	int br(0);
	while(pomocna1!=p2){
		pomocna2=p3;
		while(pomocna2!=p4){
			//if-uslov koji provjerava da li za date elemente iz blokova podataka funkcija daje istu vrijednost
			//ukoliko je uslov zadovoljen u matricu se smjestaju dobijeni podaci na nacin koji je specifirano u zadatku
			if(fun(*pomocna1)==fun(*pomocna2)){
				br++;
				matrica.resize(br);
				matrica[br-1].resize(3);
				matrica[br-1][0]=*pomocna1;
				matrica[br-1][1]=*pomocna2;
				matrica[br-1][2]=fun(*pomocna1);
			}
			pomocna2++;
		}
		pomocna1++;
	}
	//sortiranje matrice po zadanom poretku
	std::sort(matrica.begin(), matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> q1, std::vector<typename std::remove_reference<decltype(*p1)>::type> q2){
	if(q1[2]<q2[2]) return true; else if(q1[2]>q2[2]) return false; else if(q1[2]==q2[2]){
		if(q1[0]<q2[0]) return true; else if(q1[0]>q2[0]) return false; else if(q1[0]==q2[0]){
			if(q1[1]<q2[1]) return true; else if(q1[1]>q2[1]) return false; else if(q1[1]==q2[1]) return true;
		}
	}});
	return matrica;
}
//Preklapanje funckije UvrnutiPresjek da bi se obezbijedilo njeno funkcionisanje ukoliko se pozove i sa 4 i sa 5 parametara
//Princip rada ove funckije je identican prethodno opisanom 
template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*p1)>::type >> matrica;
	Tip1 pomocna1(p1);
	Tip2 pomocna2(p3);
	int br(0);
	while(pomocna1!=p2){
		pomocna2=p3;
		while(pomocna2!=p4){
			if(*pomocna1==*pomocna2){
				br++;
				matrica.resize(br);
				matrica[br-1].resize(3);
				matrica[br-1][0]=*pomocna1;
				matrica[br-1][1]=0;
				matrica[br-1][2]=0;
			}
			pomocna2++;
		}
		pomocna1++;
	}
	std::sort(matrica.begin(), matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> q1,std::vector<typename std::remove_reference<decltype(*p1)>::type> q2){
	if(q1[0]<=q2[0]) return true; else return false;});
	return matrica;
}
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*p1)>::type >> matrica;
	Tip1 pomocna1(p1);
	Tip2 pomocna2(p3);
	int br(0);
	while(pomocna1!=p2){
		pomocna2=p3;
		bool jednaki(false);
		while(pomocna2!=p4){
			if(*pomocna1==*pomocna2){
				jednaki=true;
				break;
			}
			pomocna2++;
		}
		if(!jednaki){
			br++;
			matrica.resize(br);
			matrica[br-1].resize(2);
			matrica[br-1][0]=*pomocna1;
			matrica[br-1][1]=0;
		}
		pomocna1++;
	}
	pomocna1=p1;
	pomocna2=p3;
	while(pomocna2!=p4){
		pomocna1=p1;
		bool jednaki(false);
		while(pomocna1!=p2){
			if(*pomocna1==*pomocna2){
				jednaki=true;
				break;
			}
			pomocna1++;
		}
		if(!jednaki){
			br++;
			matrica.resize(br);
			matrica[br-1].resize(2);
			matrica[br-1][0]=*pomocna2;
			matrica[br-1][1]=0;
		}
		pomocna2++;
	}
	std::sort(matrica.begin(), matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> q1,std::vector<typename std::remove_reference<decltype(*p1)>::type> q2){
	if(q1[0]<=q2[0]) return false; else return true;});
	return matrica;
}
template <typename Tip1, typename Tip2, typename TipFunkcije, typename TipParametra>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, TipFunkcije fun(TipParametra))-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector< typename std::remove_reference<decltype(*p1)>::type >> matrica;
	Tip1 pomocna1(p1);
	Tip2 pomocna2(p3);
	int br(0);
	//2 ugnijezdene while-petlje koje traze elemente prvog bloka elemenata koji nemaju svog para u drugom bloku elemenata
	while(pomocna1!=p2){
		pomocna2=p3;
		bool jednaki(false);
		while(pomocna2!=p4){
			if(fun(*pomocna1)==fun(*pomocna2)){
				jednaki=true;
				break;
			}
			pomocna2++;
		}
		if(!jednaki){
			br++;
			matrica.resize(br);
			matrica[br-1].resize(2);
			matrica[br-1][0]=*pomocna1;
			matrica[br-1][1]=fun(*pomocna1);
		}
		pomocna1++;
	}
	pomocna1=p1;
	pomocna2=p3;
	//2 ugnijezdene while-petlje koje izvdajaju elemente iz drugog bloka elemenata koji nemaju svog para u prvom bloku
	while(pomocna2!=p4){
		pomocna1=p1;
		bool jednaki(false);
		while(pomocna1!=p2){
			if(fun(*pomocna1)==fun(*pomocna2)){
				jednaki=true;
				break;
			}
			pomocna1++;
		}
		if(!jednaki){
			br++;
			matrica.resize(br);
			matrica[br-1].resize(2);
			matrica[br-1][0]=*pomocna2;
			matrica[br-1][1]=fun(*pomocna2);
		}
		pomocna2++;
	}
	//sortiranje matrice u zadani poredak
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*p1)>::type> q1, std::vector<typename std::remove_reference<decltype(*p1)>::type> q2){
		if(q1[0]>q2[0]) return true; else if(q1[0]<q2[0]) return false; else if(q1[0]==q2[0]){
			if(q1[1]>=q2[1]) return true; else if(q1[1]<q2[1]) return false;
		}
	});
	return matrica;
}

bool Prost(long long int x){
	//PAZI NA OPSEG: KORISTIS ABS
	int kor(sqrt(abs(x)));
	bool prost(true);
	if(x==2) return true;
	if(x==0 || x==1 || x%2==0) return false;
	for(int i=3; i<=kor; i+=2){
		if(x%i==0) {
			prost=false;
			break;
		}
	}
	return prost;
}

int SumaDjelilaca(long long int x){
	int suma(x);
	if(x>=0){
		for(long long int i=1; i<=x/2; i++)
		if(x%i==0) suma+=i;
	}
	if(x<0){
		suma*=-1;
		for(long long int i=1; i<=(-1*(x/2)); i++)
		if(x%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int x){
	int br(0);
	if(x<0) x*=-1;
		for(long long int i=2; i<=(x/2); i++){
			long long int broj(x);
			if(broj%i==0 && Prost(i)){
				while(broj%i==0){
					br++;
					broj/=i;
				}
			}
		}
		if(Prost(x)) br++;
	return br;
}
int BrojSavrsenihDjelilaca(long long int x){
	int br(0);
	 if(x>0){
	for(long long int i=2; i<=x; i++){
		if(x%i==0){
			int djelilac(SumaDjelilaca(i)-i);
			if(i==djelilac) br++;
		}
	}
	}
	else if(x<0){
		for(long long int i=x; i<=-2; i++){
			if(x%i==0){
				int djelilac(1*(SumaDjelilaca(i)-i));
				if(i==djelilac) br++;
			}
		}
	}
	return br;
}

int ZbirCifara(long long int x){
	int suma(0);
	if(x>0){
		while(x>0){
			suma+=x%10;
			x/=10;
		}
	}
	if(x<0){
		while(x<0){
			suma+=x%10;
			x/=10;
		}
	//	suma*=-1;
	}
	return suma;
}
int main ()
{	int n1,n2,br1(0),br2(0);
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> v1(n1);
	for(int i=0; i<n1; i++){
		int x;
		std::cin>>x;
		if(!(std::count(v1.begin(), v1.begin()+br1,x))) {
			v1[i]=x;
			br1++;
		}
		else i--;
	}
	v1.resize(br1);
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> v2(n2);
	for(int i=0; i<n2; i++){
		int x;
		std::cin>>x;
		if(!(std::count(v2.begin(), v2.begin()+br2,x))){
			v2[i]=x;
			br2++;
		}
		else i--;
	}
	v2.resize(br2);
	/*std::vector<std::vector<int>>*/ auto a(UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),ZbirCifara));
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout<<std::right<<std::setw(6)<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	auto a1(UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora));
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0; i<a1.size(); i++){
		for(int j=0; j<a1[i].size(); j++){
			std::cout<<std::right<<std::setw(6)<<a1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}