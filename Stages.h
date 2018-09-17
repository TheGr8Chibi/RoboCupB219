
//First section with different tracks
void stage1(){
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

	wait1Msec(600);
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

	JumpLine(4);

	//Open arm
	openArm();
	wait1Msec(3000);

	while(getUSDistance(S1) > 9){
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
wait1Msec(2000);
	setMotorTarget(motorB, 1000, 40);
	wait1Msec(600);
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
	wait1Msec(300);
	JumpLine(3);
	setMotorTarget(motorB, 1000, -40);
	wait1Msec(300);

	lfToBlack(blackLine,right);
}

void Stage5(){
	turnDeg(90);

	lfToBlack(blackLine, left);

}
