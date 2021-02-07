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
#include "GuitarString.hpp"
using std::cout;
using std::endl;


GuitarString::GuitarString(double frequency) {
	_rb = new RingBuffer(ceil(frequency));
}

GuitarString::GuitarString(vector<sf::Int16> init){
	_rb = new RingBuffer(init.size());
	for(unsigned i = 0; i < init.size(); i++){
		_rb->enqueue(init.at(i));
	}
}

GuitarString::~GuitarString() {
	delete _rb;
}

void GuitarString::pluck() {
	srand(std::time(NULL));
	while(!_rb->isEmpty()) {
		_rb->dequeue();
	}
	while(!_rb->isFull()) {
		int16_t rnum = rand() % 65536 + (-32767);
		_rb->enqueue(rnum);
	}
}

void GuitarString::tic() {
	int num1 = _rb->peek();
	_rb->dequeue();
	int num2 = _rb->peek();
	int num3 = 0.996 * ((num1 + num2)/2);
	_rb->enqueue(num3);
	_time++;
}

sf::Int16 GuitarString::sample() {
	return _rb->peek();
}

int GuitarString::time() {
	return _time;
}

