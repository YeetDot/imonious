// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimbSubsystem.h"
class ClimbReset
    : public frc2::CommandHelper<frc2::Command, ClimbReset> {
 public:
  explicit ClimbReset(ClimbSubsystem* subsystem);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  ClimbSubsystem* climb;
};
