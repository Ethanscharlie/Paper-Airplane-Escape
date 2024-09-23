#include "Charlie2D.hpp"
#include "Light.hpp"
#include "Vector2f.hpp"
#include "creaters/background_creater.hpp"
#include "debugtools.hpp"
#include "util.hpp"
#include <cmath>
#include <cstdlib>
#include <functional>
#include <stdlib.h>

int main(int, char **) {
  GameManager::init(Vector2f(5, 6) * 100);

  createBackground();

  GameManager::shadowFilter->shadowFilterTint = {60, 60, 60};
  Entity *light = GameManager::createEntity("Light");
  light->box = {-717.750000, -534.750000, 1496.250000, 1070.250000};
  light->add<Light>()->image = Image("res/images/light3.png");
  light->get<Light>()->r = 255;
  light->get<Light>()->g = 230;
  light->get<Light>()->b = 200;

  loadLevelWithIndex(5);

  GameManager::doUpdateLoop();
  return 0;
}
