#!/bin/zsh
echo Depth with 1000x1000 perfect maze:
time ./depth/solver map/1000perf > .tmp
echo A-star with 1000x1000 perfect maze:
time ./astar/solver map/1000perf > .tmp
echo Breadth with 1000x1000 perfect maze:
time ./breadth/solver map/1000perf > .tmp
rm .tmp
