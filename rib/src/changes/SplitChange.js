class SplitChange extends Change {
    rule_handler = null;
    parent       = null;
    child        = null;
    idx          = null;

    constructor(child, parent, rule_handler) {
        super();
        this.child  = child;
        this.parent = parent;

        this.rule_handler = rule_handler;

        this.idx = this.parent.get_child_index(this.child);

        this.do();
    }

    undo() {
        this.rule_handler.remove(this.child);
        this.parent.add_inner_rule(this.child, this.idx);
    }

    do() {
        this.parent.remove_inner_rule(this.child);
        this.rule_handler.add(this.child);
    }
}