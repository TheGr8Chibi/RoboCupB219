#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     color,          sensorEV3_Color)

//Line following
void lineFollower(int target, float multiplier){
	string t1;
	int col1 = getColorReflected(S2);
	sprintf(t1,"farve: %d", col1);
	displayCenteredBigTextLine(1,t1);

	int error = col1 - target;
	float difSpeed = error * multiplier;

	setMotorSync(motorA, motorB, difSpeed, 50);
}

//Stop motors
void stopMotors(){
	setMotorSync(motorA, motorB, 0, 0);
}

//Main program
task main()
{
	while(true){
		//Section 1
		while(getColorReflected(S2) > 15){
			lineFollower(40, 0.7);
		}
		stopMotors();

		//Drej
		setMotorTarget(motorB,5, 30);
		setMotorTarget(motorA,5, 30);
		setMotorTarget(motorA,5, 30);
		while(getColorReflected(S2) > 80){
			setMotorSync(motorA, motorB, 0, 50);
		}
		stopMotors();

		while(getColorReflected(S2) > 15){
			lineFollower(40, 0.7);
		}
	}
}
