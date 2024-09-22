#pragma once

#include "Charlie2D.hpp"
#include "components/Fan_component.hpp"
#include "creaters/Airplane_creater.hpp"
#include "creaters/Boost_creater.hpp"
#include "creaters/Fan_creater.hpp"
#include "creaters/Finish_creater.hpp"
#include "util.hpp"

void loadLevelThree() {
  createAirplane({-188.946, -262.225});
  GameManager::getEntities("background")[0]->get<Sprite>()->image =
      Image("res/images/Levels/level3.jpg");

  std::vector<Box> colliders{
      Box(-250.00, -300.00, 506.25, 20.00),
      Box(-255.42, -300.00, 24.17, 599.17),
      Box(-253.33, 278.75, 580.83, 20.42),
      Box(226.67, -300.00, 96.25, 599.58),
      Box(-232.50, -160.00, 364.58, 21.67),
      Box(109.58, -159.17, 23.75, 349.58),
      Box(-230.00, 0.00, 182.92, 279.17),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createFan(Box(-188.75, -241.25, 319.58, 80.83), FanDirection::Right);

  createBoost(Box(-36.97, 145.39, 144.51, 38.65));

  createFinish({-199.488, -119.034, 111.127, 119.034});
}
