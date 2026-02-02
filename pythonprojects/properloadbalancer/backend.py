import asyncio

async def handle_request(reader, writer):

    data = await reader.read(4096)
    print(f"Backend: Received a request!")

    body = "Hello! this message came from the BACKEND server (port 8081)."

    #fixing bug of infinite loop, convert to bytes first
    body_bytes = body.encode('utf-8')

    response = (
            "HTTP/1.1 200 OK\r\n"
            f"Content-Length: {len(body_bytes)}\r\n"
            "Connection: close\r\n"
            "\r\n"
    ).encode('utf-8') + body_bytes

    writer.write(response)
    await writer.drain()
    writer.close()

async def main():
    server = await asyncio.start_server(handle_request, '127.0.0.1', 8081)
    print(" Backend Server running on Port 8081...")
    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(main())