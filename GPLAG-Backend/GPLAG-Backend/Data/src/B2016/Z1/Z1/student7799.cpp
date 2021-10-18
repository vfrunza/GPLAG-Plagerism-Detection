/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using namespace std; 

vector <int> IzdvojiGadne(vector<int> v, bool a){
	vector<int> b; //vector koji se vraca
	if(a==true){
		for(int i=0;i<v.size();i++){
			int provjera=0; //ako se naiđe na isti element, zanemari se 
			for(int x: b){ //ako je vector prazan nece uci u petlju
				if(v[i]==x) provjera=1;
			}
			if(provjera==0){
				vector<int> ternarni;
				long long int broj=abs(v[i]);
				while(broj!=0){
					int pomocni=broj/3;
					pomocni=broj-(3*pomocni); //ostatak pri dijeljenju
					ternarni.push_back(pomocni);
					broj/=3;
				}
					int niz[3]={0,0,0}; //indexi broja ce biti 0,1 i 2 tj brojevi koji se mogu pojaviti u ternarnom brojnom sistemu
					for(int j: ternarni){
						niz[j]++; //povecava brojace
					}
					if(niz[0]%2==0 and niz[1]%2==0 and niz[2]%2==0){
						b.push_back(v[i]);
					}
				}	
			}
			}
	else{
		for(int i=0;i<v.size();i++){
			int provjera=0; //ako se naiđe na isti element, zanemari se 
			for(int x: b){ //ako je vector prazan nece uci u petlju
				if(v[i]==x) provjera=1;
			}
			if(provjera==0){
				vector<int> ternarni;
				long long int broj=abs(v[i]);
				while(broj!=0){
					int pomocni=broj/3;
					pomocni=broj-(3*pomocni); //ostatak pri dijeljenju
					ternarni.push_back(pomocni);
				broj/=3;
					
				}
					int niz[3]={0,0,0}; //indexi broja ce biti 0,1 i 2 tj brojevi koji se mogu pojaviti u ternarnom brojnom sistemu
					for(int j:ternarni){
						niz[j]++; //povecava brojace
					}
					if(niz[0]==0) niz[0]++;
					if(niz[1]==0) niz[1]++;
					if(niz[2]==0) niz[2]++;
					if(niz[0]%2!=0 and niz[1]%2!=0 and niz[2]%2!=0){
						b.push_back(v[i]);
					}
				}	
			}
			}
	return b;
}
int main (){
	vector<int> a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		int b;
		cin>>b;
		if(b==0) break;
		a.push_back(b);
	}
	vector<int> c=IzdvojiGadne(a,true);
	vector<int> d=IzdvojiGadne(a,false);
	cout<<"Opaki: ";
	for(int x:c){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
		for(int x:d){
		cout<<x<<" ";
	}
	return 0;
}