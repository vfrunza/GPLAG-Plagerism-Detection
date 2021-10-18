/*B 16/17, Zadaća 2, Zadatak 3 */
#include <iostream>
#include <vector>
#include <string>

template <typename tip1, typename tip2, typename tip3>
vector<vector<tip3>> UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 fun){
    int n(0);
    
    while(pocetak1!=kraj1){
        tip2 temp(pocetak2);
        while(temp!=kraj2){
            if(fun(*pocetak1)==fun(*temp)){
                // Povecava se broj clanova
                n++;
                
            }
        }
    }
    // parovi (x y) ako f(x)=f(y)
    
    
    // Matrica formata (n x 3)
    vector<vector<tip3>> mat(n, vector<tip3>(3));
}

int main ()
{
	return 0;
}