
//First section with different tracks
void Stage1(){
	//Stop 1
	lfToBlack(blackLine, left);

	//Switch tracks
	setMotorSync(motorA, motorB, -100, 20);
	wait1Msec(300);
	stopMotors();
	JumpLine(2);
	lfToBlack(55, left);

	setMotorSync(motorA, motorB, 100, 20);
	wait1Msec(200);
	stopMotors();

	//Stop 2
	lfToBlack(blackLine, left);

	//Switch tracks
	setMotorSync(motorA, motorB, 100, 20);
	wait1Msec(300);
	stopMotors();
	JumpLine(2);
	lfToBlack(55, left);
	setMotorSync(motorA, motorB, -100, 20);
	wait1Msec(250);
	stopMotors();
}

//Second section - pick up bottle
void Stage2(){
	//Stop 3
	//Make the turn with slower speed
	lfToBlackSpeed(blackLine, right, 30);
	
	//Drive to turn
	JumpLine(3);
	wait1Msec(2000);


	setMotorTarget(motorB, 100, -30);
	wait1Msec(1000);

	//Stop 4 (Bottle)
	//Drive to bottle

	//In this section it should run closer to the middle
	int oldlineFollowTarget = lineFollowTarget;
	lineFollowTarget = 50;
	
	while(getUSDistance(S1) > 5.5){
		lineFollower(0.7, left,15);
	}
	stopMotors();
	lineFollowTarget = oldlineFollowTarget;

	//At arm
	closeArm();

	//Driver over blue dot
	JumpLine(3);

	//Drive until black line, without linefollow
	while(getColorReflected(S2) > blackLine){
		setMotorSync(motorA, motorB, 0, 20);
	}
	stopMotors();

	//Open arm
	openArm();
	wait1Msec(3000);

	while(getUSDistance(S1) > 6){
		setMotorSync(motorA,motorB,0,10);
	}

	stopMotors();

	//Close arm
	closeArm();
}

void Stage3(){
	//Stop 5

	//Go back
	setMotorSync(motorA, motorB,0,-40);
	wait1Msec(1700);

	//Turn back to line
	setMotorTarget(motorB, 1000, 40);
	wait1Msec(800);

	stopMotors();
	
	//Go to first black. But make it extra sensitive, as the bottle is pulling to sensor closer to the ground
	lfToBlackSpeed(blackLine + 5, right, 30);

	//Jump over black line
	JumpLine(2);
	
	//Continue
	lfToBlackSpeed(blackLine + 5, right, 30);
}

void Stage4(){
	
	lfToBlack(blackLine, right);
	stopMotors();

	wait1Msec(1000);

	//Drive til end of line
	//The constant 5000, is an estimate. Precision is not a important here. 
	for(int a = 0; a < 5000; a++){
		lineFollower(0.7, right, 40);
	}
	stopMotors();

	//Turn 90 deg
	setMotorTarget(motorB, 1000, 40);
	wait1Msec(400);

	//Forward
	JumpLine(3);

	//Turn back
	setMotorTarget(motorB, 1000, -40);
	wait1Msec(450);

	//Take the turn slowly
	lfToBlackSpeed(blackLine,right, 30);
}

void Stage5(){
	//turn to bullseye
	JumpLine(4);
	setMotorTarget(motorB, 100, 40);
	wait1Msec(600);

	//Drive to bottle
	lfToBlack(blackLine, left);
	JumpLine(8);

	openArm();
	
	//Wait til arm open
	waitUntilMotorStop(motorC);

	//Drive back
	setMotorSync(motorA,motorB,0,-40);
	wait1Msec(4300);
	stopMotors();

	//Turn to line
	setMotorSync(motorA, motorB, 100, -20);
	wait1Msec(700);

	JumpLine(2);
	openArm();
	lfToBlack(blackLine, right);
}

//If r is true, it is the first of the bottle stages.
void Stage6(bool r){

	JumpLine(1);

	//Turn away from bottle
	if(r){
		moveMotorTarget(motorB, 200, 20);

		waitUntilMotorStop(r ? motorB : motorA);
	}else{
		setMotorSpeed(motorA, 20);
		wait1Msec( 1000);
		stopMotors();
	}

	JumpLine(7);

	//Turn back
	moveMotorTarget(r ? motorA : motorB, 340,  30);
	waitUntilMotorStop(r ? motorA: motorB);

	//Drive to line
	setMotorSync(motorA, motorB, 0, 20);
	while(getColorReflected(S2) > white) { }

	if(r) {


		stopMotors();
		playTone(440, 30);
		//Turn towards line
		setMotorSpeed(r ? motorB : motorA, 40);
		while(getColorReflected(S2) < white + 5) {}

	}else {
		//Drive to other side of line
		while(getColorReflected(S2) < white + 5) { }

		stopMotors();

		//Turn towards line
		playTone(440, 30);
		setMotorSpeed(r ? motorB : motorA, 20);
		while(getColorReflected(S2) > white) {}
	}
	stopMotors();

	playTone(550, 30);
	lfToBlackSpeed(blackline, r, 30);
}

void Stage7(){
	JumpLine(9);

	//Turn to wall
	setMotorSyncEncoder(motorA, motorB, 100, 80, 10);
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);

	//Drive closer
	while ( getUSDistance(S1) > 15 ) {
		setMotorSync(motorA, motorB, 0, 20);
	}
	stopMotors();

	//Turn back to exit
	setMotorSyncEncoder(motorA, motorB, 100, 190, 40);
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);

	//Drive backwards out
	setMotorSync(motorA, motorB, 0, -40);
	wait1Msec(2600);
	stopMotors();

	//Turn back
	setMotorSyncEncoder(motorA, motorB, -100, 150,  20);
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);

	//Drive to line
	setMotorSync(motorA, motorB, 0, 20);
	while(getColorReflected(S2) > white) { }
	stopMotors();
	playTone(440, 30);

	//Turn to line
	setMotorSync(motorA, motorB, -100, 20);
	while(getColorReflected(S2) < white + 5) {}
	stopMotors();

	playTone(550, 30);

	lfToBlack(blackline, right);

}

void Stage9(){
	JumpLine(2);

	//Drive to outer line
	setMotorSpeed(motorB,40);
	wait1Msec(600);
	stopMotors();

	JumpLine(1);

	setMotorSpeed(motorA,40);
	wait1Msec(800);
	stopMotors();

	//Drive to end and count
	int counter = 0;
	while(getUSDistance(S1)>10){
		lineFollower(0.8,left,40);
		counter++;
	}
	stopMotors();
	
	//Go back
	setMotorSync(motorA, motorB, 0, -20);
	wait1Msec(700);

	playTone(440, 15);
	
	//Turn arround
	setMotorSyncEncoder(motorA, motorB, 100, 300, 20);
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);
	stopMotors();

	counter -= 1500;
	//Drive back
	for(int a = 0; a < counter/2; a++){
		lineFollower(0.8,right,40);
	}
	playTone(550, 15);



}
