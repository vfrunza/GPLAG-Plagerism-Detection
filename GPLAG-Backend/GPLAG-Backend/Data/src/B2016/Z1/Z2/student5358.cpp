#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
void IspisMatrice(std::vector<std::vector<double>> ma){
	for(int i=0;i<ma.size();i++){
		for(int j=0;j<ma[0].size();j++)
		std::cout<<std::setw(4)<<ma[i][j];
		std::cout<<std::endl;
	}
}
std::vector<std::vector<double>> h(std::vector<std::vector<double>>ma){
	double pom;
	//int kr=ma[0].size()-1;
	for(int i=0;i<ma.size();i++){
		int kr=ma[0].size()-1;
	for(int j=0;j<ma[0].size()/2;j++){
		//double kr=duz-1;
		pom=ma[i][j];
		ma[i][j]=ma[i][kr];
		ma[i][kr]=pom;
		//if(ma[0].size()%2==0 && ma[0].size()!=2)
		kr--;
	}
	}
	return ma;
}
std::vector<std::vector<double>> v(std::vector<std::vector<double>>ma){
	double br=ma.size()-1;
	for(int i=0;i<ma.size()/2;i++){
		std::vector<double> pom=ma[i];
		//double br=ma.size()-1;
		ma[i]=ma[br];
		ma[br]=pom;
		br--;
	}
	return ma;
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>>ma){
	if(ma.size()==0)return ma;
	int redova =ma.size();
	//int kolona =ma[0].size();
	int l;
	for(int i=0;i<redova;i++){
		l=ma[i].size();
		for(int j=0;j<redova;j++)
		if(l!=ma[j].size())throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double>>nova(3*ma.size(),std::vector<double>(3*ma[0].size()));
	std::vector<std::vector<double>>HV=h(v(ma));
	std::vector<std::vector<double>>H=h(ma);
	std::vector<std::vector<double>>V=v(ma);
	for(int i=0;i<nova.size();i++){
		for(int j=0;j<nova[0].size();j++){
			if(i<ma.size() && j<ma[0].size())
			nova[i][j]=HV[i%ma.size()][j%ma[0].size()];
			else if(i<ma.size() && j<2*ma[0].size())
			nova[i][j]=V[i%ma.size()][j%ma[0].size()];
			else if(i<ma.size() && j<3*ma[0].size())
			nova[i][j]=HV[i%ma.size()][j%ma[0].size()];
			else if(i<2*ma.size() && j<ma[0].size())
			nova[i][j]=H[i%ma.size()][j%ma[0].size()];
			else if(i<2*ma.size() && j<2*ma[0].size())
			nova[i][j]=ma[i%ma.size()][j%ma[0].size()];
			else if(i<2*ma.size() && j<3*ma[0].size())
			nova[i][j]=H[i%ma.size()][j%ma[0].size()];
			else if(i<3*ma.size() && j<ma[0].size())
			nova[i][j]=HV[i%ma.size()][j%ma[0].size()];
			else if(i<3*ma.size() && j<2*ma[0].size())
			nova[i][j]=V[i%ma.size()][j%ma[0].size()];
			else
			nova[i][j]=HV[i%ma.size()][j%ma[0].size()];
		}
	}
	return nova;
}
int main ()
{
	try{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>>ma(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	std::cin>>ma[i][j];
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	IspisMatrice(OgledaloMatrica(ma));
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}