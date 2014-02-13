
int normalizeAccelerometer(char axis)
{
	//int nBiasValues[3];
 // nBiasValues[0] = SensorValue[xAxis];
 // nBiasValues[1] = SensorValue[yAxis];
 // nBiasValues[2] = SensorValue[zAxis];

  switch (axis)
  {
  	case 'x':
  		return SensorValue[xAxis] - nBiasValues[0];
  	case 'y':
  		return SensorValue[yAxis] - nBiasValues[1];
  	case 'z':
  		return SensorValue[zAxis] - nBiasValues[2];
  }
  return 9001;

}

void moveForward(int encoderCounts, int speed)
{
	//Clear the encoders before using them
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;

	//While both of the encoders are less than the specified amount
	while(SensorValue[rightEncoder] < encoderCounts && SensorValue[leftEncoder] < encoderCounts)
	{
		//If the two encoder values are equal
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{
			//Move the robot forward at the specified speed
			motor[rearRightMotor]  = speed;
			motor[rearLeftMotor]   = speed;
			motor[frontRightMotor] = speed;
			motor[frontLeftMotor]  = speed;
		}

		//If the right encoder is greater than the left encoder (veering to the left)
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{
			//Adjust the robot slightly to the right
			motor[rearRightMotor]  = speed;
			motor[rearLeftMotor]   = speed+5;
			motor[frontRightMotor] = speed;
			motor[frontLeftMotor]  = speed+5;
		}

		//If the left encoder is greater than the right encoder (veering to the right)
		else if(SensorValue[rightEncoder] < SensorValue[leftEncoder])
		{
			//Adjust the robot slightly to the right
			motor[rearRightMotor]  = speed+5;
			motor[rearLeftMotor]   = speed;
			motor[frontRightMotor] = speed+5;
			motor[frontLeftMotor]  = speed;
		}
	}

	//Stop the robot
	motor[rearRightMotor]  = 0;
	motor[rearLeftMotor]   = 0;
	motor[frontRightMotor] = 0;
	motor[frontLeftMotor]  = 0;
}

//Turn the robot left for the specified encoder counts
//at a specified speed
void turnLeft(int encoderCounts, int speed)
{
	//Clear the encoders before using them
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;

	//While the absolute value of the right motor's encoder is less
	//than the specified amount
	while(abs(SensorValue[rightEncoder]) < encoderCounts)
	{
		//Turn the robot to the left at the specified speed
		motor[rearRightMotor]  = speed;
		motor[rearLeftMotor]   = -speed;
		motor[frontRightMotor] = speed;
		motor[frontLeftMotor]  = -speed;
	}

	//Stop the robot
	motor[rearRightMotor]  = 0;
	motor[rearLeftMotor]   = 0;
	motor[frontRightMotor] = 0;
	motor[frontLeftMotor]  = 0;
}

//Turn the robot left for the specified encoder counts
//at a specified speed
void turnRight(int encoderCounts, int speed)
{
	//Clear the encoders
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;

	//While the absolute value of the left motor's encoder is less
	//than the specified amount
	while(abs(SensorValue[leftEncoder]) < encoderCounts)
	{
		//Turn the robot to the right at the specified speed
		motor[rearRightMotor]  = -speed;
		motor[rearLeftMotor]   = speed;
		motor[frontRightMotor] = -speed;
		motor[frontLeftMotor]  = speed;
	}

	//Stop the robot
	motor[rearRightMotor]  = 0;
	motor[rearLeftMotor]   = 0;
	motor[frontRightMotor] = 0;
	motor[frontLeftMotor]  = 0;
}

task moveArm()
{
	while(SensorValue[armPot]<2000)
{
	motor[leftArmMotor]= 175;
	motor[rightArmMotor]= 175;
}
	motor[leftArmMotor]= 0;
	motor[rightArmMotor]= 0;
//	wait1Msec(500);
//	motor[leftArmMotor]= 0;
//	motor[rightArmMotor]= 0;

}

task downArm()
{
	motor[leftArmMotor]= -175;
	motor[rightArmMotor]= -175;
	wait1Msec(1000);

	motor[leftArmMotor]= 0;
	motor[rightArmMotor]= 0;
//	wait1Msec(500);
//	motor[leftArmMotor]= 0;
//	motor[rightArmMotor]= 0;

}

void moveBackward()
{
		motor[rearRightMotor]  = -127;
		motor[rearLeftMotor]   = -127;
		motor[frontRightMotor] = -127;
		motor[frontLeftMotor]  = -127;
		wait1Msec(2100);
}

void intake()
{
	motor[leftClawMotor]= 127;
	motor[rightClawMotor]= 127;
	wait1Msec(5000);
}
