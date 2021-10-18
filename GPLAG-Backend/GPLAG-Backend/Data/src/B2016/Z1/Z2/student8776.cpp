#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>


std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> M)
{
	
	for (int i{};i<M.size();i++)
		{
			if (M[0].size() != M[i].size())
				throw std::domain_error ("Matrica nije korektna");
		}
		
	if (M.size() == 0)
		return std::vector<std::vector<double>> (0, std::vector<double> (0));
		
	if (M.size() == 0 && M[0].size() == 0)
		{
			std::vector<std::vector<double>> prazan;
			return prazan;
		}
		
	std::vector<std::vector<double>> h;
	h.resize(M.size());
	
	for (int i{};i<h.size();i++)
		h[i].resize(M[0].size());
	
	std::vector<std::vector<double>> v;
	v.resize(M.size());
	
	for (int i{};i<v.size();i++)
		v[i].resize(M[0].size());
		
	std::vector<std::vector<double>> hv;
	hv.resize(M.size());
	
	for (int i{};i<hv.size();i++)
		hv[i].resize(M[0].size());
	
	for (int i{};i<M.size();i++)
		{
			int k = M[i].size()-1;
			for (int j{};j<M[i].size();j++)
				h[i][j] = M[i][k--];
		}
	
	int k = M.size()-1;	
	for (int i{};i<M.size();i++)
		{
			
			for (int j{};j<M[i].size();j++)
				v[i][j] = M[k][j];
				
			k--;
		}
		
	k = M.size()-1;
	for (int i{};i<M.size();i++)
		{
			int l = M[i].size()-1;
			for (int j{};j<M[i].size();j++)
				hv[i][j] = M[k][l--];
				
			k--;
		}
	
	std::vector<std::vector<double>> rezultat (3*M.size(), std::vector<double> (3*M[0].size()));
	
	
		
	for (int i{};i<hv.size();i++)												///1. element
		{
			for (int j{};j<hv[i].size();j++)
				rezultat[i][j] = hv[i][j];
				
		}
		
	for (int i{};i<v.size();i++)												///2. element
		{
			int l = v[i].size();
			for (int j{};j<v[i].size();j++)
				rezultat[i][l++] = v[i][j];
		}
		
	for (int i{};i<hv.size();i++)												///3. element
		{
			int l = v[i].size();
			l*=2;
			for (int j{};j<hv[i].size();j++)
				rezultat[i][l++] = hv[i][j];
		}
	
	k = M.size();
	for (int i{};i<h.size();i++)												///4. element
		{
			for (int j{};j<h[i].size();j++)
				rezultat[k][j] = h[i][j];
				
			k++;
		}
		
	k = M.size();
	for (int i{};i<M.size();i++)												///5. element
		{
			int l = M[i].size();
			for (int j{};j<M[i].size();j++)
				rezultat[k][l++] = M[i][j];
				
			k++;
		}
		
		k = M.size();
	for (int i{};i<M.size();i++)												///6. element
		{
			int l = M[i].size();
			l*=2;
			for (int j{};j<M[i].size();j++)
				rezultat[k][l++] = h[i][j];
				
			k++;
		}
		
		k = M.size();
		k*=2;
	for (int i{};i<M.size();i++)												///7. element
		{
			for (int j{};j<M[i].size();j++)
				rezultat[k][j] = hv[i][j];
				
			k++;
		}
		
	k = M.size();
	k*=2;
	for (int i{};i<M.size();i++)												///8. element
		{
			int l = M[i].size();
			for (int j{};j<M[i].size();j++)
				rezultat[k][l++] = v[i][j];
				
			k++;
		}
		
	k = M.size();
	k*=2;
	for (int i{};i<M.size();i++)												///9. element
		{
			int l = M[i].size();
			l*=2;
			for (int j{};j<M[i].size();j++)
				rezultat[k][l++] = hv[i][j];
				
			k++;
		}
	
	
	return rezultat;
}


int main ()
{
	try
	{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		std::cin>>m>>n;
		std::cin.ignore(10000, '\n');
		
		if (m<0 || n<0)
			{
				std::cout<<"Dimenzije matrice moraju biti nenegativne!";
				return 0;
			}
		
		std::cout<<"Unesite elemente matrice: ";
		std::vector<std::vector<double>> v (m, std::vector<double> (n));
		for(int i{};i<m;i++)
			{
				for(int j{};j<n;j++)
					{
						double x;
						std::cin>>x;
						v[i][j] = x;
					}
			}
			
		auto rezultat = OgledaloMatrica(v);
		
		std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		for (int i{};i<rezultat.size();i++)
			{
				for (int j{};j<rezultat[i].size();j++)
					std::cout<<std::right<<std::setw(4)<<rezultat[i][j];
					
				std::cout<<std::endl;
			}
		
	}
	catch (std::domain_error e)
	{
		std::cout<<e.what();
	}
	
	
	return 0;
}