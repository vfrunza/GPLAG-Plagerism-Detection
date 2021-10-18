/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int*>v(5);
    for(int i = 0; i < v.size(); i++){
        if(v[i] == nullptr) std::cout<<"NULL SAM";
    }
    
    std::vector<int>v1{1,2,3};
    std::vector<int>v2(3);
    v2 = v1;
    for(auto x : v2) std::cout<<x<<" ";
    
	return 0;
}
