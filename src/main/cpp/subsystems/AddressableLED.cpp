// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AddressableLED.h"
#include "subsystems/VoraciousConsumptionStage2.h"

#include "rev/CANSparkMax.h"
#include <frc/DriverStation.h>

AddressableLED::AddressableLED(VoraciousConsumptionStage2* indexer) {
  indexerSubsystem = indexer;
  led.SetLength(90);
  for (size_t i = 0; i < 90; i++)
  {
    ledBuffer[i].SetRGB(0, 0, 0);
  }
  led.SetData(ledBuffer);
}

void AddressableLED::Periodic() {
  enabled = frc::DriverStation::IsEnabled();
  comms = frc::DriverStation::IsDSAttached();

  if (!enabled)
  {
    if (comms)
    {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(0, 255, 0);
      }
      led.SetData(ledBuffer);
    } else {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(255, 0, 0);
      }
      led.SetData(ledBuffer);
    }
  } else {
    if (indexerSubsystem->IsGamePieceIndexed()) {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(0, 255, 0);
      }
      led.SetData(ledBuffer);
    } else {
      for (size_t i = 0; i < 90; i++)
      {
        ledBuffer[i].SetRGB(255, 165, 0);
      }
      led.SetData(ledBuffer);
    }
  }
}

void AddressableLED::SimulationPeriodic() {
   
}