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
#include <stdexcept>
#include <iomanip>

using namespace std;

typedef vector<double> vek;
typedef vector<vector<double>> mat;//lijepi c#


bool Grbava(mat m){
	
	for(int i=0;i<m.size()-1;i++)
		if(m.at(i).size()!=m.at(i+1).size()) return true;		
	
	return false;
}


mat NajvecaPlaninaMatrice(mat m){
	
	
	int pi=0,pj=0,ps=0;
	int p=0;
	double suma=0;
	double temp=0;
	double ptemp=0;
	mat planina;
	
	if(Grbava(m)){ throw domain_error("Matrica nije korektna");return planina;}
	
	for(int i=0;i<m.size();i++)//Kroz sve redove
	{
		for(int j=0;j<m.at(i).size();j++)//
		{
			suma=0;
			temp=0;
			ptemp=0;
		//	cout<<"Radi za :"<<m[i][j]<<endl;
			for(p=0;p<=i && p<=j && p<m.size()-i && p<m.at(i).size()-j;p++)
			{
			
			//suma-=2*temp;
			suma=0;
			
				for(int g=i-p;g<=p+i;g++)
					for(int k=j-p;k<=j+p;k++)
							suma+=m.at(g).at(k);
				
				
			//if(m.at(i).at(j)==130)cout<<"\nSuma je:"<<suma<<" A temp:"<<temp<<" Suma-temp="<<suma-temp;
			
			if(suma-temp>=ptemp && p!=0)break;
			
				ptemp=suma-temp;
				temp=suma;
				
				
			//	cout<<" Suma je "<<suma<<" Na "<<i<<" "<<j<<" i p= "<<p<<endl;
				
					if(p>=ps){

				if((p==ps && m.at(i).at(j)>m.at(pi).at(pj)) || p>ps){
				pi=i;pj=j;ps=p;
				}
					}
					
			
			}
			
		}
		
	}
//	3 3 1 2 3 0 9 0 0 0 0
//	6 6 0 0 0 15 12 6 1 25 1 5 2 9 1 1 20 15 10 5 3 2 19 130 14 8 90 6 20 12 17 2 12 3 5 1 8 4
	vek pl;
	
	for(int i=pi-ps;i<=pi+ps;i++)
	{
		
		for(int j=pj-ps;j<=pj+ps;j++)
		{
			pl.push_back(m.at(i).at(j));
		}
		planina.push_back(pl);
		pl.resize(0);
		
	}
	
	
	
	return planina;
}

int main ()
{
	
	mat m1;
	mat planina;
	vek pom;
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			double x;
			cin>>x;
			pom.push_back(x);
		}
		m1.push_back(pom);
		pom.resize(0);
	}
	try{
	planina=NajvecaPlaninaMatrice(m1);
	}
	 catch (domain_error izuzetak){
    cout<<izuzetak.what();
    }

	cout<<endl<<"Najveca planina unesene matrice je:"<<endl;
	for(int i=0;i<planina.size();i++)
	{
		for(int j=0;j<planina.at(i).size();j++){
		cout<<right<<setw(6)<<planina.at(i).at(j);
		}
		cout<<endl;
	}

	return 0;
}