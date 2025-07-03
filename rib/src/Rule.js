class Rule {
    box = null;
    conclussion_text = null; 
    premise_text = null; 
    premise_list = []
    line = null;
    line_space = 5;
    hovered = false;
    offset = 0;
  
    constructor(x, y, ctx) { // Use of FONT_SIZE should be made dynamic!
        const width  = ctx.measureText(STANDARD_TEXT).width;
        const height = FONT_SIZE;
        x = x - width / 2;
        y = y - height;
        this.premise_text = new Text(x, y, width, height, STANDARD_TEXT);
        this.line = new Line(x, y + height + this.line_space, width);
        this.conclussion_text = new Text(x, y + height, width, height, STANDARD_TEXT);
        this.offset = this.premise_text.get_box().height;
        this.box = new Box(x, y, width, height * 2);
    }

    find_text(x, y) {
        let text = null;
        if (this.conclussion_text.get_box().is_within(x, y)) 
            text = this.conclussion_text;
        else if (this.is_premise_text() && this.premise_text.get_box().is_within(x, y)) 
            text = this.premise_text;
        else {
            for (let rule of this.premise_list) {
                text = rule.find_text(x, y);
                if (text != null) break;
            }
        }
        return text;
    }

    draw(ctx, debug=false) {
        const box = this.box;
        this.line.draw(ctx);
        if (this.is_premise_text())  {
            if (this.hovered == true)
                this.premise_text.get_box().draw(ctx, debug);
            else
                this.premise_text.draw(ctx, debug);
        }
        else {
            if (this.hovered == true)
                for (let rule of this.premise_list) { rule.get_box().draw(ctx, debug); }
            else
                for (let rule of this.premise_list) { rule.draw(ctx, debug); }
        }
        this.conclussion_text.draw(ctx, debug);
                    
        if (debug == true) {
            box.draw(ctx);
        }
    }

    set_hovered(bool) {
        this.hovered = bool;
    }

    set_pos(x, y) {
        const premise_box = this.premise_text.get_box();
        const conclussion_box = this.conclussion_text.get_box();

        let new_y = y;
        if (this.is_premise_text()) {
            premise_box.set_pos(x, y);
        } else {
            const height = this.get_max_child_height();
            new_y = y - (height - this.conclussion_text.get_box().get_height());
            this.set_children_pos(x, y);
        }
        this.line.set_pos(x, y + this.offset + this.line_space); 
        conclussion_box.set_pos(x, y + this.offset);

        this.box.set_pos(x, new_y);
        this.center_text();
    }
  
    get_premise() {
      return (this.is_premise_text()) ? this.premise_text : this.premise_list;
    }
    get_conclussion() {
        return this.conclussion_text;
    }

    update_size(ctx) { 
        this.conclussion_text.update_size(ctx);
        
        let width = 0;
        if (this.is_premise_text()) {
            this.premise_text.update_size(ctx);
            width = Math.max(this.conclussion_text.get_box().get_width(),
            this.premise_text.get_box().get_width());
        } else {
            this.set_children_pos(this.box.get_x(), this.box.get_y());
            for (let rule of this.premise_list) { rule.update_size(ctx); }
            width = this.get_sum_child_width();
            const height = this.get_max_child_height();
            this.box.set_height(height + this.conclussion_text.get_box().get_height());
            this.box.set_y(this.box.get_y() - (height - this.conclussion_text.get_box().get_height()))
        }
        this.line.set_width(width);
        this.box.set_width(width);
        this.center_text();
    }

    set_children_pos(x, y) {
        let width = 0;
        for (let i = 0; i < this.premise_list.length; i++) {
            const rule = this.premise_list[i];
            rule.set_pos(x + width, y - this.offset);
            width += rule.get_box().get_width();
        }
    }

    center_text() {
        const premise_box = this.premise_text.get_box();
        const conclussion_box = this.conclussion_text.get_box();

        const rule_center_x = this.box.get_center().x;
        const premise_center_x = premise_box.get_center().x;
        const conclussion_center_x = conclussion_box.get_center().x;
        this.premise_text.get_box().set_x(premise_box.get_x() - (premise_center_x - rule_center_x));
        this.conclussion_text.get_box().set_x(conclussion_box.get_x() - (conclussion_center_x - rule_center_x));
    }

    get_max_child_height() {
        let max_child_height = 0;
        for (let rule of this.premise_list) {
            const temp_height = rule.get_box().get_height();
            if (max_child_height < temp_height) max_child_height = temp_height;
        }
        return max_child_height;
    }

    get_sum_child_width() {
        let width_sum = 0;
        for (let rule of this.premise_list) {
            width_sum += rule.get_box().get_width();
        }
        return width_sum;
    }

    add_inner_rule(rule, ctx) {
        this.premise_list.push(rule); 
        this.update_size(ctx);
    }

    remove_inner_rule(rule, ctx) { 
        this.premise_list.slice(this.premise_list.indexOf(rule), 1); 
        this.update_size(ctx);
    }

    is_premise_text() { return this.premise_list.length == 0; }
    get_box() { return this.box; }
}