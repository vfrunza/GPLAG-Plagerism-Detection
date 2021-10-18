#include <iostream>
#include <string>
#include <vector>

int PotencijalniKrivci (/*char **&pok,*/ std::vector<std::string> vs)
{
	char **pok1(new char *[vs.size()]);
	for (int i=0; i<vs.size(); i++) pok1[i]=nullptr;
	
	for (int i=0; i<vs.size(); i++)
	{
		*pok1[i]=vs[i][0];
	}
	
	/////
	for (int i=0; i<vs.size();i++) std::cout << *pok1[i];
	
	return 5;
}

int main ()	2q
{
	std::vector<std::string> vs {{"Velid"},{"Posko"},{"Sta ima"}};
	
	
	PotencijalniKrivci(vs);
	
	
	return 0;
}