//FUNCTIONS -------------------------------------------------------------------------------------------------------------------------------------------
//Line following, if side true go on right

//Stop motors
void stopMotors(){
	setMotorSync(motorA, motorB, 0, 0);
}


void lineFollower(float multiplier, bool side, int speed){
	string t1;
	int col1 = getColorReflected(S2);
	sprintf(t1,"farve: %d", col1);
	displayCenteredBigTextLine(1,t1);

	int error = (lineFollowTarget - col1) * (side ? -1: 1);
	float difSpeed = error * multiplier;

	setMotorSync(motorA, motorB, difSpeed, speed);
}

void lfToBlack(int threshold, bool side){
	//Linefollow intil it reads black
	while(getColorReflected(S2) > threshold){
		//Values for following the yellow lines
		lineFollower(0.7, side,40);
	}
	stopMotors();
}

void turnDeg(int deg){
	resetGyro(S3);
	int meas = getGyroHeading(S3);
	int error = meas - deg;
	while( error != 0 ){
		//Turn the car(Speed it up later)
		setMotorSync(motorA, motorB, 100 * ( error < 0 ? 1 : -1 ), 20);
		meas = getGyroHeading(S3);

		string t1;
		sprintf(t1,"farve: %d", error);
		displayCenteredBigTextLine(1,t1);
		error = meas - deg;
	}
	stopMotors();
}


//Drive over black line
void JumpLine(int times){
	setMotorSync(motorA, motorB, 0, 40);
	wait1Msec(200*times);
	stopMotors();
}

void closeArm(){
	setMotorTarget(motorC,2000,40);
	wait1Msec(2800);
}

void openArm(){
	setMotorTarget(motorC,-100,40);
	wait1Msec(1300);
}
