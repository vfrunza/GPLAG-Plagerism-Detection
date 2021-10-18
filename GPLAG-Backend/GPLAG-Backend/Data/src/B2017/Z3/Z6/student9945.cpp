/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <queue>


int main ()
{
    int n(2);
    std::queue<int> Red;
    for (int j=0; j<5; j++) Red.push(j);
    int i = Red.size();
    int b=Red.size();
    std::cout<<i;
    while(b!=i-n) 
    {
    Red.pop();
    b--;
}
std::cout<<b;
	return 0;
}
