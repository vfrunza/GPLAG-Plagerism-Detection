#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>>Matrica;

Matrica HorizontalnaMatrica( Matrica M ) {
	Matrica M1 ( M.size() );
	for ( int i = 0 ; i < M.size(); i++) M1[i].resize(M[i].size());
		for ( int i = 0 ; i < M1.size(); i++ ) {
				int k = M1[i].size()-1;
			
			for ( int j = 0 ; j < M1[i].size() ; j++ )	{
			
				M1[i][j] = M[i][k];
				k--;
		}
	}
return M1;	
}

Matrica	VertikalnaMatrica( Matrica M ) {
	Matrica M1 ( M.size() );
	for ( int i = 0 ; i < M.size(); i++) M1[i].resize(M[i].size());
			int k = M1.size()-1;
		for ( int i = 0 ; i < M1.size(); i++ ) {
		
			for ( int j = 0 ; j < M1[i].size() ; j++ )	{
					
					M1[i][j] = M[k][j];
			}
			k--;
	}
	return M1;	
}

Matrica	HVMatrica ( Matrica M ) {
	Matrica M1 ( M.size() );
	for ( int i = 0 ; i < M.size(); i++) M1[i].resize(M[i].size());
			int k = M1.size()-1;
		for ( int i = 0 ; i < M1.size(); i++ ) {
			int z = M1[i].size()-1;
		for ( int j = 0 ; j < M1[i].size() ; j++ )	{
			M1[i][j] = M[k][z];
			z--;
		}
			k--;
	}
	return M1;	
}

Matrica OgledaloMatrica ( Matrica M )	{
	
	int k = 0, z = 0;
	Matrica MH;
	Matrica MV;
	Matrica MHV;
	Matrica M1 (M.size()*3);
	int brojac = 0;
	for ( int i = 0; i < M1.size(); i++ ) M1[i].resize(M[0].size()*3);
	
	for ( int i = 0; i < M.size (); i++ )	{
		
		if ( M[i].size() != M[0].size() ) brojac++;
	}
		if ( brojac > 0 )	throw std::domain_error("Matrica nije korektna");


	MH = HorizontalnaMatrica(M);
	MV = VertikalnaMatrica(M);
	MHV = HVMatrica(M);
	
	
	for ( int i = 0 ; i < M1.size()/3 ; i++ )	{
		for ( int j = 0; j < M1[i].size()/3 ; j++ ) M1[i][j] = MHV[i][j];
	}
	
				 k = 0;	
	for ( int i = 0 ; i < M1.size()/3 ; i++ )	{
				 z = 0;
		for ( int j = M1[i].size()/3 ; j < 2*M1[i].size()/3 ; j++ )	{
				M1[i][j] = MV[k][z];
		
				z++;
		}
				k++;
	}
	
	
				 k = 0;	
	for ( int i = 0 ; i < M1.size()/3 ; i++ )	{
				 z = 0;
		for ( int j = 2*M1[i].size()/3 ; j < M1[i].size() ; j++ )	{
				M1[i][j] = MHV[k][z];
		
				z++;
		}
				k++;
	}
		
				
				 k = 0;	
	for ( int i = M1.size()/3 ; i < 2*M1.size()/3 ; i++ )	{
				 z = 0;
		for ( int j = 0 ; j < M1[i].size()/3 ; j++ )	{
				M1[i][j] = MH[k][z];
		
				z++;
		}
				k++;
	}	
	
	
				 k = 0;	
	for ( int i = M1.size()/3 ; i < 2*M1.size()/3 ; i++ )	{
				 z = 0;
		for ( int j = M1[i].size()/3 ; j < 2*M1[i].size()/3 ; j++ )	{
				M1[i][j] = M[k][z];
		
				z++;
		}
				k++;
	}
	
	
				 k = 0;	
	for ( int i = M1.size()/3 ; i < 2*M1.size()/3 ; i++ )	{
				 z = 0;
		for ( int j = 2*M1[i].size()/3 ; j < M1[i].size() ; j++ )	{
				M1[i][j] = MH[k][z];
		
				z++;
		}
				k++;
	}
	
	
				 k = 0;	
	for ( int i = 2*M1.size()/3 ; i < M1.size() ; i++ )	{
				 z = 0;
		for ( int j = 0 ; j < M1[i].size()/3 ; j++ )	{
				M1[i][j] = MHV[k][z];
		
				z++;
		}
				k++;
	}
	
				 k = 0;	
	for ( int i = 2*M1.size()/3 ; i < M1.size() ; i++ )	{
				 z = 0;
		for ( int j = M1[i].size()/3 ; j < 2*M1[i].size()/3 ; j++ )	{
				M1[i][j] = MV[k][z];
		
				z++;
		}
				k++;
	}
	
	
		
				 k = 0;	
	for ( int i = 2*M1.size()/3 ; i < M1.size() ; i++ )	{
				 z = 0;
		for ( int j = 2*M1[i].size()/3 ; j < M1[i].size() ; j++ )	{
				M1[i][j] = MHV[k][z];
		
				z++;
		}
				k++;
	}
	
	return M1;
	
}

int main ()
{
	try {
	
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if ( m < 0 || n < 0 ) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica M(m,std::vector<double>(n));
	Matrica m2;
	
	

	std::cout<<"Unesite elemente matrice:"<<std::endl;
	for ( int i = 0 ; i < m ; i++ )	{
		
		for (int j = 0 ; j < n ; j++ ) std::cin>>M[i][j];
	}
	
	m2 = OgledaloMatrica(M);
	
	std::cout<<"Rezultantna matrica:"<<std::endl;
	for ( auto x : m2 )	{
		for ( auto y : x )	{
			std::cout<<std::setw(4)<<y;
		}
	
		std::cout<<std::endl;
	}
	
	}
	
	catch (std::domain_error izuzetak)	{
		std::cout<<izuzetak.what()<< std::endl;
	}
	
	return 0;
}