#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>

class ClimbSubsystem : public frc2::SubsystemBase {
   public:
   ClimbSubsystem();
   void Periodic() override;
   void SimulationPeriodic() override;
   bool atLimit();
   void startMotor(double speed);
   void stopMotor();
   void resetEncoder();
   bool isZeroed;
   private:
   rev::CANSparkMax motor{41, rev::CANSparkLowLevel::MotorType::kBrushless};
   rev::SparkLimitSwitch limit = motor.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyClosed);
   rev::SparkRelativeEncoder encoder = motor.GetEncoder();
};