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
#include "util.hpp"
#include <cmath>
#include <stdlib.h>
#include "levels/level1.hpp"

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

int main(int, char **) {
  GameManager::init(Vector2f(5, 6) * 100);

  Entity *background = GameManager::createEntity("background");
  background->box.size = GameManager::gameWindowSize;
  background->box.setWithCenter({0, 0});
  background->add<Sprite>()->image = {"res/images/Levels/level1.jpg"};
  background->layer = -1;

  GameManager::shadowFilter->shadowFilterTint = {60, 60, 60};
  Entity *light = GameManager::createEntity("Light");
  light->box = {-717.750000, -534.750000, 1496.250000, 1070.250000};
  light->add<Light>()->image = Image("res/images/light3.png");
  light->get<Light>()->r = 255;
  light->get<Light>()->g = 230;
  light->get<Light>()->b = 200;

  createDebugTooler();

  loadLevel(loadLevelOne);

  GameManager::doUpdateLoop();
  return 0;
}
