#!/bin/bash

gnuplot -persist <<-EOFMarker
 
   
    set output 'nao-ordenados.png' 
    set terminal png
    set key above
    set title 'Dados Não Ordenados'
    set xlabel "Quantidade de Dados"
    set ylabel "Tempo em Segundos"

    plot 'dados_nao_ordenados.dat' using 1:2 title 'bubble'with lines, 'dados_nao_ordenados.dat' using 1:3 title 'selection' with lines, 'dados_nao_ordenados.dat' using 1:4 title 'insertion' with lines

EOFMarker

gnuplot -persist <<-EOFMarker
    set output 'ordenados.png' 
    set terminal png
    set key above
    set title 'Dados Ordenados'
    set xlabel "Quantidade de Dados"
    set ylabel "Tempo em Segundos"
   
     plot 'dados_ordenados.dat' using 1:2 title 'bubble'with lines, 'dados_ordenados.dat' using 1:3 title 'selection' with lines, 'dados_ordenados.dat' using 1:4 title 'insertion' with lines

EOFMarker
