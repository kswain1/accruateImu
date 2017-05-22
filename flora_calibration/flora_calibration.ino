#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS0.h>
// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
// This sketch can be used to output raw sensor data in a format that
// can be understoof by MotionCal from PJRC. Download the application
// from http://www.pjrc.com/store/prop_shield.html and make note of the
// magentic offsets after rotating the sensors sufficiently.
//
// You should end up with 3 offsets for X/Y/Z, which are displayed
// in the top-right corner of the application.
//
// Make sure you have the latest versions of the Adfruit_L3GD20_U and
// Adafruit_LSM303_U libraries when running this sketch since they
// use a new .raw field added in the latest versions (Oct 10 2016)

void setupSensor()
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);
  
  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

void setup() 
{
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
  Serial.begin(9600);
  Serial.println("LSM raw read demo");
  
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS0 9DOF");
  Serial.println("");
  Serial.println("");
}


void loop(void)
{
  lsm.read();
  // Print the sensor data
  Serial.print("Raw:");
  Serial.print((int)lsm.accelData.x);
  Serial.print(',');
  Serial.print((int)lsm.accelData.y);
  Serial.print(',');
  Serial.print((int)lsm.accelData.z);
  Serial.print(',');
  Serial.print((int)lsm.gyroData.x);
  Serial.print(',');
  Serial.print((int)lsm.gyroData.y);
  Serial.print(',');
  Serial.print((int)lsm.gyroData.z);
  Serial.print(',');
  Serial.print((int)lsm.magData.x);
  Serial.print(',');
  Serial.print((int)lsm.magData.y);
  Serial.print(',');
  Serial.print((int)lsm.magData.z);
  Serial.println();  
    
  delay(50);
}
