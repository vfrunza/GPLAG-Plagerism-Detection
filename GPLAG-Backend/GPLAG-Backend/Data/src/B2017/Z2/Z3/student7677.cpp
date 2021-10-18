#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

typedef std::vector<int> Vektor;
typedef std::vector<vector<int>> Matrica;

bool TestPerioda (Vektor v, int p){
	
	if(p<=0)return false;
	
	if(int(v.size())-p<=0)return false;
	
	for(int i=0;i<v.size()-p;i++){
		if(v.at(i+p)!=v.at(i))return false;
	}
	
	return true;
}

int OdrediOsnovniPeriod (Vektor v){
	
	for(int i=0;i<int(v.size());i++){
		if(TestPerioda(v,i)) return i;
	}
	
	return 0;
}

int **AlocirajKontinualno (Vektor &v, int &koliko_puta){
	
	
	if(v.size()==0)throw domain_error ("Izuzetak: Prazan vektor!");
	for(int i=0;i<v.size();i++)
	if(v.at(i)<=0)throw domain_error("Izuzetak: Neispravan vektor!");
	int T;
	T=OdrediOsnovniPeriod(v);
	
	int br_peroda,vel_v;
	vel_v=v.size();
	
	if(T==0){
		for(int i=0;i<vel_v;i++)v.push_back(v.at(i));
	}
	else{
		br_peroda=(vel_v-1)/T;
		int x=vel_v%T;
		int y=T-x;
			if((vel_v)%T!=0)
		for(int i=x;i<T;i++)v.push_back(v.at(i));
	}
	vel_v=v.size();
	//for(int i=0;i<v.size();i++)cout<<v.at(i)<<" ";


	Vektor v_n;
	
 	int **m(nullptr);
 	
 	try{
 		m=new int *[vel_v]{};
 		try{
 			for(int i=0;i<vel_v;i++){
 				m[i]=new int [v.at(i)]{};
 			}
 		}
 			catch(...)	{
 		if(m!=nullptr){
 			for(int i=0;i<vel_v;i++) delete [] m[i];
 		}
 		delete [] m;
 			
 	}
 		
 	}
 	catch(...)	{
 				for(int i=0;i<vel_v;i++) delete [] m[i];
 		delete [] m;
 			
 	}
	
	
	int vel_v_n,vel_m;
	vel_v_n=v.size();
	
	for(int i=0;i<vel_v;i++){
		for(int j=v.at(i);j>=1;j--){
			m[i][v.at(i)-j]=j;
		}
	
	}
	
 return m;

}
////////////////////////////////////////////////////////////ž




int **AlocirajFragmentirano (Vektor &v, int &koliko_puta){
	
	if(v.size()==0)throw domain_error ("Izuzetak: Prazan vektor!");
	for(int i=0;i<v.size();i++)
	if(v.at(i)<=0)throw domain_error("Izuzetak: Neispravan vektor!");
	int T;
	T=OdrediOsnovniPeriod(v);
	
	int br_peroda,vel_v;
	vel_v=v.size();
	

	if(T==0){
		for(int i=0;i<vel_v;i++)v.push_back(v.at(i));
		T=OdrediOsnovniPeriod(v);
	}
	else{
		br_peroda=(vel_v-1)/T;
		int x=vel_v%T;
		int y=T-x;
		if((vel_v)%T!=0)
		
		for(int i=x;i<T;i++)v.push_back(v.at(i));
	}
	vel_v=v.size();
	//for(int i=0;i<v.size();i++)cout<<v.at(i)<<" ";


	Vektor v_n;
	
 	int **m(nullptr);
 	
 	try{
 		m=new int *[vel_v]{};
 		try{
 			for(int i=0;i<vel_v;i++){
 				m[i]=new int [v.at(i)]{};
 			}
 		}
 			catch(...)	{
 		if(m!=nullptr){
 			for(int i=0;i<vel_v;i++) delete [] m[i];
 		}
 		delete [] m;
 			
 	}
 	}
 	catch(...)	{
 		for(int i=0;i<vel_v;i++) delete [] m[i];
 		delete [] m;
 			
 	}
	
	
	int vel_v_n,vel_m;
	vel_v_n=v.size();
	
	
	for(int i=0;i<vel_v;i++){
		for(int j=0;j<v.at(i);j++){
			m[i][j]=T-v.at(i)+j+1;
		}
	
	}
	
	
 return m;

}

int main ()
{
	int br=0;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>br;
	Vektor v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<br;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alok;
	cin>>alok;
	
	int **a(nullptr);
	int broj=0;
	try{
		if(alok==1) a=AlocirajFragmentirano(v,broj);
		else a=AlocirajKontinualno(v,broj);
	}catch(domain_error ex){
		cout<<ex.what();

		return 0;
	}
	cout<<"Dinamicki alocirana matrica: "<<endl;
	
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.at(i);j++){
			cout<<left<<setw(3)<<a[i][j];
		}cout<<endl;
	}
	
		for(int i=0;i<v.size();i++) delete [] a[i];
 		delete [] a;
	
	
	
	return 0;
}