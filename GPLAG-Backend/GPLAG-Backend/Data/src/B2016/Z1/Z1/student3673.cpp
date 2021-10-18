/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

vector<int> IzdvojiGadne(vector<int>v,bool b){
	if(v.size()==0){vector<int>prazan(0);return prazan;}
	vector<int>pom;
	for(int i=0;i<int(v.size());i++){
	pom.push_back(v[i]);
	}
	for(int i=0;i<int(pom.size());i++){
		for(int j=i+1;j<int(pom.size());j++){
			if(pom[i]==pom[j])pom.erase(pom.begin()+j);
		}
		
	}
	for(int i=0;i<int(pom.size());i++){
		for(int j=i+1;j<int(pom.size());j++){
			if(pom[i]==pom[j])pom.erase(pom.begin()+j);
		}
	}
vector<int>rez;
	for(int i=0;i<int(pom.size());i++){
		int n(pom[i]),cif,br_1(0),br_2(0),br_0(0);
		if(n==0)br_0++;
		while(n!=0){
			cif=abs(n%3);
			if(cif==1)br_1++;
			else if(cif==2)br_2++;
			else if(cif==0)br_0++;
			n/=3;
		}
		//if(b && br_0%2==0 && br_1%2==0 && br_2%2==0)rez.push_back(pom[i]);
		if((!b && br_0%2!=0 && br_1%2!=0 && br_2%2!=0) || (!b && br_0==0 && br_1%2!=0 && br_2%2!=0) || (!b && br_0%2!=0 && br_1==0 && br_2%2!=0) || (!b && br_0%2!=0 && br_1%2!=0 && br_2==0) || (!b && br_0==0 && br_1%2!=0 && br_2==0) || (!b && br_0%2==0 && br_1==0 && br_2%2!=0)|| (!b && br_0%2!=0 && br_1==0 && br_2==0))rez.push_back(pom[i]);
		else if(b && br_0%2==0 && br_1%2==0 && br_2%2==0)rez.push_back(pom[i]);
		//else if(!b && pom[i]==0)rez.push_back(pom[i]);
		
	}


	return rez;

}

int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int>v;
	int br;
	do {

		cin>>br;
		if(br==0)break;
		if(!cin)return 0;
		v.push_back(br);
	} while(br!=0);
	
	vector<int>modifikovan1,modifikovan2;
	modifikovan1=IzdvojiGadne(v,true);
	modifikovan2=IzdvojiGadne(v,false);
	cout<<"Opaki: ";
	for(int x:modifikovan1)cout<<x<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	for(int y:modifikovan2)cout<<y<<" ";
	
	return 0;
}