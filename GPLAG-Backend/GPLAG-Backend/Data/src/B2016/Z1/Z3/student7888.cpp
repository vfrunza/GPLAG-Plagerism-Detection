#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

   Matrica RastuciPodnizovi( std::vector<double> V )    {
       Matrica M;
       int brojac = 0;
       int k = 1 , p = 0;
       int x;
       const double epsilon(1e-10);
       
       for ( int  i = 0 ; i < V.size(); i++ )    {
                brojac = 0;
                x = i;
            
        while ( i < V.size()-1 )       {     
                if ((V[i]-V[i+1]) > epsilon ) break;
                 i++;
                 brojac++;


            }
            
             if ( brojac > 0 )  {
                 M.resize(k);
                 M[k-1].resize(brojac+1);
                        
                        p = 0;
                        
                 for ( int j = x ; j <= i ; j++ )    {
                     M[k-1][p] =  V[j];  
                     p++;
                 }
              
                k++;   
             }   
           
       }
       
   
    return M;
   }
   
     Matrica OpadajuciPodnizovi( std::vector<double> V )    {
       Matrica M;
       int brojac = 0;
       int k = 1 , p = 0;
       int x;
      const double epsilon(1e-10);

       
       for ( int  i = 0 ; i < V.size(); i++ )    {
                brojac = 0;
                x = i;
        while (  i <  V.size()-1)       {    
            if ( (V[i+1]-V[i]) > epsilon ) break;
                brojac++;
                i++;
            }
            
             if ( brojac > 0 )  {
                 M.resize(k);
                 M[k-1].resize(brojac+1);
                        
                        p = 0;
                        
                 for ( int j = x ; j <= i ; j++ )    {
                     M[k-1][p] =  V[j];  
                     p++;
                 }
              
                k++;   
             }   
           
       }
       
   
    return M;
   }
   
   

int main ()
{
   int a;
   std::cout<<"Unesite broj elemenata vektora: ";
   std::cin>>a;
   std::vector<double>V;
	std::cout<<"Unesite elemente vektora: ";
	for ( int i = 0 ; i < a ; i++ ) {
	    int b;
	    std::cin>>b;
	    V.push_back(b);
	}
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica M;
	M = RastuciPodnizovi(V);
	for ( int i = 0 ; i < M.size() ; i++ )  {
	    
	    for ( int j = 0 ; j < M[i].size() ; j++ )   {
	        
	        std::cout<<M[i][j]<<" ";
	    }
	        std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;

	Matrica  M2;
	M2 = OpadajuciPodnizovi(V);
	for ( int i = 0 ; i < M2.size() ; i++ )  {
	    
	    for ( int j = 0 ; j < M2[i].size() ; j++ )   {
	        
	        std::cout<<M2[i][j]<<" ";
	    }
	        std::cout<<std::endl;
	}
	
	return 0;
}