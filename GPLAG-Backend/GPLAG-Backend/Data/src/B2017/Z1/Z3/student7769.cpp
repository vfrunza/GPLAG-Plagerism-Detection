#include <iostream>
#include <deque>
#include <vector>


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, int ses)
{
    std::deque<std::vector<int>> v,z;
    if(ses==1){
    for(int i=0;i<a.size();i++)
    {
        if(a.at(i)<=a.at(i+1)) v.push_back(std::vector<int>(i));
    }
    return v;
    }
    else if(ses==2){
        for(int i=0;i<a.size();i++)
        {
            if(a.at(i)>=a.at(i+1)) z.push_back(std::vector<int>(i));
        }
        return z;
    }
    
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
	int b;
	std::cin>>b;
	std::vector<int> a (b);
	std::cout<<"Unesite elemente vektora: ";
	
	int broj;
	for (int i=0; i<b; i++) {
		std::cin>>broj;
		a.at(i) = broj ;
	}
	int x;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>x;
	auto y=MaksimalniPodnizoviStepenaDvojke(a,x);
	
	
	return 0;
}