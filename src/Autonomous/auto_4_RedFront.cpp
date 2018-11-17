#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"



void autonomous_4()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);
  okapi::ChassisControllerIntegrated chassis = ChassisControllerFactory::create( {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

  flywheelOn = true;// Turns on Flywheel

  chassis.setMaxVelocity(130);

  chassis.moveDistance(45_in);// Hit low flag
    pros::delay(200);
  chassis.moveDistance(-39_in);//move backward, in place to shoot flag
    pros::delay(200);

    chassis.setMaxVelocity(100);

  chassis.turnAngle(-15_deg);   //turn slightly to aim for flag
    pros::delay(200);

  intake.moveRelative(-1800,200);//run intake to shoot ball
  indexer.moveRelative(-1800,200);//run intake to shoot ball
      pros::delay(200);

    chassis.turnAngle(15_deg);   //turn back
          pros::delay(200);

  chassis.setMaxVelocity(130);

  flywheelOn = false;

  chassis.moveDistance(-32_in);//move backward, in line with platforms
    pros::delay(200);
  chassis.turnAngle(-90_deg);//turn to face platforms
    pros::delay(200);

  chassis.setMaxVelocity(200);

  chassis.moveDistance(60_in);//drive onto center platform
}
