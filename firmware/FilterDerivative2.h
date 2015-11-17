#ifndef FilterDerivative2_h
#define FilterDerivative2_h
#include <math.h>
#define TWO_PI  6.28
#define PI 3.14
// returns the derivative
struct FilterDerivative2 {
  long LastUS;
  float LastInput;
  
  float Derivative;
  
  float input( float inVal );
  
  float output();
};

void testFilterDerivative2();

#endif
