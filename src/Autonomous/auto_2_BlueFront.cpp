#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"

bool flywheelOn = true;

void autonomous_2()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);
  okapi::ChassisControllerIntegrated chassis = ChassisControllerFactory::create( {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

  chassis.setMaxVelocity(150);
    pros::delay(100);

    flywheelOn = true;

  chassis.moveDistance(47_in);// Hit low flag
    pros::delay(100);
  chassis.moveDistance(-32_in);//move backward, in place to shoot flag
    pros::delay(100);

    chassis.setMaxVelocity(100);
      pros::delay(100);

  chassis.turnAngle(7_deg);   //turn slightly to aim for flag
    pros::delay(100);

  intake.moveRelative(-1800,200);//run intake to shoot ball
  indexer.moveRelative(-1800,200);//run indexer to shoot ball
      pros::delay(300);

    chassis.turnAngle(-7_deg);   //turn back
          pros::delay(100);

  chassis.setMaxVelocity(150);
    pros::delay(100);

  flywheelOn = false;

  chassis.moveDistance(-20_in);   //badk up
    pros::delay(100);

  chassis.turnAngle(-89_deg);    //turn towards red side
    pros::delay(100);

  intake.moveVelocity(-115);     //start intake
    pros::delay(100);

    flywheelOn = true;

  chassis.moveDistance(-33_in);    // go towards center coutr
    pros::delay(100);



  chassis.turnAngle(107_deg);      //turn towards flag
  pros::delay(100);

  intake.moveVelocity(0);

  chassis.moveDistance(10_in);
    pros::delay(100);

  intake.moveRelative(-1800,200);//run intake to shoot ball
  indexer.moveRelative(-1800,200);//run indexer to shoot ball
      pros::delay(1000);

      flywheelOn = false;

/*
  chassis.moveDistance(-32_in);//move backward, in line with platforms
    pros::delay(200);
  chassis.turnAngle(90_deg);//turn to face platforms
    pros::delay(200);

  chassis.setMaxVelocity(200);

  chassis.moveDistance(60_in);//drive onto center platform
*/
}
