#include <Chef.h>
Chef::Chef() {
  ItemStorage itemFact;
  name = "chef";
  item = itemFact.CreateItem(SEACUCUMBER);
}
Chef::~Chef() {
  delete item;
}

void Chef::GetDialog() {
  std::cout << "[Chef]:" << std::endl << "Ahoy sailor!" << std::endl
      << "Quite the pickle we've got ourselves in aye?" << std::endl
      << std::endl << "[Quest]: Could you be a pal "
      << "and find me a [Sea Cucumber]?" << std::endl
      << "From what've been told there should be "
      << "some living somewhere [Undersea] around here" << std::endl
      << "Before you go, make sure you got yourself some [Airtanks]"
      << std::endl << "Before you go underwater." << std::endl << std::endl;
}
void Chef::FinsihQuest(PlayerData* player) {
  if (player->GetInventory()->HasItem(item)) {
    std::cout << "[Chef]:" << std::endl << "Aha! Thank you sailor!" << std::endl
        << "Quite the specimen you got there." << std::endl
        << "I'll take it of your hands here." << std::endl
        << "If you got any more free time I'm sure there's other stuff"
        << " that needs helping around the sub." << std::endl << std::endl;
    player->GetInventory()->RemoveItem(item->GetName());
    player->addScore();
    delete item;
    item = nullptr;
  } else {
    std::cout << "[Chef]:" << std::endl
        << "Doesn't seem you have what I want there buddy" << std::endl
        << "Try looking around more and come back to me "
        << "when you have a [Sea Cucumber]." << std::endl;
  }
}
