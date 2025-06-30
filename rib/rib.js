import "src/Consts.js";

el = document.getElementsByClassName("draggable")[0]


// function move(x, y, el) {
//   el.style.position = "absolute";
//   el.style.top = y + "px"
//   el.style.left = x + "px"
// }


// function updateDisplay(event) {
//   el = document.getElementsByClassName("draggable")[0]
//   move(event.pageX, event.pageY, el)
// }

//box.addEventListener("mousemove", updateDisplay, false);
//box.addEventListener("mouseenter", updateDisplay, false);
//box.addEventListener("mouseleave", updateDisplay, false);


var c = document.getElementById("canvas");
var ctx = c.getContext("2d");
ctx.font = FONT_SIZE + "px Arial";


let canvas = new Canvas("canvas");

c.addEventListener("dblclick", (event) => {
  canvas.add(event.offsetX, event.offsetY);
});