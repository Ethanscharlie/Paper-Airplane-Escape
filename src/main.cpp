#include "Charlie2D.hpp"
#include <cstdlib>
#include <iostream>

#include "InputManager.hpp"
#include "JumpMan.hpp"
#include "Light.hpp"
#include "SolidBody.hpp"
#include "Vector2f.hpp"
#include "components/Fan_component.hpp"
#include "config.h"
#include "creaters/Airplane_creater.hpp"
#include "creaters/Fan_creater.hpp"
#include "debugtools.hpp"
#include <cmath>
#include <stdlib.h>

/*
 * Some useful code snips
 *
 * LDTK::loadJson("res/ldtk.ldtk");
 * LDTK::onLoadLevel = [](auto entities) {
 *   for (Entity *entity : entities) {
 *     if (entity->tag == "Player")
 *      std::cout << "Player\n";
 *   }
 * };
 * LDTK::loadLevel("65ba8250-25d0-11ef-b0ef-03acbc99fa7b");
 */

void addCollider(Box box) {
  Entity *entity = GameManager::createEntity("");
  entity->box = box;
  entity->add<SolidBody>();
  // entity->add<Sprite>()->image = Image("res/images/orangeBlock.jpg");
  // entity->layer = 100;
}

int main(int, char **) {
  GameManager::init(Vector2f(5, 6) * 100);

  Entity *background = GameManager::createEntity("background");
  background->box.size = GameManager::gameWindowSize;
  background->box.setWithCenter({0, 0});
  background->add<Sprite>()->image = {"res/images/Levels/level1.jpg"};
  background->layer = -1;

  createAirplane();

  GameManager::shadowFilter->shadowFilterTint = {60, 60, 60};
  Entity *light = GameManager::createEntity("Light");
  light->box = {-717.750000, -534.750000, 1496.250000, 1070.250000};
  light->add<Light>()->image = Image("res/images/light3.png");
  light->get<Light>()->r = 255;
  light->get<Light>()->g = 230;
  light->get<Light>()->b = 200;

  std::vector<Box> colliders{
      Box(-250.42, -300.00, 500.83, 20.42),
      Box(-250.42, -300.00, 21.25, 599.58),
      Box(-240.00, -142.50, 251.25, 24.58),
      Box(229.17, -300.00, 47.92, 599.58),
      Box(-88.33, -22.92, 376.25, 25.00),
      Box(-89.17, -22.50, 25.83, 225.42),
      Box(11.25, 215.83, 24.17, 83.75),
      Box(-249.58, 278.75, 527.50, 20.42),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createFan(Box(-55.8565, 108.492, 216.545, 94.8755), FanDirection::Right);
  createFan(Box(-87.5, -114.167, 270, 85.8333), FanDirection::Left);

  createDebugTooler();

  GameManager::doUpdateLoop();
  return 0;
}
