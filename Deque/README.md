# Deque Implementation

## Overview
This project implements a deque(double-ended queue) using a 2D array

## Features
- Uses blocks to group data and allow quick resizing
- Acts like a queue, supporting 'push/pop'_'front/back'
- Blocks contain empty slots for quick insertion
- Resizing is handled automatically when block is filled or there are many unused blocks

## Member Functions
- 'push_front(int num)' - puts an element in the next empty left space
- 'push_back(int num)' - puts an element in the next empty right space
- 'pop_front()' - removes the leftmost element and returns it
- 'pop_back()' - removes the rightmost element and returns it

## Work Division
- Work was done singularly