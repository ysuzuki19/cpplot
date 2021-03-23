#!/bin/bash

while :;
do
  if make; then
    make run
  fi
  res=$(fswatch -1 --event Updated .)
done
