#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

bool Grbava(Matrica M){
	if(M.size()==0)
		return false;
	std::vector<double> v(M[M.size()-1]);
	for(int i(0);i<M.size()-1;i++){
		if(M[i].size()!=M[i+1].size()||M[i].size()!=v.size())
			return true;
	}
	return false;
}

Matrica ObrniKolone(Matrica M){
	Matrica hM;
	if(M[0].size()==1||M[0].size()==0)
		return M;
	hM.resize(M.size());
	for(int i(0);i<hM.size();i++)
		hM[i].resize(M[i].size());
	for(int i(0);i<hM.size();i++){
		for(int j(0);j<hM[i].size();j++){
			hM[i][j]=M[i][hM[i].size()-j-1];
		}
	}
	return hM;
}

Matrica ObrniRedove(Matrica M){
	if(M.size()==1||M.size()==0)
		return M;
	Matrica vM;
	vM.resize(M.size());
	for(int i(0);i<M.size();i++)
		vM[i].resize(M[i].size());
	for(int i(0);i<vM.size();i++){
		for(int j(0);j<vM[i].size();j++){
			vM[i][j]=M[vM.size()-i-1][j];
		}
	}
	return vM;
}

Matrica OgledaloMatrica(Matrica M){
	Matrica O;
	if(Grbava(M))
		throw std::domain_error("Matrica nije korektna");
	if(M.size()==0)
		return M;
		else if(M.size()==0)
			return M;
		else if(M[0].size()==0){
			M.resize(3*M.size());
			return M;
		}

	O.resize(3*M.size());
	Matrica hM(ObrniKolone(M)),vM(ObrniRedove(M)),kM(ObrniKolone(ObrniRedove(M)));
	for(int i(0);i<O.size();i++){
		if(i<M.size())
			O[i]=kM[i];
			else if(i>=M.size()&&i<2*M.size())
			O[i]=hM[i-M.size()];
			else
			O[i]=kM[i-2*M.size()];
	}
	for(int i(0);i<O.size();i++){
			for(int j(0);j<M[0].size();j++){
			if(i<M.size())
			O[i].push_back(vM[i][j]);
			else if(i>=M.size()&&i<2*M.size())
			O[i].push_back(M[i-M.size()][j]);
			else
			O[i].push_back(vM[i-2*M.size()][j]);
			}
	}
		for(int i(0);i<O.size();i++){
			for(int j(0);j<M[0].size();j++){
			if(i<M.size())
			O[i].push_back(kM[i][j]);
			else if(i>=M.size()&&i<2*M.size())
			O[i].push_back(hM[i-M.size()][j]);
			else
			O[i].push_back(kM[i-2*M.size()][j]);
			}
		}
return O;
}

int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(n<0||m<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	try{
	std::cout<<"Unesite elemente matrice: "<<std::endl;;
	Matrica M;
	M.resize(m);
	for(int i(0);i<M.size();i++)
		M[i].resize(n);
	for(int i(0);i<M.size();i++){
		for(int j(0);j<M[i].size();j++){
			std::cin>>M[i][j];
		}
	}
	Matrica O(OgledaloMatrica(M));
	std::cout<<"Rezultantna matrica: "<<std::endl;
	if(m==0&&n==0)
		return 0;
	else{
	for(int i(0);i<O.size();i++){
		for(int j(0);j<O[i].size();j++){
			std::cout<<std::setw(4)<<O[i][j];
		}
		std::cout<<std::endl;
	}
}
}
catch(std::domain_error Greska){
	std::cout<<"Matrica nije korektna.";
}
	return 0;
}