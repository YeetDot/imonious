// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include "subsystems/SpatialRelocation.h"
#include "subsystems/VoraciousConsumption.h"
#include "subsystems/VoraciousConsumptionStage2.h"

namespace autos {
/**
 * Example static factory for an autonomous command.
 */
frc2::CommandPtr ExampleAuto(DriveSubsystem* drive);
frc2::CommandPtr ALittleButNotSuperDuperVeryAdvancedAutonomousCommandForMeetingTheRequirementImposedByCamden(DriveSubsystem* drive);
frc2::CommandPtr PickUpASingleNoteAuto(DriveSubsystem* drive, VoraciousConsumption* intake, VoraciousConsumptionStage2* indexer);
}  // namespace autos
