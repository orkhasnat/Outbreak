#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "location.h"
#include "destination.h"
#include "person.h"
#include "mobility.h"
#include <time.h>

#define Healthy 0
#define Infected 1
#define Recovered 2
#define Dead 3

using namespace sf;

int main()
{
      srand(time(0));

      RenderWindow window(VideoMode(1600, 900), "OUTBREAK!");
      window.setFramerateLimit(20);

      // variables
      int n = 500, n_H = 0, n_I = 0, n_R = 0, n_D = 0, di, ru, i, j, mob_prob = 0;
      int sn = 0, xn = 0, yp = 1, pp = 0, mb = 0, st = 1, men = 1;

      double t = 0, dt = 0.05;
      int ara[200] = {};

      // class variable
      location loc[1000];
      destination des[15];
      person per[1000];
      mobility mob[1000];

      // load images
      Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18;
      t1.loadFromFile("images/whiteback.png");
      t2.loadFromFile("images/blueball.png");
      t3.loadFromFile("images/redball.png");
      t4.loadFromFile("images/greenball.png");
      t5.loadFromFile("images/redball2.png");
      t6.loadFromFile("images/greenball2.png");
      t7.loadFromFile("images/greyball.png");
      t9.loadFromFile("images/blueball2.png");
      t8.loadFromFile("images/greyball2.png");
      t10.loadFromFile("images/frame3.png");
      t11.loadFromFile("images/graphball.png");
      t12.loadFromFile("images/outbreak.png");
      t13.loadFromFile("images/card.png");
      t14.loadFromFile("images/startt.png");
      t15.loadFromFile("images/outbreak1.png");
      t16.loadFromFile("images/outbreak2.png");
      t17.loadFromFile("images/outbreak3.png");
      t18.loadFromFile("images/outbreak4.png");

      Sprite sBackground(t1), sBall[n], sPaddle(t4), sGraph[50], sGraphh[200], sFrame(t10), stBackground(t12);
      Sprite black(t13), startt(t14), s1(t15), s2(t16), s3(t17), s4(t18);

      // load texts
      sf::Font myFont;
      if (!myFont.loadFromFile("Font/Sunday Morning.ttf"))
      {
      }

      // load music
      sf::Music music;
      music.openFromFile("music/bop.ogg");

      sf::Music musicc;
      musicc.openFromFile("music/yeah.ogg");

      sf::Text health;
      health.setFont(myFont);
      health.setString("Healthy:");
      health.setFillColor(sf::Color::Blue);
      health.setStyle(sf::Text::Regular);
      health.setCharacterSize(20);
      health.setPosition(1130, 100);

      sf::Text healthy;
      healthy.setFont(myFont);
      healthy.setFillColor(sf::Color::Blue);
      healthy.setStyle(sf::Text::Regular);
      healthy.setCharacterSize(20);
      healthy.setPosition(1280, 100);

      sf::Text patien;
      patien.setString("Infected:");
      patien.setFont(myFont);
      patien.setFillColor(sf::Color::Red);
      patien.setStyle(sf::Text::Regular);
      patien.setCharacterSize(20);
      patien.setPosition(1130, 150);

      sf::Text patient;
      patient.setFont(myFont);
      patient.setFillColor(sf::Color::Red);
      patient.setStyle(sf::Text::Regular);
      patient.setCharacterSize(20);
      patient.setPosition(1280, 150);

      sf::Text heale;
      heale.setString("Healed:");
      heale.setFont(myFont);
      heale.setFillColor(sf::Color::Green);
      heale.setStyle(sf::Text::Regular);
      heale.setCharacterSize(20);
      heale.setPosition(1130, 200);

      sf::Text healed;
      healed.setFont(myFont);
      healed.setFillColor(sf::Color::Green);
      healed.setStyle(sf::Text::Regular);
      healed.setCharacterSize(20);
      healed.setPosition(1280, 200);

      sf::Text deat;
      sf::Color Grey(169, 169, 169);
      deat.setString("Death:");
      deat.setFont(myFont);
      deat.setFillColor(Grey);
      // deat.setFillColor(sf::Color::Regular);
      deat.setStyle(sf::Text::Regular);
      deat.setCharacterSize(20);
      deat.setPosition(1130, 250);

      sf::Text death;
      death.setFont(myFont);
      death.setFillColor(Grey);
      death.setStyle(sf::Text::Regular);
      death.setCharacterSize(20);
      death.setPosition(1280, 250);

      sf::Text tim;
      tim.setString("Time:");
      tim.setFont(myFont);
      tim.setFillColor(sf::Color::Yellow);
      tim.setStyle(sf::Text::Regular);
      tim.setCharacterSize(20);
      tim.setPosition(1130, 300);

      sf::Text time;
      time.setFont(myFont);
      time.setFillColor(sf::Color::Yellow);
      time.setStyle(sf::Text::Regular);
      time.setCharacterSize(20);
      time.setPosition(1280, 300);

      // initialize place to population
      for (i = 0; i < n; i++)
      {
            di = rand() % 20;

            if (di < 15)
            {
                  loc[i].x1 = des[di].x2;
                  loc[i].y1 = des[di].y2;
            }

            else
            {
                  loc[i].x1 = rand() % 1100 + 1;
                  loc[i].y1 = rand() % 900 + 1;
            }

            n_H++;
      }

      // infected people from the population
      for (i = 0; i < 3; i++)
      {

            per[i].status = 1;
            n_I++;
            n_H--;
      }

      // graph paper
      sFrame.setPosition(1120, 370);

      int x = 0;

      // draw and run
      while (window.isOpen())
      {

            Event e;

            while (window.pollEvent(e))
            {

                  if (e.type == Event::Closed)
                        window.close();
            }

            // simu menu baar
            // window.clear();
            if (x == 0)
            {

                  for (int yn = 0; yn < 5; yn++)
                  {
                        window.draw(stBackground);
                        window.display();
                  }
                  // window.clear();

                  s1.setPosition(50, 25);
                  for (int yn = 0; yn < 5; yn++)
                  {
                        window.draw(s1);
                        window.display();
                  }
                  // window.clear();

                  s2.setPosition(100, 50);
                  for (int yn = 0; yn < 5; yn++)
                  {
                        window.draw(s2);
                        window.display();
                  }

                  s3.setPosition(150, 75);
                  for (int yn = 0; yn < 5; yn++)
                  {
                        window.draw(s3);
                        window.display();
                  }

                  s4.setPosition(200, 100);
                  for (int yn = 0; yn < 5; yn++)
                  {
                        window.draw(s4);
                        window.display();
                  }
                  goto start;
            }

            else if (x == 1)
            {

                  // while(1){

            start:
                  x = 1;
                  window.clear();

                  window.draw(black);

                  sf::Text start;
                  start.setFont(myFont);
                  start.setString("START SIMULATION");
                  if (men == 1)
                        start.setFillColor(sf::Color::Yellow);
                  else
                        start.setFillColor(sf::Color::White);
                  start.setStyle(sf::Text::Regular);
                  start.setCharacterSize(30);
                  start.setPosition(500, 400);

                  sf::Text exit;
                  exit.setFont(myFont);
                  exit.setString("EXIT");
                  if (men == 2)
                        exit.setFillColor(sf::Color::Yellow);
                  else
                        exit.setFillColor(sf::Color::White);
                  exit.setStyle(sf::Text::Regular);
                  exit.setCharacterSize(30);
                  exit.setPosition(500, 500);

                  sf::Text sound;
                  sound.setFont(myFont);
                  sound.setString("sound   -press S");
                  sound.setFillColor(sf::Color::Cyan);
                  sound.setStyle(sf::Text::Regular);
                  sound.setCharacterSize(20);
                  sound.setPosition(1300, 700);

                  sf::Text background;
                  background.setFont(myFont);
                  background.setString("BACKGROUND  -press B");
                  background.setFillColor(sf::Color::Cyan);
                  background.setStyle(sf::Text::Regular);
                  background.setCharacterSize(20);
                  background.setPosition(1300, 750);

                  sf::Text population;
                  population.setFont(myFont);
                  population.setString("Preset   -press P");
                  population.setFillColor(sf::Color::Cyan);
                  population.setStyle(sf::Text::Regular);
                  population.setCharacterSize(20);
                  population.setPosition(1300, 800);

                  window.draw(start);
                  window.draw(exit);
                  window.draw(sound);
                  window.draw(population);
                  window.draw(background);
                  window.display();

                  /*if (Keyboard::isKeyPressed(Keyboard::Down))goto exit;
                  else if (Keyboard::isKeyPressed(Keyboard::Enter)){
                        x=22;
                        goto game;
                  }*/
                  if (Keyboard::isKeyPressed(Keyboard::S))
                  {
                        goto sound;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::B))
                  {
                        goto theme;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::P))
                  {
                        goto set1;
                  }

                  if (men == 1)
                  {
                        if (Keyboard::isKeyPressed(Keyboard::Down))
                              men = 2;
                        else if (Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                              x = 22;
                              goto game;
                        }
                  }
                  else if (men == 2)
                  {
                        if (Keyboard::isKeyPressed(Keyboard::Up))
                              men = 1;
                        else if (Keyboard::isKeyPressed(Keyboard::Enter))
                              return 0;
                  }
            }
            else if (x == 2)
            {

            exit:
                  x = 2;
                  window.clear();

                  window.draw(black);

                  sf::Text start;
                  start.setFont(myFont);
                  start.setString("START SIMULATION");
                  start.setFillColor(sf::Color::White);
                  start.setStyle(sf::Text::Regular);
                  start.setCharacterSize(30);
                  start.setPosition(500, 400);

                  sf::Text exit;
                  exit.setFont(myFont);
                  exit.setString("EXIT");
                  exit.setFillColor(sf::Color::Yellow);
                  exit.setStyle(sf::Text::Regular);
                  exit.setCharacterSize(30);
                  exit.setPosition(500, 500);

                  sf::Text sound;
                  sound.setFont(myFont);
                  sound.setString("SOUND   -press S");
                  sound.setFillColor(sf::Color::White);
                  sound.setStyle(sf::Text::Regular);
                  sound.setCharacterSize(15);
                  sound.setPosition(1300, 700);

                  sf::Text background;
                  background.setFont(myFont);
                  background.setString("BACKGROUND  -press B");
                  background.setFillColor(sf::Color::White);
                  background.setStyle(sf::Text::Regular);
                  background.setCharacterSize(15);
                  background.setPosition(1300, 750);

                  sf::Text population;
                  population.setFont(myFont);
                  population.setString("Preset   -press P");
                  population.setFillColor(sf::Color::White);
                  population.setStyle(sf::Text::Regular);
                  population.setCharacterSize(15);
                  population.setPosition(1300, 800);

                  window.draw(start);
                  window.draw(exit);
                  window.draw(sound);
                  window.draw(background);
                  window.draw(population);
                  window.display();

                  if (Keyboard::isKeyPressed(Keyboard::Up))
                  {
                        goto start;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::S))
                  {
                        goto sound;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::B))
                  {
                        goto theme;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::P))
                  {
                        goto set1;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::Enter))
                        return 0;
            }

            else if (x == 3)
            {

            sound:

                  x = 3;
                  window.clear();

                  if (sn == 1 && yp == 1)
                        music.play();

                  window.draw(black);

                  sf::Text soundon;
                  soundon.setFont(myFont);
                  soundon.setString("SOUND ON");
                  if (sn == 1)
                        soundon.setFillColor(sf::Color::Yellow);
                  else
                        soundon.setFillColor(sf::Color::White);
                  soundon.setStyle(sf::Text::Regular);
                  soundon.setCharacterSize(30);
                  soundon.setPosition(500, 400);

                  sf::Text soundoff;
                  soundoff.setFont(myFont);
                  soundoff.setString("SOUND Off");
                  if (sn == 0)
                        soundoff.setFillColor(sf::Color::Yellow);
                  else
                        soundoff.setFillColor(sf::Color::White);
                  soundoff.setStyle(sf::Text::Regular);
                  soundoff.setCharacterSize(30);
                  soundoff.setPosition(500, 500);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  window.draw(soundon);
                  window.draw(soundoff);
                  window.draw(esc);
                  window.display();

                  yp++;

                  if (Keyboard::isKeyPressed(Keyboard::Down))
                  {
                        sn = 0;
                        yp = 1;
                        goto sound;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Up))
                  {
                        sn = 1;
                        yp = 1;
                        music.openFromFile("music/bop.ogg");
                        musicc.openFromFile("music/yeah.ogg");
                        goto sound;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Escape))
                        goto setting;
            }

            else if (x == 4)
            {

            theme:
                  x = 4;
                  window.clear();
                  window.draw(black);

                  sf::Text theme;
                  theme.setFont(myFont);
                  if (xn == 0)
                        theme.setString("         'WHITEBACK'\n\n  BATBACK       DEADBACK \n\n           SUPBACK");
                  else if (xn == 1)
                        theme.setString("          WHITEBACK \n\n 'BATBACK'      DEADBACK \n\n           SUPBACK");
                  else if (xn == 2)
                        theme.setString("          WHITEBACK \n\n  BATBACK      'DEADBACK'\n\n           SUPBACK");
                  else if (xn == 3)
                        theme.setString("          WHITEBACK \n\n  BATBACK       DEADBACK \n\n          'SUPBACK'");
                  theme.setFillColor(sf::Color::Yellow);
                  theme.setStyle(sf::Text::Regular);
                  theme.setCharacterSize(30);
                  theme.setPosition(500, 400);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  window.draw(theme);
                  window.draw(esc);

                  window.display();

                  if (Keyboard::isKeyPressed(Keyboard::Right))
                  {
                        xn = 2;
                        t1.loadFromFile("images/deadpool2.png");
                        Sprite sBackground(t1);
                        goto theme;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Left))
                  {
                        xn = 1;
                        t1.loadFromFile("images/batman.jpeg");
                        Sprite sBackground(t1);
                        goto theme;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Down))
                  {
                        xn = 3;
                        t1.loadFromFile("images/superman.png");
                        Sprite sBackground(t1);
                        goto theme;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Up))
                  {
                        xn = 0;
                        t1.loadFromFile("images/whiteback.png");
                        Sprite sBackground(t1);
                        goto theme;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Escape))
                        goto setting;
            }

            else if (x == 5)
            {
            set1:
                  x = 5;
                  window.clear();
                  window.draw(black);

                  sf::Text population;
                  population.setFont(myFont);
                  population.setString("POPULATION");
                  population.setFillColor(sf::Color::Yellow);
                  population.setStyle(sf::Text::Regular);
                  population.setCharacterSize(30);
                  population.setPosition(600, 400);

                  sf::Text mobility;
                  mobility.setFont(myFont);
                  mobility.setString("MOBILITY");
                  mobility.setFillColor(sf::Color::White);
                  mobility.setStyle(sf::Text::Regular);
                  mobility.setCharacterSize(30);
                  mobility.setPosition(600, 500);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  window.draw(population);
                  window.draw(mobility);
                  window.draw(esc);
                  window.display();

                  if (Keyboard::isKeyPressed(Keyboard::Down))
                  {
                        goto set2;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::Enter))
                  {
                        goto population;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::Escape))
                  {
                        goto setting;
                  }
            }

            else if (x == 6)
            {
            set2:
                  x = 6;
                  window.clear();
                  window.draw(black);

                  sf::Text population;
                  population.setFont(myFont);
                  population.setString("POPULATION");
                  population.setFillColor(sf::Color::White);
                  population.setStyle(sf::Text::Regular);
                  population.setCharacterSize(30);
                  population.setPosition(600, 400);

                  sf::Text mobility;
                  mobility.setFont(myFont);
                  mobility.setString("MOBILITY");
                  mobility.setFillColor(sf::Color::Yellow);
                  mobility.setStyle(sf::Text::Regular);
                  mobility.setCharacterSize(30);
                  mobility.setPosition(600, 500);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  window.draw(population);
                  window.draw(mobility);
                  window.draw(esc);
                  window.display();

                  if (Keyboard::isKeyPressed(Keyboard::Up))
                  {
                        goto set1;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::Enter))
                  {
                        goto mobili;
                  }
                  else if (Keyboard::isKeyPressed(Keyboard::Escape))
                  {
                        goto setting;
                  }
            }

            else if (x == 7)
            {
            population:
                  x = 7;
                  window.clear();

                  window.draw(black);
                  sf::Text population;
                  population.setFont(myFont);
                  if (pp == 0)
                        population.setString("         '500'\n\n  400           300 \n\n           200 ");
                  else if (pp == 1)
                        population.setString("          500 \n\n '400'          300 \n\n           200 ");
                  else if (pp == 2)
                        population.setString("          500 \n\n  400          '300'\n\n           200 ");
                  else if (pp == 3)
                        population.setString("          500 \n\n  400           300 \n\n          '200'");
                  population.setFillColor(sf::Color::Yellow);
                  population.setStyle(sf::Text::Regular);
                  population.setCharacterSize(30);
                  population.setPosition(500, 400);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  window.draw(population);
                  window.draw(esc);
                  window.display();

                  if (Keyboard::isKeyPressed(Keyboard::Left))
                  {
                        pp = 1;
                        n = 400;
                        goto population;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Right))
                  {
                        pp = 2;
                        n = 300;
                        goto population;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Down))
                  {
                        pp = 3;
                        n = 200;
                        goto population;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Up))
                  {
                        pp = 0;
                        n = 500;
                        goto population;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Escape))
                  {
                        goto set1;
                  }
            }

            else if (x == 8)
            {

            mobili:
                  x = 8;
                  window.clear();

                  window.draw(black);
                  sf::Text mobili;
                  mobili.setFont(myFont);
                  if (mb == 0)
                        mobili.setString("            '100%' \n\n    70%             50%  \n\n              10%  ");
                  else if (mb == 1)
                        mobili.setString("             100%  \n\n   '70%'            50%  \n\n              10%  ");
                  else if (mb == 2)
                        mobili.setString("             100%  \n\n    70%            '50%' \n\n              10%  ");
                  else if (mb == 3)
                        mobili.setString("             100%  \n\n    70%             50%  \n\n             '10%' ");
                  mobili.setFillColor(sf::Color::Yellow);
                  mobili.setStyle(sf::Text::Regular);
                  mobili.setCharacterSize(30);
                  mobili.setPosition(500, 400);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  window.draw(mobili);
                  window.draw(esc);
                  window.display();

                  if (Keyboard::isKeyPressed(Keyboard::Left))
                  {

                        mb = 1;
                        mob_prob = 70;
                        for (i = 0; i < n; i++)
                        {
                              mob[i].mobilit(mob_prob);
                        }
                        goto mobili;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Right))
                  {

                        mb = 2;
                        mob_prob = 50;
                        for (i = 0; i < n; i++)
                        {
                              mob[i].mobilit(mob_prob);
                        }
                        goto mobili;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Down))
                  {

                        mb = 3;
                        mob_prob = 10;
                        for (i = 0; i < n; i++)
                        {
                              mob[i].mobilit(mob_prob);
                        }
                        goto mobili;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Up))
                  {

                        mb = 0;
                        mob_prob = 100;
                        for (i = 0; i < n; i++)
                        {
                              mob[i].mobilit(mob_prob);
                        }
                        goto mobili;
                  }

                  else if (Keyboard::isKeyPressed(Keyboard::Escape))
                  {
                        goto set1;
                  }
            }
            else if (x == 9)
            {
            setting:
                  x = 9;

                  sf::Text sound;
                  sound.setFont(myFont);
                  sound.setString("sound");
                  if (st == 1)
                        sound.setFillColor(sf::Color::Yellow);
                  else
                        sound.setFillColor(sf::Color::White);
                  sound.setStyle(sf::Text::Regular);
                  sound.setCharacterSize(30);
                  sound.setPosition(600, 350);

                  sf::Text bground;
                  bground.setFont(myFont);
                  bground.setString("Background");
                  if (st == 2)
                        bground.setFillColor(sf::Color::Yellow);
                  else
                        bground.setFillColor(sf::Color::White);
                  bground.setStyle(sf::Text::Regular);
                  bground.setCharacterSize(30);
                  bground.setPosition(600, 450);

                  sf::Text pre;
                  pre.setFont(myFont);
                  pre.setString("preset");
                  if (st == 3)
                        pre.setFillColor(sf::Color::Yellow);
                  else
                        pre.setFillColor(sf::Color::White);
                  pre.setStyle(sf::Text::Regular);
                  pre.setCharacterSize(30);
                  pre.setPosition(600, 550);

                  sf::Text esc;
                  esc.setFont(myFont);
                  esc.setString("press 'esc' to go back");
                  esc.setFillColor(sf::Color::Cyan);
                  esc.setStyle(sf::Text::Regular);
                  esc.setCharacterSize(15);
                  esc.setPosition(650, 800);

                  if (Keyboard::isKeyPressed(Keyboard::Escape))
                  {
                        goto start;
                  }
                  if (st == 1)
                  {
                        if (Keyboard::isKeyPressed(Keyboard::Down))
                              st = 2;
                        else if (Keyboard::isKeyPressed(Keyboard::Enter))
                              goto sound;
                  }
                  else if (st == 2)
                  {
                        if (Keyboard::isKeyPressed(Keyboard::Down))
                              st = 3;
                        else if (Keyboard::isKeyPressed(Keyboard::Up))
                              st = 1;
                        else if (Keyboard::isKeyPressed(Keyboard::Enter))
                              goto theme;
                  }
                  else if (st == 3)
                  {
                        if (Keyboard::isKeyPressed(Keyboard::Up))
                              st = 2;
                        else if (Keyboard::isKeyPressed(Keyboard::Enter))
                              goto set1;
                  }

                  window.clear();
                  window.draw(black);
                  window.draw(sound);
                  window.draw(bground);
                  window.draw(pre);
                  window.draw(esc);
                  window.display();
            }

            else
            {
                  // simulation start

            game:

                  if (x == 22)
                  {
                        window.clear();

                        for (int pn = 0; pn <= 5; pn++)
                        {
                              window.draw(startt);
                              window.display();
                        }

                        x = 23;
                  }

                  window.clear();
                  window.draw(sBackground);
                  window.draw(sFrame);

                  // check population status
                  n_H = 0, n_I = 0, n_R = 0, n_D = 0;

                  for (i = 0; i < n; i++)
                  {

                        if (per[i].status == Healthy)
                        {
                              sBall[i] = Sprite(t2);
                              n_H++;
                        }

                        else if (per[i].status == Infected)
                        {
                              if (per[i].recovery_time == 15)
                              {
                                    sBall[i] = Sprite(t5);
                                    if (sn == 1)
                                    {
                                          // music.openFromFile("music/bop.ogg");
                                          music.play();
                                    }
                              }
                              else if (per[i].recovery_time >= 14.8)
                                    sBall[i] = Sprite(t9);
                              else if (per[i].recovery_time >= 14.6)
                                    sBall[i] = Sprite(t5);
                              else if (per[i].recovery_time == 14.4)
                                    sBall[i] = Sprite(t9);

                              else
                                    sBall[i] = Sprite(t3);
                              n_I++;
                        }

                        else if (per[i].status == Recovered)
                        {
                              if (per[i].recovery_time >= 0.8)
                              {
                                    sBall[i] = Sprite(t6);
                                    if (sn == 1)
                                    {
                                          // musicc.openFromFile("music/yeah.ogg");
                                          musicc.play();
                                    }
                              }
                              else if (per[i].recovery_time >= 0.6)
                                    sBall[i] = Sprite(t5);
                              else if (per[i].recovery_time >= 0.4)
                                    sBall[i] = Sprite(t6);
                              else
                                    sBall[i] = Sprite(t4);
                              n_R++;
                        }

                        else if (per[i].status == Dead)
                        {
                              sBall[i] = Sprite(t7);
                              n_D++;
                        }

                        sBall[i].setPosition(loc[i].x, loc[i].y);
                  }

                  // texting number of people
                  std::stringstream s1;
                  s1 << n_H;
                  healthy.setString(s1.str());

                  std::stringstream s2;
                  s2 << n_I;
                  patient.setString(s2.str());

                  std::stringstream s3;
                  s3 << n_R;
                  healed.setString(s3.str());

                  std::stringstream s4;
                  s4 << n_D;
                  death.setString(s4.str());

                  std::stringstream s5;
                  s5 << t;
                  time.setString(s5.str());

                  // load and draw
                  for (i = 0; i < n; i++)
                  {

                        window.draw(sBall[i]);
                  }

                  int t1 = t;

                  for (int h = 1; h <= t1; h++)
                  {

                        if (h == t1)
                        {
                              ara[h] = n_I / 2;
                        }

                        sGraph[h] = Sprite(t11);
                        sGraph[h].setPosition(1120 + 8 * h, 800 - ara[h]);

                        if (ara[h] >= ara[h - 1])
                        {

                              for (int h1 = ara[h - 1]; h1 <= ara[h]; h1 += 3)
                              {

                                    sGraphh[h1] = Sprite(t11);
                                    sGraphh[h1].setPosition(1120 + 8 * h, 800 - h1);
                                    window.draw(sGraphh[h1]);
                              }
                        }

                        else
                        {
                              for (int h1 = ara[h - 1]; h1 >= ara[h]; h1 -= 3)
                              {

                                    sGraphh[h1] = Sprite(t11);
                                    sGraphh[h1].setPosition(1120 + 8 * h, 800 - h1);
                                    window.draw(sGraphh[h1]);
                              }
                        }

                        window.draw(sGraph[h]);
                  }

                  window.draw(healthy);
                  window.draw(patient);
                  window.draw(healed);
                  window.draw(death);
                  window.draw(health);
                  window.draw(patien);
                  window.draw(heale);
                  window.draw(deat);
                  window.draw(time);
                  window.draw(tim);

                  window.display();

                  // update status and positions
                  for (i = 0; i < n; i++)
                  {

                        if (per[i].status == Healthy)
                        {
                              // check for infections
                              for (j = 0; j < n; j++)
                              {

                                    if ((i != j) && (per[j].status == Infected) && mob[i].m == 1 && mob[j].m == 1)
                                    {

                                          if (loc[i].infect_other(loc[j]))
                                                per[i].status = Infected; // check if person can be infected
                                    }
                              }
                        }

                        else if (per[i].status == Infected)
                        {

                              per[i].recovery_time -= dt; // recovery time ongoing

                              if (per[i].recovery_time <= 1)
                              {

                                    per[i].alive_dead(n_I, n); // check person is alive or dead
                              }
                        }

                        else if (per[i].status == Recovered)
                        {

                              per[i].recovery_time -= dt;
                        }

                        // mobility of people
                        if (mob[i].quaren(per[i].status))
                        {

                              continue;
                        }

                        else
                        {
                              if (mob[i].m)
                              {
                                    double dx, dy, a, dis;
                                    dx = loc[i].x1 - loc[i].x;
                                    dy = loc[i].y1 - loc[i].y;
                                    a = atan2(dy, dx);

                                    // move person to next position
                                    if (loc[i].movee(per[i].vel))
                                    {

                                          // assign new destination
                                          di = rand() % 15;

                                          if (di < 10)
                                          {
                                                loc[i].x1 = des[di].x2;
                                                loc[i].y1 = des[di].y2;
                                          }

                                          else
                                          {
                                                loc[i].x1 = rand() % 1100;
                                                loc[i].y1 = rand() % 900;
                                          }
                                    }
                              }
                        }
                  }

                  t += dt;

                  if (n_I == 0)
                  {

                        window.clear();

                        for (int pn = 0; pn <= 30; pn++)
                        {
                              window.draw(black);
                              sf::Text endd;
                              endd.setFont(myFont);
                              endd.setString("THE END");
                              endd.setFillColor(sf::Color::White);
                              endd.setStyle(sf::Text::Regular);
                              endd.setCharacterSize(60);
                              endd.setPosition(700, 400);
                              window.draw(endd);
                              window.display();
                        }

                        return 0;
                  }
            }
      }
      return 0;
}