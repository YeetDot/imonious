#include "subsystems/Regurgitation.h"

#include "rev/CANSparkMax.h"

Regurgitation::Regurgitation() {
  // Implementation of subsystem constructor goes here.
  shooterPID.SetSmartMotionMaxVelocity(3000);
}

void Regurgitation::Shoot(double rpm) {
  shooterPID.SetReference(rpm, rev::CANSparkBase::ControlType::kVelocity);
  kickerPID.SetReference(rpm, rev::CANSparkBase::ControlType::kVelocity);
}

void Regurgitation::StopShoot() {
  this->Shoot(0);
}

void Regurgitation::Periodic() {
   
}

void Regurgitation::SimulationPeriodic() {
   
}