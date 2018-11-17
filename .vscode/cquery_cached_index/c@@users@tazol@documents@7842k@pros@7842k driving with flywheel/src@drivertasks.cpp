#include "main.h"
#include "MotorConfig.h"

int FlywheelPower = 0;
int armhold = 0;


pros::Motor m_Flywheel(10);

pros::Motor m_Intake(9);
pros::Motor m_Indexer(15);

pros::Motor m_Arm(14);


pros::Controller JoystickMain(pros::E_CONTROLLER_MASTER);

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
    while(true)
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

      else if (JoystickMain.get_digital(DIGITAL_Y))//Arm Forward
      {
        m_Arm.move(115);
      }

      else if (JoystickMain.get_digital(DIGITAL_X))//Arm Back
      {
        m_Arm.move(-115);
      }
      else if (JoystickMain.get_digital(DIGITAL_A))//On Flywheel
      {
        flywheelOn = true;
      }
      else if (JoystickMain.get_digital(DIGITAL_B))//Off Flywheel
      {
        flywheelOn = false;
      }

      else                                        //Motors off
      {
        m_Indexer.move(0);
        m_Intake.move(0);
        m_Arm.move(0);
      }

      pros::delay(20);

      }
    }

/*
  void armTask(void*)
  {
    while(1==1)

    }
  }
*/
