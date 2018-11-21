#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;

 int main()
 {

    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;
    sf::SoundBuffer buffer3;
    sf::Music bit1;
    sf::Music bit2;
    sf::Music bit3;
    sf::SoundBufferRecorder nagr; //buffer do rozpoczêcia nagrania
    sf::SoundBuffer nagranie; //do przechowywania nagrania

    sf::Sound sound;
    sound.setVolume(100);

    buffer1.loadFromFile("organ.wav");
    buffer2.loadFromFile("pianoC.wav");
    buffer3.loadFromFile("square.wav");
    bit1.openFromFile("simpled.wav");
    bit2.openFromFile("tamba.wav");
    bit3.openFromFile("rock.wav");

sf::RenderWindow window(sf::VideoMode(1366, 768), "Synt v1.0", sf::Style::Fullscreen);

    sf::Font czcionka;
    czcionka.loadFromFile("game.ttf");

    sf::Text tekst;
    tekst.setFont(czcionka);
    tekst.setFillColor(sf::Color::Blue);
    tekst.setCharacterSize(80);
    tekst.setPosition(5,-40);
    tekst.setString("Synt v1.0 by Piotr Krzysztanowicz");

    sf::Text wybor1;
    wybor1.setFont(czcionka);
    wybor1.setFillColor(sf::Color::Blue);
    wybor1.setCharacterSize(70);
    wybor1.setPosition(30,600);
    wybor1.setString("BARWY:   1: Organy   2: Pianino klasyczne   3: Fala kwadratowa                                                                 8:STOP");

    sf::Text wybor2;
    wybor2.setFont(czcionka);
    wybor2.setFillColor(sf::Color::Blue);
    wybor2.setCharacterSize(70);
    wybor2.setPosition(30,650);
    wybor2.setString("BITY:   4: Prosta perkusja   5: Tamba   6: Rock                                           9: Start nagrania    0: Zapisz nagranie");

    sf::RectangleShape key1(sf::Vector2f(80.0f, 160.0f));//CZARNE KLAWISZE
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
    sf::RectangleShape key6(sf::Vector2f(110.0f, 300.0f));//BIALE KLAWISZE
        key6.setOutlineThickness(10);
        key6.setOutlineColor(sf::Color::Blue);
        key6.setPosition(280,200);
    sf::RectangleShape key7(sf::Vector2f(110.0f, 300.0f));
        key7.setOutlineThickness(10);
        key7.setOutlineColor(sf::Color::Blue);
        key7.setPosition(400,200);
    sf::RectangleShape key8(sf::Vector2f(110.0f, 300.0f));
        key8.setOutlineThickness(10);
        key8.setOutlineColor(sf::Color::Blue);
        key8.setPosition(520,200);
    sf::RectangleShape key9(sf::Vector2f(110.0f, 300.0f));
        key9.setOutlineThickness(10);
        key9.setOutlineColor(sf::Color::Blue);
        key9.setPosition(640,200);
     sf::RectangleShape key10(sf::Vector2f(110.0f, 300.0f));
        key10.setOutlineThickness(10);
        key10.setOutlineColor(sf::Color::Blue);
        key10.setPosition(760,200);
    sf::RectangleShape key11(sf::Vector2f(110.0f, 300.0f));
        key11.setOutlineThickness(10);
        key11.setOutlineColor(sf::Color::Blue);
        key11.setPosition(880,200);
    sf::RectangleShape key12(sf::Vector2f(110.0f, 300.0f));
        key12.setOutlineThickness(10);
        key12.setOutlineColor(sf::Color::Blue);
        key12.setPosition(1000,200);

while (window.isOpen())
{
sf::Event event;

while(window.pollEvent(event))
{
    switch (event.type)
    {
        case sf::Event::Closed:
        window.close();
        break;

        case sf::Event::KeyPressed:

            switch (event.key.code)
            {
                case sf::Keyboard::Escape:
                    window.close();
                break;

                case sf::Keyboard::Num1: //WYBOR DZWIEKU
                    sound.setBuffer(buffer1);
                break;

                case sf::Keyboard::Num2:
                    sound.setBuffer(buffer2);
                break;

                case sf::Keyboard::Num3:
                    sound.setBuffer(buffer3);
                break;

                case sf::Keyboard::Num4:
                    bit1.play();
                    bit1.setLoop(true);
                    bit2.stop();
                    bit3.stop();
                break;

                case sf::Keyboard::Num5:
                    bit2.play();
                    bit2.setLoop(true);
                    bit1.stop();
                    bit3.stop();
                break;

                case sf::Keyboard::Num6:
                    bit3.play();
                    bit3.setLoop(true);
                    bit1.stop();
                    bit2.stop();
                break;

                case sf::Keyboard::Num8:
                    bit2.stop();
                    bit1.stop();
                    bit3.stop();
                break;

                case sf::Keyboard::Num9: //NAGRYWANIE
                    nagr.start();
                break;

                case sf::Keyboard::Num0:
                    nagr.stop();
                    nagranie = nagr.getBuffer();
                    nagranie.saveToFile("nagranie.ogg");
                break;

                case sf::Keyboard::Enter:

                break;

                    case sf::Keyboard::A:   // KLAWIATURA- NACISK
                        sound.setPitch(1.0f);
                        sound.play();
                        key6.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::W:
                        sound.setPitch(1.05f);
                        sound.play();
                        key1.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::S:
                        sound.setPitch(1.1f);
                        sound.play();
                        key7.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::E:
                        sound.setPitch(1.15f);
                        sound.play();
                        key2.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::D:
                        sound.setPitch(1.2f);
                        sound.play();
                        key8.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::F:
                        sound.setPitch(1.3f);
                        sound.play();
                        key9.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::T:
                        sound.setPitch(1.35f);
                        sound.play();
                        key3.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::G:
                        sound.setPitch(1.4f);
                        sound.play();
                        key10.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::Y:
                        sound.setPitch(1.45f);
                        sound.play();
                        key4.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::H:
                        sound.setPitch(1.5f);
                        sound.play();
                        key11.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::U:
                        sound.setPitch(1.55f);
                        sound.play();
                        key5.setFillColor(sf::Color::Red);
                    break;

                    case sf::Keyboard::J:
                        sound.setPitch(1.6f);
                        sound.play();
                        key12.setFillColor(sf::Color::Red);
                    break;
            }
        break;

       case sf::Event::KeyReleased:

            switch (event.key.code)
            {
                    case sf::Keyboard::A:   // KLAWIATURA- ODPUSZCZENIE
                        sound.stop();
                        key6.setFillColor(sf::Color::White);
                    break;

                    case sf::Keyboard::W:
                        sound.stop();
                        key1.setFillColor(sf::Color::Black);
                    break;

                    case sf::Keyboard::S:
                        sound.stop();
                        key7.setFillColor(sf::Color::White);
                    break;

                    case sf::Keyboard::E:
                        sound.stop();
                        key2.setFillColor(sf::Color::Black);
                    break;

                    case sf::Keyboard::D:
                        sound.stop();
                        key8.setFillColor(sf::Color::White);
                    break;

                    case sf::Keyboard::F:
                        sound.stop();
                        key9.setFillColor(sf::Color::White);
                    break;

                    case sf::Keyboard::T:
                        sound.stop();
                        key3.setFillColor(sf::Color::Black);
                    break;

                    case sf::Keyboard::G:
                        sound.stop();
                        key10.setFillColor(sf::Color::White);
                    break;

                    case sf::Keyboard::Y:
                        sound.stop();
                        key4.setFillColor(sf::Color::Black);
                    break;

                    case sf::Keyboard::H:
                        sound.stop();
                        key11.setFillColor(sf::Color::White);
                    break;

                    case sf::Keyboard::U:
                        sound.stop();
                        key5.setFillColor(sf::Color::Black);
                    break;

                    case sf::Keyboard::J:
                        sound.stop();
                        key12.setFillColor(sf::Color::White);
                    break;

            }
        break;
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
            window.draw(tekst);
            window.draw(wybor1);
            window.draw(wybor2);

            window.setKeyRepeatEnabled(false);

    std::vector<std::string> availableDevices = sf::SoundRecorder::getAvailableDevices( ); //DOSTEPNOSC URZADZEN DO NAGRYWANIA

    for ( int i = 0; i < availableDevices.size( ); i++ )
    {
        std::cout << availableDevices.at( i ) << std::endl;
    }

window.display();
}
}
return 0;
}


