#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> matrix;

matrix hm(matrix m){
	matrix ret(m.size());
	
	for(int i = 0; i < int(ret.size()); i++){
		ret[i].resize(m[i].size());
		for(int j = 0; j < int(ret[i].size()); j++){
			ret[i][j] = m[i][int(ret[i].size()) - j-1];
		}
	}
	return ret;
}

matrix vm(matrix m){
	matrix ret(m.size());
	
	for(int i = 0; i < int(ret.size()); i++){
		ret[i].resize(m[i].size());
		for(int j = 0; j < int(ret[i].size()); j++){
			ret[i][j] = m[int(ret.size() - i -1)][j];
		}
	}
	return ret;
}
bool korektna(matrix m){
	for(int i = 0; i < m.size(); i++){
		int x = int(m[i].size());
		for(int j = i; j < m.size(); j++){
			if(x != int(m[j].size()))
				return false;
		}
		return true;
	}
	return true;
}
std::vector<double> spojiVek(std::vector<double> vFin, std::vector<double> v2, std::vector<double> v3){
	for(int i = 0; i < v2.size(); i++)
		vFin.push_back(v2[i]);
	for(int i = 0; i < v3.size(); i++)
		vFin.push_back(v3[i]);
	return vFin;
}
matrix spojiMat(matrix mFin, matrix m2, matrix m3){
	for(int i = 0; i < m2.size(); i++)
		mFin.push_back(m2[i]);
	for(int i = 0; i < m3.size(); i++)
		mFin.push_back(m3[i]);
	return mFin;
}
matrix OgledaloMatrica(matrix m){
	if(!korektna(m)){
		throw std::domain_error("Matrica nije korektna");
	}
	matrix h(hm(m)), v(vm(m)), hv(hm(vm(m)));
	matrix num1(hv), num2(h);
	for(int i = 0; i < m.size(); i++){
		num1[i] = spojiVek(num1[i], v[i], hv[i]);
		h[i] = spojiVek(h[i],m[i],h[i]);
	}
	num1 = spojiMat(num1, h, num1);
	
	
	/*for(int i = 0; i < m.size(); i++){
		num1[i].insert(num1[i].end(), v[i].begin(), v[i].end());
		num1[i].insert(num1[i].end(), hv[i].begin(), hv[i].end());
		
		num2[i].insert(num2[i].end(), m[i].begin(), m[i].end());
		num2[i].insert(num2[i].end(), h[i].begin(), h[i].end());
	}
	matrix num3(num1);
	
	num1.insert(num1.end(), num2.begin(), num2.end());
	num1.insert(num1.end(), num3.begin(), num3.end());
	*/
	return num1;
}

int main (){
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	
	std::cin >> m >> n;
	if(n < 0 || m < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrix mat(m);
	std::cout << "Unesite elemente matrice: ";
	for(int i = 0; i < int(mat.size()); i++){
		mat[i].resize(n);
		for(int j = 0; j < n; j++){
			std::cin >> mat[i][j];
		}
	}
	std::cout << std::endl << "Rezultantna matrica: " << std::endl;
	try{
		mat = OgledaloMatrica(mat);
		for(int i = 0; i < mat.size(); i++){
			for(int j = 0; j < mat[i].size(); j++){
				std::cout << std::setw(4) << mat[i][j];
			}
			std::cout<<std::endl;
		}
	}catch(std::domain_error except){
		std::cout << except.what();
	}
	return 0;
}