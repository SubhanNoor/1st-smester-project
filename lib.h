#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<fstream>
#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
using namespace sf;
RectangleShape createrectangle(Vector2f size, Color color, Vector2f position)
{
    RectangleShape rectangle(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}
ConvexShape createTriangle_xu(Vector2f position)
{
    ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(0.f, 0.f));    // Top point (relative)
    triangle.setPoint(1, Vector2f(-10.f, 20.f)); // Bottom-left point (relative)
    triangle.setPoint(2, Vector2f(10.f, 20.f));  // Bottom-right point (relative)
    triangle.setFillColor(Color::Red);
    triangle.setPosition(position); // Set the triangle at the desired position
    return triangle;
}
ConvexShape createTriangle_yr(Vector2f position)
{
    ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));     // Right top point (relative)
    triangle.setPoint(1, sf::Vector2f(-20.f, -10.f)); // Bottom-left point (relative)
    triangle.setPoint(2, sf::Vector2f(-20.f, 10.f));
    triangle.setFillColor(Color::Red);
    triangle.setPosition(position); // Set the triangle at the desired position
    return triangle;
}
ConvexShape createTriangle_yl(Vector2f position)
{
    ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(-10.f, 10.f));     // Right top point (relative)
    triangle.setPoint(1, sf::Vector2f(10.f, 0.f)); // Bottom-left point (relative)
    triangle.setPoint(2, sf::Vector2f(10.f, 20.f));
    triangle.setFillColor(Color::Red);
    triangle.setPosition(position); // Set the triangle at the desired position
    return triangle;
}
ConvexShape createTriangle_xd(Vector2f position)
{
    ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(-10.f, 0.f));    // Top point (relative)
    triangle.setPoint(1, Vector2f(10.f, 0.f)); // Bottom-left point (relative)
    triangle.setPoint(2, Vector2f(0.f, 20.f));  // Bottom-right point (relative)
    triangle.setFillColor(Color::Red);
    triangle.setPosition(position); // Set the triangle at the desired position
    return triangle;
}
void move(CircleShape& circle, const float move = 2.f, const float boundry = 865.f, const float boundry1 = 0.f)
{
    if (Keyboard::isKeyPressed(Keyboard::D))
    {

        circle.move(move, 0.f);
        if (circle.getPosition().x >= boundry)
        {
            circle.move(-move, 0.f);
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {

        circle.move(-move, 0.f);
        if (circle.getPosition().x <= boundry1)
        {
            circle.move(move, 0.f);
        }
    }
}
void move2(CircleShape& circle, const float move = 2.f, const float boundry = 865.f, const float boundry1 = 0.f)
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        circle.move(move, 0.f);
        if (circle.getPosition().x >= boundry)
        {
            circle.move(-move, 0.f);
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        circle.move(-move, 0.f);
        if (circle.getPosition().x <= boundry1)
        {
            circle.move(move, 0.f);
        }
    }
}
void jump(CircleShape& circle, float& V, float& JV, float& G, bool& check, const float move = 4.f, const float boundry = 865.f, const float boundry1 = 0.f, float height = 460.f)
{
    if (Keyboard::isKeyPressed(Keyboard::Space) && check)
    {
        V = JV;
        check = false;
    }
    V += G;
    if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::Space))
    {
        circle.move(move, V);
        if (circle.getPosition().x >= boundry)
        {
            circle.move(-move, 0.f);
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::Space))
    {
        circle.move(-move, V);
        if (circle.getPosition().x <= boundry1)
        {
            circle.move(move, 0.f);
        }
    }
    else
    {
        circle.move(0.f, V);

    }
    if (circle.getPosition().y >= height)
    {
        circle.setPosition(circle.getPosition().x, height);
        check = true;
        V = 0.f;
    }
}
void jump1(CircleShape& circle, float& V, float& JV, float& G, bool& check, const float move = 4.f, const float boundry = 865.f, const float boundry1 = 0.f, float height = 460.f)
{
    if (Keyboard::isKeyPressed(Keyboard::Space) && check)
    {
        V = JV;
        check = false;
    }
    V += G;
    if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::Space))
    {
        circle.move(-move, V);
        if (circle.getPosition().x >= boundry)
        {
            circle.move(move, 0.f);
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::Space))
    {
        circle.move(move, V);
        if (circle.getPosition().x <= boundry1)
        {
            circle.move(-move, 0.f);
        }
    }
    else
    {
        circle.move(0.f, V);

    }
    if (circle.getPosition().y >= height)
    {
        circle.setPosition(circle.getPosition().x, height);
        check = true;
        V = 0.f;
    }
}
void Collision(CircleShape& circle, RectangleShape rectangle[], int& randomIndex, float size, bool& check, float& V, float& G)
{
    bool isOnPlatform = false, ch = true;
    for (int i = 0; i < size; i++)
    {
        if (circle.getPosition().x + circle.getRadius() * 2 == rectangle[i].getPosition().x &&
            ((abs(rectangle[i].getPosition().y - circle.getPosition().y) >= 0) &&
                (abs(rectangle[i].getPosition().y - circle.getPosition().y) <= 5)))
        {
            circle.move(-2.f, 0.f);
        }
        else if (circle.getPosition().x == (rectangle[i].getPosition().x + rectangle[i].getSize().x) &&
            ((abs(rectangle[i].getPosition().y - circle.getPosition().y) >= 0) &&
                (abs(rectangle[i].getPosition().y - circle.getPosition().y) <= 5)))
        {
            circle.move(2.f, 0.f);
        }
        else if ((circle.getPosition().y + circle.getRadius() * 2) - rectangle[i].getPosition().y <= 1)
        {
            ch = true;
        }
        else if (circle.getGlobalBounds().intersects(rectangle[i].getGlobalBounds()))
        {
            if (circle.getPosition().y + circle.getRadius() * 2 > rectangle[i].getPosition().y + rectangle[i].getSize().y)
            {
                // Circle intersects from below
                ch = false;  // Prevent it from snapping to the top
                //isOnPlatform = false;
            }
            else if (i == randomIndex)
            {
                isOnPlatform = false;
            }
            else if (ch)
            {
                isOnPlatform = true;
                V = 0.f;
                circle.setPosition(circle.getPosition().x, rectangle[i].getPosition().y - circle.getRadius() * 2);
                check = true;
            }
        }
        else
        {
            isOnPlatform = false;
        }

    }

    if (!isOnPlatform)
    {
        V += G;
    }
}
void jumping(CircleShape& circle, float& V, float& JV, float& G,float&height)
{
    
        if (circle.getPosition().y>=height)
        {
            V = JV;
        }
        circle.move(0.f, V);
        V+= G;


}
void hurdle(ConvexShape any[], int b, CircleShape& circle,RenderWindow &win,float &c_x,float&c_y) 
{
    Vector2f position = circle.getPosition();
    for (int i = 0; i < b; i++)
    {
        if (circle.getGlobalBounds().intersects(any[i].getGlobalBounds()))
        {
            circle.setPosition(c_x, c_y);
            win.draw(circle);
            win.display();
        }
    }
}
void press(RectangleShape& rectangle,RectangleShape rec[],int b, CircleShape& circle, bool &check,float &y)
{
    while (rectangle.getGlobalBounds().intersects(circle.getGlobalBounds()))
    {
        rectangle.move(0.f, 0.5f); 
        check = true;
        
    }
    if (check)
    {
        rec[b].move(0.f, -2.f);
        if (rec[b].getPosition().y <= 65.f)
        {
            rec[b].move(0.f, 2.f);
            rectangle.move(0.f, -0.5f);
            if (rectangle.getPosition().y <=y )
            {
                rectangle.move(0.f, 0.5f);
            }
        }
    }
}
void press2(RectangleShape &rec, CircleShape& circle, float& y)
{

    while (circle.getGlobalBounds().intersects(rec.getGlobalBounds()))
    {
        rec.move(0.f, 0.5f);
    }

        rec.move(0, -0.5);
        if (rec.getPosition().y <= y)
        {

            rec.move(0.f, 0.5f);
        }
    
}
void press1(RectangleShape rec[], int b, CircleShape& circle,float &y)
{
    for (int i = 0; i <= b; i++)
    {
        while (rec[i].getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
            rec[i].move(0.f, 1.5f);
        }

            rec[i].move(0, -1.5);
            if (rec[i].getPosition().y <= y)
            {
                rec[i].move(0.f, 1.5f);
            }
        

    }
}
void press3(RectangleShape rec[], int b, CircleShape& circle, float& y)
{
    for (int i = 0; i <= b; i++)
    {
        while (rec[i].getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
            rec[i].move(0.f, 1.5f);
        }


    }
}
void press4(RectangleShape rec[], int b, CircleShape& circle, float& x)
{
    for (int i = 0; i <= b; i++)
    {
        while (rec[i].getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
            rec[i].move(-1.5f, 0.f);
        }

        rec[i].move(1.5f, 0);
        if (rec[i].getPosition().x >= x)
        {
            rec[i].move(-1.5f, 0.f);
        }
    }
}
void press5(RectangleShape rec[], int b, CircleShape& circle, float& x)
{
    for (int i = 0; i <= b; i++)
    {
        while (rec[i].getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
            rec[i].move(1.5f, 0.f);
        }

        rec[i].move(-1.5f, 0);
        if (rec[i].getPosition().x <= x)
        {
            rec[i].move(1.5f, 0.f);
        }
    }
}
void applyTransition(RenderWindow& window, float duration, Sprite& sprite)
{
    Clock clock; // Start the clock to track time
    float elapsed = 0.f; // Elapsed time in seconds

    // Transition loop (stays active until transition completes)
    while (elapsed < duration)
    {
        elapsed = clock.getElapsedTime().asSeconds(); // Get elapsed time

        // Phase 1: Fade in (first half of the duration)
        if (elapsed <= duration / 2.f)
        {
            float alpha = (elapsed / (duration / 2.f)) * 255; // Calculate alpha (increasing)
            sprite.setColor(Color(255, 255, 255, static_cast<Uint8>(alpha)));
        }
        // Phase 2: Fade out (second half of the duration)
        else if (elapsed > duration / 2.f)
        {
            float alpha = 255 - ((elapsed - duration / 2.f) / (duration / 2.f)) * 255; // Calculate alpha (decreasing)
            sprite.setColor(Color(255, 255, 255, static_cast<Uint8>(alpha)));
        }

        // Clear the window and draw the sprite
        window.draw(sprite);
        window.display();
    }
}
void hurdle1(Sprite sp, CircleShape& circle, RenderWindow& win, float& c_x, float& c_y)
{
        if (circle.getGlobalBounds().intersects(sp.getGlobalBounds()))
        {
            circle.setPosition(c_x, c_y);
            win.draw(circle);
            win.display();
        }
    
}
void Collision1(CircleShape& circle, RectangleShape rectangle[], int& randomIndex, float size, bool& check, float& V, float& G)
{
    bool isOnPlatform = false;
    for (int i = 0; i < size; i++)
    {
        if (circle.getGlobalBounds().intersects(rectangle[i].getGlobalBounds()))

        {
            if (i == randomIndex)
            {
                isOnPlatform = false;

            }
            else
            {
                isOnPlatform = true;
                V = 0.f;
                circle.setPosition(circle.getPosition().x, rectangle[i].getPosition().y - circle.getRadius() * 2);
                check = true;
            }
        }
    }
}
void scrn_display(RenderWindow& window, const Texture& scrn_texture)
{
    Sprite wlcm_scrn(scrn_texture);
    Clock time;
    float elapsedTime = 0.0f;

    while (window.isOpen())
    {
        Event event_change;
        while (window.pollEvent(event_change))
        {
            if (event_change.type == Event::Closed)
            {
                window.close();
            }
        }

        elapsedTime += time.restart().asSeconds();

        if (elapsedTime >= 3.0f)
        {
            break;
        }

        window.clear();
        window.draw(wlcm_scrn);
        window.display();
    }
}
void navigation(RenderWindow& window, const Texture& menu_texture, Music& bg_music, Sound& navigation_sound, const Font& font,int &c, string &a,fstream &file)
{
    string kk;
    file.open("gamefile.txt", ios::in);
    if (file.is_open()) 
    {
        file >> kk;
        file.close();
    }
    c = stoi(kk);
    Sprite main_menu(menu_texture);
    // Text for menu options
    Text Continue("Continue", font, 40);
    Continue.setPosition(345, 150);
    Continue.setFillColor(Color::White);

    Text NewGame("New Game", font, 40);
    NewGame.setPosition(335, 230);
    NewGame.setFillColor(Color::White);

    Text Exit("Exit", font, 40);
    Exit.setPosition(400, 310);
    Exit.setFillColor(Color::White);
    bg_music.play();
    navigation_sound.setVolume(250);
    int defaultselect = 0; // 0 = Continue, 1 = New Game, 2 = Exit
    while (window.isOpen())
    {
        Event any_event;
        while (window.pollEvent(any_event))
        {
            if (any_event.type == Event::Closed)
            {
                window.close();
            }

            if (any_event.type == Event::KeyPressed)
            {
                if (any_event.key.code == Keyboard::Up)
                {
                    defaultselect = (defaultselect - 1 + 3) % 3;
                    navigation_sound.play();
                }                                                                 
                if (any_event.key.code == Keyboard::Down)
                {
                    defaultselect = (defaultselect + 1) % 3;
                    navigation_sound.play();
                }
                if (any_event.key.code == Keyboard::Enter)
                {
                    if (defaultselect == 0&&c>=1)
                    {
                        file.open("gamefile.txt",ios::in);
                        if (file.is_open())
                        {
                            file >> a;
                            file.close();
                        }
                        c = stoi(a);
                        window.close();

                    }
                    else if (defaultselect == 1)
                    {
                        file.open("gamefile.txt",ios::out);
                        if (file.is_open())
                        {
                            int k = 1;
                            c = 1;
                            file << k;
                            file << c;
                            file.close();
                            
                        }
                        window.close();
                    }
                    else if (defaultselect == 2)
                    {
                        file.open("gamefile.txt", ios::out);
                        if (file.is_open())
                        {
                            int k = 0;
                            file << k;
                            file.close();
                        }
                        c = -1;
                        window.close();
                    }
                }
            }
        }
        // Update text colors based on selection
        Continue.setFillColor(defaultselect == 0 ? Color(144, 238, 144) : Color::White);
        NewGame.setFillColor(defaultselect == 1 ? Color(139, 128, 0) : Color::White);
        Exit.setFillColor(defaultselect == 2 ? Color(255, 0, 0) : Color::White);

        window.clear();
        window.draw(main_menu);
        window.draw(Continue);
        window.draw(NewGame);
        window.draw(Exit);
        window.display();
    }
}