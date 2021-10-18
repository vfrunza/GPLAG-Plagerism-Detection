#include<iostream>
#include<vector>
/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
using namespace std;

int daLiJeRuzan(int n){
	
	
	vector<int> v(3,0); 
	while(n>0){
		v[n%3]+=1;
		n/=3;
	}
	int brojac_parnih=0,brojac_neparnih=0,brojac_nula=0;
	for(int i=0;i<v.size();i++){
		if(v[i]%2!=0 && v[i]!=0) brojac_neparnih++;
		else if(v[i]==0)brojac_nula++;
		else brojac_parnih++;
	}
	if(brojac_neparnih==3) return 0;
	else if(brojac_parnih==3) return 1;
	else if(brojac_nula!=0 && brojac_neparnih!=brojac_parnih){
		if(brojac_neparnih==0)return 1;
		else return 0;
	}
	return -1;
}

vector<int> IzdvojiGadne(vector<int> v, bool kakavJe){
	vector<int> novi;
	int primljeni=int(kakavJe);
	for(int i=0;i<v.size();i++){
		int pom=v[i];
		if(v[i]<0) pom*=(-1);
		if(daLiJeRuzan(pom)==primljeni) {
			bool nasao=false;
			for(int j=0;j<novi.size();j++){
				if(novi[j]==v[i]) nasao=true;
			}
			if(nasao==false)
			novi.push_back(v[i]);
		}
	}
	return novi;
}

int main ()
{
	
	
	vector<int> v;
	int k=0;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		
		cin>>k;
		if(k==0) break;
		v.push_back(k);
	}
	vector<int> a=IzdvojiGadne(v,true);
	vector<int> b=IzdvojiGadne(v,false);
	cout<<"Opaki: ";
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<"\nOdvratni: ";
	for(int i=0;i<b.size();i++)
		cout<<b[i]<<" ";
		
//Opaki: 608 -608 60 
//Odvratni: 123 333 -15 15 715
	
	return 0;
}