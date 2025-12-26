class MergeChange extends Change {
    rule_handler = null
    before_pos   = {x: null, y: null};
    
    child  = null;
    parent = null;

    constructor(before_pos, child, parent, rule_handler) {
        super();
        this.parent = parent;
        this.child  = child;

        this.rule_handler = rule_handler;
        
        this.before_pos = before_pos;

        this.do();
    }

    undo() {
        this.parent.remove_inner_rule(this.child);
        this.rule_handler.add(this.child);
        
        this.child.get_box().set_y(this.before_pos.y);
        this.child.get_box().set_x(this.before_pos.x);
    }

    do() {
        this.rule_handler.remove(this.child);
        this.parent.add_inner_rule(this.child, 0); // !Change idx
    }
}