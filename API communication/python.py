import requests

resposta  = requests.get('http://api.github.com/')


dados = resposta.json()
print(dados['current_user_url'])