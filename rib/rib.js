// for text cursor make new text over existing text

const c = document.getElementById("canvas");
const ctx = c.getContext("2d");
ctx.font = FONT_SIZE + "px Computer Modern";


let canvas = new Canvas("canvas");

c.addEventListener("dblclick", (event) => {
  canvas.add(event.offsetX, event.offsetY);
});

c.addEventListener("mousedown", (event) => {
  canvas.click(event.offsetX, event.offsetY);
});

c.addEventListener("mousemove", (event) => {
  canvas.move(event.offsetX, event.offsetY);
});

c.addEventListener("mouseup", () => {canvas.drop()});

c.addEventListener("keydown", (event) => {
  canvas.key_press(event.key);
});

c.setAttribute("tabindex", "0");
c.style.outline = "none"; 
c.focus(); 