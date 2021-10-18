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

typedef std::vector<std::vector<double>> matrica;

matrica kreiraj_matricu(int broj_redova,int broj_kolona)
{
	return matrica (broj_redova,std::vector<double> (broj_kolona));
}


matrica unos_matrice(int broj_redova,int broj_kolona)
{
	auto m(kreiraj_matricu(broj_redova,broj_kolona));
	for(int i=0;i<m.size();i++)
	for(int j=0;j<m[i].size();j++)
	std::cin>>m[i][j];
	return m;
}


void ispis_matice(matrica m)
{
	for(auto red: m)
	{
		for(double  x: red )
		std::cout<<std::setw(4)<<x;
		std::cout<<"\n";
	}
}


bool grbava_matrica(matrica m)
{
	
	for(int i=0;i<m.size();i++)
	{
		if(m[0].size()!=m[i].size())
		return true;
	}
	
	
	return false;
	
}

matrica kreiraj_grbavu(int broj_redova)
{
	matrica vrati(broj_redova);
	for(int i=0;i<broj_redova;i++)
	vrati[i].resize(i+1);
	return vrati;
}

matrica unos_grbave_matrice(matrica m)
{

	for(int i=0;i<m.size();i++)
	for(int j=0;j<m[i].size();j++)
	std::cin>>m[i][j];
	return m;
	
	
}

matrica h (matrica m)
{
	double temp;
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[0].size();j++)
		{
			if(m[0].size()%2==0)
			if(j<m[0].size()/2)
			{
				temp=m[i][j];
				m[i][j]=m[i][m[i].size()-j-1];
				m[i][m[i].size()-j-1]=temp;
			}
			
			if(m[0].size()%2!=0)
			if(j<=m[0].size()/2)
			{
				temp=m[i][j];
				m[i][j]=m[i][m[i].size()-j-1];
				m[i][m[i].size()-j-1]=temp;
			}
		}
	}
	return m;
}




matrica umetni_h(matrica unos,matrica vrati,int red,int kolona)
{
	auto hm=h(unos);
	for(int i=red;i<red+unos.size();i++)
		for(int j=kolona;j<kolona+unos[0].size();j++)
			vrati[i][j]=hm[i-red][j-kolona];
	return vrati;
}



matrica v(matrica m)
{
	std::vector<double> temp(m[0].size()) ;
	for(int i=0;i<m.size();i++)
	{
		if(m.size()%2==0)
		{
			if(i<m.size()/2)
			{
				temp=m[i];
				m[i]=m[m.size()-1-i];
				m[m.size()-1-i]=temp;
			}
		}
		
		if(m.size()%2!=0)
		{
			if(i<=m.size()/2)
			{
				temp=m[i];
				m[i]=m[m.size()-1-i];
				m[m.size()-1-i]=temp;
			}
		}
	}
	return m;
}

matrica umetni_v(matrica unos,matrica vrati,int red,int kolona)
{
	auto temp=v(unos);
	for(int i=red;i<red+unos.size();i++)
	for(int j=kolona;j<kolona+unos[0].size();j++)
	{
		vrati[i][j]=temp[i-red][j-kolona];
		
	}
	return vrati;
}


matrica hv(matrica m)
{
	m=v(m);
	m=h(m);
	return m;

}

matrica umetni_hv(matrica unos,matrica vrati,int red,int kolona)
{
	auto temp(hv(unos));
	for(int i=red;i<red+unos.size();i++)
	{
		for(int j=kolona;j<kolona+unos[0].size();j++)
		{
			vrati[i][j]=temp[i-red][j-kolona];
		}
	}
	return vrati;
}



matrica umetni_pocetnu(matrica unos,matrica vrati,int red,int kolona)
{
	for(int i=red;i<red+unos.size();i++)
	for(int j=kolona;j<kolona+unos[0].size();j++)
	vrati[i][j]=unos[i-red][j-kolona];
	return vrati;
}


matrica OgledaloMatrica(matrica m)
{   
	if(grbava_matrica(m)==true)
	{
		throw std::domain_error("Matrica nije korektna");
	}
	
	int broj_redova;
	int broj_kolina;
	if(m.size()==0)
	{broj_redova=0;
	broj_kolina=0;
	}
	if(m.size()!=0)
	{
		broj_redova=m.size();
		broj_kolina=m[0].size();
	}
	matrica vrati(kreiraj_matricu(broj_redova*3,broj_kolina*3));
	
	for(int i=0;i<vrati.size();i++)
	for(int j=0;j<vrati[0].size();j++)
	{
		if(i==0)
		{
			if(j==0)
			vrati=umetni_hv(m,vrati,i,j);
			if(j==m[0].size())
			vrati=umetni_v(m,vrati,i,j);
			if(j==m[0].size()*2)
			vrati=umetni_hv(m,vrati,i,j);
		}
		if(i==m.size())
		{
			if(j==0)
			vrati=umetni_h(m,vrati,i,j);
			if(j==m[0].size())
			vrati=umetni_pocetnu(m,vrati,i,j);
			if(j==m[0].size()*2)
			{
				vrati=umetni_h(m,vrati,i,j);
			}
			
		}
		if(i==m.size()*2)
		{
			if(j==0)
			vrati=umetni_hv(m,vrati,i,j);
			if(j==m[0].size())
			vrati=umetni_v(m,vrati,i,j);
			if(j==m[0].size()*2)
			{
				vrati=umetni_hv(m,vrati,i,j);
			}
		}
		
	}
	return vrati;
}




int main ()
{
	int a,b;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>a>>b;
	if(a<0 || b<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	auto m=unos_matrice(a,b);
	try{
	auto ispis=OgledaloMatrica(m);
	std::cout<<"\nRezultantna matrica:\n";
	ispis_matice(ispis);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}