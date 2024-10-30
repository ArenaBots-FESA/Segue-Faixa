# Segue-Faixa
Figura 0 - protótipo em desenvolvimento

![prototipo](https://github.com/ArenaBots-FESA/Segue-Faixa/assets/73361982/01803381-db3e-4d3d-b95b-043e305bc340)

Componentes utilizados: 2 motores N20 e 5 sensores QRE113GR da Robocore, 1 placa Arduino Nano.
Com relação aos sensores, representados na Figura 1, eles possuem três terminais OUT (sinal da saída do sensor) GND (aterramento) e VCC (alimentação). Todos os sensores funcionaram, possuindo faixa de sinal de 0 até 1023. Cores brancas tiveram a leitura inferior que 100, enquanto cores pretas tiveram a leitura superior a 900. Os sensores possuem corrente de funcionamento de 50 mA e tensão de 5 V. 

Figura 1 - Sensor QRE113 Robocore

![image](https://github.com/ArenaBots-FESA/Sumo-mini-auto/assets/73361982/1e0a237c-5324-462c-858e-3e4dd0f62fb5)

Fonte: Disponível em: <https://www.robocore.net/sensor-robo/sensor-de-linha-qre-analogico>, 2024.

Já para os motores com caixa de redução, representados na Figura 2, tendo tensão de operação de 3 a 9 V, peso de 15 g, rotação de 1000 rpm, corrente de 1,6 A e Torque de 0,57 kgf*cm (aproximadamente 0,056 N*m) caso a tensão de operação seja de 6V, foi realizado o teste de giro deles com o uso da ponte H “L298N”

Figura 2 - Motores 6V

![image](https://github.com/ArenaBots-FESA/Sumo-mini-auto/assets/73361982/69a5fb26-950c-43a9-b781-741f63c1cd66)

Fonte: Disponível em: <https://www.robocore.net/motor-motoredutor/micro-motor-com-caixa-de-reducao-6v-300rpm>, 2024.

Os códigos utilizados para teste se encontram na pasta “Teste de Componentes”.
