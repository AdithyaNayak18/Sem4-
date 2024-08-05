// 1. Import the necessary modules
const http = require('http');
const os = require('os');
const path = require('path');
const EventEmitter = require('events');

// 2. Create an instance of EventEmitter
const eventEmitter = new EventEmitter();

// 3. Set up a simple HTTP server that responds with "Hello, World!"
const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Hello, World!\n');
});

// 4. Define the server's port and hostname

// 5. Start the server and listen for incoming requests
server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
    
    // 6. Print information about the operating system
    console.log('Operating System Info:');
    console.log(`OS Type: ${os.type()}`);
    console.log(`Platform: ${os.platform()}`);
    console.log(`Architecture: ${os.arch()}`);
    console.log(`Number of CPU Cores: ${os.cpus().length}`);

    // 7. Print the current working directory
    console.log('Current Working Directory:', process.cwd());

    // 8. Use the path module to join directory paths and print the result
    const joinedPath = path.join(__dirname, 'sample', 'file.txt');
    console.log('Joined Path:', joinedPath);

    // 9. Set up a custom event listener and emit a custom event
    eventEmitter.on('customEvent', (message) => {
        console.log('Custom Event Triggered:', message);
    });

    // Emit the custom event
    eventEmitter.emit('customEvent', 'This is a custom event message!');
});
