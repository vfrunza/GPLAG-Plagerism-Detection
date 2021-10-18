/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>



template <typename IterTip1, typename IterTip2, typename pok_na_fun>

auto UvrnutiPresjek (IterTip1 p1, IterTip1 p2, IterTip2 p3, IterTip2 p4, pok_na_fun f=[](typename std::remove_reference<decltype(*p1)>::type x){
	return x;
})-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	Matrica m;
	IterTip1 p1_copy(p1);
	IterTip2 p3_copy(p3);
	
		while (p1_copy!=p2 && p3_copy!=p4){
			if(f(*p1_copy)==f(p3_copy)){
				std::vector<typename std::remove_reference<decltype(*p1)>::type> v(3);
				v[0]=*p1_copy;
				v[1]=*p3_copy;
				v[3]=f(*p1_copy);
				m.push_back(v);
			}
			p1_copy++;
			p3_copy++;
		}
	
	sort(m.begin(), m.end(),[](typename std::remove_reference<decltype(*p1)>::type x, typename std::remove_reference<decltype(*p1)>::type y){
		if (x[2]!=y[2]) return (x[2]>y[2]);
		else if (x[0]!=y[0]) return (x[0]>y[0]);
		else return (x[1]>y[1]);
	});
}

int main ()
{
	
	return 0;
}