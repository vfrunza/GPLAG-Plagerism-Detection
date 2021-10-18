/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int BrojCifara(int broj) {
	int brojac(0);
	int broj1=broj;
	
	while(broj!=0) {
		int cifra=broj%10;
		brojac++;
		broj/=10;
	}
	
	if(broj1<0) brojac++;
	return brojac;
}

int DaLiJeGadan(int broj)
{
	int br=broj; // cuva nam vrijednost broja
	int brojac1(0), brojac2(0), brojac3(0);
	while(br!=0) {
		if(br%3==0) brojac1++;
		if(br%3==1) brojac2++;
		if(br%3==2) brojac3++;
		br/=3;
	}

	if((brojac3%2==0 || brojac3==0) && (brojac2%2==0 || brojac2==0) && (brojac1%2==0 || brojac1==0)) return 1; //opak
	else if((brojac3%2!=0 || brojac3==0) && (brojac2%2!=0 || brojac2==0) && (brojac1%2!=0 || brojac1==0)) return 0; //gadan
	else return 2; // ni opak ni gadan
}

vector<int> IzdvojiGadne(vector<int> v,bool logicka)
{
	vector<int> v1;

	int velicina_vektora=v.size();
	for(int i=0; i<velicina_vektora; i++) {
		for(int j=i+1; j<velicina_vektora;) {
			if((v[i]==v[j]) && (BrojCifara(v[i])==BrojCifara(v[j]))) {
				for(int k=j; k<velicina_vektora-1; k++) {
					v[k]=v[k+1];
				}
				--velicina_vektora;
			} else j++;
		}
	} 
	
	v.resize(velicina_vektora); 
	

	for(int i=0; i<v.size(); i++) {
		if(DaLiJeGadan(v[i])==logicka) v1.push_back(v[i]);
	}
	
	return v1;
}

int main ()
{
	vector<int> v;
	int n;

	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		cin>>n;
		if(n==0) break;
		v.push_back(n);
	} while (n!=0);

	vector<int> v1=IzdvojiGadne(v,true);
	vector<int> v2=IzdvojiGadne(v,false);

	cout<<"Opaki: ";
	for(int i=0; i<v1.size(); i++) {
		cout<<v1[i]<<" ";
	}

	cout<<endl<<"Odvratni: ";
	for(int i=0; i<v2.size(); i++) {
		cout<<v2[i]<<" ";
	}

	return 0;
}
