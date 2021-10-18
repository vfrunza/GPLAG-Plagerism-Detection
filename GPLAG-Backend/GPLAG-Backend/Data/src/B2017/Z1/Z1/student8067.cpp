
#include <iostream>


 // std::vector<int> IzdvojiSimetricneTernarne(int n,bool a){


int main ()
{
	int n;
	int a[32]={0},i=0,j=0;
	std::cin>>n;
	do {
	int p;
	p=n%3;
	n=n/3;
	i++;
	}while(n!=0);
	for(j=n;j>=0;j--) std::cout<<a[j];

		
	

	return 0;
}