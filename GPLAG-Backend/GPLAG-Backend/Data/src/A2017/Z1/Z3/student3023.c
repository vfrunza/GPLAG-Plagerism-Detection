#include <stdio.h> 
#include <math.h> 
#define e 0.001

int main() 
{
  double a, b, c;
  double px1, px2;
  double x1, x2;
  double pokusaj;
  
  printf("Unesite koeficijente a, b i c: ");
  scanf("%lf%lf%lf", &a, &b, &c);
  
  if(((b*b) - (4 * a * c)) < 0)
  {
    printf("Rjesenja su imaginarni brojevi.");
  }
  else
  {
    px1 = ((-b) + sqrt((b * b) - (4 * a * c)))/(2 * a);
    px2 = ((-b) + sqrt((b * b) - (4 * a * c)))/(2 * a);
    
    if(px1 <= px2)
    {
      x1 = px1;
      x2 = px2;
    }
    else
    {
      x2 = px1;
      x1 = px2;
    }
    
    
    pokusaj = 0;
    do
    {
      printf("Unesite rjesenje x1: ");
      scanf("%lf", &pokusaj);
      
      if(pokusaj > x1)
      {
        if(fabs(pokusaj - x1) > 0.1)
        {
          printf("Vece\n");
        }
        else if(((pokusaj - x1) < 0.1) && (fabs(pokusaj - x1) > e))
        {
          printf("Priblizno vece\n");
        }
        else
        {
          
        }
      }
      else
      {
        if(fabs(x1 - pokusaj) > 0.1)
        {
          printf("Manje\n");
        }
        else if(((x1 - pokusaj) < 0.1) && (fabs(pokusaj - x1) > e))
        {
          printf("Priblizno manje\n");
        }
        else
        {
          
        }
      }
    }
    while(fabs(pokusaj - x1) > e);
    printf("Tacno\n");
    
    pokusaj = 0;
    do
    {
      printf("Unesite rjesenje x2: ");
      scanf("%lf", &pokusaj);
      
      if(pokusaj > x2)
      {
        if(fabs(pokusaj - x2) > 0.1)
        {
          printf("Vece\n");
        }
        else if(((pokusaj - x2) < 0.1) && (fabs(pokusaj - x2) > e))
        {
          printf("Priblizno vece\n");
        }
        else
        {
          
        }
      }
      else
      {
        if(fabs(x2 - pokusaj) > 0.1)
        {
          printf("Manje\n");
        }
        else if(((x2 - pokusaj) < 0.1) && (fabs(pokusaj - x2) > e))
        {
          printf("Priblizno manje\n");
        }
        else
        {
          
        }
      }
    }
    while(fabs(pokusaj - x2) > e);
    printf("Tacno\n");
  }
  
  return 0;
}