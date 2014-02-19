#pragma config(Sensor, in1,    leftLightSensor, sensorReflection)
#pragma config(Sensor, in2,    midLightSensor, sensorReflection)
#pragma config(Sensor, in3,    rightLightSensor, sensorReflection)
#pragma config(Sensor, in5,    armPot,         sensorPotentiometer)
#pragma config(Sensor, in6,    gyroSensor,     sensorGyro)
#pragma config(Sensor, in7,    leftClawPot,    sensorPotentiometer)
#pragma config(Sensor, in8,    rightClawPot,   sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port2,           frontRightMotor, tmotorVex393, PIDControl, encoder, encoderPort, dgtl1, 1000)
#pragma config(Motor,  port3,           frontLeftMotor, tmotorVex393, PIDControl, reversed, encoder, encoderPort, dgtl3, 1000)
#pragma config(Motor,  port4,           rearRightMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port5,           rearLeftMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           leftArmMotor,  tmotorVex393, openLoop)
#pragma config(Motor,  port7,           rightArmMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port8,           leftClawMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rightClawMotor, tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
This program is designed to give new programmers beginning code that allows their robots to move from
point to point on the gameboard. The program uses three functions: moveForward, turnRight, and turnLeft
to move around the gameboard.  Each of the functions accepts two paramenters: encoderCounts and speed.

Ballerbot - Basic Movement
- This program assumes that you are using the VEX Ballerbot in the VEX Toss Up Game.
- This program demonstrates basic movements (forward, turn left, turn right) that can be performed
with the Ballerbot using encoder-based programming.
----------------------------------------------------------------------------------------------------*/

//Function to move the robot forward for a specified amount of encoder counts
//at a specified speed

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

task main()
{
	//Move the robot forward for 1000 encoder counts
	//at a speed of 50, then wait for half of a second
//	intake();
	StartTask(moveArm);
	nLCDButtons;
	turnLeft(130,127);
	moveForward(1450, 127);
//	wait1Msec(500);

	//Turn the robot to the right for 285 encoder counts
	//at a speed of 25, then wait for half of a second
//	turnRight(370, 25);
	moveBackward();
//	wait1Msec(500);

	//Turn the robot to the left for 285 encoder counts
	//at a speed of 25, then wait for half of a second
	StartTask(downArm);
	turnLeft(145, 127);
//	wait1Msec(500);
	moveForward(1800,127);
	turnRight(214,127);
	StartTask(moveArm);
	moveForward(350,127);
}
