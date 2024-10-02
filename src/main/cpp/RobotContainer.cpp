// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include "commands/ClimbReset.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  drive.SetDefaultCommand(frc2::RunCommand(
    [this] {
      drive.Drive(
        -units::meters_per_second_t{frc::ApplyDeadband(
                m_driverController.GetLeftY(), OIConstants::kDriveDeadband)},
            -units::meters_per_second_t{frc::ApplyDeadband(
                m_driverController.GetLeftX(), OIConstants::kDriveDeadband)},
            -units::radians_per_second_t{frc::ApplyDeadband(
                m_driverController.GetRightX(), OIConstants::kDriveDeadband)},
            true, true);
    }
  ,{&drive}));
  // Configure the button bindings
  ConfigureBindings();
}



void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`

  frc2::Trigger([this] {
    return climb.isZeroed;
  }).OnTrue(ClimbReset(&climb).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(pivot.RunOnce([this] {pivot.RememberAngle(); pivot.SpeakerSetpoint();}));
  m_driverController.B().OnFalse(intake.RunOnce([this] {pivot.SetPivotAngle(pivot.ConjureAngle());}));

  m_driverController.A().WhileTrue(intake.RunOnce([this] {intake.OverrideBeambreakPressed = true;}));
  m_driverController.A().OnFalse(intake.RunOnce([this] {intake.OverrideBeambreakPressed = false;}));

  m_driverController.LeftTrigger().WhileTrue(intake.Run([this] {
    if (indexer.IsGamePieceIndexed() || intake.OverrideBeambreakPressed){
      intake.开始输入(0.8);
      indexer.开始马达(0.5);
    } else {
      intake.停住输入();
      indexer.开始马达(0);
    }
    
  }));
  m_driverController.LeftTrigger().OnFalse(intake.RunOnce([this] {intake.停住输入();indexer.开始马达(0);}));

  m_driverController.RightTrigger().OnTrue(intake.RunOnce([this] {intake.开始输入(-0.5); indexer.开始马达(-0.5);}));
  m_driverController.RightTrigger().OnFalse(intake.RunOnce([this] {intake.停住输入(); indexer.StopMotor();}));

  m_driverController.LeftBumper().WhileTrue(pivot.Run([this] {
    pivot.SetPivotAngle(75);
  }));
  m_driverController.LeftBumper().OnFalse(pivot.RunOnce([this] {pivot.换角度(0);}));

  m_driverController.RightBumper().WhileTrue(pivot.RunOnce([this] {pivot.换角度(-0.1);}));
  m_driverController.RightBumper().OnFalse(pivot.RunOnce([this] {pivot.换角度(0);}));

  m_driverController.LeftStick().OnTrue(drive.RunOnce([this] {drive.SetX();}));
  // m_driverController.X().WhileTrue(climb.Run([this] {
  //   if(!climb.atLimit()){
  //     climb.startMotor();
  //   } else {
  //     climb.stopMotor();
  //   }
  // }));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  m_chooser.SetDefaultOption("Example", m_simpleAuto.get());
  m_chooser.AddOption("Required", m_requirementAuto.get());
  m_chooser.AddOption("Complex", m_complexAuto.get());
  frc::SmartDashboard::PutData(&m_chooser);


  return m_chooser.GetSelected();
}
