#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
typedef std::vector<int> IntVektor;

bool StepenDvojke(int n){
	if(n==0) return true;
		for(int i=1; i<=abs(n); i*=2){
	 	if (i==abs(n)) return true;
	 }
	 return false;
}


std::deque<IntVektor> MaksimalniStepeniDvojke(IntVektor v, enum rastuci){
	IntVektor Rastuci;
		for(int i=0; i<v.size(); i++){
		
	}
}


int main ()
{
	int n;
	std::cin >> n;
	bool a;
	a=StepenDvojke(n);
	std::cout << a << std::endl;
	
	return 0;
}