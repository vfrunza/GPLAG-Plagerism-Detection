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
#include <new>
#include <stdexcept>
#include <vector>
#include <iomanip>
using namespace std;
template<typename tip1>
int DajPeriod(vector<tip1> w){
	int period(0);
	for(int i=1;i<w.size();i++){
		for(int j=0;i<w.size();j++){
			if((j+i)<w.size()){
				if(w.at(j)!=w.at(j+i))break;
			}
			if(j==(w.size()-1)){
				period=i;
				break;
			}
		}
		if(period!=0)break;
	}
	return period;
}
template<typename tip>
tip **AlocirajFragmentirano(const vector<tip> &v,int &koliko_puta){
	for(int i=0;i<v.size();i++){
		if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
	}
	if(v.size()==0) throw domain_error("Prazan vektor!");
	int p,k=0;
	tip **mat(nullptr);
	int brojac=0;
	p=DajPeriod(v);
	tip max=v.at(0);
	for(int i=0;i<v.size();i++){
		if(v.at(i)>max){
			max=v.at(i);
		}
	}
	if(p!=0){
		if((v.size())%p!=0){
			while((v.size()+brojac)%p!=0){
			brojac++;
			}
		koliko_puta=(v.size()+brojac)/p;
		try{
			mat=new tip*[v.size()+brojac];
			for(int i=0;i<(v.size()+brojac);i++){
				if(i<v.size()){
					try{
			  	mat[i]=new tip[v.at(i)];
				}
				catch(...){
					throw;
				}
				}
				else{
					mat[i]=new tip[v.at(i-p)];
				}
			}
			
		}
		catch(...){
		
			throw;
		}
		}
	else{
		koliko_puta=(v.size()+brojac)/p;
		mat=new tip*[v.size()+brojac];
			for(int i=0;i<(v.size()+brojac);i++){
				if(i<v.size()){
				mat[i]=new tip[v.at(i)];
				}
				else{
					mat[i]=new tip[v.at(i-p)];
				}
			}
    	}
	for(int i=0;i<v.size()+brojac;i++){
		if(i<v.size()){
			if(i>max-1 && k>max-1) k=0;
		 for(int j=0;j<v.at(i);j++){
		 	
		 	if(k==j){
		 		
		 		mat[i][j]=max;
		 	}
			else{
				mat[i][j]=max-k+j;
			}
			
	      }
	      k++;
	
	    }
     	else{
     		
     		for(int j=0;j<v.at(i-p);j++){
     			if(k==j){
     			mat[i][j]=max;	
     			}
     			else{
     			mat[i][j]=max-k+j;
     			}
     		} 
     	}
	}
		
	return mat;
}
else{
	koliko_puta=2;
	try{
	mat=new tip*[(v.size())*2];
	for(int i=0;i<2*v.size();i++){
		if(i<v.size()){
	   try{
		mat[i]=new tip[v.at(i)];
	   }
	   catch(...){
	   	throw;
	   }
		}
	else{
		
		mat[i]=new tip[v.at(i-v.size())];
		
	 }
   }
 }
 catch(...){
 		
 	throw;
 }
 for(int i=0;i<2*v.size();i++){
 	if(i<v.size()){
 		if(i>=v.size() && k>=v.size()) k=0;
 	for(int j=0;j<v.at(i);j++){
 		if(k==j){
 		mat[i][j]=max;
 		}
 		else{
 			mat[i][j]=max-k+j;
 		}
 	}
 	k++;
  }
  else{
  	if(k>=v.size())k=0;
  	for(int j=0;j<v.at(i-v.size());j++){
  		
  		if(k==j){
  	mat[i][j]=max;
  	
  		}
  		else{
  			mat[i][j]=max-k+j;
  		}
  	}
  	k++;
  }
 }
}
return mat;
}
template<typename tip>
tip **AlocirajKontinualno(const vector<tip> &v,int &koliko_puta){
	for(int i=0;i<v.size();i++){
		if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
	}
	if(v.size()==0) throw domain_error("Prazan vektor!");
	int p;
	tip **mat(nullptr);
	int brojac(0),brel(0);
	p=DajPeriod(v);
	if(p!=0){
		if((v.size())%p!=0){
			while((v.size()+brojac)%p!=0){
				brojac++;
			}
			for(int i=0;i<v.size()+brojac;i++){
				if(i<v.size()){
					brel=brel+v.at(i);
				}
				else{
					brel=brel+v.at(i-p);
				}
			}
			koliko_puta=(v.size()+brojac)/p;
			try{
				mat=new tip*[v.size()+brojac];
				mat[0]=new tip[brel];
				for(int i=1;i<v.size()+brojac;i++){
					if(i<v.size()){
					mat[i]=mat[i-1]+v.at(i-1);
					}
					else{
						mat[i]=mat[i-1]+v.at(i-p-1);
					}
				}
			}
			catch(...){
				throw;
			}
		 }
		else{
			koliko_puta=(v.size())/p;
			try{
				mat=new tip*[v.size()];
				for(int i=0;i<v.size()+brojac;i++){
					brel=brel+v.at(i);
				}
				mat[0]=new tip[brel];
				for(int i=1;i<v.size();i++){
					mat[i]=mat[i-1]+v.at(i);
				}
			}
			catch(...){
				throw;
			}
		}
		for(int i=0;i<v.size()+brojac;i++){
			if(i<v.size()){
			for(int j=0;j<v.at(i);j++){
				mat[i][j]=v.at(i)-j;
			}
			}
			else{
				for(int j=0;j<v.at(i-p);j++){
					mat[i][j]=v.at(i-p)-j;
				}
			}
		}
		return mat;
	}
	else{
		for(int i=0;i<2*v.size();i++){
			if(i<v.size()){
			 brel=brel+v.at(i);
			}
			else{
			 brel=brel+v.at(i-v.size());
			}
		}
		mat=new tip*[2*(v.size())];
		mat[0]=new tip[brel];
		for(int i=1;i<2*(v.size());i++){
			if(i<=v.size()){
				mat[i]=mat[i-1]+v.at(i-1);
			}
			else{
				mat[i]=mat[i-1]+v.at(i-v.size());
			}
		}
		for(int i=0;i<2*v.size();i++){
			if(i<v.size()){
			for(int j=0;j<v.at(i);j++){
				mat[i][j]=v.at(i)-j;
			 }
			}
			else{
				for(int j=0;j<v.at(i-v.size());j++){
					mat[i][j]=v.at(i-v.size())-j;
				}
			}
		}
	}
return mat;
}

int main (){
	
		int n,x,f,koliko(0);
		int T;
			int **mat;
		try{
		vector<int> v;
		cout<<"Unesite broj elemenata vektora: ";
		cin>>n;
		cout<<"Unesite elemente vektora: ";
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		T=DajPeriod(v);
		cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		cin>>f;
		if(f==1){
			mat=AlocirajFragmentirano(v,koliko);
			cout<<"Dinamicki alocirana matrica: ";
			cout<<endl;
			if(T!=0){
				for(int i=0;i<T*koliko;i++){
				if(i<v.size()){
				for(int j=0;j<v.at(i);j++){
					cout<<setw(3)<<left<<mat[i][j];
				}
				cout<<endl;
				}
				else{
					for(int j=0;j<v.at(i-T);j++){
						cout<<setw(3)<<left<<mat[i][j];
					}
				
				cout<<endl;
			}
			}
			for(int i=0;i<T*koliko;i++){
		     delete [] mat[i];
	         }
        	 delete [] mat;
	         return 0;
		}
		else{
			for(int i=0;i<2*v.size();i++){
				if(i<v.size()){
					for(int j=0;j<v.at(i);j++){
						cout<<setw(3)<<left<<mat[i][j];
					}
					cout<<endl;
				}
				else{
					for(int j=0;j<v.at(i-v.size());j++){
						cout<<setw(3)<<left<<mat[i][j];
					}
					cout<<endl;
				}
			}
			for(int i=0;i<2*v.size();i++){
		     delete [] mat[i];
	         } 
	         delete [] mat;
	         return 0;
				
		}
		
	}
	else{
		if(T!=0){
		mat=AlocirajKontinualno(v,koliko);
		cout<<"Dinamicki alocirana matrica: "<<endl;
		for(int i=0;i<T*koliko;i++){
			if(i<v.size()){
			for(int j=0;j<v.at(i);j++){
				cout<<setw(3)<<left<<mat[i][j];
			}
			cout<<endl;
		  }
		  else{
		  	for(int j=0;j<v.at(i-T);j++){
		  		cout<<setw(3)<<left<<mat[i][j];
		  	}
		  	cout<<endl;
		  }
		}
		delete [] mat[0];
		delete [] mat;
	}
	else{
		mat=AlocirajKontinualno(v,koliko);
		cout<<"Dinamicki alocirana matrica: "<<endl;
		for(int i=0;i<2*v.size();i++){
			if(i<v.size()){
				for(int j=0;j<v.at(i);j++){
					cout<<setw(3)<<left<<mat[i][j];
				}
				cout<<endl;
			}
			else{
				for(int j=0;j<v.at(i-v.size());j++){
					cout<<setw(3)<<left<<mat[i][j];
				}
				cout<<endl;
			}
		}
			delete [] mat[0];
		    delete [] mat;
	}
		}
		}
	catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
}