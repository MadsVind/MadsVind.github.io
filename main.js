// JavaScript
document.getElementById('openPopup').addEventListener('click', function() {
    document.getElementById('popup').style.display = 'block';
});

document.getElementById('closePopup').addEventListener('click', function() {
    document.getElementById('popup').style.display = 'none';
});

document.getElementById('execute').addEventListener('click', async function() {
    console.log('Executing code...');
    runCode();
});


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
        let argv = ['dpli', filename].map(str => Module.allocate(intArrayFromString(str), 'i8', Module.ALLOC_NORMAL));

        // Call the main function
        let result = main(argv.length, Module.allocate(argv, 'i32', Module.ALLOC_NORMAL));

        // Handle the result
        console.log('main returned', result);
    };
};