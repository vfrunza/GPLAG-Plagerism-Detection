#include <iostream>
#include <vector>
#include <deque>


enum Smjer {Rastuci=1,Opadajuci=2};
bool StepeniDvojke(int n)
{
	bool stependvojke(false);
	for(int i=1; i<=n; i=i*2) {
		if(n==i) {
			stependvojke=true;
			break;
		}

	}

	if(stependvojke)	return true;
	return false;

}
std:: deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer smijer)
{
	std::vector<int> v1;
	std:: deque<std::vector<int>> d;
	if(smijer==Rastuci) {

		for(int i=0; i<v.size()-1; i++) {

			while(i<v.size()-1 && v.at(i)<=v.at(i+1) && StepeniDvojke(v.at(i)) && StepeniDvojke(v.at(i+1))) {
				if(v1.size()==0) {
					v1.push_back(v.at(i));
				}
				v1.push_back(v.at(i+1));

				i++;
			}
			if(v1.size()!=0) {
				d.push_back(v1);
				v1.resize(0);
			}
		

		}
	}
else 
{
	
for(int i=0; i<v.size()-1; i++) {

			while(i<v.size()-1 && v.at(i)>=v.at(i+1) && StepeniDvojke(v.at(i)) && StepeniDvojke(v.at(i+1))) {
				if(v1.size()==0) {
					v1.push_back(v.at(i));
				}
				v1.push_back(v.at(i+1));

				i++;
			}
			if(v1.size()!=0) {
				d.push_back(v1);
				v1.resize(0);
			}
		

		}	
	
}

return d;

}



int main()
{
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int> v(n);
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<v.size();i++)
	{
		std::cin>>v.at(i);
		
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int broj;
	std::cin>>broj;
   std:: deque<std::vector<int>> d(MaksimalniPodnizoviStepenaDvojke(v,Smjer(broj)));
   if(broj==1)
   std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
   else if(broj==2)
   std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<d.size();i++)
	{
		for(int j=0;j<d.at(i).size();j++)
		{
	 std::cout<<d.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
		
	}
	

	
	
	
	
	
	
return 0;
}