// JavaScript
document.getElementById('openPopup').addEventListener('click', function() {
    document.getElementById('popup').style.display = 'block';
});

document.getElementById('closePopup').addEventListener('click', function() {
    document.getElementById('popup').style.display = 'none';
});

document.getElementById('execute').addEventListener('click', async function() {
    window.runCode();
});


let output = [];
let captureOutput = false;
// Override the Module.print function
console.log = function(text) {
    // Add the text to the output array
    if (text === '-c, --cli    interpret from command line, default: false') {
        captureOutput = true;
        return;
    }
    if (captureOutput) output.push(text);
};

// Load the dpli.js file
const script = document.createElement('script');
script.src = 'dpli.js';
script.onload = function() {
   

    Module.onRuntimeInitialized = async _ => {
        // The Module object is provided by dpli.js and contains the WebAssembly functions
        let main = Module.cwrap('main', 'number', ['number', 'number']);

        window.runCode = async function() {
            // Get the source code from the textarea
            let source = document.getElementById('code').value;

            // Write the source code to a file in the virtual file system
            let filename = 'source.dpl';
            Module.FS.writeFile(filename, source);

            // Create an array in the module's memory to hold the command line arguments
            let argv = ['dpli', filename].map(str => {
                let buffer = Module._malloc(str.length + 1); // allocate memory
                Module.stringToUTF8(str, buffer, str.length + 1); // copy the string into memory
                return buffer;
            });

            // Allocate memory for the argv array
            let argvPtr = Module._malloc(argv.length * 4); // 4 bytes per pointer

            // Write the argv array to memory
            Module.HEAP32.set(argv, argvPtr / 4); // HEAP32 is an Int32Array view on the memory

            
            // Call the main function
            main(argv.length, argvPtr);

            let outputStr = output.join('\n');
            output = [];
            //console.log(outputStr);
        
            // Handle the result
            let outputDiv = document.getElementById('output');
            outputDiv.innerText = outputStr;
         
            // Free the memory
            argv.forEach(ptr => Module._free(ptr));
            Module._free(argvPtr);
        }
    };
};
document.body.appendChild(script);