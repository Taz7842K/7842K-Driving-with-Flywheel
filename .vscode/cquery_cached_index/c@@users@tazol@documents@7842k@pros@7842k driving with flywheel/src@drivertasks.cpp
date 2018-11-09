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

void FlywheelControlTask(void*){
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
pros::Motor m_LeftFront(7);
pros::Motor m_LeftRear(18);
pros::Motor m_RightFront(11);
pros::Motor m_RightRear(20);

pros::Motor m_Flywheel(5);

pros::Motor m_Intake(9);
pros::Motor m_Indexer(15);

pros::Motor m_Arm(14);

void MoveMotors(int rightspeed, int leftspeed){

 m_LeftFront.move(rightspeed);
 m_RightFront.move(leftspeed);
 m_LeftRear.move(rightspeed);
 m_RightRear.move(leftspeed);

}

void driverSimpleTask(void*)
{
 while(true)
 {
   if(JoystickMain.get_digital(DIGITAL_A))
   {
     m_Intake.move(115);
   }
   else if(JoystickMain.get_digital(DIGITAL_B))
   {
     m_Indexer.move(115);
     m_Intake.move(115);
   }
   else
   {
     m_Intake.move(0);
     m_Indexer.move(0);
   }


   if (JoystickMain.get_digital(DIGITAL_Y))
   {
     m_Arm.move(115);
   }
   else if (JoystickMain.get_digital(DIGITAL_X))
   {
     m_Arm.move(-115);
   }
   else
   {
     m_Indexer.move(0);
   }

   pros::delay(20);
 }
}
