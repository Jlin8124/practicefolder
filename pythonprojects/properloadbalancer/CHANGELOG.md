# Dev Log - Load Balancer Project

## Version 0.20 - The Round Robin Update

**DATE:** Feb 3, 2026

### Features Added
- **Round Robin Routing** Implemented logic to rotate traffic between multiple backends (Port 8081, 8082).
- **Dynamic Backend** Updated `backend.py` to auto-detect its own port number
- **Proxy Logic:** `load_balancer.py` now succesfully forwards requests and relays responses back to the client.

### Bugs Fixed
1. **The Emoji Loop** - *Issue:* using `len(string)` for Content-length caused Chrome to retry infinitely becasue emojies are 4 bytes, not 1 char.
    - *Fix:* Converted body to bytes first, then used `len(body_bytes)`.
2. **The Double Body Bug:**
    - *Issue:* Accidentally included `f{body} in the header string and appendix
    - *Fix:* removed body from the header f-string
3. **The "Amnesia Bug":**
    - *Issue:* Defined `CURRENT_PORT_INDEX` inside the function, cuasing it to reset to 0 every request
    - *Fix:* Moved the index variable to Global Scope

### Known Issues (To be fixed in Ticket #4)
- **No Failover:** If a backend server crashes (e.g., Port 8082), the Load Balancer throws a `ConnectionRefusedError` and the user sees a broken page