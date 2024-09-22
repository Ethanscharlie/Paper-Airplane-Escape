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

void loadLevelFive() {
  createAirplane({-188.946, -262.225});
  GameManager::getEntities("background")[0]->get<Sprite>()->image =
      Image("res/images/Levels/level5.png");

  std::vector<Box> colliders{
      Box(-250.00, -300.00, 506.25, 20.00),
      Box(-255.42, -300.00, 24.17, 599.17),
      Box(-253.33, 278.75, 580.83, 20.42),
      Box(226.67, -300.00, 96.25, 599.58),

      Box(-107.69, -278.48, 20.19, 439.31),
      Box(-106.25, 138.75, 218.33, 20.83),
      Box(91.67, -140.00, 20.42, 298.33),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createBoost(Box(115.01, 36.46, 108.05, 43.05));

  createMoving(Box(-249.58, -161.25, 19.58, 22.92), Vector2f(90.42, -159.58),
               100);

  createMoving(Box(-252.08, 18.75, 22.92, 21.67), Vector2f(91.25, 18.75), 200);

  createMoving(Box(-27.08, 143.33, 19.58, 18.75), Vector2f(-27.50, 259.17),
               100);

  createMoving(Box(91.25, -78.75, 19.58, 15.83), Vector2f(227.92, -79.58), 100);

  createFinish({-28.1845, 75.9883, 61.4934, 63.2504});
}
