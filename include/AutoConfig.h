const int om_leftfront = -7;
const int om_leftrear = -18;
const int om_rightfront = 11;
const int om_rightrear = 20;

const int om_Intake = 9;
const int om_Indexer = 15;



const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 13.5_in;

void FlywheelControlTask(void*);

Motor intake(om_Intake);
Motor indexer(om_Indexer);

auto chassis = ChassisControllerFactory::create(
{om_leftfront, om_leftrear},{om_rightfront, om_rightrear},
AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH});
