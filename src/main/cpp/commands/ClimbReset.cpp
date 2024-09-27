// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbReset.h"

ClimbReset::ClimbReset(ClimbSubsystem* subsystem)
    : climb{subsystem} {
  // Register that this command requires the subsystem.
  AddRequirements(climb);
}

void ClimbReset::Initialize(){
  climb->startMotor(0.05);
}

void ClimbReset::Execute(){
  
}

bool ClimbReset::IsFinished(){
  if(climb->atLimit()){
    climb->resetEncoder();
    climb->stopMotor();
    return true;
  }
  return false;
}

void ClimbReset::End(bool interrupted){
  climb->isZeroed = true;
}

