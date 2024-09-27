#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <units/magnetic_flux.h>

class Regurgitation : public frc2::SubsystemBase {
   public:
   Regurgitation();
   void Shoot(double rpm);
   void Periodic() override;
   void SimulationPeriodic() override;
   private:
   rev::CANSparkMax shooter{22, rev::CANSparkLowLevel::MotorType::kBrushless};
   rev::CANSparkMax kicker{23, rev::CANSparkLowLevel::MotorType::kBrushless};
   rev::SparkPIDController shooterPID = shooter.GetPIDController();
   rev::SparkPIDController kickerPID = kicker.GetPIDController();
};