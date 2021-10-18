#include <iostream>
#include <vector>
#include <iomanip>

int main ()
{
	int x, y;
	std::cin>>x>>y;
	
	std::vector<std::vector<int>> v(x, std::vector<int> {y});
	
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<y; j++)
		{
			std::cin>>v[i][j];
		}
	}
	
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<y; j++)
		{
				int temp=v[i][j];
				v[i][j]=v[j][i];
				v[j][i]=temp;
		}
	}
	
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<y; j++)
		{
			std::cout<<v[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	
	return 0;
}