#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"



void autonomous_6()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);
  okapi::ChassisControllerIntegrated chassis = ChassisControllerFactory::create( {om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});

    flywheelOn = true;

      chassis.setMaxVelocity(130);

    intake.moveVelocity(-100);         //start intake
      pros::delay(200);

    chassis.moveDistance(49_in);      //move forward and flip cap
      pros::delay(200);

    intake.moveVelocity(0);           //stop intake
      pros::delay(200);

    chassis.moveDistance(-46_in);     //back up
      pros::delay(200);

    chassis.turnAngle(-90_deg);       // turn to face flag
      pros::delay(200);

    intake.moveVelocity(-100);        // run intake to shoot ball

      pros::delay(1000);

    chassis.moveDistance(49_in);     //move towards middle flag
      pros::delay(200);

    chassis.turnAngle(-90_deg);

    chassis.moveDistance(49_in);


}
