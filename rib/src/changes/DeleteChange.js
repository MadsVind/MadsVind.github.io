class DeleteChange extends Change {
    rule      = null;
    rule_handler = null

    constructor(rule_handler) {
        super();
        this.rule         = rule_handler.get_active_rule();
        this.rule_handler = rule_handler;

        this.do();
    }

    undo() {
        this.rule_handler.add(this.rule);
    }

    do() {
        this.rule_handler.remove(this.rule);
        this.rule_handler.deactivate();
    }
}
