#include "ClickToScene_component.hpp"
#include "InputManager.hpp"
#include "util.hpp"

void ClickToScene::start() {}

void ClickToScene::update(float deltaTime) {
  if (InputManager::leftMouseHeld) {
    entity->toDestroy = true;
    loadLevel(onClick);
    InputManager::leftMouseHeld = false;
  }
}
