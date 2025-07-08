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
      rule.draw(this.ctx, this.debug, 0, 0);
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
      if (this.debug) box.log();

      if (box.is_within(x, y)) {
        if (this.debug) console.log(`Click is within boundaries - X: ${x}, Y: ${y}`);
        this.dragged_rule = rule;
        this.drag_diff_x = x - box.get_x(); 
        this.drag_diff_y = y - box.get_y(); 

        let text = rule.find_text(x, y);
        
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
      this.dragged_rule.get_box().set_pos(x - this.drag_diff_x, y - this.drag_diff_y);
      this.hover_rule(x, y);
      this.update();
    }
  }

  hover_rule(x, y) { // need to find way to check if exited rule
    const inner_rule = this.dragged_rule; 
    for (let outer_rule of this.rule_list) {
      if (outer_rule == inner_rule) continue;
      const found_el = outer_rule.premise_in_pos(x, y);
      const hovered_rule = outer_rule.rule_from_child(found_el);
      if (hovered_rule != null) {
        hovered_rule.set_hovered(true);
        return;
      } else {
        outer_rule.not_hovered();
      }
    }
  }


  insert_rule(x, y) {
    const inner_rule = this.dragged_rule;
    for (let outer_rule of this.rule_list) {
      if (outer_rule == inner_rule) continue;
      const found_el = outer_rule.premise_in_pos(x, y);
      const hovered_rule = outer_rule.rule_from_child(found_el);
      if (hovered_rule != null) {
        hovered_rule.add_inner_rule(inner_rule, this.ctx);
        this.rule_list.splice(this.rule_list.indexOf(inner_rule), 1);
        hovered_rule.set_hovered(false);
        return;
      }
    }
  }

  drop(x, y) {
    if (this.dragged_rule == null) return;
    this.insert_rule(x, y);
    this.update();
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

    this.active_rule.update(this.ctx);
    this.update();
  }
}
