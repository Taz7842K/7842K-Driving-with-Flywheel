#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"



void autonomous_5()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);
  okapi::ChassisControllerIntegrated chassis = ChassisControllerFactory::create( {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

bool flywheelOn = false;// Turns on Flywheel

  chassis.setMaxVelocity(130);

  intake.moveVelocity(-200);

  chassis.moveDistance(-45_in); //moves forward to knock cap over

    pros::delay(800);           //stops briefly to knock cap

  intake.moveVelocity(0);

  chassis.moveDistance(12_in);  //moves backward in place to turn
    pros::delay(200);
  chassis.turnAngle(-90_deg);   //turns to shoot flag
    pros::delay(200);

    flywheelOn = false;

  chassis.moveDistance(30_in);//drive onto center platform
}
