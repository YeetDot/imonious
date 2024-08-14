// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ExampleSubsystem.h"

#include "rev/CANSparkMax.h"

ExampleSubsystem::ExampleSubsystem() {
  // Implementation of subsystem constructor goes here.
  exampleMotor.SetSmartCurrentLimit(45);
}

frc2::CommandPtr ExampleSubsystem::ExampleMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

bool ExampleSubsystem::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ExampleSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void ExampleSubsystem::RunMotor(double power) {
  exampleMotor.Set(power);
}

double returnZero(rev::CANSparkLowLevel::MotorType type){
  if (type == rev::CANSparkLowLevel::MotorType::kBrushless){
    return 0.0;
  } else {
    return 0.0;
  }
}

double 零{returnZero(rev::CANSparkLowLevel::MotorType::kBrushless)};

double zero{零};

void ExampleSubsystem::StopMotor() {
  exampleMotor.Set(zero);
}
