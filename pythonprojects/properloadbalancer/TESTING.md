#ticket 1: Load Balancer Connection Handling Tests

**Date:** Feb 1 2026
**Tester:** Jason Lin
**Environment:** Localhost (Dev)

## Test Plan

| ID | Test Case | Command | Expected Result | Pass/Fail |
| :--- | :--- | :--- | :--- | :--- |
| **T1** | **Happy Path**<br>(Standard Request) | `nc localhost 8080`<br>Type: "Hello"<br>Enter | - Client receives: "HTTP 200 OK"<br>- Server logs: "received from..." | [ ] |