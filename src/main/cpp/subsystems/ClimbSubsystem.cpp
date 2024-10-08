// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimbSubsystem.h"

#include "rev/CANSparkMax.h"

ClimbSubsystem::ClimbSubsystem() {
  motor.SetSmartCurrentLimit(40);
  isZeroed = false;
}

void ClimbSubsystem::Periodic() {
   
}

void ClimbSubsystem::SimulationPeriodic() {
   
}

bool ClimbSubsystem::atLimit() {
  return !limit.Get();
}

void ClimbSubsystem::startMotor(double speed) {
  motor.Set(speed);
}

void ClimbSubsystem::stopMotor() {
  motor.Set(0);
}

void ClimbSubsystem::resetEncoder(){
  encoder.SetPosition(0);
}