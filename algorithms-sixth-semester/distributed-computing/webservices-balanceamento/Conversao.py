# Jenifer Mathias dos Santos
# TIA: 32092946

# Codigo implementado na instancia da AWS

from flask import Flask, jsonify
import requests

app = Flask(__name__)

@app.route('/convertemoeda/<float:valor>')
def convertemoeda(valor):
    try:
        response = requests.get("https://api.exchangerate-api.com/v4/latest/BRL")
        data = response.json()
        dolar = round(valor / data['rates']['USD'], 2)
        euro = round(valor / data['rates']['EUR'], 2)
        return jsonify({'conversao': {'real': valor, 'dolar': dolar, 'euro': euro}})
    except:
        return jsonify({'erro': 'Não foi possível converter a moeda.'})

if __name__ == '__main__':
    app.run(debug=True, port=5000, host='0.0.0.0')