#include "main.h"
#include "MainConfig.h"


//--------------Initialize--------------------------------------------
void autonomous_2();
void autonomous_3();
void autonomous_4();
void autonomous_5();
void autonomous_6();

void FlywheelControlTask(void*);
void Joystickcontroltask(void*);
void driverSimpleTask(void*);



bool simpleControlTaskOn = false;

bool baseControlTaskOn = false;

void initialize()
{
pros::Task FlywheelControl_1(FlywheelControlTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "FlywheelTask" );
pros::Task BaseControl_1(Joystickcontroltask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Joystickcontroltask" );
pros::Task SimpleControls_1(driverSimpleTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "SimpleControls" );
}
// -------------Initialize---------------------------------------------

//--------------Disabled-----------------------------------------------
void disabled() {}
//--------------Disabled-----------------------------------------------

//--------------Competition Initialize---------------------------------
void competition_initialize() {}
//--------------Competition Initialize---------------------------------

//--------------Autonomous---------------------------------------------
void autonomous()
{
/*

  pros::ADIPotentiometer auto_switch('H');

  int a_s = auto_switch.get_value();

  if(a_s < 600)
  {
    autonomous_2();
  }

  else if(a_s > 600 && a_s < 1400)
  {
    autonomous_3();
  }

  else if(a_s > 1400 && a_s < 2300)
  {
    autonomous_4();
  }

  else if (a_s > 2300 && a_s < 3400)
  {
    autonomous_5();
  }

  else if (a_s > 3400 && a_s < 4095)
  {
    autonomous_6();
  }

*/



autonomous_6();


}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------


void opcontrol()
{
  baseControlTaskOn = true;
  simpleControlTaskOn = true;
}
//------------opControl------------------------------------------------
