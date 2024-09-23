#pragma once

#include "Charlie2D.hpp"
#include "Vector2f.hpp"
#include "components/Fan_component.hpp"
#include "creaters/Airplane_creater.hpp"
#include "creaters/Boost_creater.hpp"
#include "creaters/Fan_creater.hpp"
#include "creaters/Finish_creater.hpp"
#include "creaters/Lever_creater.hpp"
#include "creaters/Moving_creater.hpp"
#include "util.hpp"

void loadLevelSix() {
  createAirplane({-188.946, -262.225});
  GameManager::getEntities("background")[0]->get<Sprite>()->image =
      Image("res/images/Levels/level6.png");

  std::vector<Box> colliders{
      Box(-250.00, -300.00, 506.25, 20.00),
      Box(-255.42, -300.00, 24.17, 599.17),
      Box(-253.33, 278.75, 580.83, 20.42),
      Box(226.67, -300.00, 96.25, 599.58),

      Box(-230.67, -139.68, 361.93, 18.01),
      Box(-107.25, -41.73, 20.20, 220.06),
      Box(91.73, 198.10, 41.73, 88.29),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createFan(Box(-231.99, -122.11, 202.05, 81.70), FanDirection::Right);
  createFan(Box(-8.86, -120.35, 235.43, 79.94), FanDirection::Left);
  createFan(Box(-87.92, -41.73, 315.81, 81.26), FanDirection::Right);
  createFan(Box(-86.60, 39.09, 315.81, 79.94), FanDirection::Left);
  createFan(Box(-228.92, -221.38, 456.37, 81.70), FanDirection::Right);
  createFan(Box(-225.42, 178.75, 316.25, 78.33), FanDirection::Left);

  createLever(Box(-167.86, -40.41, 58.86, 59.74),
              Box(132.14, 198.54, 97.07, 21.08));

  createBoost(Box(-225.42, 136.25, 117.92, 41.67));
  createBoost(Box(-226.667, 80.8333, 118.75, 38.75));

  createMoving(Box(-87.92, -300.00, 19.58, 19.58), Vector2f(-88.33, -140.00),
               100);

  createMoving(Box(-8.75, -140.00, 18.33, 17.50), Vector2f(88.33, -300.00),
               100);

  createMoving(Box(89.17, -140.42, 20.00, 18.75), Vector2f(93.33, 196.67), 100);

  createMoving(Box(-107.50, 59.58, 19.58, 17.08), Vector2f(230.42, -99.58),
               100);

  createMoving(Box(-249.17, 39.17, 20.42, 18.75), Vector2f(-107.08, 37.50),
               100);

  createMoving(Box(-106.25, 158.33, 18.33, 20.00), Vector2f(-108.33, 256.67),
               100);

  createFinish(Box(137.85, 222.25, 83.89, 53.59));
}
