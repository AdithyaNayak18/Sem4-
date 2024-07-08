const http=require('http');
const server=http.createServer((req,res)=>{
    res.writeHead(200,{'Content-Type':'text/plain'});
    const path=res.url;
    if(path==='/'){
        res.end('Welcome to home page');
    }
    else if(path==='/about'){
        res.end('Welcome to about page');
    }
    else if(path==='/info'){
        res.end('Welcome to info page');
    }
    else{
        res.writeHead(404,{'Content-Type':'text/plain'});
        res.end('Invalid Page please enter propelry');
    }

});
server.listen(3000,()=>{
    console.log('Server is running on port 3000');
});
