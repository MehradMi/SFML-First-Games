#include "Game.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

GAME::Game::Game() : m_window("Bouncing Mushroom", sf::Vector2u(800, 700)) {
  if (!m_mushroomTexture.loadFromFile(
          "Dev/SFML-First-Games/Bouncing-Mushroom/Assets/mushroom.png"))
    std::cerr << "Unable To Load Texture From File" << std::endl;
  m_mushroom.emplace(m_mushroomTexture);
  m_incrementVector = sf::Vector2i(500, 500);
}

GAME::Game::~Game() {}

void GAME::Game::Update() {
  m_window.Update();
  MoveMushroom();
}

void GAME::Game::MoveMushroom() {
  sf::Vector2u l_winSize = m_window.GetWindowSize();
  sf::Vector2u l_textureSize = m_mushroomTexture.getSize();

  if ((m_mushroom->getPosition().x >= l_winSize.x - l_textureSize.x &&
           m_incrementVector.x > 0 ||
       m_mushroom->getPosition().x <= 0 && m_incrementVector.x < 0)) {
    m_incrementVector.x = -m_incrementVector.x;
  }

  if ((m_mushroom->getPosition().y >= l_winSize.y - l_textureSize.y &&
           m_incrementVector.y > 0 ||
       m_mushroom->getPosition().y <= 0 && m_incrementVector.y < 0)) {
    m_incrementVector.y = -m_incrementVector.y;
  }

  float fElapsed = m_elapsed.asSeconds();

  m_mushroom->setPosition(
      {m_mushroom->getPosition().x + (m_incrementVector.x * fElapsed),
       m_mushroom->getPosition().y + (m_incrementVector.y * fElapsed)});
  // m_mushroom->setTexture(m_(mushroomTexture);
}

void GAME::Game::Render() {
  m_window.BeginDraw(); // Clear
  m_window.Draw(*m_mushroom);
  m_window.EndDraw(); // Display
}

GWINDOW::Window *GAME::Game::GetWindow() { return &m_window; }

sf::Time GAME::Game::GetElapsed() { return m_elapsed; }

void GAME::Game::RestartClock() { m_elapsed = m_clock.restart(); }
