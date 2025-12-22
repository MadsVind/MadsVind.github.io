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
  // Make hover event maybe?
  hovered_rule = null;
  // Key down
  control_down = false;
  alt_down = false;
  shift_down = false;
  
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

  get_root_at(x, y) {
    for (let rule of this.rule_list) 
        if (rule.get_box().has_within(x, y)) 
          return rule;
    return null;
  }
 
  /**
   * Rule at x, y in root is removed from it's parent and tangentially also the root.
   * @param {*} x 
   * @param {*} y 
   */
  split_out_rule(x, y) {
    const root = this.get_root_at(x, y);
    const rule = root.get_deepest_rule(x, y);
    if (rule != root) {
      rule.get_parent().remove_inner_rule(rule, this.ctx); 
      this.rule_list.push(rule);
    }
    this.update();
  }

  add(x, y) {
    this.rule_list.push(new Rule(x, y, this.ctx));
    this.update();
  }

  delete(x, y) {
    const root = this.get_root_at(x, y);
    remove(this.rule_list, root);
    this.update();
  }

  dbl_click(x, y) {
    this.add(x, y);
  }

  click_down(x, y) { // This is not pretty, try to make better looking (if hell)
    if (this.debug) console.log(`Click X: ${x}, Y: ${y}`);

    if (this.control_down && this.shift_down && this.alt_down) 
      return;
    else if (this.control_down && this.shift_down) 
      return;
    else if (this.control_down && this.shift_down)
      return; 
    else if (this.control_down && this.alt_down) 
      return;
    else if (this.control_down) 
      this.split_out_rule(x, y); 
    else if (this.alt_down)   
      return;
    else if (this.shift_down)
      this.delete(x, y);
    else
      this.select(x, y);
  }

  select(x, y) { // This is not pretty, try to make better looking (if hell)
    if (this.active_text != null) this.active_text.unactivate();
    this.active_text = null;
    this.active_rule = null;

    for (let rule of this.rule_list) {
      const box = rule.get_box();
      if (this.debug) box.log();

      if (box.has_within(x, y)) {
        if (this.debug) { console.log(`Click is within boundaries - X: ${x}, Y: ${y}`); }           
        this.dragged_rule = rule;
        this.active_rule = rule;
        this.drag_diff_x = x - box.get_x(); 
        this.drag_diff_y = y - box.get_y(); 

        let text = rule.find_text(x, y);
        
        if (text == null) continue; 

        if (this.active_text != null) this.active_text.unactivate();
        text.activate(x, this.ctx);
        this.active_text = text;
        break;
        
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

  hover_rule(x, y) { // This is not pretty, try to make better looking // i really hate this
    const inner_rule = this.dragged_rule; 
    for (let outer_rule of this.rule_list) {
      if (outer_rule == inner_rule) continue;
      const found_el = outer_rule.premise_in_pos(x, y);
      const hovered_rule = outer_rule.rule_from_child(found_el);
      if (hovered_rule != null) {
        if (this.hovered_rule != null) this.hovered_rule.not_hovered();
        this.hovered_rule = hovered_rule;
        hovered_rule.set_hovered();
        return;
      } 
    }
    if (this.hovered_rule != null) this.hovered_rule.not_hovered();
  }


  insert_rule(x, y) { // This is not pretty, try to make better looking
    const inner_rule = this.dragged_rule;
    for (let outer_rule of this.rule_list) {
      if (outer_rule == inner_rule) continue;
      const found_el = outer_rule.premise_in_pos(x, y);
      const hovered_rule = outer_rule.rule_from_child(found_el);
      if (hovered_rule != null) {
        let idx = 0;
        if (!hovered_rule.is_leaf()) idx = hovered_rule.get_child_index(found_el);
        hovered_rule.add_inner_rule(inner_rule, this.ctx, idx);
        this.rule_list.splice(this.rule_list.indexOf(inner_rule), 1);
        hovered_rule.not_hovered();
        break;
      }
    }
    if (this.hovered_rule != null) this.hovered_rule.not_hovered();
    this.hovered_rule = null;
  }

  click_up(x, y) {
    this.drop(x, y);
  }

  drop(x, y) {
    if (this.dragged_rule == null) return;
    this.insert_rule(x, y);
    this.update();
    this.dragged_rule = null;
    this.drag_diff_x = null;
    this.drag_diff_y = null;
  }


  key_up(key) {
    switch(key) {
      case "Control":
        this.control_down = false;
        break;
      case "Shift":
        this.shift_down = false;
        break;
      case "Alt":
        this.alt_down = false;
        break;
    }
  }

  /**
   * 
   * @param {*} key is the key which has pressed while on the canvas
   * @returns 
   */
  key_down(key) { // Not Done
    const text = this.active_text;
    const rule = this.active_rule;
    console.log("key: " + key);

    switch(key) {
      case "Control":
        this.control_down = true;
        break;
      case "Shift":
        this.shift_down = true;
        break;
      case "Alt":
        this.alt_down = true;
        break;
    }

    if (text != null) {
      if (key == "Backspace") 
        text.backspace();
      else if (key == "Delete") 
        text.delete()
      else if (key == "ArrowLeft") 
        text.cursor_left();
      else if (key == "ArrowRight") 
        text.cursor_right();
      else if (key.length > 1) 
        return;
      else 
        text.add_char(key); 
    } else if (rule != null) {
      if (key == "Delete") {
        this.rule_list.splice(this.rule_list.indexOf(rule), 1);
        this.active_rule = null;
      }
    } 
      
    if (this.active_rule != null) this.active_rule.update(this.ctx);
    this.update();
  }
}
