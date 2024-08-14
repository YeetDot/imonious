#include "subsystems/VoraciousConsumption.h"

VoraciousConsumption::VoraciousConsumption(){
   输入马达.SetSmartCurrentLimit(30);
}

void VoraciousConsumption::Periodic(){

}



void VoraciousConsumption::开始输入(){
   输入马达.Set(-0.5);
}

void VoraciousConsumption::开始输入(double 电量){
   输入马达.Set(电量);
}

void VoraciousConsumption::停住输入(){
   输入马达.Set(0);
}

