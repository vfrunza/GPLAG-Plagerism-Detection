/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;



bool JelProst(int x)
{
	x=fabs(x);
	if(x==2) return true;
	if(x==1) return false;
	for(int i=2;i<x;i++)
		if(x%i==0) return false;
	return true;
}

bool BrojProstihFaktora(int x,int y)
{    
	int br=0;int temp=x;
	for(int i=1;i<temp;i++)
		if(x%i==0 && JelProst(i)){ br++; temp/=i;i--;}
		
	int br1=0;
	temp=y;
	for(int i=1;i<temp;i++)
		if(y%i==0 && JelProst(i)) { br1++; temp/=i;i--;}
	
	
	if(br==br1 ) return x>y;
	return br>br1;
}

int funkcija(int x,int y)
{
	return -2*x+y;
}

template<typename t1,typename t2,typename t3,typename t4,typename t5>
void SortirajPodrucjeVrijednosti(t1 poc1,t1 kraj1,t2 poc2,t3 poc3,t4 f(t4,t4),bool f1(t5,t5))
{
	sort(poc1,poc1+(kraj1-poc1),f1);
    sort(poc2,poc2+(kraj1-poc1),f1);
   // for(int i=0;i<(kraj1-poc1);i++) cout<<poc2[i]<<" ";
    for(auto i=poc1,j=poc2,p=poc3;i!=kraj1;i++,j++,p++)
    {
    	bool postoji=0;auto k=poc3;
    	for(;k!=poc3+(kraj1-poc1);k++)
    			if(f(*i,*j)==*k)
    			{
    				postoji=1;
    				break;
    			}
    	
    	if(postoji==1) 
    	{
    		auto q=*k;
    			 *k=*p;
    			 *p=q;
    	}
    	else throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
    			
    }
}

int main ()
{  
	
	cout<<"Unesite broj elemenata: ";
	int n; cin>>n;
	vector<int> v1(n);
	vector<int> v2(n);
	vector<int> v3(n);
     
    cout<<"Unesite elemente prvog vektora: ";
	for(int i=0;i<v1.size();i++) {
			bool ima=1;
			int pom; cin>>pom;if(pom==0) continue;
			for(int j=0; j<v1.size(); j++) if(v1.at(j)==pom) ima=0;
			if(!ima) { i--; continue;}
			v1.at(i)=pom;
	}
	cout<<"Unesite elemente drugog vektora: ";
	for(int i=0;i<v2.size();i++) {
			bool ima=1;
			int pom; cin>>pom;if(pom==0) continue;
			for(int j=0; j<v2.size(); j++) if(v2.at(j)==pom) ima=0;
			if(!ima) { i--;continue;}
			else v2.at(i)=pom;
	}


//	for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";
	cout<<"Unesite elemente treceg vektora: "<<endl;
	for(int i=0;i<v3.size();i++) {
			bool ima=1;
			int pom; cin>>pom;if(pom==0) continue;
			for(int j=0; j<v3.size(); j++) if(v3.at(j)==pom) ima=0;
			if(!ima) { i--; continue;}
			v3.at(i)=pom;
	}
	
			try{
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),funkcija,BrojProstihFaktora);
	cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<endl;
	for(int i=0;i<v3.size();i++)
			cout<<"f("<<v1[i]<<", "<<v2[i]<<")"<<" = "<<v3[i]<<endl;
			} catch(logic_error izuz) { cout<<"Izuzetak: "<<izuz.what();}
	return 0;
}