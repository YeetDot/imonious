#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>
#include <rev/SparkLimitSwitch.h>

class VoraciousConsumption : public frc2::SubsystemBase{
   public:
   VoraciousConsumption();
   void Periodic();
   void 开始输入();
   void 开始输入(double 电量);
   void 停住输入();
   bool OverrideBeambreakPressed{false};
   private:
   rev::CANSparkMax 输入马达{11, rev::CANSparkLowLevel::MotorType::kBrushless};
};