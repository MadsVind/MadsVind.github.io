// Can't edit lower text

class Canvas {
  id = null;
  ctx = null;
  canvas = null;
  rule_list = [];
  // Flags
  debug = false;
  // Make edit event maybe!?
  active_text = null;
  active_rule = null;
  // Make drag event maybe!?
  dragged_rule = null; 
  drag_diff_x = 0;
  drag_diff_y = 0;
  
  constructor(id) {
    this.id = id;
    this.canvas = document.getElementById(this.id);
    this.ctx = this.canvas.getContext("2d");
  }

  set_debug(bool) {
    this.debug = bool;
    this.update();
  }

  update() {
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
    for (let rule of this.rule_list) {
      rule.draw(this.ctx, this.debug);
    }
  }

  add(x, y) {
    this.rule_list.push(new Rule(x, y, this.ctx));
    this.update();
  }

  click(x, y) {
    if (this.debug) console.log(`Click X: ${x}, Y: ${y}`);
    for (let rule of this.rule_list) {
      const box = rule.get_box();
      box.log();

      if (box.is_within(x, y)) {
        if (this.debug) console.log(`Click is within boundaries - X: ${x}, Y: ${y}`);
        this.dragged_rule = rule;
        this.drag_diff_x = x - box.get_x(); 
        this.drag_diff_y = y - box.get_y(); 

        const conclussion = rule.get_conclussion();
        const premise = rule.get_premise();

        let text = null;
        if (conclussion.get_box().is_within(x, y)) 
          text = conclussion;
        else if (premise.get_box().is_within(x, y)) 
          text = premise;
        
        if (text != null) {
          this.active_text = text;
          this.active_rule = rule;
          break;
        }
      } else {
        this.active_text = null;
        this.active_rule = null;
      }
    }
  }

  move(x, y) {
    if (this.dragged_rule != null) {
      this.dragged_rule.set_pos(x - this.drag_diff_x, y - this.drag_diff_y);
      this.update();
    }
  }

  drop() {
    this.dragged_rule = null;
    this.drag_diff_x = null;
    this.drag_diff_y = null;
  }

  key_press(key) { // Not Done
    const text = this.active_text;
    if (text == null) return;
    else if (key == "Backspace") text.backspace();
    else if (key.length > 1) return;
    else this.active_text.add_char(key);

    this.active_rule.update_size(this.ctx);
    this.update();
  }
}
