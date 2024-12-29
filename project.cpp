#include"lib.h"
int main()
{
    fstream file;
    //Texture and audio for main menu
    int for_con = 0;
    string counter = "1";
    Texture splashTexture;
    if (!splashTexture.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/background/main menu.jpg"))
    {
        cout << "Error loading splash screen" << endl;
        return -1;
    }
    Texture menuTexture;
    if (!menuTexture.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/background/mainmenu.jpg")) {
        cout << "Error loading main menu screen!" << endl;
        return -1;
    }
    Font font;
    if (!font.loadFromFile("C:/ALL/Programs/Semester 1 project/font/Paperkind.ttf"))
    {
        cout << "Error loading font" << endl;
        return -1;
    }
    Music bg_music;
    if (!bg_music.openFromFile("C:/ALL/Programs/Semester 1 project/Assets/background/sound.wav"))
    {
        cout << "Error loading background music!" << endl;
        return -1;
    }
    bg_music.setLoop(true);
    SoundBuffer selection_effect;
    if (!selection_effect.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/background/aound.wav"))
    {
        cout << "Error loading selection sound!" << endl;
        return -1;
    }
    //end
    RenderWindow screen(VideoMode(900, 500), "Game Menu");
    Sound selectionSound;
    selectionSound.setBuffer(selection_effect);
    scrn_display(screen, splashTexture);
    navigation(screen, menuTexture, bg_music, selectionSound, font, for_con, counter, file);
    //Texture of the character 
    Texture ch1, ch2, ch3, lv1, lv2, lv3, lv4, lv5, lv6, end;
    //load from file
    ch1.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/mj.png");
    ch2.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/mjj.png");
    ch3.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/mjjj.png");
    lv1.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/level1.png");
    lv2.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/level2.png");
    lv3.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/level3.png");
    lv4.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/level4.png");
    lv5.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/level5.png");
    lv6.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/level6.png");
    end.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/End.png");
    //smooth the corner of the ball
    ch1.setSmooth(true);
    ch2.setSmooth(true);
    ch3.setSmooth(true);
    //sprite
    Sprite lvl1, lvl2, lvl3, lvl4, lvl5, lvl6, End;
    //give them texture
    lvl1.setTexture(lv1);
    lvl2.setTexture(lv2);
    lvl3.setTexture(lv3);
    lvl4.setTexture(lv4);
    lvl5.setTexture(lv5);
    lvl6.setTexture(lv6);
    End.setTexture(end);
    // may be varaiables 
    int count = 0;
    int garbage = 100;
    //varaiables for all level 
    float gravity = 0.5f, Velocity_y = 0.f, jumpVelocity = -13.f;
    bool isjumping = true, check = false, levels = true, set = true, hitspike = false;
    float transition_time = 3, c_x = 0.f, c_y = 210.f;
    Clock clock1;
    float el1;
    //End
    //varaibles for level 1
    float b_p = 190;
    const int size = 17;
    const int s1 = 50;
    ConvexShape h[s1];
    RectangleShape rectangle[size];
    //End
    //variables for level 2
    const int size2 = 6;
    const float length = 150.f, width = 20.f, width1 = 30.f;
    float position_x = 0.f, position_y = 250.f;
    int randomIndex = 1 + rand() % (size2 - 2);
    float random_x = 0.f;
    float  g_y = 450.f, g_x = 750.f;
    ConvexShape h2[45];
    RectangleShape rect[size2];
    srand(static_cast<unsigned int>(time(nullptr)));
    const int s2 = 45;
    //End
    // variables for level 3
    const int size3 = 13;
    RectangleShape rect3[size3], gate[2];
    const int s3 = 104, b_3 = 3;
    RectangleShape button3[b_3];
    ConvexShape h3[s3];
    float c_x3 = 25.f, c_y3 = 40.f;
    float b_p2 = 160.f, b_p3 = 285, b_p4 = 380;
    bool c3 = false, c_3 = false, c__3 = false;
    //End 
    //varaibles for level 4
    const int size4 = 13, s4 = 39;
    RectangleShape rect4[size4], but4[3];
    ConvexShape h4[s4];
    float b4_0 = 190, b4_1 = 340, b4_2 = 490;
    bool c4 = false, c4_1 = false, c4_2 = false, level4 = true;
    float c_x4 = 800, c_y4 = 30;
    //End
    // Texture for level 4
    Texture c_spike;
    c_spike.loadFromFile("C:/ALL/Programs/Semester 1 project/Assets/circle spike.png");
    //sprite for level 4
    Sprite  sp_1;
    //varaibles for level 5
    const int size5 = 8;
    RectangleShape rect5[size5], but5_1, but5_2, but5_3, but5_4;
    CircleShape circle(20);
    circle.setTexture(&ch1);
    circle.setPosition(0.f, 210.f);
    const int s5 = 90;
    ConvexShape h5[s5];
    float b_5p0 = 192.f, b_5p1 = 262.f, b_5p2 = 222.f, b_5p3 = 280.f;
    bool  c_5 = false, c_51 = false, c_52 = false, c_53 = false, c_54 = false, c_55 = false;
    float c_x5 = 0.f, c_y5 = 210.f;
    //End
    // Variavle for level 6
    bool c6 = true, c6_1 = false, c6_2 = false;
    float height = 300;
    const int size6 = 10, s6 = 49;
    float  b_p6 = 340;
    Clock clock;
    float c_x6 = 860.f, c_y6 = 310.f;
    RectangleShape rect6[size6], pform[2], but6[5];
    ConvexShape h6[s6];
    //End
    Font state;
    state.loadFromFile("C:/ALL/Programs/Semester 1 project/font/Paperkind.ttf");
    Text op[3];
    string labels[3] = { "LEFT", "RIGHT", "UP" };
    for (int i = 0; i < 3; i++)
    {
        op[i].setFont(state);
        op[i].setString(labels[i]);
        op[i].setCharacterSize(30);
        op[i].setFillColor(Color::White);
    }
    op[0].setPosition(200, 400);
    op[1].setPosition(700, 400);
    op[2].setPosition(450, 200);
    //end
    //level 1 hurdles
    float b_x = 20.f, b_y = 465.f;
    for (int i = 0; i < 10; i++)
    {
        h[i] = createTriangle_yr(Vector2f(b_x, b_y));
        b_y -= 20.f;
    }
    b_y = 10.f;
    for (int i = 10; i < 16; i++)
    {
        h[i] = createTriangle_yr(Vector2f(b_x, b_y));
        b_y += 20.f;
    }
    b_y = 65.f, b_x = 385.f;
    for (int i = 16; i < 23; i++)
    {
        h[i] = createTriangle_xd(Vector2f(b_x, b_y));
        b_x += 20;
    }
    b_y = 220.f, b_x = 375.f;
    for (int i = 23; i < 31; i++)
    {
        h[i] = createTriangle_xd(Vector2f(b_x, b_y));
        b_x += 20;
    }
    b_x = 610.f, b_y = 170.f;
    for (int i = 31; i < 37; i++)
    {
        h[i] = createTriangle_xd(Vector2f(b_x, b_y));
        b_x += 20;
    }
    b_x = 890.f, b_y = 8.f;
    for (int i = 37; i < 44; i++)
    {
        h[i] = createTriangle_yl(Vector2f(b_x, b_y));
        b_y += 20;
    }
    b_y = 275.f;
    for (int i = 44; i < 50; i++)
    {
        h[i] = createTriangle_yl(Vector2f(b_x, b_y));
        b_y += 20;
    }
    b_x = 10.f, b_y = 480.f;
    //End here
    //hurdles for level 2
    for (int i = 0; i < s2; i++)
    {
        h2[i] = createTriangle_xu(Vector2f(b_x, b_y));
        b_x += 20.f;
    }
    //End Here
    //Character
//For winow open 
    RenderWindow window;
    window.create(VideoMode(900, 500), "Level 1", Style::Default);
    //Position of Rectangle for level 1
    window.setFramerateLimit(60);
    {
        rectangle[0] = createrectangle(Vector2f(120.f, 20.f), Color::Black, Vector2f(0.f, 250.f));
        rectangle[1] = createrectangle(Vector2f(120.f, 20.f), Color::Black, Vector2f(0.f, 120.f));
        rectangle[2] = createrectangle(Vector2f(100.f, 20.f), Color::Black, Vector2f(200.f, 120.f));
        rectangle[3] = createrectangle(Vector2f(150.f, 65.f), Color::Black, Vector2f(370.f, 0.f));
        rectangle[4] = createrectangle(Vector2f(150.f, 35.f), Color::Black, Vector2f(0.f, 475.f));
        rectangle[5] = createrectangle(Vector2f(100.f, 20.f), Color::Black, Vector2f(220.f, 270.f));
        rectangle[6] = createrectangle(Vector2f(150.f, 80.f), Color::Black, Vector2f(370.f, 460.f));
        rectangle[7] = createrectangle(Vector2f(170.f, 20.f), Color::Black, Vector2f(360.f, 200.f));
        rectangle[8] = createrectangle(Vector2f(120.f, 20.f), Color::Black, Vector2f(600.f, 150.f));
        rectangle[9] = createrectangle(Vector2f(120.f, 20.f), Color::Black, Vector2f(600.f, 300.f));
        rectangle[10] = createrectangle(Vector2f(-200.f, 40.f), Color::Black, Vector2f(900.f, 480.f));
        rectangle[11] = createrectangle(Vector2f(-200.f, 40.f), Color::Black, Vector2f(940.f, 440.f));
        rectangle[12] = createrectangle(Vector2f(-200.f, 40.f), Color::Black, Vector2f(980.f, 400.f));
        rectangle[13] = createrectangle(Vector2f(-120.f, 20.f), Color::Black, Vector2f(900.f, 150.f));
        rectangle[14] = createrectangle(Vector2f(-120.f, 20.f), Color::Black, Vector2f(900.f, 250.f));
        rectangle[15] = createrectangle(Vector2f(120.f, 20.f), Color::Black, Vector2f(390.f, 350.f));
        rectangle[16] = createrectangle(Vector2f(20.f, 100.f), Color::Black, Vector2f(800.f, 170.f));
        gate[0] = createrectangle(Vector2f(50.f, 50.f), Color::Black, Vector2f(850.f, 200.f));
        gate[1] = createrectangle(Vector2f(40.f, 45.f), Color::White, Vector2f(854.f, 205.f));
    }
    //End Here 
    // Rectangle for transition
    RectangleShape blackScreen(Vector2f(900.f, 500.f));
    //Rectagle for button for level 1
    RectangleShape button = createrectangle(Vector2f(80.f, 20.f), Color::Black, Vector2f(400.f, 190.f));
    string cc;
    file.open("gamefile.txt", ios::in);
    if (file.is_open())
    {
        file >> cc;
        file.close();
    }
    int x = stoi(cc);
    for_con = x;
    if (for_con == 2)
    {
        goto lv2;
    }
    else if (for_con == 3)
    {
        goto lv3;
    }
    else if (for_con == 4)
    {
        goto lv4;
    }
    else if (for_con == 5)
    {
        goto lv5;
    }
    else if (for_con == 6)
    {
        goto lv6;
    }
    //apply transition
    if (for_con >= 1)
    {
        applyTransition(window, transition_time, lvl1);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
                {
                    if (bg_music.getStatus() == sf::Sound::Playing)
                    {
                        bg_music.pause(); // Pause the sound
                    }
                    else
                    {
                        bg_music.play(); // Resume the sound
                    }
                }
            }
            if (levels)
            {
                //space and arraow key
                jump(circle, Velocity_y, jumpVelocity, gravity, isjumping);
                //character moving 
                move(circle);
                //hurdle check
                hurdle(h, s1, circle, window, c_x, c_y);
                // button check
                press(button, rectangle, 16, circle, check, b_p);
                // Collision check
                Collision(circle, rectangle, garbage, size, isjumping, Velocity_y, gravity);
            }
            window.clear(Color(47, 47, 47));// connsidertaion charcol
            if (circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()))
            {
                levels = false;
                if (set)
                {
                    clock1.restart();
                    circle.setPosition(gate[1].getPosition().x, gate[1].getPosition().y);
                    set = false;
                }
                gate[0].move(2.f, 0.f);
                gate[1].move(2.f, 0.f);
                circle.move(2.f, 0.f);
            }
            //draw rectangle for level 1
            for (int i = 0; i < size; i++)
            {
                window.draw(rectangle[i]);
            }
            //draw spikes for level 1
            for (int i = 0; i < s1; i++)
            {
                window.draw(h[i]);
            }
            //draw for button
            window.draw(button);
            window.draw(gate[0]);
            window.draw(gate[1]);
            window.draw(circle);
            window.display();
            el1 = clock1.getElapsedTime().asSeconds();
            //level complete
            //level 2 
            if (circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()) && count == 0 && el1 >= 1)
            {
            lv2:
                for_con = 2;
                file.open("gamefile.txt", ios::out);
                if (file.is_open())
                {
                    file << for_con;
                    file.close();
                }
                applyTransition(window, transition_time, lvl2);
                window.setTitle("level 2");
                circle.setPosition(c_x, c_y);
                //Position of Random Block and others too for level 2 
                set = true;
                levels = true;
                for (int i = 0; i < size2; i++)
                {
                    rect[i].setSize((i == randomIndex) ? (Vector2f(length, width)) : (Vector2f(length, width)));
                    rect[i].setPosition(position_x, position_y);
                    rect[i].setFillColor((i == randomIndex) ? Color::Black : Color::Black);
                    position_x += length;
                }
                gate[0].setPosition(850, 200);
                gate[1].setPosition(854, 205);
                count = 1;
                while (window.isOpen())
                {
                    while (window.pollEvent(event))
                    {
                        if (event.type == Event::Closed)
                        {
                            window.close();
                        }
                        if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
                        {
                            if (bg_music.getStatus() == sf::Sound::Playing)
                            {
                                bg_music.pause(); // Pause the sound
                            }
                            else
                            {
                                bg_music.play(); // Resume the sound
                            }
                        }
                    }
                    window.clear(Color(47, 47, 47));
                    window.draw(gate[0]);
                    window.draw(gate[1]);
                    window.draw(circle);
                    //check for falling ans reset the position of character and change the value random index 
                    if (circle.getPosition().y >= g_y)
                    {
                        circle.setPosition(c_x, c_y);
                        randomIndex = 1 + rand() % (size2 - 2);
                    }
                    //draw spikes for level2
                    for (int i = 0; i < s2; i++)
                    {
                        window.draw(h2[i]);
                    }
                    //draw rectangle for level 2 
                    for (int i = 0; i < size2; i++)
                    {
                        window.draw(rect[i]);
                    }
                    if (levels)
                    {

                        //move
                        move(circle);
                        //jump
                        jump(circle, Velocity_y, jumpVelocity, gravity, isjumping);
                        // Collision check
                        Collision(circle, rect, randomIndex, size2, isjumping, Velocity_y, gravity);
                    }
                    if (circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()))
                    {
                        levels = false;
                        if (set)
                        {
                            clock1.restart();
                            circle.setPosition(gate[1].getPosition().x, gate[1].getPosition().y);
                            set = false;
                        }
                        gate[0].move(2.f, 0.f);
                        gate[1].move(2.f, 0.f);
                        circle.move(2.f, 0.f);
                    }
                    el1 = clock1.getElapsedTime().asSeconds();
                    window.display();
                    //level complete
                   //level 3
                    if ((circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()) && count == 1) && el1 >= 1)
                    {
                    lv3:

                        for_con = 3;
                        file.open("gamefile.txt", ios::out);
                        if (file.is_open())
                        {
                            file << for_con;
                            file.close();
                        }
                        levels = true;
                        count = 2;
                        applyTransition(window, transition_time, lvl3);
                        window.setTitle("level 3");
                        circle.setTexture(&ch3);
                        //level 3 hurdles
                    sp3:
                        set = true;
                        gate[0].setPosition(0, 350);
                        gate[1].setPosition(4, 354);
                        c3 = false;
                        c_3 = false;
                        c__3 = false;
                        b_x = 30.f, b_y = 480.f;
                        for (int i = 0; i < 44; i++)
                        {
                            h3[i] = createTriangle_xu(Vector2f(b_x, b_y));
                            b_x += 20.f;
                        }
                        b_x = 55.f, b_y = 0.f;
                        for (int i = 44; i < 89; i++)
                        {
                            h3[i] = createTriangle_xd(Vector2f(b_x, b_y));
                            b_x += 20.f;
                        }
                        b_x = 20.f, b_y = 105.f;
                        for (int i = 89; i < 94; i++)
                        {
                            h3[i] = createTriangle_yr(Vector2f(b_x, b_y));
                            b_y += 20.f;
                        }
                        b_x = 890.f, b_y = 213.f;
                        for (int i = 94; i < 98; i++)
                        {
                            h3[i] = createTriangle_yl(Vector2f(b_x, b_y));
                            b_y += 20.f;
                        }
                        b_x = 125.f, b_y = 95;
                        for (int i = 98; i < 101; i++)
                        {
                            h3[i] = createTriangle_xd(Vector2f(b_x, b_y));
                            b_x += 20.f;
                        }
                        b_x = 20.f, b_y = 15.f;
                        for (int i = 101; i < 104; i++)
                        {
                            h3[i] = createTriangle_yr(Vector2f(b_x, b_y));
                            b_y += 20.f;
                        }
                        //End here 
                        //Position of blocks for level 3
                        {
                            rect3[0] = createrectangle(Vector2f(780.f, 30.f), Color::Black, Vector2f(0.f, 65.f));
                            rect3[1] = createrectangle(Vector2f(660.f, 30.f), Color::Black, Vector2f(120.f, 180.f));
                            rect3[2] = createrectangle(Vector2f(120.f, 30.f), Color::Black, Vector2f(780.f, 180.f));
                            rect3[3] = createrectangle(Vector2f(120.f, 30.f), Color::Black, Vector2f(120.f, 180.f));
                            rect3[4] = createrectangle(Vector2f(660.f, 30.f), Color::Black, Vector2f(0.f, 300.f));
                            rect3[5] = createrectangle(Vector2f(240.f, 30.f), Color::Black, Vector2f(660.f, 300.f));
                            rect3[6] = createrectangle(Vector2f(120.f, 30.f), Color::Black, Vector2f(780.f, 400.f));
                            rect3[7] = createrectangle(Vector2f(200.f, 30.f), Color::Black, Vector2f(0.f, 400.f));
                            rect3[8] = createrectangle(Vector2f(200.f, 30.f), Color(47, 47, 47), Vector2f(700.f, 400.f));
                            rect3[9] = createrectangle(Vector2f(200.f, 30.f), Color::Black, Vector2f(200.f, 400.f));
                            rect3[10] = createrectangle(Vector2f(200.f, 30.f), Color::Black, Vector2f(500.f, 400.f));
                            rect3[11] = createrectangle(Vector2f(200.f, 30.f), Color::Black, Vector2f(500.f, 400.f));
                        }
                        //button for level 3
                        button3[0] = createrectangle(Vector2f(60.f, 20.f), Color::Black, Vector2f(125.f, 160.f));
                        button3[1] = createrectangle(Vector2f(60.f, 20.f), Color::Black, Vector2f(125.f, 285.f));
                        button3[2] = createrectangle(Vector2f(60.f, 20.f), Color(47, 47, 47), Vector2f(840.f, 380.f));
                        circle.setPosition(c_x3, c_y3);
                        while (window.isOpen())
                        {
                            while (window.pollEvent(event))
                            {
                                if (event.type == Event::Closed)
                                {
                                    window.close();
                                }
                                if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
                                {
                                    if (bg_music.getStatus() == sf::Sound::Playing)
                                    {
                                        bg_music.pause(); // Pause the sound
                                    }
                                    else
                                    {
                                        bg_music.play(); // Resume the sound
                                    }
                                }
                            }
                            window.clear(Color(47, 47, 47));
                            window.draw(gate[0]);
                            window.draw(gate[1]);
                            window.draw(circle);
                            //button for level 3
                            press1(button3, 0, circle, b_p2);
                            press1(button3, 1, circle, b_p3);
                            press1(button3, 2, circle, b_p4);
                            //draw hurdle 
                            for (int i = 0; i < s3; i++)
                            {
                                window.draw(h3[i]);
                            }
                            for (int i = 0; i < size3; i++)
                            {
                                window.draw(rect3[i]);
                            }
                            for (int i = 0; i < b_3; i++)
                            {
                                window.draw(button3[i]);

                            }
                            //hurdle check
                            hurdle(h3, s3, circle, window, c_x3, c_y3);
                            //move
                            if (levels)
                            {
                                if (!c_3)
                                {
                                    move2(circle);
                                }
                                //jump
                                jump(circle, Velocity_y, jumpVelocity, gravity, isjumping);
                                //Collision
                                Collision(circle, rect3, garbage, size3, isjumping, Velocity_y, gravity);
                            }
                            if (circle.getGlobalBounds().intersects(button3[0].getGlobalBounds()) || c3)
                            {
                                c3 = true;
                                for (int i = 89; i < 94; i++)
                                {
                                    h3[i].move(2.5f, 0.f);
                                }
                                rect3[2].move(-2.f, 0.f);
                                rect3[3].move(-2.f, 0.f);
                                if (rect3[3].getPosition().x <= 0)
                                {
                                    rect3[2].move(2.f, 0.f);
                                    rect3[3].move(2.f, 0.f);
                                }
                            }
                            if (circle.getGlobalBounds().intersects(button3[1].getGlobalBounds()) || c_3)
                            {
                                c_3 = true;
                                //revert the movement 
                                if (levels)
                                {
                                    move(circle);
                                }
                                rect3[5].move(-2.f, 0.f);
                                if (rect3[5].getPosition().x <= 420.f)
                                {
                                    rect3[5].move(2.f, 0.f);
                                }
                            }
                            if (circle.getGlobalBounds().intersects(button3[2].getGlobalBounds()) || c__3)
                            {
                                c__3 = true;
                                rect3[10].move(-2.f, 0.f);
                                if (rect3[10].getPosition().x <= 390.f)
                                {
                                    rect3[10].move(2.f, 0.f);
                                }
                            }
                            for (int i = 0; i < s3; i++)
                            {
                                if (circle.getGlobalBounds().intersects(h3[i].getGlobalBounds()))
                                {
                                    goto sp3;
                                }
                            }
                            if (circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()))
                            {
                                if (set)
                                {
                                    clock1.restart();
                                    circle.setPosition(gate[1].getPosition().x, circle.getPosition().y);
                                    set = false;
                                }
                                levels = false;
                                gate[0].move(-2.f, 0.f);
                                gate[1].move(-2.f, 0.f);
                                circle.move(-2.f, 0.f);
                            }
                            el1 = clock1.getElapsedTime().asSeconds();
                            window.display();
                            //level4
                            if ((circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()) && count == 2) && el1 > 1)
                            {
                            lv4:
                                circle.setTexture(&ch3);
                                for_con = 4;
                                file.open("gamefile.txt", ios::out);
                                if (file.is_open())
                                {
                                    file << for_con;
                                    file.close();
                                }
                                count = 3;
                                applyTransition(window, transition_time, lvl4);
                                window.setTitle("level 4");
                            sp4:

                                hitspike = false;
                                sp_1.setTexture(c_spike);
                                sp_1.setScale(0.2, 0.2);
                                sp_1.setOrigin(sp_1.getLocalBounds().width / 2, sp_1.getLocalBounds().height / 2);
                                sp_1.setPosition(-50, 308);

                                level4 = true;
                                c4 = false, c4_1 = false, c4_2 = false;
                                circle.setPosition(c_x4, c_y4);
                                b_x = 70, b_y = -50;
                                for (int i = 0; i < s4; i++)
                                {
                                    h4[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                    b_x += 20.f;
                                }
                                {
                                    rect4[0] = createrectangle(Vector2f(-700, 40), Color::Black, Vector2f(840, 70));
                                    rect4[1] = createrectangle(Vector2f(700, 40), Color::Black, Vector2f(60, 200));
                                    rect4[2] = createrectangle(Vector2f(390, 40), Color::Black, Vector2f(60, 350));
                                    rect4[3] = createrectangle(Vector2f(-390, 40), Color::Black, Vector2f(840, 350));
                                    rect4[4] = createrectangle(Vector2f(780, 50), Color::Black, Vector2f(60, -100));
                                    rect4[5] = createrectangle(Vector2f(30, 150), Color::Black, Vector2f(130, 350));
                                    rect4[6] = createrectangle(Vector2f(50.f, 50.f), Color::Black, Vector2f(70.f, 450.f));
                                    rect4[7] = createrectangle(Vector2f(40.f, 45.f), Color::White, Vector2f(74.f, 455.f));
                                    rect4[8] = createrectangle(Vector2f(10, 10), Color::Black, Vector2f(950, 470));
                                    rect4[9] = createrectangle(Vector2f(50, 20), Color::Black, Vector2f(923, 460));
                                    rect4[10] = createrectangle(Vector2f(60, 500), Color::Black, Vector2f(0, 0));
                                    rect4[11] = createrectangle(Vector2f(60, 500), Color::Black, Vector2f(840, 0));
                                    rect4[12] = createrectangle(Vector2f(20, 5), Color::Red, Vector2f(923, 470));
                                }
                                {
                                    but4[0] = createrectangle(Vector2f(30, 10), Color::Black, Vector2f(400, 190));
                                    but4[1] = createrectangle(Vector2f(30, 10), Color::Black, Vector2f(80, 340));
                                    but4[2] = createrectangle(Vector2f(30, 10), Color::Black, Vector2f(390, 490));
                                }
                                while (window.isOpen()) {
                                    while (window.pollEvent(event))
                                    {
                                        if (event.type == Event::Closed)
                                        {
                                            window.close();
                                        }
                                        if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
                                        {
                                            if (bg_music.getStatus() == sf::Sound::Playing)
                                            {
                                                bg_music.pause(); // Pause the sound
                                            }
                                            else
                                            {
                                                bg_music.play(); // Resume the sound
                                            }
                                        }
                                    }

                                    window.clear(Color(47, 47, 47));// connsidertaion charcol
                                    for (int i = 0; i < 3; i++)
                                    {
                                        window.draw(but4[i]);
                                    }
                                    window.draw(sp_1);
                                    window.draw(rect4[12]);
                                    for (int i = 0; i < size4 - 1; i++)
                                    {
                                        window.draw(rect4[i]);
                                    }
                                    window.draw(circle);
                                    for (int i = 0; i < s4; i++)
                                    {
                                        window.draw(h4[i]);
                                    }
                                    if (level4)
                                    {
                                        //move
                                        move(circle);
                                        //collision
                                        Collision(circle, rect4, garbage, 9, isjumping, Velocity_y, gravity);
                                        //jump
                                        jump(circle, Velocity_y, jumpVelocity, gravity, isjumping);
                                        //hurdle
                                        hurdle(h4, s4, circle, window, c_x4, c_y4);
                                        //sppike hurdle
                                        hurdle1(sp_1, circle, window, c_x4, c_y4);
                                    }
                                    rect4[4].move(0.f, 0.15f);
                                    for (int i = 0; i < s4; i++)
                                    {
                                        h4[i].move(0.f, 0.15f);
                                    }
                                    //for button 1
                                    if (circle.getGlobalBounds().intersects(but4[0].getGlobalBounds()) || c4_1)
                                    {
                                        //buuton
                                        press1(but4, 0, circle, b4_1);
                                        rect4[4].move(0.f, .2f);
                                        for (int i = 0; i < s4; i++)
                                        {
                                            h4[i].move(0.f, .2f);
                                        }
                                        c4_1 = true;
                                    }
                                    if (circle.getPosition().x >= 795)
                                    {
                                        circle.move(-2.f, 0.f);
                                    }
                                    if (circle.getPosition().x <= 55)
                                    {
                                        circle.move(2.f, 0.f);
                                    }
                                    //for button 2
                                    if (circle.getGlobalBounds().intersects(but4[1].getGlobalBounds()) || c4)
                                    {
                                        sp_1.rotate(100);
                                        sp_1.move(4, 0.f);
                                        //button
                                        press1(but4, 1, circle, b4_1);
                                        rect4[3].move(-2.f, 0.f);
                                        if (rect4[3].getPosition().x <= 780)
                                        {
                                            rect4[3].move(2.f, 0.f);
                                        }
                                        c4 = true;
                                    }
                                    //for button 3
                                    if (circle.getGlobalBounds().intersects(but4[2].getGlobalBounds()) || c4_2)
                                    {
                                        gravity = 0.4;
                                        c4 = false;
                                        rect4[3].move(3.f, 0.f);
                                        rect4[8].move(-3.f, 0.f);
                                        rect4[9].move(-3.f, 0.f);
                                        rect4[12].move(-5.f, 0.f);
                                        if (rect4[3].getPosition().x >= 950)
                                        {
                                            rect4[3].move(-3.f, 0.f);
                                        }
                                        if (rect4[8].getPosition().x <= 760)
                                        {
                                            rect4[8].move(3.f, 0.f);
                                            rect4[9].move(3.f, 0.f);
                                        }
                                        if (rect4[12].getPosition().x <= 160)
                                        {
                                            rect4[12].setPosition(760, 460);
                                            rect4[5].move(0.f, -20.f);
                                        }
                                        //button
                                        press1(but4, 2, circle, b4_2);
                                        c4_2 = true;
                                    }
                                    if (circle.getGlobalBounds().intersects(rect4[7].getGlobalBounds()))
                                    {
                                        level4 = false;
                                        if (c4_2)
                                        {
                                            circle.setPosition(rect4[7].getPosition().x, rect4[7].getPosition().y);
                                            c4_2 = false;
                                            clock1.restart();
                                        }
                                        rect4[6].move(0.f, 4.f);
                                        rect4[7].move(0.f, 4.f);
                                        circle.move(0.f, 4.f);

                                    }
                                    if (circle.getPosition().y < rect4[4].getPosition().y)
                                    {
                                        goto sp4;
                                    }
                                    for (int i = 0; i < s4; i++)
                                    {
                                        if (circle.getGlobalBounds().intersects(h4[i].getGlobalBounds()))
                                        {
                                            hitspike = true;
                                            break;
                                        }
                                    }
                                    if (hitspike)
                                    {
                                        goto sp4;
                                    }
                                    if (circle.getGlobalBounds().intersects(rect4[12].getGlobalBounds()) || circle.getGlobalBounds().intersects(sp_1.getGlobalBounds()))
                                    {
                                        goto sp4;
                                    }
                                    window.display();
                                    el1 = clock1.getElapsedTime().asSeconds();
                                    //level 5
                                    if ((circle.getGlobalBounds().intersects(rect4[7].getGlobalBounds()) && count == 3) && el1 >= 1)
                                    {
                                    lv5:

                                        for_con = 5;
                                        file.open("gamefile.txt", ios::out);
                                        if (file.is_open())
                                        {
                                            file << for_con;
                                            file.close();
                                        }
                                        gravity = 0.5;
                                        circle.setTexture(&ch2);
                                        count = 4;
                                        applyTransition(window, transition_time, lvl5);
                                        window.setTitle("level 5");
                                    sp5:
                                        hitspike = false;
                                        set = true;
                                        levels = true;
                                        gate[0].setPosition(850, 170);
                                        gate[1].setPosition(854, 174);
                                        circle.setPosition(c_x5, c_y5);
                                        b_x = 10.f, b_y = 0.f;
                                        c_3 = false, c__3 = false, c_5 = false;
                                        for (int i = 0; i < 45; i++)
                                        {

                                            h5[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                            b_x += 20.f;

                                        }
                                        b_x = 10.f, b_y = 480.f;
                                        for (int i = 45; i < 90; i++)
                                        {

                                            h5[i] = createTriangle_xu(Vector2f(b_x, b_y));
                                            b_x += 20.f;

                                        }
                                        //rectangles 
                                        rect5[0] = createrectangle(Vector2f(120.f, 30.f), Color::Black, Vector2f(0.f, 250.f));
                                        rect5[1] = createrectangle(Vector2f(80.f, 20.f), Color::Black, Vector2f(200.f, 200.f));
                                        rect5[2] = createrectangle(Vector2f(80.f, 20.f), Color::Black, Vector2f(365.f, 270.f));
                                        rect5[3] = createrectangle(Vector2f(80.f, 20.f), Color::Black, Vector2f(530.f, 230.f));
                                        rect5[4] = createrectangle(Vector2f(80.f, 20.f), Color::Black, Vector2f(695.f, 290.f));
                                        rect5[5] = createrectangle(Vector2f(68.f, 20.f), Color::Black, Vector2f(832.f, 220.f));
                                        rect5[6] = createrectangle(Vector2f(68.f, 20.f), Color::Black, Vector2f(832.f, 120.f));
                                        rect5[7] = createrectangle(Vector2f(20.f, 100.f), Color::Black, Vector2f(840.f, 120.f));
                                        //buttons 
                                        but5_1 = createrectangle(Vector2f(15.f, 10.f), Color::Black, Vector2f(230.f, 190.f));
                                        but5_2 = createrectangle(Vector2f(15.f, 10.f), Color::Black, Vector2f(395.f, 260.f));
                                        but5_3 = createrectangle(Vector2f(15.f, 10.f), Color::Black, Vector2f(560.f, 220.f));
                                        but5_4 = createrectangle(Vector2f(15.f, 10.f), Color::Black, Vector2f(725.f, 280.f));

                                        while (window.isOpen())
                                        {
                                            while (window.pollEvent(event))
                                            {
                                                if (event.type == Event::Closed)
                                                {
                                                    window.close();
                                                }
                                                if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
                                                {
                                                    if (bg_music.getStatus() == sf::Sound::Playing)
                                                    {
                                                        bg_music.pause(); // Pause the sound
                                                    }
                                                    else
                                                    {
                                                        bg_music.play(); // Resume the sound
                                                    }
                                                }
                                            }
                                            if (circle.getPosition().y >= g_y)
                                            {
                                                goto sp5;
                                            }
                                            window.clear(Color(47, 47, 47));
                                            window.draw(gate[0]);
                                            window.draw(gate[1]);
                                            window.draw(circle);
                                            //button
                                            window.draw(but5_1);
                                            window.draw(but5_2);
                                            window.draw(but5_3);
                                            window.draw(but5_4);
                                            if (levels)
                                            {
                                                //move 
                                                move(circle);
                                                //jump
                                                jump(circle, Velocity_y, jumpVelocity, gravity, isjumping);
                                                //Collison
                                                Collision(circle, rect5, garbage, size5, isjumping, Velocity_y, gravity);
                                            }
                                            //Button
                                            press2(but5_1, circle, b_5p0);
                                            press2(but5_2, circle, b_5p1);
                                            press2(but5_3, circle, b_5p2);
                                            press2(but5_4, circle, b_5p3);
                                            //spike move 
                                            for (int i = 17; i < 23; i++)
                                            {
                                                if (h5[i].getPosition().y == 0 || c_51)
                                                {
                                                    c_52 = false;
                                                    c_51 = true;
                                                    h5[i].move(0, 2.f);
                                                }
                                                if (h5[19].getGlobalBounds().intersects(rect5[2].getGlobalBounds()) || c_52)
                                                {
                                                    c_52 = true;
                                                    c_51 = false;
                                                    h5[i].move(0.f, -2.f);
                                                }
                                            }
                                            for (int i = 34; i < 42; i++)
                                            {
                                                if (h5[i].getPosition().y == 0 || c_54)
                                                {
                                                    c_53 = false;
                                                    c_54 = true;
                                                    h5[i].move(0, 2.f);
                                                }
                                                if (h5[34].getGlobalBounds().intersects(rect5[4].getGlobalBounds()) || c_53)
                                                {
                                                    c_53 = true;
                                                    c_54 = false;
                                                    h5[i].move(0.f, -2.f);
                                                }
                                            }
                                            if (circle.getGlobalBounds().intersects(but5_1.getGlobalBounds()) || c_3)
                                            {
                                                c_3 = true;
                                                for (int i = 0; i < 45; i++)
                                                {
                                                    h5[i].move(0.f, 2.f);
                                                }
                                                for (int i = 45; i < s5; i++)
                                                {
                                                    h5[i].move(0.f, -2.f);

                                                }
                                                for (int i = 0; i < s5; i++)
                                                {
                                                    if (circle.getGlobalBounds().intersects(h5[i].getGlobalBounds()))
                                                    {
                                                        goto sp5;
                                                    }
                                                }
                                            }
                                            if (circle.getGlobalBounds().intersects(but5_2.getGlobalBounds()) || c__3)
                                            {
                                                c__3 = true;
                                                rect5[2].move(15.f, 0.f);
                                                for (int i = 0; i < s5; i++)
                                                {
                                                    if (circle.getGlobalBounds().intersects(h5[i].getGlobalBounds()))
                                                    {
                                                        goto sp5;
                                                    }
                                                }
                                            }
                                            if (circle.getGlobalBounds().intersects(but5_3.getGlobalBounds()))
                                            {
                                                circle.setPosition(c_x5, c_y5);
                                                goto sp5;
                                            }
                                            if (circle.getGlobalBounds().intersects(but5_4.getGlobalBounds()) || c_5)
                                            {
                                                c_5 = true;
                                                rect5[7].move(0.f, -2.f);
                                                rect5[6].move(2.f, 0.f);
                                            }
                                            //hurdle
                                            hurdle(h5, s5, circle, window, c_x5, c_y5);
                                            for (int i = 0; i < size5; i++)
                                            {
                                                window.draw(rect5[i]);
                                            }
                                            for (int i = 0; i < s5; i++)
                                            {
                                                window.draw(h5[i]);
                                                for (int i = 0; i < s5; i++)
                                                {
                                                    if (circle.getGlobalBounds().intersects(h5[i].getGlobalBounds()))
                                                    {
                                                        hitspike = true;
                                                    }
                                                }
                                            }
                                            if (hitspike)
                                            {
                                                goto sp5;
                                            }
                                            if (circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()))
                                            {
                                                levels = false;
                                                if (set)
                                                {
                                                    circle.setPosition(gate[1].getPosition().x, gate[1].getPosition().y);
                                                    set = false;
                                                    clock1.restart();
                                                }
                                                gate[0].move(2.f, 0.f);
                                                gate[1].move(2.f, 0.f);
                                                circle.move(2.f, 0.f);

                                            }
                                            el1 = clock1.getElapsedTime().asSeconds();
                                            window.display();
                                            //level 6
                                            if ((circle.getGlobalBounds().intersects(gate[1].getGlobalBounds()) && count == 4) && el1 >= 1)
                                            {
                                            lv6:
                                                circle.setTexture(&ch2);
                                                for_con = 6;
                                                file.open("gamefile.txt", ios::out);
                                                if (file.is_open())
                                                {
                                                    file << for_con;
                                                    file.close();
                                                }
                                                count = 5;
                                                window.setTitle("level 6");
                                                applyTransition(window, transition_time, lvl6);
                                            sp6:
                                                hitspike = false;
                                                levels = true;
                                                set = true;
                                                c6 = true; c6_1 = false; c6_2 = false;
                                                jumpVelocity = -23.5;
                                                circle.setPosition(c_x6, c_y6);
                                                {
                                                    rect6[0] = createrectangle(Vector2f(200.f, 250.f), Color::Black, Vector2f(0.f, 0.f));
                                                    rect6[1] = createrectangle(Vector2f(135.f, 200.f), Color::Black, Vector2f(200.f, 0.f));
                                                    rect6[2] = createrectangle(Vector2f(135.f, 150.f), Color::Black, Vector2f(335.f, 0.f));
                                                    rect6[3] = createrectangle(Vector2f(135.f, 100.f), Color::Black, Vector2f(470.f, 0.f));
                                                    rect6[4] = createrectangle(Vector2f(135.f, 50.f), Color::Black, Vector2f(605.f, 0.f));
                                                    rect6[5] = createrectangle(Vector2f(900.f, 100.f), Color::Black, Vector2f(-1000.f, 250.f));
                                                    rect6[6] = createrectangle(Vector2f(50.f, 50.f), Color::Black, Vector2f(10.f, 300.f));
                                                    rect6[7] = createrectangle(Vector2f(40.f, 45.f), Color::White, Vector2f(14.f, 305.f));
                                                    rect6[8] = createrectangle(Vector2f(50.f, 50.f), Color::Black, Vector2f(830.f, 350.f));
                                                    rect6[9] = createrectangle(Vector2f(40.f, 45.f), Color::White, Vector2f(834.f, 355.f));
                                                    pform[0] = createrectangle(Vector2f(450.f, 150.f), Color::Black, Vector2f(0.f, 350.f));
                                                    pform[1] = createrectangle(Vector2f(450.f, 150.f), Color::Black, Vector2f(450.f, 350.f));
                                                    but6[0] = createrectangle(Vector2f(30.f, 10.f), Color::Black, Vector2f(190.f, 340.f));
                                                    but6[1] = createrectangle(Vector2f(30.f, 10.f), Color::Black, Vector2f(325.f, 340.f));
                                                    but6[2] = createrectangle(Vector2f(30.f, 10.f), Color::Black, Vector2f(460.f, 340.f));
                                                    but6[3] = createrectangle(Vector2f(30.f, 10.f), Color::Black, Vector2f(595.f, 340.f));
                                                    but6[4] = createrectangle(Vector2f(30.f, 10.f), Color::Black, Vector2f(730.f, 340.f));
                                                }
                                                b_x = 10.f, b_y = 250.f;

                                                for (int i = 0; i < 10; i++)
                                                {
                                                    h6[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                                    b_x += 20.f;
                                                }
                                                b_y = 200, b_x = 210;;
                                                for (int i = 10; i < 16; i++)
                                                {
                                                    h6[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                                    b_x += 20.f;
                                                }
                                                b_y = 150, b_x = 345;
                                                for (int i = 16; i < 22; i++)
                                                {
                                                    h6[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                                    b_x += 20.f;
                                                }
                                                b_y = 100, b_x = 480;
                                                for (int i = 22; i < 28; i++)
                                                {
                                                    h6[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                                    b_x += 20.f;
                                                }
                                                b_y = 50, b_x = 615;
                                                for (int i = 28; i < 34; i++)
                                                {
                                                    h6[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                                    b_x += 20.f;
                                                }
                                                b_y = 0, b_x = 750;
                                                for (int i = 34; i < 42; i++)
                                                {
                                                    h6[i] = createTriangle_xd(Vector2f(b_x, b_y));
                                                    b_x += 20.f;
                                                }
                                                b_y = 260, b_x = -80;
                                                for (int i = 42; i < 47; i++)
                                                {
                                                    h6[i] = createTriangle_yr(Vector2f(b_x, b_y));
                                                    b_y += 20.f;
                                                }
                                                while (window.isOpen())
                                                {
                                                    while (window.pollEvent(event))
                                                    {
                                                        if (event.type == Event::Closed)
                                                        {
                                                            window.close();
                                                        }
                                                        if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
                                                        {
                                                            if (bg_music.getStatus() == sf::Sound::Playing)
                                                            {
                                                                bg_music.pause(); // Pause the sound
                                                            }
                                                            else
                                                            {
                                                                bg_music.play(); // Resume the sound
                                                            }
                                                        }
                                                    }
                                                    //hurdle check
                                                    hurdle(h6, s6, circle, window, c_x6, c_y6);
                                                    // button check
                                                    if (circle.getGlobalBounds().intersects(but6[4].getGlobalBounds()))
                                                    {
                                                        but6[4].move(0.f, 0.5f);
                                                        jumpVelocity = -21;
                                                    }
                                                    if (circle.getGlobalBounds().intersects(but6[3].getGlobalBounds()))
                                                    {
                                                        but6[3].move(0.f, 0.5f);
                                                        jumpVelocity = -18.5;
                                                    }
                                                    if (circle.getGlobalBounds().intersects(but6[2].getGlobalBounds()))
                                                    {
                                                        but6[2].move(0.f, 0.5f);
                                                        jumpVelocity = -16;
                                                    }
                                                    if (circle.getGlobalBounds().intersects(but6[1].getGlobalBounds()) || c6_1)
                                                    {
                                                        if (!c6_1)
                                                        {
                                                            clock.restart();
                                                        }
                                                        but6[1].move(0.f, 0.5f);
                                                        jumpVelocity = -13;
                                                        c6 = false;
                                                        c6_1 = true;
                                                        float el = clock.getElapsedTime().asSeconds();
                                                        for (int i = 0; i < 10; i++)
                                                        {
                                                            h6[i].move(0.f, .5f);
                                                        }
                                                        if (el >= 0.5)
                                                        {
                                                            for (int i = 10; i < 16; i++)
                                                            {
                                                                h6[i].move(0.f, 1.f);

                                                            }
                                                            if (el >= 1)
                                                            {
                                                                for (int i = 16; i < 22; i++)
                                                                {
                                                                    h6[i].move(0.f, 1.f);
                                                                }
                                                            }
                                                            if (el >= 1.5)
                                                            {
                                                                for (int i = 22; i < 28; i++)
                                                                {
                                                                    h6[i].move(0.f, 1.f);
                                                                }
                                                            }
                                                            if (el > 2)
                                                            {
                                                                for (int i = 28; i < 34; i++)
                                                                {
                                                                    h6[i].move(0.f, 1.f);
                                                                }
                                                            }
                                                            if (el >= 2.5)
                                                            {
                                                                for (int i = 34; i < 42; i++)
                                                                {
                                                                    h6[i].move(0.f, 1.f);
                                                                }
                                                            }

                                                        }

                                                    }
                                                    if (circle.getGlobalBounds().intersects(but6[0].getGlobalBounds()) || c6_2)
                                                    {
                                                        but6[0].move(0.f, 0.5f);
                                                        rect6[6].move(0.f, 2.f);
                                                        rect6[7].move(0.f, 2.f);
                                                        rect6[8].move(0.f, -2.f);
                                                        rect6[9].move(0.f, -2.f);
                                                        if (rect6[8].getPosition().y <= 300)
                                                        {
                                                            rect6[8].move(0.f, 2.f);
                                                            rect6[9].move(0.f, 2.f);
                                                        }
                                                        c6_2 = true;
                                                        rect6[5].move(2.3, 0.f);
                                                        for (int i = 42; i < 49; i++)
                                                        {
                                                            h6[i].move(2.3f, 0.f);
                                                        }
                                                    }
                                                    press3(but6, 0, circle, b_p6);
                                                    press3(but6, 1, circle, b_p6);
                                                    press3(but6, 2, circle, b_p6);
                                                    press3(but6, 3, circle, b_p6);
                                                    press3(but6, 4, circle, b_p6);
                                                    if (levels)
                                                    {
                                                        //character moving 
                                                        move(circle);
                                                        // Collision check
                                                        Collision(circle, pform, garbage, 2, isjumping, Velocity_y, gravity);
                                                        //jump
                                                        if (!c6)
                                                        {
                                                            jump(circle, Velocity_y, jumpVelocity, gravity, isjumping);
                                                        }
                                                    }
                                                    //jumping 
                                                    if (c6)
                                                    {
                                                        jumping(circle, Velocity_y, jumpVelocity, gravity, height);
                                                    }
                                                    window.clear(Color(47, 47, 47));// connsidertaion charcol
                                                    for (int i = 0; i < size6; i++)
                                                    {
                                                        window.draw(rect6[i]);
                                                    }
                                                    for (int i = 0; i < 5; i++)
                                                    {
                                                        window.draw(but6[i]);
                                                    }
                                                    for (int i = 0; i < s6; i++)
                                                    {
                                                        window.draw(h6[i]);
                                                    }
                                                    window.draw(circle);
                                                    for (int i = 0; i < 2; i++)
                                                    {
                                                        window.draw(pform[i]);
                                                    }
                                                    if (circle.getGlobalBounds().intersects(rect6[9].getGlobalBounds()))
                                                    {
                                                        levels = false;
                                                        if (set)
                                                        {
                                                            circle.setPosition(rect6[9].getPosition().x, rect6[9].getPosition().y);
                                                            set = false;
                                                            clock1.restart();
                                                        }
                                                        rect6[8].move(2.f, 0.f);
                                                        rect6[9].move(2.f, 0.f);
                                                        circle.move(2.f, 0.f);

                                                    }
                                                    for (int i = 42; i < 47; i++)
                                                    {
                                                        if (circle.getGlobalBounds().intersects(h6[i].getGlobalBounds()))
                                                        {
                                                            goto sp6;
                                                        }
                                                    }
                                                    for (int i = s6 - 1; i >= 0; i--)
                                                    {
                                                        if (circle.getGlobalBounds().intersects(h6[i].getGlobalBounds()))
                                                        {
                                                            hitspike = true;
                                                        }
                                                    }
                                                    if (hitspike)
                                                    {
                                                        goto sp6;
                                                    }
                                                    window.display();
                                                    el1 = clock1.getElapsedTime().asSeconds();
                                                    if ((circle.getGlobalBounds().intersects(rect6[9].getGlobalBounds()) && count == 5) && el1 >= 1)
                                                    {
                                                        clock.restart();
                                                        applyTransition(window, transition_time, End);
                                                        el1 = clock1.getElapsedTime().asSeconds();
                                                        if (el1 >= 1)
                                                        {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}