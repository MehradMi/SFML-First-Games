#pragma once
#include "Window.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

namespace GAME {

class Game {

private:
  void MoveMushroom();

  GWINDOW::Window m_window;

  sf::Texture m_mushroomTexture;
  std::optional<sf::Sprite> m_mushroom;
  sf::Vector2i m_incrementVector;

  sf::Clock m_clock;
  sf::Time m_elapsed;

public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();
  GWINDOW::Window *GetWindow();

  sf::Time GetElapsed();
  void RestartClock();
};

} // namespace GAME
