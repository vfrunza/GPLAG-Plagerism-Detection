/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include<iostream>
#include<algorithm>
#include<stdexcept>
#include<vector>
#include<cmath>

using namespace std;

double fun(int a, int b) {
	return a + 2*b;
}

double Cifre(int n) {
  int suma = 0;
  
  while(n != 0) {
    suma += (n % 10);
    n /= 10;
  }

  return suma;
}

bool KriterijPoBrojuCifara(int x, int y) {
  int a = Cifre(x), b = Cifre(y);
  if(a == b) return x < y;
  return a < b;
}

template<typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
void SortirajPodrucjeVrijednosti(IterTip1 p1, IterTip1 k1, IterTip1 p2, IterTip2 p3, Tip2 f(Tip1, Tip1), bool comp(Tip1, Tip1)) {
	
	int n(k1 - p1);
	sort(p1, k1, comp);
	sort(p2, p2 + n, comp);
	IterTip2 s3(p3);

	while(p1 != k1) {
		IterTip2 temp = std::find (s3, s3 + n, f(*p1++, *p2++));
		if (temp == s3 + n) throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		swap(*p3++, *temp);
	}

}

int main() {
	std::vector<int> v1;
	v1.push_back(35);
	v1.push_back(12);
	v1.push_back(8);
	v1.push_back(111);
	v1.push_back(20);
	v1.push_back(4);
	std::vector<int> v2;
	v2.push_back(61);
	v2.push_back(39);
	v2.push_back(5);
	v2.push_back(313);
	v2.push_back(42);
	v2.push_back(13);
	std::vector<double> v3;
	v3.push_back(195);
	v3.push_back(46);
	v3.push_back(634);
	v3.push_back(22);
	v3.push_back(13);
	v3.push_back(126);
	//46, 22, 195, 126, 634, 113
	SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), fun, KriterijPoBrojuCifara);
	for (std::vector<double>::iterator i = v3.begin(); i != v3.end(); ++i)
	{
		cout << *i << endl;
	}
	return 0;
}