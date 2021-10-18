/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(vektor n){

	matrica a;
	vektor b;
	int r{0};
	for(int i=0;i<n.size();i++){
		
		if(i+1==n.size())
		{
			if(n[i]>=n[i-1]) b.push_back(n[i]);
			r++;
			a.resize(r);
			a[r-1].resize(b.size());
			for(int j=0;j<b.size();j++){
				a[r-1][j]=b[j];}
		} else {
		if(n[i]<=n[i+1]) b.push_back(n[i]);
		if((n[i]>n[i+1])&&(b.size()!=0)){
			r++;
			b.push_back(n[i]);
			a.resize(r);
			a[r-1].resize(b.size());
			for(int j=0;j<b.size();j++){
				a[r-1][j]=b[j];}
			for(int k=(b.size()-1);k>=0;k--){
				b.erase(b.begin()+k);}
			
	   
		}
	
		}
	
		}
		
	
	return a;
}
matrica OpadajuciPodnizovi(vektor n){
	matrica a;
	vektor b;
	int r{0};
	
	for(int i=0;i<n.size();i++){
		if(i+1==n.size()){
			if(n[i]<=n[i-1]) b.push_back(n[i]);
			r++;
			a.resize(r);
			a[r-1].resize(b.size());
			for(int j=0;j<b.size();j++){
				a[r-1][j]=b[j];}
		} else {
		if(n[i]>=n[i+1]) b.push_back(n[i]);
		if((n[i]<n[i+1])&&(b.size()!=0)){
			r++;
			b.push_back(n[i]);
		    a.resize(r);
			a[r-1].resize(b.size());
			for(int j=0;j<b.size();j++){
				a[r-1][j]=b[j];}
			for(int k=(b.size()-1);k>=0;k--){
				b.erase(b.begin()+k);}
		}
		}
		}
	
	return a;
}

int main ()
{
	
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int m;
	std::cin>>m;
    vektor n;
	if(m<0){std::cout<<"Dimenzije vektora moraju biti nenegativne!"; return 0; }
   
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<m;i++)
	{
		int k;
		std::cin>>k;
		n.push_back(k);
	}
	matrica x=RastuciPodnizovi(n);
	matrica y=OpadajuciPodnizovi(n);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<x.size();i++){
		for(int j=0; j<x[i].size();j++){
			std::cout<<std::setprecision(12)<<x[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<y.size();i++){
		for(int j=0; j<y[i].size();j++){
			std::cout<<std::setprecision(12)<<y[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}