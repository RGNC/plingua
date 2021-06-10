#!/bin/bash

plingua graph.pli -o graph.bin -f bin

for i in {1..30}
do
  echo "Simulation $i"
  sleep 10
  time psim graph.bin -r
done

# results for i5-2500 at 3.3 Ghz.
# Average: 5.9 ms
# min: 5 ms
# sd: 0.3051286

# Simulation 1

#real	0m0,006s
#user	0m0,003s
#sys	0m0,003s
#Simulation 2

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 3

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 4

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 5

#real	0m0,006s
#user	0m0,000s
#sys	0m0,006s
#Simulation 6

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 7

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 8

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 9

#real	0m0,006s
#user	0m0,003s
#sys	0m0,003s
#Simulation 10

#real	0m0,005s
#user	0m0,000s
#sys	0m0,005s
#Simulation 11

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 12

#real	0m0,006s
#user	0m0,000s
#sys	0m0,006s
#Simulation 13

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 14

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 15

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 16

#real	0m0,006s
#user	0m0,003s
#sys	0m0,003s
#Simulation 17

#real	0m0,005s
#user	0m0,003s
#sys	0m0,003s
#Simulation 18

#real	0m0,006s
#user	0m0,003s
#sys	0m0,003s
#Simulation 19

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 20

#real	0m0,006s
#user	0m0,005s
#sys	0m0,000s
#Simulation 21

#real	0m0,006s
#user	0m0,005s
#sys	0m0,000s
#Simulation 22

#real	0m0,006s
#user	0m0,003s
#sys	0m0,003s
#Simulation 23

#real	0m0,006s
#user	0m0,005s
#sys	0m0,000s
#Simulation 24

#real	0m0,005s
#user	0m0,005s
#sys	0m0,000s
#Simulation 25

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 26

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 27

#real	0m0,005s
#user	0m0,005s
#sys	0m0,000s
#Simulation 28

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 29

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
#Simulation 30

#real	0m0,006s
#user	0m0,006s
#sys	0m0,000s
