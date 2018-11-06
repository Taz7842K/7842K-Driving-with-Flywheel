#include "main.h"
#include "MotorConfig.h"
/**
* Runs the operator control code. This function will be started in its own task
* with the default priority and stack size whenever the robot is enabled via
* the Field Management System or the VEX Competition Switch in the operator
* control mode.
*
* If no competition control is connected, this function will run immediately
* following initialize().
*
* If the robot is disabled or communications is lost, the
* operator control task will be stopped. Re-enabling the robot will restart the
* task, not resume it from where it left off.
*/
void FlywheelControl(void*);
void Joystickcontroltask(void*);
void driverSimpleTask(void*);

void opcontrol()
{
pros::Task FlywheelControl_1(FlywheelControl, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "FlywheelTask" );
pros::Task BaseControl_1(Joystickcontroltask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Joystickcontroltask" );
pros::Task SimpleControls_1(driverSimpleTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "SimpleContols" );


}
