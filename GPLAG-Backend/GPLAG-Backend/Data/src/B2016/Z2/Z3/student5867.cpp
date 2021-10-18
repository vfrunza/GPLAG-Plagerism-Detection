/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrica;

template <typename Tip>
Tip SumaCifara (Tip n)
{
	Tip suma = 0;
	while(n != 0)
	{
		Tip ostatak = n % 10;
		suma += ostatak;
		n /= 10;
	}
	return suma;
}

template <typename Tip1, typename Tip2, typename Tip3>
auto UvrnutiPresjek (Tip1 *p1, Tip1 *p2, Tip2 *q1, Tip2 *q2, Tip3 fun(Tip3)) -> typename std::remove_reference<decltype(*p1)>::type 
{
 	Matrica mat[3][3];
 	int i(0), j(0);
 	int *p = p1;
 	int *q = q1;
 	while(p != p2)
 	{
 		while(q != q2)
 		{
 			if(SumaCifara(*p) == SumaCifara(*q))
 			{
 				mat[i][j] = *p;
 				j++;
 				mat[i][j] = *q;
 				j++;
 				mat[i][j] = SumaCifara(*p);
 				i++;
 				j = 0;
 			}
 			q++;
 		}
 		p++;
 	}
 	return mat;
}
int main ()
{
	
	return 0;
}