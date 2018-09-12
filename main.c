#pragma config(Sensor, S1,     distance,       sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     color,          sensorEV3_Color)
#pragma config(Sensor, S3,     angle,          sensorEV3_Gyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "USTest.h"
//Variabler
int blackLine = 16;
int lineFollowTarget = 75;
bool right = true;
bool left = false;


void lineFollower(float multiplier,  bool side);
void stopMotors();
void lfToBlack(int threshold, bool side);
void lfToBlack(int threshold, bool side, int multiplier);
void turnDeg(int deg);
void JumpLine();

//Main program
task main()
{
	//Stop 1
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(-30);
	JumpLine();
	lfToBlack(55, left);
	turnDeg(40);

	//Stop 2
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(30);
	JumpLine();
	lfToBlack(55, left);
	turnDeg(-10);

	//Stop 3
	lfToBlack(blackLine, right);

	turnDeg(25);
	JumpLine();

	//Stop 4 (Bottle)
	//Drive to bottle
	while(getUSDistance(S1) > 7.5){
		lineFollower(0.7, true);
	}
	//Close arm
	closeArm();

	lfToBlack(blackLine, right,0.0);

	//Open arm
	openArm();

	//Close arm
	closeArm();

	//Stop 5
	turnDeg(-150);

	//Drive to line
	setMotorSync(motorA, motorB, 0, 40);
	while(getColorReflected(S2) > 90){
		wait1Msec(50);
	}
	stopMotors();
	turnDeg(20);
	lfToBlack(blackLine, right);

	//Stop 6 (Efter vippe)
	JumpLine();
	lfToBlack(blackLine, right);



}


//FUNCTIONS ----------------------------------------------------------------------------------------------------------------------------------------
//Line following, if side true go on right
void lineFollower(float multiplier, bool side){
	string t1;
	int col1 = getColorReflected(S2);
	sprintf(t1,"farve: %d", col1);
	displayCenteredBigTextLine(1,t1);

	int error = (lineFollowTarget - col1) * (side ? -1: 1);
	float difSpeed = error * multiplier;

	setMotorSync(motorA, motorB, difSpeed, 40);
}

void lfToBlack(int threshold, bool side){
	lfToBlack(threshold, side, 0.7);
}

//Follow the line until black marker
void lfToBlack(int threshold, bool side, int multiplier){
	//Linefollow intil it reads black
	while(getColorReflected(S2) > threshold){
		//Values for following the yellow lines
		lineFollower(multiplier, side);
	}
	stopMotors();
}

void turnDeg(int deg){
	resetGyro(S3);
	int meas = getGyroHeading(S3);
	int error = meas - deg;
	while( error > 1 || error < -1 ){
		//Turn the car(Speed it up later)
		setMotorSync(motorA, motorB, 100 * ( deg < 0 ? -1 : 1 ), 20);
		meas = getGyroHeading(S3);

		string t1;
		sprintf(t1,"farve: %d", error);
		displayCenteredBigTextLine(1,t1);
		error = meas - deg;
	}
	stopMotors();
}

//Stop motors
void stopMotors(){
	setMotorSync(motorA, motorB, 0, 0);
}

//Drive over black line
void JumpLine(){
	setMotorSync(motorA, motorB, 0, 40);
	wait1Msec(300);
	stopMotors();
}

void closeArm(){
setMotorTarget(motorC,1000,40);
wait1Msec(3000);
}

void openArm(){
	setMotorTarget(motorC,-500,40);
wait1Msec(3000);
}
