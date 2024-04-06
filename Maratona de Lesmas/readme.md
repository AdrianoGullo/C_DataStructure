# Corrida de Lesmas

Este é um programa em C que determina qual lesma percorreu a maior distância em um determinado tempo, com base nas velocidades das lesmas.


## Funcionamento

O programa recebe como entrada o número de lesmas e as velocidades de cada lesma. Em seguida, solicita um tempo de corrida. 
Com base nas velocidades e no tempo fornecido, calcula a distância percorrida por cada lesma e determina qual lesma percorreu a maior distância. 

No entanto, as lesmas possuem limitações dado ao tempo de corrida.
Uma lesma que tenha velocidade entre 1 e 10 m/s, consegue correr até 3 horas na maratona.
Se tiver velocidade entre 11 e 20, consegue correr por 2 horas e caso tenha velocidade entre 21 e 100,
consegue correr apenas por 1 hora.
Assim, a lesma que vence a maratona precisa correr ela inteira, independente da velocidade. Então, em uma maratona de 3 horas,
é melhor ter uma velocidade de 9m/s e conseguir  correr durante a maratona inteira do que ter 27m/s e correr apenas por uma hora.

Utilizando as funções analisePercuro e distanciaCorrida, ao final o programa imprime a velocidade da lesma que ganhou a maratona.