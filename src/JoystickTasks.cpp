#include "main.h"
#include "MainConfig.h"

int Joystickch4;
int Joystickch2;



pros::Motor m_LeftFront(7);
pros::Motor m_LeftRear(18);
pros::Motor m_RightFront(11);
pros::Motor m_RightRear(20);


void MoveMotors(int, int);

void Joystickcontroltask(void*)
{
 while (true)
 {

  if(baseControlTaskOn)
  {
    Joystickch4 = JoystickMain.get_analog(ANALOG_LEFT_X);
    Joystickch2 = JoystickMain.get_analog(ANALOG_RIGHT_Y);

    MoveMotors(Joystickch2 + Joystickch4, Joystickch2 - Joystickch4);

   }
   else
   {

   }

   pros::delay(20);

 }
}

void MoveMotors(int rightspeed, int leftspeed)
{


 m_LeftFront.move(rightspeed*1);
 m_RightFront.move(leftspeed*1);
 m_LeftRear.move(rightspeed*1);
 m_RightRear.move(leftspeed*1);

}
