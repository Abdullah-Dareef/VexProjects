#pragma config(Sensor, I2C_1,  rightIEM,       sensorNone)
#pragma config(Sensor, I2C_2,  leftIEM,        sensorNone)
#pragma config(Motor,  port1,           rightSpinnerMotor, tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port6,            ,             tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,            ,             tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,            ,             tmotorVex393, openLoop)
#pragma config(Motor,  port9,            ,             tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftSpinnerMotor, tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Move Forward and Backward - 393 Motors
This program instructs your robot to move forward at half power for 1000 encoder counts, then reverse
at half power for 1000 encoder counts. There is a two second pause at the beginning of the program.

Robot Model(s): Modified Squarebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 1        rightMotor          393 Motor             Right side motor
Motor Port 10       leftMotor           393 Motor             Left side motor, Reversed
I2C_1               rightIEM            Integrated Encoder    Encoder mounted on rightMotor
I2C_2               leftIEM             Integrated Encoder    Encoted mounted on leftMotor
----------------------------------------------------------------------------------------------------*/

task main
{


		motor[port3] = 63;
		motor[port4]	= 63;
		wait1Msec(2000);
}
