Proposta: Educação em gestão energética - introdução de programas de educação em instituições de ensino, ensinando crianças e jovens sobre eficiência energética e como podem reduzir o consumo de energia em suas casas. Procura-se formar uma nova geração mais conciente sobre o uso potável de energia elétrica.
<br>
Sistema IoT: A solução foca em duas variáveis fundamentais, voltagem (volts) e corrente (amperes). A partir dessas variáveis conseguiremos obter valores de consumo por tempo e custo da energia elétrica consumida.
<br>
Hardware: Para o hardware, optamos por utilizar uma simulação da placa esp32 utilizando o wokwi para vscode. É criado um ambiente similar ao wokwi versão web na máquina para simular as funções da placa e possíveis dospositivos.
<br>
Dashboard: Mostra as duas variáveis principais para que seja realizado o monitoramento de valores.
<br>
Gateway e protocolo: Utilizamos o MQTT gateway do Blynk, pois comunica em tempo real dispositivos. O Blynk pode funcionar como cliente MQTT, integrando-se a plataformas que suportam o protocolo MQTT.
