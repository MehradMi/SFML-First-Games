#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>

namespace GWINDOW {

class Window 
{

public:
 
   Window();
   Window(const std::string &l_winTitle, const sf::Vector2u &l_winSize);
   ~Window();

   void BeginDraw();
   void Draw(sf::Drawable &l_drawable);
   void EndDraw();

   void Update();

   bool IsDone();
   bool IsFullscreen();

   sf::Vector2u GetWindowSize();

   void ToggleFullScreen();

private:

   void Setup(const std::string &l_winTitle, const sf::Vector2u &l_winSize);
   void Create();
   void Destroy();

   
   sf::RenderWindow m_window;
   sf::Vector2u     m_windowSize;
   std::string      m_windowTitle;
   bool             m_isDone;
   bool             m_isFullscreen;

};

}
