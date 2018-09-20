
//First section with different tracks
void Stage1(){
	//Stop 1
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(-30);
	JumpLine(2);
	lfToBlack(55, left);
	turnDeg(10);

	//Stop 2
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(30);
	JumpLine(2);
	lfToBlack(55, left);
	turnDeg(-10);
}

//Second section - pick up bottle
void Stage2(){
	//Stop 3
	lfToBlack(blackLine, right);
	JumpLine(3);
	wait1Msec(2000);

	//turnDeg(90);

	setMotorTarget(motorB, 100, -40);
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
	while(getColorReflected(S2) > 15){
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

	setMotorTarget(motorB, 100, -40);
	wait1Msec(700);
	JumpLine(2);

	lfToBlack(blackLine, right);
}

void Stage6(bool r){
	//SLET
	//lfToBlack(blackline, right);
	JumpLine(1);

	//Turn away from bottle
	setMotorSpeed(r ? motorB : motorA, 40);
	wait1Msec(r ? 500 : 500);
	stopMotors();
	JumpLine(7);

	//Turn back

	setMotorSpeed(r ? motorA : motorB,  40);
	wait1Msec(900);
	stopMotors();

	setMotorSync(motorA, motorB, 0, 20);
	while(getColorReflected(S2) > 55) { }
	if(r) {

		stopMotors();

		//Turn towards line
		setMotorSpeed(r ? motorB : motorA, 40);
		while(getColorReflected(S2) < 60) {}

	}else {
		while(getColorReflected(S2) < 60) { }
		//JumpLine(1);
		//Turn towards line
		setMotorSpeed(r ? motorB : motorA, 20);
		while(getColorReflected(S2) > 60) {}
	}
	stopMotors();
	lfToBlack(blackline, r);
}

void Stage7(){
	JumpLine(8);

	//Turn to wall
	setMotorSync(motorA, motorB, 100, 40);
	wait1Msec(200);
	stopMotors();

	//Drive closer
	while ( getUSDistance(S1) > 15 ) {
		setMotorSync(motorA, motorB, 0, 20);
	}
	stopMotors();

	//Turn back to exit
	setMotorSync(motorA, motorB, 100, 40);
	wait1Msec(510);
	stopMotors();

	//Drive backwards out
	setMotorSync(motorA, motorB, 0, -40);
	wait1Msec(2600);
	stopMotors();



	//Turn back
	setMotorSync(motorA, motorB, -100, 40);
	wait1Msec(500);
	stopMotors();

	setMotorSync(motorA, motorB, 0, 20);
	while(getColorReflected(S2) > 55) { }

	setMotorSync(motorA, motorB, -100, 40);
	while(getColorReflected(S2) < 55) {}
	stopMotors();

	lfToBlack(blackline, right);

}

void Stage8(){

	Stage6(-1);
}
