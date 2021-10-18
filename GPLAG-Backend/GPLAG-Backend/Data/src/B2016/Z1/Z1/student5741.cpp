/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> IzdvojiGadne(vector<int> v,bool t){
	int broj(0);
	vector<int> v1;
	vector<int> v2;
	if(t){
		for(int x:v){
			unsigned long long int f(fabs(x));
			if(f==0){
				continue;
			}
			while(f!=0){
				broj=f%3;
				v1.push_back(broj);
				f=f/3;
			}
			vector<int> br(3);
			for(int i=0;i<v1.size();i++){
				for(int j=0;j<3;j++){
					if(v1.at(i)==j){
						br.at(j)++;
					}
				}
			}
			bool paran=true;
			for(int i=0;i<3;i++){
				if(br.at(i)%2!=0){
					paran=false;
					break;
				}
			}
			if(paran==true){
				int broj1(0);
				for(int i=0;i<v1.size();i++){
					broj1=broj1+v1.at(i)*pow(3,i);
				}
				bool negativan=false;
				if(x<0){
					negativan=true;
				}
				if(negativan){
					broj1=-broj1;
					v2.push_back(broj1);
				}
				else{
					v2.push_back(broj1);
				}
			}
			v1.resize(0);
		}
	}
	else{
		for(int x:v){
			unsigned long long int f(fabs(x));
			while(f!=0){
				broj=f%3;
				v1.push_back(broj);
				f=f/3;
			}
			vector<int> br(3);
			for(int i=0;i<v1.size();i++){
				for(int j=0;j<3;j++){
					if(v1.at(i)==j){
						br.at(j)++;
					}
				}
			}
			bool neparan=true;
			for(int i=0;i<3;i++){
				if(br.at(i)%2!=1 && br.at(i)!=0){
					neparan=false;
					break;
				}
			}
			if(neparan==true){
				int broj1(0);
				for(int i=0;i<v1.size();i++){
					broj1=broj1+v1.at(i)*pow(3,i);
				}
				bool negativan=false;
				if(x<0){
					negativan=true;
				}
				if(negativan){
					broj1=-broj1;
					v2.push_back(broj1);
				}
				else{
					v2.push_back(broj1);
				}
			}
			v1.resize(0);
		}
	}
	for(int i=0;i<v2.size();i++){
		for(int j=i+1;j<v2.size();j++){
			if(v2[i]==v2[j]){
				v2.erase(v2.begin()+j);
				j--;
			}
		}
	}
	return v2;
}

int main ()
{
	vector<int> v;
	int broj;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		cin>>broj;
		if(broj==0){
			break;
		}
		v.push_back(broj);
	}
	while(broj!=0);
	vector<int> v1(v);
	v=IzdvojiGadne(v,true);
	cout<<"Opaki: ";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	v=IzdvojiGadne(v1,false);
	cout<<endl<<"Odvratni: ";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}