// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/RunCommand.h>
#include <frc/MathUtil.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "Constants.h"
#include "commands/Autos.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/ClimbSubsystem.h"
#include "subsystems/VoraciousConsumption.h"
#include "subsystems/SpatialRelocation.h"
#include "subsystems/Pivot.h"
#include "subsystems/VoraciousConsumptionStage2.h"
#include "subsystems/AddressableLED.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  VoraciousConsumption intake;
  VoraciousConsumptionStage2 indexer;
  Pivot pivot;
  ClimbSubsystem climb;
  DriveSubsystem drive;
  AddressableLED leds{&indexer};

  // The autonomous routines
  frc2::CommandPtr m_simpleAuto = autos::ExampleAuto(&drive);
  frc2::CommandPtr m_requirementAuto = autos::ALittleButNotSuperDuperVeryAdvancedAutonomousCommandForMeetingTheRequirementImposedByCamden(&drive);
  frc2::CommandPtr m_complexAuto = autos::PickUpASingleNoteAuto(&drive, &intake, &indexer);

  // The chooser for the autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureBindings();
};
