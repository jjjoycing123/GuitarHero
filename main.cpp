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
#include <iostream>
#include <vector>
#include "RingBuffer.hpp"
#include "GuitarString.hpp"
using std::cout;
using std::endl;

int main() {
cout << "Driver program!!!!" << endl;
try {
RingBuffer buff(-1);
} catch (std::invalid_argument ia) {
cout << "Caught: " << ia.what() << endl;
}

try {
RingBuffer buff(8);
cout << "size: " << buff.size() << endl;
cout << "is empty " << buff.isEmpty() << endl;
cout << "is full " << buff.isFull() << endl << endl;
try {
buff.dequeue();
} catch(std::runtime_error re) {
cout << "Caught: " << re.what() << endl;
}

try {
buff.peek();
} catch(std::runtime_error re) {
cout << "Caught: " << re.what() << endl << endl;
}

buff.enqueue(50);
buff.enqueue(60);
buff.enqueue(70);
buff.enqueue(80);
buff.enqueue(90);
buff.enqueue(100);
buff.enqueue(110);
buff.enqueue(120);

try {
buff.enqueue(140);
} catch(std::runtime_error re) {
cout << "Caught: " << re.what() << endl;
}
cout << "Peek function: " << buff.peek() << endl;
cout << "Buff is full ? " << buff.isFull() << endl << endl;
buff.dequeue();
buff.dequeue();
buff.dequeue();
buff.dequeue();
buff.enqueue(9);
buff.enqueue(16);
buff.enqueue(25);
buff.enqueue(36);
cout << "Peek function: " << buff.peek() << endl;
cout << "Buff is full ? " << buff.isFull() << endl << endl;
} catch(std::invalid_argument ia) {
cout << "Caught: " << ia.what() << endl;
}

// Fill second buffer
cout << "Fill second buffer" << endl;
RingBuffer buff_1(8);
buff_1.enqueue(50);
buff_1.enqueue(60);
buff_1.enqueue(70);
buff_1.enqueue(80);
buff_1.enqueue(90);
buff_1.enqueue(100);
buff_1.enqueue(110);
buff_1.enqueue(120);
cout << endl << endl;

// Karplus-Strong algorithm using RingBuffer member functions.
cout << "Karplus-Strong algorithm using RingBuffer member functions. " << endl;
for(unsigned int i = 0; i < 8; i++) {
int num1 = buff_1.peek();
buff_1.dequeue();
int num2 = buff_1.peek();
int num3 = 0.996 * ((num1 + num2)/2);
buff_1.enqueue(num3);
cout << "Karplus-Strong avg value: " << num3 << endl;
}

cout << endl << endl;
GuitarString gs(3.14);
gs.pluck();
gs.tic();
gs.sample();
gs.time();

vector<sf::Int16> vec;
vec.push_back(7);
vec.push_back(8);
vec.push_back(9);
cout << endl;
GuitarString gs1(vec);
gs1.tic();
gs1.pluck();
gs1.sample();
cout << "Time " << gs1.time() << endl;
cout << endl;


return 0;
}


