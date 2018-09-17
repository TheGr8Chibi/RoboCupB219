#pragma config(Sensor, S1,     distance,       sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     color,          sensorEV3_Color)
#pragma config(Sensor, S3,     angle,          sensorEV3_Gyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Variables
const int blackLine = 16;
const int white = 90;
const int lineFollowTarget = 75;
const bool right = true;
const bool left = false;

#include "Functions.h"
#include "Stages.h"


//Main program ----------------------------------------------------------------------------------------------------------------------------------------
task main()
{
	//wait1Msec(5000);
	//Track section
	//stage1();

	//Stop 3-------------------------------------
	//stage2();

	lfToBlack(blackLine, right);
	JumpLine(3);
	wait1Msec(200);

	turnDeg(90);
	//setMotorTarget(motorB, 100, -40);
	//wait1Msec(600);

	//JumpLine();
	//turnDeg(10);
	//Stop 4 (Bottle)
	//Drive to bottle

	while(getUSDistance(S1) > 7.5){
		lineFollower(0.7, left,20);
	}
	stopMotors();

	//Close arm
	closeArm();

	JumpLine(4);

	//Open arm
	openArm();
	wait1Msec(3000);
	while(getUSDistance(S1) > 7.5){
		setMotorSync(motorA,motorB,0,20);
	}
	stopMotors();
	//Close arm
	closeArm();

	//Stop 5------------------------------------------
	//stage3();
	turnDeg(150);
	//setMotorTarget(motorB, 1000, 40);
	//wait1Msec(1000);
	JumpLine(5);

	//Drive to line
	setMotorSync(motorA, motorB, 0, 40);
	while(getColorReflected(S2) > white){
		wait1Msec(10);
	}
	stopMotors();

	lfToBlack(blackLine, right);

	//Stop 6 (Efter vippe)
	JumpLine(1);
	lfToBlack(blackLine, right);
	//---------------------------------------------------

}
