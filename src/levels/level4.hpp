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

void loadLevelFour() {
  createAirplane({-188.946, -262.225});
  GameManager::getEntities("background")[0]->get<Sprite>()->image =
      Image("res/images/Levels/level4.jpg");

  std::vector<Box> colliders{
      Box(-250.00, -300.00, 506.25, 20.00),
      Box(-255.42, -300.00, 24.17, 599.17),
      Box(-253.33, 278.75, 580.83, 20.42),
      Box(226.67, -300.00, 96.25, 599.58),
      Box(-87.92, -280.83, 18.33, 200.42),
      Box(-87.92, -0.83, 197.50, 100.00),
      Box(51.25, -80.42, 59.17, 92.08),
      Box(-127.50, 179.17, 20.83, 97.50),
      Box(-89.17, -82.50, 200.83, 182.92),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createBoost(Box(111.493, 36.4568, 111.127, 61.9326));

  createLever({30.2343, -139.239, 61.9326, 58.4187},
              {-224.524, 178.77, 96.1933, 20.205});

  createMoving(Box(-185.432, -139.239, 18.448, 20.6442),
               Vector2f(-47.9502, -138.799));

  createFinish({-217.936, 204.246, 75.1098, 68.082});
}
