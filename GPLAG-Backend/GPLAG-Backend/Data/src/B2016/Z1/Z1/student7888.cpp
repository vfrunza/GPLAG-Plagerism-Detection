#include <iostream>
#include <vector>

std::vector<int>IzdvojiGadne( std::vector<int>V1 , bool a )	{
		std::vector<int>V2;
		 int b,brojac = 0,pomocni,brojilo = 0;
		
			if ( a == true )	{
					for (int i = 0 ; i < V1.size() ; i++ )	{
							brojilo = 0;

						for ( int j = i-1 ; j >= 0 ; j-- )	{
							if ( V1[j] == V1[i] ) brojilo++;
						}
						
							if ( brojilo > 0 ) continue;
						
							b = V1[i];

						while ( (V1[i]) != 0 )		{
							brojac = 0;
							pomocni = (b);
						
							while ( pomocni != 0 )	{
								if ((V1[i]) % 3 == pomocni % 3 )	brojac++;
								pomocni/=3;
							}
							
							if ( brojac % 2 != 0 ) 	break;
							
					    	V1[i]=(V1[i])/3;	
							
						}
						
							if ( brojac % 2 == 0 && brojac != 0) V2.push_back(b);
						
							V1[i] = b;
									
				   	}
				   	
				   	return V2;
			}
						
	        
	        	for (int i = 0 ; i < V1.size() ; i++ )	{
							brojilo = 0;
							brojac = 0;
						for ( int j = i-1 ; j >= 0 ; j-- )	{
							if ( V1[j] == V1[i] ) brojilo++;
					}
						
							if ( brojilo > 0 ) continue;
						
						b = V1[i];

						while ((V1[i]) != 0 )		{
						
								brojac = 0;
								pomocni =(b);
						
							while ( pomocni != 0 )	{
							
								if ((V1[i]) % 3 == pomocni % 3 )	brojac++;
							
								pomocni/=3;
						}
						
							if ( brojac % 2 == 0 ) 	break;
							
							
						    	V1[i]=(V1[i])/3;	
						}
						
							if ( brojac % 2 != 0 ) V2.push_back(b);
							else if ( brojac == 0 ) V2.push_back(V1[i]);
							V1[i] = b;
							
			   	}
					
					return V2;
	}


int main ()
{
	int a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>V;
		std::cin>>a;
		V.push_back(a);
	for ( ; ; )	{
		std::cin>>a;
		if ( a == 0 ) break;
		V.push_back(a);
	}
	
	std::cout<<"Opaki: ";
	std::vector<int>V1;
	V1 = IzdvojiGadne(V,true);
	for (auto x : V1 ) std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	std::vector<int>V2;
	V2 = IzdvojiGadne(V,false);
	for ( auto x : V2 ) std::cout<<x<<" ";
	
	
	return 0;
}