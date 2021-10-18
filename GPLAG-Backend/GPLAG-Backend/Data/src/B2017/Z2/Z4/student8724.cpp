#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool fun (int x, int y){
	int sum=0;
	for(int i=1; i<=x;i++){
		if(x%i==0)sum++;
	}
	int sum1=0;
	for(int i=1; i<=y;i++){
		if(y%i==0)sum1++;
	}
	if(sum==sum1) return y<x;
	else return sum1<sum;
}

int f(int x, int y){
	return  -2*x+y;
}

template <typename Tip, typename Tip2>
void Zamjena (Tip &rezultat, Tip2 &temp2){
			auto var=rezultat;
			rezultat=temp2;
			temp2=var;
}

template <typename Tip, typename Tip1, typename Tip2>
void SortirajPodrucjeVrijednosti(Tip pocetak, Tip kraj, Tip1 pocetak1, Tip2 pocetak2, 
typename remove_reference<decltype(*pocetak2)>::type f (typename remove_reference<decltype(*kraj)>::type , typename remove_reference<decltype(*kraj)>::type ),
bool fun (typename remove_reference<decltype(*kraj)>::type , typename remove_reference<decltype(*kraj)>::type) ){
	sort(pocetak1, pocetak1+(kraj-pocetak), fun);
	sort(pocetak, kraj, fun);
	
	auto temp=pocetak;
	auto temp1=pocetak1;
	auto temp2=pocetak2;
	
	int br=0;
	while(temp!=kraj){
		auto x=*temp;
		auto y=*temp1;
		auto xyz=pocetak2 + (kraj-pocetak);
		auto rezultat=find(pocetak2, xyz , f(x, y) );
		if(rezultat!=pocetak2+ (kraj-pocetak) ){
			auto var=*rezultat;
			auto var1=*temp2;
			Zamjena(var, var1);
			*rezultat=var;
			*temp2=var1;
		}
		else throw logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		br++;
		temp++;
		temp1++;
		temp2++;
		if(temp==pocetak+ (kraj-pocetak))break;
	}
}


void Unos(int n, vector<int> &kontenjer){
		for(int i=0; i<n; i++){
		int k;
		cin>>k;
		bool temp=true;
		for(auto x: kontenjer){
			if(x==k){ temp=false; i--;}
		}
		if(temp) kontenjer.push_back(k);
	}
}
void Ispis(vector<int> kontenjer, vector<int> kontenjer1, vector<int> kontenjer2){
	cout<<endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<endl;
		for(int i=0; i<kontenjer.size(); i++){
			cout<<"f("<<kontenjer.at(i)<<", "<<kontenjer1.at(i)<<") = "<<kontenjer2.at(i)<<endl;
		}
}

int main (){
	cout<<"Unesite broj elemenata: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente prvog vektora: ";
	vector<int> kontenjer;
	Unos(n, kontenjer);
	cout<<"Unesite elemente drugog vektora: ";
	vector<int> kontenjer1;
	Unos(n, kontenjer1);
	cout<<"Unesite elemente treceg vektora: ";
	vector<int> kontenjer2;
	Unos(n, kontenjer2);
	try{
		SortirajPodrucjeVrijednosti ( kontenjer.begin() , kontenjer.end(), kontenjer1.begin(), kontenjer2.begin(), f, fun) ;
		Ispis(kontenjer, kontenjer1, kontenjer2);
	}
	catch(logic_error izuzetak){
		cout<<endl<<"Izuzetak: "<<izuzetak.what();
		}
	return 0;
	
}