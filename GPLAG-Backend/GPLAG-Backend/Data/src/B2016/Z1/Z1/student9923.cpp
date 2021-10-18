#include <iostream>
#include <vector>


std::vector<int> IzdvojiGadne (std::vector<int> v, bool odabir)
{
	
	std::vector<int> rezultat;
	
	for (int i{};i<v.size();i++)
		{
			int broj = v[i];
			
			if (broj <0)
				broj*=-1;
			
			std::vector<int> pomocni (0,0);                             ///Vektor u kojem stoji tercijarni zapis, okrenut unazad.
			
			while (broj > 0)
			{
				int a = broj%3;
				pomocni.push_back(a);
				
				broj/=3;
			}
			
			std::vector<int> zapis (pomocni.size());
			
			int k = zapis.size() - 1;
			for (int j{};j<zapis.size();j++)
				zapis[j] = pomocni[k--];							///Vektor u kojem stoji tercijazni zapis.
			
			
			int a{}, b{}, c{};										///Brojaci za cifre 0, 1 i 2.
			
			for (int j{};j<zapis.size();j++)						
				{
					if (zapis[j] == 0)
						a++;
					else if (zapis[j] == 1)
						b++;
					else if (zapis[j] == 2)
						c++;
				}
			
			bool uslov_a {false}, uslov_b {false}, uslov_c {false};
			
			if (odabir == true)										///Uslov za opake brojeve.
				{
					if (a == 0 || a%2 == 0)
						uslov_a = true;
					if (b == 0 || b%2 == 0)
						uslov_b = true;
					if (c == 0 || c%2 == 0)
						uslov_c = true;
						
					if (uslov_a == true && uslov_b == true && uslov_c == true)
						{
							bool postoji {false};
							
							for (int j{};j<rezultat.size();j++)
								{
									if (v[i] == rezultat[j])
										postoji = true;
								}
								
							if (postoji == false)
								rezultat.push_back(v[i]);
						}
				}
			else
				{
					if (a == 0 || a%2 != 0)
						uslov_a = true;
					if (b == 0 || b%2 != 0)
						uslov_b = true;
					if (c == 0 || c%2 != 0)
						uslov_c = true;
						
					if (uslov_a == true && uslov_b == true && uslov_c == true)
						{
							bool postoji {false};
							
							for (int j{};j<rezultat.size();j++)
								{
									if (v[i] == rezultat[j])
										postoji = true;
								}
								
							if (postoji == false)
								rezultat.push_back(v[i]);
						}
				}
		}
	
	
	
	
	
	return rezultat;
}



int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	
	while (true)
		{
			int x;
			std::cin>>x;
			
			if (x == 0)
				break;
				
			v.push_back(x);
		}
		
	std::vector<int> rezultat = IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for (int x : rezultat)
		std::cout<<x<<" ";
	
	std::cout<<std::endl<<"Odvratni: ";
	rezultat = IzdvojiGadne(v,false);
	for (int x : rezultat)
		std::cout<<x<<" ";
		
	
	return 0;
}