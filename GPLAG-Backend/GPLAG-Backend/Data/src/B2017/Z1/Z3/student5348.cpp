/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/




#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

typedef deque<vector<int>> dv;
enum Smjer {Rastuci=1,Opadajuci=2};

bool Stepen(int a){
	
	if(a<=0)return false;
	return(log2(a)==(int)log2(a));
	
}



dv MaksimalniPodnizoviStepenaDvojke(vector<int> v,Smjer s){
	
	dv d;
	vector<int> v1;
	
	for(int i=1;i<v.size();i++)
	{
		int n=v.at(i-1);
		int m=v.at(i);
	if(Stepen(m) && Stepen(n)){
			if(s==Rastuci){
				if(m>n){
					if(v1.size()==0)v1.push_back(n);//Ako je prazan ubaci prosli
					v1.push_back(m);//Ubaci veci
				}else if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
				
			}
			else if(s=Opadajuci){
				if(m<n){
					if(v1.size()==0)v1.push_back(n);//Ako je prazan ubaci prosli
					v1.push_back(m);//Ubaci veci
				}else if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
			}
	}else if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
	}
	if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
		
	
			
				
	
	
	return d;
	
	
	
	
}

dv MaksimalniPodnizoviStepenaDvojke(vector<int> v,bool s){
	
	dv d;
	vector<int> v1;
	
	for(int i=1;i<v.size();i++)
	{
		int n=v.at(i-1);
		int m=v.at(i);
	if(Stepen(m) && Stepen(n)){
			if(s==true){
				if(m>=n){
					if(v1.size()==0)v1.push_back(n);//Ako je prazan ubaci prosli
					v1.push_back(m);//Ubaci veci
				}else if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
				
			}
			else if(s=false){
				if(m<=n){
					if(v1.size()==0)v1.push_back(n);//Ako je prazan ubaci prosli
					v1.push_back(m);//Ubaci veci
				}else if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
			}
	}else if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
	}
	if(v1.size()>0){
		d.push_back(v1);
		v1.resize(0);
	}
		
	
			
				
	
	
	return d;
	
	
	
	
}

int main ()
{
	int n;
	vector<int> v1;
	
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }
	dv novi;
	
	int x;
	
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>x;
	
	if(x==1){
	 novi=MaksimalniPodnizoviStepenaDvojke(v1,Rastuci);
	 cout<<"Maksimalni rastuci podnizovi: "<<endl;
	}
	else if(x==2){
		novi=MaksimalniPodnizoviStepenaDvojke(v1,Opadajuci);
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	}
	
	for(int i=0;i<novi.size();i++){
		for(int j=0;j<novi.at(i).size();j++){
			cout<<novi.at(i).at(j)<<" ";
		}cout<<endl;
	}
	
	return 0;
}