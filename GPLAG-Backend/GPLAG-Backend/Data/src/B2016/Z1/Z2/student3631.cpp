/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include<stdexcept>
#include<iomanip>

using namespace std;
typedef vector<vector<double>> Matrica;

Matrica HorizontalnoOgledalo(Matrica a){
		Matrica horizont(a.size(),vector<double> (a[0].size()));		
			for(int i=0;i<a.size();i++) {
		for(int j=0;j<a[0].size();j++) {
			horizont[i][a[0].size()- 1-j]=a[i][j];
		}
	}
		return horizont;
}

Matrica VertikalnoOgledalo(Matrica a){
	    Matrica vertikal(a.size(),vector<double> (a[0].size()));
		for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			vertikal[a.size()- 1-i][j]=a[i][j];
		}
	}
	return vertikal;
}

Matrica VertikalnoHorizontalnoOgledalo(Matrica a){
	Matrica verthor(a.size(),vector<double> (a[0].size()));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			verthor[a.size()- 1-i][a[0].size()- 1-j]=a[i][j];
		}
	}
	
	return verthor;
	
}
	
Matrica OgledaloMatrica(Matrica a) {

 if(a.size()==0) return a;  
    Matrica ogledalo(3*(a.size()), vector<double> (3*(a[0].size())));
     
    
    for(int i=0;i+1<a.size();i++){
      if(a[i].size()!=a[i+1].size()) throw domain_error("Matrica nije korektna"); 
    }
    
    
    if(a[0].size()==1 && a.size()==1) {
    Matrica hehe(3*(a[0].size()), vector<double> (3*(a.size())));
    for(int i=0;i<3*(a.size());i++){
    	for(int j=0;j<3*(a[0].size());j++){
    		hehe[i][j]=a[0][0];
    	}
    }	
    	return hehe;
    }
   

	Matrica horizont(a.size(),vector<double> (a[0].size()));
	Matrica vertikal(a.size(),vector<double> (a[0].size()));
	Matrica verthor(a.size(),vector<double> (a[0].size()));


horizont=HorizontalnoOgledalo(a);
vertikal=VertikalnoOgledalo(a);
verthor=VertikalnoHorizontalnoOgledalo(a);

for(int i=0;i<a.size();i++){
	for(int j=0;j<a[0].size();j++){
		ogledalo[i][j]=verthor[i][j];
	}

}

for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[i][j+a[0].size()]=vertikal[i][j];
	}

}

for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[i][j+2*(a[0].size())]=verthor[i][j];
	}

}

for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[a.size()+i][j]=horizont[i][j];
	}

}
		
  /*unesena matrica*/
 for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
  		ogledalo[i+a.size()][j+a[0].size()]=a[i][j];
  	}
 
  }
	
	
for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[a.size()+i][j+2*a[0].size()]=horizont[i][j];
	}

}
	

for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[2*a.size()+i][j]=verthor[i][j];
	}

}

for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[2*a.size()+i][j+a[0].size()]=vertikal[i][j];
	}
	
}

for(int i=0;i<a.size();i++){
	for(int j=0 ;j<a[0].size() ;j++){
		ogledalo[2*a.size()+i][2*a[0].size()+j]=verthor[i][j];
		
	}
	
}


	return ogledalo;
}


int main ()
{
	try{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) { cout<<"Dimenzije matrice moraju biti nenegativne!"<<endl; return 0;}
	Matrica a(m, vector<double> (n));
    cout<<"Unesite elemente matrice: "<<endl;
    for(int i=0;i<m;i++) {
    	for (int j=0;j<n;j++){
    		cin>>a[i][j];
    	}
    }
   
	Matrica ogl(3*m, vector<double> (3*n) );
	ogl=OgledaloMatrica(a);
	cout<<"Rezultantna matrica: "<<endl;

    if(m==1 && n==1){
    		for(int i=0; i<3*m;i++){
		for(int j=0;j<3*n;j++){
			cout<<setw(2)<<ogl[i][j];
		}
		cout<<endl;
	} 
    }
else{
	for(int i=0; i<3*m;i++){
		for(int j=0;j<3*n;j++){
			cout<<setw(4)<<ogl[i][j];
		}
		cout<<endl;
	} }
	}catch (domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
	return 0;
}