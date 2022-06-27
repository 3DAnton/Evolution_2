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

    Crc1.setRadius(20);                                 ///  ������
    Crc1.setPointCount(6);                              ///  �������
    Crc1.setOutlineColor(sf::Color(70, 70, 70));        ///  ���� ��          /* ���� */
    Crc1.setOutlineThickness(3);                        ///  ������� ������� 
    Crc1.setFillColor(sf::Color(120, 120, 120));        ///  ���� ������

    sf::Event event;

    sf::View view1;
    mWindow.clear();

    for (int i = 0; i < result.size()-(w->x_draw); i++) {
        for (int j = 0; j < result[0].size()-(w->y_draw); j++)
        {

                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::VOID)
                    Crc1.setFillColor(sf::Color(120, 120, 120));    //  ����� + !!!!


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::BOT)         // ���    +
                    Crc1.setFillColor(sf::Color(250, 250, 20));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::FOOD)        // ���    +
                    Crc1.setFillColor(sf::Color(12, 180, 12));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::POISON)     // ��     
                    Crc1.setFillColor(sf::Color(250, 0, 0));


                if (result[i + (w->x_draw)][j + (w->y_draw)] == Object::ObjectType::WALL)        // �����
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
                 sf::Text text("asdfjkashjkf", font, 20);             //������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
                 text.setStyle(sf::Text::Bold);                        //������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������
                 text.setFillColor(sf::Color::White);
                 text.setPosition(10, 10);                    //������ ������� ������, ����� ������

                 text.setScale(sf::Vector2f(0.5, 0.5));
                 text.setPosition(x + 10, y + 10);
                 text.setString(std::to_string(i) + " " + std::to_string(j));
                 mWindow.draw(text);
                 text.setScale(sf::Vector2f(1, 1));
#endif // SHOW_CELLS_COORDINATES
            }
            y = (i+1) * 34;
        }
        //  mWindow.draw(text);//����� ���� �����
        mWindow.display();
}


//Gui::Gui(sf::RenderWindow& aWindow) :
Gui::Gui( int x, int y) :
    mWindow(sf::VideoMode(x, y), "EvOlUtIoN")
{                };     ///  ����};

Gui::~Gui() 
{  fin.close();  };


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

sf::VertexArray Gui::graph()
{
    int n = 0, pr = 0, kf = 10;
    std::vector<int> Vec;

    fin.open("out.out");
    while (fin >> n)
    {
        fin >> pr;
        Vec.push_back(pr / 10);                                 
    }
    fin.close();

    sf::VertexArray lines(sf::Lines, Vec.size() + Vec.size()/kf+1);
    
    if (Vec.size() > 1920) {
        Vec.erase(Vec.begin(), Vec.end() - 1920);
        lines[Vec.size() - 1].position = sf::Vector2f(1920, 1080);
    }

    lines[0].position = sf::Vector2f(0, 1080);
    for (int i = 1 ; i < Vec.size() - 1; i+=2)
    {
        lines[i].position = sf::Vector2f(i, 1080 - Vec[i]);
        lines[i + 1].position = sf::Vector2f(i, 1080 - Vec[i]);
    }
    lines[Vec.size()-1].position = sf::Vector2f(Vec.size(), 1080 - Vec[Vec.size()-1]);

    
    lines[Vec.size()].position = sf::Vector2f(0, 1080 - (Vec[0]+Vec[1])/2);
    lines[Vec.size()].color = sf::Color::Yellow;                       ///
                                                                    
    for (int i = Vec.size()+1, j = 0; i < Vec.size() + Vec.size() / kf && j < Vec.size()-kf; i+=2, j++)
    {
        int md = 0;                                                               
        for(; j%kf < kf-1; ++j)                     //  while (j % (kf + 1) < kf && j < Vec.size() - 1)
       {
           md += Vec[j];
       }
        
       md /= j % kf;
     
        lines[i].position = sf::Vector2f(j % 1920, 1080 - md);
        lines[i].color = sf::Color::Red;
        lines[i + 1].position = sf::Vector2f(j % 1920, 1080 - md);
        lines[i + 1].color = sf::Color::Red;

    }
    lines[Vec.size() + Vec.size() / kf].position = sf::Vector2f(Vec.size(), 1080 - (Vec[Vec.size() - 1] + Vec[Vec.size() - 2]) / 2);
    lines[Vec.size() + Vec.size() / kf].color = sf::Color::Blue;                ///


    return lines;
};

void Gui::draw_graph(sf::VertexArray asd)
{
    mWindow.clear();
    mWindow.draw(asd);
    mWindow.display();
}