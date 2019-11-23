#ifndef _ECG_SENSOR_H_
#define _ECG_SENSOR_H_

class ECGsensor
{
public:
  virtual float readingSignal() = 0;
};

class EGCcomponent: public ECGsensor
{ 
  ECGsensor* wrapper;  
public:
  EGCcomponent(ECGsensor* wrapper)
  {
    this->wrapper = wrapper;
  }
  
  float readingSignal()
  {
    return wrapper->readingSignal();
  }     
};

#endif //_ECG_SENSOR_H_
