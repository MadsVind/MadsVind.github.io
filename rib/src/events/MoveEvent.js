class MoveEvent extends Event {
    rule         = null;
    rule_handler = null;

    before_pos    = {x: null, y: null};
    curr_pos      = {x: null, y: null};
    drag_diff_pos = {x: null, y: null};

    //this.parent_rule = rule_handler.get_rule_hovered(x, y);
    //this.child_rule  = rule_handler.get_dragged_rule();

    constructor(x, y, rule, rule_handler, change_handler) {
        super();
        this.rule_handler   = rule_handler;
        this.change_handler = change_handler;

        this.rule = rule;

        this.rule_handler.deactivate();

        const box = this.rule.get_box();

        this.rule_handler.set_active_rule(this.rule);
        this.rule_handler.set_dragged(this.rule);

        this.before_pos.x = box.get_x();
        this.before_pos.y = box.get_y();

        this.drag_diff_pos.x = x - box.get_x(); 
        this.drag_diff_pos.y = y - box.get_y(); 
    }

    move(x, y) {
        this.curr_pos.x = x;
        this.curr_pos.y = y;
        this.rule.get_box().set_pos(this.curr_pos.x - this.drag_diff_pos.x, 
                                    this.curr_pos.y - this.drag_diff_pos.y);


        this.rule_handler.set_hovered_rule(this.curr_pos.x, 
                                           this.curr_pos.y);

    }

    end() {
        super.end();
        
        if (this.rule == null) 
            return false;  
        
        if (this.merge()) 
            return true;

        const box = this.rule.get_box(); 
        const after_pos = {x: box.get_x(), y: box.get_y()};
        this.rule_handler.set_dragged(null);

        if (check_approx(after_pos.x, this.before_pos.x, EPSILON) &&
            check_approx(after_pos.y, this.before_pos.y, EPSILON)) 
            return true;

        this.change_handler.add(
            new MoveChange(this.before_pos,
                           after_pos,
                           this.rule_handler,     
                           this.rule));   
        return true;
    }

    merge() {
        const rule_hovered = this.rule_handler.get_rule_hovered();

        if (rule_hovered == null)
            return false;

        this.change_handler.add(
            new MergeChange(this.before_pos,
                            this.rule,
                            rule_hovered, 
                            this.rule_handler));  

        rule_hovered.not_hovered();
        this.rule_handler.set_rule_hovered(null);
        return true;
    }

    is_move_event() {
        return true;
    }
}