#include <map>
#include <vector>
#include <iostream>

int main ()
{
std::map<std::string, int> stanovnistvo;
stanovnistvo.insert({"Sarajevo", 450000});
stanovnistvo.insert({"Banja Luka", 200000});
stanovnistvo.insert({"Mostar", 8500440});
stanovnistvo.insert({"Mostar", 85000});
stanovnistvo.insert({"Mostar", 8500});
stanovnistvo.insert({"Travnik", 80000});
stanovnistvo.insert({"Mostar", 8500770});
for(auto it = stanovnistvo.begin(); it != stanovnistvo.end(); it++)
 std::cout << "Grad: " << it->first << " Broj stanovnika: "
 << it->second << std::endl;
	return 0;
}
