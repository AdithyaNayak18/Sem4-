const fs = require('fs');
const path = require('path');

// Read and print the contents of example.txt
const filePath = path.join(__dirname, 'example.txt');
fs.readFile(filePath, 'utf8', (err, data) => {
    if (err) {
        console.error(`Error reading file: ${err.message}`);
        return;
    }
    console.log(`File contents:\n${data}`);

    // Write data to newFile.txt
    const newFilePath = path.join(__dirname, 'newFile.txt');
    const dataToWrite = 'This is some data that will be written to the new file.';
    fs.writeFile(newFilePath, dataToWrite, 'utf8', (err) => {
        if (err) {
            console.error(`Error writing to file: ${err.message}`);
            return;
        }
        console.log(`Data written to file: ${newFilePath}`);
    });
});

