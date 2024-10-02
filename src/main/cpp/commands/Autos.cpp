// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>

#include "commands/ExampleCommand.h"

frc2::CommandPtr autos::ExampleAuto(DriveSubsystem* drive) {
  return frc2::FunctionalCommand(
      [drive] {drive->ResetEncoders(); },
      [drive] {drive->Drive(1_mps, 0_mps, 0_rad_per_s, true, true);},
      [drive] (bool interrupted) {drive->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);},
      [drive] {return drive->GetPoseX() >= 1;},
      {drive})
    .ToPtr();
}

frc2::CommandPtr autos::ALittleButNotSuperDuperVeryAdvancedAutonomousCommandForMeetingTheRequirementImposedByCamden(DriveSubsystem* drive) {
  return frc2::FunctionalCommand(
      [drive] {drive->ResetEncoders(); },
      [drive] {drive->Drive(0_mps, 0_mps, 1.57_rad_per_s, true, true);},
      [drive] (bool interrupted) {drive->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);},
      [drive] {return drive->GetHeading() >= 1.57_rad;},
      {drive}
    ).ToPtr();
}

frc2::CommandPtr autos::PickUpASingleNoteAuto(DriveSubsystem* drive, VoraciousConsumption* intake, VoraciousConsumptionStage2* indexer) {
  return frc2::cmd::Sequence(
    frc2::FunctionalCommand(
      [drive] {drive->ResetEncoders(); },
      [drive] {drive->Drive(2_mps, 1_mps, 0_rad_per_s, true, true);},
      [drive] (bool interrupted) {drive->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);},
      [drive] {return drive->GetPoseX() >= 2 && drive->GetPoseY() >= 1;},
      {drive}
    ).ToPtr(),
    frc2::FunctionalCommand(
      [drive] { },
      [drive] {drive->Drive(2_mps, -1_mps, 0_rad_per_s, true, true);},
      [drive] (bool interrupted) {drive->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);},
      [drive] {return drive->GetPoseX() >= 4 && drive->GetPoseY() >= 0;},
      {drive}
    ).ToPtr(), 
    frc2::FunctionalCommand(
      [drive] { },
      [drive, intake, indexer] {
        drive->Drive(0.2_mps, 0_mps, 0_rad_per_s, true, true);
        intake->开始输入(0.8);
        indexer->开始马达(0.5);
      },
      [drive, intake, indexer] (bool interrupted) {
        drive->Drive(0_mps, 0_mps, 0_rad_per_s, true, true);
        intake->停住输入();
        indexer->StopMotor();
      },
      [indexer] {return !indexer->IsGamePieceIndexed();},
      {drive}
    ).ToPtr()
  );
}
