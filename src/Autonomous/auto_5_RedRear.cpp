#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"

bool flywheelOn = true;

void autonomous_5()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);
  okapi::ChassisControllerIntegrated chassis = ChassisControllerFactory::create( {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

bool flywheelOn = false;// Turns on Flywheel

  chassis.setMaxVelocity(130);

  intake.moveVelocity(-200);

  chassis.moveDistance(-39_in); //moves forward to knock cap over

    pros::delay(800);           //stops briefly to knock cap

  intake.moveVelocity(0);

  chassis.moveDistance(2_in);  //moves backward in place to turn
    pros::delay(200);
  chassis.turnAngle(-90_deg);   //turns to shoot flag
    pros::delay(200);

    flywheelOn = false;

  chassis.moveDistance(36_in);//drive onto center platform
}
