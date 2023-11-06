#pragma once
#ifndef LIFE_H
#define LIFE_H

const char live_cell{ 'X' };
const char dead_cell{ ' ' };

const int rowMax = 23;
const int colMax = 79;

//using ANSI console w/ a 1 char border

//conway param
const int min_neighbors = 2;
const int max_neighbors = 3;
const int min_parents = 3;
const int max_parents = 3;

#endif
