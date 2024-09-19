#include "Charlie2D.hpp"
#include <cstdlib>
#include <iostream>

#include "InputManager.hpp"
#include "JumpMan.hpp"
#include "Light.hpp"
#include "SolidBody.hpp"
#include "Vector2f.hpp"
#include "config.h"
#include "creaters/Airplane_creater.hpp"
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
  GameManager::init();

  Entity *background = GameManager::createEntity("background");
  background->box.size = {1920, 1080};
  background->box.setWithCenter({0, 0});
  background->add<Sprite>()->image = {"res/images/paper.jpg"};

  createAirplane();

  GameManager::shadowFilter->shadowFilterTint = {60, 60, 60};
  Entity *light = GameManager::createEntity("Light");
  light->box = {-717.750000, -534.750000, 1496.250000, 1070.250000};
  light->add<Light>()->image = Image("res/images/light3.png");
  light->get<Light>()->r = 255;
  light->get<Light>()->g = 230;
  light->get<Light>()->b = 200;

  addCollider(Box(-570.75, -453.75, 51.00, 834.00));
  addCollider(Box(-542.25, 355.50, 1164.00, 82.50));
  addCollider(Box(525.75, -463.50, 97.50, 873.75));
  addCollider(Box(-516.00, -78.00, 654.00, 3.00));
  addCollider(Box(-297.00, -165.00, 177.75, 4.50));
  addCollider(Box(310.50, 52.50, 298.50, 384.75));
  addCollider(Box(94.50, 183.00, 88.50, 240.75));
  addCollider(Box(-168.75, 270.00, 93.75, 159.75));

  createDebugTooler();

  GameManager::doUpdateLoop();
  return 0;
}
