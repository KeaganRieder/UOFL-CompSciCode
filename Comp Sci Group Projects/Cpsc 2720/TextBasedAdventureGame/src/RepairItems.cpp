#include<RepairItems.h>
Tools::Tools() {
  name = "tools";
}
Tools::~Tools() {
}

void Tools::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> This sturdy bag of tools contains everything " <<
  "a skilled craftsman needs to tackle any project." << std::endl;
}

ShipParts::ShipParts() {
  name = "shipparts";
}
ShipParts::~ShipParts() {
}

void ShipParts::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> A set of metallic gauges and pistons used" <<
  " repair the the Submarines steering control system. " << std::endl;
}

Patch::Patch() {
  name = "patch";
}
Patch::~Patch() {
}

void Patch::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> A small and unassuming patch made " <<
  "of some rubbery material." << std::endl;
}

ReactorParts::ReactorParts() {
  name = "reactorparts";
}
ReactorParts::~ReactorParts() {
}
void ReactorParts::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> A collection of metal pieces and " <<
  "bolts used to repair the reactor. " << std::endl;
}
