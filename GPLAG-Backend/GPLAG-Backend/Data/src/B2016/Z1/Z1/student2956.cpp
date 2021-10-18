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

vector<int>IzdvojiGadne(vector<int> v,bool opak)
{
	vector<int>povratni;
	int brojac[3]={0,0,0};
	
	for(int i=0;i<v.size();i++){
		brojac[0]=0;brojac[1]=0;brojac[2]=0;
		int n(v[i]);
		while(n!=0) {
			int cifra=n%3;
			if(cifra<0) cifra=cifra*(-1);
			brojac[cifra]++;
			n/=3;
		}
		
	bool jesteopak=true;
	bool jesteodvratan=true;
	
	for(int j=0;j<3;j++){
		if (brojac[j]>0 && brojac[j]%2==1) jesteopak=false;
		else if(brojac[j]>0 && brojac[j]%2==0) jesteodvratan=false;}
		for(int j=0;j<povratni.size();j++) if(v[i]==povratni[j]) {
			jesteopak=false;
			jesteodvratan=false;
		}
		if(opak && jesteopak) povratni.push_back(v[i]);
		else if(!opak && jesteodvratan&& v[i]!=0) povratni.push_back(v[i]);
	}
	return povratni;
}

int main()
{
	
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	vector<int>x;
	cin>>n;
	while(n!=0){
		x.push_back(n);
		cin>>n;
	}
	cout<<"Opaki: ";
	for(auto a:IzdvojiGadne(x,true)) cout<<a<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	for(auto a:IzdvojiGadne(x,false)) cout<<a<<" ";
	return 0;
}
	
