#!/bin/bash

gnuplot -persist <<-EOFMarker
 
   
    set output 'bubbles-nao-ordenados.png' 
    set terminal png
    set key above
    set title 'Dados Não Ordenados'
    set xlabel "Quantidade de Dados"
    set ylabel "Tempo em Segundos"

    plot 'bubbles_nao_ordenados.dat' using 1:2 title 'bubble1'with lines, 'bubbles_nao_ordenados.dat' using 1:3 title 'bubble2' with lines, 'bubbles_nao_ordenados.dat' using 1:4 title 'bubble3' with lines

EOFMarker

gnuplot -persist <<-EOFMarker
    set output 'bubbles-ordenados.png' 
    set terminal png
    set key above
    set title 'Dados Ordenados'
    set xlabel "Quantidade de Dados"
    set ylabel "Tempo em Segundos"
   
     plot 'bubbles_ordenados.dat' using 1:2 title 'bubble1'with lines, 'bubbles_ordenados.dat' using 1:3 title 'bubble2' with lines, 'bubbles_ordenados.dat' using 1:4 title 'bubble3' with lines

EOFMarker
