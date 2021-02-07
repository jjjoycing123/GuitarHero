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

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include<stdint.h>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <exception>

class RingBuffer{
 public:
  explicit RingBuffer(int capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();

 private:
  std::vector<int16_t> buffer;
  unsigned _capacity = 0;
  unsigned _buffer_size = 0;
  unsigned _first;
  unsigned _last;
};

#endif
