#include "util.hpp"
#include "ShadowFilter.hpp"
#include "creaters/StaticScene_creater.hpp"
#include "debugtools.hpp"

#include "levels/level1.hpp"
#include "levels/level2.hpp"
#include "levels/level3.hpp"
#include "levels/level4.hpp"
#include "levels/level5.hpp"
#include "levels/level6.hpp"

std::vector<std::function<void()>> levels = {loadLevelOne,   loadLevelTwo,
                                             loadLevelThree, loadLevelFour,
                                             loadLevelFive,  loadLevelSix};

std::vector<std::function<void()>>::iterator currentLevel = levels.begin();

void addCollider(Box box) {
  Entity *entity = GameManager::createEntity("");
  entity->box = box;
  entity->add<SolidBody>();
}

void loadLevel(std::function<void()> level) {
  for (Entity *entity : GameManager::getAllObjects()) {
    if (entity->checkComponent<ShadowFilter>())
      continue;
    if (entity->tag == "background")
      continue;
    if (entity->checkComponent<Light>())
      continue;
    entity->toDestroy = true;
  }

  level();
  createDebugTooler();
}

void nextLevel() {
  currentLevel++;

  if (currentLevel == levels.end()) {
    currentLevel = levels.begin();
    loadLevel([](){});
    loadStaticscene({"res/images/endScreen.jpg"}, []() {
      loadStaticscene({"res/images/endScreen.jpg"}, loadLevelTwo);
    });
    return;
  }

  loadLevel(*currentLevel);
}

void loadLevelWithIndex(int index) {
  currentLevel = levels.begin() + index;
  loadLevel(*currentLevel);
}
