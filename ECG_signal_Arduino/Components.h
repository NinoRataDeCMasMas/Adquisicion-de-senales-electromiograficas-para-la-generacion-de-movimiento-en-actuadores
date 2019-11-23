#include <Servo.h>
#include <ECGsensors.h>
#include <ComplementaryFilter.h>

/**
 * @decorator Filter
 */
struct Filter: public EGCcomponent {  
  Filter(ECGsensor* sensor, float setpoint): EGCcomponent(sensor) {
    filter = new ComplementaryFilter(setpoint);  
  }
  
  float readingSignal() {
    return filter->compute(EGCcomponent::readingSignal());
  }
private:
  ComplementaryFilter* filter;
};

/**
 * @decorator Servomotor
 */
struct Servomotor: public EGCcomponent {  
  Servomotor(ECGsensor* sensor, int attachedPin): EGCcomponent(sensor) {
    servoMotor = new Servo();
    servoMotor->attach(attachedPin);  
  }
  
  float readingSignal() {
    auto value = EGCcomponent::readingSignal();
    auto mapped = map(value, 0, 659, 30, 160);
    servoMotor->write(mapped);
    return value;
  }
private:
  Servo* servoMotor;
};
