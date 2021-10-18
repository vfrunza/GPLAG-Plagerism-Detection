/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;
typedef std::vector<std::vector<double>> Matrica;

Matrica Vertikalno(Matrica M)
{
    Matrica M1;
    M1.resize(M.size());
    for(int i=0; i<M.size(); i++) M1[i].resize(M[i].size());
    for(int i=0; i<M.size(); i++)
    {   
        int pomocna=M[0].size()-1;
        for (int j=0; j<M[i].size(); j++)
        {
        M1[i][j]=M[i][pomocna];
        pomocna--;
        }
    }
    return M1;   
}

Matrica Horizontalno(Matrica M)
{
   Matrica M1;
   M1.resize(M.size());
   for(int i=0; i<M.size(); i++) M1[i].resize(M[i].size());
   int pomocna=M.size()-1;
   for(int i=0; i<M.size(); i++)
   {
       for(int j=0; j<M[i].size(); j++)
       {
           M1[i][j]=M[pomocna][j];
       }
       pomocna--;
   }
   return M1;
}

Matrica HorizontalnoVertikalno(Matrica M)
{
    Matrica M1;
    Matrica M2;
    
    M1.resize(M.size());
    for(int i=0; i<M.size(); i++) M1[i].resize(M[i].size());
    M2.resize(M.size());
    for(int i=0; i<M.size(); i++) M2[i].resize(M[i].size());
    
    M1=Vertikalno(M);
    M2=Horizontalno(M1);
    return M2;
}

Matrica OgledaloMatrica(Matrica M)
{
    for(int i=0; i<M.size(); i++)
    {
        if(M[i].size()!=M[0].size()) throw std::domain_error ("Matrica nije korektna!");
    }
    
    
    Matrica Vertikalna=Vertikalno(M);
    Matrica Horizontalna=Horizontalno(M);
    Matrica Vertikalna_Horizontalna=HorizontalnoVertikalno(M);
    Matrica Nova;
    
    for(int i=0; i<M.size(); i++)
    {
        std::vector<double> M1;
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(Vertikalna_Horizontalna[i][j]);
        }
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(Horizontalna[i][j]);
        }
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(Vertikalna_Horizontalna[i][j]);
        }
        Nova.push_back(M1);
    }
    
    for(int i=0; i<M.size(); i++)
    {
        std::vector<double> M1;
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(Vertikalna[i][j]);
        }
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(M[i][j]);
        }
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(Vertikalna[i][j]);
        }
        Nova.push_back(M1);
    }
    
    for(int i=0; i<M.size(); i++)
    {
        std::vector<double> M1;
        for(int j=0; j<M[i].size(); j++)
        {
            M1.push_back(Vertikalna_Horizontalna[i][j]);
        }
        for(int j=0; j<M[i].size(); j++)
        {
            M1.push_back(Horizontalna[i][j]);
        }
        for(int j=0; j<M[i].size(); j++) 
        {
            M1.push_back(Vertikalna_Horizontalna[i][j]);
        }
        Nova.push_back(M1);
    }
    
return Nova;
}    
    

int main()
{
    try{
        
        Matrica M;
        int m, n;
        
        std::cout<<"Unesite dimenzije matrice (m n): ";
        std::cin>>m>>n;
        
 	    if(m<0 || n<0) 
 	    {
 	        std::cout<<"Dimenzije matrice moraju biti nenegativne!"; 
 	        return 0;
 	    }
        std::cout<<"Unesite elemente matrice: ";
        
        M.resize(m);
        for(int i=0; i<M.size(); i++) 
        {
            M[i].resize(n);
        }
        for(int i=0; i<M.size(); i++)
        for(int j=0; j<M[i].size(); j++) std::cin>>M[i][j];
        std::cout<<std::endl;
        std::cout<<"Rezultantna matrica: ";
        std::cout<<std::endl;
        M=OgledaloMatrica(M);
        
        for(int i=0; i<M.size(); i++)
        {
            for(int j=0; j<M[i].size(); j++)
            {
                std::cout<<setw(4)<<right<<M[i][j];
            }
            std::cout<<std::endl;
        }
    }catch(std::domain_error) { std::cout<<"Matrica nije korektna"; }
    
    return 0;
}
