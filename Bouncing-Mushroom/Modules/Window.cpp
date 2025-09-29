#include "Window.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

GWINDOW::Window::Window() { Setup("Default Game Window", {650, 500}); }

GWINDOW::Window::Window(const std::string &l_winTitle,
                        const sf::Vector2u &l_winSize) {
  Setup(l_winTitle, l_winSize);
}

GWINDOW::Window::~Window() { Destroy(); }

void GWINDOW::Window::Setup(const std::string &l_winTitle,
                            const sf::Vector2u &l_winSize) {
   m_windowTitle  = l_winTitle;
   m_windowSize   = l_winSize;
   m_isFullscreen = false;
   m_isDone       = false;
   Create();
}

void GWINDOW::Window::Create() {
   auto win_state = (m_isFullscreen ? sf::State::Fullscreen : sf::State::Windowed);
   sf::VideoMode win_videoMode = sf::VideoMode({m_windowSize.x, m_windowSize.y}, 32);
   m_window.create(win_videoMode ,m_windowTitle, win_state);
}

void GWINDOW::Window::Destroy() {
   m_window.close();
}

void GWINDOW::Window::Update() {
   while ( std::optional event = m_window.pollEvent() ) {
      if ( event->is<sf::Event::Closed>() ) {
         m_isDone = true;
      } else if ( event->is<sf::Event::KeyPressed>() &&
                 event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::F5) {
         ToggleFullScreen();
      }
   }
}

void GWINDOW::Window::ToggleFullScreen() {
   m_isFullscreen = !m_isFullscreen;
   Destroy();
   Create();
}

bool GWINDOW::Window::IsDone() {
   return m_isDone;
}

bool GWINDOW::Window::IsFullscreen() {
   return m_isFullscreen;
}

sf::Vector2u GWINDOW::Window::GetWindowSize() {
   return m_windowSize;
}

void GWINDOW::Window::BeginDraw() {
   m_window.clear(sf::Color::Black);
}

void GWINDOW::Window::Draw(sf::Drawable &l_drawable) {
   m_window.draw(l_drawable);
}

void GWINDOW::Window::EndDraw() {
   m_window.display();
}

