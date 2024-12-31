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
            return Matrix.fromString(matrixStr, splitter);
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
        const matrix = new Matrix(0, 0);
        for (let row of rows) {
            matrix.addRow(row);
        }
        return matrix;
    }

    toString(splitter = '; ') {
        return this.#matrix.map(row => row.join(' ')).join(splitter);
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
    
    static fromHtml(htmlMatrix, rowAmount = undefined, colAmount = undefined) {
        const rows = htmlMatrix.children;

        const htmlRowAmount = rows.length;
        const htmlColAmount = rows[0].children.length;

        if (rowAmount === undefined) rowAmount = htmlRowAmount;
        if (colAmount === undefined) colAmount = htmlColAmount;

        const matrix = new Matrix(rowAmount, colAmount);


        for (let i = 0; i < rowAmount; ++i) {
            for (let j = 0; j < colAmount; ++j) {
                const isHtmlVal = (i < htmlRowAmount) && (j < htmlColAmount);
                //! Would be more efficient if rows is taken out to outer loop
                const value = (isHtmlVal) ? rows[i].children[j].value : 0;
                matrix.setCell(value, i, j); 
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

    copyValues(matrix) {
        const rows = Math.min(matrix.rows, this.rows);
        const columns = Math.min(matrix.columns, this.columns);

        for (let i = 0; i < rows; ++i) {
            for (let j = 0; j < columns; ++j) {
                this.setCell(matrix.getCell[i][j], i, j);
            }
        }
    }

    setCell(val, row, col) {
        this.#matrix[row][col] = val;
    }

    setRow(row, idx) {
        this.#matrix[idx] = row;
    }

    addRow(row) {
        if (this.#rows != 0 && row.length != this.#columns) throw Error(`Row: ${row}\nIs incompatible with matrix: ${this.#matrix}`)
        if (this.#rows == 0) this.#columns = row.length;
        this.#rows++; 
        this.#matrix.push(row);
    }

    getCell(row, col) {
        return this.#matrix[row][col];
    }

    get rows() {
        return this.#rows;
    }

    get columns() {
        return this.#columns;
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
        
        const rows    = document.getElementById('row-input-1').value;
        const columns = document.getElementById('column-input-1').value;

        for (let i = 0; i < elements.length; ++i) {
            if (i < inputMatrixesAmount) {
                this.#inputMatrixes[i] = Matrix.fromHtml(elements[i], rows, columns); 
            }
            else this.#outputMatrixes[i - inputMatrixesAmount] = new Matrix(rows, columns);
        }
    }

    update(methodTitle = undefined) {
        this.updateMatrixes() 
        
        if (methodTitle != undefined) this.#method = Method.getMethodByTitle(methodTitle);

        this.#inputMatrixes = this.#fillMatrixes(this.#inputMatrixes, this.#method.inputAmount);
        this.#outputMatrixes = this.#fillMatrixes(this.#outputMatrixes, this.#method.outputAmount);

        this.#setMathArea();
    } 

    calculate() {
        this.updateMatrixes();
        const matrixStrArr = this.#inputMatrixes.map(matrix => matrix.toString());
        window.runCode(this.#method.title, matrixStrArr);
    }

    clear() {
        for (let i = 0; i < this.#inputMatrixes.length; ++i) {
            let matrix = this.#inputMatrixes[i]
            this.#inputMatrixes[i] = new Matrix(matrix.rows, matrix.columns);
        }
        for (let i = 0; i < this.#outputMatrixes.length; ++i) {
            let matrix = this.#outputMatrixes[i]
            this.#outputMatrixes[i] = new Matrix(matrix.rows, matrix.columns);
        }
        this.#setMathArea();
    }

    setOutput(matrixStrArr, splitter) {
        for (let i = 0; i < this.#outputMatrixes.length; ++i) {
            this.#outputMatrixes[i] = new Matrix(undefined, undefined, matrixStrArr[i], splitter);
        }
        this.#setMathArea();
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
//Method.addMethod(new Method(title=INVERSE,     inputAmount=1, outputAmount=1));
//Method.addMethod(new Method(title=REF,         inputAmount=1, outputAmount=2, operatorString="|"));
//Method.addMethod(new Method(title=RREF,        inputAmount=1, outputAmount=2, operatorString="|"));
//Method.addMethod(new Method(title=QR,          inputAmount=1, outputAmount=2, operatorString="|"));
//Method.addMethod(new Method(title=PLU,         inputAmount=1, outputAmount=3, operatorString="|"));

Method.initMethodNav()
mathArea = new MathArea();
Method.updateActive(ADD)

// Web assembly code
let output = [];
var Module = {}

console.log = function(text) { 
    output.push(text);
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
    let outputStr = output.join('\n');
    output = [];
    mathArea.setOutput([outputStr], " \n");
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
        window.runCode = async function(method, matrixArr) {
            let argv = createArgv(['cnn', method, ...matrixArr]);
            let argvPtr = createArgvPtr(argv);
            main(argv.length, argvPtr);
            handleOutput();
            freeMemory(argv, argvPtr);
        }
    };
}
