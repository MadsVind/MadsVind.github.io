class RuleHandler {
    rule_list = [];

    active_text = null;
    active_rule = null;
    hovered_rule = null;
    dragged_rule = null; 

    drag_diff_x = 0;
    drag_diff_y = 0;

    add(rule) {
        this.rule_list.push(rule);
    }

    remove(rule) {
        remove_from_list(this.rule_list, rule);
    }

    get_root_at(x, y) {
        for (let rule of this.rule_list) {
            if (rule == this.dragged_rule) 
                continue;
            if (rule.get_box().has_within(x, y)) 
                return rule;
        }
        return null;
    }

 
    set_hovered_rule(x, y) {
        const root = this.get_root_at(x, y);
        if (root == null) 
            return null;

        const found_el = root.premise_in_pos(x, y);
        const temp_hovered_rule = root.rule_from_child(found_el);

        if (this.hovered_rule != null)
            this.hovered_rule.not_hovered();

        if (temp_hovered_rule != null) {
            this.hovered_rule = temp_hovered_rule;
            temp_hovered_rule.set_hovered();
        } 
    }

    deactivate() {
        this.active_rule = null;
        this.active_text = null;
    }

    set_active_rule(rule) {
        this.active_rule = rule;
    }

    set_active_text(text) {
        this.active_text = text;
    }

    set_dragged(rule) {
        this.dragged_rule = rule;
    }

    get_dragged() {
        return this.dragged_rule;
    }

    get_active_text() {
        return this.active_text;
    }

    get_active_rule() {
        return this.active_rule;
    }

    set_rule_hovered(rule) {
        this.hovered_rule = rule;
    }

    get_rule_hovered() {
        return this.hovered_rule;
    }
}