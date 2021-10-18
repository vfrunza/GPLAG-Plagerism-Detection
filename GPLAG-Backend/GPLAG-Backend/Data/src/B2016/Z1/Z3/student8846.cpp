#include<iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica m) 
{
 for(int i = 0; i < m.size(); i++) 
 {
 for(int j = 0; j < m[i].size() ; j++)
 std::cout<<m[i][j]<<" ";
 std::cout << std::endl;
 }
}

Matrica OpadajuciPodnizovi(std::vector<double> vektor)
{
	Matrica podnizovi;
	std::vector<double>  pomocni;
	for(int i =0 ;i<vektor.size();i++)
	{
		if(i!=(int)vektor.size()-1)
		{
			while(vektor[i]>=vektor[i+1])
			{
				if(i==(int)vektor.size()-2) break;
				pomocni.push_back(vektor[i]);
				i++;
			}
			pomocni.push_back(vektor[i]);
			if(i==int(vektor.size())-2)
			{
				if(pomocni[(int)pomocni.size()-1]>=vektor[i+1])
				{
					pomocni.push_back(vektor[i+1]);
				}
			}
			if(pomocni.size()>=2)
			{
				podnizovi.push_back(pomocni);
				pomocni={};
			}
			else
			{
				pomocni={};
			}
		}
	}
	return podnizovi;
}

Matrica RastuciPodnizovi(std::vector<double> vektor)
{
	Matrica podnizovi;
	std::vector<double>  pomocni;
	for(int i =0 ;i<vektor.size();i++)
	{
		if(i!=(int)vektor.size()-1)
		{
			while(vektor[i]<=vektor[i+1])
			{
				if(i==(int)vektor.size()-2) break;
				pomocni.push_back(vektor[i]);
				i++;
			}
			pomocni.push_back(vektor[i]);
			if(i==int(vektor.size())-2)
			{
				if(pomocni[(int)pomocni.size()-1]<=vektor[i+1])
				{
					pomocni.push_back(vektor[i+1]);
				}
			}
		
			if(pomocni.size()>=2)
			{
				podnizovi.push_back(pomocni);
				pomocni={};
			}
			else
			{
				pomocni={};
			}
		}
	}
	return podnizovi;
}

int main ()
{
	int n,brojac(0),broj;
	std::vector<double> v;
	std::vector<std::vector<double>> vekt;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
   do
   {
   	std::cin>>broj;
   	brojac++;
   	v.push_back(broj);
   }
   while(brojac!=n);
   Matrica m=RastuciPodnizovi(v);
   std::cout<<"Maksimalni rastuci podnizovi: \n";
   IspisiMatricu(m); 
   std::cout<<"Maksimalni opadajuci podnizovi: \n";
   IspisiMatricu(OpadajuciPodnizovi(v));
  /* std::vector<double> vektor={ 1, 3, 2, 6, 7, 9, 10, 4, 3, 1,7};
   Matrica mat=OpadajuciPodnizovi(vektor);
   Matrica mat2 = RastuciPodnizovi(vektor);
   IspisiMatricu(mat);
   std::cout<<"\n";
   IspisiMatricu(mat2);*/
   
	return 0;
}