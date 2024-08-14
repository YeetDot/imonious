// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimbSubsystem.h"

#include "rev/CANSparkMax.h"

ClimbSubsystem::ClimbSubsystem() {
  motor.SetSmartCurrentLimit(40);
}

void ClimbSubsystem::Periodic() {
   
}

void ClimbSubsystem::SimulationPeriodic() {
   
}

bool ClimbSubsystem::atLimit() {
  return !limit.Get();
}

void ClimbSubsystem::startMotor() {
  motor.Set(0.05);
}

void ClimbSubsystem::stopMotor() {
  motor.Set(0);
}