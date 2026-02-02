Project to create a fully working loadbalancer

1. The first step I asked myself is what layer would it be best to implement this.

Using Flask or aiohttp would be at the top application layer. They automatically parse HTTP headers, handle cookies, and manage routing.
I need to handle raw TCP if i want to learn more about how packets are moved.

2. Should i use the raw socket library?

Too low-level. I'd have to manually writ the event loop.

Unit Tests: