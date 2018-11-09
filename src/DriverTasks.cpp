#include "main.h"
#include "MotorConfig.h"

int FlywheelPower;

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
      for(int FlywheelPower = 0;  FlywheelPower < 127 && flywheelOn; FlywheelPower++)
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
      if(JoystickMain.get_digital(DIGITAL_R2))
      {
        m_Intake.move(-115);
      }

      else if(JoystickMain.get_digital(DIGITAL_R1))

      {
        m_Indexer.move(-115);
        m_Intake.move(-115);
      }

      else if (JoystickMain.get_digital(DIGITAL_Y))
      {
        m_Arm.move(115);
      }

      else if (JoystickMain.get_digital(DIGITAL_X))
      {
        m_Arm.move(-115);
      }

      else if (JoystickMain.get_digital(DIGITAL_A))
      {
        flywheelOn = true;
      }
      else if (JoystickMain.get_digital(DIGITAL_B))
      {
        flywheelOn = false;
      }

      else
      {
        m_Indexer.move(0);
        m_Intake.move(0);
        m_Arm.move(0);
      }

      pros::delay(20);
    }
  }
