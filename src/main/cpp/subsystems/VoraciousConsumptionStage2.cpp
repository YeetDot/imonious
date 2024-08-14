#include "subsystems/VoraciousConsumptionStage2.h"

#include "rev/CANSparkMax.h"

VoraciousConsumptionStage2::VoraciousConsumptionStage2() {
  indexer.SetSmartCurrentLimit(20);
}

bool VoraciousConsumptionStage2::IsGamePieceIndexed(){
   return BeamBreak.Get();
}

void VoraciousConsumptionStage2::Periodic() {
   
}

void VoraciousConsumptionStage2::SimulationPeriodic() {
   
}

void VoraciousConsumptionStage2::开始马达(double power){
   indexer.Set(power);
}