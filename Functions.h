//FUNCTIONS
//Line following, if side true go on right

//Stop motors
void stopMotors(){
	setMotorSync(motorA, motorB, 0, 0);
	setMotorSpeed(motorC,0);
}


void lineFollower(float multiplier, bool side, int speed){
	string t1;
	//Read from sensor
	int col1 = getColorReflected(S2);
	sprintf(t1,"farve: %d", col1);
	displayCenteredBigTextLine(1,t1);

	//Calculate error, and add side multiplier(-1 og 1)
	int error = (lineFollowTarget - col1) * (side ? -1: 1);
	//Multiply with multiplier
	float difSpeed = error * multiplier;

	//Set motors
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
	stopMotors();
}

void openArm(){
	setMotorTarget(motorC,-2000,40);
	wait1Msec(2800);
	stopMotors();
}
/*C,D,E,F,G,A,B*/
float notes[] = {523.25,587.33,659.25,698.46,783.99,880,987.77};
/*Db,D#,F,F#,G#,A#,C*/
float n[] = { 277.18*2, 311.13*2, 349.23*2, 369.99*2, 415.30*2, 466.16*2, 523.25*2};
float time[] = {75, 37,19,9};
void play(bool run){
	int t = 15;
	while(run = true){
		int rnd = random(4);
		t = 10 + random(20);
		playTone(notes[rnd],15);
		//	delay(t*10);
	}

}

void play1(){

	const int fn = 400;
	const int hn = 200;
	const int qn = 100;
	const int f5 = 698;
	const int c6 = 1047;
	const int b5 = 988;
	const int gh5 = 831;
	const int ch6 = 1109;
	const int dh6 = 1245;

	int song[] = {
		f5,fn + hn,
		c6,hn,
		b5,qn,
		c6,qn,
		b5,qn,
		c6,qn,
		b5,hn,
		c6,hn,
		gh5,fn,
		f5,fn + hn,
		f5,hn,
		gh5,hn,
		c6,hn,
		ch6,fn,
		gh5,fn,
		ch6,fn,
		dh6,fn,
		c6,hn,
		ch6,hn,
		c6,hn,
		ch6,hn,
		c6,fn,};



	for (int i = 0; i < (sizeof(song)/sizeof(int)); i = i + 2){
		playTone(song[i],song[i + 1]/10);
		wait1Msec(song[i + 1]);

	}
	wait1Msec(fn);
}
