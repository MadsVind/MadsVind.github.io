class Rule {
    box = null;
    conclussion_text = null; 
    premise_text = null; 
    premise_list = []
    parent = null;
    line = null;
    line_space = 5;
    hovered = false;
  
    constructor(x, y, ctx) { // Use of FONT_SIZE should be made dynamic!
        const width  = ctx.measureText(STANDARD_TEXT).width;
        const height = FONT_SIZE;
        x = x - width / 2;
        y = y - height;
        this.box = new Box(x, y, width, height * 2);

        this.premise_text = new Text(0, 0, width, height, STANDARD_TEXT, this);
        this.line = new Line(0, 0 + height + this.line_space, width);
        this.conclussion_text = new Text(0, 0 + height, width, height, STANDARD_TEXT, this);
    }

    set_parent(rule) {
        this.parent = rule;
    }

    get_parent() {
        return this.parent;
    }

    set_root() {
        let [x, y] = this.get_absolute_pos();
        this.box.set_x(x); 
        this.box.set_y(y); 
        this.parent = null;
    }

    is_root() {
        return this.parent == null;
    }

    get_absolute_x() {
        let x = 0;
        let rule = this;
        while (rule != null) {
            x += rule.get_box().get_x();
            rule = rule.get_parent();
        } 
        return x;
    }

    get_absolute_y() {
        let y = 0;
        let rule = this;
        while (rule != null) {
            y += rule.get_box().get_y();
            rule = rule.get_parent();
        } 
        return y;
    }

    get_absolute_pos() {
        let y = 0;
        let x = 0;
        let rule = this;
        while (rule != null) {
            y += rule.get_box().get_y();
            x += rule.get_box().get_x();
            rule = rule.get_parent();
        } 
        return [x, y];
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

    set_hovered() {
        this.hovered = true;
    }

    not_hovered() {
        this.hovered = false;
        for (let rule of this.premise_list) { rule.not_hovered(); }
    }

    // depth first search because it is the easiest 
    rule_from_child(child) {
        if (this.conclussion_text == child || this.premise_text == child) 
            return this; 
        for (let rule of this.premise_list) {
            if (rule == child) { return this; }
            const result = rule.rule_from_child(child);
            if (result != null) { return result; }
        }
        return null;
    }
    
    find_text(x, y) {
        let text = null;
        [x, y] = this.get_relative_pos(x, y); 
        if (this.conclussion_text.get_box().has_within(x, y)) 
            text = this.conclussion_text;
        else if (this.is_leaf() && this.premise_text.get_box().has_within(x, y)) 
            text = this.premise_text;
        else {
            for (let rule of this.premise_list) {
                text = rule.find_text(x, y);
                if (text != null) break;
            }
        }
        return text;
    }
    
    premise_in_pos(x, y) { // Works but, This has to be rewritten (Should be deprecated)
        // If in premise
        let premise = false;
        [x, y] = this.get_relative_pos(x, y);
        if (this.is_leaf()) {
            if (this.premise_text.get_box().has_within(x, y))
                return this.premise_text;
            return null
        
        }
        // If in premise part of child
        for (let rule of this.premise_list) { // this need to be done from scratch
            if (rule.get_box().has_within(x, y)) {
                premise = rule.premise_in_pos(x, y);
                if (premise == null) premise = rule;
                break;
            }
        }

        // If in non premise part of child
        return (premise == false && !this.is_root()) ? this : premise; 
    }

    /**
     * Returns what number rule it is from the left
     */
    get_child_index(child) {
        return this.premise_list.indexOf(child); // this is not reliable, should be done by box x value
    }
    
    /**
     * Returns the most inner rule, by x, y coordinate.
     * The rule returned is therefore the rule for which x, y is on its conclussion text box
     * @param {*} x from left to right
     * @param {*} y from the top down
     */
    get_deepest_rule(x, y) {
        if (!this.get_box().has_within(x, y)) return null;
        if (this.is_leaf()) return this;
        
        [x, y] = this.get_relative_pos(x, y);

        // Is in children
        for (let rule of this.premise_list) { // this need to be done from scratch
            const search_result = rule.get_deepest_rule(x, y);
            if (search_result != null) { return search_result; }
        }

        // Is not in children but in rule
        return this 
    }

    get_premise() {
      return (this.is_leaf()) ? this.premise_text : this.premise_list;
    }

    get_conclussion() {
        return this.conclussion_text;
    }

    update_pos(ctx, root_height = null)  { // Works but need work 
        if (this.is_root()) root_height = this.box.get_height()
        for (let rule of this.premise_list) { rule.update_pos(ctx, root_height); }

        const text_height = FONT_SIZE;
        const this_height = this.box.get_height();
        const inner_y_offset = (root_height - text_height) - (root_height - this_height); // the text and line
      
        if (!this.is_root()) {
            const parent_height = this.parent.get_box().get_height();
            this.box.set_y((parent_height - this_height) - text_height); 
        }

        this.line.set_y(inner_y_offset + this.line_space);
        this.conclussion_text.get_box().set_y(inner_y_offset);
        this.center_text();
        this.set_children_pos();
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
        for (let child of this.premise_list) {
            const rule_box = child.get_box();
            rule_box.set_x(0 + width);
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
        for (let rule of this.premise_list) 
            width_sum += rule.get_box().get_width();
        return width_sum;
    }
    

    // Old and deprecated doens't work for
    // This does not work with removal again
    // You were loved when you were used
    update_height(height_sum) {
        const new_height = Math.max(height_sum, this.box.get_height()); // this only works for adding, but not removal
        if (!this.is_root()) 
            this.parent.update_height(new_height + FONT_SIZE); // Future proof this with function which check what actual height should be added
        else  
            this.box.set_y(this.box.get_max_y() - new_height); // Because y grows downwards, we have update the roots min y pos when heigh change
        this.box.set_height(new_height);
    }

    update_height() {
        let new_height = this.premise_text.get_box().get_height();
        for (let rule of this.premise_list) 
            if (rule.get_box().get_height() > new_height) { new_height = rule.get_box().get_height(); }

        new_height += this.conclussion_text.get_box().get_height();

        if (this.is_root()) 
            this.box.set_y(this.box.get_max_y() - new_height); // Because y grows downwards, we have update the roots min y pos when heigh change
        this.box.set_height(new_height);
        if (!this.is_root()) 
            this.parent.update_height(); // Future proof this with function which check what actual height should be added
    }
    

    add_inner_rule(rule, ctx, idx=0) { 
        this.premise_list.splice(idx, 0, rule); 
        rule.set_parent(this);
        rule.update_height();
        this.update(ctx);
    }

    remove_inner_rule(rule, ctx) { 
        const idx = this.premise_list.indexOf(rule);
        this.premise_list.splice(idx, 1); 
        rule.set_root();
        this.update_height();
        this.update(ctx);
    }

    get_root() {
        return (this.is_root()) ? this : this.parent.get_root();
    }

    is_leaf() { return this.premise_list.length == 0; }
    get_box() { return this.box; }
}