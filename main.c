#pragma config(Sensor, S1,     distance,       sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     color,          sensorEV3_Color)
#pragma config(Sensor, S3,     angle,          sensorEV3_Gyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Variables
const int blackLine = 17;
const int white = 90;
int lineFollowTarget = 65;
const bool right = true;
const bool left = false;

#include "Functions.h"
#include "Stages.h"


task main()
{
	//wait1Msec(5000);
	//Stage1();
	//Stage2();
	//Stage3();
	//Stage4();
	//Stage5();
	lfToBlack(15, right);
	Stage6(true);
	Stage7();
	Stage6(false);

}
