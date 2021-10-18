
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
enum Smjer{Opadajuci, Rastuci};

bool stepen2(int broj){
	if (broj<0) return false;
	while(broj!=1){
		if(broj%2==1) return false;
		broj/=2;
	}
	return true;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> brojevi, enum Smjer s)
{
	deque<vector<int>> maksimalniPodnizovi;
	
	int brojElemenataPodniza=1;
	for (int i = 0; i < brojevi.size()-1; i++) {
		int trenutni = brojevi.at(i);
		int sljedeci = brojevi.at(i+1);
		
		if(
			stepen2(trenutni) && 
			stepen2(sljedeci)&&
			(	( s==Rastuci && trenutni<=sljedeci)
			||	(s==Opadajuci&&trenutni>=sljedeci)
			) 
		){
			brojElemenataPodniza++;
		}
		else{
			if(brojElemenataPodniza>1){
				vector<int>maksimalanPodniz;
				for(int j=i-brojElemenataPodniza+1;j<=i;j++){
					maksimalanPodniz.push_back(brojevi.at(j));
				}
				maksimalniPodnizovi.push_back(maksimalanPodniz);
				brojElemenataPodniza=1;
			}
			
			
		}
		
	}
	
	if(brojElemenataPodniza>1){
			vector<int>maksimalanPodniz;
			int i=brojevi.size()-1;
			for(int j=i-brojElemenataPodniza+1;j<=i;j++){
				maksimalanPodniz.push_back(brojevi.at(j));
			}
			maksimalniPodnizovi.push_back(maksimalanPodniz);
			brojElemenataPodniza=1;
		}
	return maksimalniPodnizovi;
}
int main ()
{
	
	cout<<"Unesite broj elemenata vektora: ";
	int broj_elemanata;
	cin>>broj_elemanata;
	cout<<"Unesite elemente vektora: ";
	vector<int>brojevi(broj_elemanata);
	for (int i = 0; i < broj_elemanata; i++) {
		cin>>brojevi.at(i);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int smjer;
	enum Smjer s;
	cin>>smjer;
	if(smjer==1)s = Rastuci;
	else s= Opadajuci;
	
	if(s==Rastuci)
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	else
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;	
	deque<vector<int>>  rezultat = MaksimalniPodnizoviStepenaDvojke(brojevi,s);
	
	for(vector<int>v :rezultat){
		for(int e:v){
			cout<<e<<" ";
		}
		cout<<endl;
	}
	return 0;
}