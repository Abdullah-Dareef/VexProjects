#pragma config(Sensor, I2C_1,  rightEncoder,   sensorNone)
#pragma config(Sensor, I2C_2,  leftEncoder,    sensorNone)
#pragma config(Motor,  port1,           rightArm2,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           leftFrontDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           leftBackDrive, tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightFrontDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           rightBackDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm2,      tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftArm1,      tmotorVex393, openLoop)
#pragma config(Motor,  port8,           rightIntake,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           leftIntake,    tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightArm1,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
			motor[rightBackDrive]  = speed;
			motor[leftBackDrive]   = speed;
			motor[rightFrontDrive] = speed;
			motor[leftFrontDrive]  = speed;
		}

		//If the right encoder is greater than the left encoder (veering to the left)
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{
			//Adjust the robot slightly to the right
			motor[rightBackDrive]  = speed;
			motor[leftBackDrive]   = speed+5;
			motor[rightFrontDrive] = speed;
			motor[leftFrontDrive]  = speed+5;
		}

		//If the left encoder is greater than the right encoder (veering to the right)
		else if(SensorValue[rightEncoder] < SensorValue[leftEncoder])
		{
			//Adjust the robot slightly to the right
			motor[rightBackDrive]  = speed+5;
			motor[leftBackDrive]   = speed;
			motor[rightFrontDrive] = speed+5;
			motor[leftFrontDrive]  = speed;
		}
	}

	//Stop the robot
			motor[rightBackDrive]  = 0;
			motor[leftBackDrive]   = 0;
			motor[rightFrontDrive] = 0;
			motor[leftFrontDrive]  = 0;
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
			motor[rightBackDrive]  = speed;
			motor[leftBackDrive]   = -speed;
			motor[rightFrontDrive] = speed;
			motor[leftFrontDrive]  = -speed;
	}

	//Stop the robot
	motor[rightBackDrive]  = 0;
	motor[leftBackDrive]   = 0;
	motor[rightFrontDrive] = 0;
	motor[leftFrontDrive]  = 0;
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
		motor[rightBackDrive]  = -speed;
			motor[leftBackDrive]   = speed;
			motor[rightFrontDrive] = -speed;
			motor[leftFrontDrive]  = speed;
	}

	//Stop the robot
	motor[rightBackDrive]  = 0;
			motor[leftBackDrive]   = 0;
			motor[rightFrontDrive] = 0;
			motor[leftFrontDrive]  = 0;
}

task moveArm()
{
	motor[leftArm1]= 127;
	motor[rightArm1]= 127;
	motor[leftArm2]= 127;
	motor[rightArm2]= 127;
	wait1Msec(1000);
	motor[leftArm1]= 0;
	motor[rightArm1]= 0;
	motor[leftArm2]= 0;
	motor[rightArm2]= 0;

//	wait1Msec(500);
//	motor[leftArmMotor]= 0;
//	motor[rightArmMotor]= 0;

}

task downArm()
{
	motor[leftArm1]= -125;
	motor[rightArm1]= -125;
	motor[leftArm2]= -125;
	motor[rightArm2]= -125;
	wait1Msec(1000);
		motor[leftArm1]= 0;
	motor[rightArm1]= 0;
	motor[leftArm2]= 0;
	motor[rightArm2]= 0;
//	wait1Msec(500);
//	motor[leftArmMotor]= 0;
//	motor[rightArmMotor]= 0;

}

void moveBackward()
{
		motor[rightBackDrive]  = -127;
		motor[leftBackDrive]   = -127;
		motor[rightFrontDrive] = -127;
		motor[leftFrontDrive]  = -127;
		wait1Msec(2100);
}

void intake()
{
	motor[leftIntake]= 127;
	motor[rightIntake]= 127;
	wait1Msec(5000);
}


task main()
{
		//Move the robot forward for 1000 encoder counts
	//at a speed of 50, then wait for half of a second
//	intake();
	StartTask(moveArm);
	turnRight(130,127);
	moveForward(1450, 127);
//	wait1Msec(500);

	//Turn the robot to the right for 285 encoder counts
	//at a speed of 25, then wait for half of a second
//	turnRight(370, 25);
	moveBackward();
	//wait1Msec(500);
	//Turn the robot to the left for 285 encoder counts
	//at a speed of 25, then wait for half of a second
	StartTask(downArm);
	turnLeft(145, 127);
//	wait1Msec(500);
	moveForward(1800,127);
	turnRight(214,127);
	StartTask(moveArm);
	moveForward(350,127);
	motor[leftIntake] = 70;
	motor[rightIntake] = 70;
	wait1Msec(2000);




}
