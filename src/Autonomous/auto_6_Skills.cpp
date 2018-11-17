#include "main.h"
#include "MainConfig.h"
#include "AutoConfig.h"

void autonomous_6()
{
  Motor intake(om_Intake);
  Motor indexer(om_Indexer);


    chassis->setMaxVelocity(150);
    pros::delay(100);

    flywheelOn = true;

    chassis->moveDistance(47_in);// Hit low flag
    pros::delay(100);
    chassis->moveDistance(-32_in);//move backward, in place to shoot flag
    pros::delay(100);

    chassis->setMaxVelocity(100);
    pros::delay(100);

    chassis->turnAngle(-7_deg);   //turn slightly to aim for flag
    pros::delay(100);

    intake.moveRelative(-1800,200);//run intake to shoot ball
    indexer.moveRelative(-1800,200);//run indexer to shoot ball
    pros::delay(300);

    chassis->turnAngle(7_deg);   //turn back
    pros::delay(100);

    chassis->setMaxVelocity(150);
    pros::delay(100);

    flywheelOn = false;

    chassis->moveDistance(-40_in);//move backward, in line with platforms
    pros::delay(200);
    chassis->turnAngle(-90_deg);//turn to face platforms
    pros::delay(200);

    chassis->setMaxVelocity(200);

    chassis->moveDistance(60_in * 1.25);//drive onto center platform























































    /*
    flywheelOn = true;

    chassis->setMaxVelocity(130);

    intake.moveVelocity(-100);         //start intake
    pros::delay(200);

    chassis->moveDistance(49_in);      //move forward and flip cap
    pros::delay(200);

    intake.moveVelocity(0);           //stop intake
    pros::delay(200);

    chassis->moveDistance(-46_in);     //back up
    pros::delay(200);

    chassis->turnAngle(-90_deg);       // turn to face flag
    pros::delay(200);

    intake.moveVelocity(-100);        // run intake to shoot ball

    pros::delay(1000);

    chassis->moveDistance(49_in);     //move towards middle flag
    pros::delay(200);

    chassis->turnAngle(-90_deg);

    chassis->moveDistance(49_in);
    */

  }
