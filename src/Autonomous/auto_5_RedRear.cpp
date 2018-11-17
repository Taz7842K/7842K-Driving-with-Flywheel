#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"



void autonomous_5()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);
  okapi::ChassisControllerIntegrated chassis = ChassisControllerFactory::create( {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

  flywheelOn = true;// Turns on Flywheel

  chassis.setMaxVelocity(130);

  intake.moveVelocity(-200);

  chassis.moveDistance(-50_in); //moves forward to knock cap over

    pros::delay(800);           //stops briefly to knock cap

  intake.moveVelocity(0);

  chassis.moveDistance(47_in);  //moves backward in place to turn
    pros::delay(200);
  chassis.turnAngle(-90_deg);   //turns to shoot flag
    pros::delay(200);

  intake.moveRelative(-1800,200);//run intake to shoot ball
  indexer.moveRelative(-1800,200);//run intake to shoot ball
        pros::delay(500);

    flywheelOn = false;

  chassis.moveDistance(15_in);//move backward, in line with platforms
          pros::delay(200);
  chassis.turnAngle(-90_deg); //turn to face platforms
          pros::delay(200);

    chassis.setMaxVelocity(200);

  chassis.moveDistance(60_in);//drive onto center platform
}
