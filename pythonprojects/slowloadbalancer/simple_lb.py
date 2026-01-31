from flask import Flask, request
import requests

app = Flask(__name__)

SERVERS = [
    "http://localhost:8081",
    "http://localhost:8082",
    "http://localhost:8083"
    ]

#can i add more servers, what are the optimal amount of servers, is there a capacity?

current_turn = 0

@app.route('/')
def traffic_cop():
    global current_turn

    server_url = SERVERS[current_turn]
    
    server_url = SERVERS[current_turn]
    current_turn = (current_turn + 1) % len(SERVERS)

    print(f" Redirecting traffic to: {server_url}")

#The Proxy or the action

    try: 
        response = requests.get(server_url)
        return response.text
    except Exception as e:
        print(f"❌ Error: {e}")
        return "Server is down!", 500

if __name__ == '__main__':
    # run this on port 8080
    print(" Running in BLOCKING Mode (Single-Threaded)")
    app.run(port=8080, threaded = False)