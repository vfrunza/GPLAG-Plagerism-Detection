/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <new>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

template <typename BrojcaniTip>
bool TestPerioda(const std::vector<BrojcaniTip> &v, const int &p){
    
    if(p>=v.size() || p==0) return false; //  po definiciji ne moze biti period nula ili veci od dimenzija vektora
    
    bool periodican_p {true};
    
    for(int i=0;i+p<v.size();i++){
        if(v.at(i)!=v.at(i+p)) { 
            periodican_p=false; 
            break;
        }
    }
    
    return periodican_p;
}


template<typename BrojcaniTip>
int OdrediOsnovniPeriod(const std::vector<BrojcaniTip> &v){
    

    bool postoji_period{false};
    int p{0};
    
    for(p=1;p<v.size();p++){
    if(TestPerioda(v,p)){
        postoji_period=true; // p je najmanji period 
        break;   
    }
    }
    
    
    if(postoji_period) return p;
    else return 0;
}

template <typename BrojcaniTip>
int** AlocirajFragmentirano(const std::vector<BrojcaniTip> &v, int &koliko_puta){
	
	if(v.size()==0) throw "Prazan vektor!";
	for(BrojcaniTip x : v) if(x<=0) throw std::domain_error("Neispravan vektor!");
	
	int** matrica(nullptr);
	
	BrojcaniTip max_clan{*(std::max_element(v.begin(),v.end()))};
	
	int max_red{int(max_clan)};
	
	
    int Osnovni_period(OdrediOsnovniPeriod(v));
    
    
   int n(0);
    
    
    if(Osnovni_period!=0 && v.size()%Osnovni_period!=0){
    	
    	n=v.size()%Osnovni_period;
        koliko_puta=(v.size()+Osnovni_period-n)/Osnovni_period;
    }
	
	else if (Osnovni_period!=0) koliko_puta=v.size()/Osnovni_period;
	
	
	else if(Osnovni_period==0)
	    koliko_puta=2;
	
	
	try{
	    
	    if(Osnovni_period!=0)
	    matrica=new int* [Osnovni_period*koliko_puta]{};
	    
	    else matrica=new int* [v.size()*koliko_puta]{};
	    
	    try{
	        
	    for(int i=0;i<v.size();i++) matrica[i]=new int [v.at(i)];
	    
	    if(Osnovni_period!=0 && v.size()%Osnovni_period!=0)
	    for(int i=0;i<Osnovni_period-n;i++) matrica[i+v.size()]= new int [v.at(i+n)];
	    
	    else if(Osnovni_period==0)
	    for(int i=0;i<v.size();i++) matrica[i+v.size()] = new int[v.at(i)];
	    
	    for(int i=0;i<v.size();i++){
	        max_red=int(max_clan);
	        for(int j=0;j<v.at(i);j++)
	            matrica[i][v.at(i)-j-1]=max_red--;
	        
	    }
	    
	    if(Osnovni_period!=0 && v.size()%Osnovni_period!=0){
	    for(int i=0;i<Osnovni_period-n;i++){
	    	max_red=int(max_clan);
	    	for(int j=0;j<v.at(i+n);j++)
	    	matrica[i+v.size()][v.at(i+n)-j-1]=max_red--;
	    }
	    }
	    
	    else if(Osnovni_period==0){
	    	
	    	for(int i=0;i<v.size();i++){
	    	max_red=int(max_clan);
	    	for(int j=0;j<v.at(i);j++)
	    	matrica[i+v.size()][v.at(i)-j-1]=max_red--;
	    }
	    }
	}
	
	catch(std::bad_alloc){
	for(int i=0;i<koliko_puta*v.size();i++) delete[] matrica[i];
	
	throw;
	}
	
	}
	catch(std::bad_alloc){
	    delete[] matrica;
	    throw;
	}
	
	
	return matrica;
}


template <typename BrojcaniTip>
int** AlocirajKontinualno(const std::vector<BrojcaniTip> &v, int &koliko_puta){
	
	int** matrica(nullptr);
	
	if(v.size()==0) throw "Prazan vektor!";
	for(BrojcaniTip x : v) if(x<=0) throw std::domain_error("Neispravan vektor!");

    int Osnovni_period(OdrediOsnovniPeriod(v));
    
    
    int n(0);
    
    
    if(Osnovni_period!=0 && v.size()%Osnovni_period!=0){
    	
        koliko_puta=(v.size()+Osnovni_period-n)/Osnovni_period;
         n=v.size()%Osnovni_period;
    }
  
	
	else if (Osnovni_period!=0) koliko_puta=v.size()/Osnovni_period;
	
	
	else if(Osnovni_period==0)
	    koliko_puta=2;
	
	
	BrojcaniTip suma_clanova(0);
	for(BrojcaniTip x : v) suma_clanova+=x;
	
	if(Osnovni_period!=0 && v.size()%Osnovni_period!=0)
	for(int i=0;i<Osnovni_period-n;i++) suma_clanova+=v.at(i+n);
	
	else if (Osnovni_period==0) suma_clanova*=2;
	
	int suma{int(suma_clanova)};
	
	
	try{
	    
	    if(Osnovni_period!=0)
	    matrica=new int* [Osnovni_period*koliko_puta]{};
	    
	    else matrica=new int* [v.size()*koliko_puta]{};
	    
	    try{
	        
	       matrica[0]=new int[suma]; 
	    for(int i=1;i<v.size();i++) matrica[i]=matrica[i-1]+v.at(i-1);
	    
	    if(Osnovni_period!=0 && v.size()%Osnovni_period!=0)
	    for(int i=0;i<Osnovni_period-n;i++) matrica[i+v.size()]=matrica[i+v.size()-1]+v.at(i+v.size()-1);
	    
	    else if(Osnovni_period==0)
	    for(int i=0;i<v.size();i++)  matrica[i+v.size()]=matrica[i+v.size()-1]+v.at(v.size()-1-i);
	    
	    for(int i=0;i<v.size();i++){
	    	int vel_reda(v.at(i));
	        for(int j=0;j<v.at(i);j++)
	            matrica[i][j]=vel_reda--;
	        
	    }
	    
	    if(Osnovni_period!=0 && v.size()%Osnovni_period!=0){
	    	for(int i=0;i<Osnovni_period-n;i++){
	    		int vel_reda(v.at(i+n));
	    		for(int j=0;j<v.at(i+n);j++)
	    		matrica[i+v.size()][j]=vel_reda--;
	    	}
	 
	    }
	    
	    else if(Osnovni_period==0){
	    	
	    	for(int i=0;i<v.size();i++){
	    		int vel_reda(v.at(i));
	    		for(int j=0;j<v.at(i);j++)
	    		matrica[i+v.size()][j]=vel_reda--;
	    	}
	    }
	    
	    
	}
	
	catch(std::bad_alloc){
	delete[] matrica[0];
	throw;
	}
	
	}
	catch(std::bad_alloc){
	    delete[] matrica;
	    throw;
	}
	
	
	return matrica;
}


int main ()
{
	
	/*std::vector<int> v;
	cout<<"Unesite broj elemenata vektora: ";
	int br_elemenata;
	cin>>br_elemenata;
	cout<<"Unesite elemente vektora: ";
	int clan;
	for(int i=0;i<br_elemenata;i++) {
		cin>>clan;
		v.push_back(clan);
	}
	
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	
	int odabir_alokacije;
	cin>>odabir_alokacije;
	
	int Osnovni_period(OdrediOsnovniPeriod(v));
	
	if(odabir_alokacije==1){
	try{
	  
		int k;
		
	    auto a(AlocirajFragmentirano(v,k));
	    cout<<"Dinamicki alocirana matrica:"<<endl;
	    
	    if(Osnovni_period!=0){
	    for(int cnt=0;cnt<k;cnt++){
	    for(int i=0;i<Osnovni_period;i++){
	        for(int j=0;j<v.at(i);j++) {
	        	
	        	cout<<std::setw(3)<<std::left<<a[i][j];
	        }
	        cout<<endl;
	    
	    }
	    }
	     for(int i=0;i<k*Osnovni_period;i++) delete[] a[i];
	   delete[] a;
	    }
	    
	    else {
	    	for(int cnt=0;cnt<k;cnt++){
	    for(int i=0;i<v.size();i++){
	        for(int j=0;j<v.at(i);j++) {
	        	
	        	cout<<std::setw(3)<<std::left<<a[i][j];
	        }
	        cout<<endl;
	    
	    }
	    }
	    for(int i=0;i<k*v.size();i++) delete[] a[i];
	   delete[] a;
	    }
	    
	   
	}


	catch(const char poruka[]){
		cout<<"Izuzetak: "<<poruka<<endl;
	}
	catch(std::domain_error izuzetak){

	   cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	catch(...){
		
		cout<<"Izuzetak: Neuspjela alokacija!"<<endl;
	}
	
	}
	
	else{
		
		try{
	  
		int k;
		
	    auto a(AlocirajKontinualno(v,k));
	    cout<<"Dinamicki alocirana matrica:"<<endl;
	    
	    if(Osnovni_period!=0){
	    	for(int cnt=0;cnt<k;cnt++){
	    for(int i=0;i<Osnovni_period;i++){
	        for(int j=0;j<v.at(i);j++) cout<<std::setw(3)<<std::left<<a[i][j];
	        cout<<endl;
	    }
	    }
	    }
	    
	    
	  	else {
	  		for(int cnt=0;cnt<k;cnt++){
	    for(int i=0;i<v.size();i++){
	        for(int j=0;j<v.at(i);j++) cout<<std::setw(3)<<std::left<<a[i][j];
	        cout<<endl;
	    }
	  	}
	  	}
	    
	   delete[] a[0];
	   delete[] a;
	}
	
	catch(const char poruka[]){
		cout<<"Izuzetak: "<<poruka<<endl;
	}
	catch(std::domain_error izuzetak){

	   cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	catch(...){
		
		cout<<"Izuzetak: Neuspjela alokacija!"<<endl;
	}

		
	}
	*/
	
	  //AT12(skriveni) - trivijalan (kontinualna, periodican, izuzetak) 
    
        const std::vector<int> vektor{1, -2, 3, 4, 1, -2};
        int brojPuta{};
        int **matrica{nullptr};
        try
        {
            matrica = AlocirajKontinualno(vektor, brojPuta); 
            std::cout << "Ovo se ne smije ispisati!" << std::endl;       
        }
        catch(std::domain_error e)
        {
            if (matrica == nullptr)
                std::cout << "OK." << std::endl;
            std::cout << "Izuzetak: " << e.what();
        }
	return 0;
}