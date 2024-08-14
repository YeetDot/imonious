#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>

class VoraciousConsumptionStage2 : public frc2::SubsystemBase {
   public:
   VoraciousConsumptionStage2();
   void Periodic() override;
   void SimulationPeriodic() override;
   void 开始马达(double power);
   bool IsGamePieceIndexed();
   private:
   rev::CANSparkMax indexer{21, rev::CANSparkLowLevel::MotorType::kBrushless};
   rev::SparkLimitSwitch BeamBreak = indexer.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyClosed);
};