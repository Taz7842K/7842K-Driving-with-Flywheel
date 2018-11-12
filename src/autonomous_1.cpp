#include "main.h"
#include "MotorConfig.h"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
int a_distance;
void baseMove(void*);
int calcInches(int a_distance);

int calcInches(int a_distance)
{
    return a_distance * 900 * 0.079617834;
}

 void baseMove(int a_distance)
 {
   calcInches(a_distance);

 m_RightFront.move_relative(a_distance,100);
 m_RightRear.move_relative(a_distance,100);
 m_LeftRear.move_relative(a_distance,100);
 m_LeftFront.move_relative(a_distance,100);
 }

void autonomous_1()
{
  baseMove(1);
  void turnangle(double idegtarget);
}
