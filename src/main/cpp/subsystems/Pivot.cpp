// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Pivot.h"

#include "rev/CANSparkMax.h"

Pivot::Pivot() {
  // Implementation of subsystem constructor goes here.
  motor.RestoreFactoryDefaults();
  motor.SetSmartCurrentLimit(40);
  PivotAngle.SetPositionConversionFactor(360);
  pid.SetP(0.23);
  pid.SetI(0);
  pid.SetD(0);
  pid.SetFeedbackDevice(PivotAngle);
  pid.SetOutputRange(-0.6, 0.6);
  motor.SetSoftLimit(rev::CANSparkBase::SoftLimitDirection::kReverse, 50);
}

void Pivot::Periodic() {
   frc::SmartDashboard::PutNumber("Pivot Angle", PivotAngle.GetPosition());
}

void Pivot::SimulationPeriodic() {
   
}

double Pivot::GetPivotAngle(){
  return PivotAngle.GetPosition();
}

void Pivot::SetPivotAngle(double angle){
  pid.SetReference(angle, rev::CANSparkBase::ControlType::kPosition); 
}

void Pivot::换角度(double 电量) {
  motor.Set(电量);
}

void Pivot::SpeakerSetpoint() {
  this->SetPivotAngle(75);
}

void Pivot::PodiumSetpoint() {
  this->SetPivotAngle(60);
}

void Pivot::AmpSetpoint() {
  this->SetPivotAngle(80);
}

void Pivot::RememberAngle() {
  this->AngleMemory = this->GetPivotAngle();
}

double Pivot::ConjureAngle() {
  return AngleMemory;
}