#include <iostream>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona) {
 return Matrica(br_redova, std::vector<double>(br_kolona));}

Matrica UnesiMatricu(int m, int n)
{
	if(m<0||n<0)  throw std::range_error("Dimenzije matrice moraju biti nenegativne!");
	auto B(KreirajMatricu(m, n));
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++)
			std::cin>>B[i][j];
		
	}
	return B;
}

int BrRedova(Matrica M)
{
	return 3*M.size();
}

int BrKolona(Matrica M)
{
	return 3*M[0].size();
}

Matrica OgledaloMatrica(Matrica M)
{
	Matrica A;
	std::vector<double>a;
	int q=BrRedova(M);
	int y=BrKolona(M);
	for(int i=0; i<q; i++)
	{
		int k(1), l(0);
		for (int j=0; j<y; j++)
		{
			if(i==0&&j<y/3){
			a.push_back(M[M.size()-1][M[0].size()-k]);
			k++;}
			if(a.size()==M.size()){
			A.push_back(a);
			a.clear();}
			if(i==0&&j>=y/3&&j<(2*y)/3){
				a.push_back(M[M.size()-1][M[0].size()+l]);
				l++;
			}
				if(a.size()==M.size()){
			A.push_back(a);
			a.clear();}
			if(i==0&&j>=(2*y)/3&&j<y){
			a.push_back(M[M.size()-1][M[0].size()-k]);
			k++;
			}
				if(a.size()==M.size()){
			A.push_back(a);
			a.clear();}
			if(i>0&&i<=q/3&&j<y/3){
			a.push_back(M[0][M.size()-l]);
			l++;
			}
				if(a.size()==M.size()){
			A.push_back(a);
			a.clear();}
			if(i>0&&i<=q/3&&j>=y/3&&j<(2*y)/3){
			a.push_back(M[0][l]);
			l++;
			}
				if(a.size()==M.size()){
			A.push_back(a);
			a.clear();}
			if(i>0&&i<=q/3&&j>=(2*y)/3&&j<y){
			a.push_back(M[0][M.size()-l]);
			l++;
			}
				if(a.size()==M.size()){
			A.push_back(a);
			a.clear();}
			if(i>q/3&&i<=(2*q)/3&&j<y/3){
				a.push_back(M[M.size()-1][M[0].size()-k]);
				k++;
			}
				if(a.size()==M.size()){
					A.push_back(a);
					a.clear();}
			if(i>(2*q)/3&&i<q&&j<y/3)
			{
				a.push_back(M[M.size()-1][M[0].size()-k]);
				k++;
			}
				if(a.size()==M.size()){
					A.push_back(a);
					a.clear();}
			if(k>=(q/3)) k=1;
			if(l>=(y/3)) l=0;
		}
	}
	return A;
}

int main ()
{
	try
	{
	    std::cout<<"Unesite dimenzije matrice (m, n): ";
	    int m, n;
	    std::cin>>m>>n;
	    std::cout<<"Unesite elemente matrice: ";
	   	Matrica M (UnesiMatricu(m, n));
	   	std::cout<<std::endl<<"Rezultantna matrica: ";
	   	Matrica MirrorMaster=OgledaloMatrica(M);
	   	for (int i=0; i<BrRedova(M); i++){
	   		for(int j=0; j<BrKolona(M); j++)
	   		std::cout<<MirrorMaster[i][j];
	   	std::cout<<std::endl;}}
	catch (std::range_error izuzetak)
	{
		std::cout<<izuzetak.what();
	}
	return 0;
}