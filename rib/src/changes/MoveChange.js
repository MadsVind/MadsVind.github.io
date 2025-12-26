class MoveChange extends Change {
    rule         = null;
    rule_handler = null;

    before_pos    = {x: null, y: null};
    after_pos     = {x: null, y: null};
    
    constructor(before_pos, after_pos, rule_handler, rule) {
        super();
        this.rule_handler = rule_handler;
        this.rule         = rule;
        this.before_pos   = before_pos;
        this.after_pos    = after_pos;

        this.do();
    }

    do() {
        this.rule.get_box().set_pos(this.after_pos.x, 
                                    this.after_pos.y);
    }
    
    undo() {
        this.rule.get_box().set_pos(this.before_pos.x, 
                                    this.before_pos.y);
    }

}