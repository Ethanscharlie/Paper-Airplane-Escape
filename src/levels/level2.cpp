#include "components/Fan_component.hpp"
#include "creaters/Airplane_creater.hpp"
#include "creaters/Fan_creater.hpp"
#include "creaters/Finish_creater.hpp"
#include "level1.hpp"
#include "util.hpp"

void loadLevelTwo() {
  createAirplane({-188.946, -262.225});
  GameManager::getEntities("background")[0]->get<Sprite>()->image =
      Image("res/images/Levels/level2.jpg");

  std::vector<Box> colliders{
      Box(-250.83, -300.00, 499.17, 19.17),
      Box(-265.42, -300.00, 34.58, 599.58),
      Box(-253.33, 282.08, 548.33, 17.50),
      Box(230.00, -300.00, 81.67, 599.58),
      Box(-50.00, -288.75, 22.50, 211.67),
      Box(-232.92, 40.83, 361.25, 21.67),
      Box(110.42, -90.67, 20.00, 136.25),
      Box(-88.33, 140.42, 22.50, 150.42),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createFan(Box(-202.50, -51.67, 292.92, 81.67), FanDirection::Right);
  createFan(Box(-59.58, 196.83, 262.92, 77.50), FanDirection::Left);

  createFinish({-212.5, 183.75, 103.75, 95.4167});
}
