/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<new>
#include<stdexcept>


using namespace std;


int PotencijalniKrivci(char &pok, vector<string> imenakrivaca ){
	try{
		int brojac;
		
		
		
	return	brojac;
	}catch(...){
	
		throw;
	}
	
}



int main (){
	try{
	cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<endl;
	int n;
	cin>>n;
	vector<string> imenakrivaca(n);
	cout<<"Unesite potencijalne krivce: ";
	for(int i=0;i<n;i++){
		getline(cin,imenakrivaca[i]);
	}
	
	
  
	char **pok;
	char **pokazivac;
	
    
	
	
	
	}catch(bad_alloc){cout<<"Alokacija nije uspjela! ";}
	return 0;
}