/* Copyright (C) 2019 John Nay - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :

  generic copyright text from
  from https://softwareengineering.stackexchange.com/questions/19649/copyright-notices-disclaimers-in-source-files
 */

#ifndef GUITARSTRING_H
#define GUITARSTRING_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <random>
#include <time.h>
#include "RingBuffer.hpp"
using sf::Int16;
using std::vector;

class GuitarString{
 public :
explicit GuitarString(double frequency);
explicit GuitarString(vector<sf::Int16> init);

~GuitarString();
void pluck();
void tic();
sf::Int16 sample();
int time();


 private :
RingBuffer *_rb;
int _time = 0;
};




#endif
