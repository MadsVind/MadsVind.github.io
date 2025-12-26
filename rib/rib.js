// for text cursor make new text over existing text

const c     = document.getElementById("canvas");
const ctx   = c.getContext("2d");

ctx.font = FONT_SIZE + "px Computer Modern";


// Structure (Front-end -> Back-end)

// back_end
const change_handler = new ChangeHandler();
const rule_handler   = new RuleHandler();

// front_end
const event_handler  = new EventHandler(change_handler, rule_handler);
const canvas         = new CanvasHandler("canvas", rule_handler, event_handler, change_handler);

c.addEventListener("dblclick",  (event) => { canvas.dbl_click(event.offsetX, event.offsetY); });
c.addEventListener("mousedown", (event) => { canvas.click_down(event.offsetX, event.offsetY); });
c.addEventListener("mousemove", (event) => { canvas.move(event.offsetX, event.offsetY); });
c.addEventListener("mouseup",   (event) => { canvas.click_up(event.offsetX, event.offsetY); });
c.addEventListener("keydown",   (event) => { canvas.key_down(event.key); });
c.addEventListener("keyup",     (event) => { canvas.key_up(event.key);  });

c.setAttribute("tabindex", "0");
c.style.outline = "none"; 
c.focus(); 