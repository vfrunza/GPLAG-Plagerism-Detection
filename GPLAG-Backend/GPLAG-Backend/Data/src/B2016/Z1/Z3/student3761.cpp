/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> VekRP(0);
	
	double maxx(v[0]);
	std::vector<double> podniz(0);
	
	if(v[0]<v[1]) podniz.push_back(v[0]);
	
	for(int i=1;i<v.size();i++)
	 {
	 	if(v[i]>maxx)
	 	 {
	 	 	maxx=v[i];
	 	 	podniz.push_back(maxx);
	 	 }
	 	 
	 	else
	 	 {
	 	 	if(podniz.size()==1)
	 	 	 {
	 	 	 	podniz.resize(0);
	 	 	 	maxx=v[i];
	 	 	 	i--;
	 	 	 }
	 	 	else if(podniz.size()==0)
	 	 	 {
	 	 	 	maxx=v[i];
	 	 	 	podniz.push_back(v[i]);
	 	 	 }
	 	 	else if(podniz.size()>1)
	 	 	 {
	 	 	 	VekRP.push_back(podniz);
	 	 	 	podniz.resize(0);
	 	 	 	maxx=v[i];
	 	 	 	podniz.push_back(maxx);
	 	 	 	
	 	 	 }
	 	 }
	 }
	 
	// VekRP.push_back(podniz);
	 
	 return VekRP;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v)
{
   std::vector<std::vector<double>>VekRP;
   
   double minn(v[0]);
   std::vector<double> podniz(0);
   
   if(v[0]>v[1]) podniz.push_back(v[0]);
   
   for(int i=1;i<v.size();i++)
    {
      if(v[i]<minn)
       {
       	minn=v[i];
       	podniz.push_back(minn);
       }
       
      else
       {
       	 if(podniz.size()==1)
       	  {
       	  	podniz.resize(0);
       	  	minn=v[i];
       	  	i--;
       	  }
       	 else if(podniz.size()==0)
       	  {
       	  	minn=v[i];
       	  	podniz.push_back(v[i]);
       	  }
       	 else if(podniz.size()>1)
       	  {
       	  	VekRP.push_back(podniz);
       	  	podniz.resize(0);
       	  	minn=v[i];
       	  	podniz.push_back(minn);
       	  }
       	  
       }
    }
    VekRP.push_back(podniz);
    return VekRP;
}

int main ()
{
	
	int br_el;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br_el;
	std::vector<double> v(br_el);
	
	std::cout<<"Unesite elemente vektora: ";
	
	for(int i=0;i<br_el;i++)
	 {
	 	std::cin>>v[i];
	 }
	
	std::vector<std::vector<double>> vekvek1(RastuciPodnizovi(v));
	std::vector<std::vector<double>> vekvek2(OpadajuciPodnizovi(v));
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	for(int i=0;i<vekvek1.size();i++)
	 {
	 	for(int j=0;j<vekvek1[i].size();j++)
	 	 {
	 	 	std::cout<<vekvek1[i][j]<<" ";
	 	 }
	 	 std::cout<<std::endl;
	 }
	 
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<vekvek2.size();i++)
	 {
	 	for(int j=0;j<vekvek2[i].size();j++)
	 	 {
	 	 	std::cout<<vekvek2[i][j]<<" ";
	 	 }
	 	 std::cout<<std::endl;
	 }
	
	return 0;
}