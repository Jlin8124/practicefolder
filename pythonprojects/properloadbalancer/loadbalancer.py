__version__ = "0.1.0"

import asyncio

from asyncio import StreamReader, StreamWriter

async def handle_connection(reader: StreamReader, writer: StreamWriter):
    #variable originally named addr but address is more clear
    #metadata layer or ID Check
    #address is a tuple which is an immutable list
    #peername is a key or request code
    address = writer.get_extra_info('peername')
    print(f" Connection accepted from {address}")


    try:
        #we are assuming the entire User Request arrives in one delivery instead of looping

        data = await asyncio.wait_for(reader.read(4096), timeout=5.0)
    
        if not data:
            print(f" Ghost connection from {address} (No data sent)")
            return
        
        print(f" Forwarding {len(data)} byes to Backend...")
        be_reader, be_writer = await asyncio.open_connection('127.0.0.1', 8081)

        be_writer.write(data)
        await be_writer.drain()

        backend_data = await be_reader.read(4096)
        print(f" Received {len(backend_data)} bytes from Backend")

        writer.write(backend_data)
        await writer.drain()

        be_writer.close()
        await be_writer.wait_closed()

    except asyncio.TimeoutError:
        print (f" Timeout: {address} took too long to send data.")
    except ConnectionResetError:
        print(f" Client {address} disconnected abruptly")
    #tells python if an error runs in the above program don't crash the whole program 
    #instead just jump down here and run this code
    #Insurance Policy
    except Exception as e:
        print(f" Unexpected error with {address}: {e}")
    finally:
        print(f" Closing connection for {address}")
        writer.close()
        try:
            await writer.wait_closed()
        except Exception:
            pass

async def main():
    server = await asyncio.start_server(handle_connection, '127.0.0.1', 8080)

    address = server.sockets[0].getsockname()
    print(f" Load Balancer is online at {address}")

    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(main())