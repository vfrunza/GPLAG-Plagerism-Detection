/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <vector>
#include <iostream>
using namespace std;
int main ()
{
	vector<vector<int> >M{{1,2,3},
						  {4,5,6}}, V;
						  
	for(int i(0);i<M.size();i++){
		for(int j(0);j<M[i].size();j++)
			V.push_back(M[i][j]);
		
	}
for(int i(0);i<V.size();i++){
	cout<<V[i]<<" ";
	endl;
	return 0;
}   