#pragma once
#include "Charlie2D.hpp"

void addCollider(Box box);

void nextLevel();

void loadLevel(std::function<void()> level);
