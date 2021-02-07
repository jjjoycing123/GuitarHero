/*
  Copyright 2015 Fred Martin, fredm@cs.uml.edu
  Mon Mar 30 08:58:49 2015

  based on Princeton's GuitarHeroLite.java
  www.cs.princeton.edu/courses/archive/fall13/cos126/assignments/guitar.html

  build with
  g++ -Wall -c GuitarHeroLite.cpp -lsfml-system \
     -lsfml-audio -lsfml-graphics -lsfml-window
  g++ -Wall GuitarHeroLite.o RingBuffer.o GuitarString.o \
   -o GuitarHeroLite -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100
using namespace std;

vector<sf::Int16> makeSamplesFromString(GuitarString &gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero Lite");
  sf::Event event;
  double freq;
  vector<sf::Int16> samples;
  vector<vector<sf::Int16>> vec_samples;
  vector<sf::SoundBuffer> soundbuffers;
  vector<sf::Sound> sounds;
  vector<sf::Sound> vec_sound;

  for(int i = 0; i < 37; i++){
  freq = CONCERT_A * pow(2, (i -24)/12.0);
  GuitarString gs2 = GuitarString(freq);
  samples = makeSamplesFromString(gs2);
  vec_samples.push_back(samples);
  }

  for(int i = 0; i < 37; i++){
  sf::SoundBuffer buf2; 
  if (!buf2.loadFromSamples(&vec_samples.at(i)[0], vec_samples.at(i).size(), 2, SAMPLES_PER_SEC))
    throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
  soundbuffers.push_back(buf2);
  }

  for(int i = 0; i < 37; i++){
  sf::Sound sound2;
  sound2.setBuffer(soundbuffers.at(i));
  sounds.push_back(sound2); 
  }


  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        
        case sf::Keyboard::Q:
          sounds.at(0).play();
          break;
        
        case sf::Keyboard::Num2:
          sounds.at(1).play();
          break;

        case sf::Keyboard::W:
          sounds.at(2).play();
          break;

        case sf::Keyboard::E:
          sounds.at(3).play();
          break;

        case sf::Keyboard::Num4:
          sounds.at(4).play();
          break;

        case sf::Keyboard::R:
          sounds.at(5).play();
          break;

        case sf::Keyboard::Num5:
          sounds.at(6).play();
          break;

        case sf::Keyboard::T:
          sounds.at(7).play();
          break;

        case sf::Keyboard::Y:
          sounds.at(8).play();
          break;

        case sf::Keyboard::Num7:
          sounds.at(9).play();
          break;

        case sf::Keyboard::U:
          sounds.at(10).play();
          break;

        case sf::Keyboard::Num8:
          sounds.at(11).play();
          break;

        case sf::Keyboard::I:
          sounds.at(12).play();
          break;

        case sf::Keyboard::Num9:
          sounds.at(13).play();
          break;

        case sf::Keyboard::O:
          sounds.at(14).play();
          break;

        case sf::Keyboard::P:
          sounds.at(15).play();
          break;

        case sf::Keyboard::Dash:
          sounds.at(16).play();
          break;
        
        case sf::Keyboard::LBracket:
          sounds.at(17).play();
          break;

        case sf::Keyboard::Equal:
          sounds.at(18).play();
          break;

        case sf::Keyboard::Z:
          sounds.at(19).play();
          break;

        case sf::Keyboard::X:
          sounds.at(20).play();
          break;

        case sf::Keyboard::D:
          sounds.at(21).play();
          break;

        case sf::Keyboard::C:
          sounds.at(22).play();
          break;

        case sf::Keyboard::F:
          sounds.at(23).play();
          break;

        case sf::Keyboard::V:
          sounds.at(24).play();
          break;

        case sf::Keyboard::G:
          sounds.at(25).play();
          break;

        case sf::Keyboard::B:
          sounds.at(26).play();
          break;

        case sf::Keyboard::N:
          sounds.at(27).play();
          break;

        case sf::Keyboard::J:
          sounds.at(28).play();
          break;

        case sf::Keyboard::M:
          sounds.at(29).play();
          break;

        case sf::Keyboard::K:
          sounds.at(30).play();
          break;

        case sf::Keyboard::Comma:
          sounds.at(31).play();
          break;

        case sf::Keyboard::Period:
          sounds.at(32).play();
          break;

        case sf::Keyboard::SemiColon:
          sounds.at(33).play();
          break;

        case sf::Keyboard::Slash:
          sounds.at(34).play();
          break;

        case sf::Keyboard::Quote:
          sounds.at(35).play();
          break;

        case sf::Keyboard::Space:
          sounds.at(36).play();
          break;

        default:
          break;
        }

      default:
        break;
      }

      window.clear();
      window.display();
    }
  }

  return 0;
}