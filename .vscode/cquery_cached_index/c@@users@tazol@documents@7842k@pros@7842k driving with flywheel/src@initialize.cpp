#include "main.h"
#include "MotorConfig.h"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
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




void initialize() {






}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
