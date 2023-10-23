/**
 * @author Jenil Jani <jenil.jani@uleth.ca>
 * @created on 2023-03-28
 * @last modifided on 31-03-2023
 * @author Logan Feit <logan.feit@uleth.ca>
 * @created on 2023-04-02
 */
#include "Consumables.h"

AirTank::AirTank() {
  name = "airtank";
}
AirTank::~AirTank() {
}

void AirTank::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> This air tank ensures you'll have enough air to " <<
  "explore even the darkest depths, granting you the freedom to " <<
  "discover the mysteries that lie beneath the waves." << std::endl;
}

MedKit::MedKit() {
  name = "medkit";
}
MedKit::~MedKit() {
}

void MedKit::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> Packed with essential supplies to " <<
  "treat injuries and prevent infections, "
  << "it's a lifesaver in the most dire of situations." << std::endl;
}
