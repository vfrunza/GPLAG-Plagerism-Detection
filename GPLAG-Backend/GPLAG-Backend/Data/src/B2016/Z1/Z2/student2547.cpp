/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <stdexcept>
#include <iomanip>
//.....TREBAM POPRAVITI IZLAZ IZ PROGRAMA ...

std::vector<std::vector<double>> v(std::vector<std::vector<double>> m){
	
	for(int k = 0, l = m.size() - 1; k < int (m.size()/2);k++,l--){
		std::swap(m[l],m[k]);
	}
	
	return m;
}


std::vector<std::vector<double>> h (std::vector<std::vector<double>> m){
	for(std::vector<double> &a : m){
		//...SWAP SAMO PRVI RED MATRICE
		for(int i = 0, j = a.size() - 1; i < a.size()/2; i++,j--){
			std::swap(a[i],a[j]);
		}
		
	
	}
		return m;
}

std::vector<std::vector<double>> hv (std::vector<std::vector<double>> m){
	return h(v(m));
}

std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>> mat){

	/*	
	for(int i = 0; i < mat.size(); i++) { 
	if(mat.size() < 0 || mat[i].size() < 0)
		throw std::domain_error("Dimenzije moraju biti nenegativne!");
	}
	*/
	
	int zadnja_vel =- 1;
	
	for(auto &x :mat){
		if(zadnja_vel == -1)
			zadnja_vel = x.size();
		
		if(zadnja_vel != x.size())
			throw std::domain_error("Matrica nije korektna");
		
		zadnja_vel = x.size();
		}

	std::vector<std::vector<double>> r;
	std::vector<std::vector<double>> h_v = hv(mat);
	std::vector<std::vector<double>> v_ = v(mat);
	std::vector<std::vector<double>> h_ = h(mat);
	
	/* 	hv v hv
		h m h
		hv v hv 
	*/
	
	//----------PRVI RED-------------
	int l = 0; 
	std::vector<double>prazan;
	for(int i = 0; i < h_v.size();i++){
		r.push_back(prazan);
		for(int j =0 ; j < h_v[i].size();j++){
			r[l].push_back(h_v[i][j]);
		}
		l++;
	}
	
	l = 0;
	for(int i = 0; i < v_.size();i++){
		r.push_back(prazan);
		for(int j = 0; j < v_[i].size();j++){
			r[l].push_back(v_[i][j]);
		}
		l++;
	}

	l = 0;
	for(int i = 0; i < h_v.size(); i++){
		r.push_back(prazan);
		for(int j = 0; j < h_v[i].size();j++){
			r[l].push_back(h_v[i][j]);
		}
		l++;
	}
	int k = l;
	//-----------------------DRUGI RED-------------------
	for(int i = 0; i < h_.size();i++){
	
		for(int j = 0; j < h_[i].size();j++){
			if(j == 0)
				r.push_back(prazan);
			r[l].push_back(h_[i][j]);
		}
		l++;
	}
	
	l = k;
	
	for(int i = 0; i < mat.size() ;i++){
		
		for(int j = 0; j < mat[i].size();j++){
			if(j == 0)
				r.push_back(prazan);
			r[l].push_back(mat[i][j]);
		}
		l++;
	}
	
	l = k;
	
	for(int i = 0; i < h_.size();i++){
		
		for(int j = 0; j < h_[i].size();j++){
			if(j == 0)
				r.push_back(prazan);
			r[l].push_back(h_[i][j]);
		}
		l++;
	}
	
	//-------------------------------ZADNJI RED--------------
	
	k = l;
	for(int i = 0; i < h_v.size();i++){
		
		for(int j = 0; j < h_v[i].size();j++){
			if(j == 0)
				r.push_back(prazan);
			r[l].push_back(h_v[i][j]);
		}
		l++;
	}
	
	l = k;
	for(int i = 0 ; i <v_.size();i++){
		
		for(int j = 0; j < v_[i].size();j++){
			if(j == 0)
				r.push_back(prazan);
			r[l].push_back(v_[i][j]);
		}
		l++;
	}
	
	l = k;
	for(int i = 0; i < h_v.size();i++){
		
		for(int j = 0; j < h_v[i].size();j++){
			if(j == 0)
				r.push_back(prazan);
			r[l].push_back(h_v[i][j]);
		}
		l++;
	}
	
	
	return r;
}

int main ()
{
	/*
	std::vector<std::vector<double>> k = { 	{1,2,3},
								{4,5,6}	};
	*/
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>> m >> n;
	
	if(m < 0 || n < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!\n";
		//throw std::domain_error("Dimenzije moraju biti nenegativne!");
		return 0;
	}
	
	std::vector<std::vector<double>>k;
	std::cout<<"Unesite elemente matrice:\n";
	for(int i = 0; i < m; i++){
		k.push_back(std::vector<double>());
		for(int j = 0; j < n; j++){
			int l;
			std::cin >> l;
			k[i].push_back(l);
		}
	}
	std::cout<<"Rezultantna matrica: \n";
	for(std::vector<double> i : OgledaloMatrica (k) ){
		std::cout << " ";
		for(double j : i){
			std::cout<<std::setw(3)<<j << " ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}