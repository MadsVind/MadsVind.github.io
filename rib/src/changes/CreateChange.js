class CreateChange extends Change {

    rule = null;
    rule_handler = null;

    constructor(rule, rule_handler) {
        super();
        this.rule = rule;
        this.rule_handler = rule_handler;

        this.do();
    }

    undo() {
        this.rule_handler.remove(this.rule);
    }

    do() {
        this.rule_handler.add(this.rule);
    }

}