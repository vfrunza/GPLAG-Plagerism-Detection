/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<double> vektor; 
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(vektor v)
{
	Matrica temp(1);
	int k(0), i, j;
	if(v.size()<2)
		return temp;
	for(i=0; i<int(v.size()-1); i++)
	{
		for(j=i; j<int(v.size()-1); j++)
		{
			if(v.at(j)>v.at(j+1))
				break;
			while(v.at(j)<=v.at(j+1) && j < int(v.size()-1))
			{
				temp[k].push_back(v[j]);
				j++;
				if(j==v.size()-1) break;
			}
			temp.resize(k+2);
			temp[k].push_back(v[j]);
			j--;
			k++;
		}
	i = j;
	}
	return temp;
}
Matrica OpadajuciPodnizovi(vektor v)
{
	Matrica temp(1);
	int k(0), i, j;
	if(v.size()<2)	return temp;
	for(i=0; i<int(v.size()-1); i++)
	{
		for(j=i; j<int(v.size()-1); j++)
		{
			if(v.at(j)<v.at(j+1)) break;
			while(v.at(j)>=v.at(j+1) && j<int(v.size()-1))
			{
				temp[k].push_back(v[j]);
				j++;
				if(j==v.size()-1) break;
			} 
			temp.resize(k+2);
			temp[k].push_back(v[j]);
			j--;
			k++;
		} i=j;
	} return temp;
}

int main ()
{
	int n, m;
	vektor v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{
		std::cin>>m;
		v.push_back(m);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica a(RastuciPodnizovi(v));
    Matrica mat(OpadajuciPodnizovi(v));
    for(int i=0; i < a.size(); i++)
    {
    	for(int j=0; j<a[i].size(); j++)
    		std::cout<<std::setprecision(12)<<a[i][j]<<" ";
    	std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            std::cout <<std::setprecision(12)<< mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

	return 0;

}