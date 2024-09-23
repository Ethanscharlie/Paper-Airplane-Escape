#include "Charlie2D.hpp"
#include "Light.hpp"
#include "Vector2f.hpp"
#include "creaters/StaticScene_creater.hpp"
#include "creaters/background_creater.hpp"
#include "debugtools.hpp"
#include "levels/level2.hpp"
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
  light->box = Box(-206.67, -244.58, 391.67, 482.08);

  light->add<Light>()->image = Image("res/images/light3.png");
  light->get<Light>()->r = 255;
  light->get<Light>()->g = 230;
  light->get<Light>()->b = 200;

  loadStaticscene({"res/images/startScreen.jpg"}, loadLevelTwo);

  GameManager::doUpdateLoop();
  return 0;
}
