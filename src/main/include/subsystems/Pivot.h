#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <rev/CANSparkMax.h>


class Pivot : public frc2::SubsystemBase {
   public:
   Pivot();
   void Periodic() override;
   void SimulationPeriodic() override;
   void 换角度(double 电量);
   void SetPivotAngle(double angle);
   double GetPivotAngle();
   private:
   
   rev::CANSparkMax motor{31, rev::CANSparkLowLevel::MotorType::kBrushless};
   rev::SparkAbsoluteEncoder PivotAngle = motor.GetAbsoluteEncoder(rev::SparkAbsoluteEncoder::Type::kDutyCycle);
   rev::SparkPIDController pid = motor.GetPIDController();
};