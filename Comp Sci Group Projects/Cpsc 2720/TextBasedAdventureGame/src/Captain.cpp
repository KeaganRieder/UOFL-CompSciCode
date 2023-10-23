#include <Captain.h>

Captain::Captain() {
  ItemStorage itemFact;
  name = "captain";
  item = itemFact.CreateItem(MEDAL);
}
Captain::~Captain() {
  delete item;
}
void Captain::GetDialog() {
  std::cout << "[Captain]:" << std::endl << "You there! Listen up" << std::endl
      << std::endl << "[Quest]: I need you to get a [Medal] for me."
      << std::endl << "From my calculations it should be "
      << "hidden somewhere [Undersea]" << std::endl
      << "from where we've anchored." << std::endl << std::endl
      << "Now, get yourself out there and be useful!" << std::endl
      << "And by the way, make sure you got yourself some [Airtanks]"
      << std::endl << "Before you go out into dangerous waters." << std::endl
      << "GAHAHAHAHA!!" << std::endl;
}
void Captain::FinsihQuest(PlayerData* player) {
  if (player->GetInventory()->HasItem(item)) {
    std::cout << "[Captain]:" << std::endl << "Haha! Thank you my lad!"
        << std::endl << "You actually got the [Medal] I asked for!" << std::endl
        << "I underestimated you!" << std::endl
        << "Seeing how useful you are, go help whoever "
        << "else needs it around the [Ship]." << std::endl << std::endl;
    player->GetInventory()->RemoveItem(item->GetName());
    player->addScore();
    delete item;
    item = nullptr;
  } else {
    std::cout << "[Captain]:" << std::endl << "Quite a jokester here!"
        << std::endl << "Come back to me when actually got the booty I need"
        << std::endl << std::endl;
  }
}
