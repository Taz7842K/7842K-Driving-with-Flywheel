#include "main.h"
#include "MainConfig.h"

pros::Motor m_LeftFront(7);
pros::Motor m_LeftRear(18);
pros::Motor m_RightFront(11);
pros::Motor m_RightRear(20);
pros::Motor m_Flywheel(10);
pros::Motor m_Intake(9);
pros::Motor m_Indexer(15);
pros::Motor m_Arm(14);

pros::Controller JoystickMain(pros::E_CONTROLLER_MASTER);

pros::ADIPotentiometer arm_lock('G');
int arm_limit = 350;

void setBasePower(int, int); //Forward Declaration For Base Moving

int FlywheelPower = 0;
bool flywheelOn = false;

void FlywheelControlTask(void*)
{
  while(true)
  {
    if(flywheelOn)
    {
      for(int FlywheelPower = 0;  FlywheelPower < 127 && flywheelOn; FlywheelPower+= 7)
      {
        m_Flywheel.move(FlywheelPower);
        pros::delay (50);
      }
      while(flywheelOn) {pros::delay(20);}
    }
    else
    {
      m_Flywheel.move(0);
    }
    pros::delay(20);
  }
}


  void driverSimpleTask(void*)
  {
    int Joystickch4;
    int Joystickch2;

    while(true)
    {

      int arm_position = arm_lock.get_value();

      if(simpleControlTaskOn)
      {
        if(JoystickMain.get_digital(DIGITAL_R2))      //Intake
        {
          m_Intake.move(-115);
        }

        else if(JoystickMain.get_digital(DIGITAL_R1)) //Intake and Indexer

        {
          m_Indexer.move(-115);
          m_Intake.move(-115);
        }

        else if(JoystickMain.get_digital(DIGITAL_L2))//Intake and Indexer Reverse

        {
          m_Indexer.move(115);
          m_Intake.move(115);
        }

        else if (JoystickMain.get_digital(DIGITAL_A))//On Flywheel
        {
          flywheelOn = true;
        }
        else if (JoystickMain.get_digital(DIGITAL_B))//Off Flywheel
        {
          flywheelOn = false;
        }

        else if (JoystickMain.get_digital(DIGITAL_Y) && arm_position > 350)//Arm Forward
        {
          m_Arm.move(-90);
        }

        else if (JoystickMain.get_digital(DIGITAL_X))//Arm Back
        {
          m_Arm.move(90);
        }

        else if(baseControlTaskOn)
        {
          Joystickch4 = JoystickMain.get_analog(ANALOG_LEFT_X);
          Joystickch2 = JoystickMain.get_analog(ANALOG_RIGHT_Y);

          setBasePower(Joystickch4 + Joystickch2, Joystickch4 - Joystickch2);
        }
        /*

        else if (JoystickMain.get_digital(DIGITAL_LEFT))//Arm to horiz position
        {
          m_Arm.move(115);
        }

        */

        else if (arm_position < arm_limit )       //arm lock
        {
          m_Arm.move(10);
        }



        else                                        //Motors off
        {
          m_Indexer.move(0);
          m_Intake.move(0);
          m_Arm.move(0);

        }
      }

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
