/**
 * @author Jenil Jani <jenil.jani@uleth.ca>
 * @created on 2023-03-28
 * @last modifided on 31-03-2023
 */
#include "QuestItems.h"

SeaCucumber::SeaCucumber() {
  name = "seacucumber";
}
SeaCucumber::~SeaCucumber() {
}
void SeaCucumber::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> The humble Sea Cucumber, prized as a delicacy " <<
  "for its soft, gelatinous texture and mild flavor" << std::endl;
}

Medal::Medal() {
  name = "medal";
}
Medal::~Medal() {
}

void Medal::GetDescription() {
  std::cout << "> " << name << std::endl;
  std::cout << "> The captains Medal, crafted from the finest " <<
  "metals and polished to a gleaming shine." << std::endl;
}
