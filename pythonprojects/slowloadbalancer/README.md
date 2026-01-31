## The Goal

I built this project to learn how massive scale systems distribute traffic
I wrote my round robin load balancer in Python to understand:

1. How Reverse Proxies actually handle forward requests

    The load balancer is connected to the user, and also to the backend server? It get's the data and then transmit it to the user
    It terminates the first connection, and creates a new connection to the back end.

2. The logic behind Round Robin Algorithms
3. The critical impact of blocking I/O on system performance

** The Cluster **

3 Backend Servers - Built with 'aiohttp" to simulate a real microservices cluster
1 Load Balancer - Built with 'Flask' acting as the "Traffic Cop"
The Client - Standard Web Browser

** Potential Problems **

Concurrency Bug
