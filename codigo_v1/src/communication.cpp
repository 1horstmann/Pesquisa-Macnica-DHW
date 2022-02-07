#include <Arduino.h>
#include <ESPDateTime.h>
#include <ArduinoJson.h>

/*
Código exemplo enviado pelo Hazael:

temperature = 42.0

payload = {
    # collectorId do "Perini Tests"
    'collectorId': 'vJW0aIcUPjX1fAZABWtEYZBx7w1IoY7nNv4EcXZ3wxwKRwnCWg2d9ZAyUIVT0xXQ',

    # "items" é um array de "entidades" que vão ser enviadas ao Live Earth
    'items': [
        {
            # Cada item possui um entityId. Ao enviar para o Live Earth algo com um entityId que já
            #   existe, este será substituído. Caso não exista, será criado.
            'entityId': f'temperature_2',

            # O nome que é exibido pra este determinado item no mapa, na lista de itens e caixa de
            #   informação
            'name': f'Temperature',

            # Ícone que aparece no mapa, na lista de itens e caixa de informação
            'iconSource': 'https://assets.liveearth.com/icons/SharedMarkers/Marker_Alert_Red.svg',

            # Os dados que de fato vão ser exibidos na caixa de informações da entidade. Todos os
            #   testes que eu fiz foram com "type" sendo "number", para outros tipos tenho que ver
            #   com o pessoal do Live Earth quais exatamente existem.
            #
            # A caixa de informações é uma tabela com duas colunas: a coluna da esquerda mostra os
            #   "name"s e a coluna da direita mostra os "val"s associados. O campo "value" serve
            #   para fazer busca de valores, caso o campo "isSearchable" seja "true".
            #
            # Não vi o campo "color" ter algum efeito.
            'customAttributes': [
                {
                    'type': 'number',
                    'name': 'Temperature',
                    'value': temperature,
                    'val': '%0.3f °C' % temperature,
                    'color': '#ff0000',
                    'isSearchable': 'true'
                }
            ],

            # Timestamp deve ser no padrão ISO 8601, em UTC
            'timestamp': datetime.utcnow().replace(tzinfo=timezone.utc).isoformat(),

            # updatePeriod indica por quantos milissegundos a entidade vai permanecer no mapa. Na
            #   na prática ele fica mais tempo do que isso, então pode ser considerado um valor
            #   mínimo ao invés de exato.
            'updatePeriod': 60000,

            # Converter minutos e segundos de latitude e longitude pra decimal. Caso múltiplas
            #   entidades estejam no mesmo lugar ou suficientemente próximas, elas serão agrupadas
            #   pelo Live Earth e ao clicar no ícone no mapa abrirá um "Map Items" ao invés de
            #   abrir a entidade diretamente.
            'location': {
                'latitude': -26.2364,
                'longitude': -48.8829
            },
        }
    ]
}

# Log no console e coisa específica pra mandar o pacote pro endpoint, pode ignorar
print(json.dumps(payload, indent=4))
r = requests.post('https://api.liveearth.com/datacollector/event', json=payload)
print(r)
*/


