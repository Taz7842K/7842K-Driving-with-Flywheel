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
const int om_leftfront = -7;
const int om_leftrear = -18;
const int om_rightfront = 11;
const int om_rightrear = 20;

const int om_Intake = 9;
const int om_Indexer = 15;



const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 13.5_in;

void FlywheelControlTask(void*);

void autonomous_2()
{
    Motor intake(om_Intake);
    Motor indexer(om_Indexer);

  auto chassis = ChassisControllerFactory::create(
    {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
    AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

  flywheelOn = true;// Turns on Flywheel

  chassis.setMaxVelocity(130);

  chassis.moveDistance(43_in);// Hit low flag
    pros::delay(200);
  chassis.moveDistance(-37_in);//move backward, in place to shoot flag
    pros::delay(200);
  intake.moveRelative(-1800,200);//run intake to shoot ball
    pros::delay(200);
  indexer.moveRelative(-1800,200);//run intake to shoot ball
      pros::delay(200);

  flywheelOn = false;

  chassis.moveDistance(-32_in);//move backward, in line with platforms
    pros::delay(200);
  chassis.turnAngle(90_deg);//turn to face platforms
    pros::delay(200);
  chassis.moveDistance(30_in);//drive onto center platform
}
