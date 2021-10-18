#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double epsilon = 0.0001;
	double a, b, c, D, x1, x2, rjesenjeX1, rjesenjeX2;
	
    bool rjesenje1 = false, rjesenje2 = false;
	
	do
	{
	    cout << "Unesite koeficijente kvadratne jednacine a, b i c" << endl;
	    cin >> a >> b >> c;
	    
	}while(abs(a) < epsilon);
	
	D = pow(b,2) - 4 * a * c;
	
	if(D < 0) cout << "Rjesenja su imaginarni brojevi" << endl;
	else
	{
	    x1 = (-b + sqrt(D)) / (2 * a);
	    x2 = (-b - sqrt(D)) / (2 * a);
	    
	    x1 = round(x1 * 100.0) / 100.0;
	    x2 = round(x2 * 100.0) / 100.0;
	    
	    //cout << x1 << endl << x2 << endl;
	    
	    do
	    {
	    	
	        cout << "Unesite rjesenje x1: ";
	        cin >> rjesenjeX1;
	        
	        
	        if((abs(x1-rjesenjeX1) <= 0.1 || abs(x1-rjesenjeX1-epsilon) <= 0.1 || abs(x1-rjesenjeX1+epsilon) <= 0.1) && abs(x1-rjesenjeX1) > 0)
	        {
	        	
	        	if(rjesenjeX1 < x1)  cout << "Priblizno manje" << endl;
	        	else if(rjesenjeX1 > x1)  cout << "Priblizno vece" << endl;
	        	
	        }
	        else if(rjesenjeX1 < x1) cout << "Manje" << endl;
	        else if(rjesenjeX1 > x1) cout << "Vece" << endl;
	        else if(abs(x1-rjesenjeX1) < epsilon)
	        {
	            cout << "Tacno" << endl;
	            rjesenje1 = true;
	        }
	        
	    }while(!rjesenje1);
	    
	    do
	    {
	        cout << "Unesite rjesenje x2: ";
	        cin >> rjesenjeX2;
	        
	        
	        if((abs(x2-rjesenjeX2) <= 0.1 || abs(x2-rjesenjeX2-epsilon) <= 0.1 || abs(x2-rjesenjeX2+epsilon) <= 0.1) && abs(x2-rjesenjeX2) > 0)
	        {
	        	if(rjesenjeX2 > x2)  cout << "Priblizno vece" << endl;
	        	else if(rjesenjeX2 < x2)  cout << "Priblizno manje" << endl;
	        	
	        }
	        else if(rjesenjeX2 < x2) cout << "Manje" << endl;
	        else if(rjesenjeX2 > x2) cout << "Vece" << endl;
	        else if(abs(x2-rjesenjeX2) < epsilon)
	        {
	            cout << "Tacno" << endl;
	            rjesenje2 = true;
	        }
	        
	    }while(!rjesenje2);
	    
	}
	
	return 0;
}