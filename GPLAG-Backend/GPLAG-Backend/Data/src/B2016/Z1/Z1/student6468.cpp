#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int numberOfDigits(long long num){
    int pov = 0;

    while(num){
        pov++;
        num/=10;
    }

    return pov;
}

long long decToTer(long long num){
    if(num<0) num*=-1;

    int digits = ceil(log(num)/log(3));

    long long pov = 0;

    while(num){
        pov += num%3;
        num /= 3;
        pov *= 10;
    }

    if(digits != numberOfDigits(pov))
        pov /= 10;

    while(pov){
        num += pov%10;
        pov /= 10;
        num *= 10;
    }

    if(digits != numberOfDigits(num))
        num/=10;

    return num;
}

bool evilNumber(long long num){
    if(num == 0) return false;
    
    vector<int> counter(3, 0);
    
    while(num){
        counter[num%10]++;
        num /= 10;
    }
    
    return counter[0]%2==0&&counter[1]%2==0&&counter[2]%2==0;
}

bool odiousNumber(long long num){
    if(num == 0) return false;
    
    vector<int> counter(3, 0);
    
    while(num){
        counter[num%10]++;
        num /= 10;
    }
    
    if(counter[0]==0) counter[0]++;
    if(counter[1]==0) counter[1]++;
    if(counter[2]==0) counter[2]++;
    
    return counter[0]%2!=0&&counter[1]%2!=0&&counter[2]%2!=0;
}

vector<int> IzdvojiGadne(vector<int> numbers, bool condition){
    vector<int> pov(0);
    
    for(int i=0; i<numbers.size(); i++){
        bool exists = false;
        
        for(int j=0; j<pov.size(); j++)
            if(pov[j]==numbers[i]) exists = true;
            
        if(!exists){
            long long num = decToTer((long long)numbers[i]);

            if(condition){
                if(evilNumber(num))
                    pov.push_back(numbers[i]);
            }
            else {
                if(odiousNumber(num))
                    pov.push_back(numbers[i]);
            }
        }
            
    }
    
    return pov;
}

int main(){
    vector<int> brojevi(0);
    
    cout << "Unesite brojeve (0 za prekid unosa): ";
    
    for(;;){
        int x;
        cin >> x;
        if(x==0) break;
        brojevi.push_back(x);
    }
    
    vector<int> opaki = IzdvojiGadne(brojevi, true);
    vector<int> odvratni = IzdvojiGadne(brojevi, false);
    
    cout << "Opaki: ";
    for(int i=0; i< opaki.size(); i++)
        cout << opaki[i] << " ";
    
    cout << endl << "Odvratni: ";
    for(int i=0; i<odvratni.size(); i++)
        cout << odvratni[i] << " ";
    
}