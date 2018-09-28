//FUNCTIONS

//Stop motors
void stopMotors(){
	setMotorSync(motorA, motorB, 0, 0);
	setMotorSpeed(motorC,0);
}

//Line following, if side true go on right
void lineFollower(float multiplier, bool side, int speed){

	string t1;
	//Read from sensor
	int col1 = getColorReflected(S2);
	
	//Print to screen
	sprintf(t1,"farve: %d", col1);
	displayCenteredBigTextLine(1,t1);

	//Calculate error, and add side multiplier(-1 og 1)
	int error = (lineFollowTarget - col1) * (side ? -1: 1);
	//Multiply with multiplier
	float difSpeed = error * multiplier;

	//Set motors
	setMotorSync(motorA, motorB, difSpeed, speed);
}

void lfToBlackSpeed(int threshold, bool side, int speed){
	//Linefollow intil it reads black
	while(getColorReflected(S2) > threshold){
		//Values for following the yellow lines
		lineFollower(0.7, side,speed);
	}
	stopMotors();
}

//For backwardscompatability with other code
void lfToBlack(int threshold, bool side){
	lfToBlackSpeed(threshold, side, 40);
}

//Drive over black line
void JumpLine(int times){
	setMotorSync(motorA, motorB, 0, 40);
	wait1Msec(200*times);
	stopMotors();
}

//Close the arm
void closeArm(){
	setMotorTarget(motorC,2000,40);
	wait1Msec(2800);
	stopMotors();
}

//Open the arm
void openArm(){
	setMotorTarget(motorC,-2000,40);
	wait1Msec(2700);
	stopMotors();
}

//Quarternote fn
const int qn = 400;
//Eighthnote hn
const int en = 200;
//1/16 qn
const int sn = 100;
const int f5 = 698;
const int c6 = 1047;
const int b5 = 988;
const int gh5 = 831;
const int ch6 = 1109;
const int dh6 = 1245;

//Music array
int song[] = {
	f5,qn + en,
	c6,en,
	b5,sn,
	c6,sn,
	b5,sn,
	c6,sn,
	b5,en,
	c6,en,
	gh5,qn,
	f5,qn + en,
	f5,en,
	gh5,en,
	c6,en,
	ch6,qn,
	gh5,qn,
	ch6,qn,
	dh6,qn,
	c6,en,
	ch6,en,
	c6,en,
	ch6,en,
	c6,qn,};

//Play the sond array
void playMusic(){
	
	//Get size
	int numNotes = sizeof(song)/sizeof(int);

	//For every note
	for (int i = 0; i < numNotes ; i += 2){

		//Play
		playTone(song[i],song[i + 1]/10);
		wait1Msec(song[i + 1]);

	}
	wait1Msec(qn);
}
