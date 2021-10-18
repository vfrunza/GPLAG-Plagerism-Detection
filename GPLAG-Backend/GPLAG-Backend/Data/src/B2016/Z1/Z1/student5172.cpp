/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <algorithm>



bool ProvjeriOpake( std::vector<int> v )
     {
	    for(auto i = 0; i < int( v.size() ); i++)
		     {
			         auto brojac = 0;
			         for( auto j = 0; j < int( v.size() ); j++)
			                  if( v[i] == v[j] )
			                           brojac++;
			                  if( brojac % 2 != 0 )
			                      return false;
		     }                     
	    return true;                   
	}


bool ProvjeriOdvratne( std::vector<int> v )
   {
    	for(auto i = 0; i < int( v.size() ); i++)
	    	{
		      	auto brojac = 0;
		        for( auto j = 0; j < int( v.size() ); j++)
			           if( v[i] == v[j] )
			               brojac++;
			           if( brojac % 2 == 0 )
			              return false;
	    	}
			return true;	
	}

std::vector<int> PretvoriUTernarni ( int broj )
    {
          	if( broj < 0 )
          	      broj *= -1;
          	std::vector<int> ter;
          	while( broj != 0 )
                   {
                   	         ter.push_back( broj % 3);
                   	         broj /= 3;
                   }
            std::reverse( ter.begin(), ter.end() );
            return ter;
    }

bool PostojiLi( std::vector<int> v, int broj )
    {
    	for( auto elem : v )
    	         if( elem == broj )
    	                  return true;
              return false;
    }

std::vector<int> DajOpake( std::vector<int> opaki )
    {
    	std::vector<int> op;
    	for( auto i = 0; i < int( opaki.size() ); i++)
    	      if( ProvjeriOpake( PretvoriUTernarni( opaki[i])) && !PostojiLi( op, opaki[i] ) )
    	                  op.push_back( opaki[i] );
    	     return op;             
    }


std::vector<int> DajOdvratni( std::vector<int> gadni )
    {
    	std::vector<int> gd;
    	for( auto i = 0; i < int( gadni.size() ); i++)
    	         if( ProvjeriOdvratne( PretvoriUTernarni( gadni[i] ) ) && !PostojiLi( gd, gadni[i] ) )
    	               gd.push_back( gadni[i] );
    	     return gd;          
    }

std::vector<int> IzdvojiGadne( std::vector<int> brojevi, bool opaki )
    {
    	if( opaki )
    	        return DajOpake( brojevi );
    	return DajOdvratni( brojevi );
    }



int main()
{
	
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	while(true){
		int br;
		std::cin >> br;
		if(br == 0)
			break;
		v.push_back(br);
	}
	std::cout << "Opaki: ";
	for(auto i : IzdvojiGadne(v, true))
		std::cout << i << " ";
	std::cout << "\nOdvratni: ";
	
	for(auto i : IzdvojiGadne(v, false))
		std::cout << i << " ";
	

	
	return 0;
}