
//First section with different tracks
void Stage1(){
	//Stop 1
	lfToBlack(blackLine, left);

	//Skift spor
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

	//Skift spor
	setMotorSync(motorA, motorB, 100, 20);
	wait1Msec(300);
	stopMotors();
	JumpLine(2);
	lfToBlack(55, left);
	setMotorSync(motorA, motorB, -100, 20);
	wait1Msec(200);
	stopMotors();
}

//Second section - pick up bottle
void Stage2(){
	//Stop 3
	lfToBlack(blackLine, right);
	JumpLine(3);
	wait1Msec(2000);

	//turnDeg(90);

	setMotorTarget(motorB, 100, -30);
	wait1Msec(1000);
	//Stop 4 (Bottle)
	//Drive to bottle
	int oldlineFollowTarget = lineFollowTarget;
	lineFollowTarget = 50;

	while(getUSDistance(S1) > 9){
		lineFollower(0.7, left,15);
	}
	stopMotors();
	lineFollowTarget = oldlineFollowTarget;
	//Close arm
	closeArm();
	JumpLine(3);
	while(getColorReflected(S2) > blackLine){
		setMotorSync(motorA, motorB, 0, 20);
	}
	stopMotors();

	//Open arm
	openArm();
	wait1Msec(3000);

	while(getUSDistance(S1) > 8){
		setMotorSync(motorA,motorB,0,10);
	}

	stopMotors();

	//Close arm
	closeArm();
}

void Stage3(){
	//Stop 5
	//	turnDeg(160);
	setMotorSync(motorA, motorB,0,-40);
	wait1Msec(1700);
	setMotorTarget(motorB, 1000, 40);
	wait1Msec(800);
	//JumpLine(5);

	//Drive to line
	//setMotorSync(motorA, motorB, 0, 40);
	//while(getColorReflected(S2) > white){
	//wait1Msec(10);
	//}
	stopMotors();

	lfToBlack(blackLine, right);

	//Stop 6 (Efter vippe)
	JumpLine(2);
	lfToBlack(blackLine, right);
}

void Stage4(){


	lfToBlack(blackLine, right);
	stopMotors();
	wait1Msec(1000);
	for(int a = 0; a < 5000; a++){
		lineFollower(0.7, right, 40);
	}
	stopMotors();


	setMotorTarget(motorB, 1000, 40);
	wait1Msec(400);
	JumpLine(3);
	setMotorTarget(motorB, 1000, -40);
	wait1Msec(450);

	lfToBlack(blackLine,right);
}

void Stage5(){
	//Drej hen p ålinje
	//turnDeg(90);
	JumpLine(4);
	setMotorTarget(motorB, 100, 40);
	wait1Msec(600);

	//Kør til flaske
	lfToBlack(blackLine, left);

	JumpLine(7);

	openArm();

	waitUntilMotorStop(motorC);

	setMotorSync(motorA,motorB,0,-40);
	wait1Msec(4300);

	stopMotors();

	setMotorSync(motorA, motorB, 100, -20);
	wait1Msec(700);
	JumpLine(2);
	closeArm();
	lfToBlack(blackLine, right);
}

void Stage6(bool r){
	//SLET
	//lfToBlack(blackline, right);
	JumpLine(1);

	//Turn away from bottle
	if(r){
		setMotorTarget(motorB, 200, 20);
		//wait1Msec(r ? 1000 : 1000);
		//stopMotors();

		waitUntilMotorStop(r ? motorB : motorA);
		}else{
		setMotorSpeed(motorA, 20);
		wait1Msec( 1000);
		stopMotors();
	}

	JumpLine(7);

	//Turn back
	if(r) {
		setMotorTarget(r ? motorA : motorB, r ? 400 : 500,  -30);
		//wait1Msec(r ? 1000 : 700);
		//stopMotors();
		waitUntilMotorStop(r ? motorA : motorB);
		} else{
		setMotorSpeed(motorB, 30);
		wait1Msec(700);
		stopMotors();
	}

	setMotorSync(motorA, motorB, 0, 20);
	while(getColorReflected(S2) > white) { }
	if(r) {


		stopMotors();
		playTone(440, 30);
		//Turn towards line
		setMotorSpeed(r ? motorB : motorA, 40);
		while(getColorReflected(S2) < white + 5) {}

		}else {
		while(getColorReflected(S2) < white + 5) { }

		stopMotors();

		//JumpLine(1);
		//Turn towards line
		playTone(440, 30);
		setMotorSpeed(r ? motorB : motorA, 20);
		while(getColorReflected(S2) > white) {}
	}
	stopMotors();

	playTone(550, 30);
	lfToBlack(blackline, r);
}

void Stage7(){
	JumpLine(9);

	//Turn to wall
	setMotorSyncEncoder(motorA, motorB, 100, 80, 10);
	//wait1Msec(540);
	//stopMotors();
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);

	//Drive closer
	while ( getUSDistance(S1) > 15 ) {
		setMotorSync(motorA, motorB, 0, 20);
	}
	stopMotors();

	//Turn back to exit
	setMotorSyncEncoder(motorA, motorB, 100, 180, 40);
	//wait1Msec(510);
	//stopMotors();
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);

	//Drive backwards out
	setMotorSync(motorA, motorB, 0, -40);
	wait1Msec(2600);
	stopMotors();



	//Turn back
	setMotorSyncEncoder(motorA, motorB, -100, 150,  20);
	//wait1Msec(520);
	//stopMotors();
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);

	setMotorSync(motorA, motorB, 0, 20);
	while(getColorReflected(S2) > white) { }
	stopMotors();
	playTone(440, 30);

	setMotorSync(motorA, motorB, -100, 20);
	while(getColorReflected(S2) < white + 5) {}
	stopMotors();

	playTone(550, 30);

	lfToBlack(blackline, right);

}

void Stage8(){

	Stage6(-1);
}

void Stage9(){
	JumpLine(2);

	setMotorSpeed(motorB,40);
	wait1Msec(600);
	stopMotors();

	JumpLine(1);

	setMotorSpeed(motorA,40);
	wait1Msec(600);
	stopMotors();

	int counter = 0;
	while(getUSDistance(S1)>10){
		lineFollower(0.8,left,40);
		counter++;
	}
	stopMotors();

	setMotorSync(motorA, motorB, 0, -20);
	wait1Msec(700);

	playTone(440, 15);

	setMotorSyncEncoder(motorA, motorB, 100, 300, 20);
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);
	stopMotors();

	//Drive back
	for(int a = 0; a < counter/2; a++){
		lineFollower(0.8,left,40);
	}
	playTone(550, 15);



}
