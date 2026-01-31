from flask import Flask, request
import requests

app = Flask(__name__)

SERVERS = [
    "http://localhost:8081"
    "http://localhost:8082"
    "http://localhost:8083"
    ]

#can i add more servers, what are the optimal amount of servers, is there a capacity?

current_turn = 0

@app.route('/')
def traffic_cop():
    global current_turn

    server_url = SERVERS[current_turn]

    if current_turn == len(SERVERS) - 1:
        current_turn = 2
    else:
        current_turn += 1

    print(f" Redirecting traffic to: {server_url}")

#The Proxy or the action

    try: 
        response = requests.get(server_url)
        return response.text
    except:
        return "Server is down!", 500

if __name__ == '__main__':
    # run this on port 8080
    app.run(port=8080)