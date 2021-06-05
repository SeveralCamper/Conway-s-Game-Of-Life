#include <SFML/Graphics.hpp>

#ifndef SETTINGS_H_
#define SETTINGS_H_

enum class DirectionZoneButtons { HORIZONTAL = 0, VERTICAL = 1 };

static const int SCREEN_WIDTH = 1374;
static const int SCREEN_HEIGHT = 795;
static const std::string NAME_WINDOW = "Life";

static const int ARR_WIDTH = 63;
static const int ARR_HEIGHT = 39;


static const int DELAY_MILLIS = 500;

static const sf::Color INDIGO_COLOR = sf::Color(75, 0, 130);
static const sf::Color WHITE_COLOR = sf::Color(255, 255, 255);
static const sf::Color TANGERINE_COLOR = sf::Color(255, 136, 0);
static const sf::Color BLACK_COLOR = sf::Color(0, 0, 0);

static const std::string DEFAULT_FONT = "arial.ttf";

static const int DEFAULT_FONT_SIZE = 20;

#endif