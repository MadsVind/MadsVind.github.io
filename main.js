// Load the Monaco Editor
require.config({ paths: { 'vs': 'https://unpkg.com/monaco-editor@0.20.0/min/vs' }});

// Define the syntax highlighting rules
const dplLanguageDefinition = {
    tokenizer: {
        root: [
            [/#[^\n]*$/, 'comment.line.dpl'],
            [/\b[0-9]+(\.[0-9]+)?\b/, 'constant.numeric.dpl'],
            [/(==|!=|<=|>=|<|>|\+|-|\*|\=|\%)/, 'keyword.operator.dpl'],
            [/\"[^"]*\"/, 'string.quoted.double.dpl'],
            [/\b(True|False|and|or|not|None|union|intersection)\b/, 'keyword.reserved.dpl'],
            [/\b(def|if|else|break|continue|while|return)\b/, 'keyword.control.dpl'],
            [/\b(print|input|len|copy|writeTable|readTable)\b/, 'support.function.dpl'],
            [/\b[a-zA-Z_][a-zA-Z0-9_]*\b(?=\()/, 'entity.name.function.dpl'],
            [/\b[a-zA-Z_][a-zA-Z0-9_]*\b/, 'variable.other.dpl'],
        ]
    }
};

const syntaxHighLightingTheme = {
    base: 'vs-dark', // can also be 'vs' or 'hc-black'
    inherit: true, // can also be false to completely replace the builtin rules
    rules: [
        { token: 'comment.line.dpl', foreground: '888888' },
        { token: 'constant.numeric.dpl', foreground: '00ff00' },
        { token: 'keyword.operator.dpl', foreground: 'c678dd' },
        { token: 'string.quoted.double.dpl', foreground: 'ce9178' },
        { token: 'keyword.reserved.dpl', foreground: 'c678dd' },
        { token: 'keyword.control.dpl', foreground: 'c678dd' },
        { token: 'support.function.dpl', foreground: '61aeee' },
        { token: 'entity.name.function.dpl', foreground: '61aeee' },
        { token: 'variable.other.dpl', foreground: '9cdcfe' },
    ],
    colors: {
        'editor.foreground': '#A9B7C6',
        'editor.background': '#282B2E',
        'editor.selectionBackground': '#363b41',
        'editor.lineHighlightBackground': '#323232',
        'editorCursor.foreground': '#A9B7C6',
        'editorWhitespace.foreground': '#3B3A32'
    }
};

// Example code to be loaded into the editor
const exampleCode = 
    '# Uses simple python syntax.' + '\n' +
    '# Below is example of table operations' + '\n' +
    '# Replaces missing values in area column with the product of width and height' + '\n' +
    't1 = { "width": [1, 2, 3], "height": [4, 5, 6], "area": [None, 10, None] }' + '\n' +
    't2 = t1[$"area"][==None]' + '\n' +
    't2[$"area"] = t2[$"width"] * t2[$"height"]'    + '\n' +
    't3 = t1[$"area"][==None][$"area"]' + '\n' + 
    'print(t2)' + '\n';

// Create the Monaco Editor
let editor;

require(['vs/editor/editor.main'], function() {

    monaco.languages.register({ id: 'dpl' });

    // Define the syntax highlighting rules
    monaco.languages.setMonarchTokensProvider('dpl', dplLanguageDefinition);

    // The Monaco Editor library is now loaded, so you can use the `monaco` object
    createEditor();
});

function createEditor() {
    monaco.editor.defineTheme('myTheme', syntaxHighLightingTheme);

    editor = monaco.editor.create(document.getElementById('code'), {
        value: exampleCode,
        language: 'dpl',
        theme: 'myTheme',
    });
}

// Popup control
function openPopup() {
    document.getElementById('popup').style.display = 'block';
    if (!editor) createEditor();
    else editor.layout();
}

function closePopup() {
    document.getElementById('popup').style.display = 'none';
}

// Code execution
let output = [];
let captureOutput = false;

console.log = function(text) {
    if (text === '-c, --cli    interpret from command line, default: false') captureOutput = true; 
    else if (captureOutput) output.push(text);
};

function createArgv(args) {
    return args.map(str => {
        let buffer = Module._malloc(str.length + 1);
        Module.stringToUTF8(str, buffer, str.length + 1);
        return buffer;
    });
}

function createArgvPtr(argv) {
    let argvPtr = Module._malloc(argv.length * 4);
    Module.HEAP32.set(argv, argvPtr / 4);
    return argvPtr;
}

function handleOutput() {
    if (output[0] === "") output.shift(); // Remove the first line
    let outputStr = output.join('\n');
    output = [];
    let outputDiv = document.getElementById('output');
    outputDiv.innerText = outputStr;
}

function freeMemory(argv, argvPtr) {
    argv.forEach(ptr => Module._free(ptr));
    Module._free(argvPtr);
}

// Load the dpli.js file
const script = document.createElement('script');
script.src = 'dpli.js';
script.onload = loadDpli;
document.body.appendChild(script);

function loadDpli() {
    Module.onRuntimeInitialized = async _ => {
        let main = Module.cwrap('main', 'number', ['number', 'number']);
        window.runCode = async function() {
            let source = editor.getValue();
            let filename = 'source.dpl';
            Module.FS.writeFile(filename, source);
            let argv = createArgv(['dpli', filename]);
            let argvPtr = createArgvPtr(argv);
            main(argv.length, argvPtr);
            handleOutput();
            freeMemory(argv, argvPtr);
        }

        
        // Event listeners
        document.getElementById('openPopup').addEventListener('click', openPopup);
        document.getElementById('closePopup').addEventListener('click', closePopup);
        document.getElementById('execute').addEventListener('click', runCode);
        window.addEventListener('resize', () => editor.layout());
    };
}