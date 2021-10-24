#include "Screen.h"

UserZone menuZone;
UserZone gameZone;
UserZone statusZone;
UserZone modelsZone;

LifeAlgorithm LAExmpl;

float speed = DELAY_SECONDS;

int modelsFLag = 0;
int setIndexModel = 0;

sf::RenderWindow
        window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), NAME_WINDOW);

std::vector<UserButton> collectionButtonsShapes;

// Получить индекс массива ячейки на которой был совершен клик
sf::Vector2i GetIndexArray(UserZone& zone)
{
    // Индекс ячейки массива
    sf::Vector2i arrIndex;

    arrIndex.x = (sf::Mouse::getPosition(window).x - zone.GetPosition().x - 10)
            / SIZE_CELLS;
    arrIndex.y
            = ((sf::Mouse::getPosition(window).y - zone.GetPosition().y - 5)
               / SIZE_CELLS);
    return arrIndex;
}

void Custom(UserZone& zone)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (zone.GetPosition().x < sf::Mouse::getPosition(window).x - SIDE
            && zone.GetPosition().x + zone.GetSize().x - SIDE
                    > sf::Mouse::getPosition(window).x
            && zone.GetPosition().y < sf::Mouse::getPosition(window).y - SIDE
            && zone.GetPosition().y + zone.GetSize().y - SIDE
                    > sf::Mouse::getPosition(window).y) {
            int x = GetIndexArray(zone).x;
            int y = GetIndexArray(zone).y;
            LAExmpl.SetArray(x, y);
        }
    }
}

void CloseWindow()
{
    window.close();
}

void LoadModel()
{
    modelsFLag = 1;
    LAExmpl.LoadModels();
    LAExmpl.SetStep(0);
    LAExmpl.pause = false;
}

void ShowModels()
{
    modelsFLag = 1;
    LAExmpl.ShowModel(setIndexModel);
    LAExmpl.SetStep(0);
    LAExmpl.pause = false;
}

void RandomGrid()
{
    modelsFLag = 0;
    LAExmpl.RandFillUniverse();
    LAExmpl.SetStep(0);
    LAExmpl.pause = false;
}

void CustomModeGrid()
{
    modelsFLag = 0;
    LAExmpl.CreateUniverse();
    LAExmpl.SetStep(0);
    LAExmpl.pause = true;
}

void PauseStart()
{
    LAExmpl.pause = !LAExmpl.pause;
}

void Speed_1()
{
    speed = .25f;
}

void Speed_2()
{
    speed = .5f;
}

void Speed_3()
{
    speed = 1.f;
}

void Speed_4()
{
    speed = 2.f;
}

void CreateUI()
{
    /* Зоны */
    /* Зона меню */
    sf::Vector2f menuZonePosition = sf::Vector2f(5, 5);
    sf::Vector2f menuZoneSize
            = sf::Vector2f(window.getSize().x * 0.25f, window.getSize().y - 10);

    menuZone.SetWindow(&window);
    menuZone.SetPosition(menuZonePosition);
    menuZone.SetSize(menuZoneSize);
    menuZone.SetDirection(DirectionZoneButtons::VERTICAL);
    menuZone.SetFillColor(BLACK_COLOR);

    /* Зона Игрового поля */
    sf::Vector2f gameZonePosition
            = sf::Vector2f((window.getSize().x * 0.25f) + 10, 5);
    sf::Vector2f gameZoneSize = sf::Vector2f(
            (window.getSize().x * 0.75f) - 15, (window.getSize().y * 0.8f) - 5);

    gameZone.SetWindow(&window);
    gameZone.SetPosition(gameZonePosition);
    gameZone.SetSize(gameZoneSize);
    gameZone.SetFillColor(BLACK_COLOR);

    /* Зона Моделей */
    sf::Vector2f modelsZonePosition = sf::Vector2f(5, 330);
    sf::Vector2f modelsZoneSize = sf::Vector2f(
            window.getSize().x * 0.25f, window.getSize().y - 334);

    modelsZone.SetWindow(&window);
    modelsZone.SetPosition(modelsZonePosition);
    modelsZone.SetSize(modelsZoneSize);
    modelsZone.SetDirection(DirectionZoneButtons::CUBE);
    modelsZone.SetFillColor(BLACK_COLOR);

    /* Зона статусной строки  */
    sf::Vector2f statusZonePosition = sf::Vector2f(
            (window.getSize().x * 0.25f) + 10,
            (window.getSize().y * 0.8f) + 10);
    sf::Vector2f statusZoneSize = sf::Vector2f(
            (window.getSize().x * 0.75f) - 15,
            (window.getSize().y * 0.2f) - 15);

    statusZone.SetWindow(&window);
    statusZone.SetPosition(statusZonePosition);
    statusZone.SetSize(statusZoneSize);
    statusZone.SetDirection(DirectionZoneButtons::HORIZONTAL);
    statusZone.SetFillColor(BLACK_COLOR);

    /* Кнопки Игрового поля*/
    UserButton btnRandomMode("RANDOM MODE", &window);
    btnRandomMode.SetFillColor(GRAY_COLOR);
    btnRandomMode.SetSize(sf::Vector2f(200, 60));
    btnRandomMode.ClickButton = RandomGrid;

    UserButton btnCustomMode("CUSTOM MODE", &window);
    btnCustomMode.SetFillColor(GRAY_COLOR);
    btnCustomMode.SetSize(sf::Vector2f(200, 60));
    btnCustomMode.ClickButton = CustomModeGrid;

    UserButton btnModelsMode("MODELS MODE", &window);
    btnModelsMode.SetFillColor(GRAY_COLOR);
    btnModelsMode.SetSize(sf::Vector2f(200, 60));
    btnModelsMode.ClickButton = LoadModel;

    UserButton btnClose("CLOSE", &window);
    btnClose.SetSize(sf::Vector2f(100, 60));
    btnClose.SetFillColor(GRAY_COLOR);
    btnClose.ClickButton = CloseWindow;

    /* Кнопки Моделей*/

    for (int i = 0; i < (int)GetShapesNames().size(); i++) {
        UserButton btnShape("BE", &window);
        btnShape.SetSize(sf::Vector2f(40, 40));
        btnShape.SetFillColor(GRAY_COLOR);
        btnShape.ClickButton = ShowModels;
        collectionButtonsShapes.push_back(btnShape);
    }

    ShowCollectionShapesName(GetShapesNames());

    /* Кнопки Статус Зоны*/
    UserButton btnPause("PAUSE", &window);
    btnPause.SetSize(sf::Vector2f(80, 60));
    btnPause.SetFillColor(GRAY_COLOR);
    btnPause.ClickButton = PauseStart;

    UserButton btnSpeed_1("X-2", &window);
    btnSpeed_1.SetSize(sf::Vector2f(80, 60));
    btnSpeed_1.SetFillColor(GRAY_COLOR);
    btnSpeed_1.ClickButton = Speed_1;

    UserButton btnSpeed_2("X-1", &window);
    btnSpeed_2.SetSize(sf::Vector2f(80, 60));
    btnSpeed_2.SetFillColor(GRAY_COLOR);
    btnSpeed_2.ClickButton = Speed_2;

    UserButton btnSpeed_3("X-0.5", &window);
    btnSpeed_3.SetSize(sf::Vector2f(80, 60));
    btnSpeed_3.SetFillColor(GRAY_COLOR);
    btnSpeed_3.ClickButton = Speed_3;

    UserButton btnSpeed_4("X-0.25", &window);
    btnSpeed_4.SetSize(sf::Vector2f(80, 60));
    btnSpeed_4.SetFillColor(GRAY_COLOR);
    btnSpeed_4.ClickButton = Speed_4;

    /* Разделение кнопок по зонам экрана */
    menuZone.AddButton(btnCustomMode);
    menuZone.AddButton(btnRandomMode);
    menuZone.AddButton(btnModelsMode);
    menuZone.AddButton(btnClose);

    statusZone.AddButton(btnPause);
    statusZone.AddButton(btnSpeed_1);
    statusZone.AddButton(btnSpeed_2);
    statusZone.AddButton(btnSpeed_3);
    statusZone.AddButton(btnSpeed_4);

    for (int i = 0; i < (int)collectionButtonsShapes.size(); i++) {
        std::cout << "sdiptujhwes[doituweq[iotuwe" << std::endl;
        modelsZone.AddButton(collectionButtonsShapes[i]);
    }
}

void Screen()
{
    sf::Music music;
    music.openFromFile("audio/C418 - Subwoofer Lullaby.ogg");
    music.play();
    music.setLoop(true);

    LAExmpl.pause = true;
    LAExmpl.CreateUniverse();

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(5);

    CreateUI();

    sf::Clock clock;

    UserButton* casheBtnPause;

    for (int item = 0; item < (int)statusZone.collectionButtons.size();
         item++) {
        if (statusZone.collectionButtons[item].GetButtonName() == "PAUSE")
            casheBtnPause = &statusZone.collectionButtons[item];
    }

    // программа работает сколь угодно долго,пока открыто наше окно
    while (window.isOpen()) {
        sf::Time time1 = clock.getElapsedTime();
        // проверяем все события окна,которые были запущены после последней
        // итерации цикла

        sf::Event event;

        while (window.pollEvent(event)) {
            // если произошло событие Закрытие,закрываем наше окно
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Установка цвета фона
        window.clear(TANGERINE_COLOR);

        menuZone.DrawZone();
        gameZone.DrawZone();
        statusZone.DrawZone();
        if (modelsFLag == 1) {
            modelsZone.DrawZone(TANGERINE_COLOR);
        }

        ShowGrid(window);
        ShowPixel(window, LAExmpl.fieldArray);

        if (LAExmpl.pause) {
            casheBtnPause->SetName("START");
            Custom(gameZone);
        } else
            casheBtnPause->SetName("PAUSE");

        if (time1.asSeconds() > (LAExmpl.pause ? 9999 : speed)) {
            LAExmpl.Step();

            clock.restart();
        }

        sf::Font font;
        font.loadFromFile("fonts/" + DEFAULT_FONT);
        sf::String message = "generation = ";
        message += std::to_string(LAExmpl.GetStep());

        sf::Text textStep(message, font, DEFAULT_FONT_SIZE);

        textStep.setPosition(sf::Vector2f(
                window.getSize().x - 250,
                window.getSize().y - (statusZone.GetSize().y / 2)
                        - (textStep.getGlobalBounds().height / 2)));

        textStep.setFillColor(TANGERINE_COLOR);

        window.draw(textStep);

        // Отрисовка окна
        window.display();
    }
}