//2. 
#include <stdio.h>

#define PI 3.141592
main()
{
  double x;
  int stepen,minut,sekund;
  printf("Unesite ugao u radijanima: ");
  scanf("%lf",&x);
  x*=180/PI;
  stepen=(int)x;
  x-=stepen;
  x*=60;
  minut=(int)x;
  x-=minut;
  x*=60;
  sekund=(int)x;
  printf("\nStepena, minuta, sekundi [%d,%d,%d]\n",stepen,minut,sekund);
}