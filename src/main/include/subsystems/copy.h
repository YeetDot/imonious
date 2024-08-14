#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

class classnamehere : public frc2::SubsystemBase {
   public:
   classnamehere();
   void Periodic() override;
   void SimulationPeriodic() override;
   private:

};