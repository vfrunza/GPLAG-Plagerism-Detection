#include <iostream>
#include <vector>

template<typename pokt1, typename pokt2, typename tip, typename mat>


auto UvrnutiPresjek(pokt1 p1, pokt1 p2, pokt2 p3, pokt2 p4, tip f(tip)->std::vector<std::vector<typename std::remove_reference<decltype(*pokt1)>::type>>){
	std::vector<std::vector<typename std::remove_reference<decltype(*pokt1)>::type>> mat;
	int n(0);
	pokt1 poc1(p1);
	while(poc1!=p2){
		pokt2 poc3(p3);
		while(poc3!=p4){
			if(f(*poc1)==f(*poc3)) n++;
				poc3++;
		}
		poc1++;
	}
	mat.resize(n);
	int i(0);
	while(p1!=p2){
		pokt2 poc33(p3);
		while(poc33!=p4){
			if(f(*p1)==f(*poc33)){
			mat[i].push_back(*p1);
			mat[i].push_back(*poc33);
			mat[i].push_back(f(*p1));
			i++;
			if(i==n) break;
			}
			poc33++;
			if(i==n) break;
		}
		p1++;
	}
return mat;
}




int main ()
{
	return 0;
}