class Matrix {
    #rows;
    #columns;
    #matrix;

    constructor(rows = undefined, columns = undefined, matrixStr = undefined, splitter = undefined) {
        if (rows != undefined && columns != undefined) {
            this.#rows = rows;
            this.#columns = columns;
            this.#matrix = Matrix.createZeroMatrix(this.#rows, this.#columns);
        } else if (matrixStr != undefined && splitter != undefined) {
            this.#matrix = Matrix.fromString(matrixStr, splitter);
            this.#rows = this.matrix.length;
            this.#columns = this.matrix[0].length;
        }
        else throw Error(`Either rows and columns need to be given or matrixStr and Splitter`
                    +    `\nRows: ${rows}`
                    +    `\nColumns: ${columns}`
                    +    `\nMatrixStr: ${matrixStr}`
                    +    `\nSplitter: ${splitter}`)
    }


    static fromString(matrixStr, splitter) {
        const rows = matrixStr.trim().split(splitter).map(
            row => row.split(' ').map(Number)
        );
        const rowCount = rows.length;
        const colCount = rows[0].length;
        const matrix = new Matrix(rowCount, colCount);
        for (let row in rows) {
            matrix.addRow(row);
        }
        return matrix;
    }

    getHtml() {
        const matrixContainer = '<div class="matrix-container">';
        const rowStart        = '<div class="row">';
        const cellStart       = '<input class="square-cell text-center" value="';
        const rowEnd          = '</div>';
        
        let returnStr = matrixContainer;

        for (let i = 0; i < this.#rows; i++) {
            returnStr += `\n${rowStart}`;
            for (let j = 0; j < this.#columns; j++) {
                returnStr += `\n${cellStart}${this.#matrix[i][j]}" id="${i}:${j}">`;
            }
            returnStr += `\n${rowEnd}`;
        }
        returnStr += `\n${rowEnd}`; 
        return returnStr;
    }
    
    static fromHtml(htmlMatrix) {
        const rows = htmlMatrix.children;
        const colAmount = rows[0].children.length;
        const rowAmount = rows.length;

        const matrix = new Matrix(colAmount, rowAmount);

        for (let i = 0; i < rowAmount; ++i) {
            const cells = rows[i].children;
            for (let j = 0; j < colAmount; ++j) {
                matrix.setCell(cells[j].value, i, j);
            }
        }
    
        return matrix;
    }

    static createZeroMatrix(rows, columns) {
        const matrix = [];
        for (let i = 0; i < rows; i++) {
            matrix.push([]);
            for (let j = 0; j < columns; j++) {
                matrix[i].push(0);
            }
        }
        return matrix;
    }

    deepCopy() {
        const copy = new Matrix(this.#rows, this.#columns);
        for (let i = 0; i < this.#rows; i++) {
            for (let j = 0; j < this.#columns; j++) {
                copy.setCell(this.#matrix[i][j], i, j);
            }
        }
        return copy;
    }

    setCell(val, row, col) {
        this.#matrix[row][col] = val;
    }

    setRow(row, idx) {
        this.#matrix[idx] = row;
    }

    addRow(row) {
        this.#matrix.push(row);
    }

    getCell(row, col) {
        return this.#matrix[row][col];
    }
}
// Could add check for matching col row for dot and matching size for add and subtract...
// But i have been doing enough over engineering.
class Method {
    static #METHODS = [];
    static #activeMethod = undefined;
    static #element = document.getElementById("method-nav");
    
    #title
    #inputAmount
    #outputAmount
    #operatorString
    
    constructor(title, inputAmount, outputAmount, operator="") {
        this.#title = title;
        this.#inputAmount = inputAmount;
        this.#outputAmount = outputAmount;
        this.#operatorString = operator;
    }

    get title() {
        return this.#title;
    }
    static updateActive(methodTitle) {
        if (Method.#activeMethod != undefined)
            document.getElementById("nav-" + Method.#activeMethod.title).classList.toggle('active');
        Method.#activeMethod = this.getMethodByTitle(methodTitle);
        document.getElementById("nav-" + methodTitle).classList.toggle('active');
    }
    
    get inputAmount() {
        return this.#inputAmount;
    }
    
    get outputAmount() {
        return this.#outputAmount;
    }
    
    get operatorString() {
        return this.#operatorString;
    }
    
    static isValid(method) {
        return this.#METHODS.includes(method);
    }
    
    static getMethodByTitle(title) {
        return this.#METHODS.find(method => method.title === title);
    }
    
    static addMethod(method) {
        if (undefined != this.getMethodByTitle(method.title)) throw Error(`A method already exist with the title ${method.title}`)
            this.#METHODS.push(method);
    }
    
    static initMethodNav() {
        this.#element.innerHTML = "";
        
        const elementStart = '<li class="nav-item">';
        const elementEnd = '</li>';
        const buttonStart = '<a class="nav-link';
        const onclick = 'onclick="'; 
        const buttonEnd = '</a>';
        
        const methodAmount = this.#METHODS.length;
        for (let i = 0; i < methodAmount; i++) {
            let methodTitle = this.#METHODS[i].title;
            let capitalTitle = methodTitle.charAt(0).toUpperCase() + methodTitle.slice(1);

            this.#element.innerHTML += `${elementStart}${buttonStart}" id="nav-${this.#METHODS[i].title}"`
                                     + ` ${onclick}mathArea.update(${methodTitle.toUpperCase()}); Method.updateActive(${methodTitle.toUpperCase()})">${capitalTitle}${buttonEnd}`
                                     + `${elementEnd}`; 
        }
    }

}

class MathArea {
    #mathAreaId = 'math-area'
    #element = document.getElementById(this.#mathAreaId);
    #rowAmount = 3
    #colAmount = 3
    
    #method
    #inputMatrixes
    #outputMatrixes
    
    constructor() {
        this.#method  = Method.getMethodByTitle(ADD);
        this.#inputMatrixes = [new Matrix(this.#rowAmount, this.#colAmount), new Matrix(this.#rowAmount, this.#colAmount)];
        this.#outputMatrixes = [new Matrix(this.#rowAmount, this.#colAmount)];
        this.#setMathArea();
    }

    updateMatrixes() {
        const elements = document.querySelectorAll('.matrix-container');
        const inputMatrixesAmount = this.#method.inputAmount;
        for (let i = 0; i < elements.length; ++i) {
            let element = elements[i];
            const newMatrix = Matrix.fromHtml(element);
            if (i < inputMatrixesAmount) this.#inputMatrixes[i] = newMatrix;
            else this.#outputMatrixes[i - inputMatrixesAmount] = newMatrix;   
        }
        
    }

    update(methodTitle) {
        this.updateMatrixes() // This is seemingly not working
        
        this.#method = Method.getMethodByTitle(methodTitle);

        this.#inputMatrixes = this.#fillMatrixes(this.#inputMatrixes, this.#method.inputAmount)
        this.#outputMatrixes = this.#fillMatrixes(this.#outputMatrixes, this.#method.outputAmount)

        this.#setMathArea()
        
    } 
    
    #fillMatrixes(matrixes, amount) {
        if (matrixes.length < amount) {
            const missingMatrices = amount - matrixes.length;
            for (let i = 0; i < missingMatrices; ++i) {
                matrixes.push(new Matrix(this.#rowAmount, this.#colAmount))
            }
        }
        return matrixes;
    }

    #setMathArea() {
        this.#element.innerHTML = ""
        const operator = `<div class="mx-3 text-white" style="font-size: 2rem;">${this.#method.operatorString}</div>`  
        const equals   = `<div class="mx-3 text-white" style="font-size: 2rem;">=</div>`
        
        const inputMatrixAmount = this.#method.inputAmount;
        const outputMatrixAmount = this.#method.outputAmount;
        
        for (let i = 0; i < inputMatrixAmount; i++) {
            this.#element.innerHTML += this.#inputMatrixes[i].getHtml() + '\n';
            if (i < (inputMatrixAmount - 1)) this.#element.innerHTML += operator + '\n'
        }
        
        this.#element.innerHTML += equals + '\n'
        
        for (let i = 0; i < outputMatrixAmount; i++) {
            this.#element.innerHTML += this.#outputMatrixes[i].getHtml() + '\n';
            if (i < (outputMatrixAmount - 1)) this.#element.innerHTML += operator + '\n'
        }
    }
}

ADD         = "add";
SUBTRACT    = "subtract";
DOT         = "dot";
DETERMINANT = "determinant";
INVERSE     = "inverse";
TRANSPOSE   = "transpose";
REF         = "ref";
RREF        = "rref";
EIGEN       = "eigen";
QR          = "qr";
PLU         = "plu";

Method.addMethod(new Method(title=ADD,         inputAmount=2, outputAmount=1, operatorString="+"));
Method.addMethod(new Method(title=SUBTRACT,    inputAmount=2, outputAmount=1, operatorString="-"));
Method.addMethod(new Method(title=DOT,         inputAmount=2, outputAmount=1, operatorString="X"));
Method.addMethod(new Method(title=DETERMINANT, inputAmount=1, outputAmount=1));
Method.addMethod(new Method(title=INVERSE,     inputAmount=1, outputAmount=1));
Method.addMethod(new Method(title=REF,         inputAmount=1, outputAmount=2, operatorString="|"));
Method.addMethod(new Method(title=RREF,        inputAmount=1, outputAmount=2, operatorString="|"));
Method.addMethod(new Method(title=QR,          inputAmount=1, outputAmount=2, operatorString="|"));
Method.addMethod(new Method(title=PLU,         inputAmount=1, outputAmount=3, operatorString="|"));

Method.initMethodNav()
mathArea = new MathArea();
Method.updateActive(ADD)

// Web assembly code
let output = [];
var Module = {}

//console.log = function(text) { 
//    output.push(text);
//};

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
    console.log(output)
    if (output[0] === "") output.shift(); // Remove the first line
    let outputStr = output.join('\n');
    output = [];
    console.log(outputStr);
}

function freeMemory(argv, argvPtr) {
    argv.forEach(ptr => Module._free(ptr));
    Module._free(argvPtr);
}

// Load the cnn.js file
const script = document.createElement('script');
script.src = 'cnn.js';
var Module = {}
script.onload = loadCnn
document.body.appendChild(script);

function loadCnn() {
    Module.onRuntimeInitialized = async _ => {
        let main = Module.cwrap('main', 'number', ['number', 'number']);
        window.runCode = async function() {
            let method = "add";
            let matrix1 = "1 2; 3 4"
            let matrix2 = "5 6; 7 8"
            // Insert getting matrices and formatting here
            let argv = createArgv(['cnn', method, matrix1, matrix2]);
            let argvPtr = createArgvPtr(argv);
            main(argv.length, argvPtr);
            handleOutput();
            freeMemory(argv, argvPtr);
        }
    };
}