#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Subsystem.h>

#include "subsystems/SpatialRelocation.h"

class MoveCommand
    : public frc2::CommandHelper<frc2::Command, MoveCommand> {
 public:

  explicit MoveCommand(DriveSubsystem* subsystem, units::meters_per_second_t x_speed, units::meters_per_second_t y_speed, units::radians_per_second_t rot);
  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;

 private:
  DriveSubsystem* m_subsystem;
  units::meters_per_second_t x_speed;
  units::meters_per_second_t y_speed;
  units::radians_per_second_t rot;
};