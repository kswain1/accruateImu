# accruateImu
This repository is for the documentation of the flora code as we create the sensor fusion to ensure the accuracy of the device
## Materials Needed 
- Flora Board https://www.adafruit.com/product/659
- LSM9DS0 Flora https://www.adafruit.com/product/2020
- Conductive Thread (below)

# Step One Setup Your Flora Board and Accelerometer
In my project I will have my flora board connected to a shirt sleeve. If you are interested in sewing your flora board in a similar fashion follow the link below. 
- Conductive Thread 
https://learn.adafruit.com/conductive-thread

![img_1293](https://cloud.githubusercontent.com/assets/9138420/26770852/e6e7c7da-497f-11e7-8a0f-29a1274de3c2.JPG)

# Step Two Download Motion Tracking Code 
We are using the LSMD90 IMU sensor and Arduino Kit Software Download is below 

- https://learn.adafruit.com/adafruit-lsm9ds0-accelerometer-gyro-magnetometer-9-dof-breakouts/wiring-and-test
- AHRS CODE https://github.com/adafruit/Adafruit_AHRS/archive/master.zip


## Loading Up The AHRS Sample Sketch 
Once both of the example code are downloaded from the above links. Add those libraries to your Arduino AHRS library folder. Open up the Arduino platform and there should be in a ahrs_lsm9ds0 example in your libraries folder. 

![sensors_00_sketch](https://cloud.githubusercontent.com/assets/9138420/26771029/2594cf22-4981-11e7-9efe-920858cbafc7.png)

- Compile the code and the output will look similar to the content below.
![sensors_01_ahrsoutput](https://cloud.githubusercontent.com/assets/9138420/26771049/4ad558ec-4981-11e7-8c13-04103b56472b.png)

# Step 3 Understanding the AHRS DATA

### Warning Math Terms will be used! Don't Worry I will use Laymans Terms
The AHRS example sketchs reads raw data from the board's accelerometer/magnetometer and converts the raw data into easy to understand Euler angles.

It does this with a bit of trigonometry (you remember high school math, right!?), but to save you from dusting off the textbooks or wading through endless application notes, we've wrapped up all of the calculation to convert raw accelerometer and magnetometer data to degrees in a convenient helper function:


