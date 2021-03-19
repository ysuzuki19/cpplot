#!/bin/bash

while :;
do
  make
  make run
  res=$(fswatch -1 --event Updated .)
done
