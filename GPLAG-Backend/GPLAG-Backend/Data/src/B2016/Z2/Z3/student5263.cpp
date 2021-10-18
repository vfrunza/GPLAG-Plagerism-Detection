/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#define EPSILON 0.0001
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;
using std::for_each;
int SumaDjelilaca (long long int n){
	int suma(0);
	if (n<0){
		for(int i=-1;i>n;i--){
			if(n%i==0) suma-=i;
		}
		suma-=n;
		return suma;
	}
	else{
		for(int i=1; i<=n/2;i++){
			if(n%i==0) suma+=i;
		}
		suma+=n;
		return suma;
	}
}
int BrojProstihFaktora (long long int n){
	bool prost(false);
	int broj(n);
	int brojac(0);
	for(int i=2;i<=broj;i++){
		prost=true;
		if(n%i==0){
			if(i==2) prost=true;
			else {
				for(int j=2;j<i;j++){
					if(i%j==0) {prost=false;break;}
				}
			}
			if (prost){
				brojac++;
				n/=i;
				if(n==1) break;
				i=1;
			}
		}
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int n){
	int br(0);
	for(int i=2;i<=n;i++){
		if(n%i==0){
			if(i==(SumaDjelilaca(i)-i))
			br++;
		}
	}
	return br;
}
int f(int x){
	int suma(0);
	while(x!=0){
		suma+=x%10;
		x/=10;
	}
	return suma;
}
template <typename Pokazivaci_1, typename Pokazivaci_2, typename Fun1, typename Fun2>
auto UvrnutiPresjek (Pokazivaci_1 prvi_pocetak, Pokazivaci_1 prvi_kraj, Pokazivaci_2 drugi_pocetak, Pokazivaci_2 drugi_kraj, Fun2 Funkcija (Fun1)) -> vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>>{
	vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>> mat;
	Pokazivaci_2 p(drugi_pocetak);
	while(prvi_pocetak!=prvi_kraj){
		while(drugi_pocetak!=drugi_kraj){
			if(Funkcija(*prvi_pocetak)==Funkcija(*drugi_pocetak)){
				vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> niz(3);
				niz.at(0)=*prvi_pocetak;
				niz.at(1)=*drugi_pocetak;
				niz.at(2)=Funkcija(*prvi_pocetak);
				mat.push_back(niz);
			}
			drugi_pocetak++;
		}
		drugi_pocetak=p;
		prvi_pocetak++;
	}
	sort(mat.begin(), mat.end(), [] (const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &a , const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &b ){if (a[2]!=b[2]) return (a[2]<b[2]); else if(a[0]!=b[0]) return (a[0]<b[0]); else return (a[1]<b[1]);});
	return mat;
}
template <typename Pokazivaci_1, typename Pokazivaci_2, typename Fun1, typename Fun2>
auto UvrnutaRazlika (Pokazivaci_1 prvi_pocetak, Pokazivaci_1 prvi_kraj, Pokazivaci_2 drugi_pocetak, Pokazivaci_2 drugi_kraj, Fun1 Funkcija (Fun2)) -> vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>>{
	vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>> mat;
	Pokazivaci_2 p(drugi_pocetak);
	Pokazivaci_1 q(prvi_pocetak);

	bool postoji (false);
	vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> niz(2);
	while(prvi_pocetak!=prvi_kraj){
		postoji=false;
		while(drugi_pocetak!=drugi_kraj){
			if(Funkcija(*prvi_pocetak)==Funkcija(*drugi_pocetak)){
				postoji = true;
				break;
			}
			drugi_pocetak++;
		}
		if(!postoji){
				niz.at(0)=*prvi_pocetak;
				niz.at(1)=Funkcija(*prvi_pocetak);
				mat.push_back(niz);
		}
		drugi_pocetak=p;
		prvi_pocetak++;
	}
	drugi_pocetak=p;
	prvi_pocetak=q;
	while(drugi_pocetak!=drugi_kraj){
		postoji=false;
		while(prvi_pocetak!=prvi_kraj){
			if(Funkcija(*prvi_pocetak)==Funkcija(*drugi_pocetak)){
				postoji = true;
				break;
			}
			prvi_pocetak++;
		}
		if(!postoji){
				niz.at(0)=*drugi_pocetak;
				niz.at(1)=Funkcija(*drugi_pocetak);
				mat.push_back(niz);
		}
		prvi_pocetak=q;
		drugi_pocetak++;
	}
		sort(mat.begin(), mat.end(), [] (const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &a , const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &b ){if (a[0]!=b[0]) return (a[0]>b[0]); else return (a[1] > b[1] ); });

	return mat;
}
template <typename Pokazivaci_1, typename Pokazivaci_2>
auto UvrnutiPresjek (Pokazivaci_1 prvi_pocetak, Pokazivaci_1 prvi_kraj, Pokazivaci_2 drugi_pocetak, Pokazivaci_2 drugi_kraj) -> vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>>{
	vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>> mat;
	Pokazivaci_2 p(drugi_pocetak);
	while(prvi_pocetak!=prvi_kraj){
		while(drugi_pocetak!=drugi_kraj){
			if(abs(*prvi_pocetak-*drugi_pocetak)<EPSILON){
				vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> niz(3);
				niz.at(0)=*prvi_pocetak;
				niz.at(1)=0;
				niz.at(2)=0;
				mat.push_back(niz);
			}
			drugi_pocetak++;
		}
		drugi_pocetak=p;
		prvi_pocetak++;
	}
	sort(mat.begin(), mat.end(), [] (const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &a , const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &b ){if (abs(a[2]-b[2])>EPSILON) return (a[2]<b[2]); else if(abs(a[0]-b[0])<EPSILON) return (a[0]<b[0]); else return (a[1]<b[1]);});
	return mat;
}
template <typename Pokazivaci_1, typename Pokazivaci_2>
auto UvrnutaRazlika (Pokazivaci_1 prvi_pocetak, Pokazivaci_1 prvi_kraj, Pokazivaci_2 drugi_pocetak, Pokazivaci_2 drugi_kraj) -> vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>>{
	vector<vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type>> mat;
	Pokazivaci_2 p(drugi_pocetak);
	Pokazivaci_1 q(prvi_pocetak);

	bool postoji (false);
	vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> niz(2);
	while(prvi_pocetak!=prvi_kraj){
		postoji=false;
		while(drugi_pocetak!=drugi_kraj){
			if(abs(*prvi_pocetak-*drugi_pocetak)<EPSILON){
				postoji = true;
				break;
			}
			drugi_pocetak++;
		}
		if(!postoji){
				niz.at(0)=*prvi_pocetak;
				niz.at(1)=0;
				mat.push_back(niz);
		}
		drugi_pocetak=p;
		prvi_pocetak++;
	}
	drugi_pocetak=p;
	prvi_pocetak=q;
	while(drugi_pocetak!=drugi_kraj){
		postoji=false;
		while(prvi_pocetak!=prvi_kraj){
			if(abs(*prvi_pocetak-*drugi_pocetak)<EPSILON){
				postoji = true;
				break;
			}
			prvi_pocetak++;
		}
		if(!postoji){
				niz.at(0)=*drugi_pocetak;
				niz.at(1)=0;
				mat.push_back(niz);
		}
		prvi_pocetak=q;
		drugi_pocetak++;
	}
		sort(mat.begin(), mat.end(), [] (const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &a , const vector<typename std::remove_reference<decltype(*prvi_pocetak)>::type> &b ){if (BrojProstihFaktora(a[0])!=BrojProstihFaktora(b[0])) return (a[0]>b[0]); else return (BrojProstihFaktora(a[1])>BrojProstihFaktora(b[1])); });

	return mat;
}
int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	cin>>n1;
	cout<<"Unesite elemente prvog kontejnera: ";
	deque<int> dek1(n1);
	for(int i=0;i<n1;i++){
		cin>>dek1[i];
		for(int j=0;j<i;j++){
			if(dek1[i]==dek1[j])
			i--;
		}
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	cin>>n2;
	cout<<"Unesite elemente drugog kontejnera: ";
	deque<int> dek2(n2);
	for(int i=0;i<n2;i++){
		cin>>dek2[i];
		for(int j=0;j<i;j++){
			if(dek2[i]==dek2[j])
			i--;
		}
	}
	deque<int>::iterator it11(dek1.begin());
	deque<int>::iterator it12(dek1.end());
	deque<int>::iterator it21(dek2.begin());
	deque<int>::iterator it22(dek2.end());
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	vector<vector<int>> matpresjek (UvrnutiPresjek(it11,it12,it21,it22,f));
	for (int i=0;i<matpresjek.size();i++){
		for(int j=0;j<matpresjek[i].size();j++){
			cout<<std::setw(6)<<matpresjek[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	vector<vector<int>> matrazlika (UvrnutaRazlika(it11,it12,it21,it22,BrojProstihFaktora));
	for (int i=0;i<matrazlika.size();i++){
		for(int j=0;j<matrazlika[i].size();j++){
			cout<<std::setw(6)<<matrazlika[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}