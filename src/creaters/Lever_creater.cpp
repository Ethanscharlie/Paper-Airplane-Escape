#include "Lever_creater.hpp"
#include "SolidBody.hpp"
#include "components/Lever_component.hpp"

void createLever(Box leverBox, Box gateBox) {
  // Lever Box
  Entity *lever = GameManager::createEntity("Lever");
  lever->box = leverBox;

  Sprite *sprite = lever->add<Sprite>();
  sprite->image = {"res/images/lever1.png"};

  Lever* leverComponent = lever->add<Lever>();

  // Gate Box
  Entity* gate = GameManager::createEntity("Gate");
  gate->box = gateBox;
  gate->add<SolidBody>();

  Sprite *gateSprite = gate->add<Sprite>();
  gateSprite->image = {"res/images/gate.png"};

  leverComponent->gate = gate;
}
