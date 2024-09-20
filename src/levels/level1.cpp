#include "level1.hpp"
#include "components/Fan_component.hpp"
#include "creaters/Airplane_creater.hpp"
#include "creaters/Fan_creater.hpp"
#include "util.hpp"

void loadLevelOne() {
  createAirplane({-188.946, -262.225});

  std::vector<Box> colliders{
      Box(-250.42, -300.00, 500.83, 20.42),
      Box(-250.42, -300.00, 21.25, 599.58),
      Box(-240.00, -142.50, 251.25, 24.58),
      Box(229.17, -300.00, 47.92, 599.58),
      Box(-88.33, -22.92, 376.25, 25.00),
      Box(-89.17, -22.50, 25.83, 225.42),
      Box(11.25, 215.83, 24.17, 83.75),
      Box(-249.58, 278.75, 527.50, 20.42),
  };

  for (Box box : colliders) {
    addCollider(box);
  }

  createFan(Box(-55.8565, 108.492, 216.545, 94.8755), FanDirection::Right);
  createFan(Box(-87.5, -114.167, 270, 85.8333), FanDirection::Left);
}
