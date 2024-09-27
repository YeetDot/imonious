#include "subsystems/Regurgitation.h"

#include "rev/CANSparkMax.h"

Regurgitation::Regurgitation() {
  // Implementation of subsystem constructor goes here.
  shooterPID.SetSmartMotionMaxVelocity(3000);
}

void Regurgitation::Shoot(double rpm) {
  shooterPID.SetReference(rpm, rev::CANSparkBase::ControlType::kSmartVelocity);
  kickerPID.SetReference(rpm, rev::CANSparkBase::ControlType::kSmartVelocity);
}

void Regurgitation::Periodic() {
   
}

void Regurgitation::SimulationPeriodic() {
   
}