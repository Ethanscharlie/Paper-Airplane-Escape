#include "debugtools.hpp"

std::vector<Box> dragCreatedBoxes;

void KeepEntityOnDrag::start() {
  downEventId = Event::addEventListener("LeftMouseButtonDown", [this]() {
    tempBoxStartPos = InputManager::getMouseWorldPosition();
    showing = true;
  });

  upEventId = Event::addEventListener("LeftMouseButtonUp", [this]() {
    entity->box.print();
    dragCreatedBoxes.push_back(entity->box);

    showing = false;
    entity->toDestroy = true;
  });

  entity->layer = 100;
}

void KeepEntityOnDrag::update(float deltaTime) {
  if (showing) {
    Vector2f mousePos = InputManager::getMouseWorldPosition();

    if (mousePos.x > tempBoxStartPos.x && mousePos.y > tempBoxStartPos.y) {
      entity->box.position = tempBoxStartPos;
      entity->box.size = mousePos - tempBoxStartPos;
    }
  }
}

void KeepEntityOnDrag::onDestroy() {
  Event::removeEventListener(downEventId);
  Event::removeEventListener(upEventId);
}

void DebugTools::start() {}

void DebugTools::update(float deltaTime) { showImgui(); }

void DebugTools::showImgui() {
  SDL_RenderSetLogicalSize(GameManager::renderer,
                           GameManager::currentWindowSize.x,
                           GameManager::currentWindowSize.y);
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();

  ImGui::NewFrame();
  ImGui::Begin("CH2D DEBUG");

  // Drag Box Selector
  ImGui::BeginGroup();
  if (ImGui::Button("Box creater [b]") || InputManager::keyEvents[SDLK_b]) {
    Entity *drag = GameManager::createEntity("drag");
    drag->add<Sprite>()->image = Image("res/images/orangeBlock.jpg");
    drag->add<KeepEntityOnDrag>();
  }

  ImGui::SameLine();

  if (ImGui::Button("Copy")) {
    std::string text;
    for (Box box : dragCreatedBoxes) {
      text +=
          std::format("Box({:.2f}, {:.2f}, {:.2f}, {:.2f}),\n", box.position.x,
                      box.position.y, box.size.x, box.size.y);

      ImGui::SetClipboardText(text.c_str());
    }
  }

  ImGui::SameLine();

  if (ImGui::Button("Clear All")) {
    dragCreatedBoxes.clear();
  }

  for (auto it = dragCreatedBoxes.begin(); it != dragCreatedBoxes.end();) {
    Box box = *it;

    std::string text =
        std::format("Box({:.2f}, {:.2f}, {:.2f}, {:.2f})", box.position.x,
                    box.position.y, box.size.x, box.size.y);

    ImGui::Text(text.c_str());

    ImGui::SameLine();

    if (ImGui::Button(std::format("-###{}", text.c_str()).c_str())) {
      it = dragCreatedBoxes.erase(it);
    } else {
      ++it;
    }
  }

  ImGui::EndGroup();

  ImGui::End();
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
  SDL_RenderSetLogicalSize(GameManager::renderer, GameManager::gameWindowSize.x,
                           GameManager::gameWindowSize.y);
}

void createDebugTooler() {
  Entity *entity = GameManager::createEntity("DEBUG");
  entity->layer = 100;
  entity->add<DebugTools>();
}
