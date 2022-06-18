#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gui.h"



#define FONT_PATH                   "Banty Bold.ttf"
#define HEXAGON_DX                  0.f
#define HEXAGON_DY                  50.f
#define TEXT_DX                     -18.f
#define TEXT_DY                     -20.f
#define TEXT_SINGLE_DX              10.f
#define HEXAGON_SIZE                25.f
#define HEXAGON_OTLINE_THICKNESS    5.f
//#define SHOW_CELLS_COORDINATES    false


void Gui::draw(std::vector<std::vector<Object::ObjectType>> result ,WorldSize* w)
{
    sf::CircleShape Crc1;

    int x = 0, y = 0, k = 0;

    Crc1.setRadius(20);                                 ///  радиус
    Crc1.setPointCount(6);                              ///  граница
    Crc1.setOutlineColor(sf::Color(70, 70, 70));        ///  цвет гр          /* поле */
    Crc1.setOutlineThickness(3);                        ///  толщина границы 
    Crc1.setFillColor(sf::Color(120, 120, 120));        ///  цвет внутри

    sf::Event event;

    //while (mWindow.pollEvent(event))
    //{
    //    if (event.type == sf::Event::MouseButtonPressed)
    //    {
    //        if (event.mouseButton.button == sf::Mouse::Right)
    //        {
    //            std::cout << " ASD ";
    //        }
    //    }
    //    if (event.type == sf::Event::KeyReleased)
    //    {
    //        switch (event.key.code)
    //        {
    //            case (sf::Keyboard::Key::Z):
    //            {
    //                bool q = w->make_a_pause;
    //                w->make_a_pause = !q;
    //                std::cout << "ASDASD" << std::endl;
    //                break;
    //            }
    //            case (sf::Keyboard::Key::C):
    //            {
    //                bool q = w->need_to_draw;
    //                w->need_to_draw = !q;
    //                std::cout << "ASDASasD" << std::endl;
    //                break;
    //            }
    //            
    //        }
    //        if (event.type == sf::Event::Closed)
    //            mWindow.close();
    //        
    //    }
    //    //sf::Font font;//шрифт 

    //    //if (!font.loadFromFile("111.ttf"))
    //    //{
    //    //    std::cout << "Font load error!\n";
    //    //}

    //}


    sf::View view1;
    mWindow.clear();

    for (int i = 0; i < result.size()-(w->x_draw); i++) {
        for (int j = 0; j < result[0].size()-(w->y_draw); j++)
        {

                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::VOID)
                    Crc1.setFillColor(sf::Color(120, 120, 120));    //  пусто + !!!!


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::BOT)         // бот    +
                    Crc1.setFillColor(sf::Color(250, 250, 20));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::FOOD)        // еда    +
                    Crc1.setFillColor(sf::Color(12, 180, 12));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::POISON)     // яд     
                    Crc1.setFillColor(sf::Color(250, 0, 0));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::WALL)        // стена
                    Crc1.setFillColor(sf::Color(70, 70, 70));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::NUN)         // 0
                    Crc1.setFillColor(sf::Color(0, 0, 0));



                if (i % 2 == 1)
                    x = j * 37+19 ;// +19;
                

                if (i % 2 == 0)
                    x = j * 37;
                
                Crc1.setPosition(x, y);
                mWindow.draw(Crc1);
 #ifdef SHOW_CELLS_COORDINATES
                 sf::Text text("asdfjkashjkf", font, 20);             //создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
                 text.setStyle(sf::Text::Bold);                        //жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
                 text.setFillColor(sf::Color::White);
                 text.setPosition(10, 10);                    //задаем позицию текста, центр камеры

                 text.setScale(sf::Vector2f(0.5, 0.5));
                 text.setPosition(x + 10, y + 10);
                 text.setString(std::to_string(i) + " " + std::to_string(j));
                 mWindow.draw(text);
                 text.setScale(sf::Vector2f(1, 1));
#endif // SHOW_CELLS_COORDINATES
            }
            y = (i+1) * 34;
        }
        //  mWindow.draw(text);//рисую этот текст
        mWindow.display();
}

//Gui::Gui(sf::RenderWindow& aWindow) :
Gui::Gui( int x, int y) :
    mWindow(sf::VideoMode(x, y), "EvOlUtIoN",sf::Style::Fullscreen)
{
    mWindow.setVerticalSyncEnabled(true);
    mWindow.setFramerateLimit(30);
};     ///  поле};
Gui::~Gui() 
{
    fin.close();
};

std::vector<Gui::EventType> Gui::get_events()
{
    std::vector<Gui::EventType> result;
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Key::Z :
                {
                    result.push_back(Gui::EventType::SWITCH_PAUSE);
                    break;
                }
                case sf::Keyboard::Key::C :
                {
                    result.push_back(Gui::EventType::SWITCH_DRAW_MODE);
                    break;
                }
                case sf::Keyboard::Key::Q :
                {
                    result.push_back(Gui::EventType::INCREASE_SPEED);
                    break;
                }
                case sf::Keyboard::Key::W :
                {
                    result.push_back(Gui::EventType::DECREASE_SPEED);
                    break;
                }
                case sf::Keyboard::Key::Space :
                {
                    result.push_back(Gui::EventType::STANDART_PAUSE);
                    break;
                }
                case sf::Keyboard::Key::G:
                {
                    result.push_back(Gui::EventType::DRAW_GRAPH);
                    break;
                }
            }
        }
    }
    return result;
}

sf::VertexArray Gui::zad()
{
    int n = 0, pr = 0;
    std::vector<int> Vec;

    fin.open("out.out");
    while (fin >> n)
    {
        fin >> pr;
        Vec.push_back(pr/10);
    }
    fin.close();

    sf::VertexArray lines(sf::Lines, Vec.size());
    lines[0].position = sf::Vector2f(0, 1080);

    for (int i = 1; i < Vec.size(); ++i)
    {
        lines[i].position = sf::Vector2f(i, 1080 - Vec[i]);
    }
    return lines;
};

void Gui::draw_graph(sf::VertexArray asd)
{
    mWindow.clear();
    mWindow.draw(asd);
    mWindow.display();
}
