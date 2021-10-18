/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica NapraviMatricu (int redovi, int kolone)
{
	return Matrica(redovi, std::vector<double>(kolone));
}

Matrica Unesi (int redovi, int kolone)
{
	auto mat(NapraviMatricu(redovi, kolone));
	for(int i = 0; i < redovi; i++)
		for(int j = 0; j < kolone; j++)
			std::cin>>mat[i][j];
	return mat;
}

Matrica Horiz (Matrica mat)
{
	Matrica hmat (NapraviMatricu(mat.size(), mat[0].size()));
	for(int i = 0; i < mat.size(); i++)
		for(int j = 0; j < mat[i].size(); j++)
			hmat[i][j] = mat[i][mat[i].size()-1-j];
	return hmat;
}

Matrica Verti (Matrica mat)
{
	Matrica vmat (NapraviMatricu(mat.size(), mat[0].size()));
	for(int i = 0; i < mat.size(); i++)
		for(int j = 0; j < mat[i].size(); j++)
			vmat[i][j] = mat[mat.size()-1-i][j];
	return vmat;
	
}

Matrica HorizVerti (Matrica mat)
{
	Matrica hvmat (NapraviMatricu(mat.size(), mat[0].size()));
	hvmat = Horiz(mat);
	hvmat = Verti(hvmat);
	return hvmat;
}

Matrica Expanzija (int m, int n)
{
	m *= 3;
	n *= 3;
	auto pom (NapraviMatricu(m, n));
	return pom;
}

Matrica OgledaloMatrica (Matrica mat)
{
	std::vector<int>v;
	for(int i = 0; i < mat.size(); i++)
		v.push_back(mat[i].size());
		
	for(int i = 0; i < v.size(); i++)
		for(int j = 0; j < v.size(); j++)
			if(i != j && v[i] != v[j])
				throw std::domain_error ("Matrica nije korektna");
	
				
	if(mat.size() == 0)
		return mat;
		
	auto mat1(NapraviMatricu(mat.size(), mat[0].size()));
	auto mat2(NapraviMatricu(mat.size(), mat[0].size()));
	auto mat3(NapraviMatricu(mat.size(), mat[0].size()));
	auto mat4(NapraviMatricu(mat.size(), mat[0].size()));
	mat1 = HorizVerti(mat);
	mat2 = Horiz(mat);
	mat3 = Verti(mat);
	mat4 = mat;
	int m1 = mat1.size();
	int n1 = mat1[0].size();
	mat = Expanzija(mat.size(), mat[0].size());
	int m = mat.size();
	int n = mat[0].size();
	for(int i = 0; i < m; i += m1)
	{
		int b = i;
		for(int j = 0; j < n; j += n1)
		{
			int a = j;
			if((j >= 0 && j < n1 && i >= 0 && i < m1) || (j >= 0 && j < n1 && i < m && i >= m-m1) || (j < n && j >= n-n1 && i >= 0 && i < m1) || (j < n && j >= n-n1 && i >= m-m1 && i < m))
			{
				for(int k = 0; k < mat1.size(); k++)
				{
					for(int p = 0; p < mat1[0].size(); p++)
					{
						mat[i][j] = mat1[k][p];
						j++;
					}
					i++;
					j = a;
				}
			}
			if (i >= mat.size()/3 && i < mat.size()-mat1.size() && ((j >= 0 && j < mat[0].size()/3) || (j < mat[0].size() && j >= mat[0].size()-mat1[0].size())))
			{
				for(int k = 0; k < mat1.size(); k++)
				{
					for(int p = 0; p < mat1[0].size(); p++)
					{
						mat[i][j] = mat2[k][p];
						j++;
					}
				i++;
				j = a;
				}
			}
			if (j >= mat[0].size()/3 && j < mat[0].size()-mat1[0].size() && ((i >= 0 && i < mat.size()/3) || (i >= mat.size()-mat1.size() && i < mat.size())))
			{
				for(int k = 0; k < mat1.size(); k++)
				{
					for(int p = 0; p < mat1[0].size(); p++)
					{
						mat[i][j] = mat3[k][p];
						j++;
					}
				i++;
				j = a;
				}
			}
			if(i >= mat1.size() && i < mat.size()-mat1.size() && j >= mat1[0].size() && j < mat[0].size()-mat1[0].size())
			{
				for(int k = 0; k < mat1.size(); k++)
				{
					for(int p = 0; p < mat1[0].size(); p++)
					{
						mat[i][j] = mat4[k][p];
						j++;
					}
				i++;
				j = a;
				}
			}
			i = b;
		}
	//i = b;
	}
	
	
			
	return mat;
}




int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if(m < 0 || n < 0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	auto mat = Unesi(m ,n);
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: "<<std::endl;
	/*for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			mat[i][j] = m[i][4-1-j];
		}
	}*/
	//std::cout<<m.size();
	try 
	{
		mat = OgledaloMatrica(mat);
	}
	catch(const char poruka[])
	{
		std::cout<<poruka;
	}
	//mat = OgledaloMatrica(mat);
	for(int i = 0; i < mat.size(); i++)
	{
		for(int j = 0; j < mat[i].size(); j++)
		{
			std::cout<<std::setw(4)<<mat[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}