
//First part with different tracks
void stage1(){
	//Stop 1
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(-30);
	JumpLine(1);
	lfToBlack(55, left);
	turnDeg(30);

	//Stop 2
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(30);
	JumpLine(1);
	lfToBlack(55, left);
	turnDeg(-10);
}

//Lift first bottle
void stage2(){
	//Stop 3

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

	//Stop 5
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
}
