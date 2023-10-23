#include <Medic.h>
Medic::Medic() {
  name = "medic";
  item = nullptr;
}
Medic::~Medic() {
//nothing
}

void Medic::GetDialog() {
  std::cout << "[MEDIC]:" << std::endl
      << "Hey, I don't got much on me right now." << std::endl
      << "If you got a [Medkit] I could [Heal] you up." << std::endl;
}

void Medic::Heal(PlayerData *player) {
  if (player->GetInventory()->HasItem("medkit") && player->GetHealth() < 100) {
    player->UpdateHealth(100);
    std::cout << "[MEDIC]:" << std::endl
    << "There, that should put you "
    << "back into good shape!"
        << std::endl << "Come to me anytime you need some more healing."
        << std::endl;
    player->GetInventory()->RemoveItem("medkit");
  } else if (player->GetInventory()->HasItem("medkit")
      && player->GetHealth() >= 100) {
    std::cout << "You already have full health." << " Use your [Medkit] later."
        << std::endl;
  } else {
    std::cout << "You do not have an [Medkit] " << "to fill your Health."
        << std::endl;
  }
}
