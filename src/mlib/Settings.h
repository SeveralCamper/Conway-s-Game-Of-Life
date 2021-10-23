#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <SFML/Graphics.hpp>

enum class DirectionZoneButtons { HORIZONTAL = 0, VERTICAL = 1 };

static const int SCREEN_WIDTH = 1374;
static const int SCREEN_HEIGHT = 795;
static const std::string NAME_WINDOW = "Conway's Game Of Life";

static const int SIZE_CELLS = 16;

static const int ARR_WIDTH = 63;
static const int ARR_HEIGHT = 39;

static const int SIDE = 24;

static const float DELAY_SECONDS = 1.f;

static const sf::Color INDIGO_COLOR = sf::Color(75, 0, 130);
static const sf::Color WHITE_COLOR = sf::Color(255, 255, 255);
static const sf::Color TANGERINE_COLOR = sf::Color(255, 136, 0);
static const sf::Color BLACK_COLOR = sf::Color(0, 0, 0);
static const sf::Color GRAY_COLOR = sf::Color(10, 10, 10);
static const sf::Color ORANGE_COLOR = sf::Color(255, 165, 0);
static const sf::Color LIME_GREEN_COLOR = sf::Color(50, 205, 50);
static const sf::Color LIME_COLOR = sf::Color(0, 205, 0);

static const std::string DEFAULT_FONT = "arial.ttf";

static const int DEFAULT_FONT_SIZE = 20;

static const std::string PATH_TO_MODELS = "configurations/models.txt";


#endif //  SETTINGS_H_
