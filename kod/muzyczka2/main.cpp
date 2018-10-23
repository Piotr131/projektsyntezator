#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "sound.h"


 using namespace std;
 int main() {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Muzyczka v2.0");



    sf::RectangleShape key1(sf::Vector2f(80.0f, 160.0f));
        key1.setFillColor(sf::Color::Black);
        key1.setPosition(355,200);
    sf::RectangleShape key2(sf::Vector2f(80.0f, 160.0f));
        key2.setFillColor(sf::Color::Black);
        key2.setPosition(475,200);
    sf::RectangleShape key3(sf::Vector2f(80.0f, 160.0f));
        key3.setFillColor(sf::Color::Black);
        key3.setPosition(715,200);
    sf::RectangleShape key4(sf::Vector2f(80.0f, 160.0f));
        key4.setFillColor(sf::Color::Black);
        key4.setPosition(835,200);
    sf::RectangleShape key5(sf::Vector2f(80.0f, 160.0f));
        key5.setFillColor(sf::Color::Black);
        key5.setPosition(955,200);

    sf::RectangleShape key6(sf::Vector2f(110.0f, 300.0f));
        key6.setFillColor(sf::Color::White);
            key6.setOutlineThickness(10);
            key6.setOutlineColor(sf::Color::Blue);
                key6.setPosition(280,200);
    sf::RectangleShape key7(sf::Vector2f(110.0f, 300.0f));
        key7.setFillColor(sf::Color::White);
            key7.setOutlineThickness(10);
            key7.setOutlineColor(sf::Color::Blue);
                key7.setPosition(400,200);
    sf::RectangleShape key8(sf::Vector2f(110.0f, 300.0f));
        key8.setFillColor(sf::Color::White);
            key8.setOutlineThickness(10);
            key8.setOutlineColor(sf::Color::Blue);
                key8.setPosition(520,200);
    sf::RectangleShape key9(sf::Vector2f(110.0f, 300.0f));
        key9.setFillColor(sf::Color::White);
            key9.setOutlineThickness(10);
            key9.setOutlineColor(sf::Color::Blue);
                key9.setPosition(640,200);
     sf::RectangleShape key10(sf::Vector2f(110.0f, 300.0f));
        key10.setFillColor(sf::Color::White);
            key10.setOutlineThickness(10);
            key10.setOutlineColor(sf::Color::Blue);
        key10.setPosition(760,200);
    sf::RectangleShape key11(sf::Vector2f(110.0f, 300.0f));
        key11.setFillColor(sf::Color::White);
            key11.setOutlineThickness(10);
            key11.setOutlineColor(sf::Color::Blue);
        key11.setPosition(880,200);
    sf::RectangleShape key12(sf::Vector2f(110.0f, 300.0f));
        key12.setFillColor(sf::Color::White);
            key12.setOutlineThickness(10);
            key12.setOutlineColor(sf::Color::Blue);
        key12.setPosition(1000,200);



 	sf::SoundBuffer buffer;
	vector<sf::Int16> samples;

    sf::Sound sound;




while (window.isOpen())
{
         sf::Event event;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
{
                                       // key6.setFillColor(sf::Color::Red);

            for (int i = 0; i < 44100; i++)
                {
                    samples.push_back(sound::SquareWave(i, 523, 0.1));
                }
    buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
    sound.setBuffer(buffer);
    sound.play();



}
else
    {
    sound.resetBuffer();

    }



while(window.pollEvent(event))
{

    switch(event.type)      //S£ICZ OD NACISKANIA/ZWALNIANIA PRZYCISKÓW
    {
        case sf::Event::Closed:
            window.close();
                break;

        case sf::Event::KeyPressed:

                    switch(event.key.code)
                    {
                    case sf::Keyboard::A:
                      key6.setFillColor(sf::Color::Red);
                      break;
                    }
            break;

        case sf::Event::KeyReleased:

                    switch(event.key.code)
                    {
                    case sf::Keyboard::A:
                      key6.setFillColor(sf::Color::White);
                      break;
                    }
    }



    if (event.type == sf::Event::Closed)
        {
        window.close();
        }


            window.draw(key6);
            window.draw(key7);
            window.draw(key8);
            window.draw(key9);
            window.draw(key10);
            window.draw(key11);
            window.draw(key12);

            window.draw(key1);
            window.draw(key2);
            window.draw(key3);
            window.draw(key4);
            window.draw(key5);


window.display();

}

}
return 0;
}
