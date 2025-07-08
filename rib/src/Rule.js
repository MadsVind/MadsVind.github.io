class Rule {
    box = null;
    conclussion_text = null; 
    premise_text = null; 
    premise_list = []
    parent = null;
    line = null;
    line_space = 5;
    hovered = false;
    total_height = 0;
    depth = 0;
  
    constructor(x, y, ctx) { // Use of FONT_SIZE should be made dynamic!
        const width  = ctx.measureText(STANDARD_TEXT).width;
        const height = FONT_SIZE;
        x = x - width / 2;
        y = y - height;
        this.box = new Box(x, y, width, height * 2);

        this.premise_text = new Text(0, 0, width, height, STANDARD_TEXT);
        this.line = new Line(0, 0 + height + this.line_space, width);
        this.conclussion_text = new Text(0, 0 + height, width, height, STANDARD_TEXT);
    }


    get_depth() {
        return this.depth;
    }

    set_parent(rule) {
        this.parent = rule;
        this.update_depth();
    }

    update_depth() {
        this.depth = this.parent.get_depth() + 1;
        for (let rule of this.premise_list) { rule.update_depth(); }
    }

    set_root() {
        this.parent = null;
        this.depth = 0;
    }

    is_root() {
        return this.parent == null;
    }

    get_relative_pos(x, y) {
        return [x - this.box.get_x(),
                y - this.box.get_y()];
    }

    get_relative_x(x) {
        return x - this.box.get_x();
    }

    get_relative_y(y) {
        return y - this.box.get_x();
    }

    draw(ctx, debug=false, abs_x, abs_y) {
        const box = this.box;
        if (debug == true) {
            box.draw(ctx, abs_x, abs_y);
        }
        
        abs_x += this.box.get_x(); 
        abs_y += this.box.get_y();
        this.line.draw(ctx, abs_x, abs_y);
        if (this.is_leaf())  {
            if (this.hovered == true)
                this.premise_text.get_box().draw(ctx, abs_x, abs_y);
            else
            this.premise_text.draw(ctx, debug, abs_x, abs_y);
    }
    else {
        if (this.hovered == true)
            for (let rule of this.premise_list) { rule.get_box().draw(ctx, abs_x, abs_y); }
        else
        for (let rule of this.premise_list) { rule.draw(ctx, debug, abs_x, abs_y); }
    }
    this.conclussion_text.draw(ctx, debug, abs_x, abs_y);

    }

    set_hovered(bool) {
        this.hovered = bool;
    }

    // depth first search because it is the easiest 
    rule_from_child(child) {
    if (this.conclussion_text == child ||
            this.premise_text == child
        ) return this;
        for (let rule of this.premise_list) {
            if (rule == child) return this; 
            const result = rule.rule_from_child(child);
            if (result != null) 
                return result;
        }
        return null;
    }
    
    find_text(x, y) {
        let text = null;
        [x, y] = this.get_relative_pos(x, y); 
        if (this.conclussion_text.get_box().is_within(x, y)) 
            text = this.conclussion_text;
        else if (this.is_leaf() && this.premise_text.get_box().is_within(x, y)) 
            text = this.premise_text;
        else {
            for (let rule of this.premise_list) {
                text = rule.find_text(x, y);
                if (text != null) break;
            }
        }
        return text;
    }
    
    premise_in_pos(x, y) { // Works but, This has to be rewritten
        // If in premise
        let premise = false;
        [x, y] = this.get_relative_pos(x, y);
        if (this.is_leaf()) {
            if (this.premise_text.get_box().is_within(x, y))
                return this.premise_text;
            return null
        
        }
        // If in premise part of child
        for (let rule of this.premise_list) { // this need to be done from scratch
            if (rule.get_box().is_within(x, y)) {
                premise = rule.premise_in_pos(x, y);
                console.log(`x: ${x}, y: ${y}`)
                if (premise == null) {
                    premise = rule;
                } 
                break;
            }
        }

        // If in non premise part of child
        return (premise == false && !this.is_root()) ? this : premise; 
    }

    not_hovered() {
        this.hovered = false;
        for (let rule of this.premise_list) {
            rule.not_hovered();
        }
    }
    
    get_premise() {
      return (this.is_leaf()) ? this.premise_text : this.premise_list;
    }
    get_conclussion() {
        return this.conclussion_text;
    }

    update_pos(ctx, total_stacked = null)  { // Works but need work
        if (this.is_root()) total_stacked = this.total_height + 1;
        
        for (let rule of this.premise_list) { rule.update_pos(ctx, total_stacked); }
    
        let height = (total_stacked - this.depth) * FONT_SIZE; 

        // we only need to move upward for root y
        if (this.is_root()) this.box.set_y(this.box.get_max_y() - height);
        this.box.set_height(height);

        // This is here since the conclussion part needs to be at the buttom
        this.premise_text.get_box().set_y(height - (FONT_SIZE * 2));
        this.line.set_y(height - FONT_SIZE + this.line_space);
        this.conclussion_text.get_box().set_y(height - FONT_SIZE);
        this.center_text();
        this.set_children_pos()
    }

    update_size(ctx) {
        this.conclussion_text.update_size(ctx);
        this.premise_text.update_size(ctx);
        
        for (let rule of this.premise_list) { rule.update_size(ctx); }
        const premise_width = (!this.is_leaf()) ? this.get_sum_child_width() : this.premise_text.get_box().get_width();
        const width = Math.max(premise_width, this.conclussion_text.get_box().get_width())
        this.line.set_width(width);
        this.box.set_width(width);
    }

    update(ctx) { 
        const root = this.get_root();
        root.update_size(ctx); 
        root.update_pos(ctx);
    }

    set_children_pos() { 
        let width = 0;
        for (let i = 0; i < this.premise_list.length; i++) {
            const rule_box = this.premise_list[i].get_box();
            rule_box.set_pos(0 + width, 0);
            width += rule_box.get_width();
        }
    }

   center_text() {
       const premise_box = this.premise_text.get_box();
       const conclussion_box = this.conclussion_text.get_box();

       const rule_center_x = this.get_relative_x(this.box.get_center().x);
       const premise_center_x = premise_box.get_center().x;
       const conclussion_center_x = conclussion_box.get_center().x;
       this.premise_text.get_box().set_x(premise_box.get_x() - (premise_center_x - rule_center_x));
       this.conclussion_text.get_box().set_x(conclussion_box.get_x() - (conclussion_center_x - rule_center_x));
   }

    get_sum_child_width() {
        let width_sum = 0;
        for (let rule of this.premise_list) {
            width_sum += rule.get_box().get_width();
        }
        return width_sum;
    }
    
    update_total_height(height_sum) {
        this.total_height = Math.max(height_sum, this.total_height);
        if (!this.is_root()) 
            this.parent.update_total_height(this.total_height + 1);
    }

    add_inner_rule(rule, ctx) { 
        this.premise_list.push(rule); 
        rule.set_parent(this);
        rule.update_total_height(1);
        this.set_children_pos(); 
        this.update(ctx);
    }

    remove_inner_rule(rule, ctx) { // update total height
        this.premise_list.slice(this.premise_list.indexOf(rule), 1); 
        rule.set_root();
        this.update(ctx);
    }

    get_root() {
        return (this.is_root()) ? this : this.parent.get_root();
    }

    is_leaf() { return this.premise_list.length == 0; }
    get_box() { return this.box; }
}