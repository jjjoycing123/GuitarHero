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
#include "RingBuffer.hpp"


RingBuffer::RingBuffer(int capacity) {
if(capacity >= 1) {
_capacity = capacity;
buffer.resize(capacity);
_first = (capacity/2) + 1;
_first = (_first % capacity);
_last = _first;
} else {
throw
std::invalid_argument("RB Constructor: capacity must be greater than zero.");
}
}

int RingBuffer::size() {
return _buffer_size;
}

bool RingBuffer::isEmpty() {
if(_buffer_size == 0) {
return true;
} else {return false;}
}

bool RingBuffer::isFull() {
if(_buffer_size == _capacity) {
return true;
} else {return false;}
}

void RingBuffer::enqueue(int16_t x) {
if(!this->isFull()) {
buffer.at(_last) = x;
// Modular arithmetic to ensure a ring buffer that wraps around.
_last = (_last + 1) % _capacity;
_buffer_size++; } else {
throw std::runtime_error("enque: can't enque to a full ring.");
}
}

int16_t RingBuffer::dequeue() {
if(!this->isEmpty()) {
int num = buffer.at(_first);
buffer.at(_first) = 0;
_first = (_first + 1) % _capacity;
_buffer_size--;
return num;
} else {
throw std::runtime_error("dequeue: can't dequeue an empty ring.");
}
}


int16_t RingBuffer::peek() {
if(!this->isEmpty()) {
int16_t num = buffer.at(_first);
return num;
} else {
throw std::runtime_error("peek: can't peek an empty ring.");
}
}
