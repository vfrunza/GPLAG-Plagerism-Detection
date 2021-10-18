#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

typedef std::vector<std::vector<double>> Matrica;

std::vector<double> okreni(std::vector<double>v){
	std::vector<double>v1;
	for(int i=v.size()-1;i>=0;i--)
		v1.push_back(v[i]);
	return v1;
}

Matrica h(Matrica mat){
	for(int i=0;i<mat.size();i++)
		mat[i]=okreni(mat[i]);
	return mat;
}
//testiraj ponovo
Matrica v(Matrica mat){
	for(int j=0;j<mat[0].size();j++){
		std::vector<double>v;
		for(int i=0;i<mat.size();i++){
			v.push_back(mat[i][j]);
		}
		v=okreni(v);
		for(int k=0;k<v.size();k++)
			mat[k][j]=v[k];
	}
	return mat;
}

Matrica hv(Matrica mat){
	mat=h(mat);
	mat=v(mat);
	return mat;
}

Matrica OgledaloMatrica (Matrica mat){
	if(mat.size()==0) return mat;
    Matrica mat1(mat.size()*3, std::vector<double>(mat[0].size()*3));
	bool grbava=true;
	for(int i=0;i<mat.size();i++){
		if(mat[0].size()!=mat[i].size()) {
			grbava=false; break;
		}
	}
	
	if(grbava==false) throw std::domain_error ("Matrica nije korektna");
	if(mat.size()<0 || mat[0].size()<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	Matrica HV=hv(mat);
	Matrica H=h(mat);
	Matrica V=v(mat);
	
	for(int i=0;i<HV.size();i++){
		for(int j=0;j<HV[0].size();j++)
			mat1[i][j]=HV[i][j];
	}
	
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V[0].size();j++)
			mat1[i][j+V[0].size()]=V[i][j];
	}
	
	for(int i=0;i<HV.size();i++){
		for(int j=0;j<HV[0].size();j++)
		mat1[i][j+(HV[0].size())*2]=HV[i][j];
	}
	
	for(int i=0;i<H.size();i++){
		for(int j=0;j<H[0].size();j++)
			mat1[i+H.size()][j]=H[i][j];
	}
	
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++)
			mat1[i+mat.size()][j+mat[0].size()]=mat[i][j];
	}
	
	for(int i=0;i<H.size();i++){
		for(int j=0;j<H[0].size();j++)
			mat1[i+H.size()][j+(H[0].size())*2]=H[i][j];
	}
	
	for(int i=0;i<HV.size();i++){
		for(int j=0;j<HV[0].size();j++)
			mat1[i+(HV.size())*2][j]=HV[i][j];
	}
	
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V[0].size();j++)
			mat1[i+(V.size())*2][j+V[0].size()]=V[i][j];
	}
	
	for(int i=0;i<HV.size();i++){
		for(int j=0;j<HV[0].size();j++)
			mat1[i+(HV.size())*2][j+(HV[0].size())*2]=HV[i][j];
	}
	
	return mat1;
}

void IspisiMatricu (Matrica m){
	for(std::vector<double> red: m){
		for(double x: red) std::cout<<std::setw(4)<<x;
		std::cout<<std::endl;
	}
}

Matrica Unesi(int br_r, int br_k){
	Matrica m(br_r, std::vector<double>(br_k));
	for(int i=0;i<br_r;i++){
		for(int j=0;j<br_k;j++)
			std::cin>>m[i][j];
	}
	return m;
}

int main ()
{
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
		std::cout<<"Unesite elemente matrice: ";
		Matrica mat=Unesi(m,n);
		mat=OgledaloMatrica(mat);
		std::cout<<std::endl;
		std::cout<<"Rezultantna matrica: "<<std::endl;
		IspisiMatricu(mat);
	}
	catch (std::domain_error poruka){
		std::cout<<poruka.what();}
	return 0;
}