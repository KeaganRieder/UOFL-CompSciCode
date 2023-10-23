/**
 * @Author Jenil Jani <jenil.jani@uleth.ca>
 * @date 2023-03-16
 * Modifed Keagan Rider <k.rieder@uleth.ca>
 * @date 2023-03-25
 */
#include "Inventory.h"

Inventory::Inventory() {
  itemFact = new ItemStorage();
}
// the parameterized constructor
Inventory::~Inventory() {
  for (auto invPos = contents.begin(); invPos != contents.end(); invPos++) {
    delete invPos->second;
    //contents.erase(invPos);
  }
  contents.clear();
  delete itemFact;
}

bool Inventory::CheckReqItems(Inventory *inventory) {
  bool neededItems = false;
  for (auto invPos = contents.begin(); invPos != contents.end(); invPos++) {
    if (inventory->GetItem(invPos->second->GetName()) == nullptr) {
      std::cout << "> You are lacking: " << invPos->second->GetName()
          << std::endl;
      neededItems = false;
    } else if (inventory->GetItem(invPos->second->GetName())->GetName()
        == invPos->second->GetName()) {
      std::cout << "> You have the needed: " << invPos->second->GetName()
          << std::endl;
      neededItems = true;
    } else {
      std::cout << "> You are lacking: " << invPos->second->GetName()
          << std::endl;
      neededItems = false;
    }
  }
  return neededItems;
}
void Inventory::UseItems(Inventory *inventory) {
  for (auto invPos = contents.begin(); invPos != contents.end(); invPos++) {
    if (inventory->GetItem(invPos->second->GetName()) == nullptr) {
//nothing
    } else if (inventory->GetItem(invPos->second->GetName())->GetName()
        == invPos->second->GetName()) {
      inventory->RemoveItem(invPos->second->GetName());
    }
  }
}

bool Inventory::HasItem(std::string itemName) {
  auto invPos = contents.find(itemName);
  if (invPos != contents.end()) {
    if (invPos->second != nullptr) {
      return true;
    }
    return false;
  }
  return false;
}
bool Inventory::HasItem(Item *item) {
  auto invPos = contents.find(item->GetName());
  if (invPos != contents.end()) {
    if (invPos->second != nullptr) {
      return true;
    }
    return false;
  }
  return false;
}

Item* Inventory::GetItem(std::string itemName) {
  auto invPos = contents.find(itemName);
  if (invPos != contents.end()) {
    if (invPos->second != nullptr) {
      return contents[itemName];
    }
  }
  return nullptr;
}
std::string Inventory::GetItemName(std::string itemName) {
  auto invPos = contents.find(itemName);
  if (invPos != contents.end()) {
    if (invPos->second != nullptr) {
      return invPos->second->GetName();
    }
  }
  return "";
}
void Inventory::AddItem(Item *item) {
  if (item != nullptr) {
    contents[item->GetName()] = item;
  }
}
void Inventory::AddItem(ItemType item, std::string name) {
  contents[name] = itemFact->CreateItem(item);
}
void Inventory::EmptySlot(std::string itemName) {
  auto invPos = contents.find(itemName);
  if (invPos != contents.end()) {
    if (invPos->second != nullptr) {
      invPos->second = nullptr;
      contents.erase(invPos);
    }
  }
}
void Inventory::RemoveItem(std::string itemName) {
  auto invPos = contents.find(itemName);
  if (invPos != contents.end()) {
    delete invPos->second;
    contents.erase(invPos);
  }
}

void Inventory::ListContents() {
  empty = true;
  std::cout << "Items:" << std::endl;
  for (auto invPos = contents.begin(); invPos != contents.end(); invPos++) {
    if (invPos->second != nullptr) {
      //std::cout << invPos->first << ": " << std::endl;
      invPos->second->GetDescription();
      empty = false;
    }
  }
  if (empty) {
    std::cout << "> There is nothing of interest here" << std::endl;
  }
}
