#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const double PI = 3.1459256;
	const double epsilon = 0.0001;
	
	double x1, x2, x3, y1, y2, y3, a, b, c, temp;
	double alfa, minute, sekunde;
	
	bool ugao = false;
	
	
	cout << "Unesite koordinate tacke t1: ";
	cin >> x1 >> y1;
	
	cout << "Unesite koordinate tacke t2: ";
	cin >> x2 >> y2;
	
	cout << "Unesite koordinate tacke t3: ";
	cin >> x3 >> y3;
	
	
	a = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	b = sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	c = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
	
	if(abs(c - a - b) < epsilon || abs(b - a - c) < epsilon || abs(a - b - c) < epsilon) cout << "Linija" << endl;
	else
	{
	    if(abs(c * c - a * a - b * b) < epsilon || 
	       abs(b * b - a * a - c * c) < epsilon || 
	       abs(a * a - b * b - c * c) < epsilon)
	   {
	        cout << "Pravougli" << endl;
	        alfa = 90.0;
	        ugao = true;
	    }
	   
	
	    if(abs(2 * a - b - c) < epsilon)
	    {
	        cout << "Jednakostranicni" << endl;
	        alfa = 60.0;
	        ugao = true;
	    }    
	    else if(abs(a - b) < epsilon || abs(a - c) < epsilon || abs(b - c) < epsilon) cout << "Jednakokraki" << endl;
	}
	
	
	if(!ugao)
	{
	   if(b >= a && b >= c) 
	   {
	        temp = b;
	        b = a;
	        a = temp;
	   }
	   else if(c >= a && c >= b)
	   {
	        temp = c;
	        c = a;
	        a = temp;
	   }
	   
	   alfa = acos(abs((b * b + c * c - a * a) / (2 * b * c))) * 180.0 / PI;
	   
	  
	}
	
	minute = (alfa - (int)alfa) * 60;
    sekunde = (minute - (int)minute) * 60;
	
    alfa = (int)alfa;
    minute = (int)minute;
    sekunde = (int)sekunde;
    
    
    cout << "Najveci ugao je: " << alfa << " stepeni, " << minute << " minuta, " << sekunde << " sekundi" << endl;
	
	return 0;
}