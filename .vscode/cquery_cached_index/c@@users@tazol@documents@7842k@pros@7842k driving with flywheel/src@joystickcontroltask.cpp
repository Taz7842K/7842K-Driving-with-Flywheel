#include "main.h"
#include "MotorConfig.h"


int Joystickch4;
int Joystickch2;



pros::Controller JoystickMain(pros::E_CONTROLLER_MASTER);

void MoveMotors(int, int);

void Joystickcontroltask(void*){

while (true){
  Joystickch4 = JoystickMain.get_analog(ANALOG_LEFT_X);
  Joystickch2 = JoystickMain.get_analog(ANALOG_RIGHT_Y);

MoveMotors(Joystickch4 + Joystickch2, Joystickch4 - Joystickch2);

pros::delay(20);
}

}

void FlywheelControl(void*){
  while(true)
  {


  	while(!JoystickMain.get_digital(DIGITAL_R2)) {pros::delay(20);} //Wait until button pressed

  	for(int FlywheelPower = 12; JoystickMain.get_digital(DIGITAL_A); FlywheelPower++)
  	{
  		m_Flywheel.move(FlywheelPower);

  		pros::delay(50);
  	}

  	m_Flywheel.move(0);
  }
}
