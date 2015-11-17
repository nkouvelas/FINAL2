#include "FilterDerivative2.h"
#include "application.h"

float FilterDerivative2::input( float inVal ) {
  long thisUS = micros();
  float dt = 1e-6*float(thisUS - LastUS);   // cast to float here, for math
  LastUS = thisUS;                          // update this now
  
  Derivative = (inVal-LastInput) / dt;
    
  LastInput = inVal;
  return output();
}
  
float FilterDerivative2::output() { return Derivative; }
  
void testFilterDerivative2() {
  FilterDerivative2 der;
  
  while(true) {
    float t = 1e-6 * float( micros() );
    float value = 100*sin(TWO_PI*t);
    
    der.input(value);
    
    Serial.print( "\n" );
    Serial.print( value ); Serial.print( "\t");
    Serial.print( der.output() );
    
    delay(10);
  }
}
