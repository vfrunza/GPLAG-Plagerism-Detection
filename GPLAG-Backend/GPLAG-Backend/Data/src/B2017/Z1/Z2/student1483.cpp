/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>
using namespace std;
typedef vector<vector<double>> Matrica;
Matrica NajvecaPlaninaMatrice(Matrica mat){
	Matrica konacna;
	int vel1=0,vel2=0,k=0,pi=0,pj=0,p=0,q=0,w=0,t=0;
    double sumas=0,suman=0,max=-1000000000,vrh1,vrh2;
    for(int i=0;i<mat.size();i++){
    	if((mat.at(0).size())!=(mat.at(i).size())){
    		  throw domain_error("Matrica nije korektna");
    		break;
    	}
    }
	for(int i=0; i<mat.size(); i++){
     for(int j=0; j<mat.at(i).size(); j++){
			 	while((((i-1-k)>=0) && ((i+1+k)<mat.size())) && (((j-1-k)>=0) && ((j+1+k)<(mat.at(i).size())))){
			    sumas=mat.at(i).at(j+1+k)+mat.at(i).at(j-1-k)+mat.at(i+1+k).at(j)+mat.at(i-1-k).at(j)+mat.at(i-1-k).at(j-1-k)+mat.at(i-1-k).at(j+1+k)+mat.at(i+1+k).at(j-1-k)+mat.at(i+1+k).at(j+1+k);
			     if((mat.at(i).at(j))>sumas){
			 	vel1++; 
			 	if(w==0){
			 	vrh1=mat.at(i).at(j);
			 	w=1;
			     }
			     else{
			     	vrh2=mat.at(i).at(j);
			     	t=1;
			     }
			     
			      }
			 	k++;
			 	if((((i-1-k)>=0) && ((i+1+k)<mat.size())) && (((j-1-k)>=0) && ((j+1+k)<(mat.at(i).size())))){
			 	suman=mat.at(i).at(j+1+k)+mat.at(i).at(j-1-k)+mat.at(i+1+k).at(j)+mat.at(i-1-k).at(j)+mat.at(i-1-k).at(j-1-k)+mat.at(i-1-k).at(j+1+k)+mat.at(i+1+k).at(j-1-k)+mat.at(i+1+k).at(j+1+k);
			 	
			    if(sumas>suman){
			    	vel1++;
			    	k++;
			    }
			 	}
			 	
		  }   
		      if(t==1){
		      if((vel1==vel2) && (vrh2>vrh1)){
		      	vrh1=vrh2;
		      	pi=i;
		      	pj=j;
		      }
		      }
			  if(vel1>vel2){
		   	 	vel2=vel1;
		   	 	pi=i;
		   	 	pj=j;
		   	 }
		   	 
		   	  k=0; vel1=0; sumas=0; suman=0;
		   	 if(i==0 || j==0 || i==(mat.size()-1) || j==(mat.at(0).size()-1)){
		   	 	if(mat.at(i).at(j)>max){
		   	 	max=mat.at(i).at(j);
               }	
		   	 }
     }
		}
		if(vel2>0){
	     konacna.resize((2*vel2)+1);
		for(int i=0;i<konacna.size();i++){
			   konacna.at(i).resize((2*vel2)+1);
			for(int j=0;j<konacna.at(i).size();j++){
				konacna.at(i).at(j)=mat.at(pi-vel2+p).at(pj-vel2+q);
				q++;
			}
			p++;
			q=0;
		}
	}
	else if(max!=-1000000000){
		konacna.resize(1);
		konacna.at(0).resize(1);
		konacna.at(0).at(0)=max;
	}
	else{
		return konacna;
	}
	 return konacna;
	}
int main (){
    try{
 	int m,n;
 	double b;
	Matrica M;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice:";
    for(int i=0;i<m;i++){
    	     M.resize(i+1);
    	for(int j=0;j<n;j++){
    		cin>>b;
    		M.at(i).push_back(b);
    	}
    }
	M=NajvecaPlaninaMatrice(M);
	cout<<endl<<"Najveca planina unesene matrice je:"<<endl;
	for(int i=0;i<M.size();i++){
		for(int j=0;j<M.at(i).size();j++){
			cout<<setw(6)<<M.at(i).at(j);
		}
		cout<<endl;
    	}
    }
    catch(domain_error izuzetak){
    	cout<<"Izuzetak: "<<izuzetak.what()<<endl;
    }
	return 0;
}