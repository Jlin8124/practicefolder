import asyncio
import sys

async def handle_request(reader, writer):

    #so 'sockname' has {IP ADDRESS, PORT NUMBER}
    port = writer.get_extra_info('sockname')[1]

    data = await reader.read(4096)

    print(f"Backend ({port}): Received a request!")

    body = (f"Hello! this message came from the BACKEND port running on Port {port}.")

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

    if len(sys.argv) > 1:
        port = int(sys.argv[1])
    else:
        port = 8081
    server = await asyncio.start_server(handle_request, '127.0.0.1', port)
    print(f" Backend Server running on Port {port}...")
    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(main())