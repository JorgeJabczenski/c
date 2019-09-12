#!/bin/bash

echo "tam bolha selecao insercao" > dados_nao_ordenados.dat

for ((i=1000; i <= 50000; i+=1000))
do
	command time -o temp.tmp -f "%U" ./Bubble_Sort/ebubble < ./entradas/nao_ordenadas/$i.txt
	cat temp.tmp >> dados_nao_ordenados.dat
done 

