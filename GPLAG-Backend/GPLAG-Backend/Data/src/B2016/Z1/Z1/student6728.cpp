#include <iostream>
#include <cmath>
#include <vector>


bool ParniNeparni(int n)
{
	std::vector<int> v(10);
	
	for(int i = 0; i < v.size(); i++)
	{
		while(n != 0)
		{
			int pomocna = n%10;
			
			v[pomocna]++;
			
			n/= 10;
		}
		
	}
	
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 1; j < v.size(); j++)
		{
			if(v[i] != 0 && v[j] != 0)
			{
				if(v[i] != v[j])
				return false;
			}
		}
	}
	
	
return true;	
}



std::vector<int> IzdvojiGadne (std::vector<int> v, bool TacnoNetacno)
{
	std::vector<int> opaki;
	
	std::vector<int> odvratni;
	
	for(int i = 0; i < v.size(); i++)
	{
		int pomocna = abs(v[i]);
		
		int k = 1;
		int suma = 0;
		while(pomocna != 0)
		{
			
			int ostatak= pomocna % 3;
			
			pomocna /= 3;
			
			suma +=ostatak * k;
			
			k = k*10;
		}
		
		if(ParniNeparni(suma)) opaki.push_back(v[i]);
		
		else odvratni.push_back(v[i]);
	}
	
	if(TacnoNetacno == true) return opaki;
	
	else return odvratni;
	
	
}


int main()
{

   std::vector<int> v;
   
   int n;
   
   std::cout << "Koliko zelite unijeti elemenata: ";
   
   std::cin >> n;
   
   v.resize(n);
   
   std::cout << "Unesite elemente: ";
   
   for(int i = 0; i < v.size(); i++)
   {
      std::cin >> v[i];
   }
   
   std::vector<int> opaki = IzdvojiGadne(v,true);
   
   std::vector<int> gadni = IzdvojiGadne(v,false);
   
   for(int i: opaki)
   {
      std::cout << i << " ";
   }
   
   std::cout << std::endl;
   
   for(int i: gadni)
   {
      std::cout << i << " ";
   }
   
   return 0;
}

