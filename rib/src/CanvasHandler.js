class CanvasHandler {
  id     = null;
  ctx    = null;
  canvas = null;
  // Handlers
  change_handler = null;
  event_handler  = null;
  rule_handler   = null;
  // Flags
  debug = false;
  // Key down
  control_down = false;
  alt_down     = false;
  shift_down   = false;
  
  constructor(id, rule_handler, event_handler, change_handler) {
    this.id = id;

    this.rule_handler   = rule_handler;
    this.event_handler  = event_handler;
    this.change_handler = change_handler; 

    this.canvas = document.getElementById(this.id);
    this.ctx = this.canvas.getContext("2d");
  }

  set_debug(bool) {
    this.debug = bool;
    this.update();
  }

  update() {
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
    for (let rule of this.rule_handler.rule_list) { //! This is very temporary, NEED TO FIND WAY TO HANDLE DRAWING SEPERATED
      rule.update(this.ctx);
      rule.draw(this.ctx, this.debug, 0, 0);
    }
  }

  dbl_click(x, y) {
    if (this.debug) console.log(`Dbl Click X: ${x}, Y: ${y}`);

    if (this.control_down && this.shift_down && this.alt_down) 
      return;
    else if (this.control_down && this.shift_down) 
      return;
    else if (this.control_down && this.shift_down)
      return; 
    else if (this.control_down && this.alt_down) 
      return;
    else if (this.control_down) 
      return
    else if (this.alt_down)   
      return;
    else if (this.shift_down)
      return;
    else 
      this.add_rule(x, y);
    

    this.update();
  }

  add_rule(x, y) {
    const rule = new Rule(x, y, this.ctx);
    this.change_handler.add(new CreateChange(rule, this.rule_handler));
  }

  click_down(x, y) { 
    if (this.debug) console.log(`Click X: ${x}, Y: ${y}`);
    
    this.event_handler.end();
    const root = this.rule_handler.get_root_at(x, y);

    if (this.control_down && this.shift_down && this.alt_down) 
      return;
    else if (this.control_down && this.shift_down) 
      return;
    else if (this.control_down && this.shift_down)
      return; 
    else if (this.control_down && this.alt_down) 
      return;
    else if (this.control_down) 
      this.split(x, y);
    else if (this.alt_down)   
      return;
    else if (this.shift_down)
      this.change_handler.add(new DeleteChange(this.rule_handler, root));
    else 
      this.normal_click(x, y);
    
    this.update();
  }

  normal_click(x, y) {
     const rule = this.rule_handler.get_root_at(x, y);
     if (rule == null) 
      return;
    
    this.event_handler.add(new MoveEvent(x, y, rule, this.rule_handler, this.change_handler));

    const text = rule.find_text(x, y);
    if (text == null) 
      return;
    
    this.event_handler.add(new WriteEvent(x, text, rule, this.ctx, this.rule_handler, this.change_handler));
  }

  split(x, y) {
    const root = this.rule_handler.get_root_at(x, y);
    const child = root.get_deepest_rule(x, y);
    const parent = child.get_parent();
    this.change_handler.add(new SplitChange(child, parent, this.rule_handler));
  }

  move(x, y) {
    if (this.rule_handler.get_dragged == null) return;

    this.event_handler.move(x, y);
    this.update(); 
  }

  click_up() {
    this.event_handler.end();
    this.update();
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
  key_down(key) { 
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

    if (this.control_down) {
      switch (key) {
        case "z":
          this.event_handler.end();
          this.change_handler.undo();
          break;
        case "y":
          this.event_handler.end();
          this.change_handler.redo();
          break;
      }
    }

    if (!this.event_handler.key_input(key) && key == "Delete") 
        this.change_handler.add(new DeleteChange(this.rule_handler));
    this.update();
  }
}
