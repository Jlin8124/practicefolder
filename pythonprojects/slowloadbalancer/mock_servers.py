from aiohttp import web
import asyncio

async def hello(request):
    port = request.app['port']
                       
    if port == 8081:
        #testing inefficienes of a simple load balancer
        print(f"Port {port} is sleeping for 10 seconds ... (Blocking!)")
        await asyncio.sleep(10)
    
    return web.Response(text=f"Hello from Backend on Port {port}")

async def start_server(port):
    app = web.Application()
    app['port'] = port

    app.router.add_get('/', hello)

    runner = web.AppRunner(app)
    await runner.setup()

    site = web.TCPSite(runner, 'localhost', port)
    await site.start()

    print(f"Backend started on http:localhost:{port}")
    return runner

async def main():
    await asyncio.gather(
        start_server(8081),
        start_server(8082),
        start_server(8083),
    )

    await asyncio.Event().wait()

if __name__ == '__main__':
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        pass

