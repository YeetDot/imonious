#include "commands/MoveCommand.h"


MoveCommand::MoveCommand(DriveSubsystem* subsystem, units::meters_per_second_t x_speed, units::meters_per_second_t y_speed, units::radians_per_second_t rot) : m_subsystem{subsystem} {
  // Register that this command requires the subsystem.
  AddRequirements(m_subsystem);
  this->x_speed = x_speed;
  this->y_speed = y_speed;
  this->rot = rot;
}

void MoveCommand::Initialize(){
  
}

void MoveCommand::Execute(){
  m_subsystem->Drive(x_speed, y_speed, rot, true, true);
}

void MoveCommand::End(bool interrupted){
  
}