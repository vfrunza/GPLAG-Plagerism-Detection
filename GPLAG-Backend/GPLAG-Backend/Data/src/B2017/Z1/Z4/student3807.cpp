#include <string>
#include <iostream>
#include <cctype>


template <typename typ>
	void UnosBroja(std::string a, std::string b, typ &n){
		std::cout<<a;
		do
		{
			std::cin>>n;
			if(std::cin.peek()!='\n') 
			{
				std::cout<<b;
				std::cin.clear();
				std::cin.ignore(1000,'\n');
			}
			else break;
		}while(1);
		
	
	}
	

int main ()
{
	int a;
	UnosBroja("Unesi broj: ","GRESKA! ",a);
	
	std::cout<<a;
	
	
	return 0;
}