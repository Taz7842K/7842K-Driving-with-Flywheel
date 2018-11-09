#include "main.h"
#include "MotorConfig.h"

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
  Joystickch4 = JoystickMain.get_analog(ANALOG_LEFT_X);
  Joystickch2 = JoystickMain.get_analog(ANALOG_RIGHT_Y);

    MoveMotors(Joystickch4 + Joystickch2, Joystickch4 - Joystickch2);

      pros::delay(20);
  }

}

void MoveMotors(int rightspeed, int leftspeed)
{

 m_LeftFront.move(rightspeed);
 m_RightFront.move(leftspeed);
 m_LeftRear.move(rightspeed);
 m_RightRear.move(leftspeed);

}
