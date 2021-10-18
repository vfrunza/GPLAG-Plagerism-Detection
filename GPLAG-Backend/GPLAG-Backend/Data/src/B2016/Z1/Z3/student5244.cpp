/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> p;
	std::vector<double> temp;
	int w=0;
	
	for(int i=0;i<v.size();i++){
		temp.resize(0);
		while(i<v.size()-1 && v[i]<=v[i+1]){
			temp.push_back(v[i]);
			i++;
		} 
		if(i!=v.size() && i>0 && v[i-1]<=v[i]){
			temp.push_back(v[i]);
		}
		if(temp.size()>1){ 
			p.resize(w+1);
			p[w]=temp;
			w++;
		}
	}
	return p;	
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> r;
	std::vector<double> t;
	int k=0;
	
	for(int i=0;i<v.size();i++){
		t.resize(0);
		while(i<v.size()-1 && v[i]>=v[i+1]){
			t.push_back(v[i]);
			i++;
		}
		if(i!=v.size() && i>0 && v[i-1]>=v[i]) t.push_back(v[i]);
		if(t.size()>1){
			r.resize(k+1);
			r[k]=t;
			k++;
		}
	}
	return r;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>v[i];
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;;
	std::vector<std::vector<double>> m(RastuciPodnizovi(v));
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			std::cout<<std::setprecision(12)<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::vector<std::vector<double>> mat(OpadajuciPodnizovi(v));
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0;i<mat.size();i++){
    	for(int j=0;j<mat[i].size();j++){
    		std::cout<<std::setprecision(12)<<mat[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }
	
	return 0;
}