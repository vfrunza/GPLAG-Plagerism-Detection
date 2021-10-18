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
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;
typedef vector<vector<double>> Matrica;
double Zbir(const Matrica &a,int i,int j, int n){
	double suma(0);
	if(n>0 && a.size() >= n+n-1 && a.at(0).size()>=n+n-1){
	for(int k=-n; k<n; k++)

	   {    for(int z=-n; z<n; z++){
	      
	        
	        if(n==1) {if((k==0 && z==0)) {z++;
	        	suma+=a.at(i+k).at(j+z);
	        } else
	   		suma+=a.at(i+k).at(j+z);
	   } else {
	   	    if(k==n || z==-n || k==-n || z==n){
	   	       if(k+i == a.size())
	   	      suma+=a.at(i+k-1).at(j+z);
	   	      else if(z+j == a.at(i).size())
	   	      suma+=a.at(i+k).at(j+z-1);
	   	      else suma+=a.at(i+k).at(j+z);
	   		   }
	   }
	     
	   }
	   }
	}
	return suma;
}
	
Matrica NajvecaPlaninaMatrice(Matrica &a){
	int max(0),maxi(0),maxj(0);
	Matrica x;
	vector<int> vmax,imax,jmax;
	if(a.size()==0 || a.at(0).size()==0) return x;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			if(a.at(j).size() != a.at(i).size())
			throw domain_error("Matrica nije korektna\n");
		}
	}
	
if(a.size()>2){	for(int i=1; i<a.size()-1; i++){
		for(int j=1;j<a.at(i).size()-1; j++){
	
				
				if(a.at(i).at(j)>Zbir(a,i,j,1)) {
					
					int brojac(1);
					for(int h=2;;h++){
						if(i>h-1 && j>h-1 && i<(a.size()-h+1) && j<(a.size()-h+1) && Zbir(a,i,j,h)<Zbir(a,i,j,(h-1))){
						brojac++;
						max = h;  }
						else {if(brojac>1){
							vmax.push_back(max);
							imax.push_back(i);
							jmax.push_back(j);
						}
							break;
							
						}
					}
					if(brojac==1){
						vmax.push_back(1);
						imax.push_back(i);
						jmax.push_back(j);
					}
					}
			}
	
}   max=vmax.at(0);
    maxi=imax.at(0);
    maxj=jmax.at(0);
//  Traženje najveće širine
    if(vmax.size()>1){
	for(int i=1;i<vmax.size(); i++){
		if(vmax.at(i)>max){
			max = vmax.at(i);
			maxi = imax.at(i);
			maxj = jmax.at(i);
		
		} else 
		for(int j=1; j<vmax.size(); j++){
		
			if(vmax.at(j)==vmax.at(i)){
				if(a.at(imax.at(j)).at(jmax.at(j)) > a.at(imax.at(i)).at(jmax.at(i)))
				{max = vmax.at(j); 
				 maxi = imax.at(j);
				 maxj = jmax.at(j);
				} else if(a.at(imax.at(j)).at(jmax.at(j)) == a.at(imax.at(i)).at(jmax.at(i))) {
					max = vmax.at(i);
					maxi = imax.at(i);
					maxj = jmax.at(i);
				}
				
			 else {
				if(imax.at(i) > imax.at(j)){
				max = vmax.at(j); 
				maxi = imax.at(j);
				maxj = jmax.at(j);	
				}
				else if(imax.at(i) == imax.at(j)){
					if(jmax.at(i) > jmax.at(j)) {max = vmax.at(j);
						maxi = imax.at(j);
						maxj = jmax.at(j);
					} else {
						max = vmax.at(i);
						maxi = imax.at(i);
						maxj = jmax.at(i);
					}}
				}
			}
	}}}
//  Ukoliko u matrici imamo planine iste širine
   
	int z=0;
	for(int i=-max;i<=max; i++){
		
		x.resize(z+1);
		for(int j=-max; j<=max; j++){
			x.at(z).push_back(a.at(maxi+i).at(maxj+j));
		}
		z++;
	}} else
	{   max=a.at(0).at(0);
	    x.resize(1);
		for(int i=0; i<a.size();i++){
			for(int j=0; j<a.at(i).size(); j++){
				if(a.at(i).at(j)>max) max=a.at(i).at(j);
			}
		}
		x.at(0).push_back(max);
		
	}
	return x;
}

int main ()
{   try{
	cout << "Unesite dimenzije matrice (m i n): "; 
    int m,n;
    
    cin >> m >> n;
    if(m<0 || n<0)
    {	cout << "Dimenzije matrice moraju biti nenegativne!";
    return 0;}
    double b;
    Matrica a;
    cout << "Unesite elemente matrice: ";
    for(int i=0; i<m; i++){
    	a.resize(i+1);
    	for(int j=0; j<n; j++){
    		cin >> b;
    		a.at(i).push_back(b);
    	}
    }
    Matrica s = NajvecaPlaninaMatrice(a);
    cout <<endl<<"Najveca planina unesene matrice je: "<<endl;;
    for(int i=0; i<s.size(); i++){
    	for(int j=0; j<s.at(i).size(); j++){
    		cout <<setw(6)<< s.at(i).at(j) ;
    	}
    	cout << endl;
    }}
    catch(const domain_error &e){
    	cout << "Izuzetak: "<<e.what()<<endl;
    }
    catch(...){
    	cout << "Pogrešan izuzetak!";
    }
	return 0;
}