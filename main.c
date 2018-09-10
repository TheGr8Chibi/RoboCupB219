#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     color,          sensorEV3_Color)

task main()
{

	int col1;
	string t1;
	int target = 60;
	int error;
	float multiplier = 0.3;
	float targetSpeed;

	while(true){
		col1 = getColorReflected(S2);
		sprintf(t1,"farve: %d", col1);
		displayCenteredBigTextLine(1,t1);

		error = col1 - target;
		targetSpeed = error * multiplier;

		setMotorSync(motorA, motorB, targetSpeed, 50);


	}

}
