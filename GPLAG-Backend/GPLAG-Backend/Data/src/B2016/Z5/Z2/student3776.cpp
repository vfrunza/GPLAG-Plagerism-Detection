#include <iostream>
int main(){
	long long int a=143562513345345343;
	long long int b=235234345344534534;
	std::cout<<static_cast<long double>(a)/b<<std::endl;
	std::cout<<(long double )a/b;
	return 0;
}