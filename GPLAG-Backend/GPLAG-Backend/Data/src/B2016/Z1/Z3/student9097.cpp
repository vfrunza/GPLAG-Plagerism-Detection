#include<iostream>
#include<vector>
#include<iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double>v)
{
    Matrica M;
    int p(0);
    std::vector<double>a;
    for (int i=0; i<v.size(); i++)
    {
        p=i;
        while(p!=v.size()-1&&v[p]<=v[p+1])
        {
            a.push_back(v[p]);
            p++;
        }
        a.push_back(v[p]);
        if(p==v.size()&&v[p]>=v[p-1])
        a.push_back(v[p]);
        if(a.size()>1)
        M.push_back(a);
        i=p;
        a.clear();
    }
    return M;
}
Matrica OpadajuciPodnizovi(std::vector<double>v)
{
    Matrica M;
    int p(0);
    std::vector<double>a;
    for (int i=0; i<v.size(); i++)
    {
        p=i;
        while(p!=v.size()-1&&v[p]>=v[p+1])
        {
            a.push_back(v[p]);
            p++;
        }
        a.push_back(v[p]);
        if(p==v.size()&&v[p]<v[p-1])
        a.push_back(v[p]);
        if(a.size()>1)
        M.push_back(a);
        i=p;
        a.clear();
    }
    return M;
}
int main ()
{
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<double>v;
    for (int i=0; i<n; i++)
    {
        double p;
        std::cin>>p;
        v.push_back(p);
    }
    Matrica M1, M2;
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    M1=RastuciPodnizovi(v);
	for(auto i:M1)
	   {
	       for(auto j:i)
	            std::cout<<std::setprecision(12)<<j<<" ";
	       std::cout<<std::endl;
	   }
	   std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	 M2=OpadajuciPodnizovi(v);
	 for(auto k:M2)
	 {
	     for (auto z:k)
	        std::cout<<std::setprecision(12)<<z<<" ";
	     std::cout<<std::endl;
	 }
	return 0;
}