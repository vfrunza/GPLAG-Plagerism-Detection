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
using std::setw;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::sort;

int ZbirCifara(long long int x){
	int broj = 0;
	while(x>0){
		broj+=x%10;
		x/=10;
	}
	return broj;
}

int SumaDjelilaca(long long int x){
	int broj = 0;
	for(int i=1; i<x/2+1; i++){
		if(x%i==0) broj+=i;
	}
	broj+=x;
	return broj;
}

int BrojProstihFaktora(long long int x){
	int broj=0;
	for(int i=2; i<=x; i++){
		if(x%i==0){
			broj++;
			x/=i;
			i--;
		}
	}
	return broj;
}

int BrojSavrsenihDjelilaca(long long int x){
	int broj=0;
	for(int i=2; i<=x; i++){
		if(x%i==0){
			int suma=0;
			for(int j=1; j<i; j++){
				if(i%j==0) suma+=j;
			}
			if(suma==i) broj++;
		}
	}
	return broj;
}

// UVRNUTI PRESJEK

template <typename tip1, typename tip2>
vector<vector<int>> UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, int (*fun)(long long int)){
	if(pocetak1==kraj1 || pocetak2==kraj2) return {};
	vector <vector <int>> Matrica(0, vector<int>(3));
	int red_matrice=0;
	auto pomocni2 (pocetak2);
	while(pocetak1!=kraj1){
		pocetak2=pomocni2;
		while(pocetak2!=kraj2){
			if(fun(*pocetak1)==fun(*pocetak2)){
				Matrica.push_back(vector<int>(0));
				Matrica[red_matrice].push_back(*pocetak1);
				Matrica[red_matrice].push_back(*pocetak2);
				Matrica[red_matrice].push_back(fun(*pocetak1));
				red_matrice++;
			}
			pocetak2++;
		}
		pocetak1++;
	}
	if (!Matrica.size()) return {};
	if (Matrica.size()==1) return Matrica;
	sort(Matrica.begin(), Matrica.end(), [](vector<int> x, vector<int> y)-> bool{ if(x[2]!=y[2]){return x[2]<y[2];} else if(x[0]!=y[0]){ return x[0]<y[0];} else{ return x[1]<y[1];}});
	return Matrica;
}

template <typename tip1, typename tip2>
vector<vector<int>> UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2){
	if(pocetak1==kraj1 || pocetak2==kraj2) return {};
	vector <vector <int>> Matrica(0, vector<int>(3));
	int red_matrice=0;
	auto pomocni2 (pocetak2);
	while(pocetak1!=kraj1){
		pocetak2=pomocni2;
		while(pocetak2!=kraj2){
			if(*pocetak1==*pocetak2){
				Matrica.push_back(vector<int>(0));
				Matrica[red_matrice].push_back(*pocetak1);
				Matrica[red_matrice].push_back(0);
				Matrica[red_matrice].push_back(0);
				red_matrice++;
			}
			pocetak2++;
		}
		pocetak1++;
	}
	if (!Matrica.size()) return {};
	if (Matrica.size()==1) return Matrica;
	
	//sortiranje
	sort(Matrica.begin(), Matrica.end(), [](vector<int> x, vector<int> y)-> bool{ return x[0]<y[0];});
	return Matrica;
}

// UVRNUTA RAZLIKA

template <typename tip1, typename tip2>
vector<vector<int>> UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, int(*fun)(long long int)){
	if(pocetak1==kraj1 || pocetak2==kraj2) return {};
	vector<vector<int>> Matrica(0, vector<int>(2));
	int red_matrice=0;
	auto pomocni1 (pocetak1);
	auto pomocni2 (pocetak2);
	
	// poredjenje prvog sa drugim 
	
	while(pocetak1!=kraj1){
		pocetak2=pomocni2;
		bool razlicitost=1;
		while(pocetak2 != kraj2){
			if(fun(*pocetak1)==fun(*pocetak2)){
				razlicitost=0;
				break;
			}
			pocetak2++;
		}
		if(razlicitost){
			Matrica.push_back(vector<int>(0));
			Matrica[red_matrice].push_back(*pocetak1);
			Matrica[red_matrice].push_back(fun(*pocetak1));
			red_matrice++;
		}
		pocetak1++;
	}
	
	// poredjenje drugog sa prvim
	pocetak1=pomocni1;
	pocetak2=pomocni2;
	while(pocetak2!=kraj2){
		pocetak1=pomocni1;
		bool razlicitost=1;
		while(pocetak1 != kraj1){
			if(fun(*pocetak1)==fun(*pocetak2)){
				razlicitost=0;
				break;
			}
			pocetak1++;
		}
		if(razlicitost){
			Matrica.push_back(vector<int>(0));
			Matrica[red_matrice].push_back(*pocetak2);
			Matrica[red_matrice].push_back(fun(*pocetak2));
			red_matrice++;
		}
		pocetak2++;
	}
	if (!Matrica.size()) return {};
	if (Matrica.size()==1) return Matrica;
	
	//sortiranje
	sort(Matrica.begin(), Matrica.end(), [](vector<int> x, vector<int>y)-> bool{if(x[0]!=y[0]) return x[0]>y[0]; else return x[1]>y[1];});
	return Matrica;
}


int main ()
{
	deque<int> v1;
	deque<int> v2;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int br1;
	cin>>br1;
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<br1; i++){
		int element;
		cin>>element;
		bool tacnost=0;
		for(int j=0; j<i; j++){
			if(v1[j]==element) tacnost=1;
		}
		if(tacnost){
			i--;
			continue;
		}
		v1.push_back(element);
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int br2;
	cin>>br2;
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<br2; i++){
		int element;
		cin>>element;
		bool tacnost=0;
		for(int j=0; j<i; j++){
			if(v2[j]==element) tacnost=1;
		}
		if(tacnost){
			i--;
			continue;
		}
		v2.push_back(element);
	}
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	vector<vector<int>> Matrica1;
	int (*pok_na_fun1)(long long int);
	pok_na_fun1=&ZbirCifara;
	Matrica1 = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), pok_na_fun1);
	for(int i=0; i<Matrica1.size(); i++){
		for(int j=0; j<Matrica1[i].size(); j++){
			cout<<setw(6)<<Matrica1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	
	int (*pok_na_fun2)(long long int);
	pok_na_fun2=&BrojProstihFaktora;
	vector<vector<int>> Matrica2;
	Matrica2 = UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(), v2.end(), pok_na_fun2);
	for(int i=0; i<Matrica2.size(); i++){
		for(int j=0; j<Matrica2[i].size(); j++){
			cout<<setw(6)<<Matrica2[i][j]<<" ";
		}
		cout<<endl; 
	}
	cout<<"Dovidjenja!";
	return 0;
}