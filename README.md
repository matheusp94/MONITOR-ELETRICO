<p><h1>1. Proposta</h1><br>
O objetivo deste projeto é desenvolver um sistema de Internet das Coisas (IoT) capaz de monitorar e controlar dispositivos em tempo real, utilizando sensores e atuadores integrados a um dashboard intuitivo para fins educacionais. A aplicação visa monitorar o consumo de energia em uma escola média e permitir ações baseadas nos dados coletados, como controle de dispositivos e envio de notificações, ao mesmo tempo em que poderia ser feita a instrução dos alunos sobre a otimização do consumo de energia elétrica.
</p>

<p><h1>2. Sistema IoT Utilizado</h1><br>
O sistema foi desenvolvido utilizando os seguintes elementos:

<br>Simulador de hardware: Wokwi.
<br>Plataforma de gerenciamento e monitoramento: Blynk.
<br>Comunicação e protocolo: MQTT.
<br>Descrição Geral do Sistema
<br>Sensores e Atuadores Simulados:
<br>Potenciometro e LEDs para sinalização de diferentes condições.
</p>

<p><h1>3. Hardware</h1><br>
O projeto foi implementado utilizando simulação em vez de hardware físico. O ambiente escolhido foi o Wokwi para VScode, um simulador para dispositivos como Arduino, ESP32 e Raspberry Pi. Ele possibilitou a integração com bibliotecas e protótipos de maneira ágil e eficaz.


Componentes Simulados
Potenciômetros: Utilizado para simular a utilização de energia de um dispositivo eletrônico.
LEDs: Indicadores visuais para estados de operação (ex.: custo da energia).
</p>

<p><h1>4. Dashboard<h1><br>
Foi criado um dashboard no Blynk para monitoramento e controle dos dispositivos conectados ao sistema. O dashboard permite:

Visualização em tempo real dos dados:
Gráficos e indicadores para os valores de consumo de energia.

Graph Widget: Mostra tendências de consumo ao longo do tempo.
</p>

<p><h1>5. Gateway e Protocolo</h1><br>
Gateway<br>
O Blynk foi utilizado como gateway para comunicação entre o simulador de hardware e o dashboard. Ele gerencia a troca de dados em tempo real, permitindo controle e monitoramento de forma intuitiva.
<br><br>
Protocolo Utilizado: MQTT
O protocolo MQTT (Message Queuing Telemetry Transport) foi escolhido para a comunicação entre os dispositivos simulados e o Blynk. Este protocolo é amplamente utilizado em aplicações IoT devido às suas características:
<br><br>
Leve e eficiente: Ideal para dispositivos com recursos limitados.<br>
Baseado em mensagens: Utiliza o modelo publish/subscribe para troca de dados.
<br><br>
Funcionamento no Projeto:
<br><br>
Publicação: Os sensores simulados publicam os dados em tópicos MQTT específicos.<br>
Assinatura: O dashboard e outros componentes interessados assinam os tópicos para receber atualizações.<br>
Controle: Os comandos enviados pelo dashboard são publicados em tópicos que os dispositivos simulados monitoram.
</p>

<p><h1>6. Conclusão</h1><br>
Este projeto demonstra como integrar tecnologias IoT para coletar, processar e monitorar dados em tempo real, utilizando simulação de hardware, dashboards e protocolos leves como o MQTT. A escolha do Blynk como gateway permitiu um gerenciamento eficiente e uma interface amigável para interação com o sistema.
</p>