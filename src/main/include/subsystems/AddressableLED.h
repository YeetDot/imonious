#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/AddressableLED.h>

#include "subsystems/VoraciousConsumptionStage2.h"

class AddressableLED : public frc2::SubsystemBase {
   public:
   AddressableLED(VoraciousConsumptionStage2* indexer);
   void Periodic() override;
   void SimulationPeriodic() override;

   bool enabled = false;
   bool comms = false;
   private:
   VoraciousConsumptionStage2* indexerSubsystem;
   std::array<frc::AddressableLED::LEDData, 90> ledBuffer;
   frc::AddressableLED led{0};
};