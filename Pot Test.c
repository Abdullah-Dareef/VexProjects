#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    ArmPot,         sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           ArmMotor,      tmotorVex393, PIDControl, encoder, encoderPort, I2C_1, 1000)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	while(1==1){
		if(vexRT[Btn6U] == 1)
	    {
	      while(SensorValue[ArmPot] < 4000){
	      	motor[ArmMotor]= 20;
	      }

	    }
	    else
	    {
	      motor[ArmMotor] = 0;
	    }

	    if(vexRT[Btn6D] == 1)
	    {
	      while(SensorValue[ArmPot] > 1500 ){
	      	motor[ArmMotor]=-20;
	      }
	  	}
	    else
	    {
	      motor[ArmMotor] = 0;
	    }
	}


}
