#pragma once
#include "Charlie2D.hpp"
#include "Event.hpp"
#include "InputManager.hpp"
#include "SDL_keycode.h"
#include "imgui.h"
#include <format>
#include <string>

extern std::vector<Box> dragCreatedBoxes;

class KeepEntityOnDrag : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  void onDestroy() override;

  bool showing = false;
  Vector2f tempBoxStartPos;
  EventIdentifer downEventId;
  EventIdentifer upEventId;
};

class DebugTools : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  void showImgui();
};

void createDebugTooler();
